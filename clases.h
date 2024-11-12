#pragma once

#include <iostream>
#include <cstring>
#include <ctime>
#include <vector>
using namespace std;


#include "generadorIDs.h"


/// CLASES AUXILIARES

class Fecha
{
private:
    int _dia,_mes, _anio;
public:
    void Cargar();
    void Mostrar();
    int getDia();
    int getMes();
    int getAnio();

    void setDia(int d);
    void setMes(int m);
    void setAnio(int a);
};

class Tiempo
{
private:
    time_t _now = time(0);
    tm* _local = localtime(&_now);
public:
    int getHora();
    Fecha getFecha();

};

/// FIN CLASES AUXILIARES

#include "funciones.h"

class Producto
{

    private:
        int _id;
        char _nombre[50];
        float _precio;
        bool _disponible;
        int _tipo; /// 1-Entrada | 2-Plato Principal | 3-Postre | 4-Bebida
    public:
        /// SETTERS
        void setId(int id);
        void setNombre(const char* nombre);
        void setPrecio(float precio);
        void setTipo(const int tipo);
        void cambiarEstado();
        /// GETTERS
        int getId();
        const char* getNombre();
        float getPrecio();
        bool getDisponibilidad();
        const int getTipo();
        /// METHODS
        void Cargar();
        void Mostrar();
/*
class FacturaAux     /// ¿?
{
private:
    vector <int> _vIDProductos;
    vector <int> _vCantProductos;
    vector <float> _vPrecioProductos;
*/

};

class controladorProductos{
private:
    const int _tamanio = 30; /// CONSTANTE DE TAMAÑO E ITERACION
    vector<int> _vIdsProductos;
    vector<int> _vCantPorProductos;
    vector<float> _vPreciosProductos;

public:
    controladorProductos();
    controladorProductos& operator=(const controladorProductos& otro);
    void ordenarVectores();
    float calcularPrecioTotal();
    void cargarProducto(int idProducto);
    void quitarProducto(int pos, int cant);
    void mostrarProductos();
};

class Factura
{
private:
    int _id;
    /// PRIMER CAMBIO (SE REMPLAZA EL VECTOR DE FACTURA POR 3 ARRAYS)
    controladorProductos _productos;
    Fecha _fecha = fechaActual();
    int _turno; /// 1-MAÑANA / 2-TARDE / 3-NOCHE
    int _tipo; /// 1-LOCAL / 2-DELIVERY / 3-TAKEAWAY
    float _importeSubTotal = 0;
    float _importeTotal = 0;
    int _tipoYDescuentoAplicado[2];
    int _idEmpleado = NULL;
public:

    Factura();
    Factura(int id);
    Factura& operator=(const Factura& otro);
    void actualizarImporteTotal();
    void cargarItem(int IdProducto);
    void quitarItem(int pos, int cant);
    void mostrarFactura();
    void cerrarFactura();
    void aplicarDescuento(int tipo, float descuento);
    ///setters
    void setId(int id);
    void setIdEmpleado(int idEmpleado);
    void setTurno(int hora);
    ///getters
    controladorProductos getProductos();
    float getImporteTotal();
    char getTipo();
    int getId();
};

class Mesa
{
protected:
    int _numero;
    bool _disponible = true;
    char _tipo[10];
    int _idFactura;
public:
    Mesa();
    Mesa(int numero);
    void cargarMesa();
    virtual void abrirMesa();
    void mostrarMesa();
    void cerrarMesa();
    void setNumero(int numero);
    bool getDisponibilidad();
    int getNumero();
    int getIdFactura();
};

class Local : public Mesa
{
private:
    int _horaApertura;
    int _empleadoAsignado;
    int _comensales;
public:
    Local();
    Local(int numeroMesa);
    void cargarLocal();
    void mostrarLocal();
    void abrirMesa();
};

class Delivery : Mesa
{
private:
    // Direccion _dirrecionEntrega;
    char _telefonoCliente[10];
    char _deliveryAsignado[20];
    int _horaEntrega;
public:
    void cargarDelivery();
    void mostrarDelivery();
};

class TakeAway : Mesa
{
private:
    int _horaRetiro;
    char _nombreCliente[50];
public:
    void cargarTakeAway();
    void mostrarTakeAway();
};

class Usuario
{
private:
    char _nombre[50];
    int _id;
    int _dni;
public:
    void cargar();
    void mostrar();
};

class Credencial
{
private:
    int _dni;
    char _password[12];
public:
    void setPassword(char* newPassword[12]);
    char* getPassword();
};

/*
class Recaudacion
{
private:
    Fecha _fecha;
    int _turno;
    int _id;
    float _importeSubTotal;
    float _importeFinal;
    int _tipoMesa;
    int _idEmpleado;
    int _cantComensales;
    int _IDFactura;  /// VINCULAR CON EL VECTOR DE Factura
public:
    /// SETTERS
    void setFecha();
    void setTurno(int turno);
    void setId(int id);
    void setImporteSubTotal(float importe);
    void setImporteFinal(float importe);
    void setTipoMesa(int tipoMesa);
    void setIdEmpleado(int idEmpleado);
    void setCantComensales(int cantidad);
    void setIdFactura(int IDFactura);
    /// GETTERS
    Fecha getFecha();
    int getAnio();
    int getMes();
    int getDia();
    int getTurno();
    int getId();
    float getImporteSubTotal();
    float getImporteFinal();
    int getTipoMesa();
    int getIdEmpleado();
    int getCantComensales();
    int getIdFactura();
    /// METHODS
    void Cargar();
    void Mostrar();
};
*/


