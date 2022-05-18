#include "ConjuntoParticulas.h"

#include <cmath>
#include <iostream>
#include <cstdlib>
#include <ctime>


class ConjuntoParticulas {
private:
	Particula *set;
	int capacidad;
	int utiles;

	void reservarMemoria(Particula* & v, int n){
		int * v = new int[n];
	}

	void liberarMemoria(Particula* &v){
		delete []v;
	}

	void redimensiona(Particula* & v, int previo, int nuevo){
		if(previo < nuevo){
			int *v_ampliado = new int[nuevo];

			for(int i=0; i<previo; i++){
				v_ampliado[i] = v[i];
			}

			liberarMemoria(v)
			v = v_ampliado;
	 	} else{
			capacidad = nuevo;
		}
	}

public:

	ConjuntoParticulas(){
		capacidad = 0;
		utiles = 0;
		*set = new Particula[capacidad]
	}

	ConjuntoParticulas(int n){
		capacidad = n;
		utiles = n;
		*set = new Particula[capacidad]

		for(int i=0; i<capacidad; i++){
			set[i] = new Particula()
		}
	}

	~ConjuntoParticulas(){
		liberarMemoria(set);
	}

	int getCapacidad(){
		return capacidad;
	}

	int getUtiles(){
		return utiles;
	}

	void agregaParticula(Particula p);
	void borraParticula(int pos);
	Particula obtieneParticula(int pos);
	void reemplazaParticula(int pos, Particula particula);
	void moverParticulas(float ancho, float alto);
	void rebotar(float ancho, float alto);
	void mostrarInfo();

}
