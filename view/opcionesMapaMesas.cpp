#include <iostream>
#include "../rlutil.h"
#include "windows.h"

using namespace std;
#include "declaracionOpcionesMapaMesas.h"
#include "funcionesDibujar.h"
#include "pantallasMenuPrincipal.h"

void seleccionarTipoPedido()
{
    int x=0;
    char tipoPedido[10]; //SOLO TEMPORAL-PARA PROBAR
    rlutil:: locate (94+x,38);
    cout << char (16);
    int key=rlutil::getkey();
    rlutil::locate(94 + x, 38);
    cout << " ";
    rlutil::locate(95,37);
    cout << "SELECCIONE EL TIPO DE PEDIDO: ";
    rlutil::locate(95,38);
    cout << "LOCAL";
    rlutil::locate(115,38);
    cout << "DELIVERY";
    rlutil::locate(135,38);
    cout << "TAKE-AWAY";

    switch (key)
    {
    case 17:
        x+=20;
        if (x>40) x=40;
        break;
    case 16:
        x-=20;
        if (x<0) x=0;
        break;
    case 1:
        switch (x)
        {
        case 0:
            strcpy(tipoPedido, "LOCAL");
            // armarPedidoLocal();
            break;
        case 20:
            //strcpy(tipoPedido, "DELIVERY");
            // armarPedidoDelivery();
            break;
        case 40:
            // strcpy(tipoPedido, "TAKE-AWAY");
            // armarPedidoTakeAway();
            break;
        }
    }
}

void armarPedidoLocal()
{
    bool salir = true;
    int y=0;
    do
    {

        ///MOSTRAR NUM MESA ELEGIDA
        rlutil::hidecursor();
        rlutil::setColor(rlutil::LIGHTCYAN);
        dibujarBordesPantallas(42,8);
        dibujarBordesPantallas(42,10);
        rlutil::setColor(rlutil::BROWN);
        rlutil:: locate (57,9);
        cout << "TIPO DE PEDIDO LOCAL - MESA NUMERO X SELECCIONADA";
        rlutil:: locate (40,12);
         rlutil::setColor(rlutil::WHITE);
        cout << "PORFAVOR INGRESE SU ID DE EMPLEADO: ";
        rlutil:: locate (40,13);
        cout << "PORFAVOR INGRESE LA CANTIDAD DE COMENSALES: ";
        ///PEDIR CONFIRMACION Y QUE ESO LLEVE A MOSTRAR VISTA MESA
        rlutil:: locate (57,15);
        cout << "CONFIRMA QUE LOS DATOS INGRESADOS SON CORRECTOS?";
        pintarOpciones("SI",78,16,y==0);
        pintarOpciones("NO",78,17,y==1);
        pintarOpciones("VOLVER A MAPA MESAS",78,18,y==2);


        rlutil:: locate (77,16+y);
        cout << char (16);
        int key=rlutil::getkey();
        rlutil::locate(77, 16+y);
        cout <<" ";

        switch (key)
        {
        case 15:
            y+=1;
            if (y>2) y=2;
            break;
        case 14:
            y-=1;
            if (y<0) y=0;
            break;
        case 1:
            switch (y)
            {
            case 0: //si
                rlutil::cls();
                mostrarVistaMesa();
                break;
            case 1: //no
                rlutil::cls();
                armarPedidoLocal();
                break;
            case 2://volver
                rlutil::cls();
                salir=false;
                mostrarMapaMesas();
                break;
            }

        }
    }
    while(salir==true);
}
void mostrarVistaMesa()
{
    bool salir = true;
    int x=0;
    do
    {
        rlutil::hidecursor();
         rlutil::setColor(rlutil::LIGHTCYAN);
        dibujarBordeSyI(10,3);
        dibujarBordeSyI(10,6);
        rlutil::locate(22, 4);
         rlutil::setColor(rlutil::BROWN);
        cout<<"NRO. MESA";
        rlutil::locate(52, 4);
        cout <<"EMPLEADO ASIGNADO";
        rlutil::locate(100, 4);
        cout <<"TURNO";
        rlutil::locate(135, 4);
        cout <<"CANT. COMENSALES";
 rlutil::setColor(rlutil::WHITE);
        pintarOpciones("CARGAR ITEM",30, 8, x==0);
        pintarOpciones("QUITAR ITEM",60, 8,x==30);
        pintarOpciones("CERRAR MESA",90, 8, x==60);
        pintarOpciones("VOLVER A MAPA",120, 8, x==90);

 rlutil::setColor(rlutil::MAGENTA);
        dibujarBordeSyI(10,10);
        dibujarBordeSyI(10,12);
        ///PARA MODIFICAR EL LARGO SOLAMENTE SUMARLE AL ULTIMO NUM(EJ: 20+Y(Y=1)
        dibujarBordesDeI(9,11,30);
        dibujarBordesDeI(160,11,30);
        ///
 rlutil::setColor(rlutil::LIGHTCYAN);
        rlutil::locate(12, 11);
        cout<<"NRO."; //POSICIONAR SU COUT EN EL 13,12
        rlutil::locate(52, 11);
        cout <<"NOMBRE"; //POSICIONAR SU COUT A PARTIR DEL 16,12
        rlutil::locate(100, 11);
        cout <<"CANTIDAD";
        rlutil::locate(122, 11);
        cout <<"PRECIO";
        rlutil::locate(135, 11);
        cout <<"SUB-TOTAL";
        rlutil::locate(152, 11);
        cout <<"TOTAL";


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
            case 0://CARGAR
                rlutil::cls();
                cargarItem();
                break;
            case 30://QUITAR
                break;
            case 60://CERRAR MESA
                break;
            case 90://VOLVER
                rlutil::cls();
                salir=false;
                mostrarMapaMesas();
                break;
            }
            break;
        }
    }
    while (salir==true);
}

void cargarItem()
{
    int x=0;
    bool salir=true;
do{
rlutil::hidecursor();
 rlutil::setColor(rlutil::LIGHTCYAN);
dibujarBordesPantallas(42,2);
dibujarBordesPantallas(42,4);
 rlutil::setColor(rlutil::BROWN);
rlutil::locate(62, 3);
        cout<<"F  I  L  T  R  A  R     P  L  A  T O";

 rlutil::setColor(rlutil::WHITE);
        pintarOpciones("POR ENTRADA",10, 5, x==0);
        pintarOpciones("POR PLATO PRINCIPAL",40, 5,x==30);
        pintarOpciones("POR POSTRE",70, 5, x==60);
        pintarOpciones("POR BEBIDA",100, 5, x==90);
        pintarOpciones("VOLVER A PANTALLA ANTERIOR",130, 5, x==120);

 rlutil::setColor(rlutil::MAGENTA);
        dibujarBordeSyI(10,8);
        dibujarBordeSyI(10,10);
        ///PARA MODIFICAR EL LARGO SOLAMENTE SUMARLE AL ULTIMO NUM(EJ: 20+Y(Y=1)
        dibujarBordesDeI(9,9,30);
        dibujarBordesDeI(160,9,30);
 rlutil::setColor(rlutil::LIGHTCYAN);
        rlutil::locate(12, 9);
        cout<<"NRO."; //POSICIONAR SU COUT EN EL 13,12
        rlutil::locate(52, 9);
        cout <<"NOMBRE"; //POSICIONAR SU COUT A PARTIR DEL 16,12
        rlutil::locate(100, 9);
        cout <<"CANTIDAD";
        rlutil::locate(122, 9);
        cout <<"PRECIO";
        rlutil::locate(135, 9);
        cout <<"SUB-TOTAL";
        rlutil::locate(152, 9);
        cout <<"TOTAL";


 rlutil::setColor(rlutil::WHITE);
        rlutil:: locate (9+x,5);
        cout << char (16);
        int key=rlutil::getkey();
        rlutil::locate(9 + x, 5);
        cout << " ";
        switch (key)
        {
        case 17:
            x+=30;
            if (x>120) x=120;
            break;
        case 16:
            x-=30;
            if (x<0) x=0;
            break;
        case 1:
            switch (x)
            {
            case 0://ENTRADA
                break;
            case 30://P. PRINCIPAL
                break;
            case 60://POSTRE
                break;
                  case 90://BEBIDA
                break;
            case 120://VOLVER
                rlutil::cls();
                salir=false;
                mostrarVistaMesa();
                break;
            }
            break;
        }

}while (salir==true);
}

void quitarItem()
{
    int y = 0;
    int posItem, cantItem;
 bool salir=true;
do{

dibujarBordesPantallas(42,2);
dibujarBordesPantallas(42,4);

rlutil::setColor(rlutil::WHITE);
rlutil::locate(58, 3);
 cout<<"PORFAVOR INGRESE LA POSICION DEL ITEM A ELIMINAR";
  rlutil::locate(60, 7);
 cout<<"UNA VEZ FINALICE PRESIONE ENTER PARA CONTINUAR";
 rlutil::locate(80, 5);
//cin.getline() >> posItem;

dibujarBordesPantallas(42,9);
dibujarBordesPantallas(42,11);
rlutil::locate(58, 10);
 cout<<"PORFAVOR INGRESE LA CANTIDAD DE ITEMS A ELIMINAR";
  rlutil::locate(60, 14);
 cout<<"UNA VEZ FINALICE PRESIONE ENTER PARA CONTINUAR";
 rlutil::locate(80, 12);
//cin.getline>> cantItem;

//cin.ignore();

rlutil::hidecursor();
 rlutil::setColor(rlutil::MAGENTA);
        dibujarBordeSyI(10,16);
        dibujarBordeSyI(10,18);
         dibujarBordeSyI(10,23);
        ///PARA MODIFICAR EL LARGO SOLAMENTE SUMARLE AL ULTIMO NUM(EJ: 20+Y(Y=1)
        dibujarBordesDeI(9,17,5);
        dibujarBordesDeI(160,17,5);
 rlutil::setColor(rlutil::LIGHTCYAN);
        rlutil::locate(12, 17);
        cout<<"NRO."; //POSICIONAR SU COUT EN EL 13,12
        rlutil::locate(80, 17);
        cout <<"NOMBRE"; //POSICIONAR SU COUT A PARTIR DEL 16,12
        rlutil::locate(130, 17);
        cout <<"CANTIDAD";

      rlutil::locate(70, 25);
 cout << "ESTA SEGURO DE ELIMINAR EL ITEM NRO X?";
        pintarOpciones("SI",78,26,y==0);
        pintarOpciones("NO",78,27,y==1);
        pintarOpciones("CANCELAR OPERACION Y VOLVER A PANTALLA ANTERIOR",78,28,y==2);

 rlutil::setColor(rlutil::WHITE);
      rlutil:: locate (77,26+y);
        cout << char (16);
        int key = rlutil::getkey();
        rlutil::locate(77, 26+y);

        switch (key)
        {
        case 14:
            y+=1;
            if (y>2) y=2;

            break;
        case 15:
            y-=1;
            if (y<0) y=0;

            break;
        case 1:
            switch (y)
            {
            case 0://si
                break;
            case 1://no
                  rlutil::cls();
                  quitarItem();
                break;
            case 2://cancelar y volver

                rlutil::cls();
                salir=false;
                mostrarVistaMesa();
                break;
            }
            break;
        }

}while (salir==true);
}

