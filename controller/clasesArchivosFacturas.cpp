#include <iostream>
#include <cstring>

#include "clasesArchivosFacturas.h"

/// ARCHIVO FACTURA

ArchivoFactura::ArchivoFactura(const char* n)
{
    strcpy(_nombre, n);
    _tamanioRegistro=sizeof(Factura);
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
        return 0;
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
        return false;
    }

    for(int i=0; i<contarRegistros(); i++)
    {
        fread(&factura, _tamanioRegistro, 1, p);
        factura.mostrarFactura(i);
    }
    fclose(p);
    return true;
}
int ArchivoFactura::buscarRegistro(int id)
{
    FILE *p;
    Factura factura;
    int pos = 0;
    p = fopen(_nombre, "rb");
    if(p == nullptr)
    {
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
bool ArchivoFactura::actualizarRegistro(Factura factura)
{
    ArchivoFactura arc;
    int pos = arc.buscarRegistro(factura.getId());

    FILE *p;
    p = fopen(_nombre, "rb+");
    if(p == nullptr)
    {
        return false;
    }
    fseek(p, _tamanioRegistro * pos, 0);
    bool escribio=fwrite(&factura, _tamanioRegistro,1, p);
    fclose(p);
    return escribio;
}
/// PROBAR DE PASAR LOS FILTRADOS A UNA SOLA FUNCION
int ArchivoFactura::listarRegistrosPorResponsableID(int idEmpleado)
{
    FILE *p = fopen(_nombre, "rb");
    if(p == nullptr)
    {
        std::cout << "ERROR AL ABRIR EL ARCHIVO" << std::endl;
        return -1;
    }
    Factura obj;
    int cantRegistros = contarRegistros();
    int j = 0;
    for(int i=0; i<cantRegistros; i++)
    {
        obj = leerRegistro(i);
        if(obj.getIdEmpleado() == idEmpleado)
        {
            j++;
            obj.mostrarFactura(7+j);
        }
    }
    fclose(p);
    return j;
}
int ArchivoFactura::listarRegistrosPorTipo(int tipoServicio)
{
    FILE *p = fopen(_nombre, "rb");
    if(p == nullptr)
    {
        std::cout << "ERROR AL ABRIR EL ARCHIVO" << std::endl;
        return 0;
    }
    Factura obj;
    int cantRegistros = contarRegistros();
    int j = 0;
    for(int i=0; i<cantRegistros; i++)
    {
        obj = leerRegistro(i);
        if(obj.getTipo() == tipoServicio)
        {
            j++;
            obj.mostrarFactura(7+j);
        }
    }
    fclose(p);
    return j;
}
int ArchivoFactura::listarRegistrosPorTurno(int turno)
{
    FILE *p = fopen(_nombre, "rb");
    if(p == nullptr)
    {
        std::cout << "ERROR AL ABRIR EL ARCHIVO" << std::endl;
        return -1;
    }
    Factura obj;
    int cantRegistros = contarRegistros();
    int j=0;
    for(int i=0; i<cantRegistros; i++)
    {
        obj = leerRegistro(i);
        if(obj.getTurno() == turno)
        {
            j++;
            obj.mostrarFactura(7+j);
        }
    }
    fclose(p);
    return j;
}
int ArchivoFactura::listarRegistrosPorAnio(int anio)
{
    FILE *p = fopen(_nombre, "rb");
    if(p == nullptr)
    {
        std::cout << "ERROR AL ABRIR EL ARCHIVO" << std::endl;
        return 0;
    }
    Factura obj;
    int cantRegistros = contarRegistros();
    int j = 0;
    for(int i=0; i<cantRegistros; i++)
    {
        obj = leerRegistro(i);
        if(obj.getFecha().getAnio() == anio)
        {
            j++;
            obj.mostrarFactura(7+j);
        }
    }
    fclose(p);
    return j;
}
int ArchivoFactura::listarRegistrosPorMes(int mes)
{
    FILE *p = fopen(_nombre, "rb");
    if(p == nullptr)
    {
        std::cout << "ERROR AL ABRIR EL ARCHIVO" << std::endl;
        return 0;
    }
    Factura obj;
    int cantRegistros = contarRegistros();
    int j = 0;
    for(int i=0; i<cantRegistros; i++)
    {
        obj = leerRegistro(i);
        if(obj.getFecha().getMes() == mes)
        {
            j++;
            obj.mostrarFactura(7+j);
        }
    }
    fclose(p);
    return j;
}
/// FIN ARCHIVO FACTURA

/// ARCHIVO PRODUCTO

ArchivoProducto::ArchivoProducto(const char* nombre)
{
    strcpy(_nombre, nombre);
    _tamanioRegistro = sizeof(Producto);
}
void ArchivoProducto::listarRegistrosPorTipo(const int tipo)
{
    FILE *p;
    p = fopen(_nombre, "rb");
    if(p == nullptr)
    {
        return;
    }
    Producto obj;
    int cantRegistros = contarRegistros();

    int j=0;

    for(int i=0; i<cantRegistros; i++)
    {
        fread(&obj, _tamanioRegistro, 1, p);

        if(obj.getTipo() == tipo)
        {
            obj.Mostrar(13, 11+j);
            j++;
        }
    }
}
void ArchivoProducto::listarRegistrosPorNombre(const char *nombre)
{
    // PROBAR IMPLEMENTAR GETCHAR() O GETCH() PARA ACTUALIZAR EN TIEMPO REAL
    FILE *p;
    p = fopen(_nombre, "rb");
    if(p == nullptr)
    {
        return;
    }
    Producto obj;

    int cantRegistros = contarRegistros();

    for(int i=0; i<cantRegistros; i++)
    {
        fread(&obj, _tamanioRegistro, 1, p);

        if(!strcmp(obj.getNombre(), nombre))
        {
            obj.Mostrar(13, 15+i);
        }
    }
}


bool ArchivoProducto::modificarTipoRegistro(const int tipo, int id)
{
    FILE *p;
    p = fopen(_nombre, "rb+");
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
    p = fopen(_nombre, "rb+");
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
    FILE *p = fopen(_nombre, "rb");
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
    FILE *p = fopen(_nombre, "rb");

    if(p==nullptr)
    {
        return false;
    }

    Producto obj;
    int cant = contarRegistros();

    for(int i = 0; i < cant; i++)
    {
        obj = leerRegistro(i);
        if(obj.getDisponibilidad())
        {
            obj.Mostrar(13, 15+i);
        }
    }
    return true;
}
bool ArchivoProducto::cambiarEstadoRegistro(int id)
{
    int pos = buscarRegistroPorId(id);
    Producto obj;

    FILE* p = fopen(_nombre, "rb+");
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
    p = fopen(_nombre, "rb");
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
    p = fopen(_nombre, "rb+");
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
    p = fopen(_nombre, "ab");
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

    FILE *p;
    p = fopen(_nombre, "rb");
    Producto obj;
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
//FILTERS
bool ArchivoProducto::filtrarRegistrosPorEstado(int tipo)
{
    FILE *p;
    p = fopen(_nombre, "rb");
    if(p == nullptr)
    {
        return false;
    }
    Producto obj;

    int cantRegistros = contarRegistros();
    for(int i=0; i<cantRegistros; i++)
    {
        obj = leerRegistro(i);
        if(obj.getTipo() == tipo)
        {
            obj.Mostrar(1,1); ///CAMBIAR POSICION QUE RECIBE
        }
    }
    fclose(p);
    return true;
}
bool ArchivoProducto::filtrarRegistrosPorEstado(bool estado)
{
    FILE *p;
    p = fopen(_nombre, "rb");
    if(p == nullptr)
    {
        return false;
    }
    Producto obj;

    int cantRegistros = contarRegistros();
    for(int i=0; i<cantRegistros; i++)
    {
        obj = leerRegistro(i);
        if(obj.getDisponibilidad() == estado)
        {
            obj.Mostrar(1,2); ///CAMBIAR POSICION QUE RECIBE
        }
    }
    fclose(p);
    return true;
}
/// FIN ARCHIVO PRODUCTOS
