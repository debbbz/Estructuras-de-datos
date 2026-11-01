#ifndef COLA_HPP
#define COLA_HPP

#include "nodoCola.hpp"
#include <iostream>

class Cola
{
    public:
        Cola();
        ~Cola();
        void insertar(Persona p);
        Persona eliminar();
        void mostrar();
        void vaciarCola();
        int mostrarCantidad();
    
    private:
        int longitud;
        pnodoCola ultimo;
        pnodoCola primero;
};

#endif