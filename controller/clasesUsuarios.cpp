#include <iostream>
#include <cstring>

#include "clasesUsuarios.h"
#include "funciones.h"

using namespace std;

/// CLASE USUARIO

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
void Usuario::setPassword(const char* newPassword[12])
{
    strcpy(_password, *newPassword);
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
const char* Usuario::getPassword()
{
    return _password;
}
//METHODS
Usuario::Usuario(){}
//CONSTRUCTOR PARA RECIBIR PARAMS DEL FRONT
Usuario::Usuario(char* nombre, char* dni, int rol, char* password)
{
    strcpy(_nombre, nombre);
    strcpy(_dni, dni);
    _rol = rol;

    if (_rol == 2){ /// ASIGNAR PASS SOLO SI ES ADMIN
    strcpy(_password, password);
    }


    _id = generarId(1);
}
void Usuario::Cargar() /// FUNCION A BORRAR?
{
    cout << "INGRESE NOMBRE COMPLETO: " << endl;
    cargarCadena(_nombre, 50);

    cout << "INGRESE DNI: " << endl;
    cin >> _dni;

    while(_rol != 1 && _rol != 2){
    cout << "INGRESE ROL DE EMPLEADO: (1-EMPLEADO 2-ENCARGADO)" << endl;
    cin >> _rol;

    if (_rol != 1 && _rol != 2){
        cout << "EL VALOR INGRESADO NO ES CORRECTO, INTENTE DE NUEVO";
    }
    }

    if (_rol == 2){


    }

    _id=generarId(1);
}
void Usuario::Mostrar()
{
    cout << "NOMBRE: " << _nombre << endl;
    cout << "DNI: " << _dni << endl;
    cout << "ID: " << _id << endl;
    if(_rol == 1){
        cout << "ROL: " << "Empleado";
    } else {cout << "ROL: " << "Encargado";};
}
void Usuario::cambiarEstado()
{
    _estado = !_estado;
}
/// FIN CLASE USUARIO

/// CLASE CREDENCIAL

//SETTERS

//GETTERS

/// FIN CLASE CREDENCIAL
