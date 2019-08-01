#include"contadorBinario.h"
#include"contadorBinario.cpp"
//#include"arduino.h"
#include<iostream>
#include<conio.h>
#include<stdlib.h>
using namespace std;
int main(){
	int Pines[]={1,2,3,4,5,6,7,8,9,10,11,12};
	contadorBinario Bit1;
	Bit1.set_bitsContador(8);
	Bit1.set_Pines(Pines);
	Bit1.contador(Pines);
	getch();
	return 0;
}
