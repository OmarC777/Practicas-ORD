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

// --- LÓGICA DE QUICK SORT ---

int OrdenadorQS::particionEnteros(int arre[], int ini, int fin) {
    int pivote = arre[fin];
    int i = (ini - 1);

    for (int j = ini; j <= fin - 1; j++) {
        if (arre[j] <= pivote) {
            i++;
            int temp = arre[i];
            arre[i] = arre[j];
            arre[j] = temp;
        }
    }
    int temp = arre[i + 1];
    arre[i + 1] = arre[fin];
    arre[fin] = temp;
    
    return (i + 1);
}

void OrdenadorQS::ordenarEnteros(int arre[], int ini, int fin) {
    if (ini < fin) {
        int indicePivote = particionEnteros(arre, ini, fin);
        ordenarEnteros(arre, ini, indicePivote - 1);
        ordenarEnteros(arre, indicePivote + 1, fin);
    }
}

int OrdenadorQS::particionCaracteres(char arre[], int ini, int fin) {
    char pivote = arre[fin];
    int i = (ini - 1);

    for (int j = ini; j <= fin - 1; j++) {
        if (arre[j] <= pivote) {
            i++;
            char temp = arre[i];
            arre[i] = arre[j];
            arre[j] = temp;
        }
    }
    char temp = arre[i + 1];
    arre[i + 1] = arre[fin];
    arre[fin] = temp;
    
    return (i + 1);
}

void OrdenadorQS::ordenarCaracteres(char arre[], int ini, int fin) {
    if (ini < fin) {
        int indicePivote = particionCaracteres(arre, ini, fin);
        ordenarCaracteres(arre, ini, indicePivote - 1);
        ordenarCaracteres(arre, indicePivote + 1, fin);
    }
}

int OrdenadorQS::particionEmpleados(Empleado arre[], int ini, int fin) {
    int pivote = arre[fin].id;
    int i = (ini - 1);

    for (int j = ini; j <= fin - 1; j++) {
        if (arre[j].id <= pivote) {
            i++;
            Empleado temp = arre[i];
            arre[i] = arre[j];
            arre[j] = temp;
        }
    }
    Empleado temp = arre[i + 1];
    arre[i + 1] = arre[fin];
    arre[fin] = temp;
    
    return (i + 1);
}

void OrdenadorQS::ordenarEmpleados(Empleado arre[], int ini, int fin) {
    if (ini < fin) {
        int indicePivote = particionEmpleados(arre, ini, fin);
        ordenarEmpleados(arre, ini, indicePivote - 1);
        ordenarEmpleados(arre, indicePivote + 1, fin);
    }
}
