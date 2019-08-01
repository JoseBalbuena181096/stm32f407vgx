#include<iostream>
#include<conio.h>
using std::cout;
using std::cin;
using std::endl;

class Primo{
	private:
		int numero; 
	public:
		Primo(int _numero){
			numero=_numero;
		}
		void NumerosPrimos(){
     		for(int j=2;j<=numero;j++){
				int contador=0;
				for(int i=1;i<=numero;i++){
					if(j%i==0){
						contador++;	
					}
				}
				if(contador<=2){
					cout<<j<<endl;
				}
			}
		}
	};

int main(){
	int n;
	cout<<"///////////////////////////////////////////////"<<endl; 
	cout<<"// PROGRAMA PARA CALCULAR LOS NUMEROS PRIMOS //"<<endl;
	cout<<"///////////////////////////////////////////////"<<endl; 
	cout<<" "<<endl;
	cout<<"Introduce el numero hasta donde se calcularan los numeros primos:"<<endl; cin>>n;
	cout<<" "<<endl; 
	Primo number(n);
	number.NumerosPrimos();	
	getch();
	return 0;
}
