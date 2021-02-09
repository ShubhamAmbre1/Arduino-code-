#include <VirtualWire.h>
char *data;
char *data1;
const int AOUTpin = 0;        //the AOUT pin of the alcohol sensor goes into analog pin A0 of the arduino
int value; //for MQ3

void setup() {
  Serial.begin(9600);

  //Touch sensor
  pinMode(2, INPUT);

  //Transmitter
  vw_set_tx_pin(12);  //tx pin
  vw_setup(2000);     //sets the baud rate
}

void loop()
{
  //MQ3 and touch sensor
  value= analogRead(AOUTpin);       //reads the analaog value from the alcohol sensor's AOUT pin
//  Serial.print("Alcohol value: ");
//  Serial.println(value);            //prints the alcohol value

  //Touch Sensor
  if (digitalRead(2) == HIGH && value < 1000){  // Checking touch and alcohol value
    Serial.println("Sensor is touched");
    data="a";
    vw_send((uint8_t *)data, strlen(data));   // Data sent to rx
    vw_wait_tx();
    Serial.println("SENT");
  }
  else if(digitalRead(2) == LOW) {
    Serial.println("SENDING LOW");
    data1 ="b";
    vw_send((uint8_t *)data, strlen(data));   // Data sent to rx
    vw_wait_tx();
    Serial.println("SENT B");
  }
  
  delay(500);

}
