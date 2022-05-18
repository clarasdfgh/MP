#include <iostream>
#include "Calculo.h"

//Dado un array de enteros que representan meses, imprime su nombre en vez de el número
void listaMeses(int v[], int n){

	cout << endl << "\t ";
	for(int i=0; i<n; i++){
		cout << MESES[v[i]] << " - ";
	}
	cout << endl;
}

//Dada una matriz, la imprime por pantalla
void mostrarMatriz(const int m[][COL], int util_fil, int util_col){
	for(int i=0; i<util_fil; i++){
		cout << endl << MESES[i] << " - ";
		for(int j=0; j<util_col; j++){
			cout << setw(2) << setfill('0') <<  m[i][j] << "  ";
		}
	}
}

//Rellena una matriz de elementos aleatorios entre max y min
void rellenarMatriz(int m[][COL], int util_fil, int util_col, int min, int max){
	int num_valores = max - min + 1;

	for(int i=0; i<util_fil; i++){
		for(int j=0; j<util_col; j++){
			m[i][j] = (rand() % num_valores) + min;
		}
	}
}

//Devuelve dos vectores de 12 elementos, con las temperaturas máximas y mínimas de cada mes
void resumenMaximasMinimas(const int m[][COL], int util_fil, int util_col, \
													 int maximas[], int minimas[], int tam_v){
	for(int i=0; i<util_fil; i++){
		maximas[i] = m[i][obtieneMax(m[i], util_col)];
		minimas[i] = m[i][obtieneMin(m[i], util_col)];
	}
}

//Devuelve la temperatura promedio ajustada (eliminando temperatura max y min) de un mes
float mediaMensualAjustada(const int m[][COL], int util_fil, int util_col, int mes){
	return promedioAjustado(m[mes], util_col);
}

//Dada una temperatura t, un número de días d y un mes, devuelve si en ese mes existe una
//secuencia de d días en los que se superó la temperatura t
bool secuenciaDiasCalidosMes(int mes[], int util_col, int d, int t){
	int racha = 0;

	for(int i=0; i<util_col && racha < d; i++){
		racha = mes[i] >= t ? racha+1 : 0;
	}

	return racha >= d;
}

//Dada una temperatura t, un número de días d, devuelve una lista de meses en
//los que hubo una secuencia de d días en los que se superó la temperatura t
void secuenciaDiasCalidos(int m[][COL], int util_fil, int util_col, int t, int d, int indice[], int & n_indice){
	n_indice = 0;

	for(int i=0; i<util_fil; i++){
		if(secuenciaDiasCalidosMes(m[i], util_col, d, t)){
			indice[n_indice] = i;
			n_indice++;
		}
	}
}
