//SurferTim's code
//http://forum.arduino.cc/index.php/topic,104449.msg784053.html#msg784053

#include <SPI.h>
#include <Ethernet.h>

byte mac[] = {  
  0x00, 0xAA, 0xBB, 0xCC, 0xDE, 0x02 };

IPAddress ip( 192, 168, 2, 2 );    
IPAddress gateway( 192, 168, 2, 1 );
IPAddress subnet( 255, 255, 255, 0 );

// gmail.com email server
IPAddress server( 74, 125, 65, 27 );

EthernetClient client;

void setup()
{
  Serial.begin(115200);
  pinMode(4,OUTPUT);
  digitalWrite(4,HIGH);
//  Ethernet.begin(mac, ip, gateway, gateway, subnet); 
  if (Ethernet.begin(mac) == 0) {
    Serial.println("Failed to configure Ethernet using DHCP");
    // no point in carrying on, so do nothing forevermore:
    for(;;)
      ;
  }
  delay(2000);
  Serial.println("Ready. Press 'e' to send");
}

void loop()
{
  byte inChar;

  inChar = Serial.read();

  if(inChar == 'e')
  {
      if(sendEmail()) Serial.println("Email sent");
      else Serial.println("Email failed");
  }
}

byte sendEmail()
{
  byte thisByte = 0;
  byte respCode;
  
  if (client.connect(server,25)) {
    Serial.println("connected");
  } else {
    Serial.println("connection failed");
    return 0;
  }

  if(!eRcv()) return 0;

// change this ip to your public ip
  client.write("helo 1.2.3.4\r\n");

  if(!eRcv()) return 0;

// change this
  client.write("MAIL From: <beerandtrailmix@gmail.com>\r\n");
  
  if(!eRcv()) return 0;

// change this  
  client.write("RCPT To: <beerandtrailmix@gmail.com>\r\n");

  if(!eRcv()) return 0;

  client.write("DATA\r\n");

  if(!eRcv()) return 0;

//change this
  client.write("To: You <youremail@gmail.com>\r\n");

// change this
  client.write("From: Me <myemail@gmail.com>\r\n");
  
  client.write("Subject: Arduino email test\r\n");
  
  client.write("This is from my Arduino!\r\n");
  
  client.write(".\r\n");

  if(!eRcv()) return 0;

  client.write("QUIT\r\n");

  if(!eRcv()) return 0;

  client.stop();
  Serial.println("disconnected");
  return 1;
}

byte eRcv()
{
  byte respCode;
  byte thisByte;
  
  while(!client.available()) delay(1);

  respCode = client.peek();

  while(client.available())
  {  
    thisByte = client.read();    
    Serial.write(thisByte);
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

  client.write("QUIT\r\n");

  while(!client.available()) delay(1);

  while(client.available())
  {  
    thisByte = client.read();    
    Serial.write(thisByte);
  }

  client.stop();
  Serial.println("disconnected");
}