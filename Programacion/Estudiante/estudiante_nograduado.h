#ifndef ESTUDIANTE_NOGRADUADO_H
#define ESTUDIANTE_NOGRADUADO_H
#include"iostream"
#include"estudiante.h"
using namespace std;

class estudiante_nograduado:public estudiante
{
  public:
    estudiante_nograduado(string ,string ,string , int ,int,int,int,float);
    void mostrarEstudiante_nograduado();
    private:
    	int grado;
    	int materias_reprovadas;
    	int materias_aprovadas;
    	float promedio;
};
#endif //HERENCIA_H

