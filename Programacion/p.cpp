#include<iostream>
#include<stdlib.h>
#include<fstream>
#include<conio.h>
using std::string;
using std::cerr;
using std::cout;
using std::cin;
using std::endl;
using std::ofstream;
using std::ifstream;

	
int  main(){
    ///abre un archivo copia.txt para la salida  
	ofstream archivo_salida("copia.cpp");
	string car;
	if(!archivo_salida){
		cerr<<"No se puede abrir copia.txt para salida \n"<<endl;
		return -1;
	} 
	
	
    bool b=1;
	
	while(b){
		getline(cin,car);///leer datos en pantalla 
		archivo_salida<<car;//guardar archivos en car 
		if(car=="adios"){
			b=0;
	       } 
	}
	
	
   	getch();
	return 0;
}
