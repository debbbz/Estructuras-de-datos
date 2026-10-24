#include "Cola.hpp"

using namespace std;

Cola::Cola()
{
    longitud = 0;
    ultimo = nullptr;
    primero = nullptr;
}

void Cola::insertar(Persona p)
{
    pnodoCola nodo;

    nodo = new NodoCola(p);
    if (!primero)
    {
        ultimo = nodo;
        primero = nodo;
    }else
    {
        ultimo->siguiente = nodo;
        ultimo = nodo;
    }
    longitud++;
}

Persona Cola::eliminar()
{
    pnodoCola nodo;
    Persona v;

    if (!primero)
        return Persona();
    v = primero->persona;
    nodo = primero;
    primero = nodo->siguiente;
    delete(nodo);
    if (!primero)
        ultimo = nullptr;
    longitud--;
    return v;
}

void Cola::vaciarCola()
{
    pnodoCola nodoActual;
    pnodoCola nodoSiguiente;

    nodoActual = primero;
    nodoSiguiente = nullptr;
    while (nodoActual != nullptr)
    {
        nodoSiguiente = nodoActual->siguiente;
        delete nodoActual;
        nodoActual = nodoSiguiente;
    }
    primero = nullptr;
    ultimo = nullptr;
    longitud = 0;
}

int Cola::mostrarCantidad()
{
    return longitud;
}


void Cola::mostrar()
{
    pnodoCola nodo;

    nodo = primero;
    while (nodo)
    {
        cout << "El paciente cuyo DNI es " << nodo->persona.getDni() << " tiene ";
        if (nodo->persona.getEstado())
            cout << "apendicitis, su ID es: " << nodo->persona.getId() << " y su habitacion asignada es: " << nodo->persona.getHabitacion() <<endl;
        else
            cout << "hernias, su ID es: " << nodo->persona.getId() << " y su habitacion asignada es: " << nodo->persona.getHabitacion() <<endl;
        nodo = nodo->siguiente;
    }
}

Cola::~Cola()
{
    pnodoCola nodo;

    while (primero)
    {
        eliminar();
    }
}