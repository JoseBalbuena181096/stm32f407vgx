#ifndef ESTUDIANTE_GRADUADO_H
#define ESTUDIANTE_GRADUADO_H
#include"iostream"
#include"estudiante.h"
using namespace std;

class estudiante_graduado:public estudiante
{
  public:
    estudiante_graduado(string ,string ,string , int ,string ,string,int );
    void mostrarEstudiante_graduado();
    private:
    	string titulacion;
    	string forma_titulacion;
    	int anios_titulado;
};
#endif //HERENCIA_H

