#ifndef EMPLEADO_H
#define EMPLEADO_H
#include <string>

using namespace std;

class Empleado {
public:
    int id;
    string nombre;
    Empleado();
    Empleado(int i, string n);
    ~Empleado();
protected:
};

class Ordenamiento {
public:
  
    void Enteros(int arre[], int indices[], int ini, int med, int fin);
    void marEnteros(int arre[], int indices[], int ini, int fin);
    
	void Caracteres(char arre[], int indices[], int ini, int med, int fin);
    void marCaracteres(char arre[], int indices[], int ini, int fin);
    
    void Empleados(Empleado arre[], int indices[], int ini, int med, int fin);
    void marEmpleados(Empleado arre[], int indices[], int ini, int fin);
};

#endif
