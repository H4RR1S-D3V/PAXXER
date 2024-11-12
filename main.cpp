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
    ArchivoMesasLocal arc;

/*

    obj.abrirMesa();

    arc.setearCantMesas(5);

    Producto prod;
    prod.Cargar();
    arcPro.agregarRegistro(prod);
*/
    //ArchivoProducto arcPro;
   // arcPro.listarRegistros();
    /*

    Local obj(2);
    obj.abrirMesa();
    */
    arc.listarRegistros();

  return 0;
}
