#ifndef GESTION_ARRAY_H
#define GESTION_ARRAY_H

#include<iostream>

using namespace std;

const int MAX = 20;

void mostrarVector(const int v[], int n);
void cargaVector(int v[], int n, int min, int max);
void cargaVectorOrdenado(int v[], int n, int inicial, int incremento);
void cargaValor(int v[], int n, int m);
int obtieneMax(const int v[], int n);
int obtieneMin(const int v[], int n);
void obtieneMaxMin(const int v[], int n, int & pos_max, int & pos_min);
float promedioAjustado(const int v[], int n);
bool todosDistintos(const int v[], int n);
void masFrecuente(const int v[], int n, int & valor, int & frec);
bool estaOrdenado(const int v[], int n);
void mezclaOrdenada(const int v1[], int n1, const int v2[], int n2, int v3[], int & n3);


#endif
