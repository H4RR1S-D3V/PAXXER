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
        int numero; // ?
        char nombre[30];
        int tamanioRegistro;
    public:
        ArchivoFactura(const char* n=ARCHIVO_FACTURAS);
        int contarRegistros();
        bool listarRegistros();
        bool actualizarFactura(Pedido factura);
        int buscarFactura(int id);
};

#endif // CLASESARCHIVOS_H_INCLUDED



