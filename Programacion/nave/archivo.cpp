#include<iostream>
#include<stdlib.h>
#include<fstream>
#include<conio.h>
using namespace std;

void escribir(); 

int main(){
	
	getch();
	return 0;
}
void escribir(){
	//etiquetador o descriptor del archivo
	ofstream archivo;
	//abrir el achivo nombre,modo
	archivo.open("prueba.txt",ios::out);
	//verificar si el archivo se creo
    if(archivo.fail()){
    	cout<<"no se pudo abrir el archivo"<<endl;
    	exit(1);
    	}
    archivo<<"Hola que tal";
	archivo.close();
		
    	
}
