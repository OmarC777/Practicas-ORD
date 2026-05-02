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

class OrdenadorQS {
public:
    // Se añade el parámetro 'int indices[]' a todas las funciones
    int particionEnteros(int arr[], int indices[], int inicio, int fin);
    void ordenarEnteros(int arr[], int indices[], int inicio, int fin);

    int particionCaracteres(char arr[], int indices[], int inicio, int fin);
    void ordenarCaracteres(char arr[], int indices[], int inicio, int fin);

    int particionEmpleados(Empleado arr[], int indices[], int inicio, int fin);
    void ordenarEmpleados(Empleado arr[], int indices[], int inicio, int fin);
};

#endif
