
#include<iostream>
#include<fstream>
#include<conio.h>
using namespace std;
int main(){
	
    int n[10];
    
	for(int j=0;j<10;j++){
		cout<<"Introdusca el salario del trabajador 1["<<j<<"]: ";
		cin>>n[j];
	}
	register int i;
	//creamos el objeto salida de la clase ofstream , pasamos por parametros el nombre del archivo,  
	ofstream salida("aguinaldo",ios::out|ios::binary);
	if(!salida){
		cout<<"No se pudo abrir el archivo"<<endl;
	}
	//nombre del objeto.
	salida.write((char*)&n,sizeof(n));//pasa porreferencia char al la memoria del arreglo n 
	salida.close();
	
	//inicializa el array en cero  para borrar los datos previame almacenados 
	for(i=0;i<10;i++){
		n[i]=0;
	}
	ifstream entrada("aguinaldo",ios::in|ios::binary);
	entrada.read((char*)&n,sizeof(n));//sizeof(n)) tamaño del arreglo n
	for(i=0;i<10;i++){
		cout<<"El aguinaldo del trabajador["<<i<<"] es: "<<2*n[i]<<endl;
	}
	entrada.close();
	getch();
	return 0;
}
