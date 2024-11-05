#include <iostream>
#include <cstring>

#include "clases.h"
#include "clasesArchivos.h"

using namespace std;

ArchivoMesas::ArchivoMesas(const char* n)
{
    strcpy(nombre, n);
}

int ArchivoMesas::contarRegistros()
{
    FILE *p;
    p=fopen(nombre, "rb");
    if(p==NULL){
        return -1;
    }
    fseek(p, 0, 2);
    int tam=ftell(p);
    fclose(p);
    return tam/sizeof (Mesa);
}

Mesa ArchivoMesas::leerRegistro(int pos)
{
    FILE *p;
    Mesa obj(pos);
    p=fopen(nombre, "rb");
    if(p=nullptr)
    {
        obj.setNumero(-2);
        return obj;
    }
    obj.setNumero(pos+1); // ?
    fseek(p, sizeof obj * pos, 0);
    fread(&obj, sizeof obj, 1, p);
    fclose(p);
    return obj;
}

int ArchivoMesas::setearCantMesas(int cant)
{
    /*
        ABRE EL ARCHIVO
        CREA UNA CANTIDAD DE REGISTROS IGUAL A LA CANTIDAD PASADA
        LES SETEA A TODOS UN NUMERO AUTO INCREMETNAL
    */
    FILE *p;
    p=fopen(nombre, "ab");
    if(p=nullptr)
    {
        return -1;  // ERROR AL VINCULAR CON EL ARCHIVO
    }
    for(int i=0; i<cant; i++)
    {
        Mesa obj(i+1);
        cout << (fwrite(&obj, sizeof obj, 1, p)) << endl;
    }
    fclose(p);
    cant = contarRegistros();
    return cant;
}






