#pragma once

using namespace std;
#include "Pila.h"
#include "Persona.h"
#include "IReadOnlyCollection.h"

class ListaDePersona
{
private:
	Pila* miembros;

public:
	ListaDePersona(Pila* miembros);


	void llenarListaDePersona();
	ObjetoBase* RetornaUltimopeek();
	ObjetoBase* EliminaUltimoPop();
	IReadOnlyCollection* getMiembros();

	~ListaDePersona();

};

