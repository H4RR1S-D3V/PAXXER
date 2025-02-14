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
    bool validarItemRepetido(const char* nombre);
    void listarRegistrosPorNombre(const char *nombre);
    void listarRegistrosPorTipo(const int tipo);
    bool filtrarRegistrosPorEstado(int);
    bool filtrarRegistrosPorEstado(bool estado);
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
        float listarRegistrosPorResponsableID(int idEmpleado);
        float listarRegistrosPorTipo(int tipoServicio);
        float listarRegistrosPorTurno(int turno);
        float listarRegistrosPorAnio(int anio);
        float listarRegistrosPorMes(int mes);
        void filtrarRegistrosPorTipo(int tipo);
        void filtrarRegistrosPorEstado(bool estado);

};
