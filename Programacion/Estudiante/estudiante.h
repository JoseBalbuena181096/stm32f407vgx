#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H
#include"iostream"
using namespace std;

class estudiante
{
  public:
    estudiante(string,string,string,int);
    void mostrarEstudiante();
  private:
  	string nombre,carrera,matricula;
  	int edad;
};
#endif

