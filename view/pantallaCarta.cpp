
#include <iostream>
#include "../rlutil.h"
#include "windows.h"

using namespace std;
#include "pantallasMenuPrincipal.h"
#include "funcionesDibujar.h"


void mostrarCarta()
{
    bool salir=true;
    int x=0;
    do
    {
  rlutil::setColor(rlutil::BROWN);
        dibujarBordeSyI(44,12);
           dibujarBordeSyI(44,14);
             rlutil::setColor(rlutil::CYAN);
        rlutil::locate (95,13);
        cout << "P       A       X       X       E       R";

        rlutil::setColor(rlutil::MAGENTA);
        dibujarTituloNUESTRACARTA();
        rlutil::setColor(rlutil::WHITE);
        dibujarBordeSyI(44,20);
        dibujarBordeSyI(44,22);
        ///PARA MODIFICAR EL LARGO SOLAMENTE SUMARLE AL ULTIMO NUM(EJ: 20+Y(Y=1)
        dibujarBordesDeI(43,21,20);
        dibujarBordesDeI(193,21,20);

        rlutil::locate (50,21);
        cout<<"ID";
        rlutil::locate (65,21);
        cout<< "TIPO";
        rlutil::locate (115,21);
        cout<< "NOMBRE";
        rlutil::locate (165,21);
        cout<< "PRECIO";
        rlutil::locate (185,21);
        cout<< "ESTADO";

        rlutil:: locate (89+(x),17);
        cout << char (16);
        pintarOpciones("VOLVER AL MENU PRINCIPAL",90,17, x==0);
        pintarOpciones("IR A CONFIGURACIONES DE CARTA",120,17, x==30);

         int key=rlutil::getkey();
        switch(key){
        case 17:
           rlutil:: locate (89+(x),17);
            cout << " ";
            x+=30;
            if (x>30) x=30;

            break;
        case 16:
             rlutil:: locate (89+(x),17);
            cout << " ";
            x-=30;
            if (x<0) x=0;
            break;

        case 1:
        switch (x)
        {
        case 0:
            rlutil::cls();
            salir=false;
            break;
        case 30:
            int resultado=MessageBox(NULL,"¿Desea ingresar su contraseña de Encargado?","INGRESO RESTRINGIDO - SOLO ENCARGADOS",MB_OKCANCEL|MB_ICONINFORMATION);
                if (resultado==IDOK)
                {
                    rlutil::cls();
                    mostrarConfiguraciones();
                      //pantallaContrasenaC();
                }
            break;
        }
        break;
        }

    }
    while(salir==true);
}

