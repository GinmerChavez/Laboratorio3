#pragma once
#include<iostream>
#include"ObjetoBase.h"
using namespace std;

class Persona : public ObjetoBase
{
private:
	string nombre;
	int edad;

public:
	Persona(string nombre=0, int edad=0);
	
	string getNombre() const;
	void setNombre(string nombre);
	int getEdad() const;
	void setEdad(int edad);
	string toString() override;
};