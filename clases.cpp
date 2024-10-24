#include <iostream>
#include <cstring>

#include "clases.h"

using namespace std;

/// CLASE BASE MESA

Mesa::Mesa()
{
    _numero = 0;
    _disponible = true;
}

Mesa::Mesa(int numero)
{
    _numero = numero;
    _disponible = true;
}

void Mesa::cargarMesa()
{
    // FALTA SETEAR EL NUMERO DE MESA
    _disponible = false;    /// LA MESA SE OCUPA AL ABRIRLA
}

void Mesa::mostrarMesa()
{
    cout << "N° " << _numero << endl;
    //_pedido.mostrarPedido();
    //cout << "TOTAL: " <<  _pedido.getImporteTotal() << endl;
    cout << "DISPONIBLE: " << _disponible << endl;
}

void Mesa::cerrarMesa()
{
    // ENTRAR AL ARCHIVO Y LIMPIAR EL REGISTRO
    _disponible = true;
}

void Mesa::setNumero(int numero)
{
    _numero = numero;
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
    //cout << "TOTAL: " << Mesa::_pedido.getImporteTotal() << endl;
    //cout << "SUBTOTAL POR PERSONA: " << Mesa::_pedido.getImporteTotal() / _comensales << endl;
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

/// CLASE BASE USUARIO

void Usuario::cargar()
{
    cout << "INGRESE NOMBRE COMPLETO: " << endl;
    cin >> _nombre;

    cout << "INGRESE DNI: " << endl;
    cin >> _nombre;

    // generar id automaticamente
}

void Usuario::mostrar()
{
    cout << "NOMBRE: " << _nombre << endl;
    cout << "DNI: " << _dni << endl;
    cout << "ID: " << _id << endl;
}

/// CLASE BASE CREDENCIAL

void Credencial::setPassword(char* newPassword[12])
{
    strcpy(_password, *newPassword);
}

char* Credencial::getPassword()
{
    return _password;
}

/// CLASE BASE PEDIDO

// FUNCIONES DEL ARRAY _PRODUCTOS

void Pedido::cargarItem()
{
    /// cargar producto al array _productos
}

void Pedido::quitarItem()
{
    /// pide contraseÑa y borra item del array _productos
}

void Pedido::mostrarPedido()
{
    /// listar items del array _productos
    cout << "MOSTRANDO VECTOR DE PEDIDOS." << endl;
}
// FIN FUNCIONES _PRODUCTOS

/// generar id automaticamente

float Pedido::getImporteTotal()
{
    return _importeTotal;
}

void Pedido::cerrarPedido()
{
    /// guardar pedido en archivo y cerrar mesa
}

char Pedido::getTipo()
{
    return _tipo;
}

void Pedido::aplicarDescuento(int tipo, float descuento)
{
    /// tipo: 1-Fijo / 2-Porcentaje

    /// pedir contraseÑa maestra

    if(tipo == 1)
    {
        _importeTotal -= descuento;
    }
    else
    {
        _importeTotal -= ((_importeTotal * descuento) / 100 );
    }
}

/// CLASE BASE PRODUCTO

void Producto::cargarItem()
{
    cout << "INGRESE NOMBRE: " << endl;
    cin >> _nombre;
    cout << "INGRESE TIPO: (1-ENTRADA | 2-PLATO PRINCIPAL | 3-POSTRE | 4-BEBIDA)"<< endl;
    cin >> _tipo;
    cout << "INGRESE PRECIO: " << endl;
    cin >> _precio;

    /// generar id automaticamente

}

void Producto::mostrarItem()
{
    cout << "ID: "<< _id << endl;
    cout << _nombre << endl;
    cout << " $" << _precio << endl;
}

void Producto::setEstado(bool valor)
{
    _estado = valor;
}

void Producto::setPrecio(float nuevoPrecio)
{
    _precio = nuevoPrecio;
}

void Producto::setNombre (const char* nuevoNombre)
{
    if(strlen(nuevoNombre) > 50)
    {
        cout << "EL NOMBRE NO PUEDE TENER MAS DE 50 CARACTERES" << endl;
        return;
    }
    strcpy(_nombre, nuevoNombre);
}

float Producto::getPrecio()
{
    return _precio;
}

char* Producto::getNombre()
{
    return _nombre;
}
