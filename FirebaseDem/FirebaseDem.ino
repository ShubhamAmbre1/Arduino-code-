//#include <Firebase.h>
#include <FirebaseArduino.h>


#include <ESP8266WiFi.h>

// Set these to run examples
#define FIREBASE_HOST "inthelmet.firebaseio.com"
#define FIREBASE_AUTH "dAMaRpvyzonK9c7yQYpTL4n0YjEjRlA1W1jhQQMr"
#define WIFI_SSID "Virus.exe"
#define WIFI_PASSWORD "14486492"

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
