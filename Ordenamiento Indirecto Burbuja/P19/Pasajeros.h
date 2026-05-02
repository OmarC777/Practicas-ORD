#ifndef PASAJEROS_H
#define PASAJEROS_H
#include <string>

using namespace std;

class Pasajeros
{
	public:
		int numeroAsiento;
    	string nombre;
};

class Ordenamiento
{
	public:
		void burbujaEnteros(int arreglo[], int n);
	    void burbujaCaracteres(char arreglo[], int n);
	    void burbujaPasajeros(Pasajeros arreglo[], int n);
};

#endif


