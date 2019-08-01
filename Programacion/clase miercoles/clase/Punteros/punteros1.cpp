#include<iostream>
#include<conio.h>
using namespace std;
int main(){
	int num,*dir_num;
	num=20;
	dir_num=&num;
	cout<<"Numero: "<<*dir_num<<endl;//se coloca * para que muestre el valor almacenado en esa direccion de memoria
	cout<<"Direccion de memoria:"<<dir_num<<endl;//cuando no se coloca  se muestra la direccion  de memoria
	getch();
	return 0;
}
