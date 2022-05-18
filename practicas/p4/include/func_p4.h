#ifndef FUNC_P4_H
#define FUNC_P4_H

#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

const int MAX = 20;

void mostrarVector(const int v[], int n);
void mostrarCadena(char * str);
int tamCadena(char * str);
void cargaVector(int v[], int & n, int min, int max);
void devuelvePunteroMaximo(int arr[], int n, int * & max);
void invierteCadena(char * & str);

#endif
