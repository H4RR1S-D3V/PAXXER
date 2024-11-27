#include <iostream>
#include <cstring>

#include "clasesAuxiliares.h"
#include "../rlutil.h"

using namespace std;

string horaActual(){
Tiempo tiempo;
    int hora = tiempo.getHora();
    int mins = tiempo.getMinutos();
    string HHMM = (hora < 10 ? "0" : "") + to_string(hora) + ":" +
                       (mins < 10 ? "0" : "") + to_string(mins);
return HHMM;
}

Fecha fechaActual(){
Tiempo tiempo;
return tiempo.getFecha();
}

void cargarCadena(char *pal, int tam){
    int i;
    fflush (stdin); ///limpia el buffer de entrada para que la carga se haga sin caracteres que hayan quedado sin usar
    for(i=0; i<tam;i++){
        pal[i]=cin.get();
        if(pal[i]=='\n')break;
    }
    pal[i]='\0';
    fflush(stdin); ///vuelve a limpiar el buffer para eliminar los caracteres sobrantes
}

void borrarLinea(int x, int y)
{
    rlutil::locate(x, y); // Posiciona el cursor
    cout << string(70, ' '); // Sobrescribe la línea con espacios
    rlutil::locate(x, y); // Devuelve el cursor al inicio de la línea
}
