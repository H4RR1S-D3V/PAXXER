#include <iostream>

#include "../rlutil.h"
#include "funcionesDibujar.h"
#include "../controller/clasesArchivosMesas.h"


using namespace std;

#include "pantallaDelivery.h"
#include "pantallasMenuPrincipal.h"

void pantallaDelivery()
{
    bool salir = true;
    int x=0;
    do
    {
        rlutil::hidecursor();

        ///CUADRO INFERIOR
        rlutil::setColor(rlutil::MAGENTA);
        dibujarBordeSyI(10,15);
        dibujarBordeSyI(10,17);
        dibujarBordesDeI(9,16,30);
        dibujarBordesDeI(160,16,30);
        rlutil::setColor(rlutil::LIGHTCYAN);
        rlutil::locate(13, 16);
        cout <<"#";
        rlutil::locate(20, 16);
        cout <<"DIRECCION DE ENTREGA ";
        rlutil::locate(64, 16);
        cout <<"RESPONSABLE";
        rlutil::locate(95, 16);
        cout <<"HORA ENTREGA";
        rlutil::locate(128, 16);
        cout <<"TOTAL";
        rlutil::locate(150, 16);
        cout <<"ESTADO";


        ArchivoDelivery arc;

        arc.listarRegistros(18);

        rlutil::setColor(rlutil::WHITE);

        pintarOpciones("AGREGAR DELIVERY",30, 8, x==0);
        pintarOpciones("CERRAR DELIVERY",60, 8,x==30);
        pintarOpciones("ABRIR DELIVERY",90, 8, x==60);
        pintarOpciones("VOLVER A MAPA MESAS",120, 8, x==90);


        rlutil::setColor(rlutil::WHITE);
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
            case 0://AGREGAR DELIVERY
            {
                int cantRegistros = arc.contarRegistros();
                Delivery obj(cantRegistros + 1);
                obj.cargarDelivery();
                arc.agregarRegistro(obj);
                rlutil::cls();
                obj.abrirMesa();
                break;
            }
            break;
            case 30://CERRAR DELIVERY
                break;
            case 60://ABRIR DELIVERY
            {
                int pos;
                rlutil::locate (10,10);
                cout << "INGRESE DELIVERY A ABRIR: ";
                cin >> pos;

                Delivery obj;
                obj = arc.leerRegistro(pos-1);
                rlutil::cls();
                obj.abrirMesa();
                break;
            }
            break;
            case 90://VOLVER A MAPA

                rlutil::cls();
                salir = false;
                mostrarMapaMesas();
                break;
            }

        }

    }
    while (true);

    /*
        ArchivoDelivery arc;

        cout << "# | ";
        cout << "DIRECCION DE ENTREGA | ";
        cout << "RESPONSALBLE | ";
        cout << "HORA DE ENTREGA | ";
        cout << "TOTAL | " << endl;
        cout << "-------------------------------------------------------------------" << endl;

        arc.listarRegistros();

        int opcion;

        cout << "SELECCIONAR OPCION: (1-AGREGAR DELIVERY 2-ABRIR DELIVERY 3-VOLVER) ";
        cin >> opcion;

        switch(opcion)
        {
        case 1:
            {
                int cantRegistros = arc.contarRegistros();
                Delivery obj(cantRegistros + 1);
                obj.cargarDelivery();
                arc.agregarRegistro(obj);
                system("cls");
                obj.abrirMesa();
                break;
            }
        case 2:
            {
                int pos;
                cout << "INGRESE DELIVERY A ABRIR: ";
                cin >> pos;

                Delivery obj;
                obj = arc.leerRegistro(pos-1);
                system("cls");
                obj.abrirMesa();
                break;
            }
        case 3:
            system("cls");
            return;
        default:
            cout << "INGRESE UNA OPCION VALIDA";
            system("pause");
        }
    */
}
