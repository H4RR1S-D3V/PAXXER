///INCLUDES /LIBRARIES
#include <windows.h>

///INCLUDES /VIEW
#include "./view/menuPrincipal.h"
#include <iostream>
#include <cstring>
#include <ctime>
#include "rlutil.h"

///INCLUDES /CONTROLLER
#include "./controller/constantes.h"
#include "./controller/generadorIDs.h"


#include "./controller/clasesArchivosMesas.h"
#include "./controller/clasesArchivosFacturas.h"

#include "./view/declaracionOpcionesMapaMesas.h"
#include "./view/pantallasMenuPrincipal.h"
#include "./view/funcionesDibujar.h"
#include "./view/funcionesDibujarTitulos.h"
#include "./view/pantallaDelivery.h"

using namespace std;

int main()
{
/*
*/
    ArchivoMesasLocal arc;
    arc.setearCantMesas(10);
    HWND consola = GetConsoleWindow();
    ShowWindow(consola, SW_MAXIMIZE);

    mostrarMenuPrincipal();

    return 0;
}
