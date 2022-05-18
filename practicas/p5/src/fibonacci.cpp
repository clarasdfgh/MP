#include <iostream>
#include <cstdlib>

using namespace std;

void mostrarVector(const int v[], int n){
	cout << "\n· ";
	for(int i=0; i<n; i++){
		cout << v[i] << " · ";
	}
	cout << endl;
}


void ampliar(int* & v, int previo, int nuevo){
	if(previo < nuevo){
		int *v_ampliado = new int[nuevo];

		for(int i=0; i<previo; i++){
			v_ampliado[i] = v[i];
		}

		delete []v;
		v = v_ampliado;
	}
}


void fibonacci(int n, int extra){
	int * sucesion = new int[n];

	sucesion[0] = 0;
	sucesion[1] = 1;

	for(int i=2; i<n; i++){
		sucesion[i] = sucesion[i-1] + sucesion[i-2];
	}

	if(extra > 0){
		ampliar(sucesion, n, n+extra);
	}

	for(int i=n; i<n+extra; i++){
		sucesion[i] = sucesion[i-1] + sucesion[i-2];
	}

	mostrarVector(sucesion, n+extra);

	delete [] sucesion;
}

int main(int argc, char * argv[]){
	int n 		= 2;
	int extra = 0;

	//Comprobación - n debe ser mínimo 2, y extra no puede ser negativo
	n     = atoi(argv[1]) > n? atoi(argv[1]) 			: 2;
	extra = atoi(argv[2]) > extra? atoi(argv[2]) 	: 0;

	cout << "============================" << endl;
	cout << "Fibonacci - n= " << n << " +" << extra << endl;
	cout << "============================" << endl;

	if(n+extra > 47){
		cout << "Nota - El número máximo del tipo int en c++ es 2,147,483,647." << endl;
		cout << "A partir de la iteración 48, se produce desbordamiento y aparecen " << endl;
		cout << "números negativos. Esto se solucionaría con otros tipos, pero la" << endl;
		cout << "práctica especifica int y que no haya fugas, así que así se queda. " << endl;
	}

	fibonacci(n, extra);

	return(0);
}
