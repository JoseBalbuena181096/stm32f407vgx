#include"estudiante_nograduado.h"
#include"estudiante.h"
#include<iostream>
using namespace std;
estudiante_nograduado::estudiante_nograduado(string _nombre,string _matricula,string _carrera, int _edad,int _grado,int _materias_reprovadas,int _materias_aprovadas,float _promedio):estudiante::estudiante(_nombre, _matricula,  _carrera,  _edad){
	grado=_grado;
	materias_reprovadas=_materias_reprovadas;
	materias_aprovadas=_materias_aprovadas;
	promedio=_promedio;	
}
void  estudiante_nograduado::mostrarEstudiante_nograduado(){
	estudiante::mostrarEstudiante();
	cout<<"EL semestre que esta estudiando es el: "<<grado<<endl;
	cout<<"La cantidad e materias reprovadas son: "<<materias_reprovadas<<endl;
	cout<<"La candidad de materias aprovadas son: "<<materias_aprovadas<<endl;
	cout<<"El promedio es de: "<<promedio<<endl;
	
}


