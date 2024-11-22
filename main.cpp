///INCLUDES /LIBRARIES
#include <iostream>
#include <cstring>
#include <ctime>
#include <windows.h>
#include "rlutil.h"

///INCLUDES /CONTROLLER
#include "./controller/clasesArchivos.h"
#include "./controller/constantes.h"
#include "./controller/generadorIDs.h"

///INCLUDES /VIEW
#include "./view/declaracionOpcionesMapaMesas.h"
#include "./view/menuPrincipal.h"
#include "./view/pantallasMenuPrincipal.h"
#include "./view/funcionesDibujar.h"
#include "./view/funcionesDibujarTitulos.h"
#include "./view/pantallaDelivery.h"

using namespace std;

int main()
{
    HWND consola = GetConsoleWindow();
    ShowWindow(consola, SW_MAXIMIZE);

    mostrarMenuPrincipal();

    return 0;
}
