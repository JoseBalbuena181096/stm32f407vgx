#include<iostream>
#include<conio.h>
using namespace std;
int main(){
	int n;
	int &r=n;
	int *Puntero;//Declaremos un punteroo de tipo entero
	Puntero=&n;//Appunta a n		
    n=3;
    *Puntero=8;
    cout<<"Valor de n: "<<n<<endl;
    cout<<"Direccion de n: "<<&n<<endl;
    cout<<"r Referencia de r"<<r<<endl;
    cout<<"Valor puntero"<<Puntero<<endl;
    //Derreferencia 
    cout<<"Direccion de r"<<&r<<endl;
    cout<<"Direccion de puntero"<<&Puntero<<endl;
    cout<<"Ladireccion de puntero"<<*Puntero<<endl;
	getch();
	return 0;
}

