/////el siguiente programa describe un entero , un valor en como flotante y una cadena en un demo llamado "demo.txt"
#include<iostream>
#include<fstream>
#include<conio.h>
#include<stdlib.h>
/*
using std::string;
using std::cerr;
using std::cout;
using std::cin;
using std::endl;
using std::ofstream;
using std::ifstream;
*/
using namespace std;
int main(){
	char c;
	int i;
	float j;
	char cad[40];
	string texto;
	ifstream nomArchivo("demo.txt");
	if(!nomArchivo){
		cerr<<"no se puede abrir el archivo"<<endl;
		return -1;
	}
	while(!nomArchivo.eof()){
		getline(nomArchivo,texto);
		cout<<texto<<endl;
	}
	
	nomArchivo.close();
	getch();
	return 0;
}
