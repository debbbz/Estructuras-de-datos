#ifndef NODO_COLA_HPP
#define NODO_COLA_HPP
#include "persona.hpp"
class NodoCola
{
    public:
        NodoCola(Persona p, NodoCola *nodo = nullptr);
        ~NodoCola();
    private:
        Persona persona;
        NodoCola *siguiente;
        friend class Cola;
};
typedef NodoCola *pnodoCola;
#endif