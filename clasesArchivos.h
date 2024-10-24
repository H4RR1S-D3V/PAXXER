#ifndef CLASESARCHIVOS_H_INCLUDED
#define CLASESARCHIVOS_H_INCLUDED

#include "clases.h"

class ArchivoMesas
{
    private:
        int numero; // ?
        char nombre[30];
    public:
        ArchivoMesas(const char* n="mesas.dat");
        Mesa leerRegistro(int pos);
        int setearCantMesas(int cant);
        int contarRegistros();
};

#endif // CLASESARCHIVOS_H_INCLUDED


/*
class ArchivoCanciones{
    private:
        char nombre[30];
    public:
        ArchivoCanciones(const char *n="canciones.dat");
        Cancion leerRegistro(int);
        int contarRegistros();
        int buscarRegistro(int);
        bool grabarRegistro(Cancion);
        bool modificarRegistro(Cancion, int);
        void listarRegistros();
        void vaciar();
};
*/
