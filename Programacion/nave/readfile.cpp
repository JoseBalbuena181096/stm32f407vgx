
#include<iostream>
#include<fstream>
#include<string>
using std::string;
using std::getline;
#include<conio.h>
using std::cerr;
using std::cout;
using std::cin;
using std::endl;
using std::ofstream;
using std::ifstream;


	
int  main(){
     
	cout<<"Nombre del archivo:";
	string nombre_archivo;
	cin>>nombre_archivo;
	//abrir un archivo copy.txt para entrada 
	ifstream ArchivoEntrada(nombre_archivo.c_str());
	if(!ArchivoEntrada){
		cerr<<"No se puede abrir copia.txt para salida \n"<<endl;
		return -1;
	} 
	char car;
   
	
	while(ArchivoEntrada.get(car)){
	
		cout.put(car);//guardar archivos en car 
	 
	}
	

	
	
   	getch();
	return 0;
}
