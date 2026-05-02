#include "Empleado.h"

using namespace std;

Empleado::Empleado() {
    id = 0;
    nombre = "";
}

Empleado::Empleado(int i, string n) {
    id = i;
    nombre = n;
}

Empleado::~Empleado() {
}

void Ordenamiento::Enteros(int arre[], int indices[], int ini, int med, int fin) {
    int n1 = med - ini + 1;
    int n2 = fin - med;
    
    int* izq = new int[n1];
    int* der = new int[n2];
    
    for (int i = 0; i < n1; i++) izq[i] = indices[ini + i];
    for (int j = 0; j < n2; j++) der[j] = indices[med + 1 + j];
    
    int i = 0, j = 0, k = ini;
    while (i < n1 && j < n2) {
        if (arre[izq[i]] <= arre[der[j]]) {
            indices[k] = izq[i]; // Movemos el índice
            i++;
        } else {
            indices[k] = der[j]; // Movemos el índice
            j++;
        }
        k++;
    }
    
    while (i < n1) { indices[k] = izq[i]; i++; k++; }
    while (j < n2) { indices[k] = der[j]; j++; k++; }
    
    delete[] izq;
    delete[] der;
}

void Ordenamiento::marEnteros(int arre[], int indices[], int ini, int fin) {
    if (ini >= fin) return;
    int med = ini + (fin - ini) / 2;
    marEnteros(arre, indices, ini, med);
    marEnteros(arre, indices, med + 1, fin);
    Enteros(arre, indices, ini, med, fin);
}

void Ordenamiento::Caracteres(char arre[], int indices[], int ini, int med, int fin) {
    int n1 = med - ini + 1;
    int n2 = fin - med;

    int* izq = new int[n1];
    int* der = new int[n2];

    for (int i = 0; i < n1; i++) izq[i] = indices[ini + i];
    for (int j = 0; j < n2; j++) der[j] = indices[med + 1 + j];

    int i = 0, j = 0, k = ini;
    while (i < n1 && j < n2) {
        if (arre[izq[i]] <= arre[der[j]]) {
            indices[k] = izq[i]; // Movemos el índice
            i++;
        } else {
            indices[k] = der[j]; // Movemos el índice
            j++;
        }
        k++;
    }

    while (i < n1) { indices[k] = izq[i]; i++; k++; }
    while (j < n2) { indices[k] = der[j]; j++; k++; }

    delete[] izq;
    delete[] der;
}

void Ordenamiento::marCaracteres(char arre[], int indices[], int ini, int fin) 
{
    if (ini >= fin) return;
    int med = ini + (fin - ini) / 2;
    marCaracteres(arre, indices, ini, med);
    marCaracteres(arre, indices, med + 1, fin);
    Caracteres(arre, indices, ini, med, fin);
}

void Ordenamiento::Empleados(Empleado arre[], int indices[], int ini, int med, int fin) {
    int n1 = med - ini + 1;
    int n2 = fin - med;
    
    int* izq = new int[n1];
    int* der = new int[n2];
    
    for (int i = 0; i < n1; i++) izq[i] = indices[ini + i];
    for (int j = 0; j < n2; j++) der[j] = indices[med + 1 + j];
    
    int i = 0, j = 0, k = ini;
    while (i < n1 && j < n2) {
        if (arre[izq[i]].id <= arre[der[j]].id) {
            indices[k] = izq[i];
            i++;
        } else {
            indices[k] = der[j];
            j++;
        }
        k++;
    }
    
    while (i < n1) { indices[k] = izq[i]; i++; k++; }
    while (j < n2) { indices[k] = der[j]; j++; k++; }
    
    delete[] izq;
    delete[] der;
}

void Ordenamiento::marEmpleados(Empleado arre[], int indices[], int ini, int fin) {
    if (ini >= fin) return;
    int med = ini + (fin - ini) / 2;
    marEmpleados(arre, indices, ini, med);
    marEmpleados(arre, indices, med + 1, fin);
    Empleados(arre, indices, ini, med, fin);
}

