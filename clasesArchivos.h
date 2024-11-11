#ifndef CLASESARCHIVOS_H_INCLUDED
#define CLASESARCHIVOS_H_INCLUDED

#include "clases.h"
#include "constantes.h"

class ArchivoMesas
{
    private:
        int numero; // ?
        char nombre[30];
        int tamanioRegistro;
    public:
        ArchivoMesas(const char* n=ARCHIVO_MESAS);
        Mesa leerRegistro(int pos);
        int setearCantMesas(int cant);
        int contarRegistros();
        bool actualizarMesa(Mesa mesa);
};

class ArchivoFactura
{
    private:
        int _numero; // ?
        char _nombre[30];
        int _tamanioRegistro;
    public:
        ArchivoFactura(const char* n=ARCHIVO_FACTURAS);
        Pedido leerRegistro(int pos);
        bool agregarRegistro(Pedido &obj);    // DEBERIA CREAR UN REGISTRO DE PEDIDO O DE FACTURA
        int contarRegistros();
        bool listarRegistros();
        bool actualizarFactura(Pedido* factura, int id);
        int buscarFactura(int id);
};

class ArchivoProducto
{
private:
    char _nombre[15];
public:
    ArchivoProducto(const char* n=ARCHIVO_PRODUCTOS);
    bool agregarRegistro(Producto &obj);
    Producto leerRegistro(int pos);
    bool modificarPrecioRegistro(float precio, int id);
    int buscarRegistroPorId(int id);
    bool deshabilitarRegistro(int id);
    bool habilitarRegistro(int id);
    int contarRegistros();
    bool listarRegistros();
    bool modificarNombreRegistro(const char *nombre, int id);
    bool modificarTipoRegistro(const int tipo, int id);
    void listarRegistrosPorNombre(const char *nombre);
    void listarRegistrosPorTipo(const int tipo);
    void eliminarRegistro(int id);
};

#endif // CLASESARCHIVOS_H_INCLUDED



