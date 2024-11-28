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
*/
    //ArchivoMesasLocal arc;
    //cout << arc.verificarDisponibilidadGlobal();
    //cout << arc.contarRegistros();
    HWND consola = GetConsoleWindow();
    ShowWindow(consola, SW_MAXIMIZE);

   /* ArchivoDelivery arc;
    Delivery obj1(1);
    Delivery obj2(2);
    Delivery obj3(3);
    Delivery obj4(4);

    obj1.cargarDelivery();    obj2.cargarDelivery();    obj3.cargarDelivery();    obj4.cargarDelivery();

    arc.agregarRegistro(obj1);
    arc.agregarRegistro(obj2);
    arc.agregarRegistro(obj3);
    arc.agregarRegistro(obj4);*/

    //cout << arc.verificarDisponibilidadGlobal();


    mostrarMenuPrincipal();


    return 0;
}
