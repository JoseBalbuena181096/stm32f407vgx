#include<Arduino.h>
#include"Estructura.h"

Estructura::Estructura(int _an1, int _an2, int _an3)
{
  Pot1 = _an1;
  Pot2 = _an2;
  Pot3 = _an3;
  
}

void Estructura::leerPonteciometro()
{
 potenciometros.c_analogico_1= analogRead(Pot1); // 
 potenciometros.c_analogico_2= analogRead(Pot2); // 
 potenciometros.c_analogico_3= analogRead(Pot3); // ya tenemos guardado la estructura en el potenciometro
}

void Estructura::mostrarLectura()
{
Serial.print("Canal:");
Serial.print(Pot1);
Serial.print(Pot1);
}

