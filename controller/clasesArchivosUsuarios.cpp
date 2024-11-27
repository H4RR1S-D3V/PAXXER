#include <iostream>
#include <cstring>

#include "clasesUsuarios.h"
#include "clasesArchivosUsuarios.h"

using namespace std;

/// ARCHIVO USUARIOS

ArchivoUsuario::ArchivoUsuario(const char* nombre)
{
    strcpy(_nombre, nombre);
    _tamanioRegistro=sizeof(Usuario);
}

bool ArchivoUsuario::agregarRegistro(Usuario &obj)
{
    FILE *p;
    p = fopen(_nombre, "ab");
    if(p == nullptr)
    {
        return 0;
    }
    bool escribio = fwrite(&obj, _tamanioRegistro, 1, p);
    fclose(p);
    return escribio;
}

Usuario ArchivoUsuario::leerRegistro(int pos)
{
    Usuario obj;

    FILE *p;
    p = fopen(_nombre, "rb");
    if(p == nullptr)
    {
        obj.setId(-1);
        return obj;
    }
    fseek(p, _tamanioRegistro * pos, 0);
    fread(&obj, _tamanioRegistro, 1, p);
    fclose(p);
    return obj;
}

int ArchivoUsuario::contarRegistros()
{
    FILE *p;
    p = fopen(_nombre, "rb");
    if(p == nullptr)
    {
        return -1;
    }
    fseek(p, 0, 2);
    int tam = ftell(p);
    fclose(p);
    return tam/_tamanioRegistro;
}

bool ArchivoUsuario::listarRegistros()
{
    FILE *p;
    Usuario obj;
    p = fopen(_nombre, "rb");
    if(p == nullptr)
    {
        return false;
    }

    while(fread(&obj, _tamanioRegistro, 1, p)==1)
    {
        obj.Mostrar();
        cout << endl;
    }
    fclose(p);
    return true;
}

int ArchivoUsuario::buscarRegistro(int id)
{
    FILE *p;
    Usuario obj;
    p = fopen(_nombre, "rb");
    if(p == nullptr)
    {
        return -2;
    }
    int cantRegistros = contarRegistros();

    for(int i=0; i<cantRegistros; i++)
    {
        obj = leerRegistro(i);
        if(obj.getId() == id)
        {
            fclose(p);
            return i;
        }
    }
    fclose(p);
    return -1;
}

int ArchivoUsuario::buscarRegistroDNI(char* DNI)
{
    FILE *p;
    Usuario obj;
    p = fopen(_nombre, "rb");
    if(p == nullptr)
    {
        return -2;
    }
    int cantRegistros = contarRegistros();

    for(int i=0; i<cantRegistros; i++)
    {
        obj = leerRegistro(i);
        if(strcmp(obj.getDNI(), DNI))
        {
            fclose(p);
            return i;
        }
    }
    fclose(p);
    return -1;
}

bool ArchivoUsuario::cambiarEstadoRegistro(int id)
{
    int pos = buscarRegistro(id);
    Usuario obj;

    FILE* p = fopen(_nombre, "rb+");
    if(p == nullptr)
    {
        return 0;
    }
    obj = leerRegistro(pos);
    obj.cambiarEstado();

    fseek(p, _tamanioRegistro * pos, 0);
    bool modifico = fwrite(&obj, _tamanioRegistro, 1, p);
    fclose(p);
    return modifico;
}

bool ArchivoUsuario::modificarNombreRegistro(const char *nombre, int id)
{
    FILE *p;
    p = fopen(_nombre, "rb+");
    if(p == nullptr)
    {
        return 0;
    }
    Usuario obj;
    int pos = buscarRegistro(id);

    obj = leerRegistro(pos);
    obj.setNombre(nombre);

    fseek(p, _tamanioRegistro * pos, 0);
    bool modifico = fwrite(&obj, _tamanioRegistro, 1, p);
    fclose(p);
    return modifico;
}

bool ArchivoUsuario::modificarDNIRegistro(const char *DNI, int id)
{
    FILE *p;
    p = fopen(_nombre, "rb+");
    if(p == nullptr)
    {
        return 0;
    }
    Usuario obj;
    int pos = buscarRegistro(id);

    obj = leerRegistro(pos);
    obj.setDNI(DNI);

    fseek(p, _tamanioRegistro * pos, 0);
    bool modifico = fwrite(&obj, _tamanioRegistro, 1, p) == 1;
    fclose(p);
    return modifico;
}

void ArchivoUsuario::listarRegistrosPorNombre(const char *nombre)
{
    FILE *p;
    p = fopen(_nombre, "rb");
    if(p == nullptr)
    {
        return;
    }

    Usuario obj;
    int cantRegistros = contarRegistros();

    for(int i=0; i<cantRegistros; i++)
    {
        fread(&obj, _tamanioRegistro, 1, p);
        if(strstr(obj.getNombre(), nombre))
        {
            cout << "---------------" << endl;
            obj.Mostrar();
        }
    }
}

bool ArchivoUsuario::verificarCredenciales(const char* dni, const char* password){
    FILE *p;
    p = fopen(_nombre, "rb");
    if(p == nullptr)
    {
        return false;
    }

    Usuario obj;
    int cantRegistros = contarRegistros();

    for(int i=0; i<cantRegistros; i++)
    {
        fread(&obj, _tamanioRegistro, 1, p);
        if(strcmp(obj.getDNI(), dni) == 0 && strcmp(obj.getPassword(),password) == 0){
            return true;
        }
    }
    return false;
}

/*
    CAMBIAR ROL
    TRAER POR ROL
*/


/// FIN ARCHIVO USUARIOS
