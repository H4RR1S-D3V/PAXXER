#include <iostream>
#include <ctime>

#include "funciones.h"
#include "clasesAuxiliares.h"
#include "../rlutil.h"

using namespace std;

/// CLASE FECHA

// SETTERS
void Fecha::setDia(int d)
{
    _dia=d;
}
void Fecha::setMes(int m)
{
    _mes=m;
}
void Fecha::setAnio(int a)
{
    _anio=a;
}
// GETTERS
int Fecha::getDia()
{
    return _dia;
}
int Fecha::getMes()
{
    return _mes;
}
int Fecha::getAnio()
{
    return _anio;
}
// METHODS
void Fecha::Cargar()
{
    cin>>_dia;
    cin>>_mes;
    cin>>_anio;
}
void Fecha::Mostrar()
{
    cout<<_dia<<"/";
    cout<<_mes<<"/";
    cout<<_anio<<endl;
}
/// FIN CLASE FECHA

/// CLASE TIEMPO

// GETTERS
int Tiempo::getHora()
{
    return _local->tm_hour;
}
int Tiempo::getMinutos()
{
    return _local->tm_min;
}
Fecha Tiempo::getFecha()
{
    Fecha fecha;
    fecha.setDia(_local->tm_mday);
    fecha.setMes(_local->tm_mon+1);
    fecha.setAnio(_local->tm_year + 1900);

    return fecha;
}
/// FIN CLASE TIEMPO

/// CLASE DOMICILIO

// METHODS
void Domicilio::Cargar()
{
    rlutil::locate(10, 14);
    cout << "CALLE: ";
    cargarCadena(_calle, 20);

    rlutil::locate(10, 15);
    cout << "ALTURA: ";
    cin >> _altura;

    rlutil::locate(10, 16);
    cout << "LOCALIDAD: ";
    cargarCadena(_localidad, 20);
}
void Domicilio::Mostrar()
{
    cout << _calle << " " << _altura << " - " << _localidad;
}
