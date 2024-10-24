#ifndef DIBUJARBORDES_H_INCLUDED
#define DIBUJARBORDES_H_INCLUDED

///DIBUJA LOS BORDES SUPERIOR E INFERIOR DE MESAS
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

#endif // DIBUJARBORDES_H_INCLUDED
