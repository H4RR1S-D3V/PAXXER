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
        dibujarBordesPantallas(87,9);
        dibujarBordesPantallas(87,11);
        rlutil::setColor (rlutil::BROWN);
        rlutil:: locate (96,10);
        cout << "F  I  L  T  R  A  R       R  E  C  A  U  D  A  C  I  O  N  E  S";
        rlutil::setColor (rlutil::WHITE);
        pintarOpciones("POR FECHA",40,12, x==0);
        pintarOpciones("POR ITEMS DE CARTA",80,12, x==40);
        pintarOpciones("POR TIPO DE PEDIDO",120,12, x==80);
        pintarOpciones("POR EMPLEADO",160,12, x==120);
        pintarOpciones("VOLVER A MENU PRINCIPAL",200,12, x==160);

        rlutil:: locate (39+x,12);
        cout << char (16);
        int key=rlutil::getkey();
        rlutil::locate(39 + x, 12);
        cout << " ";


        switch (key)
        {
        case 17:
            x+=40;
            if (x>160) x=160;
            break;
        case 16:
            x-=40;
            if (x<0) x=0;
            break;
        case 1:
            switch (x)
            {
            case 0:
                mostrarRecaudacionesPorFecha();
                break;
            case 40:

                mostrarRecaudacionesPorItemsDeCarta();
                break;
            case 80:
                mostrarRecaudacionesPorTipoDePedido();
                break;
            case 120:

                mostrarRecaudacionesPorEmpleado();
                break;
            case 160:
                rlutil::cls();
                salir=false;
                rlutil::cls();
                break;
            }
        }


    }
    while(salir==true);

}

