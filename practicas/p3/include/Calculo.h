#ifndef CALCULO_H
#define CALCULO_H


#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <iomanip>

#include "GestionArrays.h"

using namespace std;

const int FIL = 12;
const int COL = 31;
const string MESES[FIL] = {"ENE", "FEB", "MAR", "ABR", "MAY", "JUN",
													 "JUL", "AGO", "SEP", "OCT", "NOV", "DIC"};

void listaMeses(int v[], int n);
void mostrarMatriz(const int m[][COL], int util_fil, int util_col);
void rellenarMatriz(int m[][COL], int util_fil, int util_col, int min, int max);
void resumenMaximasMinimas(const int m[][COL], int util_fil, int util_col, int maximas[], int minimas[], int tam_v);
float mediaMensualAjustada(const int m[][COL], int util_fil, int util_col, int mes);
bool secuenciaDiasCalidosMes(int mes[], int util_col, int d, int t);
void secuenciaDiasCalidos(int m[][COL], int util_fil, int util_col, int t, int d, int indice[], int & n_indice);

#endif
