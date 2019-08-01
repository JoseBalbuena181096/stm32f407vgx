#include"estudiante.h"
#include<iostream>
using namespace std;
estudiante::estudiante(string _nombre,string _matricula,string _carrera, int _edad){
	nombre=_nombre;
	matricula= _matricula;
	edad=_edad;
	carrera=_carrera;

}
void estudiante::mostrarEstudiante(){
	cout<<"Nombre: "<<nombre<<endl;
	cout<<"Carrera: "<<carrera<<endl;
	cout<<"Matricula: "<<matricula<<endl;
	cout<<"Edad: "<<edad<<endl;
}

