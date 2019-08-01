#include<iostream>
#include<stdlib.h>
#include<fstream>
#include<conio.h>
using namespace std;

void aniadir();


int main(){
    aniadir();
	getch();
	return 0;
}
void aniadir(){
	ofstream archivo;
	string texto;
	archivo.open("texto1.txt",ios::app);//abrendo el archivo en modo añadir
	if(archivo.fail()){
		cout<<"Nose pudo abrir el archivo";
		exit(1);
	}
	
	cout<<"Digite el texto que quiera añadir";
	getline(cin,texto);
	archivo<<texto;
		archivo.close();
	/*archivo<<"Hola quetal";

	*/
}


