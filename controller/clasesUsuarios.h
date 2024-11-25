#pragma once

class Usuario
{
    private:
        char _nombre[50];
        int _id;
        char _dni[10];
        bool _estado = true;
        int _rol = 0; /// 1-EMPLEADO (USER) 2-ENCARGADO (ADMIN)
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
        Credencial(char* dni);
        void Cargar();
        /// SETTERS
        void setPassword(const char* newPassword[12]);
        /// GETTERS
        const char* getPassword();
};
