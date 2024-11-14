#include <iostream>
#include "../rlutil.h"
#include "windows.h"

using namespace std;
#include "declaracionOpcionesMapaMesas.h"
#include "funcionesDibujar.h"

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
/*
void armarPedidoLocal(tipoPedido)
{
    cout << "TIPO PEDIDO: "<< tipoPedido;
//MOSTRAR EL TIPO PEDIDO
//INGRESE ID EMPLEADO/CAMARERO
//INGRESE CANT. COMENSALES
//ELEGIR MESA
//VERIFICAR SI LA MESA ESTA DISPONIBLE
//PREGUNTAR SIE STA SEGURO DE LA ELECCION
//CAMBIAR ESTADO MESA
//ABRIR MESA--> LLEVA A VISTA DE MESA
}

void mostrarVistaMesa()
{
//MESA ELEGIDA
//ARMAR PEDIDO: AGREGAR ITEMS A ELECCION
//PREGUNTAR SI ESTA SEGURO DE LAS ELECCIONES
//If SI-->LLEVA A ARMAR FACTURA
}

void armarPedidoDelivery()
{
    cout << "TIPO PEDIDO: DELIVERY";
//MOSTRAR EL TIPO PEDIDO
//INGRESE ID EMPLEADO/DELIVERY
//INGRESE DIRECCION
//NOMBRE DE CLIENTE
//ARMAR PEDIDO: ITEMS
//VERIFICAR ELECCIONES
//IF SI-->SE ARMA EL PEDIDO Y SE VAN LOS DATOS A MOSTRAR PEDIDOS
}

void armarPedidoTakeAway()
{
    cout << "TIPO PEDIDO: TAKE-AWAY";

    cout << "INGRESE ID EMPLEADO QUE TOMA LA ORDEN: ";
    cout<< "INGRESE NOMBRE DEL CLIENTE QUE RETIRA LA ORDEN: ";
    cout << "INGRESE TELEFONO DEL CLIENTE: ";

//ARMAR PEDIDO: ITEMS
//VERIFICAR ELECCIONES
//IF SI-->SE ARMA EL PEDIDO Y SE VAN LOS DATOS A MOSTRAR PEDIDOS
}
*/
