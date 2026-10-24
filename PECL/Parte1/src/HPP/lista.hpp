#ifndef LISTA_HPP
#define LISTA_HPP

#include "nodoLista.hpp"

class Lista
{
    public:
        Lista();
        void insertar(Persona p);
        Persona eliminar();
        Persona buscarMayor();
        Persona eliminarMayor();
        Persona buscarMenor();
        void insertarOrdenado(Persona p);
        void insertarIzquierda(Persona p);
        void insertarDerecha(Persona p);
        void vaciarLista();
        void ordenar();
        int cantidad();
        void mostrar();
        ~Lista();
    private:
        pnodoLista primero;
        pnodoLista ultimo;
        int longitud;
};

#endif