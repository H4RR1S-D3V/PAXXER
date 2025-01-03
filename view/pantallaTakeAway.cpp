#include <iostream>

#include "../rlutil.h"
#include "funcionesDibujar.h"
#include "../controller/clasesArchivosMesas.h"

using namespace std;

#include "pantallaTakeAway.h"
#include "pantallasMenuPrincipal.h"

void pantallaTakeAway()
{
    int x = 0;
    do
    {
        rlutil::hidecursor();
        rlutil::setColor (rlutil::LIGHTCYAN);
        dibujarBordesPantallas(42,3);
        dibujarBordesPantallas(42,5);
        rlutil::setColor (rlutil::BROWN);
        rlutil::locate(75, 4);
        cout << "T A K E - A W A Y";

        /// OPCIONES
        rlutil::setColor(rlutil::WHITE);
        pintarOpciones("ABRIR TAKEAWAY",35, 8,x==0);
        pintarOpciones("AGREGAR TAKEAWAY",75, 8, x==40);
        pintarOpciones("VOLVER A MAPA MESAS",115, 8, x==80);

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
        cout <<"NOMBRE CLIENTE ";
        rlutil::locate(64, 19);
        cout <<"TELEFONO CLIENTE";
        rlutil::locate(95, 19);
        cout <<"HORA RETIRO";
        rlutil::locate(128, 19);
        cout <<"TOTAL";
        rlutil::locate(150, 19);
        cout <<"ESTADO";

        /// MOSTRAR TAKEAWAYS EN CURSO
        ArchivoTakeAway arc;
        arc.listarRegistros(21);

        /// MENU DE OPCIONES
        rlutil::setColor(rlutil::WHITE);
        rlutil::locate(34+x,8);
        cout << char(16);
        int key = rlutil::getkey();
        rlutil::locate(34+x, 8);
        cout << " ";
        switch (key)
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
            switch (x)
            {
            case 40:     //AGREGAR TAKE AWAY
            {
                int cantRegistros = arc.contarRegistros();
                TakeAway obj(cantRegistros + 1);
                obj.cargarTakeAway();
                arc.agregarRegistro(obj);
                rlutil::cls();
                obj.abrirMesa();
                break;
            }
            case 0:    //ABRIR TAKEAWAY
            {
                int pos;
                rlutil::locate (10,10);
                cout << "INGRESE TAKEAWAY A ABRIR: ";
                cin >> pos;

                if(pos > arc.contarRegistros() || pos < 1)
                {
                    rlutil::cls();
                    rlutil::locate(10, 9);
                    rlutil::setColor(rlutil::RED);
                    cout << "TAKEAWAY INVALIDO, INGRESE NUEVAMENTE" << endl;
                    cin.clear();
                    cin.ignore(1000, '\n');
                    break;
                }
                TakeAway obj;
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
            rlutil::cls();
            }
            break;
        }
    }
    while(true);
}

