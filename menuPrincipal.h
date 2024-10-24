#ifndef MENUPRINCIPAL_H_INCLUDED
#define MENUPRINCIPAL_H_INCLUDED
#include "dibujarTitulo.h"
#include "pintarBackgroundOpcionesMenuPrincipal.h"

void mostrarMenuPrincipal()
{
    int op=1;
    //POSICION DE Y PARA MANIPULAR LA KEY DE SELECCION
    int y;
    do
    {
        //rlutil::cls();
        rlutil::hidecursor();


        dibujarBordesMenuPrincipal(70,19);
        dibujarTituloPAXXER();
        dibujarBordesMenuPrincipal(70,10);
        rlutil::setColor(rlutil::LIGHTCYAN);
        rlutil::locate(95,21);
        cout << "R    E    S    T    O   -   B    A    R";
        rlutil::setColor(rlutil::WHITE);
        pintarOpcionesMenuPrincipal("MESAS", 112, 24, y==0);
        pintarOpcionesMenuPrincipal("CARTA", 112, 26, y==2);
        pintarOpcionesMenuPrincipal("INFORMES", 111, 28, y==4);
        pintarOpcionesMenuPrincipal("CONFIGURACION", 108, 30, y==6);
        pintarOpcionesMenuPrincipal("SALIR", 112, 32, y==8);


        rlutil::locate(106,24+(y));
        cout << char (26);
        rlutil::locate(122,24+(y));
        cout << char (27);

        int key=rlutil::getkey();

        switch (key)
        {
        case 14:
            rlutil::locate(106,24+(y));
            cout << " ";
            rlutil::locate(122,24+(y));
            cout << " ";
            y -= 2;
            if (y < 0) y = 0;
            break;
        case 15:
            rlutil::locate(106,24+(y));
            cout << " ";
            rlutil::locate(122,24+(y));
            cout << " ";
            y += 2;
            if (y > 8) y = 8;
            break;
        case 1://enter
            switch (y)
            {
            case 0: ///MESAS
                break;
            case 2: ///CARTA
                break;
            case 4: ///INFORMES
                break;
            case 6: ///CONFIGURACION
                break;
            case 8: ///SALIR
                op=0;
                break;
            }

        }


    }
    while (op!=0);
}

#endif // MENUPRINCIPAL_H_INCLUDED
