#include<iostream>
#include<string>
#include"ListaCompra.h"

using namespace std;

int main()
{

    Producto actual;
    Compra mi_compra;
    float precio;
    float peso;
    string nombre;

    cin >> mi_compra.util;
    for(int i = 0; i < mi_compra.util; i++)
    {
        cin >> nombre >> peso >> precio;
        mi_compra.lista[i] = creaProducto(nombre, peso, precio);
    }

    // se muestra la lista de productos.
    cout << "\n********    Prueba de funcion listarCompra \t********\n";
    listarCompra(mi_compra);

    // se muestra el importe total de la compra y el peso
    cout << "\n********    Prueba de funcion obtenerImporteYPeso \t********\n";
    obtenerImporteYPeso(mi_compra, precio, peso);
    cout << "\nEl importe de la compra es: " << precio << ", su compra pesa:"
         << peso << " Kg. " << endl;

    // se muestra el ticket de la compra.
    cout << "\n********    Prueba de la funcion mostrarTicketCompra \t********\n";
    mostrarTicketCompra(mi_compra);

    cout << "\n********    Prueba de la funcion incrementarPrecio \t********\n*";
    incrementarPrecios(mi_compra, 10);
    mostrarTicketCompra(mi_compra);

    cout << "\n********    Prueba de la función arrayRangoPeso \t********";
    cout << "\n********    en el rango 3000 a 4000 gramos \t\t********\n";
    int util_pdtos = mi_compra.util;
    Producto lista_productos[util_pdtos];
    arrayRangoPeso(mi_compra, 3000.0, 4000.0, lista_productos, util_pdtos);

    for(int i=0; i<util_pdtos; i++){
      cout << "\n" << productoToString(lista_productos[i]);
    }

    cout << "\n\n********    Prueba de la función noHaySuficiente \t********";
    cout << "\n********    ud. tiene 15€ \t\t\t\t********\n";

    noHaySuficiente(mi_compra, 15);
    mostrarTicketCompra(mi_compra);

    cout << "\n\n********    Prueba de la función finalDelDia \t********";
    Compra listado[100];
    int util_listado = 0;
    Compra compra_listado;

    cin >> util_listado;
    for(int i = 0; i < util_listado; i++){
      cin >> compra_listado.util;
      for(int j = 0; j < compra_listado.util; j++)
      {
          cin >> nombre >> peso >> precio;
          compra_listado.lista[j] = creaProducto(nombre, peso, precio);
      }
      listado[i] = compra_listado;
    }

    finalDelDia(listado, util_listado);

    return(0);
}
