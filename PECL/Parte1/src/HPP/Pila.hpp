#ifndef PILA_HPP
#define PILA_HPP
#include "nodoPila.hpp"

class Pila
{
    public:
        Pila();
        ~Pila();
        void insertar(Persona persona);
        Persona eliminar();
        Persona cima();
        void mostrar();
        void vaciarPila();
        int mostrarCantidad();
    private:
        int longitud;
        pnodoPila ultimo;
};

#endif