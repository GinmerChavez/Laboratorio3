#pragma once
#include <iostream>
#include <sstream>
using namespace std;
#include "Pila.h"
#include "IteradorArrayList.h"

class ArrayList: public Pila
{
private:
	ObjetoBase** datos;
	int capacidadActual;
	int can;
	void asegurarCapacidad();
public:
	ArrayList(int capacidadInicial);
	// Heredado vía Pila
	virtual string toString() override;
	virtual void push(ObjetoBase* valor) override;
	virtual ObjetoBase* peek() override;
	virtual ObjetoBase* pop() override;

	IIterador* obtenerIterador() override;
	~ArrayList();

	// Heredado vía Pila
	virtual void liberarDatosInternos() override;

	// Heredado vía Pila
	virtual ObjetoBase* consultarPorPosicion(int posicion) override;
	virtual bool contiene(ObjetoBase* elemento) override;
	virtual int getCantidad() override;
};

