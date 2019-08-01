#include"trabajo.h"
#include"estudiante_graduado.h"
#include<iostream>
using namespace std;
trabajo::trabajo(string _nombre,string _matricula,string _carrera, int _edad,string _titulacion,string _forma_titulacion,int _anios_titulado,string _DondeTrabaja,int _TiempoTrabajando,int _Salario ):estudiante_graduado::estudiante_graduado(_nombre, _matricula,  _carrera,  _edad,_titulacion,_forma_titulacion,_anios_titulado){
DondeTrabaja=_DondeTrabaja;
TiempoTrabajando=_TiempoTrabajando;
Salario=_Salario;




}
void  trabajo::mostrarTrabajo(){
	estudiante_graduado::mostrarEstudiante_graduado();
	cout<<"Trabaja en : "<<DondeTrabaja<<endl;
	cout<<"Cuantos años lleva trabajando: "<<TiempoTrabajando<<endl;
	cout<<"Su salario es de: "<<Salario<<endl;
}


