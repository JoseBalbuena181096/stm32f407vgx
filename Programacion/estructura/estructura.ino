#include"Estructura.h"


Estructura oEstructura(A0, A1, A2);

void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:

}

void loop() {
  oEstructura.leerPonteciometro();
  oEstructura.mostrarLectura();
  delay (500);
  // put your main code here, to run repeatedly:

}
