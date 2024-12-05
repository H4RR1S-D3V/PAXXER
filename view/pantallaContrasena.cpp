
#include <iostream>
#include "../rlutil.h"
#include "windows.h"

using namespace std;

#include "menuPrincipal.h"
#include "pantallasMenuPrincipal.h"
#include "funcionesDibujar.h"
#include "../controller/clasesArchivosUsuarios.h"

void pantallaContrasenaI()

{
    int respuesta;
    bool salir = true;
    ArchivoUsuario arc;


do {

    rlutil::cls();
    rlutil::setColor(rlutil::LIGHTRED);
    dibujarBordeSyI(10,10);
    dibujarBordeSyI(10,12);
    dibujarBordeSyI(10,20);
      rlutil::setColor(rlutil::YELLOW);
       rlutil::locate(60,11);

    cout<< "ACCESO RESTRINGIDO  -  SOLO PERSONAL AUTORIZADO";

    char inputDNI[10] = "";
    char inputPassword[12] = "";
    rlutil::setColor(rlutil::WHITE);
    rlutil::locate(60,14);
    cout<<"PORFAVOR, INGRESE SU DNI: ";
    ///agregar cin DNI
    rlutil::locate(60,15);
    cout<<"PORFAVOR, INGRESE SU CONTRASE"<<char (165)<<"A: ";
    rlutil::showcursor();
    rlutil::locate(86,14);
    cin >> inputDNI;
    cin.ignore();
    rlutil::locate(93,15);
    cin >> inputPassword;
    cin.ignore();
    rlutil::hidecursor();
    if (arc.verificarCredenciales(inputDNI, inputPassword))
    {
        salir=false;
        rlutil::cls();
        mostrarInformes();
    }
    else
      respuesta=  MessageBox(NULL, "¿Desea intentarlo nuevamente?","CONTRASEÑA INCORRECTA", MB_YESNO|MB_ICONERROR);
    if (respuesta == 6) ///CASE YES
    {
        rlutil::cls();

    }
    else if (respuesta == 7) ///CASE NO
        {
        salir=false;
        rlutil::cls();
        mostrarMenuPrincipal();

    }

}while(salir==true);


}
//REVISAR COMO LIMPIAR BUFFER
void pantallaContrasenaC()
{
    int respuesta = 0;
    bool salir = true;
    ArchivoUsuario arc;

do {

    rlutil::cls();
    rlutil::setColor(rlutil::LIGHTRED);
    dibujarBordeSyI(10,10);
    dibujarBordeSyI(10,12);
    dibujarBordeSyI(10,20);
      rlutil::setColor(rlutil::YELLOW);
       rlutil::locate(60,11);

    cout<< "ACCESO RESTRINGIDO  -  SOLO PERSONAL AUTORIZADO";


    char inputDNI[10] = "";
    char inputPassword[12] = "";
    rlutil::setColor(rlutil::WHITE);
    rlutil::locate(60,14);
    cout<<"PORFAVOR, INGRESE SU DNI: ";
    ///agregar cin DNI
    rlutil::locate(60,15);
    cout<<"PORFAVOR, INGRESE SU CONTRASE"<<char (165)<<"A: ";
    rlutil::showcursor();
    rlutil::locate(86,14);
    cin >> inputDNI;
    //cin.ignore();
    rlutil::locate(93,15);
    cin >> inputPassword;
    //cin.ignore();
    rlutil::hidecursor();
    if (arc.verificarCredenciales(inputDNI, inputPassword))
    {
        salir=false;
        rlutil::cls();
        mostrarConfiguraciones();
    }
    else
      respuesta=  MessageBox(NULL, "¿Desea intentarlo nuevamente?","CONTRASEÑA INCORRECTA", MB_YESNO|MB_ICONERROR);
    if (respuesta == 6) ///CASE YES
    {
        rlutil::cls();

    }
    else if (respuesta == 7) ///CASE NO
        {
        salir=false;
        rlutil::cls();
        mostrarMenuPrincipal();

    }

}while(salir==true);
}
