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









