#include <iostream>
#include <string>
using namespace std;

struct Alumno {
    string nombre;
    float promedio;
};

void burbujaEnteros(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void burbujaChars(char arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                char temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Para el Nuevo Tipo de Dato (Alumno)
void burbujaAlumnos(Alumno arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            // Ordenamos por el campo 'promedio'
            if (arr[j].promedio > arr[j + 1].promedio) {
                // Intercambio de la estructura completa
                Alumno temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int numeros[] = {5, 2, 8, 1};
    char letras[] = {'z', 'a', 'h', 'b'};
    Alumno grupo[] = { {"Luis", 8.2}, {"Ana", 9.5}, {"Pedro", 7.0} };

    burbujaEnteros(numeros, 4);
    burbujaChars(letras, 4);
    burbujaAlumnos(grupo, 3);

    std::cout << "Enteros: ";
    for(int i=0; i<4; i++) cout << numeros[i] << " ";

    std::cout << "\nCaracteres: ";
    for(int i=0; i<4; i++) cout << letras[i] << " ";

    std::cout << "\nAlumnos (por promedio):\n";
    for(int i=0; i<3; i++) 
        std::cout << " - " << grupo[i].nombre << ": " << grupo[i].promedio << "\n";

    return 0;
}
