#include <VirtualWire.h>
char *data;
const int AOUTpin=0;//the AOUT pin of the alcohol sensor goes into analog pin A0 of the arduino
const int DOUTpin=8;//the DOUT pin of the alcohol sensor goes into digital pin D8 of the arduino
const int ledPin=13;//the anode of the LED connects to digital pin D13 of the arduino

int limit;
int value;

void setup() 
{
  vw_set_tx_pin(12);
  vw_setup(2000);
  Serial.begin(9600);
  pinMode(DOUTpin, INPUT);//sets the pin as an input to the arduino
}

void loop()
{
  delay(5);
  value= analogRead(AOUTpin);//reads the analaog value from the alcohol sensor's AOUT pin
  Serial.print("Alcohol value: ");
  Serial.println(value);//prints the alcohol value
  delay(100) ;

  if (value > 300){
    data="a";
    vw_send((uint8_t *)data, strlen(data));
    vw_wait_tx();
    delay(500);
}
  else{
    data="b";
    vw_send((uint8_t *)data, strlen(data));
    vw_wait_tx();
    delay(500);
    }
  
    
 
}
