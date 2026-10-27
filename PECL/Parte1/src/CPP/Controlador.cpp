#include "Controlador.hpp"
#include <ctime>
using namespace std;

Controlador::Controlador()
{
    srand(time(nullptr));
    for (int i = 0; i < 300; i++) usado[i] = false;
    siguienteIdApendicitis = 1;
    siguienteIdHernia = 51;
}

Controlador::~Controlador()
{

}

int Controlador::pacientesEnPila()
{
    return pila.mostrarCantidad();
}

int Controlador::pacientesEnSalaA()
{
    return colaA.mostrarCantidad();
}
int Controlador::pacientesEnSalaB()
{
    return colaB.mostrarCantidad();
}

int Controlador::pacientesEnSalaC()
{
    return colaC.mostrarCantidad();
}
int Controlador::pacientesEnSalaD()
{
    return colaD.mostrarCantidad();
}


int Controlador::pacientesEnListaApendicitis()
{
    return listaApendicitis.cantidad();
}

int Controlador::pacientesEnListaHernias()
{
    return listaHernias.cantidad();
}

//void Controlador::pacientesEnArbol();

void Controlador::generar12Pacientes()
{
    if (pila.mostrarCantidad() >= 48)
        cout << "Pila llena, cantidad: " << pila.mostrarCantidad() << endl;
    else
        for (int i = 0; i < 12; i++)
        {
            Persona p = Persona();
            pila.insertar(p);
        }
}
void Controlador::muestraPacientes()
{
    pila.mostrar();
}
void Controlador::borraPacientesPila()
{
    while (pila.mostrarCantidad() > 0)
        pila.eliminar();
}
void Controlador::encolarPacientes()
{
    while (pila.mostrarCantidad())
    {
        Persona persona = pila.eliminar();
        if (persona.getEstado())
        {
            //persona.setId(siguienteIdApendicitis);
            //persona.setHabitacion(siguienteIdApendicitis);
            siguienteIdApendicitis++;
			persona.setId(rand() % 49 + 1);           // 1-49
			persona.setHabitacion(rand() % 99 + 101); // 101-199
            int id, hab;
            do id = rand() % 49 + 1; while (usado[id]);
            usado[id] = true;
            do hab = rand() % 99 + 101; while (usado[hab]);
            usado[hab] = true;
            persona.setId(id);
            persona.setHabitacion(hab);
            if (colaA.mostrarCantidad() <= colaB.mostrarCantidad())
            {
                colaA.insertar(persona);
            }
            else
            {
                colaB.insertar(persona);
            }
        }
        else
        {
            //persona.setId(siguienteIdHernia);
            //persona.setHabitacion(siguienteIdHernia);
            siguienteIdHernia++;
			persona.setId(rand() % 49 + 51);          // 51-99
			persona.setHabitacion(rand() % 99 + 201); // 201-299
            int id, hab;
            do id = rand() % 49 + 51; while (usado[id]);
            usado[id] = true;
            do hab = rand() % 99 + 201; while (usado[hab]);
            usado[hab] = true;
            persona.setId(id);
            persona.setHabitacion(hab);
            if (colaC.mostrarCantidad() <= colaD.mostrarCantidad())
            {
                colaC.insertar(persona);
            }
            else
            {
                colaD.insertar(persona);
            }
        }
    }
}
void Controlador::muestraPacientesSalasAyB()
{
    cout << "Sala A:" << endl;
    colaA.mostrar();
    cout << endl;
    cout << "Sala B:" << endl;
    colaB.mostrar();
}
void Controlador::muestraPacientesSalasCyD()
{
    cout << "Sala C:" << endl;
    colaC.mostrar();
    cout << endl;
    cout << "Sala D:" << endl;
    colaD.mostrar();
}
void Controlador::borraPacientesColas()
{
    while (colaA.mostrarCantidad() || colaB.mostrarCantidad() || colaC.mostrarCantidad() || colaD.mostrarCantidad())
    {
        colaA.eliminar();
        colaB.eliminar();
        colaC.eliminar();
        colaD.eliminar();
    }
}

void Controlador::enlistarPacientes()
{
    while (colaA.mostrarCantidad() || colaB.mostrarCantidad())
    {
        if (colaA.mostrarCantidad())
            listaApendicitis.insertar(colaA.eliminar());
        if (colaB.mostrarCantidad())
            listaApendicitis.insertar(colaB.eliminar());
    }
    while (colaC.mostrarCantidad() || colaD.mostrarCantidad())
    {
        if (colaC.mostrarCantidad())
            listaHernias.insertar(colaC.eliminar());
        if (colaD.mostrarCantidad())
            listaHernias.insertar(colaD.eliminar());
    }
    listaApendicitis.ordenar();
    listaHernias.ordenar();
}

void Controlador::enlistarPacientes2()
{
    while (colaA.mostrarCantidad() > 0)
        listaApendicitis.insertarOrdenado(colaA.eliminar());
    while (colaB.mostrarCantidad() > 0)
        listaApendicitis.insertarOrdenado(colaB.eliminar());
    while (colaC.mostrarCantidad() > 0)
        listaHernias.insertarOrdenado(colaC.eliminar());
    while (colaD.mostrarCantidad() > 0)
        listaHernias.insertarOrdenado(colaD.eliminar());
}

void Controlador::muestraPacientesApendicitis()
{
    listaApendicitis.mostrar();
}

void Controlador::muestraPacientesHernias()
{
    listaHernias.mostrar();
}

void Controlador::buscarPacientes()
{
    listaApendicitis.buscarMenor();
    listaHernias.buscarMayor();
}
void Controlador::reiniciar()
{
    listaApendicitis.vaciarLista();
    listaHernias.vaciarLista();
    colaA.vaciarCola();
    colaB.vaciarCola();
    colaC.vaciarCola();
    colaD.vaciarCola();
    pila.vaciarPila();
	for (int i = 0; i < 300; i++) usado[i] = false;
}