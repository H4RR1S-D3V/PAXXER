#include <iostream>
#include <cstring>

#include "clases.h"
#include "clasesArchivos.h"

using namespace std;

ArchivoMesas::ArchivoMesas(const char* n)
{
    strcpy(nombre, n);
    tamanioRegistro=sizeof(Mesa);
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

bool ArchivoMesas::actualizarMesa(Mesa mesa)
{

    FILE *p;
        p=fopen(nombre, "rb+");
        if(p==NULL){
            cout<<"NO SE PUDO ABRIR EL ARCHIVO "<<endl;
            return false;
        }
        fseek(p,tamanioRegistro,mesa.getNumero());
        bool escribio=fwrite(&mesa, tamanioRegistro,1, p);
        fclose(p);
        return escribio;
}

/// Archivo Factura


ArchivoFactura::ArchivoFactura(const char* n)
{
    strcpy(nombre, n);
    tamanioRegistro=sizeof(Pedido);
}

int ArchivoFactura::contarRegistros()
{
    FILE *p;
    p=fopen(nombre, "rb");
    if(p==NULL){
        return -1;
    }
    fseek(p, 0, 2);
    int tam=ftell(p);
    fclose(p);
    return tam/sizeof (Pedido);
}

bool ArchivoFactura::listarRegistros()
{
    FILE *p;
        Pedido factura;
        p=fopen(nombre, "rb");
        if(p==NULL){
            cout<<"NO SE PUDO ABRIR EL ARCHIVO "<<endl;
            return false;
        }

        while(fread(&factura,tamanioRegistro,1,p)==1){
            factura.mostrarPedido();
            cout<<endl;
        }

        fclose(p);
        return true;
}


bool ArchivoFactura::actualizarFactura(Pedido factura)
{

    FILE *p;
        p=fopen(nombre, "rb+");
        if(p==NULL){
            cout<<"NO SE PUDO ABRIR EL ARCHIVO "<<endl;
            return false;
        }
        fseek(p,tamanioRegistro, factura.getId());
        bool escribio=fwrite(&factura, tamanioRegistro,1, p);
        fclose(p);
        return escribio;
}

int ArchivoFactura::buscarFactura(int id){
        FILE *p;
        Pedido factura;
        int pos=0;
        p=fopen(nombre, "rb");
        if(p==NULL){
            cout<<"NO SE PUDO ABRIR EL ARCHIVO "<<endl;
            return -2;
        }

           while(fread(&factura,tamanioRegistro,1,p)==1){
                if(factura.getId()==id){
                fclose(p);
                return pos;
                }
            pos++;
            }
        fclose(p);
        return -1;
        }

ArchivoProducto::ArchivoProducto(const char* nombre)
{
    strcpy(_nombre, nombre);
}

void ArchivoProducto::eliminarRegistro(int id)
{
    // AUN NO LISTO
    // ELIMINA TODO EL ARCHIVO
    FILE *p;
    p = fopen("productos.dat", "wb");
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

void ArchivoProducto::listarRegistrosPorTipo(const char *tipo)
{
    FILE *p;
    p = fopen("productos.dat", "rb");
    if(p == nullptr)
    {
        return;
    }
    Producto obj;

    while(fread(&obj, sizeof(Producto), 1, p))
    {
        if(!strcmp(obj.getTipo(), tipo))
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
    p = fopen("productos.dat", "rb");
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

bool ArchivoProducto::modificarTipoRegistro(const char *tipo, int id)
{
    FILE *p;
    p = fopen("productos.dat", "rb+");
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
    p = fopen("productos.dat", "rb+");
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
    FILE *p = fopen("productos.dat", "rb");
    if(p == nullptr)
    {
        return -1;
    }
    fseek(p, 0, 2);
    int tam = ftell(p);
    fclose(p);
    return tam / sizeof(Producto);
}

void ArchivoProducto::listarRegistros()
{
    FILE *p = fopen("productos.dat", "rb");

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

    FILE* p = fopen("productos.dat", "rb+");
    if(p == nullptr)
    {
        return 0;
    }
    obj = leerRegistro(pos);
    obj.Habilitar();

    fseek(p, sizeof(Producto) * pos, 0);
    bool modifico = fwrite(&obj, sizeof(Producto), 1, p);
    fclose(p);
    return modifico;
}

bool ArchivoProducto::deshabilitarRegistro(int id)
{
    int pos = buscarRegistroPorId(id);
    Producto obj;

    FILE* p = fopen("productos.dat", "rb+");
    if(p == nullptr)
    {
        return 0;
    }
    obj = leerRegistro(pos);
    obj.Deshabilitar();

    fseek(p, sizeof(Producto) * pos, 0);
    bool modifico = fwrite(&obj, sizeof(Producto), 1, p);
    fclose(p);
    return modifico;
}

int ArchivoProducto::buscarRegistroPorId(int id)
{
    FILE *p;
    p = fopen("productos.dat", "rb");
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
    p = fopen("productos.dat", "rb+");
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
    p = fopen("productos.dat", "ab");
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
    p = fopen("productos.dat", "rb");
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







