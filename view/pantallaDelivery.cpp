#include <iostream>

#include "../rlutil.h"
#include "funcionesDibujar.h"
#include "../controller/clasesArchivosMesas.h"


using namespace std;

#include "pantallaDelivery.h"

void pantallaDelivery()
{

/*
    rlutil::cls();

    rlutil::hidecursor();
    rlutil::setColor(rlutil::LIGHTCYAN);
    dibujarBordeSyI(10,3);
    dibujarBordeSyI(10,6);
    rlutil::setColor(rlutil::BROWN);
    rlutil::locate(15, 5);
    cout<<"NRO.";
    rlutil::locate(45, 5);
    cout <<"DIRECCION";
    rlutil::locate(75, 5);
    cout <<"ID REPARTIDOR";
    rlutil::locate(105, 5);
    cout <<"HORA ENTREGA";
    rlutil::locate(135, 5);
    cout <<"IMPORTE";

    ArchivoDelivery arc;
    arc.listarRegistros();

    rlutil::setColor(rlutil::WHITE);



    pintarOpciones("AGREGAR DELIVERY",30, 8, x==0);
    pintarOpciones("CERRAR DELIVERY",60, 8,x==30);
    pintarOpciones("ABRIR DEÑIVERY",90, 8, x==60);
    pintarOpciones("VOLVER A MAPA",120, 8, x==90);

    system("pause");
*/

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
}
