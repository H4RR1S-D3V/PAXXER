#include <iostream>
#include <cstring>

#include "clases.h"
#include "clasesArchivos.h"

using namespace std;

/// ARCHIVO MESAS LOCAL

ArchivoMesasLocal::ArchivoMesasLocal(const char* n)
{
    strcpy(_nombre, n);
    _tamanioRegistro=sizeof(Mesa);
}

int ArchivoMesasLocal::contarRegistros()
{
    FILE *p;
    p=fopen(_nombre, "rb");
    if(p==nullptr)
    {
        return -1;
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
    if(p==NULL)
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
    obj.setNumero(pos+1); // ?
    fseek(p, sizeof obj * pos, 0);
    fread(&obj, sizeof obj, 1, p);
    fclose(p);
    return obj;
}

int ArchivoMesasLocal::setearCantMesas(int cant)
{
    FILE *p;
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

/// ARCHIVO FACTURA

ArchivoFactura::ArchivoFactura(const char* n)
{
    strcpy(_nombre, n);
    _tamanioRegistro=sizeof(Factura); /// MUY BUENOOOOOO
}

/// PARA TRAER EL Factura DESDE EL ARCHIVO A LA MESA
Factura ArchivoFactura::leerRegistro(int pos)
{
    Factura obj;

    FILE *p;
    p = fopen(ARCHIVO_FACTURAS, "rb");
    if(p == nullptr)
    {
        obj.setId(-1);
        return obj;
    }
    fseek(p, sizeof(Factura) * pos, 0);
    fread(&obj, sizeof(Factura), 1, p);
    fclose(p);
    return obj;
}

bool ArchivoFactura::agregarRegistro(Factura &obj)
{
    FILE *p;
    p = fopen(ARCHIVO_FACTURAS, "ab");
    if(p == nullptr)
    {
        return 0;
    }
    bool writed = fwrite(&obj, sizeof(Factura), 1, p);
    fclose(p);
    return writed;
}

int ArchivoFactura::contarRegistros()
{
    FILE *p;
    p=fopen(_nombre, "rb");
    if(p==NULL)
    {
        return -1;
    }
    fseek(p, 0, 2);
    int tam=ftell(p);
    fclose(p);
    return tam/sizeof (Factura);
}

bool ArchivoFactura::listarRegistros()
{
    FILE *p;
    Factura factura;
    p=fopen(_nombre, "rb");
    if(p==NULL)
    {
        cout<<"NO SE PUDO ABRIR EL ARCHIVO "<<endl;
        return false;
    }

    while(fread(&factura, _tamanioRegistro, 1, p)==1)
    {
        factura.mostrarFactura();
        cout<<endl;
    }

    fclose(p);
    return true;
}

int ArchivoFactura::buscarRegistro(int id)
{
    FILE *p;
    Factura factura;
    int pos=0;
    p=fopen(_nombre, "rb");
    if(p==NULL)
    {
        cout<<"NO SE PUDO ABRIR EL ARCHIVO "<<endl;

        return -2;
    }

    while(fread(&factura, _tamanioRegistro, 1, p)==1)
    {
        if(factura.getId()==id)
        {
            fclose(p);
            return pos;
        }
        pos++;
    }
    fclose(p);
    return -1;
}

bool ArchivoFactura::actualizarRegistro(Factura* factura, int id)
{

    FILE *p;
    p=fopen(_nombre, "rb+");
    if(p==NULL)
    {
        cout<<"NO SE PUDO ABRIR EL ARCHIVO"<<endl;
        return false;
    }
    fseek(p, _tamanioRegistro, buscarRegistro(id));
    bool escribio=fwrite(factura, _tamanioRegistro,1, p);
    fclose(p);
    return escribio;
}



/// ARCHIVO PRODUCTO

ArchivoProducto::ArchivoProducto(const char* nombre)
{
    strcpy(_nombre, nombre);
}

void ArchivoProducto::eliminarRegistro(int id)
{
    // AUN NO LISTO
    // ELIMINA TODO EL ARCHIVO
    FILE *p;
    p = fopen(ARCHIVO_PRODUCTOS, "wb");
    if(p == nullptr)
    {
        return;
    }
    Producto obj;

    int cant = contarRegistros();

    for(int i = 0; i < cant; i++)
    {
        obj = leerRegistro(i);
        if(obj.getId() != id)
        {
            fseek(p, sizeof(Producto) * i, 0);
            fwrite(&obj, sizeof(Producto), 1, p);
        }
    }
    fclose(p);
}

void ArchivoProducto::listarRegistrosPorTipo(const int tipo)
{
    FILE *p;
    p = fopen(ARCHIVO_PRODUCTOS, "rb");
    if(p == nullptr)
    {
        return;
    }
    Producto obj;

    while(fread(&obj, sizeof(Producto), 1, p))
    {
        if(obj.getTipo() == tipo)
        {
            cout << "---------------" << endl;
            obj.Mostrar();
        }
    }
}

void ArchivoProducto::listarRegistrosPorNombre(const char *nombre)
{
    // PROBAR IMPLEMENTAR GETCHAR() O GETCH() PARA ACTUALIZAR EN TIEMPO REAL
    FILE *p;
    p = fopen(ARCHIVO_PRODUCTOS, "rb");
    if(p == nullptr)
    {
        return;
    }
    Producto obj;

    while(fread(&obj, sizeof(Producto), 1, p))
    {
        if(strstr(obj.getNombre(), nombre))
        {
            cout << "---------------" << endl;
            obj.Mostrar();
        }
    }
}

bool ArchivoProducto::modificarTipoRegistro(const int tipo, int id)
{
    FILE *p;
    p = fopen(ARCHIVO_PRODUCTOS, "rb+");
    if(p == nullptr)
    {
        return 0;
    }
    Producto obj;
    int pos = buscarRegistroPorId(id);

    obj = leerRegistro(pos);
    obj.setTipo(tipo);

    fseek(p, sizeof(Producto) * pos, 0);
    bool modifico = fwrite(&obj, sizeof(Producto), 1, p);
    fclose(p);
    return modifico;
}

bool ArchivoProducto::modificarNombreRegistro(const char *nombre, int id)
{
    FILE *p;
    p = fopen(ARCHIVO_PRODUCTOS, "rb+");
    if(p == nullptr)
    {
        return 0;
    }
    Producto obj;
    int pos = buscarRegistroPorId(id);

    obj = leerRegistro(pos);
    obj.setNombre(nombre);

    fseek(p, sizeof(Producto) * pos, 0);
    bool modifico = fwrite(&obj, sizeof(Producto), 1, p);
    fclose(p);
    return modifico;
}

int ArchivoProducto::contarRegistros()
{
    FILE *p = fopen(ARCHIVO_PRODUCTOS, "rb");
    if(p == nullptr)
    {
        return -1;
    }
    fseek(p, 0, 2);
    int tam = ftell(p);
    fclose(p);
    return tam / sizeof(Producto);
}

bool ArchivoProducto::listarRegistros()
{
    FILE *p = fopen(ARCHIVO_PRODUCTOS, "rb");

    if(p==nullptr)
    {
        cout << "NO SE PUDO ABRIR EL ARCHIVO" << endl;
        return false;
    }

    Producto obj;
    int cant = contarRegistros();

    for(int i = 0; i < cant; i++)
    {
        obj = leerRegistro(i);
        if(obj.getDisponibilidad())
        {
            cout << "---------------" << endl;
            obj.Mostrar();
        }
    }
}

bool ArchivoProducto::habilitarRegistro(int id)
{
    int pos = buscarRegistroPorId(id);
    Producto obj;

    FILE* p = fopen(ARCHIVO_PRODUCTOS, "rb+");
    if(p == nullptr)
    {
        return 0;
    }
    obj = leerRegistro(pos);
    obj.cambiarEstado();

    fseek(p, sizeof(Producto) * pos, 0);
    bool modifico = fwrite(&obj, sizeof(Producto), 1, p);
    fclose(p);
    return modifico;
}

bool ArchivoProducto::deshabilitarRegistro(int id)
{
    int pos = buscarRegistroPorId(id);
    Producto obj;

    FILE* p = fopen(ARCHIVO_PRODUCTOS, "rb+");
    if(p == nullptr)
    {
        return 0;
    }
    obj = leerRegistro(pos);
    obj.cambiarEstado();

    fseek(p, sizeof(Producto) * pos, 0);
    bool modifico = fwrite(&obj, sizeof(Producto), 1, p);
    fclose(p);
    return modifico;
}

int ArchivoProducto::buscarRegistroPorId(int id)
{
    FILE *p;
    p = fopen(ARCHIVO_PRODUCTOS, "rb");
    if(p == nullptr)
    {
        return -1;
    }
    Producto obj;
    int pos = 0;

    while(fread(&obj, sizeof(Producto), 1, p))
    {
        if(obj.getId() == id)
        {
            return pos;
        }
        pos++;
    }
    return -2;
}

bool ArchivoProducto::modificarPrecioRegistro(float precio, int id)
{
    FILE *p;
    p = fopen(ARCHIVO_PRODUCTOS, "rb+");
    if(p == nullptr)
    {
        return 0;
    }
    Producto obj;
    int pos = buscarRegistroPorId(id);

    obj = leerRegistro(pos);
    obj.setPrecio(precio);

    fseek(p, sizeof(Producto) * pos, 0);
    bool modifico = fwrite(&obj, sizeof(Producto), 1, p);
    fclose(p);
    return modifico;
}

bool ArchivoProducto::agregarRegistro(Producto &obj)
{
    FILE *p;
    p = fopen(ARCHIVO_PRODUCTOS, "ab");
    if(p == nullptr)
    {
        return 0;
    }
    bool writed = fwrite(&obj, sizeof(Producto), 1, p);
    fclose(p);
    return writed;
}

Producto ArchivoProducto::leerRegistro(int pos)
{
    Producto obj;

    FILE *p;
    p = fopen(ARCHIVO_PRODUCTOS, "rb");
    if(p == nullptr)
    {
        obj.setId(-1);
        return obj;
    }
    fseek(p, sizeof(Producto) * pos, 0);
    fread(&obj, sizeof(Producto), 1, p);
    fclose(p);
    return obj;
}
