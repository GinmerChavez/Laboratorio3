

#include <iostream>
using namespace std;

#include "Pila.h"
#include "ArrayList.h"
#include "LinkedList.h"
#include "Persona.h"
#include "ListaDePersona.h"


int main()
{	bool a = true;
	do
	{
		
	bool tipo = false;
	cout << "Escoja una opcion: " << endl;
	cout << "0) ArrayList" << endl;
	cout << "1) LinkedList" << endl;
	cout << "Opcion: ";
	cin >> tipo;

	Pila* piLL = nullptr;

	if (!tipo)
	{
		piLL = new ArrayList(8);
	}
	else
	{
		piLL = new LinkedList();
	}
	 
	ListaDePersona* LPer = new ListaDePersona(piLL);

	int opc;
	cout << "--------Funcion por realizar-----" << endl;
	cout << "1- Push" << endl;
	cout << "2- Pop" << endl;
	cout << "3- Peek" << endl;
	cin >> opc;
	if (opc == 1)
	{
		LPer->llenarListaDePersona();
	}
	if (opc == 2)
	{
		LPer->llenarListaDePersona();
		cout << "Pop: " << LPer->EliminaUltimoPop()->toString() << endl;
	}
	if (opc == 3)
	{
		LPer->llenarListaDePersona();
		cout << "Peek: " << LPer->RetornaUltimopeek()->toString() << endl;
	}
	
	
	IIterador* iterador = LPer->getMiembros()->obtenerIterador();
	
	while (iterador->haySiguiente())
	{
		Persona* actual = dynamic_cast<Persona*>(iterador->actual());
		cout << "Actual es: " << actual->getNombre() <<" , "<<actual->getEdad()<< endl;
	}

	cout << "Seguir Si==1/No==0?" << endl;
	cin >> a;

	delete iterador;
	delete LPer;

	} while (a);
    system("pause");
}
