#pragma once

void dibujarTituloPAXXER();
void dibujarTituloNUESTRACARTA();
void dibujarTituloINFORMES();
void dibujarTituloCONFIGURACIONES();
void dibujarTituloMAPAMESAS();
void dibujarTituloNUESTROSPEDIDOS();
void dibujarBordesMenuPrincipal(int posicionX, int posicionY);
void dibujarBordesPantallas(int posicionX, int posicionY);
void dibujarBordeSyI(int posicionX, int posicionY);
void dibujarBordesDeI(int posicionX, int posicionY, int largo);
void dibujarMesa(int posX, int posY);
void pintarOpciones(const char* texto, int posX, int posY, bool seleccion);

void opcionesModificarItem();

void limpiarDesdePosicion(int x, int y, int ancho, int alto);


