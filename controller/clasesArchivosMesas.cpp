#include <iostream>
#include <cstring>

#include "clasesMesas.h"
#include "clasesArchivosMesas.h"

/// ARCHIVO MESAS LOCAL

ArchivoMesasLocal::ArchivoMesasLocal(const char* n)
{
    strcpy(_nombre, n);
    _tamanioRegistro=sizeof(Local);
}

int ArchivoMesasLocal::contarRegistros()
{
    FILE *p;
    p=fopen(_nombre, "rb");
    if(p==nullptr)
    {
        return 0;
    }
    fseek(p, 0, 2);
    int tam=ftell(p);
    fclose(p);
    return tam/sizeof (Local);
}

bool ArchivoMesasLocal::listarRegistros()
{
    FILE *p;
    p=fopen(_nombre, "rb");
    if(p==nullptr)
    {
        return false;
    }
    Local obj;
    int cantRegistros = contarRegistros();

    for(int i=0; i<cantRegistros; i++)
    {
        obj = leerRegistro(i);
        obj.mostrarLocal();
    }
    fclose(p);
    return true;
}

Local ArchivoMesasLocal::leerRegistro(int pos)
{
    FILE *p;
    Local obj(pos);
    p=fopen(_nombre, "rb");
    if(p==nullptr)
    {
        obj.setNumero(-2);
        return obj;
    }
    obj.setNumero(pos+1);
    fseek(p, sizeof obj * pos, 0);
    fread(&obj, sizeof obj, 1, p);
    fclose(p);
    return obj;
}

bool ArchivoMesasLocal::verificarDisponibilidadGlobal(){
//REVISA QUE TODAS LAS MESAS ESTEN DISPONIBLES PARA PODER SETEARLAS SIN PERDER DATOS
    FILE *p;
    p=fopen(_nombre, "rb");
    if(p==nullptr)
    {
        return true;
    }
    Local obj;
    int cantRegistros = contarRegistros();
    if (cantRegistros < 1){
        fclose(p);
        return true;
    } else {
        for(int i=0; i<cantRegistros; i++)
        {
            obj = leerRegistro(i);
            if (obj.getDisponibilidad() == false){
            fclose(p);
             return false;
            }

        }
    }
    fclose(p);
    return true;
}

int ArchivoMesasLocal::setearCantMesas(int cant)
{
    FILE *p;
    if (cant < 1) {
        return -2;
    }
    if (verificarDisponibilidadGlobal() == true){
    p=fopen(_nombre, "wb");
    if(p==nullptr)
    {
        return -1;
    }
        for(int i=0; i<cant; i++)
        {
            Local obj(i+1);
            fwrite(&obj, sizeof obj, 1, p);
        }
    } else {
        fclose(p);
        return 0;
    }

    fclose(p);
    cant = contarRegistros();
    return cant;
}




bool ArchivoMesasLocal::actualizarMesa(Local mesa)
{
    FILE *p;
    p=fopen(_nombre, "rb+");
    if(p==nullptr)
    {
        return false;
    }
    fseek(p, _tamanioRegistro * (mesa.getNumero()-1), 0);
    bool escribio = fwrite(&mesa, _tamanioRegistro, 1, p) == 1;
    fclose(p);
    return escribio;
}


/// FIN ARCHIVO MESAS LOCAL

/// ARCHIVO DELIVERY

ArchivoDelivery::ArchivoDelivery(const char* n)
{
    strcpy(_nombre, n);
    _tamanioRegistro = sizeof(Delivery);
}

bool ArchivoDelivery::agregarRegistro(Delivery &obj)
{
    FILE *p;
    p = fopen(_nombre, "ab");
    if(p == nullptr)
    {
        return 0;
    }
    bool escribio = fwrite(&obj, _tamanioRegistro, 1, p) == 1;
    fclose(p);
    return escribio;
}

bool ArchivoDelivery::listarRegistros(int y)
{
    FILE *p;
    p = fopen(_nombre, "rb");
    if(p == nullptr)
    {
        return false;
    }
    Delivery obj;
    int cantRegistros = contarRegistros();

    for(int i=0; i<cantRegistros; i++)
    {
        obj = leerRegistro(i);
        obj.mostrarDelivery(y+i);
    }
    fclose(p);
    return true;
}

Delivery ArchivoDelivery::leerRegistro(int pos)
{
    FILE *p;
    Delivery obj;
    p = fopen(_nombre, "rb");
    if(p == nullptr)
    {
        obj.setNumero(-2);
        return obj;
    }
    obj.setNumero(pos+1); //
    fseek(p, _tamanioRegistro * pos, 0);
    fread(&obj, sizeof obj, 1, p);
    fclose(p);
    return obj;
}

int ArchivoDelivery::contarRegistros()
{
    FILE *p;
    p = fopen(_nombre, "rb");
    if(p == nullptr)
    {
        return 0;
    }
    fseek(p, 0, 2);
    int tam = ftell(p);
    fclose(p);
    return tam/sizeof(Delivery);
}

int ArchivoDelivery::eliminarRegistro(int pos)
{
    /// LEER EL ARCHIVO PARA GUARDAR LOS REGISTROS EN UN ARRAY
    FILE *p;
    p = fopen(_nombre, "rb");
    if(p == nullptr)
    {
        return -1;
    }
    int cantRegistros = contarRegistros();

    if(pos > cantRegistros)
    {
        return -2;
    }

    Delivery *vBackUpRegistros = new Delivery[cantRegistros];

    for(int i=0; i<cantRegistros; i++)
    {
        vBackUpRegistros[i] = leerRegistro(i);
    }
    fclose(p);

    /// ENCONTRAR EL REGISTRO A ALIMINAR Y OBVIARLO

    p = fopen(_nombre, "wb");
    if(p == nullptr)
    {
        return -3;
    }

    // REGISTROS ANTES DEL ELIMINADO (NO CAMBIAN)
    int j = 0;
    while(j < pos-1)
    {
        agregarRegistro(vBackUpRegistros[j]);
        j++;
    }
    // SE SALTEA EL REGISTRO A ELIMINAR

    // SE LES DISMINUYE EN UN EL NUMERO A LOS REGISTROS SIGUIENTES Y SE GUARDAN
    for(int k=j+1; k<cantRegistros; k++)
    {
        vBackUpRegistros[k].disminuirNumero();
        agregarRegistro(vBackUpRegistros[k]);
    }

    delete vBackUpRegistros;
    fclose(p);
    return 1;
}

/// FIN ARCHIVO DELIVERY

/// ARCHIVO TAKEAWAY

ArchivoTakeAway::ArchivoTakeAway(const char* n)
{
    strcpy(_nombre, n);
    _tamanioRegistro = sizeof(TakeAway);
}

bool ArchivoTakeAway::agregarRegistro(TakeAway &obj)
{
    FILE *p;
    p = fopen(_nombre, "ab");
    if(p == nullptr)
    {
        return 0;
    }
    bool escribio = fwrite(&obj, sizeof(TakeAway), 1, p) == 1;
    fclose(p);
    return escribio;
}

bool ArchivoTakeAway::listarRegistros(int y)
{
    FILE *p;
    p = fopen(_nombre, "rb");
    if(p == nullptr)
    {
        return false;
    }
    TakeAway obj;
    int cantRegistros = contarRegistros();

    for(int i=0; i<cantRegistros; i++)
    {
        obj = leerRegistro(i);
        obj.mostrarTakeAway(y+i);
    }
    fclose(p);
    return true;
}

TakeAway ArchivoTakeAway::leerRegistro(int pos)
{
    FILE *p;
    TakeAway obj;
    p = fopen(_nombre, "rb");
    if(p == nullptr)
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

bool ArchivoTakeAway::actualizarRegstro(TakeAway obj)
{
    FILE *p;
    p = fopen(_nombre, "rb+");
    if(p == nullptr)
    {
        return false;
    }
    fseek(p, _tamanioRegistro * (obj.getNumero()-1), 0);
    bool escribio = fwrite(&obj, _tamanioRegistro, 1, p) == 1;
    fclose(p);
    return escribio;
}

int ArchivoTakeAway::contarRegistros()
{
    FILE *p;
    p = fopen(_nombre, "rb");
    if(p == nullptr)
    {
        return 0;
    }
    fseek(p, 0, 2);
    int tam = ftell(p);
    fclose(p);
    return tam/sizeof(TakeAway);
}

int ArchivoTakeAway::eliminarRegistro(int pos)
{
    /// LEER EL ARCHIVO PARA GUARDAR LOS REGISTROS EN UN ARRAY
    FILE *p;
    p = fopen(_nombre, "rb");
    if(p == nullptr)
    {
        return -1;
    }
    int cantRegistros = contarRegistros();

    if(pos > cantRegistros)
    {
        return -2;
    }

    TakeAway *vBackUpRegistros = new TakeAway[cantRegistros];

    for(int i=0; i<cantRegistros; i++)
    {
        vBackUpRegistros[i] = leerRegistro(i);
    }
    fclose(p);

    /// ENCONTRAR EL REGISTRO A ALIMINAR Y OBVIARLO

    p = fopen(_nombre, "wb");
    if(p == nullptr)
    {
        return -3;
    }

    // REGISTROS ANTES DEL ELIMINADO (NO CAMBIAN)
    int j = 0;
    while(j < pos-1)
    {
        agregarRegistro(vBackUpRegistros[j]);
        j++;
    }
    // SE SALTEA EL REGISTRO A ELIMINAR

    // SE LES DISMINUYE EN UN EL NUMERO A LOS REGISTROS SIGUIENTES Y SE GUARDAN
    for(int k=j+1; k<cantRegistros; k++)
    {
        vBackUpRegistros[k].disminuirNumero();
        agregarRegistro(vBackUpRegistros[k]);
    }

    delete vBackUpRegistros;
    fclose(p);
    return 1;
}

/// FIN ARCHIVO TakeAway
