#include <iostream>

using namespace std;

#include "funcionesDeDesarrollo.h"
#include "clasesArchivosFacturas.h"
#include "clasesFactura.h"


void cargarFacturas()
{

}

void generarProductos()
{
    ArchivoProducto archivo;

    // Productos de ejemplo (30 elementos distribuidos entre los 4 tipos)
    Producto productos[30];

    // Entradas (1)
    const char* entradas[] = {"Ensalada Cesar", "Sopa de Pollo", "Bruschetta", "Empanadas", "Croquetas"};
    for (int i = 0; i < 5; i++) {
        productos[i].setId(i + 1);
        productos[i].setNombre(entradas[i]);
        productos[i].setPrecio(10 + i * 2);  // Precios arbitrarios
        productos[i].setTipo(1);
        //productos[i].setDisponibilidad(true);
        archivo.agregarRegistro(productos[i]);
    }

    // Platos Principales (2)
    const char* principales[] = {"Spaghetti Bolognesa", "Pizza Margarita", "Pollo a la Parrilla", "Filete de Res", "Paella"};
    for (int i = 0; i < 5; i++) {
        productos[i + 5].setId(i + 6);
        productos[i + 5].setNombre(principales[i]);
        productos[i + 5].setPrecio(15 + i * 3);  // Precios arbitrarios
        productos[i + 5].setTipo(2);
       // productos[i + 5].setDisponibilidad(true);
        archivo.agregarRegistro(productos[i + 5]);
    }

    // Postres (3)
    const char* postres[] = {"Tiramisu", "Cheesecake", "Helado de Chocolate", "Panna Cotta", "Brownie"};
    for (int i = 0; i < 5; i++) {
        productos[i + 10].setId(i + 11);
        productos[i + 10].setNombre(postres[i]);
        productos[i + 10].setPrecio(6 + i * 1.5);  // Precios arbitrarios
        productos[i + 10].setTipo(3);
        //productos[i + 10].setDisponibilidad(true);
        archivo.agregarRegistro(productos[i + 10]);
    }

    // Bebidas (4)
    const char* bebidas[] = {"Coca-Cola", "Fanta", "Agua Mineral", "Cerveza", "Vino"};
    for (int i = 0; i < 5; i++) {
        productos[i + 15].setId(i + 16);
        productos[i + 15].setNombre(bebidas[i]);
        productos[i + 15].setPrecio(3 + i);  // Precios arbitrarios
        productos[i + 15].setTipo(4);
       // productos[i + 15].setDisponibilidad(true);
        archivo.agregarRegistro(productos[i + 15]);
    }

    // Otros productos (hasta completar 30)
    const char* otros[] = {"Limonada", "Sopa de Verduras", "Ensalada Rusa", "Tacos", "Hamburguesa"};
    for (int i = 0; i < 5; i++) {
        productos[i + 20].setId(i + 21);
        productos[i + 20].setNombre(otros[i]);
        productos[i + 20].setPrecio(8 + i * 2);  // Precios arbitrarios
        productos[i + 20].setTipo(2);  // Tipo Plato Principal
       // productos[i + 20].setDisponibilidad(true);
        archivo.agregarRegistro(productos[i + 20]);
    }

    cout << "30 productos generados y almacenados en " << ARCHIVO_PRODUCTOS << endl;
}
