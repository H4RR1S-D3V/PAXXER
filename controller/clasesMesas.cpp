/// FACTURA (CAMBIAR LUEGO)

#include <iostream>

#include "clasesMesas.h"
#include "clasesArchivos.h"
#include "generadorIDs.h"
#include "../view/funcionesDibujar.h"
#include "../view/pantallasMenuPrincipal.h"
#include "../view/declaracionOpcionesMapaMesas.h"   /// WTF... cargarItem() viene de aca??
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
void Mesa::abrirMesa(){}
void Mesa::cerrarMesa(){}
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
Local::Local(){}
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
                cerrarMesa();
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
void Local::cerrarMesa()
{
    Factura objFac;
    ArchivoFactura arcFac;
    int pos = arcFac.buscarRegistro(_idFactura);
    objFac = arcFac.leerRegistro(pos);

    int opcion;

    /// PASAR A FUNCION
    rlutil::locate(60, 36);
    cout << "DESEA APLICAR AlGUN DESCUENTO? (1-SI 0-NO) ";
    rlutil::locate(60, 37);
    cout<<"UNA VEZ FINALICE PRESIONE ENTER PARA CONTINUAR";
    rlutil::locate(80, 38);
    rlutil::setColor(rlutil::WHITE);
    cin >> opcion;

    if(opcion)
    {
        float descuento;

        rlutil::setColor(rlutil::BROWN);
        rlutil::locate(60, 36);
        cout << "SELECCIONAR TIPO DE DESCUENTO: (1-MONTO FIJO 2-PORCENTAJE) ";
        rlutil::locate(60, 37);
        cout << "UNA VEZ FINALICE PRESIONE ENTER PARA CONTINUAR";
        rlutil::locate(80, 38);
        rlutil::setColor(rlutil::WHITE);
        cout << " ";
        cin >> opcion;

        switch(opcion)
        {
        case 1:
            rlutil::setColor(rlutil::BROWN);
            rlutil::locate(60, 36);
            cout << " ";
            rlutil::locate(60, 36);
            cout << "DESCUENTO A APLICAR: ";
            rlutil::locate(60, 37);
            cout << "UNA VEZ FINALICE PRESIONE ENTER PARA CONTINUAR";
            rlutil::locate(80, 38);
            rlutil::setColor(rlutil::WHITE);
            cout << " ";
            cin >> descuento;

            if(descuento > objFac.getImporteSubTotal())
            {
                rlutil::setColor(rlutil::BROWN);
                rlutil::locate(60, 36);
                cout << "MONTO SUPERIOR AL TOTAL DE LA FACTURA";
                rlutil::locate(80, 38);
                rlutil::setColor(rlutil::WHITE);
                cout << " ";
                system("pause");
            }
            else
            {
                objFac.aplicarDescuento(1, descuento);
            }
            break;
        case 2:
            rlutil::setColor(rlutil::BROWN);
            rlutil::locate(60, 36);
            cout << " ";
            rlutil::locate(60, 36);
            cout << "DESCUENTO A APLICAR: ";
            rlutil::locate(60, 37);
            cout << "UNA VEZ FINALICE PRESIONE ENTER PARA CONTINUAR";
            rlutil::locate(80, 38);
            rlutil::setColor(rlutil::WHITE);
            cout << " ";
            cin >> descuento;

            if(descuento > 100 || descuento < 0)
            {
                rlutil::setColor(rlutil::BROWN);
                rlutil::locate(60, 36);
                cout << "MONTO SUPERIOR AL TOTAL DE LA FACTURA";
                rlutil::locate(80, 38);
                rlutil::setColor(rlutil::WHITE);
                cout << " ";
                system("pause");
            }
            else
            {
                objFac.aplicarDescuento(2, descuento);
            }
            break;
        default:
            rlutil::setColor(rlutil::BROWN);
            rlutil::locate(60, 36);
            cout << "INGRESE UNA OPCOIN VALIDA";
            rlutil::locate(80, 38);
            rlutil::setColor(rlutil::WHITE);
            cout << " ";
            system("pause");
        }
    }
    else
    {
        objFac.setImporteTotal(objFac.getImporteSubTotal());
    }
    arcFac.actualizarRegistro(objFac);
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
Delivery::Delivery(){}
Delivery::Delivery(int num)
{
    _numero = num;
}
void Delivery::cargarDelivery()
{
    cargarMesa();

    /// buscar factura y pasar hora para calcular turno

    cout << "INGRESE EL TELEFONO DEL CLIENTE: ";
    cargarCadena(_telefonoCliente, 20);

    cout << "INGRESE EL ID DEL DELIVERY ASIGNADO: ";
    cin >> _deliveryAsignado;

    cout << "INGRESE LA HORA DE ENTREGA: ";
    cin >> _horaEntrega;

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
void Delivery::mostrarDelivery()
{

    ArchivoFactura arcFac;

    Factura objFac;
    int pos = arcFac.buscarRegistro(_idFactura);
    objFac = arcFac.leerRegistro(pos);

    cout << _numero << " | ";
    _direccionEntrega.Mostrar();
    cout << " | " << _deliveryAsignado << " | "; // SACAR NOMBRE CON ID
    cout << _horaEntrega << "Hs. | ";
    cout << "$" << objFac.getImporteSubTotal() << " | ";

    if(!_entregado)
    {
        cout << "PENDIENTE" << endl;
    }
    else
    {
        cout << "ENTREGADO" << endl;
    }
}
void Delivery::abrirMesa()
{
    Delivery obj;
    ArchivoDelivery arcDel;
    ArchivoFactura arcFac;

    int pos = _numero -1;
    obj = arcDel.leerRegistro(pos);

    cout << "# | ";
    cout << "DIRECCION DE ENTREGA | ";
    cout << "RESPONSALBLE | ";
    cout << "HORA DE ENTREGA | ";
    cout << "TOTAL | ";
    cout << "ESTADO | " << endl;
    cout << "-------------------------------------------------------------------" << endl;

    obj.mostrarDelivery();

    /// MOSTRAR FACTURA (PEDIDO)
    Factura objFac;
    pos = arcFac.buscarRegistro(_idFactura);
    objFac = arcFac.leerRegistro(pos);

    objFac.mostrarFacturaDetalle();

    cout << endl;
    system("pause");

    return;
}
void Delivery::cerrarMesa()
{
    Factura objFac;
    ArchivoFactura arcFac;
    int pos = arcFac.buscarRegistro(_idFactura);
    objFac = arcFac.leerRegistro(pos);

    int opcion;

    cout << "�DESEA APLICAR AlGUN DESCUENTO? (1-SI 0-NO) ";
    cin >> opcion;

    if(opcion)
    {
        float descuento;

        cout << "SELLECCIONAR TIPO DE DESCUENTO: (1-MONTO FIJO 2-PORCENTAJE) ";
        cin >> opcion;

        switch(opcion)
        {
        case 1:
            cout << "DESCUENTO A APLICAR: ";
            cin >> descuento;

            if(descuento > objFac.getImporteSubTotal())
            {
                cout << "MONTO SUPERIOR AL TOTAL DE LA FACTURA" << endl;
                system("pause");
            }
            else
            {
                objFac.aplicarDescuento(1, descuento);
            }
            break;
        case 2:
            cout << "DESCUENTO A APLICAR: ";
            cin >> descuento;

            if(descuento > 100 || descuento < 0)
            {
                cout << "PORCENTAJE INVALIDO" << endl;
                system("pause");
            }
            else
            {
                objFac.aplicarDescuento(2, descuento);
            }
            break;
        default:
            cout << "INGRESE UNA OPCION VALIDA" << endl;
            system("pause");
            break;
        }
    }
    else
    {
        objFac.setImporteTotal(objFac.getImporteSubTotal());
    }
    arcFac.actualizarRegistro(objFac);
    ArchivoDelivery arcDel;
    arcDel.eliminarRegistro(_numero - 1);
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
TakeAway::TakeAway(){}
TakeAway::TakeAway(int num)
{
    _numero = num;
}
void TakeAway::cargarTakeAway()
{
    cargarMesa();

    cout << "INGRESE EL TELEFONO DEL CLIENTE: ";
    cargarCadena(_telefonoCliente, 20);

    cout << "INGRESE EL NOMBRE DEL CLIENTE: ";
    cargarCadena(_nombreCliente, 50);

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
void TakeAway::mostrarTakeAway()
{
    ArchivoFactura arcFac;

    Factura objFac;
    int pos = arcFac.buscarRegistro(_idFactura);
    objFac = arcFac.leerRegistro(pos);

    cout << _numero << " | ";
    cout << _nombreCliente << " | ";
    cout << _telefonoCliente << " | ";
    cout << _horaRetiro << "Hs. | ";
    cout << "$" << objFac.getImporteTotal() << " | ";

    if(!_entregado)
    {
        cout << "PENDIENTE" << endl;
    }
    else
    {
        cout << "ENTREGADO" << endl;
    }
}
void TakeAway::abrirMesa()
{
    TakeAway obj;
    ArchivoTakeAway arcTake;
    ArchivoFactura arcFac;

    int pos = _numero -1;
    obj = arcTake.leerRegistro(pos);

    cout << "# | ";
    cout << "NOMBRE | ";
    cout << "TELEFONO | ";
    cout << "HORA RETIRO | ";
    cout << "TOTAL | ";
    cout << "ESTADO | " << endl;
    cout << "-------------------------------------------------------------------" << endl;

    obj.mostrarTakeAway();

    /// MOSTRAR FACTURA (PEDIDO)
    Factura objFac;
    pos = arcFac.buscarRegistro(_idFactura);
    objFac = arcFac.leerRegistro(pos);

    objFac.mostrarFactura(0);

    return;
}
void TakeAway::cerrarMesa()
{
    Factura objFac;
    ArchivoFactura arcFac;
    int pos = arcFac.buscarRegistro(_idFactura);
    objFac = arcFac.leerRegistro(pos);

    int opcion;

    cout << " DESEA APLICAR AlGUN DESCUENTO? (1-SI 0-NO) ";
    cin >> opcion;

    if(opcion)
    {
        float descuento;

        cout << "SELLECCIONAR TIPO DE DESCUENTO: (1-MONTO FIJO 2-PORCENTAJE) ";
        cin >> opcion;

        switch(opcion)
        {
        case 1:
            cout << "DESCUENTO A APLICAR: ";
            cin >> descuento;

            if(descuento > objFac.getImporteSubTotal())
            {
                cout << "MONTO SUPERIOR AL TOTAL DE LA FACTURA" << endl;
                system("pause");
            }
            else
            {
                objFac.aplicarDescuento(1, descuento);
            }
            break;
        case 2:
            cout << "DESCUENTO A APLICAR: ";
            cin >> descuento;

            if(descuento > 100 || descuento < 0)
            {
                cout << "PORCENTAJE INVALIDO" << endl;
                system("pause");
            }
            else
            {
                objFac.aplicarDescuento(2, descuento);
            }
            break;
        default:
            cout << "INGRESE UNA OPCION VALIDA" << endl;
            system("pause");
            break;
        }
    }
    else
    {
        objFac.setImporteTotal(objFac.getImporteSubTotal());
    }
    arcFac.actualizarRegistro(objFac);
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
