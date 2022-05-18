#ifndef LISTA_COMPRA_H
#define LISTA_COMPRA_H

#include<iostream>
#include<string>
#include<cmath>

using namespace std;

struct Producto{
    string nombre;
    int peso; // en gramos
    float precio_kg;
};

struct Compra{
    static const int MAX = 10;
    Producto lista[MAX];
    int util;
};

struct Recuento{
  static const int MAX = 100;
  string lista_pdtos[MAX];
  int lista_freq[MAX] = { 0 };
  float lista_peso[MAX] = {0};
  int util = 0;
};

string productoToString(Producto a);
Producto creaProducto(string nombre, int peso, float precio);
void incrementarPrecios(Compra & c, int k);
void listarCompra(const Compra & c);
void obtenerImporteYPeso(const Compra & c, float & precio, float & peso);
void mostrarTicketCompra(const Compra & c);
void arrayRangoPeso(const Compra & c, float min, float max, Producto pdtos[], int & util_pdtos);
float precio(const Producto pdto);
float precioTotalCompra(const Compra & c);
void eliminaProducto(Compra & c, int ind_pdto);
void noHaySuficiente(Compra & c, float dinero);
void finalDelDia(Compra listado[], int util);

#endif
