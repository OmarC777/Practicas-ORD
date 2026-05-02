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

class OrdenadorQS // Clase exclusiva para Quick Sort
{
public:
    int particionEnteros(int arr[], int inicio, int fin);
    void ordenarEnteros(int arr[], int inicio, int fin);

    int particionCaracteres(char arr[], int inicio, int fin);
    void ordenarCaracteres(char arr[], int inicio, int fin);

    int particionEmpleados(Empleado arr[], int inicio, int fin);
    void ordenarEmpleados(Empleado arr[], int inicio, int fin);
};

#endif
