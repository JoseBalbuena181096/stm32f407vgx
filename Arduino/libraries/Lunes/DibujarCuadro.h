#ifndef _DibujarCuadro_h
#define _DibujarCuadro_h
#include<iostream>
#include<conio.h>
using namespace std;
class DibujarCuadro{
   private: 
      
         int lado;
      
   public:
        DibujarCuadro();         
        void establecerLado(int _lado);     
        void imprimirCuadro();           
};
#endif

