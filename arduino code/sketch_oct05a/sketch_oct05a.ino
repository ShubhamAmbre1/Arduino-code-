
////#include <LiquidCrystal.h> 
//#include <SoftwareSerial.h> 
//#include <TinyGPS.h> 
//
//float lat = 28.5458,lon = 77.1703; // create variable for latitude and longitude object  
//SoftwareSerial gpsSerial(0,1);//rx,tx 
////LiquidCrystal lcd(A0,A1,A2,A3,A4,A5); 
//TinyGPS gps; // create gps object 
//
//void setup(){ 
//  Serial.begin(9600); // connect serial 
//  Serial.println("The GPS Received Signal:"); 
//  gpsSerial.begin(9600); // connect gps sensor 
//  //lcd.begin(16,2); 
//} 
//
//void loop(){ 
//  while(gpsSerial.available()){ // check for gps data 
//  if(gps.encode(gpsSerial.read()))// encode gps data 
//  {  
//  gps.f_get_position(&lat,&lon); // get latitude and longitude 
//  // display position 
////  lcd.clear(); 
////  lcd.setCursor(1,0); 
////  lcd.print("GPS Signal"); 
//  Serial.print("Position: "); 
//  Serial.print("Latitude:"); 
//  Serial.print(lat,6); 
//  Serial.print(";"); 
//  Serial.print("Longitude:"); 
//  Serial.println(lon,6);  
////  lcd.setCursor(1,0); 
////  lcd.print("LAT:"); 
////  lcd.setCursor(5,0); 
////  lcd.print(lat); 
//  Serial.print(lat); 
//  Serial.print(" "); 
////  lcd.setCursor(0,1); 
////  lcd.print(",LON:"); 
////  lcd.setCursor(5,1); 
////  lcd.print(lon); 
// } 
//} 
//String latitude = String(lat,6); 
//  String longitude = String(lon,6); 
//Serial.println(latitude+";"+longitude); 
//delay(1000); 
//}
#include <MPU6050_tockn.h>
#include <Wire.h>

MPU6050 mpu6050(Wire);

long timer = 0;

void setup() {
  Serial.begin(9600);
  Wire.begin();
  mpu6050.begin();
  mpu6050.calcGyroOffsets(true);
}

void loop() {
  mpu6050.update();

  if(millis() - timer > 1000){
    
    Serial.println("=======================================================");
    Serial.print("temp : ");Serial.println(mpu6050.getTemp());
    Serial.print("accX : ");Serial.print(mpu6050.getAccX());
    Serial.print("  accY : ");Serial.print(mpu6050.getAccY());
    Serial.print("  accZ : ");Serial.println(mpu6050.getAccZ());
  
    Serial.print("gyroX : ");Serial.print(mpu6050.getGyroX());
    Serial.print("  gyroY : ");Serial.print(mpu6050.getGyroY());
    Serial.print("  gyroZ : ");Serial.println(mpu6050.getGyroZ());
  
    Serial.print("accAngleX : ");Serial.print(mpu6050.getAccAngleX());
    Serial.print("  accAngleY : ");Serial.println(mpu6050.getAccAngleY());
  
    Serial.print("gyroAngleX : ");Serial.print(mpu6050.getGyroAngleX());
    Serial.print("  gyroAngleY : ");Serial.print(mpu6050.getGyroAngleY());
    Serial.print("  gyroAngleZ : ");Serial.println(mpu6050.getGyroAngleZ());
    
    Serial.print("angleX : ");Serial.print(mpu6050.getAngleX());
    Serial.print("  angleY : ");Serial.print(mpu6050.getAngleY());
    Serial.print("  angleZ : ");Serial.println(mpu6050.getAngleZ());
    Serial.println("=======================================================");
    timer = millis();
    
  }

} 
