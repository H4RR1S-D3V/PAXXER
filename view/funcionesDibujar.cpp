#include <iostream>
#include "../rlutil.h"
#include "windows.h"

#include "../controller/clasesArchivosFacturas.h"
#include "../controller/clasesArchivosUsuarios.h"
//#include "../controller/ClasesFactura.h"
#include "../view/declaracionOpcionesConfiguraciones.h"

#include "funcionesDibujar.h"

using namespace std;


///DIBUJA EL CUADRADO DE LA MESA
void dibujarMesa(int posX, int posY)
{


    for(int x=posX; x<=posX+14; x++)
    {
        for (int y=posY; y<=posY+6; y++)
        {
            rlutil::locate(x,y);
            cout << (char) 219;
        }

    }


}

///DIBUJA LOS BORDES SUPERIOR E INFERIOR DE MESAS Y DE LA CARTA
void dibujarBordeSyI (int posicionX, int posicionY)
{
    rlutil::locate(posicionX,posicionY);
    for (int i=0; i<150; i++)
    {

        cout << char (205);
    }
}
void dibujarBordesMenuPrincipal (int posicionX, int posicionY)
{
    rlutil::setColor(rlutil::BROWN);
    rlutil::locate(posicionX,posicionY);
    for (int i=0; i<90; i++)
    {

        cout << char (158);
    }
}

void dibujarBordesPantallas (int posicionX, int posicionY)
{
    rlutil::locate(posicionX,posicionY);
    for (int i=0; i<80; i++)
    {

        cout << char (240);
    }
}
void dibujarBordesDeI(int posicionX, int posicionY, int largo)
{

    for (int y=0; y<=largo; y++)
    {
        rlutil::locate(posicionX,posicionY+y);
        cout << char (186);
    }
}


void opcionesModificarItem()
{
    int x =0;
    ArchivoProducto arc;
    Producto obj;
    int idItem;
    do
    {

        rlutil::setColor (rlutil::WHITE);
        pintarOpciones("PRECIO",40,9, x==0);
        pintarOpciones("NOMBRE",60,9, x==20);
        pintarOpciones("TIPO",80,9, x==40);
        pintarOpciones("ESTADO",100,9, x==60);
        pintarOpciones("VOLVER",120,9, x==80);

        rlutil::locate(39+x,9);
        cout << char(16);
        int key = rlutil::getkey();
        rlutil::locate(39+x, 9);
        cout << " ";

        switch (key)
        {
        case 17:
            x+=20;
            if(x>80) x=80;
            break;
        case 16:
            x-=20;
            if(x<0) x=0;
            break;
        case 1:
            limpiarDesdePosicion(40,10,100,5);

            switch (x)
            {
            case 0:     /// ACTUALIZAR PRECIO
            {

                rlutil::setColor(rlutil::WHITE);
                rlutil::locate (40,12);
                cout << "INGRESE ID ITEM MODIFICAR: ";

                rlutil::showcursor();
                cin >> idItem;
                cin.clear();
                rlutil::hidecursor();

                if(idItem < 0)
                {
                    rlutil::setColor(rlutil::RED);
                    rlutil::locate (40,13);
                    cout << "INGRESE UN ID VALIDO: ";

                    break;
                }
                else if(arc.buscarRegistroPorId(idItem) == -2)
                {
                    rlutil::setColor(rlutil::RED);
                    rlutil::locate (40,13);
                    cout << "NO SE ENCONTRO ITEM CON EL ID SELECCIONADO: ";

                    break;
                }

                int pos = arc.buscarRegistroPorId(idItem);

                rlutil::setColor(rlutil::WHITE);
                rlutil::locate (40,14);
                cout << "INGRESE EL NUEVO PRECIO: ";
                rlutil::showcursor();
                float nuevoPrecio;
                cin >> nuevoPrecio;
                if(nuevoPrecio <= 0)
                {
                    rlutil::setColor(rlutil::RED);
                    rlutil::locate (40,15);
                    cout << "INGRESE UN VALOR VALIDO: ";

                    break;
                }

                int resultado = MessageBox(NULL, "Desea cambiar el precio de este item de la carta?", "CAMBIAR PRECIO ITEM", MB_YESNO|MB_ICONQUESTION);
                if (resultado==IDYES) //&& SI LA OPERACION FUE EXITOSA
                {
                    if(arc.modificarPrecioRegistro(nuevoPrecio, idItem))
                    {
                        MessageBox(NULL,"Precio actualizado exitosamente", "OPERACION EXITOSA", MB_OK|MB_ICONINFORMATION);
                    }
                }
                rlutil::cls();
                mostrarConfigurarCarta();
                break;
            }
            case 20:        /// ACTUALIZAR NOMBRE
            {

                rlutil::setColor(rlutil::WHITE);
                rlutil::locate (40,12);
                cout << "INGRESE ID ITEM MODIFICAR: ";

                rlutil::showcursor();
                cin >> idItem;
                cin.clear();
                rlutil::hidecursor();

                if(idItem < 0)
                {
                    rlutil::setColor(rlutil::RED);
                    rlutil::locate (40,13);
                    cout << "INGRESE UN ID VALIDO: ";

                    break;
                }
                else if(arc.buscarRegistroPorId(idItem) == -2)
                {
                    rlutil::setColor(rlutil::RED);
                    rlutil::locate (40,13);
                    cout << "NO SE ENCONTRO ITEM CON EL ID SELECCIONADO: ";

                    break;
                }
                rlutil::setColor(rlutil::WHITE);
                rlutil::locate (40,14);
                cout << "INGRESE EL NUEVO NOMBRE: ";
                rlutil::showcursor();
                char nuevoNombre[50];
                cargarCadena(nuevoNombre, 50);

                int resultado = MessageBox(NULL, "Desea cambiar el nombre de este item de la carta?", "CAMBIAR NOMBRE ITEM", MB_YESNO|MB_ICONQUESTION);
                if (resultado==IDYES) //&& SI LA OPERACION FUE EXITOSA
                {
                    if(arc.modificarNombreRegistro(nuevoNombre, idItem))
                    {
                        MessageBox(NULL,"Nombre actualizado exitosamente", "OPERACION EXITOSA", MB_OK|MB_ICONINFORMATION);
                    }
                }
                rlutil::cls();
                mostrarConfigurarCarta();
                break;
            }
            case 40:     /// ACTUALIZAR TIPO
            {
                rlutil::setColor(rlutil::WHITE);
                rlutil::locate(40,12);
                cout << "INGRESE ID ITEM MODIFICAR: ";

                rlutil::showcursor();
                cin >> idItem;
                cin.clear();
                rlutil::hidecursor();

                if(idItem < 0)
                {
                    rlutil::setColor(rlutil::RED);
                    rlutil::locate (40,13);
                    cout << "INGRESE UN ID VALIDO: ";

                    break;
                }
                else if(arc.buscarRegistroPorId(idItem) == -2)
                {
                    rlutil::setColor(rlutil::RED);
                    rlutil::locate (40,13);
                    cout << "NO SE ENCONTRO ITEM CON EL ID SELECCIONADO: ";

                    break;
                }

                rlutil::setColor(rlutil::WHITE);
                rlutil::locate (40,14);
                cout << "INGRESE EL NUEVO TIPO (1-ENTRADA | 2-PLATO PRINCIPAL | 3-POSTRE | 4-BEBIDA): ";
                rlutil::showcursor();
                int nuevoTipo;
                cin >> nuevoTipo;

                if(nuevoTipo < 1 || nuevoTipo > 4)
                {
                    rlutil::setColor(rlutil::RED);
                    rlutil::locate (40,15);
                    cout << "INGRESE UN TIPO VALIDO: ";

                    break;
                }
                int resultado = MessageBox(NULL, "Desea cambiar el tipo de este item de la carta?", "CAMBIAR TIPO ITEM", MB_YESNO|MB_ICONQUESTION);
                if (resultado==IDYES) //&& SI LA OPERACION FUE EXITOSA
                {
                    if(arc.modificarTipoRegistro(nuevoTipo, idItem))
                    {
                        MessageBox(NULL,"Tipo actualizado exitosamente", "OPERACION EXITOSA", MB_OK|MB_ICONINFORMATION);
                    }
                }
                rlutil::cls();
                mostrarConfigurarCarta();
                break;
            }
            case 60:     /// ACTUALIZAR ESTADO
            {
                rlutil::setColor(rlutil::WHITE);
                rlutil::locate (40,12);
                cout << "INGRESE ID ITEM MODIFICAR: ";

                rlutil::showcursor();
                cin >> idItem;
                cin.clear();
                rlutil::hidecursor();

                if(idItem < 0)
                {
                    rlutil::setColor(rlutil::RED);
                    rlutil::locate (40,13);
                    cout << "INGRESE UN ID VALIDO: ";

                    break;
                }
                else if(arc.buscarRegistroPorId(idItem) == -2)
                {
                    rlutil::setColor(rlutil::RED);
                    rlutil::locate (40,13);
                    cout << "NO SE ENCONTRO ITEM CON EL ID SELECCIONADO: ";

                    break;
                }

                int resultado = MessageBox(NULL, "Desea cambiar el estado de este item de la carta?", "CAMBIAR ESTADO ITEM", MB_YESNO|MB_ICONQUESTION);
                if (resultado==IDYES) //&& SI LA OPERACION FUE EXITOSA
                {
                    if(arc.cambiarEstadoRegistro(idItem))
                    {
                        MessageBox(NULL,"Estado actualizado exitosamente", "OPERACION EXITOSA", MB_OK|MB_ICONINFORMATION);
                    }
                }
                rlutil::cls();
                mostrarConfigurarCarta();
                break;
            }
            case 80:
            {
                rlutil::cls();
                mostrarConfigurarCarta();
                break;
            }
            }
        }
    }
    while(true);
}
void opcionesModificarUsuario()
{
    int x = 0;
    ArchivoUsuario arc;
    Usuario obj;
    int idUsuario;
    do
    {
        rlutil::setColor (rlutil::WHITE);
        pintarOpciones("DNI",40,9, x==0);
        pintarOpciones("NOMBRE",60,9, x==20);
        pintarOpciones("ROL",80,9, x==40);
        pintarOpciones("ESTADO",100,9, x==60);
        pintarOpciones("VOLVER",120,9, x==80);
        limpiarDesdePosicion(40,10,100,5);
        rlutil::locate(39+x,9);
        cout << char(16);
        int key = rlutil::getkey();
        rlutil::locate(39+x, 9);
        cout << " ";

        switch (key)
        {
        case 17:
            x+=20;
            if(x>80) x=80;
            break;
        case 16:
            x-=20;
            if(x<0) x=0;
            break;
        case 1:
            limpiarDesdePosicion(40,10,100,5);

            switch (x)
            {
            case 0:     /// ACTUALIZAR DNI
            {
                rlutil::setColor(rlutil::WHITE);
                rlutil::locate (40,12);
                cout << "INGRESE ID USUARIO A MODIFICAR: ";

                rlutil::showcursor();
                cin >> idUsuario;
                cin.clear();
                rlutil::hidecursor();

                if(idUsuario < 0)
                {
                    rlutil::setColor(rlutil::RED);
                    rlutil::locate (40,13);
                    cout << "INGRESE UN ID VALIDO: ";

                    break;
                }
                else if(arc.buscarRegistro(idUsuario) == -2)
                {
                    rlutil::setColor(rlutil::RED);
                    rlutil::locate (40,13);
                    cout << "NO SE ENCONTRO USUARIO CON EL ID SELECCIONADO: ";

                    break;
                }

                int pos = arc.buscarRegistro(idUsuario);

                rlutil::setColor(rlutil::WHITE);
                rlutil::locate (40,14);
                cout << "INGRESE EL NUEVO DNI: ";
                rlutil::showcursor();
                char nuevoDNI[10];
                cargarCadena(nuevoDNI, 10);

                int resultado = MessageBox(NULL, "Desea cambiar el dni de este usuario?", "CAMBIAR DNI USUARIO", MB_YESNO|MB_ICONQUESTION);
                if (resultado==IDYES) //&& SI LA OPERACION FUE EXITOSA
                {
                    if(arc.modificarDNIRegistro(nuevoDNI, idUsuario))
                    {
                        MessageBox(NULL,"DNI actualizado exitosamente", "OPERACION EXITOSA", MB_OK|MB_ICONINFORMATION);
                    }
                }
                rlutil::cls();
                mostrarEmpleados();
                break;
            }
            case 20:        /// ACTUALIZAR NOMBRE
            {
                rlutil::setColor(rlutil::WHITE);
                rlutil::locate (40,12);
                cout << "INGRESE ID USUARIO A MODIFICAR: ";

                rlutil::showcursor();
                cin >> idUsuario;
                cin.clear();
                rlutil::hidecursor();

                if(idUsuario < 0)
                {
                    rlutil::setColor(rlutil::RED);
                    rlutil::locate (40,13);
                    cout << "INGRESE UN ID VALIDO: ";

                    break;
                }
                else if(arc.buscarRegistro(idUsuario) == -2)
                {
                    rlutil::setColor(rlutil::RED);
                    rlutil::locate (40,13);
                    cout << "NO SE ENCONTRO USUARIO CON EL ID SELECCIONADO: ";

                    break;
                }
                rlutil::setColor(rlutil::WHITE);
                rlutil::locate (40,14);
                cout << "INGRESE EL NUEVO NOMBRE: ";
                rlutil::showcursor();
                char nuevoNombre[50];
                cargarCadena(nuevoNombre, 50);

                int resultado = MessageBox(NULL, "Desea cambiar el nombre de este usuario?", "CAMBIAR NOMBRE USUARIO", MB_YESNO|MB_ICONQUESTION);
                if (resultado==IDYES) //&& SI LA OPERACION FUE EXITOSA
                {
                    if(arc.modificarNombreRegistro(nuevoNombre, idUsuario))
                    {
                        MessageBox(NULL,"Nombre actualizado exitosamente", "OPERACION EXITOSA", MB_OK|MB_ICONINFORMATION);
                    }
                }
                rlutil::cls();
                mostrarEmpleados();
                break;
            }
            case 40:     /// ACTUALIZAR ROL
            {
                rlutil::setColor(rlutil::WHITE);
                rlutil::locate(40,12);
                cout << "INGRESE ID USUARIO A MODIFICAR: ";

                rlutil::showcursor();
                cin >> idUsuario;
                cin.clear();
                rlutil::hidecursor();

                if(idUsuario < 0)
                {
                    rlutil::setColor(rlutil::RED);
                    rlutil::locate(40,13);
                    cout << "INGRESE UN ID VALIDO: ";

                    break;
                }
                else if(arc.buscarRegistro(idUsuario) == -2)
                {
                    rlutil::setColor(rlutil::RED);
                    rlutil::locate (40,13);
                    cout << "NO SE ENCONTRO USUARIO CON EL ID SELECCIONADO: ";

                    break;
                }

                rlutil::setColor(rlutil::WHITE);
                rlutil::locate (40,14);

                int resultado = MessageBox(NULL, "Desea cambiar el rol de este usuario?", "CAMBIAR ROL USUARIO", MB_YESNO|MB_ICONQUESTION);
                if (resultado==IDYES) //&& SI LA OPERACION FUE EXITOSA
                {
                    if(arc.modificarRolRegistro(idUsuario))
                    {
                        MessageBox(NULL,"Rol actualizado exitosamente", "OPERACION EXITOSA", MB_OK|MB_ICONINFORMATION);
                    }
                }
                rlutil::cls();
                mostrarEmpleados();
                break;
            }
            case 60:     /// ACTUALIZAR ESTADO
            {
                rlutil::setColor(rlutil::WHITE);
                rlutil::locate (40,12);
                cout << "INGRESE ID USUARIO A MODIFICAR: ";

                rlutil::showcursor();
                cin >> idUsuario;
                cin.clear();
                rlutil::hidecursor();

                if(idUsuario < 0)
                {
                    rlutil::setColor(rlutil::RED);
                    rlutil::locate (40,13);
                    cout << "INGRESE UN ID VALIDO: ";

                    break;
                }
                else if(arc.buscarRegistro(idUsuario) == -2)
                {
                    rlutil::setColor(rlutil::RED);
                    rlutil::locate (40,13);
                    cout << "NO SE ENCONTRO USUARIO CON EL ID SELECCIONADO: ";

                    break;
                }

                int resultado = MessageBox(NULL, "Desea cambiar el estado de este Usuario?", "CAMBIAR ESTADO USUARIO", MB_YESNO|MB_ICONQUESTION);
                if (resultado==IDYES) //&& SI LA OPERACION FUE EXITOSA
                {
                    if(arc.cambiarEstadoRegistro(idUsuario))
                    {
                        MessageBox(NULL,"Estado actualizado exitosamente", "OPERACION EXITOSA", MB_OK|MB_ICONINFORMATION);
                    }
                }
                rlutil::cls();
                mostrarEmpleados();
                break;
            }
            case 80:
            {
                rlutil::cls();
                mostrarEmpleados();
                break;
            }
            }
        }
    }
    while(true);
}

void limpiarDesdePosicion(int x, int y, int ancho, int alto) {
    for (int i = 0; i < alto; ++i) {
        rlutil::locate(x, y + i);
        for (int j = 0; j < ancho; ++j) {
            cout << " ";
        }
    }
}

