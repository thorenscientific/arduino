/*
   FTP passive client for IDE v1.0.1 and w5100/w5200
   Posted October 2012 by SurferTim
*/

#include <SD.h>
#include <SPI.h>
#include <Ethernet.h>
// comment out next line to write to SD from FTP server
//#define FTPWRITE

// this must be unique
//byte mac[] = { 0x90, 0xA2, 0xDA, 0x00, 0x59, 0x67 };  

byte mac[] = {  0x00, 0xAA, 0xBB, 0xCC, 0xDE, 0x02 }; // Mark's Ethernet Shield

// change to your network settings
IPAddress ip( 192, 168, 2, 2 );    
IPAddress gateway( 192, 168, 2, 1 );
IPAddress subnet( 255, 255, 255, 0 );

// change to your server
IPAddress server( 192, 168, 1, 101 );

EthernetClient client;
EthernetClient dclient;

char outBuf[128];
char outCount;

// change fileName to your file (8.3 format!)
char fileName[13] = "dolist.txt";

void setup()
{
  Serial.begin(9600);

  pinMode(10,OUTPUT);
  digitalWrite(10,HIGH);

  if(SD.begin(4) == 0)
  {
    Serial.println(F("SD init fail"));          
  }

 // Try using DHCP for convenience...
  if (Ethernet.begin(mac) == 0) {
    Serial.println("Failed to configure Ethernet using DHCP");
    // no point in carrying on, so do nothing forevermore:
    for(;;);}

//  Ethernet.begin(mac, ip, gateway, gateway, subnet); 
  digitalWrite(10,HIGH);
  delay(2000);
  Serial.println(F("Ready. Press f or r"));
}

void loop()
{
  byte inChar;

  inChar = Serial.read();

  if(inChar == 'f')
  {
    if(doFTP()) Serial.println(F("FTP OK"));
    else Serial.println(F("FTP FAIL"));
  }

  if(inChar == 'r')
  {
    readSD();    
  }

}

File fh;

byte doFTP()
{
#ifdef FTPWRITE
  fh = SD.open(fileName,FILE_READ);
#else
  SD.remove(fileName);
  fh = SD.open(fileName,FILE_WRITE);
#endif

  if(!fh)
  {
    Serial.println(F("SD open fail"));
    return 0;    
  }

#ifndef FTPWRITE  
  if(!fh.seek(0))
  {
    Serial.println(F("Rewind fail"));
    fh.close();
    return 0;    
  }
#endif

  Serial.println(F("SD opened"));

  if (client.connect(server,21)) {
    Serial.println(F("Command connected"));
  } 
  else {
    fh.close();
    Serial.println(F("Command connection failed"));
    return 0;
  }

  if(!eRcv()) return 0;

  client.println(F("USER pi"));

  if(!eRcv()) return 0;

  client.println(F("PASS raspberry"));

  if(!eRcv()) return 0;

  client.println(F("SYST"));

  if(!eRcv()) return 0;

  client.println(F("PASV"));

  if(!eRcv()) return 0;

  char *tStr = strtok(outBuf,"(,");
  int array_pasv[6];
  for ( int i = 0; i < 6; i++) {
    tStr = strtok(NULL,"(,");
    array_pasv[i] = atoi(tStr);
    if(tStr == NULL)
    {
      Serial.println(F("Bad PASV Answer"));    

    }
  }

  unsigned int hiPort,loPort;

  hiPort = array_pasv[4] << 8;
  loPort = array_pasv[5] & 255;

  Serial.print(F("Data port: "));
  hiPort = hiPort | loPort;
  Serial.println(hiPort);

  if (dclient.connect(server,hiPort)) {
    Serial.println(F("Data connected"));
  } 
  else {
    Serial.println(F("Data connection failed"));
    client.stop();
    fh.close();
    return 0;
  }

#ifdef FTPWRITE 
  client.print(F("STOR "));
  client.println(fileName);
#else
  client.print(F("RETR "));
  client.println(fileName);
#endif

  if(!eRcv())
  {
    dclient.stop();
    return 0;
  }

#ifdef FTPWRITE
  Serial.println(F("Writing"));

  byte clientBuf[64];
  int clientCount = 0;

  while(fh.available())
  {
    clientBuf[clientCount] = fh.read();
    clientCount++;

    if(clientCount > 63)
    {
      dclient.write(clientBuf,64);
      clientCount = 0;
    }
  }

  if(clientCount > 0) dclient.write(clientBuf,clientCount);

#else
  while(dclient.connected())
  {
    while(dclient.available())
    {
      char c = dclient.read();
      fh.write(c);      
      Serial.write(c); 
    }
  }
#endif

  dclient.stop();
  Serial.println(F("Data disconnected"));

  if(!eRcv()) return 0;

  client.println(F("QUIT"));

  if(!eRcv()) return 0;

  client.stop();
  Serial.println(F("Command disconnected"));

  fh.close();
  Serial.println(F("SD closed"));
  return 1;
}

byte eRcv()
{
  byte respCode;
  byte thisByte;

  while(!client.available()) delay(1);

  respCode = client.peek();

  outCount = 0;

  while(client.available())
  {  
    thisByte = client.read();    
    Serial.write(thisByte);

    if(outCount < 127)
    {
      outBuf[outCount] = thisByte;
      outCount++;      
      outBuf[outCount] = 0;
    }
  }

  if(respCode >= '4')
  {
    efail();
    return 0;  
  }

  return 1;
}


void efail()
{
  byte thisByte = 0;

  client.println(F("QUIT"));

  while(!client.available()) delay(1);

  while(client.available())
  {  
    thisByte = client.read();    
    Serial.write(thisByte);
  }

  client.stop();
  Serial.println(F("Command disconnected"));
  fh.close();
  Serial.println(F("SD closed"));
}

void readSD()
{
  fh = SD.open(fileName,FILE_READ);

  if(!fh)
  {
    Serial.println(F("SD open fail"));
    return;    
  }

  while(fh.available())
  {
    Serial.write(fh.read());
  }

  fh.close();
}