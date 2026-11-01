#include "nodoPila.hpp"

NodoPila::NodoPila(Persona p, NodoPila *nodo)
{
    siguiente = nodo;
    persona = p;
}

NodoPila::~NodoPila()
{
    
}
