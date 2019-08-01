#include"DibujarCuadro.h"
DibujarCuadro::DibujarCuadro(){
	lado=4;
}

void DibujarCuadro::establecerLado(int _lado){
	lado=_lado;
}

 void DibujarCuadro::imprimirCuadro(){
 	char matriz[20][20];
 	for(int i=0;i<20;i++){
 	    for(int j=0;j<20;j++){
 	    	matriz[i][j]=' ';
			 }
		 }	 
	for(int i=0;i<lado;i++){
 	   
 	    	matriz[i][0]='*';
			 
		 }
	for(int i=0;i<lado;i++){
 	   
 	    	matriz[i][lado-1]='*';
			 
		 }		 
		 	
	for(int j=0;j<lado;j++){
 	   
 	    	matriz[0][j]='*';
			 
		 }	
		for(int j=0;j<lado;j++){
 	   
 	    	matriz[lado-1][j]='*';
			 
		 }		 	 

	for(int i=0;i<lado;i++){
 	    for(int j=0;j<lado;j++){
 	    	
 	    		cout<<matriz[i][j];	  
			 	 
 	    	  	
		 }	 
		 cout<<"\n";
	 }
	 
	 

 }
