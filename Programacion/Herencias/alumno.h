#ifndef ALUMNO_H
#define ALUMNO_H
#include"iostream"
#include"herencia.h"
using namespace std;

class Alumno:public Persona
{
  public:
    Alumno(string,int,string,float);
    void mostrarAlumno();
    private:
    	string matricula;
    	float notaFinal;
};
#endif //HERENCIA_H

