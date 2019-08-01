///Escritura de un array enteres y lectura posterior
#include<iostream>
#include<fstream>
#include<conio.h>
using namespace std;
int main(){
	int n[6]={15,25,35,45,50,60};
	register int i;
	//creamos el objeto salida de la clase ofstream , pasamos por parametros el nombre del archivo,  
	ofstream salida("prueba",ios::out|ios::binary);
	if(!salida){
		cout<<"No se pudo abrir el archivo"<<endl;
	}
	//nombre del objeto.
	salida.write((char*)&n,sizeof(n));//pasa porreferencia char al la memoria del arreglo n 
	salida.close();
	
	//inicializa el array en cero  para borrar los datos previame almacenados 
	for(i=0;i<6;i++){
		n[i]=0;
	}
	ifstream entrada("prueba",ios::in|ios::binary);
	entrada.read((char*)&n,sizeof(n));//sizeof(n)) tamaño del arreglo n
	for(i=0;i<6;i++){
		cout<<n[i]<<" ";
	}
	entrada.close();
	getch();
	return 0;
}
