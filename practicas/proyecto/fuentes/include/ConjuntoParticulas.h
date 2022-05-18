#ifndef _CONJUNTOPARTICULAS_
#define _CONJUNTOPARTICULAS_

#include <iostream>
#include "Particula.h"

static const int TAM_BLOQUE = 3;

class ConjuntoParticulas {
private:
	Particula *set;
	int capacidad;
	int utiles;

	void reservarMemoria();
	void liberarMemoria();
	void redimensiona();

public:

	ConjuntoParticulas();
	ConjuntoParticulas(int n);
	~ConjuntoParticulas();

	int getCapacidad();
	int getUtiles();
	void agregaParticula(Particula p);
	void borraParticula(int pos);
	Particula obtieneParticula(int pos);
	void reemplazaParticula(int pos, Particula particula);
	void moverParticulas(float ancho, float alto);
	void rebotar(float ancho, float alto);
	void mostrarInfo();

}
#endif
