#define BLYNK_PRINT Serial
#include <ESP8266_Lib.h>
#include <BlynkSimpleShieldEsp8266.h>
#include <SoftwareSerial.h>
#define ESP8266_BAUD 9600

char auth[] = "6bae2d0e7bfa4b6096feeaffa2030e4f";
char ssid[] = "Virus.exe"; //You can replace the wifi name to your wifi 

char pass[] = "14486492";  //Type password of your wifi.

SoftwareSerial EspSerial(0, 1); // RX, TX
//WidgetLCD lcd(V0);

ESP8266 wifi(&EspSerial);

void setup()
{

  Serial.begin(9600);
  EspSerial.begin(ESP8266_BAUD);
  Blynk.begin(auth, wifi, ssid, pass);
 // lcd.clear();
 //lcd.print(1, 1, "IoT");
}

void loop()
{
  Blynk.run();
}
