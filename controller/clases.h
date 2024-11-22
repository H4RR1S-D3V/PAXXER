#pragma once

#include <iostream>


using namespace std;

#include "generadorIDs.h"
#include "funciones.h"

/// FIN CLASES AUXILIARES





class Usuario
{
private:
    char _nombre[50];
    int _id;
    char _dni[10];
    bool _estado;
    int _rol; /// 1- usuario 2-administrador
public:
    Usuario();
    Usuario(char* nombre, char* dni);
    /// SETTERS
    void setId(int id);
    void setRol(int rol);
    void setNombre(const char* nombre);
    void setDNI(const char *DNI);
    /// GETTERS
    int getId();
    char* getDNI();
    int getRol();
    bool getEstado();
    const char* getNombre();
    /// METHODS
    void Cargar();
    void Mostrar();
    void cambiarEstado();
};

class Credencial
{
private:
    char _dni[10];
    char _password[12];
    public:
        /// SETTERS
        void setPassword(const char* newPassword[12]);
        /// GETTERS
        const char* getPassword();
};
