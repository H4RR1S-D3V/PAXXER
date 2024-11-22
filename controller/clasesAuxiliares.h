#pragma once

#include <ctime>

class Fecha
{
    private:
        int _dia, _mes, _anio;
    public:
        /// SETTERS
        void setDia(int d);
        void setMes(int m);
        void setAnio(int a);
        /// GETTERS
        int getDia();
        int getMes();
        int getAnio();
        /// MATHODS
        void Cargar();
        void Mostrar();
};

class Tiempo
{
    private:
        time_t _now = time(0);
        tm* _local = localtime(&_now);
    public:
        /// GETTERS
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
        /// METHODS
        void Cargar();
        void Mostrar();
};
