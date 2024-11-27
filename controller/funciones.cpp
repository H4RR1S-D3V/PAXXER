#include <iostream>
#include <cstring>

#include "clasesAuxiliares.h"
#include "clasesArchivosFacturas.h"
#include "clasesArchivosUsuarios.h"



using namespace std;

string horaActual(){
Tiempo tiempo;
    int hora = tiempo.getHora();
    int mins = tiempo.getMinutos();
    string HHMM = (hora < 10 ? "0" : "") + to_string(hora) + ":" +
                       (mins < 10 ? "0" : "") + to_string(mins);
return HHMM;
}

Fecha fechaActual(){
Tiempo tiempo;
return tiempo.getFecha();
}

void cargarCadena(char *pal, int tam){
    int i;
    fflush (stdin); ///limpia el buffer de entrada para que la carga se haga sin caracteres que hayan quedado sin usar
    for(i=0; i<tam;i++){
        pal[i]=cin.get();
        if(pal[i]=='\n')break;
    }
    pal[i]='\0';
    fflush(stdin); ///vuelve a limpiar el buffer para eliminar los caracteres sobrantes
}

int generarId(int tipo){
/// TIPO = 1 - USUARIOS | 2- PRODUCTOS | 3- FACTURAS
    switch(tipo){
    case 1:{
        ArchivoUsuario arc;
        int cant = arc.contarRegistros();
        return cant+1;
        break;
        }
    case 2:{
        ArchivoProducto arc;
        int cant = arc.contarRegistros();
        return cant+1;
        break;
        }
     case 3:{
        ArchivoFactura arc;
        int cant = arc.contarRegistros();
        return cant+1;
        break;
        }
      default:{
        return -1; ///tipo invalido
        break;
        }
    }
}
