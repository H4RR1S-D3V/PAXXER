#include <iostream>

#include "clases.h"

using namespace std;

/// CLASE BASE MESA

void Mesa::cargarMesa()
{
    // FALTA SETEAR EL NUMERO DE MESA
    _disponible = false;
}

void Mesa::mostrarMesa()
{
    cout << "N° " << _numero << endl;
    // cout << Pedido << endl;
    cout << "TOTAL: ";// <<  SUBTOTAL << endl;
    cout << "SUBTOTAL POR PERSONA: "; // SUBTOTAL / _comensales << endl;
}

void Mesa::cerrarMesa()
{
    // ENTRAR AL ARCHIVO Y LIMPIAR EL REGISTRO
    _disponible = true;
}

/// CLASE HEREDADA LOCAL

void Local::cargarLocal()
{
    Mesa::cargarMesa();
    // CUANDO SE ABRE POR PRIMERA VEZ
    cout << "INGRESE EL ID EL CAMARERO ASIGNADO: ";
    cin >> _empleadoAsignado;

    cout << "INGRESE LA CANTIDAD DE COMENSALES: ";
    cin >> _comensales;

    // _horaApertura = (hora())
}
void Local::mostrarLocal()
{
    Mesa::mostrarMesa();
    //cout << "HORA DE APERTURA: " << _horaApertura << endl;
    cout << "CAMARERO ASIGNADO: " << _empleadoAsignado << endl;
    cout << "COMENZALES: " << _comensales << endl;
}

/// CLASE HEREDADA DELIVERY

void Delivery::cargarDelivery()
{
    Mesa::cargarMesa();

    cout << "INGRESE EL TELEFONO DEL CLIENTE: ";
    cin.getline(_telefonoCliente, 10);

    cout << "INGRESE EL DELIVERY ASIGNADO: ";
    cin.getline(_deliveryAsignado, 20);

    cout << "INGRESE LA HORA DE ENTREGA: ";
    //_horaEntrega.cargarHora();
}
void Delivery::mostrarDelivery()
{
    Mesa::mostrarMesa();

    cout << "TELEFONO CLIENTE: " << _telefonoCliente;
    cout << "DELIVERY ASIGNADO: " << _deliveryAsignado;
}

/// CLASE HEREDADA TAKEAWAY

void TakeAway::cargarTakeAway()
{
    Mesa::cargarMesa();

    cout << "INGRESE LA HORA DE RETIRO: ";
    // _horaRetiro.cargarHora();

    cout << "INGRESE EL NOMBRE DEL CLIENTE: ";
    cin.getline(_nombreCliente, 50);
}

void TakeAway::mostrarTakeAway()
{
    Mesa::mostrarMesa();

    //cout << "HORA DE RETIRO: " << _horaRetiro;
    cout << "NOMBRE DEL CLIENTE: " << _nombreCliente;
}
