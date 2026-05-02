#ifndef ALUMNOS_H
#define ALUMNOS_H
#include <string>

using namespace std;

class Alumnos
{
	private: 
		string nombre;
		float promedio;
		
	public:
		float getPromedio();
    	string getNombre();
		void imprimir();
		void burOb(Alumnos grupo[], int n);
		void burChar(char arr[], int n);
		Alumnos();
		Alumnos(string n, float p);
		~Alumnos();
	protected:
};

#endif



