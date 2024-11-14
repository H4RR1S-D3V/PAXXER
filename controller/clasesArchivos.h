#ifndef CLASESARCHIVOS_H_INCLUDED
#define CLASESARCHIVOS_H_INCLUDED

#include "clases.h"
#include "constantes.h"

class ArchivoMesasLocal
{
    private:
        char _nombre[30];
        int _tamanioRegistro;
    public:
        ArchivoMesasLocal(const char* n=ARCHIVO_MESAS_LOCAL);
        int setearCantMesas(int cant);
        bool listarRegistros();
        int contarRegistros();
        Local leerRegistro(int pos);
        bool actualizarMesa(Local mesa);
};

class ArchivoDelivery
{
    private:
        char _nombre[30];
        int _tamanioRegistro;
    public:
        ArchivoDelivery(const char* n=ARCHIVO_DELIVERY);
        bool agregarRegistro(Delivery &obj);
        bool listarRegistros();
        Delivery leerRegistro(int pos);
        bool actualizarRegstro(Delivery obj);
        int contarRegistros();
        int eliminarRegistro(int pos);
};

class ArchivoFactura
{
    private:
        char _nombre[30];
        int _tamanioRegistro;
    public:
        ArchivoFactura(const char* n=ARCHIVO_FACTURAS);
        Factura leerRegistro(int pos);
        bool agregarRegistro(Factura &obj);    // DEBERIA CREAR UN REGISTRO DE Factura O DE FACTURA
        int contarRegistros();
        bool listarRegistros();
        bool actualizarRegistro(Factura factura);
        int buscarRegistro(int id);
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
    bool cambiarEstadoRegistro(int id);
    int contarRegistros();
    bool listarRegistros();
    bool modificarNombreRegistro(const char *nombre, int id);
    bool modificarTipoRegistro(const int tipo, int id);
    void listarRegistrosPorNombre(const char *nombre);
    void listarRegistrosPorTipo(const int tipo);
   // void eliminarRegistro(int id);
};

#endif // CLASESARCHIVOS_H_INCLUDED



