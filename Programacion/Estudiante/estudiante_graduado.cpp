#include"estudiante_graduado.h"
#include"estudiante.h"
#include<iostream>
using namespace std;
estudiante_graduado::estudiante_graduado(string _nombre,string _matricula,string _carrera, int _edad,string _titulacion,string _forma_titulacion,int _anios_titulado):estudiante::estudiante(_nombre, _matricula,  _carrera,  _edad){
	titulacion=_titulacion;
	forma_titulacion=_forma_titulacion;
	anios_titulado=_anios_titulado;
	
}
void  estudiante_graduado::mostrarEstudiante_graduado(){
	estudiante::mostrarEstudiante();
	cout<<"Esta Titulado: "<<titulacion<<endl;
	cout<<"Como se  Titulo: "<<forma_titulacion<<endl;
	cout<<"Cuantos años lleva titulado: "<<anios_titulado<<endl;
}


