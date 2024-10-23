#ifndef CLASES_H_INCLUDED
#define CLASES_H_INCLUDED

#include <iostream>

using namespace std;

class Mesa
{
    protected:
        int _numero;
        bool _disponible;
        char _tipo[10];
        // Pedido _pedido;
    public:
        void cargarMesa();
        void mostrarMesa();
        void cerrarMesa();
};

class Local : Mesa
{
    private:
        // Hora _horaApertura;
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
        // Hora _horaEntrega;
    public:
        void cargarDelivery();
        void mostrarDelivery();
};

class TakeAway : Mesa
{
    private:
        // Hora _horaRetiro;
        char _nombreCliente[50];
    public:
        void cargarTakeAway();
        void mostrarTakeAway();
};


#endif // CLASES_H_INCLUDED
