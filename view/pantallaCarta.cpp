#include <iostream>
#include <iomanip>
#include "../rlutil.h"
#include "windows.h"

using namespace std;
#include "pantallasMenuPrincipal.h"
#include "funcionesDibujar.h"
#include "../controller/clasesArchivosFacturas.h"


void mostrarCarta()
{
    bool salir=true;
    int x=0;
    do
    {
  rlutil::setColor(rlutil::BROWN);
        dibujarBordeSyI(11,12);
           dibujarBordeSyI(11,14);
             rlutil::setColor(rlutil::CYAN);
        rlutil::locate (65,13);
        cout << "P       A       X       X       E       R";

        rlutil::setColor(rlutil::MAGENTA);
        dibujarTituloNUESTRACARTA();
        rlutil::setColor(rlutil::WHITE);
        ///VERIFICAR SI ES POSIBLE DIBUJAR ESTOS BORDES DE FORMA DINAMICA

///ITEMS PRUEBA

int cantItems=30;
int posXinicial=13;
int posYinicial=23;

Producto obj;
ArchivoProducto arc;

for (int i=0; i < cantItems; i++) {
         rlutil::setColor(rlutil::WHITE);
         obj=arc.leerRegistro(i);
     rlutil::locate(posXinicial, posYinicial+i);
        cout<< obj.getId();
        rlutil::locate(posXinicial+13,  posYinicial+i);
        cout <<obj.getTipo();
      rlutil::locate(posXinicial+50,  posYinicial+i);
        cout <<obj.getNombre();
        rlutil::locate(posXinicial+120,  posYinicial+i);
        cout <<fixed<<setprecision(2)<<obj.getPrecio();


}
        rlutil:: locate (41+(x),17);
        cout << char (16);
        pintarOpciones("VOLVER AL MENU PRINCIPAL",42,17, x==0);
        pintarOpciones("IR A CONFIGURACIONES DE CARTA",92,17, x==50);

         int key=rlutil::getkey();
        switch(key){
        case 17:
           rlutil:: locate (41+(x),17);
            cout << " ";
            x+=50;
            if (x>50) x=50;

            break;
        case 16:
            rlutil:: locate (41+(x),17);
            cout << " ";
            x-=50;
            if (x<0) x=0;
            break;

        case 1:
        switch (x)
        {
        case 0:
            rlutil::cls();
            salir=false;
            break;
        case 50:
            int resultado=MessageBox(NULL,"¿Desea ingresar su contraseña de Encargado?","INGRESO RESTRINGIDO - SOLO ENCARGADOS",MB_OKCANCEL|MB_ICONINFORMATION);
                if (resultado==IDOK)
                {
                    rlutil::cls();
                      //pantallaContrasenaC();
                    mostrarConfiguraciones();
                }
            break;
        }
        break;
        }

    }
    while(salir==true);
}
