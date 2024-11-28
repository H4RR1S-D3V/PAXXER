#include <iostream>

#include "../rlutil.h"
#include "funcionesDibujar.h"
#include "../controller/clasesArchivosMesas.h"


using namespace std;

#include "pantallaTakeAway.h"
#include "pantallasMenuPrincipal.h"
#include "funcionesDibujar.h"

void pantallaTakeAway()
{
bool salir = true;
int x=0;
    do{


///CUADRO SUPERIOR
    rlutil::hidecursor();
    rlutil::setColor(rlutil::LIGHTCYAN);
    dibujarBordeSyI(10,3);
    dibujarBordeSyI(10,6);
    rlutil::setColor(rlutil::BROWN);
    rlutil::locate(15, 5);
    cout<<"NRO.";
    rlutil::locate(45, 5);
    cout <<"NOMBRE CLIENTE";
    rlutil::locate(75, 5);
    cout <<"ID EMPLEADO";
    rlutil::locate(105, 5);
    cout <<"HORA ENTREGA";
    rlutil::locate(135, 5);
    cout <<"IMPORTE";

///CUADRO INFERIOR
    rlutil::setColor(rlutil::MAGENTA);
dibujarBordeSyI(10,15);
dibujarBordeSyI(10,17);
dibujarBordesDeI(9,16,30);
dibujarBordesDeI(160,16,30);
    rlutil::setColor(rlutil::LIGHTCYAN);
    rlutil::locate(25, 16);
    cout <<"CLIENTE QUE RETIRA ";
    rlutil::locate(65, 16);
    cout <<"EMPLEADO ASIGNADO";
    rlutil::locate(95, 16);
    cout <<"HORA ENTREGA ESTIMADA";
    rlutil::locate(135, 16);
    cout <<"TOTAL";

    rlutil::setColor(rlutil::WHITE);

   pintarOpciones("AGREGAR TAKE-AWAY",30, 8, x==0);
    pintarOpciones("CERRAR TAKE-AWAY",60, 8,x==30);
    pintarOpciones("ABRIR TAKE-AWAY",90, 8, x==60);
    pintarOpciones("VOLVER A MAPA MESAS",120, 8, x==90);

        rlutil:: locate (29+x,8);
        cout << char (16);
        int key=rlutil::getkey();
        rlutil::locate(29 + x, 8);
        cout << " ";

        switch (key)
        {
        case 17:

            x+=30;
            if (x>90) x=90;
            break;

        case 16:

            x-=30;
            if (x<0) x=0;

            break;
        case 1:
            switch (x)
            {
            case 0://AGREGAR TAKE-AWAY

                break;
            case 30://CERRAR TAKE-AWAY
                break;
            case 60://ABRIR TAKE-AWAY
                break;
            case 90://VOLVER A MAPA

                 rlutil::cls();
                 salir = false;
                mostrarMapaMesas();
                break;

            }
  rlutil::cls();
            }

    }while (salir==true);

        }
