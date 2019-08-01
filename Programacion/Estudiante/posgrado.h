#ifndef POSGRADO_H
#define POSGRADO_H
#include"iostream"
#include"estudiante_graduado.h"

using namespace std;

class posgrado:public estudiante_graduado
{
  public:
    posgrado(string ,string ,string , int ,string ,string,int,string,string,int);
    void mostrarPosgrado();
    private:
    	string Posgrado;
    	string escuelaPosgrado;
    	int timpoPosgrado;
};
#endif //HERENCIA_H

