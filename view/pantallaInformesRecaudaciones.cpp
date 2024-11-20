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
        pintarOpciones("FILTRAR POR AÑO",80,17, x==70);
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
                rlutil:: locate (100,19);
                cout << "ACA IRIA EL <<EXCEL>> DE RECAUDACIONES POR MES";
                break;
            case 70:
                rlutil:: locate (100,19);
                cout << "ACA IRIA EL <<EXCEL>> DE RECAUDACIONES POR AÑO";
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
                rlutil:: locate (100,19);
                cout << "ACA IRIA EL <<EXCEL>> DE RECAUDACIONES POR ENTRADAS";
                break;
            case 20:
                rlutil:: locate (100,19);
                cout << "ACA IRIA EL <<EXCEL>> DE RECAUDACIONES POR PLATO PRINCIPAL";
                break;
            case 40:
                rlutil:: locate (100,19);
                cout << "ACA IRIA EL <<EXCEL>> DE RECAUDACIONES POR POSTRES";
                break;
            case 60:
                rlutil:: locate (100,19);
                cout << "ACA IRIA EL <<EXCEL>> DE RECAUDACIONES POR BEBIDA";
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
                rlutil:: locate (100,19);
                cout << "ACA IRIA EL <<EXCEL>> DE RECAUDACIONES POR LOCAL";
                break;
            case 30:
                rlutil:: locate (100,19);
                cout << "ACA IRIA EL <<EXCEL>> DE RECAUDACIONES POR DELIVERY";
                break;
            case 60:
                rlutil:: locate (100,19);
                cout << "ACA IRIA EL <<EXCEL>> DE RECAUDACIONES POR TAKE AWAY";
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
            rlutil:: locate (33+(x),17);
            cout << " ";
            x+=30;
            if (x>120) x=120;

            break;
        case 16:
            rlutil:: locate (30+(x),17);
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
                cout << "ACA IRIA EL <<EXCEL>> DE INFORMES RENDIMIENTO POR DNI";
                break;
            case 60:
                rlutil:: locate (100,19);
                cout << "ACA IRIA EL <<EXCEL>> DE INFORMES RENDIMIENTO POR TURNO";
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
