#include <iostream>
#include "../rlutil.h"
#include "windows.h"
//#include <vector>

using namespace std;

#include "pantallasMenuPrincipal.h"
#include "declaracionOpcionesMapaMesas.h"
#include "funcionesDibujar.h"
#include "../controller/clasesArchivos.h"
#include "../controller/clases.h"



void mostrarMapaMesas()
{

    rlutil::cls();
ArchivoMesasLocal arcMesa;
arcMesa.setearCantMesas(20);
Local prueba(12);
prueba.cargarMesa();
arcMesa.actualizarMesa(prueba);

    bool salir = true;

    int x=0;
    do
    {
        rlutil::setColor (rlutil::MAGENTA);
        dibujarTituloMAPAMESAS();
        rlutil::setColor (rlutil::WHITE);
  //  vector<int> posicionesX;
    //vector<int> posicionesY;

///CONTENEDOR MESAS

 int posXInicial = 47; //X
    int altoMesa = 12;   //Y
    int posYInicial = 9; //Y
    int anchoMesa = 30; //X
int cantMesas = arcMesa.contarRegistros();
    for (int i = 0; i < cantMesas; i++) {
        int posX = posXInicial + (i % 5) * anchoMesa;
        int posY = posYInicial + (i / 5) * altoMesa;
Local mesa;
mesa = arcMesa.leerRegistro(i);
if (mesa.getDisponibilidad()){
     rlutil::setColor (rlutil::GREEN);
}

else{

       rlutil::setColor (rlutil::LIGHTRED);
}
       dibujarMesa(posX, posY);
       // posicionesX.push_back(posX);
        //posicionesY.push_back(posY);

    }

        /*dibujarMesa(47,9);
        dibujarMesa(113,9);
        dibujarMesa(80,9);
        dibujarMesa(145,9);
        dibujarMesa(180,9);

///MESAS INFERIORES
        dibujarMesa(47,25);
        dibujarMesa(113,25);
        dibujarMesa(80,25);
        dibujarMesa(145,25);
        dibujarMesa(180,25);


///NUMEROS MESAS
        rlutil::setColor(rlutil::WHITE);
        rlutil::locate(52,8);
        cout << "MESA 1";
        rlutil::locate(85,8);
        cout << "MESA 2";
        rlutil::locate(118,8);
        cout << "MESA 3";
        rlutil::locate(150,8);
        cout << "MESA 4";
        rlutil::locate(185,8);
        cout << "MESA 5";
        rlutil::locate(52,24);
        cout << "MESA 6";
        rlutil::locate(85,24);
        cout << "MESA 7";
        rlutil::locate(118,24);
        cout << "MESA 8";
        rlutil::locate(150,24);
        cout << "MESA 9";
        rlutil::locate(185,24);
        cout << "MESA 10";
        rlutil::setColor(rlutil::BROWN);

        dibujarBordeSyI(45,7);
        dibujarBordeSyI(45,33);
        */

        rlutil::locate(96,20);
        rlutil::setColor(rlutil::GREEN);
        cout <<"DISPONIBLE";
        rlutil::locate(92,20);
        cout<<char (176)<<char (177)<<char (178);
        rlutil::locate(135,20);
        rlutil::setColor(rlutil::LIGHTRED);
        cout<< "OCUPADA";
        rlutil::locate(131,20);
        cout<<char (176)<<char (177)<<char (178);
        rlutil::setColor(rlutil::WHITE);

pintarOpciones("NUEVO PEDIDO",70,35,x==0);
pintarOpciones("VER PEDIDOS EN CURSO",110,35,x==40);
pintarOpciones("VOLVER A MENU PRINCIPAL",150,35, x==80);

     rlutil:: locate (69+x,35);
        cout << char (16);
    int key=rlutil::getkey();
    rlutil::locate(69 + x, 35);
    cout << " ";
switch (key)
    {
    case 17:
        x+=40;
        if (x>80) x=80;
            break;
        case 16:
            x-=40;
            if (x<0) x=0;
            break;
        case 1:
            switch (x)
            {
            case 0:///INICIA PEDIDO
                //seleccionarTipoPedido();
                break;
            case 40:///DIRIGE A PANTALLA PEDIDOS
                rlutil::cls();
                salir=false;
             mostrarPantallaPedidos();
                break;
            case 80:///VUELVE A MENU PRINCIPAL

                break;
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
