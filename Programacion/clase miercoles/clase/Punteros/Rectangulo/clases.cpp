#include<iostream>

#include<conio.h>
using std::cout;
using std::cin;
using std::endl;
#include<string>
using std::string;
using std::getline;
#include"Rectangulo.h"





int main(){
	float a,l;
	cout<<"Digite longitud"<<endl;
	cin>>l;
	cout<<"Digite ancho"<<endl;
	cin>>a;
	Rectangulo rectangulo1(a,l);

	bool c=rectangulo1.establecerAncho_Longitud(a,l);
	
	while(c==1){
		rectangulo1.mostrar();
		getch();
		c=0;
	}
	
	getch();
	return 0;
}


