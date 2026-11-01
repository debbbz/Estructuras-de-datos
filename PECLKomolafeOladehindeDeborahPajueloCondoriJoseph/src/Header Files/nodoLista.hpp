#ifndef NODO_LISTA_HPP
#define NODO_LISTA_HPP

#include "persona.hpp"
#include <iostream>

class NodoLista
{
    public:
        NodoLista(Persona p, NodoLista *ant = nullptr, NodoLista *sig = nullptr);
        ~NodoLista();
    private:
        Persona persona;
        NodoLista *siguiente;
        NodoLista *anterior;
        friend class Lista;
};
typedef NodoLista *pnodoLista;

#endif