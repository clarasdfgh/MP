/******************************************************************************/
//	MP 21-22 Práctica 5 - main.cpp
//	CLARA MARÍA ROMERO LARA
//	05985367P
/******************************************************************************/

#include <iostream>
#include <climits>
#include <string>
#include <cstdlib>
#include <cmath>
#include "lienzo.h"

using namespace std;

void test1(); 		// reserva-libera
void test2(); 		// dibuja rectangulos
void test3(); 		// combina
void test4(); 		// pinta barras
void test5(bool); // aniade barras. True: muestra la matriz despues de agregar cada barra

// funcion auxiliar solo para main
void crearMatriz(char **&m, int nf, int nc, char c);

int main(int argc, char* argv[]) {

    int opcion = atoi(argv[1]);
    switch (opcion){
        case 1: {test1(); break;}
        case 2: {test2(); break;}
        case 3: {test3(); break;}
        case 4: {test4(); break;}
        case 5: {test5(false); break;}
    }

    return 0;
}


void crearMatriz(char **& m, int nf, int nc, char c){
 reservaMemoria(m, nf, nc);
 rellenar(m, nf, nc, '.');
}


void test1(){
    cout << "Reserva-Libera" << endl;
    char **M;

    for(int i = 0; i < 10; i++){
        int n = random()%1000 + 10;
        reservaMemoria(M, n, n);
        liberaMemoria(M, n, n);
    }
}


void test2(){
 cout << "Prueba dibujar Rectangulos " << endl;
 char **m = 0;
 int nf, nc;
 nf = nc = 5;

 crearMatriz(m, nf, nc, '.');
 dibujaRectangulo(m, nf, nc, 1,1,3,3,'X');
 imprime(m, nf, nc);

 rellenar(m, nf, nc, '.');
 dibujaRectangulo(m, nf, nc, 3,3,3,3,'X');
 imprime(m, nf, nc);

 rellenar(m, nf, nc, '.');
 dibujaRectangulo(m, nf, nc, -1,-1,3,3,'X');
 imprime(m, nf, nc);

 rellenar(m, nf, nc, '.');
 dibujaRectangulo(m, nf, nc, 0,0,0,0,'X');
 imprime(m, nf, nc);

 cout << endl;

 liberaMemoria(m, nf, nc);
}

void test3(){
 cout << "Prueba combinar " << endl;
 char **m1 = 0;
 int nf1, nc1;
 nf1 = nc1 = 5;
 crearMatriz(m1, nf1, nc1, '.');
 dibujaRectangulo(m1, nf1, nc1, 2,0,3,3,'L');
 imprime(m1, nf1, nc1);

 char **m2 = 0;
 int nf2, nc2;
 nf2 = nc2 = 7;

 crearMatriz(m2, nf2, nc2, '.');

 dibujaRectangulo(m2, nf2, nc2, 3, 3, 4, 4,'R');
 imprime(m2, nf2, nc2);

 int nf3, nc3;
 char ** m3 = combinar(m1, nf1, nc1, m2, nf2, nc2, nf3, nc3);
 imprime(m3, nf3, nc3);

 liberaMemoria(m3, nf3, nc3);

 m3 = combinar(m2, nf2, nc2, m1, nf1, nc1, nf3, nc3);
 imprime(m3, nf3, nc3);

 liberaMemoria(m1, nf1, nc1);
 liberaMemoria(m2, nf2, nc2);
 liberaMemoria(m3, nf3, nc3);
}

void test4(){
    cout << "\n\nPinta barras " << endl;
    char **m1;
    const int N = 10;
    int barras[N] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

    int nf1;
    int nc1;

    pintaBarras(m1, nf1, nc1, barras, N, 'Y');
    cout << "Matriz de " << nf1 << " filas y " << nc1 << " cols" << endl;
    imprime(m1, nf1, nc1);
    cout << endl;
    liberaMemoria(m1, nf1, nc1);
}

void test5(bool all) {
    cout << "\n\n-- aniadeBarras -- " << endl;

    const int N = 7;
    int datos2[N] = {4, 6, 8, 11, 8, 6, 4};
    char simb2[N] = {'1', '2', '3', '4', '5', '6', '7'};

    char **MM = 0;
    int f_MM, cols_MM;
    f_MM = cols_MM = 0;
    for (int i = 0; i < N; i++) {
        aniadeBarra(MM, f_MM, cols_MM, datos2[i], simb2[i]);
        if (all) {
            imprime(MM, f_MM, cols_MM);
            cout << endl;
        }
    }
    if (!all) {
        imprime(MM, f_MM, cols_MM);
        cout << endl;

    }
    liberaMemoria(MM, f_MM, cols_MM);

}
