#include<iostream>
#include<stdlib.h>
#include<fstream>
#include<conio.h>
using namespace std;

void lectura();

int main(){
    lectura();
	getch();
	return 0;
}

void lectura(){
	ifstream archivo;
	string texto;
	archivo.open("texto1.txt",ios::in);//abrimos el archivo en modo lectura
	if(archivo.fail()){
		cout<<"No se pudo abrir el archivo";
		exit(1);
	}
	while(!archivo.eof()){//mientras no sea el final del archivo
		getline(archivo,texto);
		cout<<texto<<endl;
	}
	archivo.close();
}
