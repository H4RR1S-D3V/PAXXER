
#include <iostream>
#include "../rlutil.h"
#include "windows.h"

using namespace std;

#include "menuPrincipal.h"
#include "pantallasMenuPrincipal.h"
#include "funcionesDibujar.h"

void pantallaContrasenaI()

{
    int respuesta;
bool salir = true;

do {

    rlutil::cls();
    rlutil::setColor(rlutil::LIGHTRED);
    dibujarBordeSyI(10,10);
    dibujarBordeSyI(10,12);
    dibujarBordeSyI(10,20);
      rlutil::setColor(rlutil::YELLOW);
       rlutil::locate(60,11);

    cout<< "ACCESO RESTRINGIDO  -  SOLO PERSONAL AUTORIZADO";


  int constrasenaM =123;
        rlutil::setColor(rlutil::WHITE);
  rlutil::locate(60,14);
         cout<<"PORFAVOR, INGRESE SU DNI: ";
         ///agregar cin DNI
    rlutil::locate(60,15);
    cout<<"PORFAVOR, INGRESE SU CONTRASE"<<char (165)<<"A: ";
    rlutil::showcursor();
    rlutil::locate(73,15);
  cin >> constrasenaM;
    cin.ignore();
    rlutil::hidecursor();
    if (constrasenaM==123)
    {
        salir=false;
        rlutil::cls();
        mostrarInformes();
    }
    else
      respuesta=  MessageBox(NULL, "¿Desea intentarlo nuevamente?","CONTRASEÑA INCORRECTA", MB_YESNO|MB_ICONERROR);
    if (IDYES)
    {
        rlutil::cls();

    }
    else if (IDNO) {
        salir=false;
        rlutil::cls();
        mostrarMenuPrincipal();

    }

}while(salir==true);


}
//REVISAR COMO LIMPIAR BUFFER
void pantallaContrasenaC()
{
   int respuesta;

bool salir = true;

do {

    rlutil::cls();
    rlutil::setColor(rlutil::LIGHTRED);
    dibujarBordeSyI(10,10);
    dibujarBordeSyI(10,12);
    dibujarBordeSyI(10,20);
      rlutil::setColor(rlutil::YELLOW);
       rlutil::locate(60,11);

    cout<< "ACCESO RESTRINGIDO  -  SOLO PERSONAL AUTORIZADO";


  int constrasenaM =123;
        rlutil::setColor(rlutil::WHITE);
  rlutil::locate(60,14);
         cout<<"PORFAVOR, INGRESE SU DNI: ";
         ///agregar cin DNI
    rlutil::locate(60,15);
    cout<<"PORFAVOR, INGRESE SU CONTRASE"<<char (165)<<"A: ";
    rlutil::showcursor();
    rlutil::locate(73,15);
  cin >> constrasenaM;
    cin.ignore();
    rlutil::hidecursor();
    if (constrasenaM==123)
    {
        salir=false;
        rlutil::cls();
        mostrarConfiguraciones();
    }
    else
      respuesta=  MessageBox(NULL, "¿Desea intentarlo nuevamente?","CONTRASEÑA INCORRECTA", MB_YESNO|MB_ICONERROR);
    if (IDYES)
    {
        rlutil::cls();

    }
    else if (IDNO) {
        salir=false;
        rlutil::cls();
        mostrarMenuPrincipal();

    }

}while(salir==true);
}
