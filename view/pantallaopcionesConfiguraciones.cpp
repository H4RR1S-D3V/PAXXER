#include <iostream>
#include <iomanip>
#include "../rlutil.h"

using namespace std;
#include "../controller/clasesArchivosFacturas.h"
#include "../controller/clasesArchivosUsuarios.h"
#include "pantallasMenuPrincipal.h"
#include "declaracionOpcionesConfiguraciones.h"
#include "funcionesDibujar.h"
#include "../controller/clasesUsuarios.h"

void mostrarConfigurarCarta()
{
    int x = 0;
    int idItem;
    string tipoPlato, nombrePlato;
    float precioPlato;
    int resultado;
    float nuevoPrecio;
    do
    {
        rlutil::hidecursor();
        rlutil::setColor (rlutil::LIGHTCYAN);
        dibujarBordesPantallas(42,3);
        dibujarBordesPantallas(42,5);
        rlutil::setColor (rlutil::BROWN);
        rlutil::locate(65, 4);
        cout << "M O D I F I C A R   C A R T A";

        rlutil::setColor(rlutil::LIGHTCYAN);
        dibujarBordeSyI(10,17);
        dibujarBordeSyI(10,19);
        dibujarBordesDeI(9,18,30);
        dibujarBordesDeI(160,18,30);
        rlutil::setColor (rlutil::MAGENTA);
        rlutil::locate(12, 18);
        cout<<"ID";
        rlutil::locate(25,18);
        cout<< "TIPO";
        rlutil::locate(70,18);
        cout<< "NOMBRE";
        rlutil::locate(120, 18);
        cout<< "PRECIO";
        rlutil::locate(135, 18);
        cout<< "ESTADO";

        ArchivoProducto arc;
        Producto obj;

        int posXinicial=13;
        int posYinicial=20;

        int j = 0;
        for (int i=0; i < arc.contarRegistros(); i++)
        {
            rlutil::setColor(rlutil::WHITE);
            obj = arc.leerRegistro(i);

            rlutil::locate(posXinicial, posYinicial+j);
            cout<< obj.getId();
            rlutil::locate(posXinicial+13,  posYinicial+j);
            cout <<obj.getTipo();
            rlutil::locate(posXinicial+50,  posYinicial+j);
            cout <<obj.getNombre();
            rlutil::locate(posXinicial+107,  posYinicial+j);
            cout <<fixed<<setprecision(2)<<obj.getPrecio();
            rlutil::locate(posXinicial+122,  posYinicial+j);
            if(obj.getDisponibilidad())
            {
                cout << "DISPONIBLE";
            }
            else
            {
                cout << "NO DISPONIBLE";
            }
            j++;
        }

        rlutil::setColor (rlutil::WHITE);
        pintarOpciones("AGREGAR ITEM",40,7, x==0);
        pintarOpciones("MODIFICAR ITEM",70,7, x==30);
        pintarOpciones("VOLVER A CONFIGURACIONES",100,7, x==60);

        rlutil::locate(39+x,7);
        cout << char(16);
        int key = rlutil::getkey();
        rlutil::locate(39+x, 7);
        cout << " ";

        switch (key)
        {
        case 17:
            x+=30;
            if (x>60) x=60;
            break;
        case 16:
            x-=30;
            if (x<0) x=0;
            break;
        case 1:
            switch (x)
            {
            case 0:     ///AGREGAR ITEM
            {
                Producto obj;
                obj.Cargar();
                arc.agregarRegistro(obj);
                MessageBox(NULL,"Item agregado exitosamente", "OPERACION EXITOSA", MB_OK|MB_ICONINFORMATION);

                rlutil::cls();
                mostrarConfigurarCarta();
                //ELSE IF (SI LA OPERACION NO FUE EXITOSA SE MUESTRA)
                //SELECCION=MessageBox(NULL,"No fue posible agregar el item. Desea intentarlo nuevamente?", "OPERACION FALLIDA", MB_OKCANCEL|MB_ICONINFORMATION);
                //if -->si==configurarCarta();
                //no--> VUELVE A CONFIGURACIONES

                break;
            }
            case 30:    ///MODIFICAR ITEM
                opcionesModificarItem();
                break;
            case 60:    ///VOLVER A CONFIGURACIONES

                rlutil::cls();
                mostrarConfiguraciones();
                break;

            }
        }
    }
        while(true);
}


void mostrarEmpleados()
{
    char dniEmpleado[10];
    char nombreEmpleado[50];

    int x=0;
    int y=0;
    bool salir=true;
    do
    {
        rlutil::hidecursor();
        rlutil::setColor (rlutil::LIGHTCYAN);
        dibujarBordesPantallas(42,3);
        dibujarBordesPantallas(42,5);
        rlutil::setColor (rlutil::MAGENTA);
        rlutil:: locate (65,4);
        cout << "L I S T A D O   D E   E M P L E A D O S";
        rlutil::setColor (rlutil::WHITE);



        dibujarBordeSyI(10, 16);
        dibujarBordeSyI(10, 18);
        rlutil::locate(30, 17);
        cout << "NOMBRE";
        rlutil::locate(80, 17);
        cout << "ID";
        rlutil::locate(120, 17);
        cout << "DNI";


        ArchivoUsuario arc;
        int cantEmp=arc.contarRegistros();
        int posXinicial=25;
        int posYinicial=19;
        int j=0;
        for (int i=0; i < cantEmp; i++)
        {
            Usuario obj;
            obj=arc.leerRegistro(i);
            if (obj.getEstado()){

                rlutil::setColor(rlutil::WHITE);
                rlutil::locate(posXinicial, posYinicial+j);
                cout<< obj.getNombre();
                rlutil::locate(posXinicial+55,  posYinicial+j);
                cout <<obj.getId();
                rlutil::locate(posXinicial+92,  posYinicial+j);
                cout <<obj.getDNI();

                j++;
            }
        }

        dibujarBordeSyI(10,posYinicial+j);


        pintarOpciones("ELIMINAR EMPLEADO",25,7, x==0);
        pintarOpciones("AGREGAR EMPLEADO",75,7, x==50);
        pintarOpciones("VOLVER A CONFIGURACIONES",125,7, x==100);
        rlutil:: locate (24+x,7);
        cout << char (16);
        int key=rlutil::getkey();
        rlutil::locate(24 + x, 7);
        cout << " ";




        switch (key)
        {
        case 17:
            x+=50;
            if (x>100) x=100;
            break;
        case 16:
            x-=50;
            if (x<0) x=0;
            break;
        case 1:
            switch (x)
            {
            case 0:
            {
                int id;
                rlutil:: locate (60,9);
                cout << "INGRESE ID DE EMPLEADO: ";
                rlutil::setCursorVisibility(true);
                cin >> id;
                rlutil::setCursorVisibility(false);
                rlutil::locate(55,11);
                cout << "PULSE ENTER PARA CONTINUAR";
                int seleccion=MessageBox(NULL, "Confirma eliminar a este empleado?", "ELIMINACION DE EMPLEADO", MB_YESNO);
                if (seleccion==6)
                {
                    ///Aqui logica de eliminar empleado
                    arc.cambiarEstadoRegistro(id);
                    MessageBox(NULL, "Eliminacion de empleado exitosa", "OPERACION EXITOSA", MB_OK);
                    rlutil::cls();
                }
                mostrarEmpleados();


            }
            break;
            case 50:
            {   ///AGREGAR TIPO Y CONTRASE;A SI HACE FALTA
                int tipoEmpleado;
                char password[50] = "";

                rlutil:: locate (60,9);
                cout << "INGRESE DNI DE EMPLEADO: ";
                rlutil::setCursorVisibility(true);
                cin >> dniEmpleado;
                rlutil::setCursorVisibility(false);
                rlutil:: locate (60,10);
                cout << "INGRESE NOMBRE DE EMPLEADO: ";
                rlutil::setCursorVisibility(true);
                cin >> nombreEmpleado;
                rlutil::setCursorVisibility(false);
                rlutil:: locate (60,11);
                cout << "INGRESE ROL (1-EMPLEADO | 2-ENCARGADO): ";
                rlutil::setCursorVisibility(true);
                cin >> tipoEmpleado;
                rlutil::setCursorVisibility(false);
                ///VERIFICA EL TIPO PARA ASIGNAR O NO PASS
                if( tipoEmpleado == 2){
                rlutil:: locate (60,12);
                cout << "INGRESE CONTRASEÑA: ";
                rlutil::setCursorVisibility(true);
                cin >> password;
                rlutil::setCursorVisibility(false);
                }
                rlutil::locate(55,13);
                cout << "PULSE ENTER PARA CONTINUAR";
                int seleccion=MessageBox(NULL, "Confirma agregar a este empleado?", "AGREGAR EMPLEADO", MB_YESNO);
                if (seleccion==6)
                {
                    ///Aqui logica de agregar empleado
                    Usuario obj(nombreEmpleado, dniEmpleado, tipoEmpleado, password);
                    arc.agregarRegistro(obj);
                    MessageBox(NULL, "Agrego el empleado exitosamente", "OPERACION EXITOSA", MB_OK);
                }
                    rlutil::cls();

                mostrarEmpleados();

            break;
            }
            case 100:
                rlutil::cls();
                salir=false;
                mostrarConfiguraciones();
                break;
            }
            break;
        }



    }
    while(salir==true);



}
