#include "persona.hpp"

Persona::Persona()
{
    nhabitacion = 0;
    id = 0;
    estado = (rand() % 2);
    generarDni();
}

bool Persona::getEstado()
{
    return estado;
}

int Persona::getHabitacion()
{
    return nhabitacion;
}

int Persona::getId()
{
    return id;
}

void Persona::generarDni()
{
    char letras[] = "TRWAGMYFPDXBNJZSQVHLCKE";
    int numDNI = 0;
    for (int i = 0; i < 8; i++)
    {
        int num = rand() % 10;
        this->dni[i] = '0' + num;
        numDNI = numDNI * 10 + num;
    }
    this->dni[8] = letras[numDNI % 23];
    this->dni[9] = '\0';
}

const char *Persona::getDni()
{
    return dni;
}

void Persona::setHabitacion(int habitacion)
{
    this->nhabitacion = habitacion;
}

void Persona::setId(int id)
{
    this->id = id;
}

void Persona::setEstado(bool estado)
{
    this->estado = estado;
}

Persona::~Persona()
{

}