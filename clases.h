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
class PedidoAux     /// ¿?
{
private:
    vector <int> _vIDProductos;
    vector <int> _vCantProductos;
    vector <float> _vPrecioProductos;
*/

};

class controladorProductos{
private:
    const int tamanio = 30; /// CONSTANTE DE TAMAÑO E ITERACION
    vector<int> _vIdsProductos(tamanio, 0);
    vector<int> _vCantPorProductos(tamanio, 0);
    vector<float> _vPreciosProductos(tamanio, 0);

public:
    void ordenarVectores();
    float calcularPrecioTotal();
    void cargarProducto(int idProducto);
    void quitarProducto(int pos, int cant);
    void mostrarProductos();
};

class Pedido
{
private:
    int _id;
    /// PRIMER CAMBIO (SE REMPLAZA EL VECTOR DE PEDIDOS POR 3 ARRAYS)
    int _vIdsProductos[30];
    int _vCantPorProductos[30];
    float _vPreciosProductos[30];
    Fecha _fecha;
    int _turno; /// 1-MAÑANA / 2-TARDE / 3-NOCHE
    int _tipo; /// 1-LOCAL / 2-DELIVERY / 3-TAKEAWAY
    float _importeSubTotal;
    float _importeTotal;
    int _tipoYDescuentoAplicado[2];
    int _idEmpleado = NULL;
public:
    Pedido();
    Pedido(int hora, int tipo);
    void actualizarImporteTotal();
    void cargarItem(int IdItem);
    void quitarItem(int pos, int cant);
    void mostrarPedido();
    float getImporteTotal();
    void cerrarPedido();
    char getTipo();
    int getId();
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
    int getNumero();
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
    int _IDpedido;  /// VINCULAR CON EL VECTOR DE PEDIDO
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
    void setIdPedido(int IDpedido);
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
    int getIdPedido();
    /// METHODS
    void Cargar();
    void Mostrar();
};
*/


