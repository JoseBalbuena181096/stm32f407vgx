#include<iostream>
#include<conio.h>
using namespace std;
struct Punto{
	double x,y;
};
Punto operator+(const Punto &p,const Punto &q);//cuando no hay sobrecarga Punto suma (const Punto &p,const Punto &q);
int main(){//int main(int argc,char *argv[]) es los mismo
	//delclar ab,r de tipo punto
	Punto a,b,c,r;
	a.x=0.0;
	a.y=-1.5;
	b.x=3.5;
	b.y=1.5;
	c.x=2;
	c.y=3;
	
    r=a+b+c;//r=suma(a,b); se utiliza cuando no hay sobrecarga de operadores
    cout<<r.x<<" "<<r.y<<endl;
	getch();
	return 0;
}

Punto operator+(const Punto &p,const Punto &q){//funcion para la sobrecarga de operadores
	Punto r;
	r.x=p.x+q.x;
	r.y=p.y+q.y;
	return r;
}
