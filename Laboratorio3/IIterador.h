#pragma once
#include "ObjetoBase.h"

using namespace std;

class IIterador
{
public:
	virtual bool haySiguiente() = 0;
	virtual ObjetoBase* actual() = 0;
};