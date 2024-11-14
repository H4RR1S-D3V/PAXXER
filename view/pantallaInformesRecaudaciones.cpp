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
        dibujarBordesPantallas(80,16);
        rlutil::setColor (rlutil::BROWN);
        rlutil:: locate (90,15);
        cout << "R E C A U D A C I O N E S   P O R   F E C H A";
        rlutil::setColor (rlutil::WHITE);
        rlutil:: locate (99+(x),12);
        cout << char (16);
        //PODRIAMOS FILTRAR POR SEMANA O SINO FILTRAR POR DIA YQ UE TE MUESTRE TODOS LOS (POR EJ) MARTES DEL AÑO
        pintarOpciones("FILTRAR POR DIA",35,17, x==0);
        pintarOpciones("FILTRAR POR MES",70,17, x==35);
        pintarOpciones("FILTRAR POR AÑO",105,17, x==70);
        pintarOpciones("VOLVER A INFORMES",140,17, x==105);
        pintarOpciones("VOLVER A MENU PRINCIPAL",175,17, x==140);
        int key=rlutil::getkey();
        switch (key)
        {
        case 17:
            rlutil:: locate (33+(x),17);
            cout << " ";
            x+=35;
            if (x>140) x=140;

            break;
        case 16:
            rlutil:: locate (33+(x),17);
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

        dibujarBordesPantallas(80,16);
        rlutil::setColor (rlutil::BROWN);
        rlutil:: locate (90,15);
        cout << "R E C A U D A C I O N E S   P O R   I T E M S   D E   C A R T A";
        rlutil::setColor (rlutil::WHITE);
        rlutil:: locate (44+(x),17);
        cout << char (16);
        pintarOpciones("FILTRAR POR ENTRADA",45,17, x==0);
        pintarOpciones("FILTRAR POR P. PRINCIPAL",75,17, x==30);
        pintarOpciones("FILTRAR POR POSTRE",105,17, x==60);
        pintarOpciones("FILTRAR POR BEBIDA",135,17, x==90);
        pintarOpciones("VOLVER A INFORMES",165,17, x==120);
        pintarOpciones("VOLVER A MENU PRINCIPAL",195,17, x==150);
        int key=rlutil::getkey();
        switch (key)
        {
        case 17:
            rlutil:: locate (44+(x),17);
            cout << " ";
            x+=30;
            if (x>150) x=150;

            break;
        case 16:
            rlutil:: locate (44+(x),17);
            cout << " ";
            x-=30;
            if (x<0) x=0;
            break;

        case 1:
            switch (x)
            {
            case 0:
                rlutil:: locate (100,19);
                cout << "ACA IRIA EL <<EXCEL>> DE RECAUDACIONES POR ENTRADAS";
                break;
            case 30:
                rlutil:: locate (100,19);
                cout << "ACA IRIA EL <<EXCEL>> DE RECAUDACIONES POR PLATO PRINCIPAL";
                break;
            case 60:
                rlutil:: locate (100,19);
                cout << "ACA IRIA EL <<EXCEL>> DE RECAUDACIONES POR POSTRES";
                break;
            case 90:
                rlutil:: locate (100,19);
                cout << "ACA IRIA EL <<EXCEL>> DE RECAUDACIONES POR BEBIDA";
                break;

            case 120:
                rlutil::cls();
                salir=false;
                break;
            case 150:
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
        dibujarBordesPantallas(80,16);
        rlutil::setColor (rlutil::BROWN);
        rlutil:: locate (90,15);
        cout << "R E C A U D A C I O N E S   P O R   T I P O   D E   P E D I D O";
        rlutil::setColor (rlutil::WHITE);
        rlutil:: locate (33+(x),17);
        cout << char (16);
        pintarOpciones("FILTRAR POR LOCAL",35,17, x==0);
        pintarOpciones("FILTRAR POR DELIVERY",70,17, x==35);
        pintarOpciones("FILTRAR POR TAKE AWAY",105,17, x==70);
        pintarOpciones("VOLVER A INFORMES",140,17, x==105);
        pintarOpciones("VOLVER A MENU PRINCIPAL",175,17, x==140);
        int key=rlutil::getkey();
        switch (key)
        {
        case 17:
            rlutil:: locate (33+(x),17);
            cout << " ";
            x+=35;
            if (x>140) x=140;

            break;
        case 16:
            rlutil:: locate (33+(x),17);
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
            case 35:
                rlutil:: locate (100,19);
                cout << "ACA IRIA EL <<EXCEL>> DE RECAUDACIONES POR DELIVERY";
                break;
            case 70:
                rlutil:: locate (100,19);
                cout << "ACA IRIA EL <<EXCEL>> DE RECAUDACIONES POR TAKE AWAY";
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

void mostrarRecaudacionesPorEmpleado()
{
    int x=0;
    bool salir=true;
    do
    {

        rlutil::hidecursor();
        rlutil::setColor (rlutil::LIGHTCYAN);
        dibujarBordesPantallas(80,16);
        rlutil::setColor (rlutil::BROWN);
        rlutil:: locate (90,15);
        cout << "R E C A U D A C I O N E S   P O R   E M P L E A D O S";
        rlutil::setColor (rlutil::WHITE);
        rlutil:: locate (33+(x),17);
        cout << char (16);
        pintarOpciones("FILTRAR POR ID",35,17, x==0);
        pintarOpciones("FILTRAR POR DNI",70,17, x==35);
        pintarOpciones("FILTRAR POR TURNO",105,17, x==70);
        pintarOpciones("VOLVER A INFORMES",140,17, x==105);
        pintarOpciones("VOLVER A MENU PRINCIPAL",175,17, x==140);
        int key=rlutil::getkey();
        switch (key)
        {
        case 17:
            rlutil:: locate (33+(x),17);
            cout << " ";
            x+=35;
            if (x>140) x=140;

            break;
        case 16:
            rlutil:: locate (33+(x),17);
            cout << " ";
            x-=35;
            if (x<0) x=0;
            break;

        case 1:
            switch (x)
            {
            case 0:
                rlutil:: locate (100,19);
                cout << "ACA IRIA EL <<EXCEL>> DE INFORMES RENDIMIENTO POR ID EMPLEADO";
                break;
            case 35:
                rlutil:: locate (100,19);
                cout << "ACA IRIA EL <<EXCEL>> DE INFORMES RENDIMIENTO POR DNI";
                break;
            case 70:
                rlutil:: locate (100,19);
                cout << "ACA IRIA EL <<EXCEL>> DE INFORMES RENDIMIENTO POR TURNO";
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
