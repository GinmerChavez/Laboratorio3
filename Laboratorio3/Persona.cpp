#include "Persona.h"
#include <sstream>

Persona::Persona(string nombre, int edad)
{
	this->nombre = nombre;
	this->edad = edad;
}


string Persona::getNombre() const
{
	return nombre;
}

void Persona::setNombre(string nombre)
{
	this->nombre = nombre;
}

int Persona::getEdad() const
{
	return edad;
}

void Persona::setEdad(int edad)
{
	this->edad = edad;
}

string Persona::toString()
{
	stringstream s;
	s << "Nombre: " << this->nombre << endl;
	s << "Edad: " << this->edad << endl;
	return s.str();
}
