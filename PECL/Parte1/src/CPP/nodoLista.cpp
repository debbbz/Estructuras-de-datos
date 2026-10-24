#include "nodoLista.hpp"

NodoLista::NodoLista(Persona p, NodoLista *ant, NodoLista *sig)
{
    persona = p;
    anterior = ant;
    siguiente = sig;
}

NodoLista::~NodoLista()
{

}