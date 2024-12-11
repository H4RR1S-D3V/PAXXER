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
        pintarOpciones("POR TURNO",35,12, x==25);
        pintarOpciones("POR TIPO DE PEDIDO",60,12, x==50);
        pintarOpciones("POR EMPLEADO",85,12, x==75);
        pintarOpciones("ABRIR FACTURA",110,12, x==100);
        pintarOpciones("VOLVER A MENU PRINCIPAL",135 ,12, x==125);


        rlutil:: locate (9+x,12);
        cout << char (16);
        int key=rlutil::getkey();
        rlutil::locate(9 + x, 12);
        cout << " ";


        switch (key)
        {
        case 17:
            x+=25;
            if (x>125) x=125;
            break;
        case 16:
            x-=25;
            if (x<0) x=0;
            break;
        case 1:
            switch (x)
            {
            case 0:
                mostrarRecaudacionesPorFecha();
                break;
            case 25:
                mostrarRecaudacionesPorTurno();
                break;
            case 50:
                mostrarRecaudacionesPorTipoDePedido();
                break;
            case 75:

                mostrarRecaudacionesPorEmpleado();
                break;
            case 125:
                rlutil::cls();
                salir=false;
                rlutil::cls();
                break;
            case 100:
                mostrarFacturaPorID();
                break;
            }
        }


    }
    while(salir==true);

}

