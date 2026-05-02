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

Empleado::~Empleado() {}

// --- ENTEROS ---
int OrdenadorQS::particionEnteros(int arre[], int indices[], int ini, int fin) {
    // El pivote se obtiene del arreglo original usando el índice correspondiente al final
    int pivote = arre[indices[fin]]; 
    int i = (ini - 1);

    for (int j = ini; j <= fin - 1; j++) {
        // Comparamos usando los índices
        if (arre[indices[j]] <= pivote) {
            i++;
            // INTERCAMBIAMOS SOLO LOS ÍNDICES (enteros)
            int temp = indices[i];
            indices[i] = indices[j];
            indices[j] = temp;
        }
    }
    int temp = indices[i + 1];
    indices[i + 1] = indices[fin];
    indices[fin] = temp;

    return (i + 1);
}

void OrdenadorQS::ordenarEnteros(int arre[], int indices[], int ini, int fin) {
    if (ini < fin) {
        int indicePivote = particionEnteros(arre, indices, ini, fin);
        ordenarEnteros(arre, indices, ini, indicePivote - 1);
        ordenarEnteros(arre, indices, indicePivote + 1, fin);
    }
}

// --- CARACTERES ---
int OrdenadorQS::particionCaracteres(char arre[], int indices[], int ini, int fin) {
    char pivote = arre[indices[fin]];
    int i = (ini - 1);

    for (int j = ini; j <= fin - 1; j++) {
        if (arre[indices[j]] <= pivote) {
            i++;
            // Intercambiamos solo índices
            int temp = indices[i];
            indices[i] = indices[j];
            indices[j] = temp;
        }
    }
    int temp = indices[i + 1];
    indices[i + 1] = indices[fin];
    indices[fin] = temp;

    return (i + 1);
}

void OrdenadorQS::ordenarCaracteres(char arre[], int indices[], int ini, int fin) {
    if (ini < fin) {
        int indicePivote = particionCaracteres(arre, indices, ini, fin);
        ordenarCaracteres(arre, indices, ini, indicePivote - 1);
        ordenarCaracteres(arre, indices, indicePivote + 1, fin);
    }
}

// --- EMPLEADOS ---
int OrdenadorQS::particionEmpleados(Empleado arre[], int indices[], int ini, int fin) {
    // Obtenemos el ID del pivote basándonos en el índice
    int pivote = arre[indices[fin]].id; 
    int i = (ini - 1);

    for (int j = ini; j <= fin - 1; j++) {
        // Comparamos los IDs referenciados por los índices
        if (arre[indices[j]].id <= pivote) {
            i++;
            // El intercambio es super ligero porque solo movemos ints (índices), no objetos Empleado
            int temp = indices[i];
            indices[i] = indices[j];
            indices[j] = temp;
        }
    }
    int temp = indices[i + 1];
    indices[i + 1] = indices[fin];
    indices[fin] = temp;

    return (i + 1);
}

void OrdenadorQS::ordenarEmpleados(Empleado arre[], int indices[], int ini, int fin) {
    if (ini < fin) {
        int indicePivote = particionEmpleados(arre, indices, ini, fin);
        ordenarEmpleados(arre, indices, ini, indicePivote - 1);
        ordenarEmpleados(arre, indices, indicePivote + 1, fin);
    }
}
