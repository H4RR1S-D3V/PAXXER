#include <iostream>
#include "../rlutil.h"
#include "windows.h"

using namespace std;


///DIBUJA EL CUADRADO DE LA MESA
void dibujarMesa(int posX, int posY){


    for(int x=posX; x<=posX+14; x++)
    {
        for (int y=posY; y<=posY+6; y++){
        rlutil::locate(x,y);
        cout << (char) 219;
        }

    }


}

///DIBUJA LOS BORDES SUPERIOR E INFERIOR DE MESAS Y DE LA CARTA
void dibujarBordeSyI (int posicionX, int posicionY){
rlutil::locate(posicionX,posicionY);
for (int i=0; i<150; i++){

    cout << char (205);
}
}
void dibujarBordesMenuPrincipal (int posicionX, int posicionY){
    rlutil::setColor(rlutil::BROWN);
rlutil::locate(posicionX,posicionY);
for (int i=0; i<90; i++){

    cout << char (158);
}
}

void dibujarBordesPantallas (int posicionX, int posicionY){
rlutil::locate(posicionX,posicionY);
for (int i=0; i<80; i++){

    cout << char (240);
}
}
void dibujarBordesDeI(int posicionX, int posicionY, int largo){

for (int y=0; y<=largo; y++){
rlutil::locate(posicionX,posicionY+y);
    cout << char (186);
}
}

void limpiarDesdePosicion(int x, int y, int ancho, int alto) {
    for (int i = 0; i < alto; ++i) {
        rlutil::locate(x, y + i);
        for (int j = 0; j < ancho; ++j) {
            cout << " ";
        }
    }
}
