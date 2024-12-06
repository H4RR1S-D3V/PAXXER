#pragma once

#include "clasesUsuarios.h"
#include "constantes.h"

class ArchivoUsuario
{
    private:
        char _nombre[30];
        int _tamanioRegistro;
    public:
        ArchivoUsuario(const char* n=ARCHIVO_USUARIOS);
        bool agregarRegistro(Usuario &obj);
        int buscarRegistro(int id);
        int buscarRegistroDNI(char* DNI);
        Usuario leerRegistro(int pos);
        bool cambiarEstadoRegistro(int id);
        int contarRegistros();
        int contarRegistrosAdmin();
        bool listarRegistros();
        bool modificarNombreRegistro(const char *nombre, int id);
        bool modificarDNIRegistro(const char *DNI , int id);
        bool modificarRolRegistro(int id);
        void listarRegistrosPorNombre(const char *nombre);
        bool verificarCredenciales(const char* dni, const char* password);
};
