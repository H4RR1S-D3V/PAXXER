#pragma once

#include <iostream>
#include <cstring>
#include <ctime>
using namespace std;


#include "generadorIDs.h"


/// CLASES AUXILIARES

class Fecha{
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
        int _tipo; /// 1-ENTRADA | 2-PLATO PRINCIPAL | 3-POSTRE | 4-BEBIDA
        float _precio;
        bool _estado = true; /// ACTIVO O NO
    public:
        void cargarItem();
        void mostrarItem();
        void setEstado(bool valor);
        void setPrecio(float nuevoPrecio);
        void setNombre (const char* nuevoNombre);
        float getPrecio();
        char* getNombre();
};

class Pedido
{
    private:
        int _id;
        Producto _productos[1];
        Fecha _fecha;
        int _turno; /// 1-MAÑANA / 2-TARDE / 3-NOCHE
        int _tipo; /// 1-LOCAL / 2-DELIVERY / 3-TAKEAWAY
        float _importeTotal;
    public:
        Pedido(int hora, int tipo);
        void cargarItem();
        void quitarItem();
        void mostrarPedido();
        /// generar id automaticamente
        float getImporteTotal();
        void cerrarPedido();
        char getTipo();
        void aplicarDescuento(int tipo, float descuento);
};

class Mesa
{
    protected:
        int _numero;
        bool _disponible;
        char _tipo[10];
        int _IDpedido; // VINCULA EL ID DE LA FACTURA
    public:
        Mesa();
        Mesa(int numero);
        void cargarMesa();
        void mostrarMesa();
        void cerrarMesa();
        void setNumero(int numero);
};

class Local : Mesa
{
    private:
        int _horaApertura;
        int _empleadoAsignado;
        int _comensales;
    public:
        void cargarLocal();
        void mostrarLocal();
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
        char _password[12];
    public:
        void setPassword(char* newPassword[12]);
        char* getPassword();
};


