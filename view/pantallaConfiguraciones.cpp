#include <iostream>
#include "../rlutil.h"
#include "windows.h"

using namespace std;

#include "pantallasMenuPrincipal.h"
#include "funcionesDibujar.h"
#include "declaracionOpcionesConfiguraciones.h"
#include "../controller/clasesArchivos.h"
#include "menuPrincipal.h"


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
        dibujarBordesPantallas(42,9);
        dibujarBordesPantallas(42,11);
        rlutil::setColor (rlutil::BROWN);
        rlutil:: locate (60,10);
        cout << "S O L O     P E R S O N A L    A U T O R I Z A D O";
        rlutil::setColor (rlutil::WHITE);
        pintarOpciones("CONFIGURAR CARTA", 74, 14, y==0);
        pintarOpciones("LISTADO DE EMPLEADOS", 74, 16, y==2);
        pintarOpciones("CAMBIAR CANTIDAD MESAS", 74, 18, y==4);
        pintarOpciones("VOLVER A MENU PRINCIPAL", 74, 20, y==6);

        rlutil::locate(72,14+(y));
        cout << char (16);

        int key=rlutil::getkey();
        switch (key)
        {
        case 14:
            rlutil::locate(72,14+(y));
            cout << " ";
            y -= 2;
            if (y < 0) y = 0;
            break;
        case 15:
            rlutil::locate(72,14+(y));
            cout << " ";
            y += 2;
            if (y > 6) y = 6;
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
               mostrarEmpleados();
                break;
            case 4:{
               rlutil::cls();
               ///
               int resultado=MessageBox(NULL,"Ingrese la cantidad de mesas a dibujar (MAX 10)","CAMBIAR CANTIDAD DE MESAS - SALON",MB_OKCANCEL|MB_ICONINFORMATION);
               if (resultado==IDOK)
                {
                    int cantMesas;
                    cout << "NRO DE MESAS ";
                    cin >> cantMesas;
                    if (cantMesas <= 10){

                    ArchivoMesasLocal arc;
                    arc.setearCantMesas(cantMesas);
                    } else {
                    rlutil::cls();
                    MessageBox(NULL, "EL MAXIMO DE MESAS ES 10", "ERROR CANTIDAD DE MESAS", MB_OKCANCEL);
                    }

                }
                break;
            }
            case 6:
                rlutil::cls();
                salir=false;
                mostrarMenuPrincipal();
                break;


            }



        }
    }
    while(salir==true);

}
