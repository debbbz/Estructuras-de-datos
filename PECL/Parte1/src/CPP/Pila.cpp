#include "Pila.hpp"
using namespace std;

Pila::Pila()
{
    ultimo = nullptr;
    longitud = 0;
}

void Pila::insertar(Persona persona)
{
    pnodoPila nodo;

    nodo = new NodoPila(persona, ultimo);
    ultimo = nodo;
    longitud++;
}

Persona Pila::eliminar()
{
    pnodoPila nodo;
    Persona v;

    if (!ultimo)
        return Persona();
    v = ultimo->persona;
    nodo = ultimo;
    ultimo = nodo->siguiente;
    delete nodo;
    longitud--;
    return v;
}

Persona Pila::cima()
{
    if (!ultimo)
        return Persona();
    return ultimo->persona;
}

int Pila::mostrarCantidad()
{
    return longitud;
}

void Pila::mostrar()
{
    pnodoPila nodo;

    nodo = ultimo;
    while (nodo)
    {
        cout << "El paciente cuyo DNI es " << nodo->persona.getDni() << " tiene ";
        if (nodo->persona.getEstado())
            cout << "apendicitis" << endl;
        else
            cout << "hernias" << endl;
        nodo = nodo->siguiente;
    }
}

void Pila::vaciarPila()
{
    pnodoPila nodoActual;
    pnodoPila nodoSiguiente;

    nodoActual = ultimo;
    nodoSiguiente = nullptr;
    while (nodoActual != nullptr)
    {
        nodoSiguiente = nodoActual->siguiente;
        delete nodoActual;
        nodoActual = nodoSiguiente;
    }
    ultimo = nullptr;
    longitud = 0;
}

Pila::~Pila()
{
    while (ultimo)
    {
        eliminar();
    }
}