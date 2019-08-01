
#ifndef _Rectangulo_h
#define _Rectangulo_h

class Rectangulo{
	private: 
		float longitud;
		float ancho;
	public:
		//Declaracion del constructor
		Rectangulo(float Ancho, float Longitud);
		bool establecerAncho_Longitud(float alto, float largo);
	    float obtenerAncho();
		float obtenerlongitud(); 
		float perimetro();
		float area();
		void mostrar();
};
#endif



