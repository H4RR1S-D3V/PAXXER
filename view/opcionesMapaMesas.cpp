#include <iostream>
#include "../rlutil.h"
#include "windows.h"
#include <iomanip>

using namespace std;
#include "declaracionOpcionesMapaMesas.h"
#include "funcionesDibujar.h"
#include "pantallasMenuPrincipal.h"
#include "../controller/clasesArchivosFacturas.h"


void seleccionarTipoPedido()
{
    int x=0;
    char tipoPedido[10]; //SOLO TEMPORAL-PARA PROBAR
    rlutil:: locate(94+x,38);
    cout << char(16);
    int key = rlutil::getkey();
    rlutil::locate(94+x, 38);
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
    // string IDEMP;
    // string CANTCOM;
    /* int idEmp;
     int cantCom;*/
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
        //  cin>>IDEMP;
        rlutil:: locate (40,13);
        cout << "PORFAVOR INGRESE LA CANTIDAD DE COMENSALES: ";
        //   cin>>CANTCOM;
//cin.ignore();

        // cout << IDEMP << CANTCOM << endl;
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
            break;
        }
    }
    while(salir==true);
}
/*
void mostrarVistaMesa()
{
    int posItem, cantItem, descuentoTipo,descuentoMonto;;
    bool salir = true;
    int x=0;
    do
    {
        rlutil::hidecursor();
        rlutil::setColor(rlutil::LIGHTCYAN);
        dibujarBordeSyI(10,3);
        dibujarBordeSyI(10,6);
        rlutil::setColor(rlutil::BROWN);
        rlutil::locate(42, 4);
        cout<<"NRO. MESA";
        rlutil::locate(46, 5);
        cout<<"5";
        rlutil::locate(80, 4);
        cout <<"HORA";
        rlutil::locate(80, 5);
        cout<<"22:00";
        rlutil::locate(110, 4);
        cout <<"CANT. COMENSALES";
        rlutil::locate(121, 5);
        cout<<"4";
        rlutil::setColor(rlutil::WHITE);
        pintarOpciones("CARGAR ITEM",30, 8, x==0);
        pintarOpciones("QUITAR ITEM",60, 8,x==30);
        pintarOpciones("CERRAR MESA",90, 8, x==60);
        pintarOpciones("VOLVER A MAPA",120, 8, x==90);

        rlutil::setColor(rlutil::MAGENTA);
        dibujarBordeSyI(10,16);
        dibujarBordeSyI(10,18);


        rlutil::setColor(rlutil::YELLOW);
        rlutil::locate(12, 15);
        cout<<"NRO. FACTURA: "<< 3;
        rlutil::locate(50, 15);
        cout<<"ID EMPLEADO: "<< 07;
        rlutil::locate(90, 15);
        cout<<"TURNO: "<< 1;
        rlutil::locate(130, 15);
        cout<<"FECHA: "<< "19/11/2024";

        rlutil::setColor(rlutil::LIGHTCYAN);
        rlutil::locate(12, 17);
        cout<<"NRO.";
        rlutil::locate(52, 17);
        cout <<"NOMBRE";
        rlutil::locate(100, 17);
        cout <<"CANTIDAD";
        rlutil::locate(122, 17);
        cout <<"PRECIO";
        rlutil::locate(135, 17);
        cout <<"SUB-TOTAL";



        int cantItems=5;
        int posXinicial=13;
        int posYinicial=19;

        for (int i=0; i < cantItems; i++)
        {
            rlutil::setColor(rlutil::WHITE);

            obj=arc.leerRegistro(i);
            rlutil::locate(posXinicial, posYinicial+i);
            cout<< obj.getId();
            rlutil::locate(posXinicial+35,  posYinicial+i);
            cout <<obj.getNombre();
            rlutil::locate(posXinicial+90,  posYinicial+i);
            cout <<"4";
            rlutil::locate(posXinicial+108,  posYinicial+i);
            cout <<obj.getPrecio();
            rlutil::locate(posXinicial+122,  posYinicial+i);
            cout <<fixed<<setprecision(2)<<obj.getPrecio()*4;
            //dibujarBordeSyI(13,posYinicial+i);
        }

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
        {
                rlutil::setColor(rlutil::WHITE);
                rlutil::locate(48, 11);
                cout<<"PORFAVOR INGRESE ID DE ITEM A ELIMINAR: ";
                cin >> posItem;
                    rlutil::locate(48, 12);
        cout<<"PORFAVOR INGRESE LA CANTIDAD DE ITEMS A ELIMINAR";
         cin >> cantItem;
int resultado = MessageBox(NULL, "Desea quitar esta cantidad de items?", "CONFIRMACION DE OPERACION", MB_OKCANCEL);
        if (resultado==IDOK)
        {
            MessageBox(NULL, "Se quito el item exitosamente", "OPERACION EXITOSA", MB_OK);
        }
        rlutil::cls();

        }
                break;
            case 60://CERRAR MESA
        {
                int resultado = MessageBox(NULL, "Desea aplicar algun descuento antes de cerrar mesa?", "CONFIRMACION DE OPERACION", MB_YESNO);
        if (resultado==IDNO)
        {
            MessageBox(NULL, "Se cerro la mesa exitosamente", "OPERACION EXITOSA", MB_OK);
        }
        else   rlutil::locate(48, 11);
               cout<<"PORFAVOR INGRESE TIPO DESCUENTO: ";
                cin >> descuentoTipo;
                 rlutil::locate(48, 12);
                 cout<<"PORFAVOR INGRESE MONTO A DESCONTAR: ";
                  cin >> descuentoMonto;
        int seleccion  = MessageBox(NULL, "Desea aplicar este descuento?", "CONFIRMACION DE OPERACION", MB_OKCANCEL);
        if (resultado==IDOK){
            MessageBox(NULL, "Se aplico el descuento exitosamente", "OPERACION EXITOSA", MB_OK);
        }
        rlutil::cls();

        }
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
*/

void cargarItem(int idFactura)
{
    int idItem;
    int cantItem;
    int x=0;
    do
    {
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
        dibujarBordeSyI(10,30);
        ///PARA MODIFICAR EL LARGO SOLAMENTE SUMARLE AL ULTIMO NUM(EJ: 20+Y(Y=1)
        dibujarBordesDeI(9,9,20);
        dibujarBordesDeI(160,9,20);
        rlutil::setColor(rlutil::LIGHTCYAN);
        rlutil::locate(12, 9);
        cout<<"NRO.";
        rlutil::locate(52, 9);
        cout <<"NOMBRE";
        rlutil::locate(100, 9);
        cout <<"PRECIO";
        rlutil::locate(122, 9);
        cout <<"TIPO";

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
            if(x>120) x=120;
            break;
        case 16:
            x-=30;
            if(x<0) x=0;
            break;
        case 1:
            switch(x)
            {
            case 0://ENTRADA
            {
                ///PRIMERO SE MUESTRA LA CARTA CON EL FILTRO
                ArchivoProducto arc;
                arc.listarRegistrosPorTipo(1);
                rlutil::locate (70, 31);
                cout<<"INGRESE ID DE ITEM A CARGAR"; /// PEDIR CANT
                rlutil::showcursor();
                rlutil::locate (84, 32);
                cin >> idItem;
                rlutil::locate (70, 33);
                cout<<"INGRESE LA CANTIDAD"; /// PEDIR CANT
                rlutil::showcursor();
                rlutil::locate (84, 34);
                cin >> cantItem;
                int seleccion=MessageBox(NULL, "¿Desea agregar el item seleccionado?", "CONFIRMACION AGREGAR ITEM", MB_OKCANCEL);
                if (seleccion==IDOK)
                {
                    ///ACA LOGICA PARA AGREGAR ITEM

                    ArchivoFactura arcFac;
                    Factura objFac;

                    int pos = arcFac.buscarRegistro(idFactura);

                    objFac = arcFac.leerRegistro(pos);
                    if(objFac.cargarItem(idItem, cantItem))
                    {
                        /// SE CARGA EL ITEM CORRECTAMENTE
                        rlutil::cls();
                        return;
                    }
                    /// NO DISPONIBLE
                    rlutil::setColor(rlutil::RED);
                    rlutil::locate (70, 35);
                    cout << "ITEM NO DISPONIBLE" << endl;
                    system("pause");
                    rlutil::cls();
                }
                break;
            }
            case 30://P. PRINCIPAL
            {
                ///PRIMERO SE MUESTRA LA CARTA CON EL FILTRO
                ArchivoProducto arc;
                arc.listarRegistrosPorTipo(2);
                rlutil::locate (70, 31);
                cout<<"INGRESE ID DE ITEM A CARGAR";
                rlutil::showcursor();
                rlutil::locate (84, 32);
                cin >> idItem;
                rlutil::locate (70, 33);
                cout<<"INGRESE LA CANTIDAD"; /// PEDIR CANT
                rlutil::showcursor();
                rlutil::locate (84, 34);
                cin >> cantItem;

                int seleccion=MessageBox(NULL, "¿Desea agregar el item seleccionado?", "CONFIRMACION AGREGAR ITEM", MB_OKCANCEL);
                if (seleccion==IDOK)
                {
                    ///ACA LOGICA PARA AGREGAR ITEM

                    ArchivoFactura arcFac;
                    Factura objFac;

                    int pos = arcFac.buscarRegistro(idFactura);

                    objFac = arcFac.leerRegistro(pos);
                    if(objFac.cargarItem(idItem, cantItem))
                    {
                        /// SE CARGA EL ITEM CORRECTAMENTE
                        rlutil::cls();
                        return;
                    }
                    /// NO DISPONIBLE
                    rlutil::setColor(rlutil::RED);
                    rlutil::locate (70, 35);
                    cout << "ITEM NO DISPONIBLE" << endl;
                    system("pause");
                    rlutil::cls();
                }
                break;
            }
            case 60://POSTRE
            {
                ///PRIMERO SE MUESTRA LA CARTA CON EL FILTRO
                ArchivoProducto arc;
                arc.listarRegistrosPorTipo(3);
                rlutil::locate (70, 31);
                cout<<"INGRESE ID DE ITEM A CARGAR";
                rlutil::showcursor();
                rlutil::locate (84, 32);
                cin >> idItem;
                rlutil::locate (70, 33);
                cout<<"INGRESE LA CANTIDAD"; /// PEDIR CANT
                rlutil::showcursor();
                rlutil::locate (84, 34);
                cin >> cantItem;
                int seleccion=MessageBox(NULL, "¿Desea agregar el item seleccionado?", "CONFIRMACION AGREGAR ITEM", MB_OKCANCEL);
                if (seleccion==IDOK)
                {
                    ///ACA LOGICA PARA AGREGAR ITEM

                    ArchivoFactura arcFac;
                    Factura objFac;

                    int pos = arcFac.buscarRegistro(idFactura);

                    objFac = arcFac.leerRegistro(pos);
                    if(objFac.cargarItem(idItem, cantItem))
                    {
                        /// SE CARGA EL ITEM CORRECTAMENTE
                        rlutil::cls();
                        return;
                    }
                    /// NO DISPONIBLE
                    rlutil::setColor(rlutil::RED);
                    rlutil::locate (70, 35);
                    cout << "ITEM NO DISPONIBLE" << endl;
                    system("pause");
                    rlutil::cls();
                }
                break;
            }
            case 90://BEBIDA
            {
                ///PRIMERO SE MUESTRA LA CARTA CON EL FILTRO
                ArchivoProducto arc;
                arc.listarRegistrosPorTipo(4);
                rlutil::locate (70, 31);
                cout<<"INGRESE ID DE ITEM A CARGAR";
                rlutil::showcursor();
                rlutil::locate (84, 32);
                cin >> idItem;
                rlutil::locate (70, 33);
                cout<<"INGRESE LA CANTIDAD"; /// PEDIR CANT
                rlutil::showcursor();
                rlutil::locate (84, 34);
                cin >> cantItem;
                int seleccion=MessageBox(NULL, "¿Desea agregar el item seleccionado?", "CONFIRMACION AGREGAR ITEM", MB_OKCANCEL);
                if (seleccion==IDOK)
                {
                    ///ACA LOGICA PARA AGREGAR ITEM

                    ArchivoFactura arcFac;
                    Factura objFac;

                    int pos = arcFac.buscarRegistro(idFactura);

                    objFac = arcFac.leerRegistro(pos);
                    if(objFac.cargarItem(idItem, cantItem))
                    {
                        /// SE CARGA EL ITEM CORRECTAMENTE
                        rlutil::cls();
                        return;
                    }
                    /// NO DISPONIBLE
                    rlutil::setColor(rlutil::RED);
                    rlutil::locate (70, 35);
                    cout << "ITEM NO DISPONIBLE" << endl;
                    system("pause");
                    rlutil::cls();
                }
                break;
            }
            case 120://VOLVER
                rlutil::cls();
                return;
            }
            break;
        }
    }
    while(true);
}

void quitarItem(int idFactura)
{
    int y = 0;
    int idItem, cantItem;
    bool salir=true;
    do
    {
        rlutil::locate(60, 36);
        cout<<"PORFAVOR INGRESE ID DE ITEM A ELIMINAR";
        rlutil::locate(60, 37);
        cout<<"UNA VEZ FINALICE PRESIONE ENTER PARA CONTINUAR";
        rlutil::locate(80, 38);
        rlutil::setColor(rlutil::WHITE);
        cin >> idItem;

        rlutil::setColor(rlutil::BROWN);
        rlutil::locate(60, 36);
        cout<<"PORFAVOR INGRESE LA CANTIDAD DE ITEMS A ELIMINAR";
        rlutil::locate(60, 37);
        cout<<"UNA VEZ FINALICE PRESIONE ENTER PARA CONTINUAR";
        rlutil::locate(80, 38);
        rlutil::setColor(rlutil::WHITE);
        cout << "     ";
        cin>> cantItem;

        /*
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
        */

        int resultado = MessageBox(NULL, "Desea quitar esta cantidad de items?", "CONFIRMACION DE OPERACION", MB_OKCANCEL);
        if (resultado==IDOK)
        {
            ArchivoFactura arcFac;
            Factura objFac;

            int pos = arcFac.buscarRegistro(idFactura);
            objFac = arcFac.leerRegistro(pos);

            if(objFac.quitarItem(idItem, cantItem))
            {
                MessageBox(NULL, "Se quito el item exitosamente", "OPERACION EXITOSA", MB_OK);
            }
            else
            {
                MessageBox(NULL, "NO SE ENCONTRO EL PRODUCTO", "ERROR ELIMINAR PRODUCTO", MB_OKCANCEL);
            }
        }
        rlutil::cls();
        return;
    }
    while (salir==true);
}
