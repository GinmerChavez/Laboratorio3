#pragma once
#include <iostream>
#include <sstream>
using namespace std;

#include "ObjetoBase.h"

#include "IReadOnlyCollection.h"

class Pila : public IReadOnlyCollection
{
public:
	virtual void push(ObjetoBase* valor) = 0;
	virtual ObjetoBase* peek() = 0;
	virtual ObjetoBase* pop() = 0;
	virtual void liberarDatosInternos() = 0;

	virtual ~Pila() = default;
};