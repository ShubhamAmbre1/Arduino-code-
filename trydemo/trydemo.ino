#include <ESP8266WiFi.h>
//#include <<span class="TextRun Highlight BCX0 SCXW174472232" lang="EN-US" xml:lang="EN-US" data-contrast="auto"><span class="SpellingError BCX0 SCXW174472232">FirebaseArduino.h></span></span>
#include <FirebaseArduino.h>
//Replace these strings with your own
#define FIREBASE_HOST "https://arduino-db-88785.firebaseio.com" 
#define FIREBASE_AUTH "aORPDenjU9lYIvS4dsNOCGbTOt4ahYs3BiSUQL5b"
#define WIFI_SSID "RedmiNote" 
#define WIFI_PASSWORD "ad@123456" 


void setup() { 
 Serial.begin(9600); 
 // connect to wifi. 
 WiFi.begin(WIFI_SSID, WIFI_PASSWORD); 
 Serial.print("connecting"); 
 while (WiFi.status() != WL_CONNECTED) { 
   Serial.print("."); 
   delay(500); 
 } 
 Serial.println(); 
 Serial.print("connected: "); 
 Serial.println(WiFi.localIP()); 
 Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH); 
} 
int n = 0;

 
void loop() { 
 //Set value 
 Firebase.setFloat("number", 42.0); 
 // handle error 
 if (Firebase.failed()) { 
     Serial.print("setting /number failed:"); 
     Serial.println(Firebase.error());   
     return; 
 } 
 delay(1000); 
 
 //Update value 
 Firebase.setFloat("number", 43.0); 
 
 //Handle error 
 if (Firebase.failed()) { 
     Serial.print("setting /number failed:"); 
     Serial.println(Firebase.error());   
     return; 
 } 
 delay(1000);
  
 //Get value  
 Serial.print("number: "); 
 Serial.println(Firebase.getFloat("number")); 
 delay(1000); 
 
 //Remove value 
 Firebase.remove("number"); 
 delay(1000); 
 
 //Set string value 
 Firebase.setString("message", "hello world"); 
 // handle error 
 if (Firebase.failed()) { 
     Serial.print("setting /message failed:"); 
     Serial.println(Firebase.error());   
     return; 
 } 
 delay(1000); 
 
 //Set bool value 
 Firebase.setBool("truth", false); 
 
 //Jandle error 
 if (Firebase.failed()) { 
     Serial.print("setting /truth failed:"); 
     Serial.println(Firebase.error());   
     return; 
 } 
 delay(1000); 

 //Append a new value to /logs 
 String name = Firebase.pushInt("logs", n++); 
 
 //Handle error 
 if (Firebase.failed()) { 
     Serial.print("pushing /logs failed:"); 
     Serial.println(Firebase.error());   
     return; 
 } 
 Serial.print("pushed: /logs/"); 
 Serial.println(name); 
 delay(1000); 
} 
