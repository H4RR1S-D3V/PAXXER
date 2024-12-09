///INCLUDES /LIBRARIES
#include <windows.h>

///INCLUDES /VIEW
#include "./view/menuPrincipal.h"
#include "./view/pantallasMenuPrincipal.h"

int main()
{
    HWND consola = GetConsoleWindow();
    ShowWindow(consola, SW_MAXIMIZE);



    mostrarMenuPrincipal();
    return 0;
}
