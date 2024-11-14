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
    Delivery obj(1);
    obj.cargarDelivery();

    Delivery obj2(2);
    obj2.cargarDelivery();

    arc.agregarRegistro(obj);
    arc.agregarRegistro(obj2);
*/

    ArchivoDelivery arc;
    cout << "# | ";
    cout << "DIRECCION DE ENTREGA | ";
    cout << "RESPONSALBLE | ";
    cout << "HORA DE ENTREGA | ";
    cout << "TOTAL | " << endl;
    cout << "-------------------------------------------------------------------" << endl;

    arc.listarRegistros();

    return 0;
}
