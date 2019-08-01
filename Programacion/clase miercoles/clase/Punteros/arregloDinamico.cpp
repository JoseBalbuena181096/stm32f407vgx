//asignacion dinamica de arreglos
//new:Reserva el numero de byte solisitados 'parav la declaracion
//delate:Libera un bloque de bytes reservado con anterioridad
//ejemplo pedir al usuario n calificaciones y almacenarlos en un arreglo dimencional

#include<iostream>
#include<conio.h>
#include<stdlib.h>//funciona new y delate
using namespace std;

void pedirNotas();
void mostrarNotas();
int numCalif,*calif;

int main(){
	pedirNotas();	
	 mostrarNotas();
	 //liberar memoria en bytes utilizados anterior mente
	 delete[] calif;
	getch();
	return 0;
}
void pedirNotas(){
	cout<<"Digite el numero de calificaciones";
	cin>>numCalif;
	calif=new int[numCalif];//crear el arreglo de tipo dinamico  
	for(int i=0;i<numCalif;i++){
		cout<<"Ingrese una nota: ";
		cin>>calif[i];
	}
	
}
void mostrarNotas(){
	cout<<"\n Mostrarndo Notas del usuario\n";
	for(int i=0;i<numCalif;i++){
		cout<<calif[i]<<endl;
		
	}
}
