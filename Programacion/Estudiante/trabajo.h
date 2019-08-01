#ifndef TRABAJO_H
#define TRABAJO_H
#include"iostream"
#include"estudiante_graduado.h"

using namespace std;

class trabajo:public estudiante_graduado
{
  public:
    trabajo(string ,string ,string , int ,string ,string,int,string,int,int);
    void mostrarTrabajo();
    private:
    	string DondeTrabaja;
    	int TiempoTrabajando;
    	int Salario;
};
#endif //HERENCIA_H

