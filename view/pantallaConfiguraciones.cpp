#include <iostream>
#include "../rlutil.h"
#include "windows.h"

using namespace std;

#include "pantallasMenuPrincipal.h"
#include "funcionesDibujar.h"
#include "declaracionOpcionesConfiguraciones.h"

void mostrarConfiguraciones()
{

    bool salir=true;
    int y=0;


    do
    {
        rlutil::hidecursor();
        rlutil::setColor (rlutil::MAGENTA);
        dibujarTituloCONFIGURACIONES();
        rlutil::setColor (rlutil::LIGHTCYAN);
        dibujarBordesPantallas(80,9);
        dibujarBordesPantallas(80,11);
        rlutil::setColor (rlutil::BROWN);
        rlutil:: locate (95,10);
        cout << "S O L O     P E R S O N A L    A U T O R I Z A D O";
        rlutil::setColor (rlutil::WHITE);
        pintarOpciones("CONFIGURAR CARTA", 104, 14, y==0);
        pintarOpciones("LISTADO DE EMPLEADOS", 104, 16, y==2);
        pintarOpciones("VOLVER A MENU PRINCIPAL", 104, 18, y==4);

        rlutil::locate(103,14+(y));
        cout << char (16);

        int key=rlutil::getkey();
        switch (key)
        {
        case 14:
            rlutil::locate(103,14+(y));
            cout << " ";
            y -= 2;
            if (y < 0) y = 0;
            break;
        case 15:
            rlutil::locate(103,14+(y));
            cout << " ";
            y += 2;
            if (y > 4) y = 4;
            break;
        case 1:
            switch (y)
            {
            case 0:{
             rlutil::cls();
              mostrarConfigurarCarta();
                break;
            }

            case 2:
                rlutil::cls();
               //mostrarEmpleados();
                break;
            case 4:
                rlutil::cls();
                salir=false;
                break;


            }



        }
    }
    while(salir==true);

}
