#include "Empleado.h"
#include <iostream>
#include <string>
using namespace std;

Empleado::Empleado() 
{
    id = 0;
    nombre = "";
}

Empleado::Empleado(int i, string n) 
{
    id = i;
    nombre = n;
}

Empleado::~Empleado() {}

void Ordenamiento::Enteros(int arre[], int ini, int med, int fin) 
{
    int n1 = med - ini + 1;
    int n2 = fin - med;

    int* izq = new int[n1];
    int* der = new int[n2];

    for (int i = 0; i < n1; i++) izq[i] = arre[ini + i];
    for (int j = 0; j < n2; j++) der[j] = arre[med + 1 + j];

    int i = 0, j = 0, k = ini;
    while (i < n1 && j < n2) {
        if (izq[i] <= der[j]) {
            arre[k] = izq[i];
            i++;
        } else {
            arre[k] = der[j];
            j++;
        }
        k++;
    }

    while (i < n1) { arre[k] = izq[i]; i++; k++; }
    while (j < n2) { arre[k] = der[j]; j++; k++; }

    delete[] izq;
    delete[] der;
}

void Ordenamiento::marEnteros(int arre[], int ini, int fin) 
{
    if (ini >= fin) return;
    int med = ini + (fin - ini) / 2;
    marEnteros(arre, ini, med);
    marEnteros(arre, med + 1, fin);
    Enteros(arre, ini, med, fin);
}

void Ordenamiento::Empleados(Empleado arre[], int ini, int med, int fin) 
{
    int n1 = med - ini + 1;
    int n2 = fin - med;

    Empleado* izq = new Empleado[n1];
    Empleado* der = new Empleado[n2];

    for (int i = 0; i < n1; i++) izq[i] = arre[ini + i];
    for (int j = 0; j < n2; j++) der[j] = arre[med + 1 + j];

    int i = 0, j = 0, k = ini;
    while (i < n1 && j < n2) {
        if (izq[i].id <= der[j].id) { 
            arre[k] = izq[i];
            i++;
        } else {
            arre[k] = der[j];
            j++;
        }
        k++;
    }

    while (i < n1) { arre[k] = izq[i]; i++; k++; }
    while (j < n2) { arre[k] = der[j]; j++; k++; }

    delete[] izq;
    delete[] der;
}

void Ordenamiento::marEmpleados(Empleado arre[], int ini, int fin) 
{
    if (ini >= fin) return;
    int med = ini + (fin - ini) / 2;
    marEmpleados(arre, ini, med);
    marEmpleados(arre, med + 1, fin);
    Empleados(arre, ini, med, fin);
}
