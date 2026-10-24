#ifndef NODO_PILA_HPP
#define NODO_PILA_HPP

#include <iostream>
#include "persona.hpp"
class NodoPila
{
    public:
        NodoPila(Persona p, NodoPila *nodo = nullptr);
        ~NodoPila();
        
    private:
        Persona persona;
        NodoPila *siguiente;
        friend class Pila;
};
typedef NodoPila *pnodoPila;
#endif