void setup(){
  Serial.begin(9600);
}
void loop(){
  Serial.write("Hello world");
  delay(2000);
}
