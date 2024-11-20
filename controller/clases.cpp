#include <iostream>
#include <string>
#include <cstring>
#include "clases.h"
#include "funciones.h"
#include "clasesArchivos.h"
#include "../rlutil.h"
#include "../view/funcionesDibujar.h"
#include "../view/pantallasMenuPrincipal.h"
#include <cctype>



/// CLASES AUXILIARES


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

void Domicilio::Cargar()
{
    cout << "CALLE: ";
    cargarCadena(_calle, 20);

    cout << "ALTURA: ";
    cin >> _altura;

    cout << "LOCALIDAD: ";
    cargarCadena(_localidad, 20);
}

void Domicilio::Mostrar()
{
    cout << _calle << " " << _altura << " - " << _localidad << endl;
}


void controladorProductos::ordenarVectores()
{
    int pos = 0;

    for (int i = 0; i < _tamanio; ++i)
    {
        if (_vCantPorProductos[i] != 0)
        {
            _vIdsProductos[pos] = _vIdsProductos[i];
            _vCantPorProductos[pos] = _vCantPorProductos[i];
            _vPreciosProductos[pos] = _vPreciosProductos[i];
            pos++;
        }
    }
    // LLENAR CON CEROS DESDE POS HASTA EL FINAL
    for (int i = pos; i < _tamanio; ++i)
    {
        _vIdsProductos[i] = 0;
        _vCantPorProductos[i] = 0;
        _vPreciosProductos[i] = 0;
    }
}

float controladorProductos::calcularPrecioTotal()
{
    float acumulador = 0;
    int i = 0;

    ordenarVectores();

    while(_vPreciosProductos[i] != 0)
    {
        acumulador += (_vPreciosProductos[i] * float(_vCantPorProductos[i]));
        i++;
    }
    return acumulador;
}

void controladorProductos::cargarProducto(int idProducto)
{
    int i = 0;

    Producto obj;
    ArchivoFactura arcFac;
    ArchivoProducto arcPro;

    while(_vIdsProductos[i] != 0)
    {
        if(_vIdsProductos[i] == idProducto)
        {
            _vCantPorProductos[i]++;

            return;
        }
        i++;
    }

    int pos = arcPro.buscarRegistroPorId(idProducto);
    obj = arcPro.leerRegistro(pos);

    _vIdsProductos[i] = idProducto;
    _vCantPorProductos[i]++;
    _vPreciosProductos[i] = obj.getPrecio();
}

void controladorProductos::quitarProducto(int pos, int cant)
{
    pos = pos-1; /// al mostrarse se le suma 1, por lo que al nro ingresado hay q restarle
    _vCantPorProductos[pos] -= cant;
    if(_vCantPorProductos[pos] <= 0)
    {
        _vIdsProductos[pos] = 0;
        _vCantPorProductos[pos] = 0;
        _vPreciosProductos[pos] = 0.0;
    }

    ordenarVectores();
}

void controladorProductos::mostrarProductos()
{
    int i = 0;

    Producto obj;
    ArchivoProducto arc;

    cout << endl << "productos:" <<endl;
    while(_vIdsProductos[i] != 0)
    {
        int pos = arc.buscarRegistroPorId(_vIdsProductos[i]);
        obj = arc.leerRegistro(pos);

        cout << "#" << i+1 << " " << obj.getNombre() << " x" << _vCantPorProductos[i] << " SUB: $" << _vPreciosProductos[i] << " TOTAL: $" << _vPreciosProductos[i] * _vCantPorProductos[i] << endl;
        i++;
    }
}
controladorProductos& controladorProductos::operator=(const controladorProductos& otro) {
        if (this != &otro){
            for (int i = 0; i < 30; ++i) {
                _vIdsProductos[i] = otro._vIdsProductos[i];
                _vCantPorProductos[i] = otro._vCantPorProductos[i];
                _vPreciosProductos[i] = otro._vPreciosProductos[i];
            }/*
            _vIdsProductos = otro._vIdsProductos;
            _vCantPorProductos = otro._vCantPorProductos;
            _vPreciosProductos = otro._vPreciosProductos;*/
        }
        return *this;
    }

/// CLASE BASE MESA

Mesa::Mesa()
{
    _numero = 0;
    ///_disponible = true;
}

Mesa::Mesa(int numero)
{
    _numero = numero;
    ///_disponible = true;

}

void Mesa::abrirMesa(){}
void Mesa::cerrarMesa(){}


void Mesa::cargarMesa()
{
    // FALTA SETEAR EL NUMERO DE MESA
    _disponible = false;    /// LA MESA SE OCUPA AL ABRIRLA
    /// GENERAR Factura Y ASIGNARLO

    _idFactura = generarId(3);
    Factura obj(_idFactura);

    ArchivoFactura arc;

    arc.agregarRegistro(obj);
}

void Mesa::mostrarMesa()
{
    ///METODO INNECESARIO??
    ///cout << "N� " << _numero << endl;

    // SETEAR COLOR Y FUNCIONALIDADES SEGUN DISPONBLE
    /// DIBUJAR()
}

void Mesa::setNumero(int numero)
{
    _numero = numero;
}

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

/// CLASE HEREDADA LOCAL

Local::Local(int numeroMesa)
{
    _numero = numeroMesa;
    _disponible = true;
    _empleadoAsignado;
}

Local::Local()
{

}

void Local::cargarLocal()
{
    ArchivoFactura archiFac;
    Factura obj;
    cargarMesa();

    /*
    // CUANDO SE ABRE POR PRIMERA VEZ
    cout << "INGRESE EL ID EL CAMARERO ASIGNADO: ";
    cin >> _empleadoAsignado;

    cout << "INGRESE LA CANTIDAD DE COMENSALES: ";
    cin >> _comensales;
    */
    /// seccion grafica
    bool salir = true;
    int y=0;
    do
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
    mostrarMesa();
        bool salir = true;
        int x=0;
    do
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
            case 0://CARGAR
                {
                rlutil::cls();
                ///cargarItem();
                break;
                }
            case 30://QUITAR


                break;
                }
            case 60://CERRAR MESA

                break;
            case 90://VOLVER
                rlutil::cls();
                salir=false;
                mostrarMapaMesas();
                break;
            }
            break;
        }
    }
    while (salir==true);

        ///BUSCAR FACTURA Y MOSTRARLA
        ArchivoFactura arc;
        Factura obj;
        int pos = arc.buscarRegistro(_idFactura);
        obj = arc.leerRegistro(pos);
        obj.mostrarFactura();

        /// SACAR EL ID Y BUSCAR EL PEIDOD (FACTURA) PARA MOSTRAR EL TOTAL
        //cout << "TOTAL: " <<  _Factura.getImporteTotal() << endl;
    //}
}

void Local::abrirMesa()
{
    // PREGUNTAR SI LA MESA ESTA DISPO PARA ASIGNAR CAMARERO Y FACTURA Y CAMBIAR ESTADO

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

    /// buscar el id asignado a _IDFactura en el archivo de Facturas y sacar el total
    /// lo de arriba / _comensales

    /// SUBMENU DE OPCIONES

}

void Local::liberarMesa()
{
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
    ArchivoMesasLocal arcLocal;

    liberarMesa();
    arcLocal.actualizarMesa(*this);
}

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
    // PROVISORIO
    strcpy(_direccionEntrega, "VALLE GRANDE 151");
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

    ArchivoFactura arc;
    Factura obj;

    int pos = arc.buscarRegistro(_idFactura);
    obj = arc.leerRegistro(pos);
    obj.setTurno(horaActual());
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
    cout << _direccionEntrega << " | ";
    cout << _deliveryAsignado << " | "; // SACAR NOMBRE CON ID
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
    // PREGUNTAR SI LA MESA ESTA DISPO PARA ASIGNAR CAMARERO Y FACTURA Y CAMBIAR ESTADO

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

    objFac.mostrarFactura();

    return;

    /// buscar el id asignado a _IDFactura en el archivo de Facturas y sacar el total
    /// lo de arriba / _comensales

    /// SUBMENU DE OPCIONES
}

void Delivery::cerrarMesa()
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
    /// buscar factura y pasar hora para calcular turno

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
    Mesa::mostrarMesa();
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
    // PREGUNTAR SI LA MESA ESTA DISPO PARA ASIGNAR CAMARERO Y FACTURA Y CAMBIAR ESTADO

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

    objFac.mostrarFactura();

    return;

    /// buscar el id asignado a _IDFactura en el archivo de Facturas y sacar el total
    /// lo de arriba / _comensales

    /// SUBMENU DE OPCIONES
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

/// CLASE BASE USUARIO
Usuario::Usuario(){}

Usuario::Usuario(char* nombre, char* dni){
    strcpy(_nombre, nombre);
    strcpy(_dni, dni);
    _id = generarId(1);
}

// SETTERS
void Usuario::setId(int id)
{
    _id = id;
}
void Usuario::setNombre(const char* nombre)
{
    strcpy(_nombre, nombre);
}
void Usuario::setDNI(const char *DNI)
{
    strcpy(_dni, DNI);
}
void Usuario::setRol(int rol)
{
    if(rol != 1 || rol != 2)
    {
        cout << "INGRESE UN CODIGO DE ROL VALIDO:" << endl;
        cout << "1 - USUARIO | 2 - ADMINISTRADOR" << endl;
    }
}

// GETTERS
int Usuario::getId()
{
    return _id;
}
char* Usuario::getDNI()
{
    return _dni;
}
bool Usuario::getEstado()
{
    return _estado;
}
const char* Usuario::getNombre()
{
    return _nombre;
}
int Usuario::getRol()
{
    return _rol;
}

// METHODS
void Usuario::Cargar()
{
    cout << "INGRESE NOMBRE COMPLETO: " << endl;
    cargarCadena(_nombre, 50);

    cout << "INGRESE DNI: " << endl;
    cin >> _dni;

    _id=generarId(1);
}

void Usuario::Mostrar()
{
    cout << "NOMBRE: " << _nombre << endl;
    cout << "DNI: " << _dni << endl;
    cout << "ID: " << _id << endl;
}

void Usuario::cambiarEstado()
{
    _estado = !_estado;
}

/// CLASE BASE CREDENCIAL

void Credencial::setPassword(const char* newPassword[12])
{
    strcpy(_password, *newPassword);
}

const char* Credencial::getPassword()
{
    return _password;
}

/// CLASE BASE PRODUCTO

void Producto::Cargar()
{
    rlutil::locate (20,12);
    cout << "NOMBRE: ";
    cargarCadena(_nombre, 30);

    rlutil::locate (40,12);
    cout << "PRECIO: ";
    cin >> _precio;

    rlutil::locate (80,12);
    cout << "TIPO: (1-Entrada | 2-Plato Principal | 3-Postre | 4-Bebida : ";
    cin >> _tipo;

    cin.clear();
    cin.ignore();

    _disponible = true;


    _id = generarId(2);
}
void Producto::Mostrar()
{
    cout << "ID: " << _id << endl;

    cout << "NOMBRE: " << _nombre << endl;

    cout << "PRECIO: $" << _precio << endl;

    cout << "TIPO: " << _tipo << endl;

    if(_disponible)
    {
        cout << "DISPONIBLE" << endl;
    }
    else
    {
        cout << "NO DISPONIBLE" << endl;
    }
}
void Producto::cambiarEstado()
{
    _disponible = !_disponible;
}
void Producto::setId(int id)
{
    _id = id;
}
void Producto::setPrecio(float precio)
{
    _precio = precio;
}
void Producto::setNombre(const char* nombre)
{
    if(strlen(nombre) > 50)
    {
        cout << "EL NOMBRE NO PUEDE TENER MAS DE 50 CARACTERES" << endl;
        return;
    }
    strcpy(_nombre, nombre);
}
void Producto::setTipo(const int tipo)
{
    _tipo = tipo;
}
float Producto::getPrecio()
{
    return _precio;
}
const char* Producto::getNombre()
{
    return _nombre;
}
int Producto::getId()
{
    return _id;
}
bool Producto::getDisponibilidad()
{
    return _disponible;
}
const int Producto::getTipo()
{
    return _tipo;
}


/// CLASE BASE FACTURA
Factura::Factura(){
    controladorProductos();
}

Factura& Factura::operator=(const Factura& otro) {
        if (this != &otro) {

            _id = otro._id;
            _productos = otro._productos;
            _fecha = otro._fecha;
            _turno = otro._turno;
            _tipo = otro._tipo;
            _importeSubTotal = otro._importeSubTotal;
            _importeTotal = otro._importeTotal;
            _tipoYDescuentoAplicado[0] = otro._tipoYDescuentoAplicado[0];
            _tipoYDescuentoAplicado[1] = otro._tipoYDescuentoAplicado[1];
            _idEmpleado = otro._idEmpleado;
        }
        return *this;
}

Factura::Factura(int id)
{
    _id = id;
    //controladorProductos();


}

/// FUNCIONES DEL ARRAY _PRODUCTOS

void Factura::setId(int id)
{
    _id = id;
}

void Factura::setTipo(int tipo)
{
    _tipo = tipo;
}

void Factura::setImporteSubTotal(float monto)
{
    _importeSubTotal = monto;
}

void Factura::setImporteTotal(float monto)
{
    _importeTotal = monto;
}

void Factura::setIdEmpleado(int idEmpleado){
    _idEmpleado = idEmpleado;
}

void Factura::actualizarImporteTotal()
{
    _importeSubTotal = _productos.calcularPrecioTotal();
}

void Factura::cargarItem(int idProducto)
{
    ArchivoFactura arcFac;

    _productos.cargarProducto(idProducto);

    actualizarImporteTotal();

    /// agregar los cambios en el archivo segun id.
    arcFac.actualizarRegistro(*this);
}

void Factura::quitarItem(int pos, int cant)
{
    // PEDIR CONTRASENIA
    _productos.quitarProducto(pos, cant);
    /// agregar los cambios en el archivo segun id.
    ArchivoFactura archi;
    actualizarImporteTotal();
    archi.actualizarRegistro(*this);
}


void Factura::mostrarFactura()
{
        rlutil::setColor(rlutil::MAGENTA);
        dibujarBordeSyI(10,12);
        dibujarBordeSyI(10,14);
        ///PARA MODIFICAR EL LARGO SOLAMENTE SUMARLE AL ULTIMO NUM(EJ: 20+Y(Y=1)
        dibujarBordesDeI(9,13,30);
        dibujarBordesDeI(160,13,30);
        rlutil::setColor(rlutil::YELLOW);
        rlutil::locate(12, 11);
        cout<<"NRO. FACTURA: "<< _id;
        rlutil::locate(50, 11);
        cout<<"ID EMPLEADO: "<< _idEmpleado;
         rlutil::locate(90, 11);
        cout<<"TURNO: "<< 1;
            rlutil::locate(130, 11);
        cout<<"FECHA: ";
         _fecha.Mostrar();

        /// AGREGAR IMPORTES TOTAL Y SUB

        ///MARCO TABLA PRODUCTOS
        rlutil::setColor(rlutil::LIGHTCYAN);
        rlutil::locate(12, 11);
        cout<<"NRO."; //POSICIONAR SU COUT EN EL 13,12
        rlutil::locate(52, 11);
        cout <<"NOMBRE"; //POSICIONAR SU COUT A PARTIR DEL 16,12
        rlutil::locate(100, 11);
        cout <<"CANTIDAD";
        rlutil::locate(122, 11);
        cout <<"PRECIO";
        rlutil::locate(135, 11);
        cout <<"SUB-TOTAL";
        rlutil::locate(152, 11);
        cout <<"TOTAL";

        ///MOSTAR PRODUCTOS
   _productos.mostrarProductos();

}
// FIN FUNCIONES ARRAY _PRODUCTOS

void Factura::setTurno(string horaString){

    int hora = stoi(horaString.substr(0, 2));
    if(hora >= 9 && hora <= 14)
    {
        _turno = 1;
    }
    else if (hora >= 15 && hora <= 20)
    {
        _turno = 2;
    }
    else
    {
        _turno = 3;
    }
}



float Factura::getImporteTotal()
{
    actualizarImporteTotal();
    return _importeTotal;
}

float Factura::getImporteSubTotal()
{
    actualizarImporteTotal();
    return _importeSubTotal;
}

char Factura::getTipo()
{
    return _tipo;
}

controladorProductos Factura::getProductos(){
    return _productos;
}

int Factura::getId()
{
    return _id;
}

void Factura::aplicarDescuento(int tipo, float descuento)
{
    /// pedir contraseÑa maestra

    if(tipo == 1)
    {
        _importeTotal = _importeSubTotal - descuento;
    }
    else if(tipo == 2)
    {
        _importeTotal = _importeSubTotal - ((_importeSubTotal * descuento) / 100 );
    }
}

