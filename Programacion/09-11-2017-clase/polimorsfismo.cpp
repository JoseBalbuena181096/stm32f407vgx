#include<iostream>
#include<conio.h>

using namespace std;


//Definicon de la claase persona
class Persona{
	private:
		string nombre;
		int edad;
	public: 
		Persona(string,int);
		//viltual es una palabra clave permite el polimorfismo 
		//indica que esa funcion tiene polimorfismo
		virtual	void mostrar();
		
};
Persona::Persona(string _nombre,int _edad){
	nombre=_nombre;
	edad=_edad;	
}
void Persona::mostrar(){
	cout<<"Nombre: "<<nombre<<endl;
	cout<<"Edad: "<<edad<<endl;
}
class Alumno:public Persona{
	private:
		float notaFinal;
	public:
		Alumno(string,int,float);
		void mostrar();
};
class Profesor:public Persona{
	private: 
		string materia;
	public:
			Profesor(string,int,string);
			void mostrar();
};
Profesor::Profesor(string _nombre,int _edad, string _materia):Persona(_nombre,_edad){
	materia=_materia;
}
void Profesor::mostrar(){
	Persona::mostrar();
	cout<<"Materia : "<<materia<<endl;
}
Alumno::Alumno(string _nombre,int _edad, float _notaFinal):Persona(_nombre,_edad){
	notaFinal=_notaFinal;
}
void Alumno::mostrar(){
	Persona::mostrar();
	cout<<"Nota final: "<<notaFinal<<endl;
	}
int main(){
	Persona *persona[3];//declara un puntero de clase persona que es un arreglo
	int array[3]={0,1,0};
	
	cout<<"Array: "<<1+*array<<endl;
    cout<<"Valor de persona"<<persona<<endl;
    cout<<"Direccion del puntero persona"<<*persona<<endl;
    cout<<"Direccion del puntero persona[0]"<<&persona[0]<<endl;
	persona[0]=new Alumno("Jose",21,5);
	persona[1]=new Alumno("Jose2",22,10);
	persona[2]=new Alumno("Jose3",21,10);
	//namePTR->nameFuntion()
		for(int i=0;i<=2;i++){
			persona[i]->mostrar();
			cout<<" "<<endl;
		}

	getch();
	return 0;
}

