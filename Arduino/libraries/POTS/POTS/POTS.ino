#include <Sensores.h>
int leds[3]={A0,A1,A2};
int pots[3]={A3,A4,A5};


void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
 Sensores s1;
 s1.mostrarLeds(leds[3],pots[3]);
}
