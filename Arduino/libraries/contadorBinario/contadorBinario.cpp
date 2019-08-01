#include"contadorBinario.h"
#include"arduino.h"
#include"math.h"

contadorBinario::contadorBinario(){
	bitsContador=4;
}

void contadorBinario::set_bitsContador(int _bitsContador){
	bitsContador=_bitsContador;
}
 int contadorBinario::get_bitsContador(){
 	return bitsContador;
 }

 void contadorBinario::contador(int _Pines[12]){
 	 	for(int i=0;i<get_bitsContador();i++){
 		pinMode(_Pines[i],OUTPUT);
 	 }	  

 		for(int i=0;i<pow(2,get_bitsContador());i++){
		for(int j=get_bitsContador()-1;j>=0;j--){
			if(((i>>j)&1)==1){
				digitalWrite(_Pines[j],HIGH);
			}
			else{
				digitalWrite(_Pines[j],LOW);
			}
		}
	    delay(1000);
	}
 }
 

