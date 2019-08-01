#include"Rectangulo.h"
#include<iostream>
#include<conio.h>
using std::cout;
using std::cin;
using std::endl;
#include<string>
using std::string;
using std::getline;

		//Declaracion del constructor
		Rectangulo::Rectangulo(float Ancho, float Longitud){
			establecerAncho_Longitud(Ancho, Longitud);
		}
		
		bool 	Rectangulo::establecerAncho_Longitud(float alto, float largo){
						
			bool a=0,c=0,b=0;
			if(alto>0.0 && alto<20.0){
			ancho=alto;
			a=1;			
			}
			else{
			
				a=0;
			}	
		    if(largo>0.0 && largo<20.0){
		    	longitud=largo;
		    	b=1;
			}			
			else{
					
				b=0;
			}
			
			if(a==0||b==0){
				cout<<"los valores que introdujo no estan entre 0 y 20"<<endl;
				c=0;
			}
			else{
				c=1;
			}
			
				
		return c;			
				
		}
	   float  Rectangulo::obtenerAncho(){
			return ancho;
		}
		
	    
		
		
		float Rectangulo::obtenerlongitud(){
			return longitud;
	   } 


		float Rectangulo::perimetro(){
			
			float c=(2*obtenerAncho())+(2*obtenerlongitud());
			return c;
		}
		
	float 	Rectangulo::area(){
		
			float c=obtenerlongitud()*obtenerAncho();
			return c;
		}
		
		
		void Rectangulo::mostrar(){
  		     
			cout<<"El perimetro es \n "<< perimetro()<<endl;
			cout<<"El area es \n "<< area()<<endl;
			
	}
	
		

