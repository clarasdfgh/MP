#include <iostream>
#include <assert.h>

#include "Calculo.h"

using namespace std;

void testRellenar(int min, int max);
void testMaxMin();
void testPromedio();
void testCalidos();

int main() {
    srand(time(0));

    cout << "\nTest Rellenar ";
    testRellenar(1, 45);
    cout << " -> OK " << endl;

		cout << "\nTest MaxMin ";
    testMaxMin();
    cout << " -> OK " << endl;

		cout << "\nTest Promedio ";
    testPromedio();
    cout << " -> OK " << endl;

		cout << "\nTest secuenciaDiasCalidos ";
    testCalidos();
    cout << " -> OK " << endl;

    return 0;
}

/******************************************************************************/

void testRellenar(int min, int max){
		int m[FIL][COL];

		rellenarMatriz(m, FIL, COL, min, max);
		mostrarMatriz(m, FIL, COL);
}

//..............................................................................

void testMaxMin(){
		int m[FIL][COL];
		int max[FIL];
		int min[FIL];

		rellenarMatriz(m, FIL, COL, 0, 40);

		//Para el test, introducimos algunos máximos/mínimos artificiales
		m[0][10] = -900;
		m[7][1]  = 999;
		m[10][25]= -999;
		m[3][14] = 900;
		//mostrarMatriz(m, FIL, COL);

		resumenMaximasMinimas(m, FIL, COL, max, min, COL);
		int min_abs = min[obtieneMin(min, FIL)];
		int max_abs = max[obtieneMax(max,FIL)];

    assert((min_abs == -999) && (max_abs == 999));
}

//..............................................................................

void testPromedio(){
		int m[FIL][COL];

		rellenarMatriz(m, FIL, COL, 0, 40);

		//Para el test, introducimos un mes con temperatura constante
		cargaValor(m[2], COL, 1);

		//También introducimos un mes con un máximo y mínimo establecido
		m[7][10] = -900;
		m[7][1]  = 999;

		//Un mes de temperatura constante excepto por un máximo, y otro constante menos por un mínimo
		cargaValor(m[10], COL, 2);
		cargaValor(m[11], COL, 3);
		m[10][20] = -900;
		m[11][20]  = 999;

		//Y finalmente un mes de temperatura constante menos por un máximo y otro número
		cargaValor(m[5], COL, 4);
		m[5][20] = 9;
		m[5][21] = 10;

		//mostrarMatriz(m, FIL, COL);

		cout << "\n\tTest promedio 1 - constante";
		assert(mediaMensualAjustada(m, FIL, COL, 2) == 1);

		cout << "\n\tTest promedio 2 - maximo establecido";
		assert(mediaMensualAjustada(m, FIL, COL, 10) == 2);

		cout << "\n\tTest promedio 3 - minimo establecido";
		assert(mediaMensualAjustada(m, FIL, COL, 11) == 3);

		cout << "\n\tTest promedio 4 - constante con maximo y otro numero";
		float resultado = ((4.0*28.0) + 9.0)/ 29.0;
		assert(mediaMensualAjustada(m, FIL, COL, 5) == resultado);
}

//..............................................................................

void testCalidos(){
		int m[FIL][COL];
		int meses[FIL];
		int meses_util = 0;

		rellenarMatriz(m, FIL, COL, 0, 40);

		//Ahora, introducimos unos valores artificiales para los test:
		m[7][0] = 0;
		m[7][1] = 99;
		m[7][2] = 99;
		m[7][3] = 0;

		m[8][19] = 0;
		m[8][20] = 99;
		m[8][21] = 99;
		m[8][22] = 0;

		mostrarMatriz(m, FIL, COL);

		//Primero, una salida sobre los valores aleatorios, sin adulterar:
		cout << "\n\tTest calidos 1 - valores aleatorios (3 días, 25ºC)";
		secuenciaDiasCalidos(m, FIL, COL, 25, 3, meses, meses_util);
		cout << "\n\t Meses que cumplen la secuencia: " << meses_util;
		listaMeses(meses, meses_util);

		//También hacemos una llamada que sabemos que no va a devolver nada:
		cout << "\n\tTest calidos 2 - valores imposibles (7 días, 100ºC)";
		secuenciaDiasCalidos(m, FIL, COL, 100, 7, meses, meses_util);
		cout << "\n\t Meses que cumplen la secuencia: " << meses_util;
		listaMeses(meses, meses_util);
		assert(meses_util == 0);

		//Ahora una salida sobre los valores artificales. Como son solo 2 días y los
		//hemos rodeado con 0, no afectan a la salida del primer test (aleatorios)
		cout << "\n\tTest calidos 2 - valores artificiales (2 días, 99ºC)";
		secuenciaDiasCalidos(m, FIL, COL, 99, 2, meses, meses_util);
		cout << "\n\t Meses que cumplen la secuencia: " << meses_util;
		listaMeses(meses, meses_util);
		assert(meses_util == 2);

}
