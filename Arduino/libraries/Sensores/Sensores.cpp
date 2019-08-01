#include"Sensores.h"
#include"arduino.h"
#include"math.h"

struct Sensores::tresPots{
	float lectura[3];
};

 void Sensores::mostrarLeds(int _leds[3],int _pots[3]){
 	 	for(int i=0;i<3;i++){
 		pinMode(_leds[i],OUTPUT);
 	 }	  
 	for(int i=0;i<3;i++){
 		pinMode(_pots[i],INPUT);
 	 }
 	 tresPots L1;
 	for(int i=0;i<3;i++){
 		L1.lectura[i]=analogRead(_pots[i]);
 	 }
 	/* L1.lectura[0]=analogRead(_pots[0]);
 	 L1.lectura[1]=analogRead(_pots[1]);
 	 L1.lectura[2]=analogRead(_pots[2]);
 	 */
    float signal[3];
   	for(int i=0;i<3;i++){
 		signal[i]=0.25*L1.lectura[i];
 	 }
	/* signal[0]=0.25*L1.lectura[0];
	 signal[2]=0.25*L1.lectura[1];
	 signal[3]=0.25*L1.lectura[2];
	 */
	for(int i=0;i<3;i++){
 	   analogWrite(_leds[i],signal[i]);
 	 } 
 }
 

