#include "nodoCola.hpp"

NodoCola::NodoCola(Persona p, NodoCola *nodo)
{
    persona = p;
    siguiente = nodo;
}

NodoCola::~NodoCola()
{
    
}