#pragma once

#include "IIterador.h"
using namespace std;
class IIterable : public ObjetoBase
{
public:
	virtual IIterador* obtenerIterador() = 0;
	~IIterable() = default;
};