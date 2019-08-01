#include <iostream>
#include<conio.h>

#include"trabajo.h"
#include"posgrado.h"
//#include"estudiante.h"
//#include"estudiante_graduado.h"
#include"estudiante_nograduado.h"

/*#include"estudiante_nograduado.cpp"
#include"estudiante_graduado.cpp"
#include"estudiante.cpp"
#include"posgrado.cpp"
#include"trabajo.cpp"
*/
using namespace std;

int main() {
	posgrado _posgrado("Jose","IM140744","MECATRONICA",21,"SI","TESIS",2,"MAESTRIA","INAOE",2);
	trabajo _trabajo("Jose","IM140744","MECATRONICA",21,"SI","TESIS",2,"EMPRESA",2,100);
	estudiante_nograduado _estudiante_nograduado("Jose","IM140744","MECATRONICA",21,7,0,10,90);
	_posgrado.mostrarPosgrado();
	cout<<"  "<<endl;
	_trabajo.mostrarTrabajo();
	cout<<"  "<<endl;
	_estudiante_nograduado.mostrarEstudiante_nograduado();
	
	getch();
	return 0;
}
