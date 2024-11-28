#include <iostream>
#include "../rlutil.h"
#include "windows.h"

using namespace std;

#include "pantallasMenuPrincipal.h"
#include "funcionesDibujar.h"
#include "declaracionOpcionesConfiguraciones.h"
#include "../controller/clasesArchivosMesas.h"
#include "menuPrincipal.h"


void mostrarConfiguraciones()
{

    bool salir=true;
    int y=0;


    do
    {
        rlutil::hidecursor();
        rlutil::setColor (rlutil::MAGENTA);
        dibujarTituloCONFIGURACIONES();
        rlutil::setColor (rlutil::LIGHTCYAN);
        dibujarBordesPantallas(42,9);
        dibujarBordesPantallas(42,11);
        rlutil::setColor (rlutil::BROWN);
        rlutil:: locate (60,10);
        cout << "S O L O     P E R S O N A L    A U T O R I Z A D O";
        rlutil::setColor (rlutil::WHITE);
        pintarOpciones("CONFIGURAR CARTA", 74, 14, y==0);
        pintarOpciones("LISTADO DE EMPLEADOS", 74, 16, y==2);
        pintarOpciones("CAMBIAR CANTIDAD MESAS", 74, 18, y==4);
        pintarOpciones("VOLVER A MENU PRINCIPAL", 74, 20, y==6);

        rlutil::locate(72,14+(y));
        cout << char (16);

        int key=rlutil::getkey();
        switch (key)
        {
        case 14:
            rlutil::locate(72,14+(y));
            cout << " ";
            y -= 2;
            if (y < 0) y = 0;
            break;
        case 15:
            rlutil::locate(72,14+(y));
            cout << " ";
            y += 2;
            if (y > 6) y = 6;
            break;
        case 1:
            switch (y)
            {
            case 0:{
             rlutil::cls();
              mostrarConfigurarCarta();
                break;
            }

            case 2:
               rlutil::cls();
               mostrarEmpleados();
                break;
            case 4:{
               rlutil::cls();
               ///
                ArchivoMesasLocal arc;

               int resultado=MessageBox(NULL,"Ingrese la cantidad de mesas a dibujar (MAX 30)","CAMBIAR CANTIDAD DE MESAS - SALON",MB_OKCANCEL|MB_ICONINFORMATION);
               if (resultado==IDOK)
                {
                    int cantMesas;
                    cout << "NRO DE MESAS ";
                    cin >> cantMesas;
                    if (cantMesas <= 30){
                    int cantDevuelta = arc.setearCantMesas(cantMesas);
                        if (cantDevuelta == 0){
                                MessageBox(NULL, "VERIFIQUE QUE TODAS LAS MESAS ESTEN DESOCUPADAS", "ERROR MESAS OCUPADAS", MB_OK);
                        } else if (cantDevuelta == -2){
                                MessageBox(NULL, "EL NUMERO INGRESADO NO ES VALIDO", "ERROR CANTIDAD MESAS", MB_OK);
                        } else if (cantDevuelta == -1){
                                MessageBox(NULL, "NO SE PUDO ACCEDER AL ARCHIVO DE MESAS", "ERROR ARCHIVO MESAS", MB_OK);
                        }else {
                                MessageBox(NULL, "LA CANTIDAD DE MESAS SE CAMBIO CORRECTAMENTE", "CANTIDAD DE MESAS CAMBIADA", MB_OK);
                        }
                    } else {
                    rlutil::cls();
                    MessageBox(NULL, "EL MAXIMO DE MESAS ES 30", "ERROR CANTIDAD DE MESAS", MB_OK);
                    }

                }
                break;
            }
            case 6:
                rlutil::cls();
                salir=false;
                mostrarMenuPrincipal();
                break;


            }



        }
    }
    while(salir==true);

}
