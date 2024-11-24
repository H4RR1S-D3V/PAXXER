#pragma once

#include "ClasesFactura.h"
#include "constantes.h"

class ArchivoProducto
{
private:
    char _nombre[30];
    int _tamanioRegistro;
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
};

class ArchivoFactura
{
    private:
        char _nombre[30];
        int _tamanioRegistro;
    public:
        ArchivoFactura(const char* n=ARCHIVO_FACTURAS);
        Factura leerRegistro(int pos);
        bool agregarRegistro(Factura &obj);
        int contarRegistros();
        bool listarRegistros();
        bool actualizarRegistro(Factura factura);
        int buscarRegistro(int id);
        ///FILTERS
        void filtrarRegistrosPorTipo(int tipo);
        void filtrarRegistrosPorEstado(bool estado);
};
