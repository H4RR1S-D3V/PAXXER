#include <iostream>
#include "../rlutil.h"

using namespace std;

void pintarOpciones(const char* texto, int posX, int posY, bool seleccion)
{
    if (seleccion)
    {

        rlutil::setBackgroundColor(rlutil::LIGHTMAGENTA);

    }
    else
    {
        rlutil::setBackgroundColor(rlutil::BLACK);
    }


    rlutil::locate(posX,posY);
    cout << texto;
    rlutil::setBackgroundColor(rlutil::BLACK);

}

void pintarBack(int posX, int posY){
   rlutil::setBackgroundColor(rlutil::WHITE);
}

