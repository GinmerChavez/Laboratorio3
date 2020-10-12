#include "LinkedList.h"

LinkedList::LinkedList()
{
    this->primero = nullptr;
    this->cantidad = 0;
}

string LinkedList::toString()
{
    stringstream s;
    Nodo* actual = this->primero;

    while (actual != nullptr)
    {
        if (actual->getDato())
        {
            s << actual->getDato()->toString() << endl;
        }
        actual = actual->getSiguiente();
    }

    return s.str();
}

void LinkedList::push(ObjetoBase* valor)
{
    
    this->primero = new Nodo(valor, primero);   
    this->cantidad++;
}

ObjetoBase* LinkedList::peek()
{   
    return this->primero->getDato();
}

ObjetoBase* LinkedList::pop()
{
    Nodo* aux = this->primero;
    this->primero = this->primero->getSiguiente();
    
    return aux->getDato();   
}

IIterador* LinkedList::obtenerIterador()
{
    return new IteradorLinkedList(this->primero);
}


LinkedList::~LinkedList()
{
    while (primero != nullptr)
    {
        if (this->primero != nullptr)
        {
            Nodo* eliminado = primero;
            this->primero = this->primero->getSiguiente();
            delete eliminado;
        }
    }
}

void LinkedList::liberarDatosInternos()
{
    while (primero != nullptr)
    {
        if (primero->getDato())
        {
            delete primero->getDato();
        }
        if (this->primero != nullptr)
        {
            Nodo* eliminado = primero;
            this->primero = this->primero->getSiguiente();
            delete eliminado;
        }
    }

    this->cantidad = 0;
}

ObjetoBase* LinkedList::consultarPorPosicion(int posicion)
{
    Nodo* actual = this->primero;
    int i = 0;
    for (int i = 0; i < posicion && actual != nullptr; i++)
    {
        actual = actual->getSiguiente();
    }

    if (actual != nullptr)
    {
        return actual->getDato();
    }
    else
    {
        cerr << "Posicion invalida" << endl;
        return nullptr; // Posicion estaba fuera de los límites de la colección
    }
}

bool LinkedList::contiene(ObjetoBase* elemento)
{
    Nodo* actual = this->primero;
    while (actual != nullptr)
    {
        if (actual->getDato() == elemento)
            return true;
        actual = actual->getSiguiente();
    }
    return false;
}

int LinkedList::getCantidad()
{
    return this->cantidad;
}
