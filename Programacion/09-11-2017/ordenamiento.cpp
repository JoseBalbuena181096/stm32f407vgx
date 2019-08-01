
  #include <iostream>
  using std::cout;
 using std::endl;
 
  #include <iomanip>
  using std::setw;
 #include<conio.h>
 void ordenamientoSeleccion( int * const, const int ); // prototipo
 void intercambiar( int * const, int * const ); // prototipo
 int main()
  {
 const int tamanioArreglo = 10;
  int a[ tamanioArreglo ] = { 2, 6, 4, 8, 10, 12, 89, 68, 45, 37 };
  cout << "Elementos de datos en el orden original\n";
 
  for ( int i = 0; i < tamanioArreglo; i++ )
  cout << setw( 4 ) << a[ i ];
 
  ordenamientoSeleccion( a, tamanioArreglo ); // ordena el arreglo

 cout << "\nElementos de datos en orden ascendente\n";

 for ( int j = 0; j < tamanioArreglo; j++ )
 cout << setw( 4 ) << a[ j ];

 cout << endl;
 getch();
 return 0; // indica que termin� correctamente
 
 } // fin de main
 // funci�n para ordenar un arreglo
 void ordenamientoSeleccion( int * const arreglo, const int tamanio )
 {
 int menor; // sub�ndice del elemento m�s peque�o

 // itera a trav�s de tamanio - 1 elementos
 for ( int i = 0; i < tamanio - 1; i++ )
 {
 menor = i; // primer sub�ndice del resto del arreglo


 // itera hasta encontrar el sub�ndice del elemento m�s peque�o
 for ( int subindice = i + 1; subindice < tamanio; subindice++ )

 if ( arreglo[ subindice ] < arreglo[ menor ] )
 menor = subindice;

 intercambiar( &arreglo[ i ], &arreglo[ menor ] );
} // fin de if
 } // fin de la funci�n ordenamientoSeleccion

// intercambia los valores en las ubicaciones de memoria
 // a las que apuntan elemento1Ptr y elemento2Ptr
 void intercambiar( int * const elemento1Ptr, int * const elemento2Ptr )
{
 int contenido = *elemento1Ptr;
 *elemento1Ptr = *elemento2Ptr;
*elemento2Ptr = contenido;

 } // fin de la funci�n intercambiar
