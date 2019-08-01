#include<iostream>
#include<conio.h>
#include"DibujarCuadro.h"
using namespace std;
int main(){
	DibujarCuadro Cuadro;
	Cuadro.establecerLado(8); 
	Cuadro.imprimirCuadro();
	getch();
	return 0;
}
