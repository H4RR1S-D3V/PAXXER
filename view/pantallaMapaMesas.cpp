#include <iostream>
#include "../rlutil.h"
#include "windows.h"
//#include <vector>

using namespace std;

#include "menuPrincipal.h"
#include "declaracionOpcionesMapaMesas.h"
#include "funcionesDibujar.h"
#include "../controller/clasesArchivos.h"
#include "pantallaDelivery.h"



void mostrarMapaMesas()
{

    rlutil::cls();
    ArchivoMesasLocal arcMesa;

    bool salir = true;

    int x=0;
    do
    {
        rlutil::setColor (rlutil::MAGENTA);
        dibujarTituloMAPAMESAS();
        rlutil::setColor (rlutil::WHITE);

///CONTENEDOR MESAS

        int posXInicial = 20; //X
        int posYInicial = 9; //Y
        int altoMesa = 12;   //Y
        int anchoMesa = 30; //X
        int posX;
        int posY;
        int cantMesas = arcMesa.contarRegistros();
        for (int i = 0; i < cantMesas; i++)
        {
            posX = posXInicial + (i % 5) * anchoMesa;
            posY = posYInicial + (i / 5) * altoMesa;
            Local mesa;
            mesa = arcMesa.leerRegistro(i);
            int nroMesa = mesa.getNumero();

            if (mesa.getDisponibilidad())
            {
                rlutil::setColor (rlutil::GREEN);
            }

            else
            {

                rlutil::setColor (rlutil::LIGHTRED);
            }
            dibujarMesa(posX, posY);
            rlutil::setColor(rlutil::WHITE);
            rlutil::locate(posX +4, posY+8);
            cout << "MESA " << nroMesa;
            // posicionesX.push_back(posX);
            //posicionesY.push_back(posY);

        }

        rlutil::setColor(rlutil::BROWN);
        dibujarBordeSyI(11,7);
        dibujarBordeSyI(11,33);


        rlutil::locate(40,19);
        rlutil::setColor(rlutil::GREEN);
        cout <<"DISPONIBLE";
        rlutil::locate(51,19);
        cout<<char (176)<<char (177)<<char (178);
        rlutil::locate(100,19);
        rlutil::setColor(rlutil::LIGHTRED);
        cout<< "OCUPADA";
        rlutil::locate(108,19);
        cout<<char (176)<<char (177)<<char (178);
        rlutil::setColor(rlutil::WHITE);

        pintarOpciones("SELECCIONAR MESA",30,35,x==0);
        pintarOpciones("VER DELIVERIES",60,35,x==30);
        pintarOpciones("VER TAKE AWAYS",90,35,x==60);
        pintarOpciones("VOLVER A MENU PRINCIPAL",120,35, x==90);

        rlutil:: locate (29+x,35);
        cout << char (16);
        int key=rlutil::getkey();
        rlutil::locate(29 + x, 35);
        cout << " ";

        int nroMesaSeleccionada;

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
            case 0:///INICIA PEDIDO LOCAL
            {
                //pedir nro mesa
                rlutil:: locate (55,37);
                cout << "PORFAVOR ESCRIBA EL NUMERO DE MESA A SELECCIONAR";
                rlutil:: locate (65,41);
                cout << "PRESIONE ENTER PARA CONTINUAR";
                rlutil::showcursor();
                rlutil:: locate (78,39);
                cin >> nroMesaSeleccionada;
                rlutil::cls();
                salir=false;
                Local obj;
                obj = arcMesa.leerRegistro(nroMesaSeleccionada-1);
                obj.abrirMesa();
                break;
            }
            case 30:///DIRIGE A PANTALLA DELIVERIES
            {
                rlutil::cls();
                pantallaDelivery();
                break;
            }
            case 60:///DIRIGE A PANTALLA TAKE AWAY
            {
                rlutil::cls();
                ArchivoTakeAway arcTake;
                arcTake.listarRegistros();
                system("pause");

                break;
            }
            case 90:///VUELVE A MENU PRINCIPAL
            {

                rlutil::cls();
                salir=false;
                mostrarMenuPrincipal();
                break;
            }
            }
            break;
        }


    }
    while (salir==true);
}



void armarFactura()
{
///ACA SE ARMARIAN TODAS LAS FACTURAS??
///DIVIDIRLO EN FUNCIONES ESPECIFICAS??
}

void mostrarPedidosEnCurso()
{
///PÁNTALLA DONDE ESTEN LISTADOS TODOS LOS PEDIDOS SIN CONCLUIR- UNA VEZ TERMINADOS/ENTREGADOS DESAPARECEN
}
