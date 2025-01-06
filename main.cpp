///INCLUDES /LIBRARIES
#include <windows.h>

///INCLUDES /VIEW
#include "./view/menuPrincipal.h"
#include "./view/pantallasMenuPrincipal.h"



int main() {
    /// PONER CONSOLA EN FULLSCREEN
    HWND consola = GetConsoleWindow();
    if (consola) {
        // Enviar combinación de teclas ALT + ENTER para pantalla completa
        keybd_event(VK_MENU, 0x38, 0, 0);       // Presionar ALT
        keybd_event(VK_RETURN, 0x1C, 0, 0);     // Presionar ENTER
        keybd_event(VK_RETURN, 0x1C, KEYEVENTF_KEYUP, 0); // Soltar ENTER
        keybd_event(VK_MENU, 0x38, KEYEVENTF_KEYUP, 0);   // Soltar ALT
    }
    /// EJECUCION DE LA APP
    mostrarMenuPrincipal();
    return 0;
}
