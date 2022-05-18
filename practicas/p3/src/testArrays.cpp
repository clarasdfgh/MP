/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   main.cpp
 * Author: David A. Pelta
 *
  */

#include <iostream>
#include <assert.h>

#include "GestionArrays.h"

using namespace std;



void testMezcla1(int n1, int n2);
void testMezcla2(int n1, int n2);
void testMezcla3();
void testOrden();
void testMaxMin();
void testMasFrecuente();
void testDistintos();
void testPromAjustado();


int main() {
    srand(time(0));


    cout << "Test Orden ";
    testOrden();
    cout << " -> OK ";

    cout << "\nTest promedioAjustado ";
    testPromAjustado();
    cout << " -> OK ";

		cout << "\nTest Mezclas 1 ";
    cout << "\n\tTest Mezclas 1.1 ";
    testMezcla1(5, 0);
		cout << "\n\tTest Mezclas 1.2 ";
    testMezcla1(0, 5);
		cout << "\n\tTest Mezclas 1.3 ";
    testMezcla1(3, 7);
		cout << "\n\tTest Mezclas 1.4 ";
    testMezcla1(7, 3);
		cout << "\n\tTest Mezclas 1.5 ";
    testMezcla1(7, 7);

    cout << " -> OK";

    cout << "\nTest Mezclas 2 ";
    testMezcla2(5, 15);
    cout << " -> OK ";

    cout << "\nTest Mezclas 3 ";
    testMezcla3();
    cout << " -> OK ";

    cout << "\nTest Mas Frecuente ";
    testMasFrecuente();
    cout << " -> OK ";

    cout << "\nTest MaxMin ";
    testMaxMin();
    cout << " -> OK";

    cout << "\nTest TodosDistintos ";
    testDistintos();
    cout << " -> OK";

		cout << endl;
    return 0;
}

/*
 INCORPORA ESTAS DOS FUNCIONES AL MÓDULO GestionArrays

// carga un vector con valores al azar entre min, max
void CargaVector(int v[], int n, int min, int max){
    int rango = max - min;
    for(int i = 0; i < n; i++)
        v[i] = random()% rango + min;
}

// genera un vector ordenado. El primer valor es "inicial" y los siguientes
// son incrementos al azar entre [0, incremento-1]
void CargaVectorOrdenado(int v[], int n, int inicial, int incremento){

    v[0] = inicial;
    for(int i = 1; i < n; i++)
        v[i] = v[i-1] + random() % incremento;
}
*/


// test con tamaños correctos y arrays ordenados
void testMezcla1(int n1, int n2){
    int v1[MAX];
    int v2[MAX];
    int v3[MAX];
    int n3;

    cargaVectorOrdenado(v1, n1, -2, random()%6 + 1);
    cargaVectorOrdenado(v2, n2, 1, random()%5 + 1);
    mezclaOrdenada(v1, n1, v2, n2, v3, n3);
    assert(estaOrdenado(v3,n3) && (n3 == n1 + n2));
}

// test con tamaños correctos y arrays desordenados
void testMezcla2(int n1, int n2){
    int v1[MAX];
    int v2[MAX];
    int v3[MAX];
    int n3;

    cargaVector(v1, n1, 1, 10);
    cargaVector(v2, n2, 1, 10);
    mezclaOrdenada(v1, n1, v2, n2, v3, n3);
    assert(n3 == 0);
}

// test con tamaños grandes y arrays ordenados
void testMezcla3(){
    int n1 = MAX;
    int n2 = MAX;
    int v1[n1];
    int v2[n2];
    int v3[MAX];
    int n3;

    cargaVectorOrdenado(v1, n1, -2, random()%6 + 1);
    cargaVectorOrdenado(v2, n2, 1, random()%5 + 1);
    mezclaOrdenada(v1, n1, v2, n2, v3, n3);
    assert(estaOrdenado(v3,n3) && (n3 == MAX));
}



void testOrden(){
    int n = MAX/2;
    int v[n];
    for(int i = 0; i < n; i++)
        v[i] = i + 1;

    assert(estaOrdenado(v,n));
    v[1] = 6;

    assert(!estaOrdenado(v,n));
}

void testMaxMin(){
    int n = MAX/2;
    int v[n];

    // vector aleatorio con valores entre [0,10}
    cargaVector(v, n, 0, 10);

    v[1] = -1;
    v[n-1] = 11;
    int p_min, p_max;
    obtieneMaxMin(v,n,p_max, p_min);

    assert(v[p_min] == -1 && v[p_max] == 11);
}

void testMasFrecuente(){
    int n = MAX/2;
    int v[n];

    for(int i = 0; i < n; i++)
        v[i] = i + 1;
    int valor, veces;

    masFrecuente(v,n,valor,veces);
    assert((valor == 1 || valor == n) && veces == 1);

    // pongo el valor -1 en dos posiciones distintas
    // así el más frecuente será el -1, con dos apariciones
    v[0] = -1;
    v[n-1] = -1;

    masFrecuente(v,n,valor,veces);
    assert(valor == -1 && veces == 2);
}

void testDistintos(){
    int n = MAX/2;
    int v[n];
    for(int i = 0; i < n; i++)
        v[i] = i + 1;

    assert(todosDistintos(v,n));
    v[1] = 6;
    assert(!todosDistintos(v,n));
}

void testPromAjustado(){


    int n = MAX/2;
    int v[n];

    for(int i = 0; i < n; i++)
        v[i] = 2;

    assert(promedioAjustado(v, n) == 2);



    cargaVector(v, n, 2, 9);
    v[0] = 1; // el val. minimo;
    v[n-1] = 10; // el maximo

    float suma = 0;
    for(int i = 0; i < n; i++)
        suma += v[i];

    suma -= 11; //(resto max y min)
    suma = suma / (n-2);

    assert(promedioAjustado(v, n) == suma);




}
