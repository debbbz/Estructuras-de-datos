#include "lista.hpp"
using namespace std;
Lista::Lista()
{
    longitud = 0;
    primero = nullptr;
    ultimo = nullptr;
}

void Lista::insertar(Persona p)
{
    pnodoLista nodo;

    nodo = new NodoLista(p, ultimo, nullptr);
    if (!primero)
    {
        primero = nodo;
    }
    else
    {
        ultimo->siguiente = nodo;
    }
    ultimo = nodo;
    longitud++;
}
Persona Lista::eliminar()
{
    pnodoLista nodo;
    Persona p;
    if (!primero)
        return Persona();
    nodo = primero;
    primero = nodo->siguiente;
    p = nodo->persona;
    delete nodo;
    longitud--;
    if (!primero)
        ultimo = nullptr;
    return p;
}

Persona Lista::eliminarMayor()
{
    pnodoLista nodo;
    pnodoLista aux;
    Persona p;
    if (!primero)
        return Persona();
    nodo = primero;
    p = primero->persona;
    aux = primero;
    while (nodo)
    {
        if (p.getId() < nodo->persona.getId())
        {
            p = nodo->persona;
            aux = nodo;
        }
       nodo = nodo->siguiente;
    }
    if (aux->anterior)
        aux->anterior->siguiente = aux->siguiente;
    else
        primero = aux->siguiente;
    
    if (aux->siguiente)
        aux->siguiente->anterior = aux->anterior;
    else
        ultimo = aux->anterior;    
    delete aux;
    return p;
}

void Lista::mostrar()
{
    pnodoLista nodo;

    if (!primero)
        return;
    nodo = primero;
    while (nodo)
    {
        if (nodo->persona.getEstado())
            cout << "El paciente cuyo DNI es " << nodo->persona.getDni() << " tiene apendicitis, ";
        else
            cout << "El paciente cuyo DNI es " << primero->persona.getDni() << " tiene hernias, ";
        cout << "su ID es: " << nodo->persona.getId() << " y su habitacion asignada es: " << nodo->persona.getHabitacion() << endl;
        nodo = nodo->siguiente;
    }
}
Persona Lista::buscarMenor()
{
    pnodoLista nodo;
    Persona min;
    if (!primero)
    {
        cout << "Lista vacia" << endl;
        return Persona();
    }
    nodo = primero;
    min = nodo->persona;
    while (nodo)
    {
        if (nodo->persona.getId() < min.getId())
            min = nodo->persona;
        nodo = nodo->siguiente;
    }
    cout <<"Apendicitis menor prioridad -> El paciente cuyo DNI es " << min.getDni() << " tiene apendicitis, su ID es: ";
    cout << min.getId() << " y su habitacion asignada es: " << min.getHabitacion() << endl;
    return min;
}

int Lista::cantidad()
{
    return longitud;
}

Persona Lista::buscarMayor()
{
    pnodoLista nodo;
    Persona max;
    if (!primero)
    {
        cout << "Lista vacia" << endl;
        return Persona();
    }
    nodo = primero;
    max = nodo->persona;
    while (nodo)
    {
        if (nodo->persona.getId() > max.getId())
            max = nodo->persona;
        nodo = nodo->siguiente;
    }
    cout <<"Hernias mayor prioridad -> El paciente cuyo DNI es " << max.getDni() << " tiene hernias, su ID es: ";
    cout << max.getId() << " y su habitacion asignada es: " << max.getHabitacion() << endl;
    return max;
}

void Lista::ordenar()
{
    Lista auxLista;
    int limite = this->longitud;

    for (int i = 0; i < limite; i++)
    {
        auxLista.insertar(this->eliminarMayor());
    }
    this->primero = auxLista.primero;
    this->ultimo = auxLista.ultimo;
    this->longitud = longitud;

    auxLista.primero = nullptr;
    auxLista.ultimo = nullptr;
    auxLista.longitud = 0;
}

void Lista::vaciarLista()
{
    pnodoLista nodoSiguiente;
    pnodoLista nodoActual;

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

void Lista::insertarOrdenado(Persona p)
{
    if (!primero || p.getId() <= primero->persona.getId())
    {
        insertarIzquierda(p);
        return ;
    }
    if (p.getId() >= ultimo->persona.getId())
    {
        insertarDerecha(p);
        return ;
    }
    pnodoLista actual = primero;
    while (actual != nullptr && actual->persona.getId() < p.getId())
        actual = actual->siguiente;
    
    pnodoLista nuevoNodo = new NodoLista(p, actual->anterior, actual);
    actual->anterior->siguiente = nuevoNodo;
    actual->anterior = nuevoNodo;
    longitud++;
}

void Lista::insertarDerecha(Persona p)
{
    pnodoLista nuevoNodo = new NodoLista(p, ultimo, nullptr);
    if (!primero)
    {
        primero = nuevoNodo;
    }
    else
    {
        ultimo->siguiente = nuevoNodo;
    }
    ultimo = nuevoNodo;
    longitud++;
}

void Lista::insertarIzquierda(Persona p)
{
    pnodoLista nuevoNodo = new NodoLista(p, nullptr, primero);
    if (!primero)
    {
        ultimo = nuevoNodo;
    }
    else
    {
        primero->anterior = nuevoNodo;
    }
    primero = nuevoNodo;
    longitud++;
}

Lista::~Lista()
{
    while (primero)
    {
        pnodoLista aux = primero;
        primero = primero->siguiente;
        delete aux;
    }
}