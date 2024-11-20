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
    int getMinutos();
    Fecha getFecha();

};

class Domicilio
{
    private:
        char _localidad[20];
        char _calle[20];
        int _altura;
    public:
        /// SETTERS
        /// GETTERS
        /// METHODS
        void Cargar();
        void Mostrar();

};

/// FIN CLASES AUXILIARES

#include "funciones.h"

class Producto
{

    private:
        int _id;
        char _nombre[50];
        float _precio;
        bool _disponible = true;
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
        void Mostrar(int posX, int posY);

};

class controladorProductos{
private:
    const int _tamanio = 30; /// CONSTANTE DE TAMAÑO E ITERACION
    int _vIdsProductos[30]{0};
    int _vCantPorProductos[30]{0};
    int _vPreciosProductos[30]{0};

public:
    controladorProductos& operator=(const controladorProductos& otro);
    void ordenarVectores();
    float calcularPrecioTotal();
    void cargarProducto(int idProducto);
    bool quitarProducto(int id, int cant);
    void mostrarProductos();
};

class Factura
{
private:
    int _id;
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
    bool quitarItem(int pos, int cant);
    void mostrarFactura(int i);
    void mostrarFacturaDetalle();
    void aplicarDescuento(int tipo, float descuento);
    ///setters
    void setId(int id);
    void setTipo(const int tipo);
    void setIdEmpleado(int idEmpleado);
    void setTurno(string horaString);
    void setImporteTotal(float monto);
    void setImporteSubTotal(float monto);

    ///getters
    controladorProductos getProductos();
    float getImporteTotal();
    float getImporteSubTotal();
    char getTipo();
    int getId();
};

class Mesa
{
protected:
    int _numero;
    bool _disponible = true; /// PONERLO SOLO EN MESA SALON
    char _tipo[10];
    int _idFactura;
public:
    Mesa();
    Mesa(int numero);
    void cargarMesa();
    virtual void abrirMesa();
    void mostrarMesa();
    void setNumero(int numero);
    virtual void cerrarMesa();
    bool getDisponibilidad();
    int getNumero();
    int getIdFactura();
};

class Local : public Mesa
{
private:
    string _horaApertura;
    int _empleadoAsignado;
    int _comensales;
public:
    Local();
    Local(int numeroMesa);
    void cargarLocal();
    void mostrarLocal();
    void abrirMesa();
    void cerrarMesa();
    void liberarMesa();
};

class Delivery : public Mesa
{
private:
    Domicilio _direccionEntrega; /// CREAR CLASE DIRECCION
    char _telefonoCliente[20];
    int _deliveryAsignado;
    int _horaEntrega;   // PASAR A HH:MM
    bool _entregado;
    // �AGREGAR NOMBRE CLIENTE?

public:
    /// SETTERS
    void setNumero(int num);
    /// GETTERS
    int getNumero();
    /// METHODS
    Delivery();
    Delivery(int num);
    void abrirMesa();
    void cerrarMesa();
    void cargarDelivery();
    void mostrarDelivery();
    void entregarDelivery();
    void disminuirNumero();
};

class TakeAway : public Mesa
{
private:
    int _horaRetiro;
    char _nombreCliente[50];
    char _telefonoCliente[20];
    bool _entregado;
public:
    /// SETTERS
    void setNumero(int num);
    /// GETTERS
    int getNumero();
    /// METHODS
    TakeAway();
    TakeAway(int num);
    void abrirMesa();
    void cerrarMesa();
    void cargarTakeAway();
    void mostrarTakeAway();
    void entregarTakeAway();
    void disminuirNumero();
};

class Usuario
{
private:
    char _nombre[50];
    int _id;
    char _dni[10];
    bool _estado;
    int _rol; /// 1- usuario 2-administrador
public:
    Usuario();
    Usuario(char* nombre, char* dni);
    /// SETTERS
    void setId(int id);
    void setRol(int rol);
    void setNombre(const char* nombre);
    void setDNI(const char *DNI);
    /// GETTERS
    int getId();
    char* getDNI();
    int getRol();
    bool getEstado();
    const char* getNombre();
    /// METHODS
    void Cargar();
    void Mostrar();
    void cambiarEstado();
};

class Credencial
{
private:
    char _dni[10];
    char _password[12];
    public:
        /// SETTERS
        void setPassword(const char* newPassword[12]);
        /// GETTERS
        const char* getPassword();
};


