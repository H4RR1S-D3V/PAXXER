#include <iostream>

#include <cstring>
#include <ctime>

#include "constantes.h"
#include "clases.h"

#include "generadorIDs.h"
#include "rlutil.h"

#include "clasesArchivos.h"



#include "dibujarBordes.h"
#include "menuPrincipal.h"

using namespace std;

int main()
{
    /*



    obj = arc.leerRegistro(3);
    obj.abrirMesa();
    */


    ArchivoMesasLocal arc;


    arc.listarRegistros();




/*
    int cant = arc.contarRegistros();
    for(int i=0; i<cant; i++)
    {
        obj = arc.leerRegistro(i);
        obj.mostrarLocal();
    }
*/

///mostrarMenuPrincipal();


   return 0;
}
