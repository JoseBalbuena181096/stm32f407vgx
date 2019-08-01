//correspondencia entre array y punteros
#include<iostream>
#include<conio.h>
using namespace std;
int main(){
	int numeros[]={1,2,3,4,5};
	//crar una bariable puntero para msytar el viiector
	int *dir_numeros;
	dir_numeros=numeros;//dir_numeros=numeros[0];
	for(int i=0;i<5;i++)
	{
		cout<<"Elemento del vector["<<i<<"]:"<<*dir_numeros++<<endl;
	
	}
	
		for(int i=0;i<5;i++)
	{
	cout<<numeros[i]<<"La posicion es: "<<dir_numeros++<<endl;
	}
	
	getch();
	return 0;
}

