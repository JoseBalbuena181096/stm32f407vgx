#include<Arduino.h>
#include"Sensores1.h"
Sensores1::Sensores1(int a1,int a2,int a3){
	pot1=a1;
	pot2=a2;
	pot3=a3;
}
void Sensores1::leerPots(){
	potenciometros.signal_1=analogRead(pot1);
	potenciometros.signal_2=analogRead(pot2);
	potenciometros.signal_3=analogRead(pot3);
	
}
void Sensores1::mostrarLeds(){
	Serial.print("Canal:");
	Serial.print(pot1);
	Serial.print("Canal:");
	Serial.printnl(pot1);
	
}
