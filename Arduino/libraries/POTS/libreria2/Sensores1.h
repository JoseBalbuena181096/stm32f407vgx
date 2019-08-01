#ifndef _Sensores1_h
#define _Sensores1_h
//#include"arduino.h"
struct pots{
	int signal_2;
	int signal_1;
	int signal_3;
};
class Sensores1{
      private: 
             pots potenciometros;
			 int pot1; 
			 int pot2;
			 int pot3;   
      
   public:
   	  
   	    
        Sensores1(int a1,int a2,int a3);
        void leerPots();
        void mostrarLeds();
};
#endif

