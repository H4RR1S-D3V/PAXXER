#include <iostream>
#include "../rlutil.h"

using namespace std;
#include "declaracionOpcionesConfiguraciones.h"
#include "funcionesDibujar.h"

///FALTA: SOLUCIONAR CLS, ORDENAR LISTADO ITEMS , AGREGAR OPCIONES PARA CONFIRMAR LA CONFIGURACION.

void mostrarConfigurarCarta()
{
    int x = 0;
    bool salir = true;
         int idItem;
         string tipoPlato, nombrePlato;
         float precioPlato;
              int resultado;
    do
    {
        rlutil::hidecursor();
        rlutil::setColor (rlutil::LIGHTCYAN);
        dibujarBordesPantallas(80,9);
        dibujarBordesPantallas(80,11);
        rlutil::setColor (rlutil::MAGENTA);

        rlutil:: locate (100,10);
        cout << "M O D I F I C A R   C A R T A";
        rlutil::setColor (rlutil::WHITE);
        pintarOpciones("AGREGAR ITEM",40,12, x==0);
        pintarOpciones("ELIMINAR ITEM",70,12, x==30);
        pintarOpciones("HABILITAR ITEM",100,12, x==60);
        pintarOpciones ("DESHABILITAR ITEM", 130,12, x==90);
        pintarOpciones("MODIFICAR PRECIO",160,12, x==120);
        pintarOpciones("VOLVER A CONFIGURACIONES",190,12, x==150);

        rlutil:: locate (39+x,12);
        cout << char (16);
        int key=rlutil::getkey();
        rlutil::locate(39 + x, 12);
        cout << " ";


        switch (key)
        {
        case 17:
            x+=30;
            if (x>150) x=150;
            break;
        case 16:
            x-=30;
            if (x<0) x=0;
            break;
        case 1:
            switch (x)
            {
            case 0: ///AGREGAR ITEM
                //NO AGREGO ID PORQUE ESTE SE GENERA AUTOMATICAMETE, PERO SE PODRIA MOSTRAR EL ID QUE LE CORRESPONDERIA A ESTE NUEVO ITEM.
                rlutil::locate (65,15);
                cout << "TIPO: ";
                cin>> tipoPlato;
                 rlutil::locate (115,15);
                cout << "NOMBRE: ";
                cin >> nombrePlato;
                 rlutil::locate (165,15);
                cout << "PRECIO: ";
                cin>>precioPlato;
                rlutil::anykey();
                resultado=MessageBox(NULL, "Desea agregar este item a la carta?", "AGREGAR NUEVO ITEM", MB_YESNO|MB_ICONQUESTION);
                if (resultado==IDYES){
                    MessageBox(NULL,"Item agregado exitosamente", "OPERACION EXITOSA", MB_OK|MB_ICONINFORMATION);

                }else
                //MessageBox(NULL,"No fue posible agregar el item. Desea intentarlo nuevamente?", "OPERACION FALLIDA", MB_OKCANCEL|MB_ICONINFORMATION);
                //if -->si==configurarCarta();
                //no--> menuPrincipal();
                rlutil::cls();
               // configurarCarta();
                break;

            case 30:///ELIMINAR ITEM

                rlutil::setColor(rlutil::WHITE);
                rlutil::locate (100,15);

                cout << "INGRESE ID ITEM A";
                rlutil::setColor(rlutil::CYAN);
                cout << " ELIMINAR ";
                rlutil::locate(110,17);
                rlutil::showcursor();
                rlutil::locate(110,17);
                cin >> idItem;

//PODRIA AGREGAR VENTANAS EMERGENTES CUANDO FUE EXITOSA/FRACASO ELIMINAR ITEM
                rlutil::locate (55,20);
                cout<<"ID";
                rlutil::locate (70,20);
                cout<< "TIPO";
                rlutil::locate (120,20);
                cout<< "NOMBRE";
                rlutil::locate (170,20);
                cout<< "PRECIO";
                rlutil::locate (190,20);
                cout<< "ESTADO";

                break;
            case 60:///HABILITAR ITEM
                rlutil::locate (100,15);
                cout << "INGRESE ID ITEM A";
                rlutil::setColor(rlutil::LIGHTGREEN);
                cout << " HABILITAR ";
                rlutil::locate(110,17);
                rlutil::showcursor();
                rlutil::locate(110,17);
                cin >> idItem;
//PODRIA AGREGAR VENTANAS EMERGENTES CUANDO FUE EXITOSA/FRACASO ELIMINAR ITEM
                rlutil::setColor(rlutil::LIGHTGREEN);
                rlutil::locate (55,20);
                cout<<"ID";
                rlutil::locate (70,20);
                cout<< "TIPO";
                rlutil::locate (120,20);
                cout<< "NOMBRE";
                rlutil::locate (170,20);
                cout<< "PRECIO";
                rlutil::locate (190,20);
                cout<< "ESTADO";
                rlutil::setColor(rlutil::WHITE);
                break;
            case 90:///DESHABILITAR ITEM
                rlutil::locate (100,15);
                cout << "INGRESE ID ITEM A";
                rlutil::setColor(rlutil::LIGHTRED);
                cout << " DESHABILITAR ";
                 rlutil::locate(110,17);
                rlutil::showcursor();
                rlutil::locate(110,17);
                cin >> idItem;
//PODRIA AGREGAR VENTANAS EMERGENTES CUANDO FUE EXITOSA/FRACASO ELIMINAR ITEM
                rlutil::setColor(rlutil::LIGHTRED);
                rlutil::locate (55,20);
                cout<<"ID";
                rlutil::locate (70,20);
                cout<< "TIPO";
                rlutil::locate (120,20);
                cout<< "NOMBRE";
                rlutil::locate (170,20);
                cout<< "PRECIO";
                rlutil::locate (190,20);
                cout<< "ESTADO";
                rlutil::setColor(rlutil::WHITE);
                break;
            case 120:///MODIFICAR PRECIO
                rlutil::locate (100,15);

                cout << "INGRESE ID ITEM A";
                rlutil::setColor(rlutil::BROWN);
                cout << " MODIFICAR PRECIO ";
                 rlutil::locate(110,17);
                rlutil::showcursor();
                rlutil::locate(110,17);
                cin >> idItem;
//PODRIA AGREGAR VENTANAS EMERGENTES CUANDO FUE EXITOSA/FRACASO ELIMINAR ITEM
                rlutil::setColor(rlutil::BROWN);
                rlutil::locate (55,20);
                cout<<"ID";
                rlutil::locate (70,20);
                cout<< "TIPO";
                rlutil::locate (120,20);
                cout<< "NOMBRE";
                rlutil::locate (170,20);
                cout<< "PRECIO";
                rlutil::locate (190,20);
                cout<< "ESTADO";
                rlutil::setColor(rlutil::WHITE);
                break;
            case 150:///VOLVER A CONFIGURACIONES
                rlutil::cls();
                salir=false;
                break;

            }
            break;
        }

       } while (salir==true);

}




void mostrarEmpleados()
{
    rlutil::hidecursor();
    rlutil::setColor (rlutil::LIGHTCYAN);
    dibujarBordesPantallas(80,9);
    dibujarBordesPantallas(80,11);
    rlutil::setColor (rlutil::MAGENTA);
    rlutil:: locate (90,10);
    cout << "L I S T A D O   D E   E M P L E A D O S";
    ///PRIMERO SE DECIDE ESTO.
    rlutil:: locate (80,12);
    cout << "ELIMINAR EMPLEADO";
      rlutil:: locate (90,12);
    cout << "AGREGAR EMPLEADO";
      rlutil:: locate (100,12);
    cout << "VER EMPLEADO";
    ///LUEGO SE SELECCIONA EL NUMERO DE EMPLEADO QUE QUIERE VER MEDIANTE SU DNI
    rlutil:: locate (90,16);
    cout << "NOMBRE";
    rlutil:: locate (100,16);
    cout << "USERNAME";
    rlutil:: locate (110,16);
    cout << "DNI";
    rlutil:: locate (120,16);
    cout << "CONTRASEÑA";

}

