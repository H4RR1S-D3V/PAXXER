#include <iostream>
#include <cstring>
#include <iomanip>

#include "ClasesFactura.h"
#include "clasesArchivosFacturas.h"

#include "funciones.h"
#include "../view/funcionesDibujar.h"
#include "../rlutil.h"

using namespace std;

/// CLASE BASE PRODUCTO

//SETTERS
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
// GETTERS
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
//METHODS
void Producto::Cargar()
{
    rlutil::locate(20,12);
    cout << "NOMBRE: ";
    cargarCadena(_nombre, 50);

    rlutil::locate(20,14);
    cout << "PRECIO: ";
    cin >> _precio;

    rlutil::locate(20,16);
    cout << "TIPO: (1-ENTRADA | 2-PLATO PRINCIPAL | 3-POSTRE | 4-BEBIDA): ";
    cin >> _tipo;

    _disponible = true;

    _id = generarId(2);
}
void Producto::Mostrar(int posX, int posY)
{
    rlutil::setColor(rlutil::WHITE);

    rlutil::locate(posX, posY);
    cout << _id;

    rlutil::locate(posX+35, posY);
    cout << _nombre;

    rlutil::locate(posX+90, posY);
    cout << _precio;

    //TIPO: (1-ENTRADA | 2-PLATO PRINCIPAL | 3-POSTRE | 4-BEBIDA)
    rlutil::locate(posX+108, posY);
    switch(_tipo){
    case 1:
        cout << "Entrada";
        break;
    case 2:
        cout << "Principal";
        break;
    case 3:
        cout << "Postre";
        break;
    case 4:
        cout << "Bebida";
        break;
    default:
        cout << "Error";
        break;
    }
    cout << _tipo;
}
void Producto::cambiarEstado()
{
    _disponible = !_disponible;
}
/// FIN CLASE PRODUCTO

/// CLASE CONTROLADOR PRODUCTOS

///METHODS
void controladorProductos::ordenarVectores()
{
    int pos = 0;

    for (int i = 0; i < 30; ++i)
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
    for (int i = pos; i < 30; ++i)
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
bool controladorProductos::cargarProducto(int idProducto, int cant)
{
    int i = 0;

    Producto obj;
    ArchivoFactura arcFac;
    ArchivoProducto arcPro;

    int pos = arcPro.buscarRegistroPorId(idProducto);
    obj = arcPro.leerRegistro(pos);

    if(obj.getDisponibilidad())
    {
        while(_vIdsProductos[i] != 0)
        {
            if(_vIdsProductos[i] == idProducto)
            {
                _vCantPorProductos[i] += cant;

                return true;
            }
            i++;
        }
        _vIdsProductos[i] = idProducto;
        _vCantPorProductos[i]+= cant;
        _vPreciosProductos[i] = obj.getPrecio();
    }
    else
    {
        return false;
    }
}
bool controladorProductos::quitarProducto(int id, int cant)
{
    int i=0;
    while(_vIdsProductos[i] != 0)
    {
        if(_vIdsProductos[i] == id)
        {
            _vCantPorProductos[i] -= cant;
            /// CHEQUEAR SI SE QUEDA SIN CANTIDAD

            if(_vCantPorProductos[i] <= 0)
            {
                _vIdsProductos[i] = 0;
                _vCantPorProductos[i] = 0;
                _vPreciosProductos[i] = 0.0;
            }
            ordenarVectores();
            return true;
        }
        i++;
    }
    return false;
}
void controladorProductos::mostrarProductos()
{
    int i = 0;

    Producto obj;
    ArchivoProducto arc;

    ///MARCO TABLA PRODUCTOS
    rlutil::setColor(rlutil::LIGHTCYAN);
    rlutil::locate(12, 13);
    cout<<"ID."; //POSICIONAR SU COUT EN EL 13,12
    rlutil::locate(52, 13);
    cout <<"NOMBRE"; //POSICIONAR SU COUT A PARTIR DEL 16,12
    rlutil::locate(100, 13);
    cout <<"CANTIDAD";
    rlutil::locate(122, 13);
    cout <<"PRECIO";
    rlutil::locate(135, 13);
    cout <<"TOTAL";

    int posXinicial=13;
    int posYinicial=15;

    while(_vIdsProductos[i] != 0)
    {
        int pos = arc.buscarRegistroPorId(_vIdsProductos[i]);
        obj = arc.leerRegistro(pos);

        rlutil::setColor(rlutil::WHITE);

        rlutil::locate(posXinicial, posYinicial+i);
        cout << obj.getId();

        rlutil::locate(posXinicial+35, posYinicial+i);
        cout << obj.getNombre();

        rlutil::locate(posXinicial+90, posYinicial+i);
        cout << _vCantPorProductos[i];

        rlutil::locate(posXinicial+108, posYinicial+i);
        cout << obj.getPrecio();

        rlutil::locate(posXinicial+122, posYinicial+i);
        cout << fixed<<setprecision(2)<<obj.getPrecio()*_vCantPorProductos[i];

        i++;
    }
}
controladorProductos& controladorProductos::operator=(const controladorProductos& otro)
{
    if (this != &otro)
    {
        for (int i = 0; i < 30; ++i)
        {
            _vIdsProductos[i] = otro._vIdsProductos[i];
            _vCantPorProductos[i] = otro._vCantPorProductos[i];
            _vPreciosProductos[i] = otro._vPreciosProductos[i];
        }
    }
    return *this;
}
/// FIN CLASE CONTROLADOR PRODUCTOS

/// CLASE FACTURA

//SETTERS
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
void Factura::setIdEmpleado(int idEmpleado)
{
    _idEmpleado = idEmpleado;
}
void Factura::setTurno(string horaString)
{

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
//GETTERS
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
int Factura::getTipo()
{
    return _tipo;
}
int Factura::getTurno()
{
    return _turno;
}
controladorProductos Factura::getProductos()
{
    return _productos;
}
int Factura::getId()
{
    return _id;
}
Fecha Factura::getFecha()
{
    return _fecha;
}
int Factura::getIdEmpleado()
{
    return _idEmpleado;
}
//METHODS
Factura::Factura()
{
    controladorProductos();
}
Factura::Factura(int id)
{
    _id = id;
}
Factura& Factura::operator=(const Factura& otro)
{
    if (this != &otro)
    {
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
void Factura::actualizarImporteTotal()
{
    _importeSubTotal = _productos.calcularPrecioTotal();
}
void Factura::cargarItem(int idProducto, int cant)
{
    ArchivoFactura arcFac;

    _productos.cargarProducto(idProducto, cant);

    actualizarImporteTotal();

    /// agregar los cambios en el archivo segun id.
    arcFac.actualizarRegistro(*this);
}
bool Factura::quitarItem(int pos, int cant)
{
    // PEDIR CONTRASENIA
    bool elimino = _productos.quitarProducto(pos, cant);
    /// agregar los cambios en el archivo segun id.
    ArchivoFactura archi;
    actualizarImporteTotal();
    archi.actualizarRegistro(*this);
    return elimino;
}
void Factura::mostrarFacturaDetalle()
{


    mostrarFactura(-3,true ); ///SE LE PASA TRUE COMO PARAMETRO PARA MOSTRAR LOS MARCOS DE LA VISTA DE FACTURA DETALLADA
    ///MOSTAR PRODUCTOS
    _productos.mostrarProductos();

}
void Factura::mostrarFactura(int i, bool dibujarMarco)
{
    if (dibujarMarco){
    rlutil::setColor(rlutil::MAGENTA);
    dibujarBordeSyI(10,12);
    dibujarBordeSyI(10,14);
    ///PARA MODIFICAR EL LARGO SOLAMENTE SUMARLE AL ULTIMO NUM(EJ: 20+Y(Y=1)
    dibujarBordesDeI(9,13,30);
    dibujarBordesDeI(160,13,30);
    }
    rlutil::setColor(rlutil::YELLOW);
    rlutil::locate(12, 11+i+3);
    cout<<"NRO. FACTURA: "<< _id;
    rlutil::locate(40, 11+i+3);
    cout<<"ID EMPLEADO: "<< _idEmpleado;
    rlutil::locate(60, 11+i+3);
    cout<<"TURNO: "<< _turno;
    rlutil::locate(75, 11+i+3);
    cout<<"FECHA: ";
    _fecha.Mostrar();
    rlutil::locate(100, 11+i+3);
    cout<<"SUBTOTAL: " << _importeSubTotal;
    rlutil::locate(130, 11+i+3);
    cout<<"TOTAL: " << _importeTotal;
}
void Factura::aplicarDescuento(int tipo, float descuento)
{
    /// pedir contraseÃ‘a maestra

    if(tipo == 1)
    {
        _importeTotal = _importeSubTotal - descuento;
    }
    else if(tipo == 2)
    {
        _importeTotal = _importeSubTotal - ((_importeSubTotal * descuento) / 100 );
    }
}
bool Factura::preguntarPorDescuento()
{
    int opcion;

    rlutil::locate(60, 36);
    cout << "DESEA APLICAR AlGUN DESCUENTO? (1-SI 0-NO) ";
    rlutil::locate(60, 37);
    cout << "UNA VEZ FINALICE PRESIONE ENTER PARA CONTINUAR";
    rlutil::locate(80, 38);
    rlutil::setColor(rlutil::WHITE);
    cin >> opcion;

    if(opcion)
    {
        float descuento;

        rlutil::setColor(rlutil::BROWN);
        borrarLinea(60, 36);
        rlutil::locate(60, 36);
        cout << "SELECCIONAR TIPO DE DESCUENTO: (1-MONTO FIJO 2-PORCENTAJE) ";
        borrarLinea(60, 38);
        rlutil::locate(80, 38);
        rlutil::setColor(rlutil::WHITE);
        cin >> opcion;

        switch(opcion)
        {
        case 1:
            rlutil::setColor(rlutil::BROWN);
            borrarLinea(60, 36);
            rlutil::locate(60, 36);
            cout << "DESCUENTO A APLICAR: ";
            borrarLinea(60, 38);
            rlutil::locate(80, 38);
            rlutil::setColor(rlutil::WHITE);
            cin >> descuento;

            if(descuento > _importeSubTotal || descuento < 0)
            {
                rlutil::setColor(rlutil::BROWN);
                borrarLinea(60, 36);
                rlutil::locate(60, 36);
                cout << "IMPORTE INVALIDO";
                borrarLinea(60, 38);
                rlutil::locate(80, 38);
                rlutil::setColor(rlutil::WHITE);
                system("pause");
            }
            else
            {
                aplicarDescuento(1, descuento);
            }
            break;
        case 2:
            rlutil::setColor(rlutil::BROWN);
            borrarLinea(60, 36);
            rlutil::locate(60, 36);
            cout << "DESCUENTO A APLICAR: ";
            borrarLinea(60, 38);
            rlutil::locate(60, 38);
            rlutil::setColor(rlutil::WHITE);

            cin >> descuento;

            if(descuento > 100 || descuento < 0)
            {
                rlutil::setColor(rlutil::BROWN);
                borrarLinea(60, 36);
                rlutil::locate(60, 36);
                cout << "IMPORTE INVALIDO";
                borrarLinea(60, 38);
                rlutil::locate(80, 38);
                rlutil::setColor(rlutil::WHITE);
                system("pause");
            }
            else
            {
                aplicarDescuento(2, descuento);
            }
            break;
        default:
            rlutil::setColor(rlutil::BROWN);
            borrarLinea(60, 36);
            rlutil::locate(60, 36);
            cout << "INGRESE UNA OPCOIN VALIDA";
            borrarLinea(60, 38);
            rlutil::locate(80, 38);
            rlutil::setColor(rlutil::WHITE);
            system("pause");
        }
    }
    else
    {
        _importeTotal = _importeSubTotal;
    }

    system("cls");
    mostrarFacturaDetalle();

    ArchivoFactura arc;
    arc.actualizarRegistro(*this);
    rlutil::locate(60, 36);
    system("pause");
}
/// FIN CLASE FACTURA
