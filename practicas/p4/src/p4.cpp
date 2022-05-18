#include <iostream>
#include "func_p4.h"

using namespace std;

int main(){
	int vector[MAX];
	int usados = 10;
	int * p;

	cargaVector(vector, usados, 10, 50);
	mostrarVector(vector, usados);

	cout << endl;

	p = vector;
	devuelvePunteroMaximo(vector, usados, p);
	cout << "Mayor del array: " << *p << endl;

	p = vector;
	devuelvePunteroMaximo(vector, usados/2, p);
	cout << "Mayor de la primera mitad: " << *p << endl;

	p = vector + (usados/2);
	devuelvePunteroMaximo(vector, usados, p);
	cout << "Mayor de la segunda mitad: " << *p << endl;

	char cad[] = "0123456789";
	char * str = cad;

	mostrarCadena(str);
	cout << "Tamaño de la cadena: " << tamCadena(cad) << endl;
	invierteCadena(str);
	cout << "Cadena inversa: ";
	mostrarCadena(str);


	return(0);
}
