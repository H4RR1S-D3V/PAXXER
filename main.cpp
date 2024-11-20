#include <iostream>

#include <cstring>
#include <ctime>
#include "rlutil.h"
#include <windows.h>





///INCLUDES /CONTROLLER
#include "./controller/clases.h"
#include "./controller/clasesArchivos.h"
#include "./controller/constantes.h"
#include "./controller/generadorIDs.h"

///INCLUDES /VIEW
#include "./view/declaracionOpcionesMapaMesas.h"
#include "./view/menuPrincipal.h"
#include "./view/pantallasMenuPrincipal.h"
#include "./view/funcionesDibujar.h"
#include "./view/funcionesDibujarTitulos.h"



using namespace std;




int main()
{
    //ArchivoProducto arc;
    //arc.listarRegistros();
    HWND consola = GetConsoleWindow();
    ShowWindow(consola, SW_MAXIMIZE);
    ArchivoMesasLocal arcMesa;
    arcMesa.setearCantMesas(10);

    mostrarMenuPrincipal();




  return 0;
}
