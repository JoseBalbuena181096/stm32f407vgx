
#include<iostream>
#include<fstream>
#include<conio.h>
using namespace std;
int main(){
	
    int n[10];
    char aguinaldo[10];
   // string texto;
    
	for(int j=0;j<10;j++){
		cout<<"Introdusca el salario del trabajador ["<<j<<"]: ";
		cin>>n[j];
	}
	ofstream aperturaArchivo("aguinaldo.txt");
	if(!aperturaArchivo){
		cerr<<"no se puede abrir el archivo"<<endl;
		return -1;
	}
	for(int j=0;j<10;j++){
		aperturaArchivo<<2*n[j]<<endl;
	}
	aperturaArchivo.close();

	
	ifstream Archivo("aguinaldo.txt");
	if(!Archivo){
		cerr<<"no se puede abrir el archivo"<<endl;
		return -1;
	}
	cout<<"Los aguinaldos de los trabajadores son :"<<endl;
	for(int i=0;i<10;i++){
	Archivo>>aguinaldo;
	cout<<"El aguinaldo del trabajador ["<<i<<"] es:"<<aguinaldo<<endl;
	}

	
	Archivo.close();
	getch();
	return 0;
}
