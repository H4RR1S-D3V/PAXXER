#ifndef CLSRECAUDACION_H_INCLUDED
#define CLSRECAUDACION_H_INCLUDED

class Recaudacion
{
    private:
        //Fecha _fecha;
        //Turno _turno;
        int _id;
        float _importeSubTotal;
        float _importeFinal;
        char _tipoMesa[10];
        int _idEmpleado;
        int _cantComensales;
        /*
            AGREGAR ARRAY DE PRODUCTOS?
                Ó
            DEJAR EL ARRAY PARA OTRO ARCHIVO?
        */
    public:
        /// SETTERS
        /*
            void setFecha();
            void setTurno();
        */
        void setId(int id);
        void setImporteSubTotal(float importe);
        void setImporteFinal(float importe);
        void setTipoMesa(const char* servicio);
        void setIdEmpleado(int idEmpleado);
        void setCantComensales(int cantidad);
        /// GETTERS
        /*
            Fecha getFecha();
            Turno getTurno();
        */
        int getId();
        float getImporteSubTotal();
        float getImporteFinal();
        const char* getTipoServicio();
        int getIdVendedor();
        int getCantComensales();
        /// METHODS
        void Cargar();
        void Mostrar();
};

#endif // CLSRECAUDACION_H_INCLUDED
