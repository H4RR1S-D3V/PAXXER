#include <iostream>

#include "../rlutil.h"
#include "funcionesDibujar.h"
#include "../controller/clasesArchivosMesas.h"

using namespace std;

#include "pantallaDelivery.h"
#include "pantallasMenuPrincipal.h"

void pantallaDelivery()
{
    int x = 0;
    do
    {
        rlutil::hidecursor();

        /// OPCIONES
        rlutil::setColor(rlutil::WHITE);
        pintarOpciones("AGREGAR DELIVERY",40, 8, x==0);
        pintarOpciones("ABRIR DELIVERY",80, 8,x==40);
        pintarOpciones("VOLVER A MAPA MESAS",120, 8, x==80);

        /// CUADRO
        rlutil::setColor(rlutil::MAGENTA);
        dibujarBordeSyI(10,18);
        dibujarBordeSyI(10,20);
        dibujarBordesDeI(9,19,30);
        dibujarBordesDeI(160,19,30);
        rlutil::setColor(rlutil::LIGHTCYAN);
        rlutil::locate(13, 19);
        cout <<"#";
        rlutil::locate(20, 19);
        cout <<"DIRECCION DE ENTREGA ";
        rlutil::locate(64, 19);
        cout <<"RESPONSABLE";
        rlutil::locate(95, 19);
        cout <<"HORA ENTREGA";
        rlutil::locate(128, 19);
        cout <<"TOTAL";
        rlutil::locate(150, 19);
        cout <<"ESTADO";

        /// MOSTRAR DELIVERIES EN CURSO
        ArchivoDelivery arc;
        arc.listarRegistros(21);

        /// MEN� DE OPCIONES
        rlutil::setColor(rlutil::WHITE);
        rlutil::locate(29+x,8);
        cout << char (16);
        int key = rlutil::getkey();
        rlutil::locate(29+x, 8);
        cout << " ";
        switch(key)
        {
        case 17:
            x+=40;
            if(x>80) x=80;
            break;
        case 16:
            x-=40;
            if(x<0) x=0;
            break;
        case 1:
            switch(x)
            {
            case 0:     //AGREGAR DELIVERY
            {
                int cantRegistros = arc.contarRegistros();
                Delivery obj(cantRegistros + 1);
                obj.cargarDelivery();
                arc.agregarRegistro(obj);
                rlutil::cls();
                obj.abrirMesa();
                break;
            }
            case 40:    //ABRIR DELIVERY
            {
                int pos;
                rlutil::locate (10,10);
                cout << "INGRESE DELIVERY A ABRIR: ";
                cin >> pos;

                if(pos > arc.contarRegistros() || pos < 1)
                {
                    rlutil::cls();
                    rlutil::locate(10, 9);
                    rlutil::setColor(rlutil::RED);
                    cout << "DELIVERY INVALIDO, INGRESE NUEVAMENTE" << endl;
                    break;
                }
                Delivery obj;
                obj = arc.leerRegistro(pos-1);
                rlutil::cls();
                obj.abrirMesa();
                break;
            }
            case 80:    //VOLVER A MAPA
            {
                rlutil::cls();
                mostrarMapaMesas();
                break;
            }
            }
        }
    }
    while(true);
}
