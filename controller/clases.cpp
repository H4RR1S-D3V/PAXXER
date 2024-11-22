#include <iostream>
#include <string>
#include <cstring>

#include "clases.h"
#include "funciones.h"
#include "clasesArchivos.h"
#include "../rlutil.h"
#include "../view/declaracionOpcionesMapaMesas.h"
#include "../view/funcionesDibujar.h"
#include "../view/pantallasMenuPrincipal.h"
#include <cctype>


/// CLASE BASE USUARIO
Usuario::Usuario() {}

Usuario::Usuario(char* nombre, char* dni)
{
    strcpy(_nombre, nombre);
    strcpy(_dni, dni);
    _id = generarId(1);
}

// SETTERS
void Usuario::setId(int id)
{
    _id = id;
}
void Usuario::setNombre(const char* nombre)
{
    strcpy(_nombre, nombre);
}
void Usuario::setDNI(const char *DNI)
{
    strcpy(_dni, DNI);
}
void Usuario::setRol(int rol)
{
    if(rol != 1 || rol != 2)
    {
        cout << "INGRESE UN CODIGO DE ROL VALIDO:" << endl;
        cout << "1 - USUARIO | 2 - ADMINISTRADOR" << endl;
    }
}

// GETTERS
int Usuario::getId()
{
    return _id;
}
char* Usuario::getDNI()
{
    return _dni;
}
bool Usuario::getEstado()
{
    return _estado;
}
const char* Usuario::getNombre()
{
    return _nombre;
}
int Usuario::getRol()
{
    return _rol;
}

// METHODS
void Usuario::Cargar()
{
    cout << "INGRESE NOMBRE COMPLETO: " << endl;
    cargarCadena(_nombre, 50);

    cout << "INGRESE DNI: " << endl;
    cin >> _dni;

    _id=generarId(1);
}

void Usuario::Mostrar()
{
    cout << "NOMBRE: " << _nombre << endl;
    cout << "DNI: " << _dni << endl;
    cout << "ID: " << _id << endl;
}

void Usuario::cambiarEstado()
{
    _estado = !_estado;
}

/// CLASE BASE CREDENCIAL

void Credencial::setPassword(const char* newPassword[12])
{
    strcpy(_password, *newPassword);
}

const char* Credencial::getPassword()
{
    return _password;
}



