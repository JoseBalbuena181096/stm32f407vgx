
#include<iostream>
#include<conio.h>
using std::cout;
using std::cin;
using std::endl;
//declar una estructua persona
struct Fecha{
		unsigned int dia;
		unsigned int mes;
		unsigned int anyo;
	};
struct Persona{
		char nombre[20];
		unsigned int edad;
		float altura;
		float peso;
		Fecha fec;
	};	
struct PersonaEmpleado{
		Persona persona;
		unsigned int salario;
		unsigned int horas_por_semana;

	};
	
int  main(){
	PersonaEmpleado pe;
	cout<<"Introdusca su nombre: "<<endl; cin>>pe.persona.nombre;
	cout<<"Introdusca su edad: "<<endl; cin>>pe.persona.edad;
	cout<<"Introdusca su altura: "<<endl; cin>>pe.persona.altura;
	cout<<"Introdusca su peso: "<<endl; cin>>pe.persona.peso;
	cout<<"Introdusca su fecha de nacimeinto: "<<endl;
    cin>>pe.persona.fec.dia;
    cin>>pe.persona.fec.mes;
    cin>>pe.persona.fec.anyo;
    cout<<"Introdusca su salario: "<<endl;
    cin>>pe.salario;
    cout<<"Introdusca numeros de horas "<<endl;
    cin>>pe.horas_por_semana;
    cout<<"////////////////////////////////////"<<endl;
    cout<<"//       DATOS DEL EMPLEADO:      //"<<endl;
    cout<<"////////////////////////////////////"<<endl;
    cout<<"nombre: "<<pe.persona.nombre<<endl;
    cout<<"edad: "<<pe.persona.edad<<endl;
    cout<<"altura: "<<pe.persona.altura<<endl;
    cout<<"peso: "<<pe.persona.peso<<endl;
    cout<<"Fecha de Nacimento"<<endl;
    cout<<pe.persona.fec.dia<<"-";
    cout<<pe.persona.fec.mes<<"-";
    cout<<pe.persona.fec.anyo<<endl;
    cout<<"Salario: "<<pe.salario<<endl;
    cout<<"Horas por semana: "<<pe.horas_por_semana<<endl;
   	getch();
	return 0;
}
