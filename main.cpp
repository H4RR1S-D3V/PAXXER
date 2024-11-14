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
    ArchivoDelivery arc;
    cout << arc.eliminarRegistro(1);
    arc.listarRegistros();

    return 0;
}
