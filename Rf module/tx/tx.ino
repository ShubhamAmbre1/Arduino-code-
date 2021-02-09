#include <VirtualWire.h>
char *data;

void setup() 
{
  vw_set_tx_pin(12);
  vw_setup(2000);
}

void loop()
{
    data="b";
    vw_send((uint8_t *)data, strlen(data));
    vw_wait_tx();
    delay(500);
 
}
