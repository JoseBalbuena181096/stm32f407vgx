#include<iostream>
#include<conio.h>
using std::cout;
using std::cin;
using std::endl;

struct CD{
		char Titulo[30];
		char Artista[25];
		int Numero_de_Canciones;
		float Precio;
		char FechaCompra[10];
	} 
	CD1={"AyAyAy","No me pises",10,2222.25,"8-10-1992"};

int main(){
	//struct CD1;
	char T[30];
	T=CD1.Titulo;
	cout<<"Titulo:"<<T<<endl;
	cout<<"Artista:"<<CD1.Artista<<endl;
	cout<<"Numero de Canciones:"<<CD1.Numero_de_Canciones<<endl;
	cout<<"Precio:"<<CD1.Precio<<endl;
	cout<<"Fecha de Compra:"<<CD1.FechaCompra<<endl;
	getch();
	return 0;
}
