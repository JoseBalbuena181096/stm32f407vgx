//ziseof
#include<iostream>
#include<conio.h>
using std::cout;
using std::cin;
using std::endl;
//declar una estructua persona
struct Persona{
		char nombre;
		int edad;
		float altura;
		float peso;
	};
	
int  main(){
	 Persona P1;

     P1.nombre="Arturo";
	 P1.edad=20;
	 P1.altura=30;
	 P1.peso=20;
     cout<<P1.nombre<<endl;  
	 cout<<P1.edad<<endl;   
	 cout<<P1.altura<<endl;
	 cout<<P1.peso<<endl;  	
	getch();
	return 0;
}
