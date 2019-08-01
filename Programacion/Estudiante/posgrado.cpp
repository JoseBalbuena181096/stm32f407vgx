#include"posgrado.h"
#include"estudiante_graduado.h"
#include<iostream>
using namespace std;
posgrado::posgrado(string _nombre,string _matricula,string _carrera, int _edad,string _titulacion,string _forma_titulacion,int _anios_titulado,string _Posgrado,string _escuelaPosgrado,int _timpoPosgrado):estudiante_graduado::estudiante_graduado(_nombre,_matricula,_carrera,  _edad, _titulacion, _forma_titulacion, _anios_titulado){
Posgrado=_Posgrado;
escuelaPosgrado=_escuelaPosgrado;
timpoPosgrado=_timpoPosgrado;




}
void  posgrado::mostrarPosgrado(){
	estudiante_graduado::mostrarEstudiante_graduado();
	cout<<"El posgrado que realizo: "<<Posgrado<<endl;
	cout<<"Su posgrado lo estudio en : "<<escuelaPosgrado<<endl;
	cout<<"Su posgrados duro en años: "<<timpoPosgrado<<endl;
}


