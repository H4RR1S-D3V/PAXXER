///INCLUDES /LIBRARIES
#include <windows.h>

#include "./view/menuPrincipal.h"
#include <iostream>
#include <cstring>
#include <ctime>
#include "rlutil.h"

///INCLUDES /CONTROLLER
#include "./controller/constantes.h"
#include "./controller/funciones.h"


#include "./controller/clasesArchivosMesas.h"
#include "./controller/clasesArchivosFacturas.h"
#include "./controller/clasesArchivosUsuarios.h"

///INCLUDES /VIEW
#include "./view/declaracionOpcionesMapaMesas.h"
#include "./view/pantallasMenuPrincipal.h"
#include "./view/funcionesDibujar.h"
#include "./view/funcionesDibujarTitulos.h"
#include "./view/pantallaDelivery.h"


using namespace std;

int main()
{
/*
    arc.setearCantMesas(10);
    cout << arc.contarRegistros();
*/
    HWND consola = GetConsoleWindow();
    ShowWindow(consola, SW_MAXIMIZE);
    ArchivoMesasLocal arc;

    //cout << arc.verificarDisponibilidadGlobal();


    mostrarMenuPrincipal();


    return 0;
}
