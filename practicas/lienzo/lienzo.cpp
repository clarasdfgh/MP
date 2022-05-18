/******************************************************************************/
//	MP 21-22 Práctica 5 - lienzo.cpp
//	CLARA MARÍA ROMERO LARA
//	05985367P
//******************************************************************************/

#include "lienzo.h"
#include <iostream>

using namespace std;

void reservaMemoria(char** & M, int nf, int nc){
	M = new char*[nf];

	for (int i=0; i<nf; ++i)
		M[i] = new char[nc];
}

void liberaMemoria(char** & M, int nf, int nc){
	for(int i=0; i<nf; ++i)
		delete[] M[i];

	delete[] M;
}

void imprime(char **M, int nf, int nc){
	for(int i=0; i<nf; i++){
		for(int j=0; j<nc; j++){
			cout << " " << M[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void rellenar(char **M, int nf, int nc, char simbolo){
	for(int i=0; i<nf; i++){
		for(int j=0; j<nc; j++){
			M[i][j] = simbolo;
		}
	}
}

// x,y representan el vertice superior izquierdo del rectangulo
// la posición (0,0) corresponde al vertice superior izquierdo de la matriz m
void dibujaRectangulo(char **m, int nf, int nc, int x, int y, int ancho, int alto, char c){
	//Números negativos sustituidos por 0 automáticamente
	x = x < 0? 0 : x;
	y = y < 0? 0 : y;
	ancho = ancho < 0? 0 : ancho;
	alto  = alto < 0?  0 : alto;

	//Comprobar que x, y pertenecen al ámbito de la matriz
	x = x > nf? nf : x;
	y = y > nc? nc : y;

	//Obtener el ancho/alto total, comprobando que no se sale del ámbito de la matriz
	ancho = ancho+x > nf? nf : ancho+x;
	alto  = alto+y  > nc? nc : alto+y;

	for(int i=x; i<ancho; i++){
		for(int j=y; j<alto; j++){
			m[i][j] = c;
		}
	}
}

// construye y devuelve una matriz C con la información de A y B
// lea las indicaciones del guion de prácticas para el cálculo de filas/cols de C
char** combinar(char **A, int nf_A, int nc_A,
								char **B, int nf_B, int nc_B,
								int & nf_C, int & nc_C){
	char ** c = 0;
	nf_C = nf_A > nf_B? nf_A : nf_B;
	nc_C = nc_A + nc_B;


	reservaMemoria(c, nf_C, nc_C);
	rellenar(c, nf_C, nc_C, '.');
	//imprime(c, nf_C, nc_C);

	int diferencia_A = nf_C-nf_A;
	int diferencia_B = nf_C-nf_B;

	for(int i=0; i<nf_A; i++){
		for(int j=0; j<nc_A; j++){
			c[i+diferencia_A][j] = A[i][j];
		}
	}

	for(int i=0; i<nf_B; i++){
		for(int j = 0; j<nc_B; j++){
			c[i+diferencia_B][j+nc_A] = B[i][j];
		}
	}

	//imprime(c, nf_C, nc_C);
	return c;
}

// redimensiona M para agregar una nueva barra que corresponde a valor.
// se pinta con el carácter c
void aniadeBarra(char ** & M, int & nf, int & nc, int valor, char c){
	char ** A = 0;
	int nf_A = valor+1;
	int nc_A = 4;

	reservaMemoria(A, nf_A, nc_A);
	rellenar(A, nf_A, nc_A, '.');
	dibujaRectangulo(A, nf_A, nc_A, 1, 1, valor, 2, c);

	M = combinar(M, nf, nc, A, nf_A, nc_A, nf, nc);

	liberaMemoria(A, nf_A, nc_A);
}


// crea una matriz donde se pintarán todos los datos del array barras.
void pintaBarras(char ** &M, int & nf, int & nc, int *barras, int n, char c){
	//num columnas = n*4 (2 bloques para cada barra, 2 espacios para cada barra)
	nc = n * 4;

	//num filas = altura de barra máxima +1
	nf = 0;

	for(int i=0; i<n; i++){
		if(barras[i] >= nf){
			nf = barras[i];
		}
	}

	nf += 1;

	reservaMemoria(M, nf, nc);
	rellenar(M, nf, nc, '.');

	int barra = 1;

	for(int i=0; i<n; i++){
		dibujaRectangulo(M, nf, nc, nf - barras[i], barra, barras[i], 2, c);
		barra += 4;
	}
}
