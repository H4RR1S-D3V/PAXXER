#include <iostream>
#include "../rlutil.h"
#include "windows.h"

using namespace std;

#include "declaracionInformesRecaudaciones.h"
#include "funcionesDibujar.h"
#include "menuPrincipal.h"
#include "../controller/clasesArchivosFacturas.h"
#include "../controller/clasesArchivosUsuarios.h"
#include "../controller/ClasesFactura.h"


void mostrarRecaudacionesPorFecha()
{
    ArchivoFactura arc;
    int x=0;
    bool salir=true;
    do
    {

        rlutil::hidecursor();
        rlutil::setColor (rlutil::LIGHTCYAN);
        dibujarBordesPantallas(42,16);
        rlutil::setColor (rlutil::BROWN);
        rlutil:: locate (60,15);
         rlutil::setColor (rlutil:: WHITE);
        cout << "R E C A U D A C I O N E S   P O R   F E C H A";

        pintarOpciones("FILTRAR POR MES",55,17, x==0);
        pintarOpciones("FILTRAR POR ANIO",90,17, x==35);
        pintarOpciones("VOLVER A INFORMES",125,17, x==70);
    rlutil:: locate (54+x,17);
        cout << char (16);
        int key=rlutil::getkey();
        rlutil::locate(54 + x, 17);
        cout << " ";

        switch (key)
        {
        case 17:

            x+=35;
            if (x>105) x=105;

            break;
        case 16:

            x-=35;
            if (x<0) x=0;
            break;

        case 1:
            switch (x)
            {
            case 0:{
                int valor;
                dibujarBordeSyI (10,19);
                dibujarBordeSyI (10,21);
                dibujarBordesDeI (10,20,20);
                dibujarBordesDeI (160,20,20);
                rlutil::setColor (rlutil::BROWN);
                /// LIMPIAR TABLA
                int cantRegistrosTotal = arc.contarRegistros();
                limpiarDesdePosicion(11, 22, 149, cantRegistrosTotal);
                rlutil:: locate (70,23);
                cout << "INGRESE EL MES QUE DESEA VER";
                rlutil:: locate (70,24);
                rlutil::showcursor();
                cin >> valor;
                rlutil::hidecursor();
                /// LIMPIAR TABLA
                limpiarDesdePosicion(11, 22, 149, cantRegistrosTotal);
                if (valor < 1 || valor > 12 || cin.fail()){
                    rlutil::locate(70,24);
                    cout << "Por favor ingrese un mes valido";
                    cin.clear();
                    cin.ignore(1000,'\n');
                } else {
                ///FETCH
                float recaudacion = arc.listarRegistrosPorMes(valor);
                rlutil:: locate (40,20);
                cout << "MES " << valor << "      ";
                rlutil:: locate (100,20);
                cout << "RECAUDACION: $" << recaudacion << "      ";
                break;
                if (recaudacion == 0) {rlutil::locate(58,24); cout << "No se encontraron registros con el criterio ingresado";}
                }
            }
            case 35:{
                int valor;
                dibujarBordeSyI (10,19);
                dibujarBordeSyI (10,21);
                dibujarBordesDeI (10,20,20);
                dibujarBordesDeI (160,20,20);
                rlutil::setColor (rlutil::BROWN);
                /// LIMPIAR TABLA
                int cantRegistrosTotal = arc.contarRegistros();
                limpiarDesdePosicion(11, 22, 149, cantRegistrosTotal);
                rlutil:: locate (70,23);
                cout << "INGRESE EL A"<< char(165)<< "O QUE DESEA VER";
                rlutil:: locate (70,24);
                rlutil::showcursor();
                cin >> valor;
                rlutil::hidecursor();
                /// LIMPIAR TABLA
                limpiarDesdePosicion(11, 22, 149, cantRegistrosTotal);
                if (valor < 1990 || valor > 4000 || cin.fail()){
                    rlutil::locate(70,24);
                    cout << "Por favor ingrese un a"<< char(164) <<"o valido";
                    cin.clear();
                    cin.ignore(1000,'\n');
                } else {
                ///FETCH
                float recaudacion = arc.listarRegistrosPorAnio(valor);
                rlutil:: locate (40,20);
                cout << "A"<< char(165)<< "O: " << valor << "      ";
                rlutil:: locate(100,20);
                cout << "RECAUDACION: $" << recaudacion << "       ";
                if (recaudacion == 0) {rlutil::locate(58,24); cout << "No se encontraron registros con el criterio ingresado";}
                }
                break;
            }
            case 70:
                rlutil::cls();
                salir=false;
                break;
            }
            break;
        }
    }
    while (salir==true);
}

void mostrarRecaudacionesPorTurno()
{
    ArchivoFactura arc;
    int x=0;
    bool salir=true;
    do
    {

        rlutil::hidecursor();
        rlutil::setColor (rlutil::LIGHTCYAN);

        dibujarBordesPantallas(42,16);
        rlutil::setColor (rlutil::BROWN);
        rlutil:: locate (56,15);
        cout << "R E C A U D A C I O N E S   P O R   T  U  R  N  O";
        rlutil::setColor (rlutil::WHITE);
        pintarOpciones("TURNO MANIANA",40,17, x==0);
        pintarOpciones("TURNO TARDE",60,17, x==20);
        pintarOpciones("TURNO NOCHE",80,17, x==40);
        pintarOpciones("VOLVER A INFORMES",100,17, x==60);
            rlutil:: locate (39+(x),17);
            cout <<char (16);
        int key=rlutil::getkey();
            rlutil:: locate (39+(x),17);
            cout << " ";
        switch (key)
        {
        case 17:
            x+=20;
            if (x>60) x=60;

            break;
        case 16:

            x-=20;
            if (x<0) x=0;
            break;

        case 1:
            switch (x)
            {
            case 0:{
                dibujarBordeSyI (10,19);
                dibujarBordeSyI (10,21);
                dibujarBordesDeI (10,20,20);
                dibujarBordesDeI (160,20,20);
                rlutil::setColor (rlutil::BROWN);
                /// LIMPIAR TABLA
                int cantRegistrosTotal = arc.contarRegistros();
                limpiarDesdePosicion(11, 22, 149, cantRegistrosTotal);
                ///FETCH
                float recaudacion = arc.listarRegistrosPorTurno(1); /// 1-MANIANA / 2-TARDE / 3-NOCHE
                rlutil:: locate (40,20);
                cout << "MANIANA   ";
                rlutil:: locate (100,20);
                cout << "RECAUDACION: $" << recaudacion << "    ";
                if (recaudacion == 0) {rlutil::locate(58,24); cout << "No se encontraron registros con el criterio ingresado";}
                break;
                }
            case 20:{
                dibujarBordeSyI (10,19);
                dibujarBordeSyI (10,21);
                dibujarBordesDeI (10,20,20);
                dibujarBordesDeI (160,20,20);
                rlutil::setColor (rlutil::BROWN);
                /// LIMPIAR TABLA
                int cantRegistrosTotal = arc.contarRegistros();
                limpiarDesdePosicion(11, 22, 149, cantRegistrosTotal);
                ///FETCH
                float recaudacion = arc.listarRegistrosPorTurno(2); /// 1-MANIANA / 2-TARDE / 3-NOCHE
                rlutil:: locate (40,20);
                cout << "TARDE   ";
                rlutil:: locate (100,20);
                cout << "RECAUDACION: $" << recaudacion << "   ";
                if (recaudacion == 0) {rlutil::locate(58,24); cout << "No se encontraron registros con el criterio ingresado";}
                break;
                }
            case 40:{
                dibujarBordeSyI (10,19);
                dibujarBordeSyI (10,21);
                dibujarBordesDeI (10,20,20);
                dibujarBordesDeI (160,20,20);
                rlutil::setColor (rlutil::BROWN);
                /// LIMPIAR TABLA
                int cantRegistrosTotal = arc.contarRegistros();
                limpiarDesdePosicion(11, 22, 149, cantRegistrosTotal);
                ///FETCH
                float recaudacion = arc.listarRegistrosPorTurno(3); /// 1-MANIANA / 2-TARDE / 3-NOCHE
                rlutil:: locate (40,20);
                cout << "NOCHE    ";
                rlutil:: locate (100,20);
                cout << "RECAUDACION: $" << recaudacion << "    ";
                if (recaudacion == 0) {rlutil::locate(58,24); cout << "No se encontraron registros con el criterio ingresado";}
                break;
                }
            case 60:

                rlutil::cls();
                salir=false;
                break;

            }
            break;
        }
    }
    while (salir==true);

}

void mostrarRecaudacionesPorTipoDePedido()
{
    ArchivoFactura arc;
    int x=0;
    bool salir=true;
    do
    {
        rlutil::hidecursor();
        rlutil::setColor (rlutil::LIGHTCYAN);
        dibujarBordesPantallas(42,16);
        rlutil::setColor (rlutil::BROWN);
        rlutil:: locate (50,15);
        cout << "R E C A U D A C I O N E S   P O R   T I P O   D E   P E D I D O";
        rlutil::setColor (rlutil::WHITE);
        pintarOpciones("POR LOCAL",20,17, x==0);
        pintarOpciones("POR DELIVERY",50,17, x==30);
        pintarOpciones("POR TAKE AWAY",80,17, x==60);
        pintarOpciones("VOLVER A INFORMES",110,17, x==90);

        rlutil:: locate (19+(x),17);
            cout <<char (16);
        int key=rlutil::getkey();
            rlutil:: locate (19+(x),17);
            cout << " ";
        switch (key)
        {
        case 17:
              rlutil:: locate (19+(x),17);
            cout << char (16);
            rlutil:: locate (19+(x),17);
            cout << " ";
            x+=30;
            if (x>90) x=90;

            break;
        case 16:
             rlutil:: locate (19+(x),17);
            cout << char (16);
            rlutil:: locate (19+(x),17);
            cout << " ";
            x-=30;
            if (x<0) x=0;
            break;

        case 1:
            switch (x)
            {
            case 0:{
                dibujarBordeSyI (10,19);
                dibujarBordeSyI (10,21);
                dibujarBordesDeI (10,20,20);
                dibujarBordesDeI (160,20,20);
                rlutil::setColor (rlutil::BROWN);
                /// LIMPIAR TABLA
                int cantRegistrosTotal = arc.contarRegistros();
                limpiarDesdePosicion(11, 22, 149, cantRegistrosTotal);
                ///FETCH
                float recaudacion = arc.listarRegistrosPorTipo(1); /// 1-LOCAL / 2-DELIVERY / 3-TAKEAWAY
                rlutil::locate(40,20);
                cout << "LOCAL   ";
                rlutil:: locate (100,20);
                cout << "RECAUDACION: $" << recaudacion << "      ";
                if (recaudacion == 0) {rlutil::locate(58,24); cout << "No se encontraron registros con el criterio ingresado";}
                break;
                }

            case 30:{
                dibujarBordeSyI (10,19);
                dibujarBordeSyI (10,21);
                dibujarBordesDeI (10,20,20);
                dibujarBordesDeI (160,20,20);
                rlutil::setColor (rlutil::BROWN);
                /// LIMPIAR TABLA
                int cantRegistrosTotal = arc.contarRegistros();
                limpiarDesdePosicion(11, 22, 149, cantRegistrosTotal);
                ///FETCH
                float recaudacion = arc.listarRegistrosPorTipo(2); /// 1-LOCAL / 2-DELIVERY / 3-TAKEAWAY
                rlutil:: locate (40,20);
                cout << "DELIVERY   ";
                rlutil:: locate (100,20);
                cout << "RECAUDACION: $" << recaudacion << "    ";
                if (recaudacion == 0) {rlutil::locate(58,24); cout << "No se encontraron registros con el criterio ingresado";}
                break;
                }
            case 60:
                {
                dibujarBordeSyI (10,19);
                dibujarBordeSyI (10,21);
                dibujarBordesDeI (10,20,20);
                dibujarBordesDeI (160,20,20);
                rlutil::setColor (rlutil::BROWN);
                /// LIMPIAR TABLA
                int cantRegistrosTotal = arc.contarRegistros();
                limpiarDesdePosicion(11, 22, 149, cantRegistrosTotal);
                ///FETCH
                float recaudacion = arc.listarRegistrosPorTipo(3); /// 1-LOCAL / 2-DELIVERY / 3-TAKEAWAY
                rlutil::locate(40,20);
                cout << "TAKE AWAY";
                rlutil::locate(100,20);
                cout << "RECAUDACION: $" << recaudacion << "     ";
                if (recaudacion == 0) {rlutil::locate(58,24); cout << "No se encontraron registros con el criterio ingresado";}
                break;
                }
            case 90:{
                rlutil::cls();
                salir=false;
                break;
            }
            break;
            }
        }
    }
    while (salir==true);
}

void mostrarRecaudacionesPorEmpleado()
{

    ArchivoFactura arc;
    int x=0;
    bool salir=true;
    do
    {

        rlutil::hidecursor();
        rlutil::setColor (rlutil::LIGHTCYAN);
        dibujarBordesPantallas(42,16);
        rlutil::setColor (rlutil::BROWN);
        rlutil:: locate (55,15);
        cout << "R E C A U D A C I O N E S   P O R   E M P L E A D O S";
        rlutil::setColor (rlutil::WHITE);
        pintarOpciones("POR ID",50,17, x==0);
        pintarOpciones("VOLVER A INFORMES",90,17, x==40);


        rlutil:: locate (49+(x),17);
            cout <<char (16);
        int key=rlutil::getkey();
            rlutil:: locate (49+(x),17);
            cout << " ";

        switch (key)
        {
        case 17:
            rlutil:: locate (49+(x),17);
            cout << " ";
            x+=40;
            if (x>40) x=40;
            break;
        case 16:
            rlutil:: locate (49+(x),17);
            cout << " ";
            x-=40;
            if (x<0) x=0;
            break;

        case 1:
            switch (x)
            {
            case 0:
                {
                int valor;
                dibujarBordeSyI (10,19);
                dibujarBordeSyI (10,21);
                dibujarBordesDeI (10,20,20);
                dibujarBordesDeI (160,20,20);
                rlutil::setColor (rlutil::BROWN);
                /// LIMPIAR TABLA
                int cantRegistrosTotal = arc.contarRegistros();
                limpiarDesdePosicion(11, 22, 149, cantRegistrosTotal);
                rlutil:: locate (70,23);
                cout << "INGRESE EL ID DEL EMPLEADO QUE DESEA VER";
                rlutil:: locate (70,24);
                rlutil::showcursor();
                cin >> valor;
                rlutil::hidecursor();
                /// LIMPIAR TABLA
                limpiarDesdePosicion(11, 22, 149, cantRegistrosTotal);
                if (valor < 1 || cin.fail()){
                    rlutil::locate(70,24);
                    cout << "Por favor ingrese una ID valida";
                    cin.clear();
                    cin.ignore(1000,'\n');
                } else {
                ///FETCH
                float recaudacion = arc.listarRegistrosPorResponsableID(valor);
                rlutil:: locate (40,20);
                cout << "ID: " << valor;
                rlutil::locate(100,20);
                cout << "RECAUDACION: $" << recaudacion;
                if (recaudacion == 0) {rlutil::locate(58,24); cout << "No se encontraron registros con el criterio ingresado";}
                }
                break;
                }
            case 40:
                rlutil::cls();
                salir=false;
                break;

            }
            break;
        }
    }
    while (salir==true);
}

void mostrarFacturaPorID()
{
ArchivoFactura arc;

    bool abierto = false;
    int x=0;
    bool salir=true;
    do
    {

        rlutil::hidecursor();
        rlutil::setColor (rlutil::LIGHTCYAN);
        dibujarBordesPantallas(42,abierto ? 6 : 16);
        rlutil::setColor (rlutil::BROWN);
        rlutil:: locate (70, abierto? 5 : 15);
        cout << "A B R I R   F A C T U R A";
        rlutil::setColor (rlutil::WHITE);
        pintarOpciones("POR ID",60,abierto ? 7 : 17, x==0);
        pintarOpciones("VOLVER A INFORMES",90, abierto ? 7 : 17, x==30);


        rlutil:: locate (59+(x),abierto ? 7 : 17);
            cout <<char (16);
        int key=rlutil::getkey();
            rlutil:: locate (59+(x),abierto ? 7 : 17);
            cout << " ";
        switch (key)
        {
        case 17:
            rlutil:: locate (59+(x),abierto ? 7 : 17);
            cout << " ";
            x+=30;
            if (x>30) x=30;
            break;
        case 16:
            rlutil:: locate (59+(x),abierto ? 7 : 17);
            cout << " ";
            x-=30;
            if (x<0) x=0;
            break;

        case 1:
            switch (x)
            {
            case 0:
                {
                int valor;
                rlutil::setColor (rlutil::BROWN);
                /// LIMPIAR TABLA
                /*
                int cantRegistrosTotal = arc.contarRegistros();
                limpiarDesdePosicion(11, 22, 149, cantRegistrosTotal);
                */
                limpiarDesdePosicion(50, abierto ? 9 : 19, 250, 1);
                rlutil:: locate (50,abierto ? 9 : 19);
                cout << "INGRESE EL ID DE LA FACTURA QUE QUIERE VER:";
                rlutil:: locate (94,abierto ? 9 : 19);
                rlutil::showcursor();
                cin >> valor;
                rlutil::hidecursor();
                /// LIMPIAR TABLA
                //limpiarDesdePosicion(11, 22, 149, cantRegistrosTotal);
                if (valor < 1 || cin.fail()){
                    limpiarDesdePosicion(50, abierto ? 9 : 19, 250, 1);
                    rlutil::locate(70, abierto ? 9 : 19);
                    cout << "Por favor ingrese una ID valida";
                    cin.clear();
                    cin.ignore(1000, '\n');
                } else {
                ///FETCH
                Factura obj;
                obj = arc.leerRegistro(valor-1);
                rlutil::cls();
                obj.mostrarFacturaDetalle();
                ///NUEVO MENU DE FACTURA
                abierto = true;


                //float recaudacion = arc.listarRegistrosPorResponsableID(valor);
                /*
                rlutil:: locate (40,20);
                cout << "ID: " << valor;
                rlutil::locate(100,20);
                cout << "RECAUDACION: $" << recaudacion;
                if (recaudacion == 0) {rlutil::locate(58,24); cout << "No se encontraron registros con el criterio ingresado";}
                    */
                }
                break;
                }
            case 30:
                rlutil::cls();
                salir=false;
                break;

            }
            break;
        }
    }
    while (salir==true);

}
