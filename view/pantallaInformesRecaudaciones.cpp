#include <iostream>
#include "../rlutil.h"
#include "windows.h"

using namespace std;

#include "declaracionInformesRecaudaciones.h"
#include "funcionesDibujar.h"
#include "menuPrincipal.h"


void mostrarRecaudacionesPorFecha()
{
    int x=0;
    bool salir=true;
    do
    {
        rlutil::hidecursor();
        rlutil::setColor (rlutil::LIGHTCYAN);
        dibujarBordesPantallas(42,16);
        rlutil::setColor (rlutil::BROWN);
        rlutil:: locate (60,15);
        cout << "R E C A U D A C I O N E S   P O R   F E C H A";
        rlutil::setColor (rlutil::WHITE);
        rlutil:: locate (9+(x),12);
        cout << char (16);
        //PODRIAMOS FILTRAR POR SEMANA O SINO FILTRAR POR DIA YQ UE TE MUESTRE TODOS LOS (POR EJ) MARTES DEL AÑO
        pintarOpciones("FILTRAR POR DIA",10,17, x==0);
        pintarOpciones("FILTRAR POR MES",45,17, x==35);
        pintarOpciones("FILTRAR POR ANIO",80,17, x==70);
        pintarOpciones("VOLVER A INFORMES",115,17, x==105);
        pintarOpciones("VOLVER A MENU PRINCIPAL",145,17, x==140);
        int key=rlutil::getkey();
        switch (key)
        {
        case 17:
            rlutil:: locate (9+(x),17);
            cout << " ";
            x+=35;
            if (x>140) x=140;

            break;
        case 16:
            rlutil:: locate (9+(x),17);
            cout << " ";
            x-=35;
            if (x<0) x=0;
            break;

        case 1:
            switch (x)
            {
            case 0:
                rlutil:: locate (100,19);
                cout << "ACA IRIA EL <<EXCEL>> DE RECAUDACIONES POR DIA";
                break;
            case 35:

                dibujarBordeSyI (10,19);
                dibujarBordeSyI (10,21);
                dibujarBordesDeI (10,20,20);
                dibujarBordesDeI (160,20,20);
                rlutil::setColor (rlutil::BROWN);
                rlutil:: locate (40,20);
                cout << "MES";
                rlutil:: locate (100,20);
                cout << "RECAUDACION";

                break;
            case 70:
                dibujarBordeSyI (10,19);
                dibujarBordeSyI (10,21);
                dibujarBordesDeI (10,20,20);
                dibujarBordesDeI (160,20,20);
                rlutil::setColor (rlutil::BROWN);
                rlutil:: locate (40,20);
                cout << "A"<< char(165)<< "O";
                rlutil:: locate (100,20);
                cout << "RECAUDACION";
                break;
            case 105:
                rlutil::cls();
                salir=false;
                break;
            case 140:
                rlutil::cls();
                mostrarMenuPrincipal();
                break;
            }
            break;
        }
    }
    while (salir==true);
}

void mostrarRecaudacionesPorItemsDeCarta()
{
    int x=0;
    bool salir=true;
    do
    {

        rlutil::hidecursor();
        rlutil::setColor (rlutil::LIGHTCYAN);

        dibujarBordesPantallas(42,16);
        rlutil::setColor (rlutil::BROWN);
        rlutil:: locate (50,15);
        cout << "R E C A U D A C I O N E S   P O R   I T E M S   D E   C A R T A";
        rlutil::setColor (rlutil::WHITE);
        rlutil:: locate (19+(x),17);
        cout << char (16);
        pintarOpciones("POR ENTRADA",20,17, x==0);
        pintarOpciones("POR P. PRINCIPAL",40,17, x==20);
        pintarOpciones("POR POSTRE",60,17, x==40);
        pintarOpciones("POR BEBIDA",80,17, x==60);
        pintarOpciones("VOLVER A INFORMES",100,17, x==80);
        pintarOpciones("VOLVER A MENU PRINCIPAL",120,17, x==100);
        int key=rlutil::getkey();
        switch (key)
        {
        case 17:
            rlutil:: locate (19+(x),17);
            cout << " ";
            x+=20;
            if (x>120) x=120;

            break;
        case 16:
            rlutil:: locate (19+(x),17);
            cout << " ";
            x-=20;
            if (x<0) x=0;
            break;

        case 1:
            switch (x)
            {
            case 0:
                dibujarBordeSyI (10,19);
                dibujarBordeSyI (10,21);
                dibujarBordesDeI (10,20,20);
                dibujarBordesDeI (160,20,20);
                rlutil:: locate (40,20);
                cout << "ID ENTRADAS";
                rlutil:: locate (100,20);
                cout << "RECAUDACION";
                break;
            case 20:
                dibujarBordeSyI (10,19);
                dibujarBordeSyI (10,21);
                dibujarBordesDeI (10,20,20);
                dibujarBordesDeI (160,20,20);
                rlutil:: locate (30,20);
                cout << "ID PLATOS PRINCIPALES";
                rlutil:: locate (100,20);
                cout << "RECAUDACION";
                break;
            case 40:
                dibujarBordeSyI (10,19);
                dibujarBordeSyI (10,21);
                dibujarBordesDeI (10,20,20);
                dibujarBordesDeI (160,20,20);
                rlutil:: locate (40,20);
                cout << "ID POSTRES";
                rlutil:: locate (100,20);
                cout << "RECAUDACION";
                break;
            case 60:
                dibujarBordeSyI (10,19);
                dibujarBordeSyI (10,21);
                dibujarBordesDeI (10,20,20);
                dibujarBordesDeI (160,20,20);
                rlutil::setColor (rlutil::BROWN);
                rlutil:: locate (40,20);
                cout << "ID BEBIDAS";
                rlutil:: locate (100,20);
                cout << "RECAUDACION";
                break;

            case 80:
                rlutil::cls();
                salir=false;
                break;
            case 100:
                rlutil::cls();
                mostrarMenuPrincipal();
                break;
            }
            break;
        }
    }
    while (salir==true);

}

void mostrarRecaudacionesPorTipoDePedido()
{
    int x=0;
    bool salir=true;
    do
    {

        rlutil::hidecursor();
        rlutil::setColor (rlutil::LIGHTCYAN);
        dibujarBordesPantallas(42,16);
        rlutil::setColor (rlutil::BROWN);
        rlutil:: locate (50,15);
        cout << "R E C A U D A C I O N E S   P O R   T I P O   D E   P E D I D O";
        rlutil::setColor (rlutil::WHITE);
        rlutil:: locate (9+(x),17);
        cout << char (16);
        pintarOpciones("POR LOCAL",10,17, x==0);
        pintarOpciones("POR DELIVERY",40,17, x==30);
        pintarOpciones("POR TAKE AWAY",70,17, x==60);
        pintarOpciones("VOLVER A INFORMES",100,17, x==90);
        pintarOpciones("VOLVER A MENU PRINCIPAL",130,17, x==120);
        int key=rlutil::getkey();
        switch (key)
        {
        case 17:
            rlutil:: locate (9+(x),17);
            cout << " ";
            x+=30;
            if (x>120) x=120;

            break;
        case 16:
            rlutil:: locate (9+(x),17);
            cout << " ";
            x-=35;
            if (x<0) x=0;
            break;

        case 1:
            switch (x)
            {
            case 0:
                dibujarBordeSyI (10,19);
                dibujarBordeSyI (10,21);
                dibujarBordesDeI (10,20,20);
                dibujarBordesDeI (160,20,20);
                rlutil::setColor(rlutil::BROWN);
                rlutil:: locate (30,20);
                cout << "ID PEDIDOS POR LOCAL";
                rlutil:: locate (100,20);
                cout << "RECAUDACION";
                break;
            case 30:
                dibujarBordeSyI (10,19);
                dibujarBordeSyI (10,21);
                dibujarBordesDeI (10,20,20);
                dibujarBordesDeI (160,20,20);
                rlutil::setColor(rlutil::BROWN);
                rlutil:: locate (30,20);
                cout << "ID PEDIDOS POR DELIVERY";
                rlutil:: locate (100,20);
                cout << "RECAUDACION";
                break;
            case 60:
                dibujarBordeSyI (10,19);
                dibujarBordeSyI (10,21);
                dibujarBordesDeI (10,20,20);
                dibujarBordesDeI (160,20,20);
                rlutil::setColor(rlutil::BROWN);
                rlutil:: locate (30,20);
                cout << "ID PEDIDOS POR TAKE-AWAY";
                rlutil:: locate (100,20);
                cout << "RECAUDACION";
                break;
            case 90:
                rlutil::cls();
                salir=false;
                break;
            case 120:
                rlutil::cls();
                mostrarMenuPrincipal();
                break;
            }
            break;
        }
    }
    while (salir==true);
}

void mostrarRecaudacionesPorEmpleado()
{
    int x=0;
    bool salir=true;
    do
    {

        rlutil::hidecursor();
        rlutil::setColor (rlutil::LIGHTCYAN);
        dibujarBordesPantallas(42,16);
        rlutil::setColor (rlutil::BROWN);
        rlutil:: locate (55,15);
        cout << "R E C A U D A C I O N E S   P O R   E M P L E A D O S";
        rlutil::setColor (rlutil::WHITE);
        rlutil:: locate (33+(x),17);
        cout << char (16);
        pintarOpciones("POR ID",10,17, x==0);
        pintarOpciones("POR DNI",40,17, x==30);
        pintarOpciones("POR TURNO",70,17, x==60);
        pintarOpciones("VOLVER A INFORMES",100,17, x==90);
        pintarOpciones("VOLVER A MENU PRINCIPAL",130,17, x==120);
        int key=rlutil::getkey();
        switch (key)
        {
        case 17:
            rlutil:: locate (9+(x),17);
            cout << " ";
            x+=30;
            if (x>120) x=120;

            break;
        case 16:
            rlutil:: locate (9+(x),17);
            cout << " ";
            x-=30;
            if (x<0) x=0;
            break;

        case 1:
            switch (x)
            {
            case 0:
                rlutil:: locate (100,19);
                cout << "ACA IRIA EL <<EXCEL>> DE INFORMES RENDIMIENTO POR ID EMPLEADO";
                break;
            case 30:
                 rlutil:: locate (100,19);
                dibujarBordeSyI (10,19);
                dibujarBordeSyI (10,21);
                dibujarBordesDeI (10,20,20);
                dibujarBordesDeI (160,20,20);
                rlutil::setColor(rlutil::BROWN);
                rlutil:: locate (30,20);
                cout << "ID EMPLEADO POR DNI";
                rlutil:: locate (80,20);
                cout << "PEDIDOS A SU CARGO";
                rlutil:: locate (120,20);
                cout << "RECAUDACION";
                break;
            case 60:
                rlutil:: locate (100,19);
                dibujarBordeSyI (10,19);
                dibujarBordeSyI (10,21);
                dibujarBordesDeI (10,20,20);
                dibujarBordesDeI (160,20,20);
                rlutil::setColor(rlutil::BROWN);
                rlutil:: locate (30,20);
                cout << "ID EMPLEADO POR TURNO";
                rlutil:: locate (80,20);
                cout << "PEDIDOS A SU CARGO";
                rlutil:: locate (120,20);
                cout << "RECAUDACION";
                break;
            case 90:
                rlutil::cls();
                salir=false;
                break;
            case 120:
                rlutil::cls();
                mostrarMenuPrincipal();
                break;
            }
            break;
        }
    }
    while (salir==true);
}
