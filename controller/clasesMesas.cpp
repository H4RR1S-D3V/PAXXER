/// FACTURA (CAMBIAR LUEGO)

#include <iostream>

#include "clasesMesas.h"
#include "ClasesFactura.h"
#include "clasesArchivosMesas.h"
#include "clasesArchivosFacturas.h"
#include "clasesArchivosUsuarios.h"
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
bool Mesa::cerrarMesa()
{
    Factura objFac;
    ArchivoFactura arcFac;

    int pos = arcFac.buscarRegistro(_idFactura);
    objFac = arcFac.leerRegistro(pos);

    return objFac.preguntarPorDescuento();
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


        cout << "POR FAVOR INGRESE SU ID DE EMPLEADO: ";
        rlutil::locate(40,13);
        int id;
        cin >> id;

        ArchivoUsuario arc;
        Usuario objUs;
        int pos = arc.buscarRegistro(id);
        objUs = arc.leerRegistro(pos);

        while(!objUs.getEstado() || arc.buscarRegistro(id) == -2)
        {
            rlutil::setColor(rlutil::RED);
            rlutil::locate(40,13);            cout << "ID DE USUARIO NO DISPONIBLE, INTENTE NUEVAMENTE: ";
            rlutil::locate(89,13);
            cout << "     ";
            rlutil::locate(89,13);
            cin >> id;
            pos = arc.buscarRegistro(id);
            objUs = arc.leerRegistro(pos);
        }
        rlutil::setColor(rlutil::WHITE);
        _empleadoAsignado = id;
        rlutil::locate(40,14);
        cout << "POR FAVOR INGRESE LA CANTIDAD DE COMENSALES: ";
        rlutil::locate(40,15);
        cin >> _comensales;

        ///PEDIR CONFIRMACION Y QUE ESO LLEVE A MOSTRAR VISTA MESA
        int respuesta = MessageBox(NULL, "LOS DATOS INGRESADOS SON CORRECTOS?", "VALIDACION DATOS", MB_YESNOCANCEL);
        switch (respuesta)
        {
        case 6: //si
        {

            rlutil::cls();
            _horaApertura[0] = horaActual() /*horaActual()*/;
            _horaApertura[1] = minutosActual();

            /// buscar factura y pasar hora para calcular turno
            int pos = archiFac.buscarRegistro(_idFactura);
            obj = archiFac.leerRegistro(pos);
            obj.setTurno(_horaApertura[0]);
            obj.setIdEmpleado(_empleadoAsignado);
            obj.setTipo(1);

            archiFac.actualizarRegistro(obj);
            return;
            break;
        }
        case 7: //no
        {
            rlutil::cls();
            this->cargarLocal();
            break;
        }
        case 2://volver
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
        cout << _horaApertura[0] << ":" << _horaApertura[1];
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
    _horaApertura[0] = 0;
    _horaApertura[1] = 0;

    _comensales = -1;
    _empleadoAsignado = -1;
}
void Local::cerrarLocal()
{
    if (cerrarMesa())
    {
        ArchivoMesasLocal arcLocal;
        liberarMesa();
        arcLocal.actualizarMesa(*this);

        mostrarMapaMesas();
    }
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
    ArchivoFactura arc;
    Factura obj;

    do
    {

        limpiarDesdePosicion(10,10,90,8);
        rlutil::locate(10, 10);
        cout << "INGRESE EL TELEFONO DEL CLIENTE: ";
        cargarCadena(_telefonoCliente, 20);


        rlutil::locate(10, 11);
        cout << "INGRESE EL ID DEL DELIVERY ASIGNADO: ";
        int id;
        cin >> id;

        ArchivoUsuario arcUs;
        Usuario objUs;
        int posUs = arcUs.buscarRegistro(id);
        objUs = arcUs.leerRegistro(posUs);

        while(!objUs.getEstado() || arcUs.buscarRegistro(id) == -2)
        {
            rlutil::setColor(rlutil::RED);
            rlutil::locate(10,11);
            cout << "ID DE USUARIO NO DISPONIBLE, INTENTE NUEVAMENTE: ";
            rlutil::locate(59,11);
            cout << "     ";
            rlutil::locate(59,11);
            cin >> id;
            posUs = arcUs.buscarRegistro(id);
            objUs = arcUs.leerRegistro(posUs);
        }
        rlutil::setColor(rlutil::WHITE);
        _deliveryAsignado = id;




        rlutil::locate(10, 12);
        cout << "INGRESE LA HORA DE ENTREGA: ";
        cin >> _horaEntrega;
        rlutil::locate(10, 13);
        cout << "INGRESE EL DOMICILIO A ENTREGAR: " << endl;
        _direccionEntrega.Cargar();


        int pos = arc.buscarRegistro(_idFactura);
        obj = arc.leerRegistro(pos);
        obj.setTurno(_horaEntrega);
        obj.setTipo(2);
        obj.setIdEmpleado(_deliveryAsignado);
    }
    while (MessageBox(NULL, "LOS DATOS INGRESADOS SON CORRECTOS?", "CONFIRMACION DATOS", MB_YESNO) == 7);

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
        rlutil:: locate (15,5);
        rlutil::setColor(rlutil::BROWN);
        cout << "DELIVERY NRO: ";
        rlutil::setColor(rlutil::LIGHTCYAN);
        cout << _numero;

        rlutil:: locate (45,5);
        rlutil::setColor(rlutil::BROWN);
        cout << "HORA DE ENTREGA: ";
        rlutil::setColor(rlutil::LIGHTCYAN);
        cout << _horaEntrega;

        rlutil:: locate (73,5);
        rlutil::setColor(rlutil::BROWN);
        cout << "TELEFONO: ";
        rlutil::setColor(rlutil::LIGHTCYAN);
        cout << _telefonoCliente;

        rlutil:: locate (105,5);
        rlutil::setColor(rlutil::BROWN);
        cout << "DIRECCION: ";
        rlutil::setColor(rlutil::LIGHTCYAN);
        _direccionEntrega.Mostrar();

        rlutil::setColor(rlutil::BROWN);
        dibujarBordeSyI(10,6);



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
                if(cerrarDelivery())
                {
                    rlutil::cls();
                    pantallaDelivery();
                }
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
bool Delivery::cerrarDelivery()
{
    if (cerrarMesa())
    {

        entregarDelivery();

        ArchivoDelivery arc;
        arc.eliminarRegistro(_numero);
        return true;
    }
    return false;
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
        rlutil:: locate (15,5);
        rlutil::setColor(rlutil::BROWN);
        cout << "PEDIDO NRO: ";
        rlutil::setColor(rlutil::LIGHTCYAN);
        cout << _numero;

        rlutil:: locate (45,5);
        rlutil::setColor(rlutil::BROWN);
        cout << "HORA DE RETIRO: ";
        rlutil::setColor(rlutil::LIGHTCYAN);
        cout << _horaRetiro;

        rlutil:: locate (73,5);
        rlutil::setColor(rlutil::BROWN);
        cout << "TELEFONO: ";
        rlutil::setColor(rlutil::LIGHTCYAN);
        cout << _telefonoCliente;

        rlutil:: locate (105,5);
        rlutil::setColor(rlutil::BROWN);
        cout << "NOMBRE CLIENTE: ";
        rlutil::setColor(rlutil::LIGHTCYAN);
        cout << _nombreCliente;

        rlutil::setColor(rlutil::BROWN);
        dibujarBordeSyI(10,6);

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
                if (cerrarTakeAway())
                {
                    rlutil::cls();
                    pantallaTakeAway();
                }
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
bool TakeAway::cerrarTakeAway()
{
    if (cerrarMesa())
    {

        entregarTakeAway();
        ArchivoTakeAway arcTake;
        arcTake.eliminarRegistro(_numero);
        return true;
    }
    return false;
}
void TakeAway::entregarTakeAway()
{
    _entregado = true;
}
void TakeAway::disminuirNumero()
{
    _numero--;
}
