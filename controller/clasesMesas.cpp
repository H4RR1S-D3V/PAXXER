/// FACTURA (CAMBIAR LUEGO)

#include <iostream>

#include "clasesMesas.h"
#include "ClasesFactura.h"
#include "clasesArchivosMesas.h"
#include "clasesArchivosFacturas.h"
#include "funciones.h"

#include "../view/funcionesDibujar.h"
#include "../view/pantallasMenuPrincipal.h"
#include "../view/pantallaDelivery.h"
#include "../view/pantallaTakeAway.h"
#include "../view/declaracionOpcionesMapaMesas.h"
#include "../rlutil.h"

using namespace std;

/// CLASE BASE MESA

//SETTERS
void Mesa::setNumero(int numero)
{
    _numero = numero;
}
//GETTERS
bool Mesa::getDisponibilidad()
{
    return _disponible;
}
int Mesa::getNumero()
{
    return _numero;
}
int Mesa::getIdFactura()
{
    return _idFactura;
}
//METHODS
Mesa::Mesa()
{
    _numero = 0;
}
Mesa::Mesa(int numero)
{
    _numero = numero;

}
void Mesa::abrirMesa() {}
void Mesa::cerrarMesa()
{
    Factura objFac;
    ArchivoFactura arcFac;

    int pos = arcFac.buscarRegistro(_idFactura);
    objFac = arcFac.leerRegistro(pos);

    objFac.preguntarPorDescuento();
}
void Mesa::cargarMesa()
{
    // FALTA SETEAR EL NUMERO DE MESA
    _disponible = false;

    _idFactura = generarId(3);
    Factura obj(_idFactura);

    ArchivoFactura arc;
    arc.agregarRegistro(obj);
}
/// FIN CLASE BASE MESA

/// CLASE HEREDADA LOCAL

//METHODS
Local::Local() {}
Local::Local(int numeroMesa)
{
    _numero = numeroMesa;
    _disponible = true;
}
void Local::cargarLocal()
{

    ArchivoFactura archiFac;
    Factura obj;

    cargarMesa();

    bool salir = true;
    int y=0;
    do  //! PASAR A FUNCION
    {

        ///MOSTRAR NUM MESA ELEGIDA
        rlutil::hidecursor();
        rlutil::setColor(rlutil::LIGHTCYAN);
        dibujarBordesPantallas(42,8);
        dibujarBordesPantallas(42,10);
        rlutil::setColor(rlutil::BROWN);
        rlutil::locate (57,9);


        cout << "TIPO DE PEDIDO LOCAL - MESA NUMERO " << _numero << " SELECCIONADA";
        rlutil::locate (40,12);
        rlutil::setColor(rlutil::WHITE);


        cout << "PORFAVOR INGRESE SU ID DE EMPLEADO: ";
        rlutil::locate (40,13);
        cin >> _empleadoAsignado;


        rlutil::locate(40,14);
        cout << "PORFAVOR INGRESE LA CANTIDAD DE COMENSALES: ";
        rlutil::locate(40,15);
        cin >> _comensales;



        ///PEDIR CONFIRMACION Y QUE ESO LLEVE A MOSTRAR VISTA MESA
        rlutil::locate(40,16);
        cout << "CONFIRMA QUE LOS DATOS INGRESADOS SON CORRECTOS?" <<endl;
        rlutil::setColor(rlutil::GREEN);
        rlutil::locate(40,17);
        cout << "Y";
        rlutil::setColor(rlutil::WHITE);
        cout << "/";
        rlutil::setColor(rlutil::RED);
        cout << "N";
        rlutil::setColor(rlutil::WHITE);
        cout<< " - 0 PARA VOLVER";


        rlutil:: locate (77,18);
        char opcion;
        cin >> opcion;
        switch (tolower(opcion))
        {
        case 'y': //si
        {

            rlutil::cls();
            _horaApertura = horaActual();

            /// buscar factura y pasar hora para calcular turno
            int pos = archiFac.buscarRegistro(_idFactura);
            obj = archiFac.leerRegistro(pos);
            obj.setTurno(_horaApertura);
            obj.setIdEmpleado(_empleadoAsignado);
            obj.setTipo(1);

            archiFac.actualizarRegistro(obj);
            return;
            break;
        }
        case 'n': //no
        {
            rlutil::cls();
            this->cargarLocal();
            break;
        }
        case '0'://volver
        {
            rlutil::cls();
            salir=false;
            mostrarMapaMesas();
            break;
        }
        }
        break;

    }

    while(salir==true);
}
void Local::mostrarLocal()
{
    bool salir = true;
    int x=0;
    do  //! PASAR A FUNCION
    {
        rlutil::hidecursor();
        rlutil::setColor(rlutil::LIGHTCYAN);
        dibujarBordeSyI(10,3);
        dibujarBordeSyI(10,6);
        rlutil::setColor(rlutil::BROWN);
        rlutil::locate(42, 4);
        cout<<"NRO. MESA";
        rlutil::locate(46, 5);
        cout << _numero;
        rlutil::locate(80, 4);
        cout <<"HORA APERTURA";
        rlutil::locate(80, 5);
        cout << _horaApertura;
        rlutil::locate(110, 4);
        cout <<"CANT. COMENSALES";
        rlutil::locate(121, 5);
        cout << _comensales;
        rlutil::setColor(rlutil::WHITE);
        pintarOpciones("CARGAR ITEM",30, 8, x==0);
        pintarOpciones("QUITAR ITEM",60, 8,x==30);
        pintarOpciones("CERRAR MESA",90, 8, x==60);
        pintarOpciones("VOLVER A MAPA",120, 8, x==90);

        ///BUSCAR FACTURA Y MOSTRARLA

        ArchivoFactura arc;
        Factura obj;
        int pos = arc.buscarRegistro(_idFactura);
        obj = arc.leerRegistro(pos);
        obj.mostrarFacturaDetalle();

        rlutil::setColor(rlutil::WHITE);
        rlutil:: locate (29+x,8);
        cout << char (16);
        int key=rlutil::getkey();
        rlutil::locate(29 + x, 8);
        cout << " ";
        switch (key)
        {
        case 17:
            x+=30;
            if (x>90) x=90;
            break;
        case 16:
            x-=30;
            if (x<0) x=0;
            break;
        case 1:
            switch (x)
            {
            // CARGAR
            case 0:
            {
                rlutil::cls();
                cargarItem(_idFactura);
                break;
            }
            case 30://QUITAR
                quitarItem(_idFactura);
                break;
            case 60://CERRAR MESA
                cerrarLocal();
                break;
            case 90://VOLVER
                rlutil::cls();
                mostrarMapaMesas();
            }
        }
    }

    while (salir==true);

}
void Local::abrirMesa()
{
    Local obj;
    ArchivoMesasLocal arcMesa;
    ArchivoFactura arcFac;

    int pos = _numero -1;
    obj = arcMesa.leerRegistro(pos);

    if(obj.getDisponibilidad())
    {
        obj.cargarLocal();
        arcMesa.actualizarMesa(obj);
    }

    obj.mostrarLocal();
    return;
}
void Local::liberarMesa()
{
    /// Mesa(numero)?

    _disponible = true;
    _idFactura = -1;
    _horaApertura = -1;
    _comensales = -1;
    _empleadoAsignado = -1;
}
void Local::cerrarLocal()
{
    cerrarMesa();

    ArchivoMesasLocal arcLocal;
    liberarMesa();
    arcLocal.actualizarMesa(*this);

    mostrarMapaMesas();
}
/// FIN CLASE HEREDADA LOCAL

/// CLASE HEREDADA DELIVERY

// SETTERS
void Delivery::setNumero(int num)
{
    _numero = num;
    _entregado = false;
}
// GETTERS
int Delivery::getNumero()
{
    return _numero;
}
// METHODS
Delivery::Delivery() {}
Delivery::Delivery(int num)
{
    _numero = num;
}
void Delivery::cargarDelivery()
{
    cargarMesa();

    rlutil::locate(10, 10);
    cout << "INGRESE EL TELEFONO DEL CLIENTE: ";
    cargarCadena(_telefonoCliente, 20);
    rlutil::locate(10, 11);
    cout << "INGRESE EL ID DEL DELIVERY ASIGNADO: ";
    cin >> _deliveryAsignado;
    rlutil::locate(10, 12);
    cout << "INGRESE LA HORA DE ENTREGA: ";
    cin >> _horaEntrega;
    rlutil::locate(10, 13);
    cout << "INGRESE EL DOMICILIO A ENTREGAR: " << endl;
    _direccionEntrega.Cargar();

    ArchivoFactura arc;
    Factura obj;

    int pos = arc.buscarRegistro(_idFactura);
    obj = arc.leerRegistro(pos);
    obj.setTurno(horaActual());
    obj.setTipo(2);
    obj.setIdEmpleado(_deliveryAsignado);

    arc.actualizarRegistro(obj);
}
void Delivery::mostrarDelivery(int y)
{
    ArchivoFactura arc;
    Factura obj;
    int pos = arc.buscarRegistro(_idFactura);
    obj = arc.leerRegistro(pos);

    rlutil::locate(13, y);
    cout << _numero;
    rlutil::locate(20, y);
    _direccionEntrega.Mostrar();
    rlutil::locate(64, y);
    cout << _deliveryAsignado; // SACAR NOMBRE CON ID
    rlutil::locate(100, y);
    cout << _horaEntrega << "Hs.";
    rlutil::locate(128, y);
    cout << "$" << obj.getImporteSubTotal();
    rlutil::locate(148, y);
    if(!_entregado)
    {
        cout << "PENDIENTE" << endl;
    }
    else
    {
        cout << "ENTREGADO" << endl;
    }
}
void Delivery::mostrarDeliveryDetalle()
{
    int x = 0;
    do
    {
        rlutil::setColor(rlutil::WHITE);
        pintarOpciones("CARGAR ITEM",30, 8, x==0);
        pintarOpciones("QUITAR ITEM",60, 8,x==30);
        pintarOpciones("CERRAR DELIVERY",90, 8, x==60);
        pintarOpciones("VOLVER A DELIVERIES",120, 8, x==90);

        ///BUSCAR FACTURA Y MOSTRARLA
        ArchivoFactura arc;

        Factura obj;

        int pos = arc.buscarRegistro(_idFactura);
        obj = arc.leerRegistro(pos);

        obj.mostrarFacturaDetalle();

        rlutil::setColor(rlutil::WHITE);
        rlutil:: locate (29+x,8);
        cout << char (16);
        int key=rlutil::getkey();
        rlutil::locate(29 + x, 8);
        cout << " ";
        switch (key)
        {
        case 17:
            x+=30;
            if (x>90) x=90;
            break;
        case 16:
            x-=30;
            if (x<0) x=0;
            break;
        case 1:
            switch (x)
            {
            // CARGAR
            case 0:
            {
                rlutil::cls();
                cargarItem(_idFactura);
                break;
            }
            case 30://QUITAR
                quitarItem(_idFactura);
                break;
            case 60://CERRAR MESA
                cerrarDelivery();
                rlutil::cls();
                pantallaDelivery();
                break;
            case 90://VOLVER
                rlutil::cls();
                pantallaDelivery();
            }
        }
    }
    while(true);
}
void Delivery::abrirMesa()
{
    Delivery obj;
    ArchivoDelivery arcDel;
    ArchivoFactura arcFac;

    int pos = _numero -1;
    obj = arcDel.leerRegistro(pos);
    obj.mostrarDeliveryDetalle();
}
void Delivery::cerrarDelivery()
{
    cerrarMesa();
    entregarDelivery();

    ArchivoDelivery arc;
    arc.eliminarRegistro(_numero - 1);
}
void Delivery::entregarDelivery()
{
    _entregado = true;
}
void Delivery::disminuirNumero()
{
    _numero--;
}
/// FIN CLASE HEREDADA DELIVERY

/// CLASE HEREDADA TAKEAWAY

// SETTERS
void TakeAway::setNumero(int num)
{
    _numero = num;
    _entregado = false;
}
// GETTERS
int TakeAway::getNumero()
{
    return _numero;
}
// METHODS
TakeAway::TakeAway() {}
TakeAway::TakeAway(int num)
{
    _numero = num;
}
void TakeAway::cargarTakeAway()
{
    cargarMesa();

    rlutil::locate(10, 10);
    cout << "INGRESE EL TELEFONO DEL CLIENTE: ";
    cargarCadena(_telefonoCliente, 20);

    rlutil::locate(10, 11);
    cout << "INGRESE EL NOMBRE DEL CLIENTE: ";
    cargarCadena(_nombreCliente, 50);

    rlutil::locate(10, 12);
    cout << "INGRESE LA HORA DE RETIRO: ";
    cin >> _horaRetiro;

    ArchivoFactura arc;
    Factura obj;

    int pos = arc.buscarRegistro(_idFactura);
    obj = arc.leerRegistro(pos);
    obj.setTipo(3);
    obj.setTurno(horaActual());

    arc.actualizarRegistro(obj);
}
void TakeAway::mostrarTakeAway(int y)
{
    ArchivoFactura arc;
    Factura obj;
    int pos = arc.buscarRegistro(_idFactura);
    obj = arc.leerRegistro(pos);

    rlutil::locate(13, y);
    cout << _numero;
    rlutil::locate(20, y);
    cout << _nombreCliente;
    rlutil::locate(64, y);
    cout << _telefonoCliente;
    rlutil::locate(100, y);
    cout << _horaRetiro << "Hs.";
    rlutil::locate(128, y);
    cout << "$" << obj.getImporteSubTotal();
    rlutil::locate(148, y);
    if(!_entregado)
    {
        cout << "PENDIENTE" << endl;
    }
    else
    {
        cout << "ENTREGADO" << endl;
    }
}
void TakeAway::mostrarTakeAwayDetalle()
{
    int x = 0;
    do
    {
        rlutil::setColor(rlutil::WHITE);
        pintarOpciones("CARGAR ITEM",30, 8, x==0);
        pintarOpciones("QUITAR ITEM",60, 8,x==30);
        pintarOpciones("CERRAR TAKEAWAY",90, 8, x==60);
        pintarOpciones("VOLVER A TAKEAWAYS",120, 8, x==90);

        ///BUSCAR FACTURA Y MOSTRARLA
        ArchivoFactura arc;

        Factura obj;

        int pos = arc.buscarRegistro(_idFactura);
        obj = arc.leerRegistro(pos);

        obj.mostrarFacturaDetalle();

        rlutil::setColor(rlutil::WHITE);
        rlutil::locate(29+x, 8);
        cout << char(16);
        int key = rlutil::getkey();
        rlutil::locate(29+x, 8);
        cout << " ";
        switch (key)
        {
        case 17:
            x+=30;
            if (x>90) x=90;
            break;
        case 16:
            x-=30;
            if (x<0) x=0;
            break;
        case 1:
            switch (x)
            {
            // CARGAR
            case 0:
            {
                rlutil::cls();
                cargarItem(_idFactura);
                break;
            }
            case 30://QUITAR
                quitarItem(_idFactura);
                break;
            case 60://CERRAR MESA
                cerrarTakeAway();
                rlutil::cls();
                pantallaTakeAway();
                break;
            case 90://VOLVER
                rlutil::cls();
                pantallaTakeAway();
            }
        }
    }
    while(true);
}
void TakeAway::abrirMesa()
{
    TakeAway obj;
    ArchivoTakeAway arcTake;
    ArchivoFactura arcFac;

    int pos = _numero -1;
    obj = arcTake.leerRegistro(pos);
    obj.mostrarTakeAwayDetalle();

    return;
}
void TakeAway::cerrarTakeAway()
{
    cerrarMesa();
    entregarTakeAway();
    ArchivoTakeAway arcTake;
    arcTake.eliminarRegistro(_numero - 1);
}
void TakeAway::entregarTakeAway()
{
    _entregado = true;
}
void TakeAway::disminuirNumero()
{
    _numero--;
}
