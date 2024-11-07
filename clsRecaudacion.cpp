#include <iostream>
#include <cstring>
#include "clsRecaudacion.h"

using namespace std;

/// CLASE BASE RECAUDACION

// SETTERS

void Recaudacion::setFecha()
{

}
void Recaudacion::setTurno()
{

}
void Recaudacion::setId(int id)
{
    _id = id;
}
void Recaudacion::setImporteSubTotal(float importe)
{
    _importeSubTotal = importe;
}
void Recaudacion::setImporteFinal(float importe)
{
    _importeFinal = importe;
}
void Recaudacion::setTipoServicio(const char* servicio)
{
    _tipoServicio= servicio;
}
void Recaudacion::setIdVendedor(int id)
{
    _idVendedor = id;
}
void Recaudacion::setCantComensales(int cantidad)
{
    _cantComensales = cantidad;
}

// GETTERS

/*
Fecha Recaudacion::getFecha()
{
    return _fecha;
}
Turno Recaudacion::getTurno()
{
    return _turno;
}
*/
int Recaudacion::getId(){return id;}
float Recaudacion::getImporteSubTotal(){return _importeSubTotal;}
float Recaudacion::getImporteFinal(){return _importeFinal;}
const char* Recaudacion::getTipoServicio(){return _tipoServicioservicio;}
int Recaudacion::getIdVendedor(){return _idVendedor;}
int Recaudacion::getCantComensales(){return _cantComensales;}

// METHODS

void Recaudacion::Cargar()
{
    // CAPAZ NO SEA NECESARIO
}

void Recaudacion::Mostrar()
{
    cout << "ID: " << _id << endl;
    cout << "FECHA: " // _fecha.Mostrar();
    cout << "TURNO: " // turno.Mostrar();?
    if(_importeFinal != _importeSubTotal)
    {
        cout << "IMPORTE SUB TOTAL: $" << _importeSubTotal << endl;
    }
    cout << "IMPORTE FINAL: $" << _importeFinal << endl;
    cout << "TIPO DE SERVICIO: " << _tipoServicio << endl;
    if(!strcmp(_tipoServicio, "take away"))
    {
        co "RESPONSABLE DE LA VENTA: " <<
    }
}













