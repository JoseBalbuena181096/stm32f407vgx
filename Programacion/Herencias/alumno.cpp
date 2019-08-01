#include"alumno.h"
#include"herencia.h"
#include<iostream>
using namespace std;
Alumno::Alumno(string _nombre,int _edad,string _matricula,float _notaFinal):Persona::Persona( _nombre, _edad){
	matricula=_matricula;
	notaFinal=_notaFinal;
}
void  Alumno::mostrarAlumno(){
	Persona::mostrarPersona();
	cout<<"Matricula: "<<matricula<<endl;
	cout<<"Nota final: "<<notaFinal<<endl;
	
}


