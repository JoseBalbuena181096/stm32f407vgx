#ifndef _contadorBinario_h
#define _contadorBinario_h
class contadorBinario{
	private: 
		
			int bitsContador;
		
	public:
	      contadorBinario();			
	      contadorBinario(int _bitsContador);
		  void set_bitsContador(int _bitsContador);		
		  int get_bitsContador();
		  void set_Pines(int _Pines[12]);
		  void contador(int _Pines[12]);		  	
};
#endif

