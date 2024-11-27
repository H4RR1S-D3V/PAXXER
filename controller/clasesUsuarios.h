#pragma once

class Usuario
{
    private:
        char _nombre[50];
        int _id;
        char _dni[10];
        bool _estado = true;
        int _rol = 0; /// 1-EMPLEADO (USER) 2-ENCARGADO (ADMIN)
        char _password[12] = "";
    public:
        Usuario();
        Usuario(char* nombre, char* dni, int rol, char* password);
        /// SETTERS
        void setId(int id);
        void setRol(int rol);
        void setNombre(const char* nombre);
        void setDNI(const char *DNI);
        void setPassword(const char* newPassword[12]);
        /// GETTERS
        int getId();
        char* getDNI();
        int getRol();
        bool getEstado();
        const char* getNombre();
        const char* getPassword();

        /// METHODS
        void Cargar();
        void Mostrar();
        void cambiarEstado();
};

