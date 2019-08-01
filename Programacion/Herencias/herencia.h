#ifndef HERENCIA_H
#define HERENCIA_H
#include"iostream"
using namespace std;

class Persona
{
  public:
    Persona(string,int);
    void mostrarPersona();
  private:
  	string nombre;
  	int edad;
};
#endif //HERENCIA_H

