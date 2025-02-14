#pragma once

#include <string>

#include "clasesAuxiliares.h"

class Mesa
{
    protected:
        int _numero;
        bool _disponible = true; /// PONERLO SOLO EN MESA SALON
        char _tipo[10];
        int _idFactura;
    public:
        ///SETTERS
        void setNumero(int numero);
        ///GETTERS
        bool getDisponibilidad();
        int getNumero();
        int getIdFactura();
        /// METHODS
        Mesa();
        Mesa(int numero);
        void cargarMesa();
        virtual void abrirMesa();
        void mostrarMesa();
        virtual bool cerrarMesa();
};

class Local : public Mesa
{
    private:
        int _horaApertura[2] = {0,0};
        int _empleadoAsignado;
        int _comensales;
    public:
        ///METHODS
        Local();
        Local(int numeroMesa);
        void cargarLocal();
        void mostrarLocal();
        void abrirMesa();
        void cerrarLocal();
        void liberarMesa();
};

class Delivery : public Mesa
{
    private:
        Domicilio _direccionEntrega;
        char _telefonoCliente[20];
        int _deliveryAsignado;
        int _horaEntrega;   // PASAR A HH:MM
        bool _entregado;
    public:
        /// SETTERS
        void setNumero(int num);
        /// GETTERS
        int getNumero();
        /// METHODS
        Delivery();
        Delivery(int num);
        void abrirMesa();
        bool cerrarDelivery();
        void cargarDelivery();
        void mostrarDelivery(int y);
        void mostrarDeliveryDetalle();
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
        bool cerrarTakeAway();
        void cargarTakeAway();
        void mostrarTakeAway(int y);
        void mostrarTakeAwayDetalle();
        void entregarTakeAway();
        void disminuirNumero();
};
