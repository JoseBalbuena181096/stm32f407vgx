#ifndef ESTRUCTURA_H
#define ESTRUCTURA_H

//estructura para guardar la lectura de 3 canales
struct Pots
{
   int c_analogico_1;
   int c_analogico_2;
   int c_analogico_3;
  
};

class Estructura
{
  public:
  Estructura(int, int, int);  //constructor
  void leerPonteciometro();   //lee el valor analogico en los 3 canales
  void mostrarLectura();      //imprime el valor de tipo Pots
  private:
  Pots potenciometros;
  int Pot1;
  int Pot2;
  int Pot3;
  
};
#endif 

