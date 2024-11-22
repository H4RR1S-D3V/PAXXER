#include <iostream>
#include <cstring>

#include "clases.h"
#include "clasesArchivos.h"

using namespace std;

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

bool ArchivoDelivery::listarRegistros()
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
        obj.mostrarDelivery();
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
/*
bool ArchivoDelivery::actualizarEstado(int pos);
{
    FILE *p;
    Delivery obj;
    p = fopen(_nombre, "rb+");
    if(p == nullptr)
    {
        return false;
    }

    fseek(p, _tamanioRegistro * pos, 0);
    bool escribio = fwrite(&obj, _tamanioRegistro, 1, p) == 1;
    fclose(p);
    return escribio;
}
*/

int ArchivoDelivery::contarRegistros()
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

bool ArchivoTakeAway::listarRegistros()
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
        obj.mostrarTakeAway();
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
        return -1;
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

/// FIN ARCHIVO FACTURA

/// ARCHIVO PRODUCTO

/*
void ArchivoProducto::eliminarRegistro(int id)
{
    // AUN NO LISTO
    // ELIMINA TODO EL ARCHIVO
    FILE *p;
    p = fopen(_nombre, "wb");
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
*/
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
    Producto obj;

    FILE *p;
    p = fopen(_nombre, "rb");
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
/// FIN ARCHIVO PRODUCTOS

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
/*
    CAMBIAR ROL
    TRAER POR ROL
*/


/// FIN ARCHIVO USUARIOS
