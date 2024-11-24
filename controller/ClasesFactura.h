#pragma once

#include <string>

#include "clasesAuxiliares.h"
#include "funciones.h"

class Producto
{
    private:
        int _id;
        char _nombre[50];
        float _precio;
        bool _disponible = true;
        int _tipo; /// 1-ENTRADA | 2-PLATO PRINCIPAL | 3-POSTRE | 4-BEBIDA
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

class controladorProductos
{
    private:
        int _vIdsProductos[30]{0};
        int _vCantPorProductos[30]{0};
        int _vPreciosProductos[30]{0};
    public:
        ///METHODS
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
        int _turno; /// 1-MANIANA / 2-TARDE / 3-NOCHE
        int _tipo; /// 1-LOCAL / 2-DELIVERY / 3-TAKEAWAY
        float _importeSubTotal = 0;
        float _importeTotal = 0;
        int _tipoYDescuentoAplicado[2]; // INNUTIL?
        int _idEmpleado = -1;
    public:
        ///SETTERS
        void setId(int id);
        void setTipo(const int tipo);
        void setIdEmpleado(int idEmpleado);
        void setTurno(std::string horaString);
        void setImporteTotal(float monto);
        void setImporteSubTotal(float monto);
        ///GETTERS
        controladorProductos getProductos();
        float getImporteTotal();
        float getImporteSubTotal();
        int getTipo();
        int getTurno();
        int getId();
        Fecha getFecha();
        int getIdEmpleado();
        ///METHODS
        Factura();
        Factura(int id);
        Factura& operator=(const Factura& otro);
        void actualizarImporteTotal();
        void cargarItem(int IdProducto);
        bool quitarItem(int pos, int cant);
        void mostrarFactura(int i);
        void mostrarFacturaDetalle();
        void aplicarDescuento(int tipo, float descuento);
};
