#include "GestionArrays.h"

using namespace std;

//Imprime un vector
void mostrarVector(const int v[], int n){
	cout << "\n ·";
	for(int i=0; i<n; i++){
		cout << v[i] << " · ";
	}
	cout << "\n";
}

//Carga un vector con valores al azar entre min, max
void cargaVector(int v[], int n, int min, int max){
    int rango = max - min;
    for(int i = 0; i < n; i++)
        v[i] = random()% rango + min;
}

//Genera un vector ordenado. El primer valor es "inicial" y los siguientes
//son incrementos al azar entre [0, incremento-1]
void cargaVectorOrdenado(int v[], int n, int inicial, int incremento){

    v[0] = inicial;
    for(int i = 1; i < n; i++)
        v[i] = v[i-1] + random() % incremento;
}

//Carga un vector que contiene un único número m en todas sus posiciones
void cargaValor(int v[], int n, int m){
	for(int i = 0; i < n; i++)
			v[i] = m;
}

//Devuelve la posición del elemento maximo
int obtieneMax(const int v[], int n){
	int pos_max = 0;

	for(int i=0; i<n; i++){
		if(v[i] >= v[pos_max]){
			pos_max = i;
		}
	}

	return pos_max;
}

//Devuelve la posición del elemento minimo
int obtieneMin(const int v[], int n){
	int pos_min = 0;

	for(int i=0; i<n; i++){
		if(v[i] <= v[pos_min]){
			pos_min = i;
		}
	}

	return pos_min;
}

//Devuelve la posición del elemento maximo y mínimo. No toma en cuenta si están repetidos
void obtieneMaxMin(const int v[], int n, int & pos_max, int & pos_min){
	pos_max = obtieneMax(v,n);
	pos_min = obtieneMin(v,n);
}

//Devuelve la media de los elementos del array excluyendo los elementos max y min
float promedioAjustado(const int v[], int n){
	int pos_max, pos_min;
	float sumatorio = 0;

	if(n >= 3){
		obtieneMaxMin(v, n, pos_max, pos_min);

		for(int i=0; i<n; i++){
			sumatorio += v[i];
		}

		sumatorio -= v[pos_max];
		sumatorio -= v[pos_min];
	}


	return sumatorio/(n-2);
}

//Devuelve si todos los elementos del vector son distintos
bool todosDistintos(const int v[], int n){
	bool todos_distintos = true;

	for(int i=0; i<n && todos_distintos; i++){
		for(int j=i+1; j<n && todos_distintos; j++){
			if(v[i] == v[j]){
				todos_distintos = false;
			}
		}
	}

	return todos_distintos;
}

//Devuelve el elemento más frecuente y su frecuencia.
//Si todos son distintos, devuelve el primer elemento y su frecuencia (1)
void masFrecuente(const int v[], int n, int & valor, int & frec){
	if(todosDistintos(v,n) == true){
		valor = v[0];
		frec = 1;
	} else{
			int pos_max = obtieneMax(v, n);
			int pos_min = obtieneMin(v,n);
			const int MAX_V = v[pos_max];
			const int MIN_V = v[pos_min];
			const int TAM = MAX_V + 1;
			const int TAM_NEG = -1 * MIN_V + 1;

			//Tenemos que saber si hay negativos en el array, porque cambia el algoritmo
			bool negativos = MIN_V < 0? true : false;

			int frecuencias[TAM] = {0};					//Array del 0 al elemento más alto del array, inicializado a 0
			int frecuencias_neg[TAM_NEG] = {0}; //Array del 0 al valor absoluto del elemento más negativo, inicializado a 0


			for(int i=0; i<n; i++){
				//La posición en el vector de frecuencias la da el valor de v, o su valor absoluto si es negativo
				v[i] > 0 ? frecuencias[v[i]]++ : frecuencias_neg[-1*v[i]]++;
			}

			int max_freq = frecuencias[obtieneMax(frecuencias, TAM)];
			int max_freq_neg = negativos ? frecuencias_neg[obtieneMax(frecuencias_neg, TAM_NEG)] : -1;

			if(max_freq > max_freq_neg){
				valor = obtieneMax(frecuencias, TAM);					//El max en el vector de frecuencias es el mas repetido
				frec  = frecuencias[valor];
			} else{
				valor = -obtieneMax(frecuencias_neg, TAM_NEG);		//El max en el vector de frecuencias negativas es el mas repetido
				frec  = frecuencias_neg[-valor];
			}
	}
}

//Devuelve si el array está ordenado de forma ascendente
bool estaOrdenado(const int v[], int n){
	bool ordenado = true;

	for(int i=0; i<n-1 && ordenado; i++){
		if(v[i] > v[i+1]){
			ordenado = false;
		}
	}

	return ordenado;
}

//Dados dos arrays ordenados crecientemente, los combina y pasa en orden ascendente al vector v3
void mezclaOrdenada(const int v1[], const int n1, const int v2[], const int n2, int v3[], int & n3){
	if(estaOrdenado(v1,n1) && estaOrdenado(v2,n2)){
		int i = 0, j = 0, k = 0;
		n3 = n1 + n2 < MAX ? n1+n2 : MAX;

		bool v1_cont = true;
		bool v2_cont = true;

		while ((v1_cont || v2_cont) && k < MAX){	//Mientras quede alguno de los dos que no se haya recorrido entero...

			if (v1_cont && v2_cont){		//Si todavía no se ha recorrido ninguno entero...
				if(v1[i] < v2[j]){				//...comprobamos el menor y lo metemos, aumentando los iteradores correspondientes
					v3[k++] = v1[i++];
					v1_cont = i < n1;
				} else{
					v3[k++] = v2[j++];
					v2_cont = j < n2;
				}

			} else{											//Cuando alguno de los dos ya se ha recorrido entero...
				if(v1_cont){							//...metemos los elementos del otro de golpe
					for(int p=i; p<n1; p++){
						v3[k] = v1[p];
						k++;
					}
					v1_cont = false;

				} else{
					for(int p=j; p<n2; p++){
						v3[k] = v2[p];
						k++;
					}
					v2_cont = false;
				}

			}
		}
	} else{												//Si no están ordenados los vectores de entrada
		n3 = 0;
		cout << "\n\tERROR: Los vectores de entrada deben estar ordenados crecientemente";
	}
}
