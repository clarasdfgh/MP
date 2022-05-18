#include "func_p4.h"
using namespace std;

//Imprime un vector de int
void mostrarVector(const int v[], int n){
	cout << "\n· ";
	for(int i=0; i<n; i++){
		cout << v[i] << " · ";
	}
	cout << endl;
}

//Imprime una cadena char*
void mostrarCadena(char * str){
	cout << endl;
	for(char * p = str; *p != '\0'; ++p){
		cout << *p;
	}
	cout << endl;
}

int tamCadena(char * str){
	int size = 0;

	for(char * p = str; *p != '\0'; ++p){
		size++;
	}

	return size;
}

//Carga un vector con valores al azar entre min, max
void cargaVector(int v[], int & n, int min, int max){
    int rango = max - min;

		n = n > MAX ? MAX : n;
		srand(time(0));

    for(int i = 0; i < n; i++)
        v[i] = rand()% rango + min;
}

//Dado un array y su longitud, devuelve un puntero al elemento mayor
//PRERREQUISITO: el puntero debe apuntar al principio del array (o a donde queramos que empiece) antes de hacer la llamada
void devuelvePunteroMaximo(int arr[], int n, int * & max){
	for(int *p = max; p < arr + n; ++p){
		if(*p >= *max){
			max = p;
		}
	}
}

//Recibe una cadena de caracteres y la invierte
void invierteCadena(char * & str){
	int len = tamCadena(str);
	char * inversa = str + 2*len;
	int pos_inversa = 0;

	for(char *p = str + len - 1; p != str - 1; --p){
		*(inversa + pos_inversa) = *p;
		pos_inversa++;
	}

	str = inversa;
}
