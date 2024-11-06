

#include "clases.h"
#include "funciones.h"


/// CLASES AUXILIARES


    void Fecha::Cargar(){
        cin>>_dia;
        cin>>_mes;
        cin>>_anio;
    }
    void Fecha::Mostrar(){
        cout<<_dia<<"/";
        cout<<_mes<<"/";
        cout<<_anio<<endl;
    }

    int Fecha::getDia(){return _dia;}
    int Fecha::getMes(){return _mes;}
    int Fecha::getAnio(){return _anio;}

    void Fecha::setDia(int d){_dia=d;}
    void Fecha::setMes(int m){_mes=m;}
    void Fecha::setAnio(int a){_anio=a;}


int Tiempo::getHora(){
    return _local->tm_hour;
}


Fecha Tiempo::getFecha(){
    Fecha fecha;
    fecha.setDia(_local->tm_mday);
    fecha.setMes(_local->tm_mon+1);
    fecha.setAnio(_local->tm_year + 1900);

    return fecha;
}


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

int Mesa::getNumero()
{
    return _numero;
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
    _horaApertura = horaActual();
}

void Local::mostrarLocal()
{
    Mesa::mostrarMesa();
    cout << "HORA DE APERTURA: " << _horaApertura << endl;
    cout << "CAMARERO ASIGNADO: " << _empleadoAsignado << endl;
    cout << "COMENZALES: " << _comensales << endl;
    /// buscar el id asignado a _IDpedido en el archivo de pedidos y sacar el total
    /// lo de arriba / _comensales
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

    _horaEntrega = horaActual();
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

    _horaRetiro = horaActual();

    cout << "INGRESE EL NOMBRE DEL CLIENTE: ";
    cin.getline(_nombreCliente, 50);
}

void TakeAway::mostrarTakeAway()
{
    Mesa::mostrarMesa();

    cout << "HORA DE RETIRO: " << _horaRetiro;
    cout << "NOMBRE DEL CLIENTE: " << _nombreCliente;
}

/// CLASE BASE USUARIO

void Usuario::cargar()
{
    cout << "INGRESE NOMBRE COMPLETO: " << endl;
    cin >> _nombre;

    cout << "INGRESE DNI: " << endl;
    cin >> _dni;

    _id=generarId(1);
    mostrar();
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
Pedido::Pedido(){
    _id ;
    _turno; ///sacar el turno de la hora local
    _tipo;
    _importeTotal = 0;
    _fecha;
    vector<Producto*> _productos;
}

Pedido::Pedido(int hora, int tipo){
    _id = generarId(3);
    _turno; ///sacar el turno de la hora local
    _tipo = tipo;
    _importeTotal = 0;
    _fecha = fechaActual();
    vector<Producto*> _productos;

    /// Logica del turno;
    if(hora >= 9 && hora <= 14){
        _turno = 1;
    } else if (hora >= 15 && hora <= 20){
        _turno = 2;
    } else {_turno = 3;}

}


// FUNCIONES DEL ARRAY _PRODUCTOS

void Pedido::cargarItem(Producto *nuevoProducto)
{
    _productos.push_back(nuevoProducto);

    /// agregar los cambios en el archivo segun id.

}

void Pedido::quitarItem(int pos)
{
    /// pide contraseÑa
    _productos.erase(_productos.begin()+pos-1);
    /// agregar los cambios en el archivo segun id.


}


void Pedido::mostrarPedido()
{
    for (int i = 0; i < _productos.size(); i++){
        cout << i+1 << " - " << endl;
        _productos.at(i)->Mostrar();
        cout << "------------------" << endl;

    }
}
// FIN FUNCIONES ARRAY _PRODUCTOS

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

int Pedido::getId(){
    return _id;
}

void Pedido::aplicarDescuento(int tipo, float descuento)
{
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

void Producto::Cargar()
{
    cout << "NOMBRE: ";
    cin.getline(_nombre, 30);

    cout << "PRECIO: ";
    cin >> _precio;

    cout << "TIPO: ";
    cin.ignore();
    cin.getline(_tipo, 10);

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
void Producto::Deshabilitar()
{
    _disponible = false;
}
void Producto::Habilitar()
{
    _disponible = true;
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
void Producto::setTipo(const char *tipo)
{
    strcpy(_tipo, tipo);
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
const char* Producto::getTipo()
{
    return _tipo;
}

