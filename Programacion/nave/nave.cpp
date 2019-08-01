#include<stdio.h>
#include<windows.h>
#include<conio.h>//para detectar  presionar la teclas
#define ARRIBA 72
#define IZQUIERDA 75
#define DERECHA 77
#define ABAJO 80
void gotoxy(int x,int y){//Funcion  al llamar la funcion se pasan por parametros las coordenadas x ,y
	HANDLE hCon;//TIpo de nombre a esta vatiable  recuperar el identificador de la consola
	hCon = GetStdHandle(STD_OUTPUT_HANDLE);//funcion para recuperar el identificador de la consola
	COORD dwPos;//Objeto para la posicion
	dwPos.X=x;//llamamos sua atributo en x
	dwPos.Y=y;//llamamos sua atributo en y
	SetConsoleCursorPosition(hCon,dwPos);
}
void pintar_limites(){
	for(int i=2;i<78;i++){
		gotoxy(i,3); printf("%c",205);
		gotoxy(i,33); printf("%c",205);
	}
	for(int i=4;i<33;i++){
		gotoxy(2,i); printf("%c",186);
		gotoxy(77,i); printf("%c",186);
	}
	gotoxy(2,3);printf("%c",201);
	gotoxy(2,33);printf("%c",200);
	gotoxy(77,3);printf("%c",187);
	gotoxy(77,33);printf("%c",188);
}

//Funcion para quitar el parpadeo del cursor
void OcultarCursor(){
	HANDLE hCon;
	hCon = GetStdHandle(STD_OUTPUT_HANDLE);	
	CONSOLE_CURSOR_INFO  cci;//Es una estructura con la que podemos controlar la apariencia del cursor en pantallla
	cci.dwSize=2;
	cci.bVisible=FALSE;//ELCURSOR SEMUESTRAE EN PANTALLA
	SetConsoleCursorInfo(hCon,&cci);//&cci pas de parametros por referencia 
}




///clase 
class NAVE{
	//ATRIBUTOS
	private: int x,y,corazones;//nose puede accedera atros metodos 
	public: 
		////constructor que inicializa los atributos de la clase 
		NAVE(int _x,int _y, int _corazones):x(_x),y(_y),corazones(_corazones){
		};
		void pintar();
		void borrar();
		void mover();
		void pintar_corazones();
		
};
void NAVE::pintar(){//LOS :: pasa acceder a metodos de la clase
	gotoxy(x,y);printf("  %c",30);//caracter asociado al numero 30 en codigo asiic
	gotoxy(x,y+1);printf(" %c%c%c",40,207,41);
	gotoxy(x,y+2);printf("%c%c %c%c",30,190,190,30);
}
void NAVE::borrar(){
	gotoxy(x,y);printf("     ");
	gotoxy(x,y+1);printf("     ");
	gotoxy(x,y+2);printf("     ");
}
void NAVE::mover(){
		if(kbhit()){///kbhit() Funcion para dectar si se ha presionado una tecla Y LA TECLA PRESIONADA
			char tecla=getch();//guardar la tecla que se presiona
			borrar();
			////////definiendo limites y moviendo
			if(tecla==IZQUIERDA && x>3) x--;//disminulle la posicion en x al presionar la tecla j
			if(tecla==DERECHA && x+6<77) x++;//aumenta  la posicion en x al presionar la tecla l
			if(tecla==ARRIBA && y>4) y--;//disminulle la posicion en y al presionar la tecla i
			if(tecla==ABAJO &&y+3<33) y++;//aumenta la posicion en y al presionar la tecla j
			if(tecla=='e') corazones--;
			if(tecla=='a') corazones++;
			pintar();
			pintar_corazones();
		}
	
}
void NAVE::pintar_corazones(){
	gotoxy(64,2);printf("Salud");
	gotoxy(70,2);printf("     ");
	for(int i=0;i<corazones;i++){
		gotoxy(70+i,2);printf("%c",3);
	}
	
}




int main(){
	
	OcultarCursor();
	pintar_limites();
	NAVE N(10,10,3);
	N.pintar();
	N.pintar_corazones();
	///iteraciones llamando metodos 
	bool game_over=false;
	while(!game_over){//Hacemos el argumento  verdad 
	
	    N.mover();
		Sleep(30);///detiene la ejecucion del programa por 30 segundos
		
	
	}
	
	getch();
	return 0;
}
