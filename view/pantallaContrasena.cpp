
#include <iostream>
#include "../rlutil.h"
#include "windows.h"

using namespace std;

#include "pantallasMenuPrincipal.h"

void pantallaContrasenaI()
{
    rlutil::cls();
    rlutil::showcursor();
    int constrasenaM=40999923;
    rlutil::locate(90,15);
    cout<<"PORFAVOR, INGRESE SU CONTRASEÑA";
    rlutil::locate(90,16);
    cout<<"CONTRASEÑA: ";
    cin>>constrasenaM;
    if (constrasenaM==40999923)
    {
        rlutil::cls();
        //mostrarInformes();
    }
    else
        MessageBox(NULL, "¿Desea intentarlo nuevamente?","CONTRASEÑA INCORRECTA", MB_YESNO|MB_ICONERROR);
    if (IDYES)
    {
        rlutil::cls();
        pantallaContrasenaI();
    }
    else
        rlutil::cls();


}

void pantallaContrasenaC()
{
    rlutil::showcursor();
    int constrasenaM=40999923;
    rlutil::locate(90,15);
    cout<<"PORFAVOR, INGRESE SU CONTRASEÑA";
    rlutil::locate(90,16);
    cout<<"CONTRASEÑA: ";
    cin>>constrasenaM;
    if (constrasenaM==40999923)
    {
        rlutil::cls();
        mostrarConfiguraciones();
    }
    else
        MessageBox(NULL, "¿Desea intentarlo nuevamente?","CONTRASEÑA INCORRECTA", MB_YESNO|MB_ICONERROR);
    if (IDYES)
    {
        rlutil::cls();
        pantallaContrasenaC();
    }
    else
        rlutil::cls();


}

