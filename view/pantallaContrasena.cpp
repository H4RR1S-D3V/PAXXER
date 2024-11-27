
#include <iostream>
#include "../rlutil.h"
#include "windows.h"

using namespace std;

#include "pantallasMenuPrincipal.h"
#include "menuPrincipal.h"

void pantallaContrasenaI()
{

    rlutil::cls();
    rlutil::showcursor();
    int constrasenaM=123;
    rlutil::locate(90,15);
    cout<<"PORFAVOR, INGRESE SU CONTRASEÑA";
    rlutil::locate(90,16);
    cout<<"CONTRASEÑA: ";
    cin>>constrasenaM;

    int respuesta;
    if (constrasenaM==123)
    {
        rlutil::cls();
        mostrarInformes();
    }
    else
       respuesta = MessageBox(NULL, "¿Desea intentarlo nuevamente?","CONTRASEÑA INCORRECTA", MB_YESNO|MB_ICONERROR);
    if (respuesta == 6) /// LE DIO AL BOTON ACEPTAR
    {
        rlutil::cls();
        pantallaContrasenaI();
    }
    else if (respuesta == 7) ///LE DIO AL BOTON DE NO
        {
        rlutil::cls();
        mostrarMenuPrincipal();
    }


}

void pantallaContrasenaC()
{
    rlutil::showcursor();
    int constrasenaM=123;
    rlutil::locate(90,15);
    cout<<"PORFAVOR, INGRESE SU CONTRASEÑA";
    rlutil::locate(90,16);
    cout<<"CONTRASEÑA: ";
    cin>>constrasenaM;

    int respuesta;
    if (constrasenaM==123)
    {
        rlutil::cls();
        mostrarConfiguraciones();
    }
    else
      respuesta = MessageBox(NULL, "¿Desea intentarlo nuevamente?","CONTRASEÑA INCORRECTA", MB_YESNO|MB_ICONERROR);
    if (respuesta == 6) /// LE DIO AL BOTON ACEPTAR
    {
        rlutil::cls();
        pantallaContrasenaC();
    }
    else if (respuesta == 7) ///LE DIO AL BOTON DE NO
        {
        rlutil::cls();
        mostrarMenuPrincipal();
    }


}

