

#include "clases.h"
#include "funciones.h"
#include "clasesArchivos.h"


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


Fecha Tiempo::getFecha()
{
    Fecha fecha;
    fecha.setDia(_local->tm_mday);
    fecha.setMes(_local->tm_mon+1);
    fecha.setAnio(_local->tm_year + 1900);

    return fecha;
}

/// CLASE AUXILIAR CONTROLADOR DE VECTORES DE PRODUCTOS

controladorProductos::controladorProductos(){

    vector<int> _vIdsProductos(_tamanio, 0);
    vector<int> _vCantPorProductos(_tamanio, 0);
    vector<float> _vPreciosProductos(_tamanio, 0);
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
            ++pos;
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

    ordenarVectores();
    while(_vIdsProductos[i] != 0)
    {
        if(_vIdsProductos[i] == idProducto)
        {
            _vCantPorProductos[i]++;
            return;
        }
        i++;
    }
    _vIdsProductos[i] = idProducto;
    _vCantPorProductos[i]++;
    _vPreciosProductos[i] = NULL; /// FALTA BUSCAR EL PRECIO DADO UN ID DE PRODUCTO

    ordenarVectores();
    return;
}

void controladorProductos::quitarProducto(int pos, int cant)
{
    pos = pos-1; /// al mostrarse se le suma 1, por lo que al nro ingresado hay q restarle
    _vCantPorProductos[pos] =- cant;
    if(_vCantPorProductos[pos] <= 0)
    {
        _vIdsProductos[pos] = 0;
        _vPreciosProductos[pos] = 0.0;
    }

    ordenarVectores();
}

void controladorProductos::mostrarProductos()
{
    int i = 0;
    ordenarVectores();
    while(_vIdsProductos[i] != 0)
    {
        cout << "#" << i+1 << " " << "NOMBRE SEGUN ID: " << _vCantPorProductos[i] << " SUB: $" << _vPreciosProductos[i] << " TOTAL: $" << _vPreciosProductos[i] * _vCantPorProductos[i] << endl;
        i++;
    }
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
    /// GENERAR Factura Y ASIGNARLO
    Factura obj;
    ArchivoFactura arc;

    arc.agregarRegistro(obj);

    _idFactura = obj.getId();
}

void Mesa::mostrarMesa()
{
    cout << "N° " << _numero << endl;
    //cout << "TOTAL: " <<  _Factura.getImporteTotal() << endl;
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

int Mesa::getIdFactura()
{
    return _idFactura;
}

/// CLASE HEREDADA LOCAL

void Local::cargarLocal()
{
    cargarMesa();

    /// buscar factura y pasar hora para calcular turno

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
    cout << "COMENSALES: " << _comensales << endl;
    /// buscar el id asignado a _IDFactura en el archivo de Facturas y sacar el total
    /// lo de arriba / _comensales
}

/// CLASE HEREDADA DELIVERY

void Delivery::cargarDelivery()
{
    cargarMesa();

    /// buscar factura y pasar hora para calcular turno


    cout << "INGRESE EL TELEFONO DEL CLIENTE: ";
    cin.getline(_telefonoCliente, 10);

    cout << "INGRESE EL DELIVERY ASIGNADO: ";
    /// id del delivery

    cout << "INGRESE LA HORA DE ENTREGA: ";

    cin >> _horaEntrega;
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
    cargarMesa();
    /// buscar factura y pasar hora para calcular turno

    cout << "INGRESE LA HORA DE RETIRO: ";

    cin >> _horaRetiro;

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

/// CLASE BASE PRODUCTO

void Producto::Cargar()
{
    cout << "NOMBRE: ";
    cin.getline(_nombre, 30);

    cout << "PRECIO: ";
    cin >> _precio;

    cout << "TIPO (1-Entrada | 2-Plato Principal | 3-Postre | 4-Bebida : ";
    cin >> _tipo;

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

/// FUNCIONES DEL ARRAY _PRODUCTOS

void Factura::setId(int id)
{
    _id = id;
}
void Factura::actualizarImporteTotal()
{
    _importeSubTotal = _productos.calcularPrecioTotal();
}

void Factura::cargarItem(int idProducto)
{
    /*
    int i = 0;

    Producto obj;
    ArchivoFactura arcFac;
    ArchivoProducto arcPro;

    while(_vIdsProductos[i] != 0)
    {
        if(_vIdsProductos[i] == idProducto)
        {
            _vCantPorProductos[i]++;

            actualizarImporteTotal();

            /// agregar los cambios en el archivo segun id.
            arcFac.actualizarFactura(this,this->_id);

            return;
        }
        i++;
    }

    int pos = arcPro.buscarRegistroPorId(idProducto);
    obj = arcPro.leerRegistro(pos);

    _vIdsProductos[i] = idProducto;
    _vCantPorProductos[i]++;
    _vPreciosProductos[i] = obj.getPrecio();

    actualizarImporteTotal();

    /// agregar los cambios en el archivo segun id.
    arcFac.actualizarFactura(this,this->_id);
    */
}

/// CAMBIO 6 (SE RESTA UNA CANTIDAD DADA AL INDEX DESEADO)
void Factura::quitarItem(int pos, int cant)
{
    /*
    /// pide contraseÑa
    _vCantPorProductos[pos] =- cant;
    if(_vCantPorProductos[pos] <= 0)
    {
        _vIdsProductos[pos] = 0;
        _vPreciosProductos[pos] = 0.0;
        // QUITAR 0 DEL MEDIO
        // OJO CON LOS OTROS DOS VECTORES
    }
    actualizarImporteTotal();
    /// agregar los cambios en el archivo segun id.
    ArchivoFactura archi;
    archi.actualizarFactura(this, this->_id);
    */
}


void Factura::mostrarFactura()
{
    /*int i = 0;

    Producto obj;
    ArchivoProducto arc;

    while(_vIdsProductos[i] != 0)
    {
        int pos = arc.buscarRegistroPorId(_vIdsProductos[i]);
        obj = arc.leerRegistro(pos);

        cout << "#" << i+1 << " " << obj.getNombre() << " x" << _vCantPorProductos[i] << " SUB: $" << _vPreciosProductos[i] << " TOTAL: $" << _vPreciosProductos[i] * _vCantPorProductos[i] << endl;
        i++;
    }
    */
}
// FIN FUNCIONES ARRAY _PRODUCTOS

void Factura::setTurno(int hora){
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

void Factura::cerrarFactura()
{
    /// preguntar por descuento
    /// guardar Factura en archivo
}

char Factura::getTipo()
{
    return _tipo;
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
        _importeTotal -= descuento;
    }
    else
    {
        _importeTotal -= ((_importeTotal * descuento) / 100 );
    }
}

/// CLASE BASE RECAUDACION
/*
void Recaudacion::setFecha()
{
    _fecha.Cargar();
}
void Recaudacion::setTurno(int turno)
{
    _turno = turno;
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
void Recaudacion::setTipoMesa(int tipoMesa)
{
    _tipoMesa = tipoMesa;
}
void Recaudacion::setIdEmpleado(int id)
{
    _idEmpleado = id;
}
void Recaudacion::setCantComensales(int cantidad)
{
    _cantComensales = cantidad;
}
void Recaudacion::setIdFactura(int IDFactura)
{
    _IDFactura = IDFactura;
}
// GETTERS

Fecha Recaudacion::getFecha(){return _fecha;}
int Recaudacion::getAnio(){return _fecha.getAnio();}
int Recaudacion::getMes(){return _fecha.getMes();}
int Recaudacion::getDia(){return _fecha.getDia();}
int Recaudacion::getTurno(){return _turno;}
int Recaudacion::getId(){return _id;}
float Recaudacion::getImporteSubTotal(){return _importeSubTotal;}
float Recaudacion::getImporteFinal(){return _importeFinal;}
int Recaudacion::getIdFactura(){return _IDFactura;}

// METHODS

void Recaudacion::Cargar()
{
    // CAPAZ NO SEA NECESARIO
    cout << "ID: ";
    cin >> _id;

    cout << "FECHA: ";
    _fecha.Cargar();

    cout << "TURNO: ";
    cin >> _turno;    /// DECODIFICAR A: 1=MANIANA; 2=TARDE; 3=NOCHE

    cout << "SUB TOTAL: ";
    cin >> _importeSubTotal;

    cout << "TOTAL: ";
    cin >> _importeFinal;

    cout << "TIPO DE MESA: ";
    cin >> _tipoMesa;   /// DECODIFICAR A: 1=LOCAL; 2=DELIVERY; 3=TAKE AWAY

    cout << "RESPONSABLE DE LA VENTA: ";
    cin >> _idEmpleado;

    cout << "CANT. COMENSALES: ";
    cin >> _cantComensales;
}

void Recaudacion::Mostrar()
{
    cout << "ID: " << _id << endl;
    cout << "FECHA: ";
    _fecha.Mostrar();
    cout << "TURNO: " << _turno << endl;    /// DECODIFICAR A: 1=MANIANA; 2=TARDE; 3=NOCHE
    if(_importeFinal != _importeSubTotal)
    {
        cout << "IMPORTE SUB TOTAL: $" << _importeSubTotal << endl;
    }
    cout << "IMPORTE FINAL: $" << _importeFinal << endl;
    cout << "TIPO DE MESA: " << _tipoMesa << endl;  /// DECODIFICAR A: 1=LOCAL; 2=DELIVERY; 3=TAKE AWAY
    if(_tipoMesa != 3) /// TAKE AWAY NO TIENE EMPLEADO ASIGNADO
    {
        cout << "RESPONSABLE DE LA VENTA: " << _idEmpleado << endl;
    }
    if(_tipoMesa == 1)
    {
        cout << "COMENSALES: " << _cantComensales << endl;
    }
}

*/
