//Trasmicion de Direcciones
//Ejemplo Intercambiar el valor de 2 variables
 

#include<iostream>
#include<conio.h>

using namespace std;
void intercambio(float *,float *);//dos direcciones de memoria donde hay guardado dos numeros floatantes
int main(){
   float num1=20.8,num2=6.78;
    cout<<"Primer Numero:"<<num1<<endl;
    cout<<"Segundo Numero:"<<num2<<endl;
    
	intercambio(&num1,&num2);
     cout<<"\n\nDespues del intercambio: \n\n";
       cout<<"El nuevo valor del primer Numero:"<<num1<<endl;
    cout<<"Elnuevo valor del segundo Numero:"<<num2<<endl;
	getch();
	return 0;
}
void intercambio(float *dirNum1,float *dirNum2){
	float aux;
	//intercambiar los valores de las variables
	aux=*dirNum1;
	*dirNum1=*dirNum2;
	*dirNum2=aux;
}

