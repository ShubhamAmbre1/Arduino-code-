//const int AOUTpin=0;//the AOUT pin of the alcohol sensor goes into analog pin A0 of the arduino
//const int DOUTpin=8;//the DOUT pin of the alcohol sensor goes into digital pin D8 of the arduino
//const int ledPin=13;//the anode of the LED connects to digital pin D13 of the arduino
//
//int limit;
//int value;
//
//void setup() {
//Serial.begin(115200);//sets the baud rate
//pinMode(DOUTpin, INPUT);//sets the pin as an input to the arduino
//pinMode(ledPin, OUTPUT);//sets the pin as an output of the arduino
//}
//
//void loop()
//{
//value= analogRead(AOUTpin);//reads the analaog value from the alcohol sensor's AOUT pin
//limit= digitalRead(DOUTpin);//reads the digital value from the alcohol sensor's DOUT pin
//Serial.print("Alcohol value: ");
//Serial.println(value);//prints the alcohol value
//Serial.print("Limit: ");
//Serial.print(limit);//prints the limit reached as either LOW or HIGH (above or underneath)
//delay(100);
//if (limit == HIGH){
//digitalWrite(ledPin, HIGH);//if limit has been reached, LED turns on as status indicator
//}
//else{
//digitalWrite(ledPin, LOW);//if threshold not reached, LED remains off
//}
//}


//#include <LiquidCrystal.h> 
#include <SoftwareSerial.h> 
#include <TinyGPS.h> 

float lat = 28.5458,lon = 77.1703; // create variable for latitude and longitude object  
SoftwareSerial gpsSerial(0,1);//rx,tx 
//LiquidCrystal lcd(A0,A1,A2,A3,A4,A5); 
TinyGPS gps; // create gps object 

void setup(){ 
  Serial.begin(9600); // connect serial 
  Serial.println("The GPS Received Signal:"); 
  gpsSerial.begin(9600); // connect gps sensor 
  //lcd.begin(16,2); 
} 

void loop(){ 
  while(gpsSerial.available()){ // check for gps data 
  if(gps.encode(gpsSerial.read()))// encode gps data 
  {  
  gps.f_get_position(&lat,&lon); // get latitude and longitude 
  // display position 
//  lcd.clear(); 
//  lcd.setCursor(1,0); 
//  lcd.print("GPS Signal"); 
  Serial.print("Position: "); 
  Serial.print("Latitude:"); 
  Serial.print(lat,6); 
  Serial.print(";"); 
  Serial.print("Longitude:"); 
  Serial.println(lon,6);  
//  lcd.setCursor(1,0); 
//  lcd.print("LAT:"); 
//  lcd.setCursor(5,0); 
//  lcd.print(lat); 
  Serial.print(lat); 
  Serial.print(" "); 
//  lcd.setCursor(0,1); 
//  lcd.print(",LON:"); 
//  lcd.setCursor(5,1); 
//  lcd.print(lon); 
 } 
} 
String latitude = String(lat,6); 
  String longitude = String(lon,6); 
Serial.println(latitude+";"+longitude); 
delay(1000); 
} 
