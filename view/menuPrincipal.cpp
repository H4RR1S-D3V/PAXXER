
#include <iostream>
#include "../rlutil.h"
#include "windows.h"

using namespace std;
#include "menuPrincipal.h"
#include "funcionesDibujar.h"
#include "funcionesDibujarTitulos.h"
#include "pantallasMenuPrincipal.h"
#include "funcionesDibujarTitulos.h"


void mostrarMenuPrincipal()
{
    int op=1;
    int y=0;
    do
    {

        rlutil::hidecursor();


        dibujarBordesMenuPrincipal(42,19);
        dibujarTituloPAXXER();
        dibujarBordesMenuPrincipal(42,10);
        rlutil::setColor(rlutil::LIGHTCYAN);
        rlutil::locate(65,21);
        cout << "R    E    S    T    O   -   B    A    R";
        rlutil::setColor(rlutil::WHITE);
        pintarOpciones("MESAS", 84, 24, y==0);
        pintarOpciones("CARTA", 84, 26, y==2);
        pintarOpciones("INFORMES", 83, 28, y==4);
        pintarOpciones("CONFIGURACION", 80, 30, y==6);
        pintarOpciones("SALIR", 84, 32, y==8);


        rlutil::locate(78,24+(y));
        cout << char (26);
        rlutil::locate(95,24+(y));
        cout << char (27);

        int key=rlutil::getkey();

        switch (key)
        {
        case 14:
            rlutil::locate(78,24+(y));
            cout << " ";
            rlutil::locate(95,24+(y));
            cout << " ";
            y -= 2;
            if (y < 0) y = 0;
            break;
        case 15:
            rlutil::locate(78,24+(y));
            cout << " ";
            rlutil::locate(95,24+(y));
            cout << " ";
            y += 2;
            if (y > 8) y = 8;
            break;
        case 1:
            switch (y)
            {
            case 0:  ///MESAS
            {
                rlutil::cls();
                mostrarMapaMesas();
                break;
            }
            case 2:  ///CARTA
            {

                rlutil::cls();
                mostrarCarta();

                break;
            }
            case 4: ///INFORMES
            {
                int resultado=MessageBox(NULL,"¿Desea ingresar su contraseña de Encargado?","INGRESO RESTRINGIDO - SOLO ENCARGADOS",MB_OKCANCEL|MB_ICONINFORMATION);
                if (resultado==IDOK)
                {
                    rlutil::cls();
                    mostrarInformes();
                    //pantallaContrasenaI();
                }

                break;
            }



            case 6: ///CONFIGURACION
            {
                int resultado=MessageBox(NULL,"¿Desea ingresar su contraseña de Encargado?","INGRESO RESTRINGIDO - SOLO ENCARGADOS",MB_OKCANCEL|MB_ICONINFORMATION);
                if (resultado==IDOK)
                {
                    rlutil::cls();
                    mostrarConfiguraciones();
                      //pantallaContrasenaC();

                }
                 break;
            }


            case 8:  ///SALIR
            {
               rlutil::cls();
               cout << "SALIENDO DEL PROGRAMA..."<< endl;
              rlutil::setColor(rlutil::BLACK);
                exit(0);

                break;
            }
            }

        }


    }
    while (op!=0);
}
