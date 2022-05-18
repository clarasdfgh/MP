#include<iostream>
#include<string>
#include"ListaCompra.h"

using namespace std;

// función para devolver los datos de un producto como un string
string productoToString(Producto a){
    string rta;
    rta = a.nombre + "\t\t" + to_string(a.peso) + "gr\t" \
          + to_string(a.precio_kg) + "€/kg\t\t" \
          + to_string(a.precio_kg * (a.peso / 1000.0)) + "€";
    return rta;
}

// crea una variable de tipo Producto y la devuelve
Producto creaProducto(string nombre, int peso, float precio){
    Producto nuevo_pdto = {nombre, peso, precio};
    return nuevo_pdto;
}

// incrementa el precio de cada producto en un k %
void incrementarPrecios(Compra & c, int k){
  for(int i = 0; i < c.util; i++){
      c.lista[i].precio_kg *= (1 + k/100.0);
  }
}

// muestra el listado de productos comprados
void listarCompra(const Compra & c){
  for(int i = 0; i < c.util; i++){
      cout << "\n" << productoToString(c.lista[i]);
  }
  cout << "\n";
}

// función que devuelve el importe total de la compra (sin IVA) y su peso (en kgs)
void obtenerImporteYPeso(const Compra & c, float & precio, float & peso){
  peso = 0;
  precio = 0;

  for(int i = 0; i < c.util; i++){
      precio += c.lista[i].precio_kg * (c.lista[i].peso / 1000.0);
      peso   += c.lista[i].peso / 1000.0;
  }
}

// función que muestra el "ticket" de compra según el formato sugerido
void mostrarTicketCompra(const Compra & c){
    cout << "\n\n=============================================================";
    cout << "\n= T I C K E T  D E  C O M P R A =============================\n";
    listarCompra(c);

    float precio = 0;
    float peso = 0;
    obtenerImporteYPeso(c, precio, peso);
    cout << "\nSubtotal: \t" << to_string(precio);

    float iva = precio*0.21;
    cout << "\nIVA (21%): \t" << to_string(iva);

    cout << "\n\nTotal de la compra: \t" << to_string(precio+iva);
    cout << "\n=============================================================\n";
}

// Dada una compra y un rango, devuelve el array de Productos cuyo peso se encuentre en el rango
void arrayRangoPeso(const Compra & c, float min, float max, Producto pdtos[], int & util_pdtos){
    int j = 0;
    for(int i = 0; i < c.util; i++){
        if(c.lista[i].peso >= min && c.lista[i].peso <= max){
          pdtos[j] = c.lista[i];
          j++;
        }
    }
    util_pdtos = j;
}

//Dado un producto, calcula su precio
float precio(const Producto pdto){
  return pdto.precio_kg * (pdto.peso / 1000.0);
}

//Dada una compra, devuelve su precio total + IVA
float precioTotalCompra(const Compra & c){
  float total = 0;
  for(int i = 0; i < c.util; i++){
      total += precio(c.lista[i]);
  }
  return total  + (total * 0.21);
}

//Dada una compra, elimina el producto i de la lista
void eliminaProducto(Compra & c, int ind_pdto){
  Compra nueva_c;
  for(int i = 0; i < c.util; i++){
    if(i != ind_pdto){
      nueva_c.lista[nueva_c.util] = c.lista[i];
      nueva_c.util++;
    }
  }
  c = nueva_c;
}

//Dado el precio total de la compra y una cantidad de dinero, si el precio > dinero, elimina producutos
void noHaySuficiente(Compra & c, float dinero){
  float total = precioTotalCompra(c);

  if(dinero < total){
    float diferencia  = total - dinero;

    cout << "\nLa diferencia es de " << diferencia << "€";

    while(diferencia > 0 && c.util > 1){
      int ind_mas_cercano = 0;
      float precio_mas_cercano = precio(c.lista[0]);

      for(int i = 0; i < c.util; i++){
        if(abs(precio(c.lista[i]) - diferencia) <= abs(precio_mas_cercano - diferencia)){
          ind_mas_cercano = i;
          precio_mas_cercano = precio(c.lista[i]);
        }
      }
      cout << "\nEl elemento mas cercano a la diferencia es: " \
           << c.lista[ind_mas_cercano].nombre << ", " << precio_mas_cercano << "€";
      eliminaProducto(c, ind_mas_cercano);
      diferencia -= precio_mas_cercano;
    }
  } else{
      cout << "\nEl importe entregado para pagar la compra es suficiente";
  }
}

//Dado el listado de las compras realizadas a lo largo del día, devuelve un array de productos
void finalDelDia(Compra listado[], int util){
  Recuento recuento;

  //La primera compra serán todo productos nuevos, así que se meten directamente sin comprobaciones
  for(int i=0; i<listado[0].util; i++){
    recuento.lista_pdtos[i] = listado[0].lista[i].nombre;
    recuento.lista_freq[i]++;
    recuento.lista_peso[i] += listado[0].lista[i].peso;
    recuento.util++;
  }

  //Con los productos que contiene la primera lista, iniciamos comprobaciones
  //secuencialmente en los productos de todas las compras: si el producto aparece en el
  //recuento, se suma 1 a la frecuencia y se suma el peso. Si no, se añade al final.

    for(int i=1; i<util; i++){                          //Bucle para la lista de compras
      Compra compra_actual = listado[i];
      for(int j=0; j<compra_actual.util; j++){          //Bucle para la compra
        Producto producto_actual = compra_actual.lista[j];
        bool found = false;

        for(int k=0; k<recuento.util && !found; k++){   //Bucle para la lista de recuento
          if(producto_actual.nombre == recuento.lista_pdtos[k]){
            recuento.lista_freq[k]++;
            recuento.lista_peso[k] += producto_actual.peso;
            found = true;
          }
        }

        if(!found){           //Si no se encuentra , se añade al final de la lista
            recuento.lista_pdtos[recuento.util] = producto_actual.nombre;
            recuento.lista_freq[recuento.util]++;
            recuento.lista_peso[recuento.util] += producto_actual.peso;
            recuento.util++;
        }
      }
    }

    cout << "\n";
    for(int k=0; k<recuento.util; k++){
        cout << recuento.lista_pdtos[k] << "     \t\t" << recuento.lista_freq[k] << " compra/s \t\t" << recuento.lista_peso[k] << " gramos\n";
    }
    cout << "\n\n";

}
