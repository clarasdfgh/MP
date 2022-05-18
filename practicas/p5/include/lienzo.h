#ifndef LIENZO_H
#define LIENZO_H

void reservaMemoria(char** & M, int nf, int nc);

void liberaMemoria(char** & M, int nf, int nc);

void imprime(char **M, int nf, int nc);

void rellenar(char **M, int nf, int nc, char simbolo);

// x,y representan el vertice superior izquierdo del rectangulo
// la posición (0,0) corresponde al vertice superior izquierdo de la matriz m
void dibujaRectangulo(char **m, int nf, int nc, int x, int y, int ancho, int alto, char c);

// construye y devuelve una matriz C con la información de A y B
// lea las indicaciones del guion de prácticas para el cálculo de filas/cols de C
char** combinar(char **A, int nf_A, int nc_A,
								char **B, int nf_B, int nc_B,
								int & nf_C, int & nc_C);

// redimensiona M para agregar una nueva barra que corresponde a valor.
// se pinta con el carácter c
void aniadeBarra(char ** & M, int & nf, int & nc, int valor, char c);


// crea una matriz donde se pintarán todos los datos del array barras.
void pintaBarras(char ** &M, int & nf, int & nc, int *barras, int n, char c);


#endif
