#include "ArrayList.h"

void ArrayList::asegurarCapacidad()
{
    if (this->can == this->capacidadActual)
    {
        // Se duplica la capacidad actual del arreglo.
        this->capacidadActual = capacidadActual * 2;
        ObjetoBase** nuevoArreglo = new ObjetoBase * [this->capacidadActual];

        // Se copian los elementos almacenados en el nuevo arreglo
        for (int i = 0; i < this->can; i++)
        {
            nuevoArreglo[i] = this->datos[i];
        }

        // Se elimina el arreglo anterior y se actualiza el arreglo actual
        delete[] this->datos;
        this->datos = nuevoArreglo;

        // Se inicializan las nuevas posiciones libres
        for (int i = this->can; i < this->capacidadActual; i++)
        {
            this->datos[i] = nullptr;
        }
    }
}

ArrayList::ArrayList(int capacidadInicial)
{
    this->capacidadActual = capacidadInicial;    
    this->can = 0;
    this->datos = new ObjetoBase * [this->capacidadActual];
    for (int i = 0; i < this->capacidadActual; i++)
    {
        this->datos[i] = nullptr;
    }
}

string ArrayList::toString()
{
    stringstream s;
    for (int i = 0; i < this->can; i++)
    {
        if (this->datos[i])
        {
            s << this->datos[i]->toString() << endl;
        }
    }
    return s.str();
}

void ArrayList::push(ObjetoBase* valor)
{
    asegurarCapacidad();
    if (this->can + 1 < this->capacidadActual)
    {
        datos[can] = valor;
        can++;
    }
   
}

ObjetoBase* ArrayList::peek()
{
    return datos[this->can-1];
}

ObjetoBase* ArrayList::pop()
{
   
    
    if (this->can != 0)
    {       
        ObjetoBase* aux = datos[this->can-1];
        this->can--;      
        return aux;        
    }
    else
    {
    return nullptr;
    }
    
}

IIterador* ArrayList::obtenerIterador()
{
    return new IteradorArrayList(this->datos, this->can);
}

ArrayList::~ArrayList()
{
    delete[] this->datos;
}

void ArrayList::liberarDatosInternos()
{
    for (int i = 0; i < this->can; i++)
    {
        if (this->datos[i])
        {
            delete this->datos[i];
            this->datos[i] = nullptr;
        }
    }

    this->can = 0;
}

ObjetoBase* ArrayList::consultarPorPosicion(int posicion)
{
    if (posicion >= this->can)
    {
        cerr << "Posicion invalida" << endl;
        return nullptr; // Posicion estaba fuera de los límites de la colección
    }

    return this->datos[posicion];
}

bool ArrayList::contiene(ObjetoBase* elemento)
{
    for (int i = 0; i < this->can; i++)
    {
        if (this->datos[i] == elemento)
            return true;
    }
    return false;
}

int ArrayList::getCantidad()
{
    return this->can;
}
