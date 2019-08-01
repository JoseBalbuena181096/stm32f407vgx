//ziseof
#include<iostream>
#include<conio.h>
using std::cout;
using std::cin;
using std::endl;
//declar una estructua persona
struct Persona{
		char nombre[30];
		int edad;
		float altura;
		float peso;
	};
	
int  main(){
	
	Persona persona;
	cout<<"sizeof(Persona):"
	<<sizeof(Persona);
	
	getch();
	return 0;
}
