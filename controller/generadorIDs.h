#pragma once

int generarId(int tipo);

class ArchivoId{
    private:
        char nombre[30];
    public:
        /// EN EL CONSTRUCTOR, LE PASAMOS CUAL ARCHIVO QUEREMOS USAR
        /// "id_empleados.txt" - "id_productos.txt" - "id_facturas.txt" -
        ArchivoId(const char *n);

        int leerRegistro(int pos);

        bool grabarRegistro(int nuevaId);
};
