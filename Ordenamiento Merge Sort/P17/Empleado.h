#ifndef EMPLEADO_H
#define EMPLEADO_H
#include <string>

using namespace std;

class Empleado
{
public:
    int id;
    string nombre;
    Empleado();
    Empleado(int i, string n);
    ~Empleado();
};

class Ordenamiento
{
public:
    void Enteros(int arre[], int ini, int med, int fin);
    void marEnteros(int arre[], int ini, int fin);
    void Empleados(Empleado arre[], int ini, int med, int fin);
    void marEmpleados(Empleado arre[], int ini, int fin);
};

#endif
