#include <VirtualWire.h>
//#define ledPin 13
const int inputPin3  = 9;   // Pin  7 of L293D IC
const int inputPin4  = 8;   // Pin  2 of L293D IC


void setup()
{
  Serial.begin(9600); 
    vw_set_rx_pin(11);
    vw_setup(2000);
//    pinMode(ledPin, OUTPUT);
    vw_rx_start();
//
    pinMode(inputPin3, OUTPUT);
    pinMode(inputPin4, OUTPUT);
}

void loop()
{
    uint8_t buf[VW_MAX_MESSAGE_LEN];
    uint8_t buflen = VW_MAX_MESSAGE_LEN; 
    
    if (vw_get_message(buf, &buflen))
    {
      if(buf[0]=='a')
      {  
        Serial.println("Working fine.....");
//       digitalWrite(ledPin,HIGH);
//       delay(1000);
//       digitalWrite(ledPin,LOW);
//       delay(1000);
       digitalWrite(inputPin3, HIGH);
       digitalWrite(inputPin4, LOW);
       Serial.println("A");
      }  
      else if(buf[0]== 'b'){
        Serial.println("B");
        digitalWrite(inputPin3, LOW);
        digitalWrite(inputPin4, LOW);
    }
      
    }
}
