#include<SoftwareSerial.h>
SoftwareSerial gsm(2,3);
//tx=2 rx=3 gnd        no vcc         only adapter
void setup()
{
  delay(10000);
  Serial.begin(9600);
  gsm.begin(9600);
  gsm.println("AT+CMGF=1");
  delay(1000);
  gsm.println("AT+CMGS=\"+919221142876\"\r"); //replace x by your number
  delay(1000);
  gsm.println("hello");
  delay(100);
  gsm.println((char)26);
  delay(1000);
  Serial.println("sent");
}
void loop()
{
  
}
