#include <iostream>
#include "../rlutil.h"
#include "windows.h"

using namespace std;
#include "declaracionInformesRecaudaciones.h"
#include "pantallasMenuPrincipal.h"
#include "funcionesDibujar.h"
void mostrarInformes()
{

    bool salir=true;
    int x=0;


    do
    {
        rlutil::hidecursor();
        rlutil::setColor (rlutil::MAGENTA);
        dibujarTituloINFORMES();
        rlutil::setColor (rlutil::LIGHTCYAN);
        dibujarBordesPantallas(42,9);
        dibujarBordesPantallas(42,11);
        rlutil::setColor (rlutil::BROWN);
        rlutil:: locate (50,10);
        cout << "F  I  L  T  R  A  R       R  E  C  A  U  D  A  C  I  O  N  E  S";
        rlutil::setColor (rlutil::WHITE);
        pintarOpciones("POR FECHA",10,12, x==0);
        pintarOpciones("POR TURNO",40,12, x==30);
        pintarOpciones("POR TIPO DE PEDIDO",70,12, x==60);
        pintarOpciones("POR EMPLEADO",100,12, x==90);
        pintarOpciones("VOLVER A MENU PRINCIPAL",130,12, x==120);

        rlutil:: locate (9+x,12);
        cout << char (16);
        int key=rlutil::getkey();
        rlutil::locate(9 + x, 12);
        cout << " ";


        switch (key)
        {
        case 17:
            x+=30;
            if (x>120) x=120;
            break;
        case 16:
            x-=30;
            if (x<0) x=0;
            break;
        case 1:
            switch (x)
            {
            case 0:
                mostrarRecaudacionesPorFecha();
                break;
            case 30:
                mostrarRecaudacionesPorTurno();
                break;
            case 60:
                mostrarRecaudacionesPorTipoDePedido();
                break;
            case 90:

                mostrarRecaudacionesPorEmpleado();
                break;
            case 120:
                rlutil::cls();
                salir=false;
                rlutil::cls();
                break;
            }
        }


    }
    while(salir==true);

}

