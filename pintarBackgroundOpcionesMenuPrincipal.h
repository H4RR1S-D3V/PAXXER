#ifndef PINTARBACKGROUNDOPCIONESMENUPRINCIPAL_H_INCLUDED
#define PINTARBACKGROUNDOPCIONESMENUPRINCIPAL_H_INCLUDED

void pintarOpcionesMenuPrincipal(const char* texto, int posX, int posY, bool seleccion)
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



#endif // PINTARBACKGROUNDOPCIONESMENUPRINCIPAL_H_INCLUDED
