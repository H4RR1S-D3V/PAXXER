#include <iostream>
#include <cstring>
#include "generadorIDs.h"
#include "constantes.h"

using namespace std;



/// EN EL CONSTRUCTOR, LE PASAMOS CUAL ARCHIVO QUEREMOS USAR
/// "id_empleados.txt" - "id_productos.txt" - "id_facturas.txt" -

ArchivoId::ArchivoId(const char *n){
strcpy(this->nombre,n);
}
int ArchivoId::leerRegistro(int pos){
    int nuevaId = 0;
    FILE *p=fopen(nombre,"rb");
    if(p==NULL){
        return nuevaId;
        }
    fseek(p, pos * sizeof nuevaId, 0);
    fread(&nuevaId, sizeof nuevaId, 1, p);
    fclose(p);
    return nuevaId;
}

bool ArchivoId::grabarRegistro(int nuevaId){
    FILE *p;
    p=fopen(nombre, "wb");
    if(p==NULL) return false;
    int escribio=fwrite(&nuevaId, sizeof nuevaId,1, p);
    fclose(p);
    return escribio;
}

int generarId(int tipo){
    /// TIPO = 1 - EMPLEADOS | 2- PRODUCTOS | 3- FACTURAS
int nuevaId = 0;
char nombreArchivo[30];

switch(tipo){
case 1:
    strcpy(nombreArchivo, ARCHIVO_ID_EMPLEADOS);
    break;
case 2:
    strcpy(nombreArchivo, ARCHIVO_ID_PRODUCTOS);
    break;
case 3:
    strcpy(nombreArchivo, ARCHIVO_ID_FACTURAS);
    break;
}

ArchivoId archivo(nombreArchivo);

nuevaId = archivo.leerRegistro(0)+1;
archivo.grabarRegistro(nuevaId);

return nuevaId;
}
