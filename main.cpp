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
    ArchivoMesasLocal arc;
    arc.setearCantMesas(10);
    obj = arc.leerRegistro(16);
    obj.cargarItem(5, 1);
    obj.cargarItem(3, 3);
    obj.cargarItem(2, 2);
    obj.cargarItem(5, 1);
    obj.cargarItem(10, 1);
    obj.cargarItem(11, 1);
    obj.cargarItem(12, 1);
    ArchivoFactura arc;
    arc.listarRegistrosPorAnio(2024);
*/
    HWND consola = GetConsoleWindow();
    ShowWindow(consola, SW_MAXIMIZE);



    mostrarMenuPrincipal();



    return 0;
}
