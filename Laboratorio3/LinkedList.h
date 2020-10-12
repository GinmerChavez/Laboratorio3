#pragma once
#include <iostream>
#include <sstream>

using namespace std;

#include "Pila.h"
#include "ObjetoBase.h"
#include "Nodo.h"
#include "IteradorLinkedList.h"

class LinkedList: public Pila
{
private:
	Nodo* primero;
	int cantidad;	
	

public:
	LinkedList();	

	// Heredado vía Pila
	virtual string toString() override;
	virtual void push(ObjetoBase* valor) override;
	virtual ObjetoBase* peek() override;
	virtual ObjetoBase* pop() override;
	
	IIterador* obtenerIterador() override;
	
	~LinkedList();

	// Heredado vía Pila
	virtual void liberarDatosInternos() override;

	// Heredado vía Pila
	virtual ObjetoBase* consultarPorPosicion(int posicion) override;
	virtual bool contiene(ObjetoBase* elemento) override;
	virtual int getCantidad() override;
};

