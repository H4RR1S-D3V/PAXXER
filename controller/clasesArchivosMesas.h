#pragma once

#include "clasesMesas.h"
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
        bool verificarDisponibilidadGlobal();

};

class ArchivoDelivery
{
    private:
        char _nombre[30];
        int _tamanioRegistro;
    public:
        ArchivoDelivery(const char* n=ARCHIVO_DELIVERY);
        bool agregarRegistro(Delivery &obj);
        bool listarRegistros(int y);
        Delivery leerRegistro(int pos);
        int contarRegistros();
        int eliminarRegistro(int pos);
};

class ArchivoTakeAway
{
    private:
        char _nombre[30];
        int _tamanioRegistro;
    public:
        ArchivoTakeAway(const char* n=ARCHIVO_TAKEAWAY);
        bool agregarRegistro(TakeAway &obj);
        bool listarRegistros(int y);
        TakeAway leerRegistro(int pos);
        bool actualizarRegstro(TakeAway obj);
        int contarRegistros();
        int eliminarRegistro(int pos);
};
