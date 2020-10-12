#include "ListaDePersona.h"

ListaDePersona::ListaDePersona(Pila* miembros)
{
	this->miembros = miembros;
}

void ListaDePersona::llenarListaDePersona()
{
	this->miembros->push(new Persona("Ginmer", 22));
	this->miembros->push(new Persona("Juan", 32));
	this->miembros->push(new Persona("Pedro", 53));
	this->miembros->push(new Persona("Felipe", 66));
	this->miembros->push(new Persona("Luis", 11));
}

ObjetoBase* ListaDePersona::RetornaUltimopeek()
{
	return this->miembros->peek();
}

ObjetoBase* ListaDePersona::EliminaUltimoPop()
{
	return this->miembros->pop();
}


IReadOnlyCollection* ListaDePersona::getMiembros()
{
	return this->miembros; 
}

ListaDePersona::~ListaDePersona()
{
	delete this->miembros;
}
