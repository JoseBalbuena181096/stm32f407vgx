#include<iostream>
#include<stdlib.h>
#include<fstream>
#include<conio.h>
using namespace std;

void escribir(); 

int main(){
	escribir();
	getch();
	return 0;
}
void escribir(){
	//etiquetador o descriptor del archivo
	ofstream archivo;
	string nombreArchivo,frase;
	cout<<"nombreArchivo";
	getline(cin,nombreArchivo);
	//abrir el achivo nombre,modo
	archivo.open(nombreArchivo.c_str(),ios::out);
	//verificar si el archivo se creo
    if(archivo.fail()){
    	cout<<"no se pudo abrir el archivo"<<endl;
    	exit(1);
    	}
    //archivo<<"Hola que tal";
    cout<<"\n Digite el texto del archivo";
    getline(cin,frase);
    archivo<<frase;
	archivo.close();
		
    	
}
