
#include <iostream>
#include "../rlutil.h"
#include "windows.h"

using namespace std;
#include "menuPrincipal.h"
#include "funcionesDibujar.h"
#include "funcionesDibujarTitulos.h"
#include "pantallasMenuPrincipal.h"
#include "funcionesDibujarTitulos.h"
#include "../controller/clasesArchivosMesas.h"
#include "../controller/clasesArchivosUsuarios.h"
#include "declaracionOpcionesConfiguraciones.h"

void mostrarMenuPrincipal()
{
    int op=1;
    int y=0;
    do
    {
        //CHECKEAR SI HAY MESAS
        ArchivoMesasLocal arcLocal;
        int cantMesasInicio = arcLocal.contarRegistros();
        if(cantMesasInicio < 1) {
            // PANTALLA PETICION DE CANTIDAD
            int cantMesas;
            cout << "Parece que no hay mesas cargadas, indique cuantas quiere tener ";
            cin >> cantMesas;
            arcLocal.setearCantMesas(cantMesas);
        }

        //CHEKEAR SI HAY USUARIO ADMIN
        ArchivoUsuario arcUsuarios;
        int cantUsuariosInicio = arcUsuarios.contarRegistros();
        if (arcUsuarios.contarRegistrosAdmin() < 1){
            MessageBox(NULL, "NO HAY USUARIOS ADMINISTRADOR, POR FAVOR GENERE UNO", "ERROR NO ADMINISTRADORES", MB_OK);
            mostrarEmpleados();
        }

        rlutil::hidecursor();
        dibujarBordesMenuPrincipal(42,19);
        dibujarTituloPAXXER();
        dibujarBordesMenuPrincipal(42,10);
        rlutil::setColor(rlutil::LIGHTCYAN);
        rlutil::locate(65,21);
        cout << "R    E    S    T    O   -   B    A    R";
        rlutil::setColor(rlutil::WHITE);
        pintarOpciones("MESAS", 84, 24, y==0);
        pintarOpciones("CARTA", 84, 26, y==2);
        pintarOpciones("INFORMES", 83, 28, y==4);
        pintarOpciones("CONFIGURACION", 80, 30, y==6);
        pintarOpciones("SALIR", 84, 32, y==8);

        int key=rlutil::getkey();

        switch (key)
        {
        case 14:
            /*rlutil::locate(78,24+(y));
            cout << " ";
            rlutil::locate(95,24+(y));
            cout << " ";*/
            y -= 2;
            if (y < 0) y = 0;
            break;
        case 15:
            /*rlutil::locate(78,24+(y));
            cout << " ";
            rlutil::locate(95,24+(y));
            cout << " ";*/
            y += 2;
            if (y > 8) y = 8;
            break;
        case 1:
            switch (y)
            {
            case 0:  ///MESAS
            {
                rlutil::cls();
                mostrarMapaMesas();
                break;
            }
            case 2:  ///CARTA
            {

                rlutil::cls();
                mostrarCarta();

                break;
            }
            case 4: ///INFORMES
            {
                int resultado=MessageBox(NULL,"�Desea ingresar su contrase�a de Encargado?","INGRESO RESTRINGIDO - SOLO ENCARGADOS",MB_OKCANCEL|MB_ICONINFORMATION);
                if (resultado==IDOK)
                {
                    rlutil::cls();
                    pantallaContrasenaI();
                }

                break;
            }



            case 6: ///CONFIGURACION
            {
                int resultado=MessageBox(NULL,"�Desea ingresar su contrase�a de Encargado?","INGRESO RESTRINGIDO - SOLO ENCARGADOS",MB_OKCANCEL|MB_ICONINFORMATION);
                if (resultado==IDOK)
                {
                    rlutil::cls();
                    pantallaContrasenaC();
                }
                 break;
            }


            case 8:  ///SALIR
            {
               rlutil::cls();
               cout << "SALIENDO DEL PROGRAMA..."<< endl;
              rlutil::setColor(rlutil::BLACK);
                exit(0);

                break;
            }
            }

        }


    }
    while (op!=0);
}
