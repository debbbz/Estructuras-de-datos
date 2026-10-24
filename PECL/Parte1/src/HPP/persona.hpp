#ifndef PERSONA_HPP
#define PERSONA_HPP

#include <iostream>
class Persona
{
    public:
        Persona();
        int getHabitacion();
        int getId();
        const char * getDni();
        bool getEstado();
        void setHabitacion(int habitacion);
        void setId(int id);
        void setEstado(bool estado);
        ~Persona();
    private:
        int nhabitacion;
        char dni[10];
        int id;
        bool estado;
        void generarDni();
};

#endif