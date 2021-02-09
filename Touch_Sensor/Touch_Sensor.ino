void setup() {
  pinMode(2, INPUT);
  Serial.begin(9600);

}

void loop() {
  if (digitalRead(2) == HIGH){
    Serial.print("Touched");
   }
  delay(500);

}
