#include <iostream>
#include "../rlutil.h"
#include <windows.h>

using namespace std;

#include "declaracionOpcionesMapaMesas.h"
#include "funcionesDibujar.h"
#include "menuPrincipal.h"
#include "pantallasMenuPrincipal.h"


void dibujarPedidos()
{
    //dibujarCajaPedidos();
    cout << "PEDIDO N°: "; //ACA ID PEDIDO
    cout << "NOMBRE/ID EMPLEADO: ";
    cout << "MESA N° ";
    cout << "CANTIDAD COMENSALES: ";
    cout << "LISTA DE ITEMS:";
    cout << "ENTRADAS: ";
    cout << "PLATO PRINCIPAL: ";
    cout << "POSTRE: ";
    cout << "BEBIDAS: ";

    cout << "DESCUENTOS: ";

    cout << "TOTAL: ";

}

void mostrarPantallaPedidos()
{
    bool salir=true;
    int x=0;
    do
    {
        rlutil::hidecursor();
        rlutil::setColor(rlutil::MAGENTA);
        dibujarTituloNUESTROSPEDIDOS();
        rlutil::setColor(rlutil::LIGHTCYAN);
        dibujarBordesPantallas(80, 9);
        dibujarBordesPantallas(80,11);
        rlutil::setColor(rlutil::BROWN);
        rlutil::locate(98,10);
        cout << "P       A       X       X       E       R";
        rlutil::setColor(rlutil::WHITE);
        pintarOpciones("PEDIDOS EN CURSO",40,13, x==0);
        pintarOpciones("PEDIDOS TERMINADOS",90,13, x==50);
        pintarOpciones("VOLVER A MAPA MESAS", 140,13, x==100);
        pintarOpciones("VOLVER A MENU PRINCIPAL",190,13, x==150 );

        rlutil:: locate (39+x,13);
        cout << char (16);
        int key=rlutil::getkey();
        rlutil::locate(39 + x, 13);
        cout << " ";



        switch (key)
        {
        case 17:
            x+=50;
            if (x>150) x=150;
            break;
        case 16:
            x-=50;
            if (x<0) x=0;
            break;
        case 1:
            switch (x)
            {
            case 0://MOSTRAR PEDIDOS EN CURSO
                   //If pedidos == 0 --> "Sin pedidos por el momento"
                break;
            case 50: //MOSTRAR PEDIDOS TERMINADOS
                break;
            case 100://VOLVER A MAPA MESAS

                salir=false;
                rlutil::cls();
                mostrarMapaMesas();
                break;
            case 150://VOLVER A MENU PRINCIPAL

                salir=false;
                 rlutil::cls();
                mostrarMenuPrincipal();

                break;
            }
        }



    }
    while(salir==true);
}

void dibujarFactura()
{


}
