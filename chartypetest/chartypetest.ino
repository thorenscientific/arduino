void setup() {

char a[] = "plain old char\r\n";
unsigned char b[] = "unsigned char\r\n";
signed char c[] = "signed char\r\n";
int8_t d[] = "int8\r\n";
uint8_t e[] = "uint8\r\n";

//This works fine
Serial.print(a);
Serial.print((char*)b);
Serial.print((char*)c);
Serial.print((char*)d);
Serial.print((char*)e);

//This bonks
Serial.print(a);
Serial.print(b);
Serial.print(c);
Serial.print(d);
Serial.print(e);
}

void loop() {
  // put your main code here, to run repeatedly: 
  
}