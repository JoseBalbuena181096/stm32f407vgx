#ifndef _contadorBinario_h
#define _contadorBinario_h
#include"arduino.h"
class contadorBinario{
   private: 
      
         int bitsContador;
      
   public:
        contadorBinario();         
        
        void set_bitsContador(int _bitsContador);      
        int get_bitsContador();
        void contador(int _Pines[12]);           
};
#endif

