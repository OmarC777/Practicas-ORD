#include <iostream>
#include <string>
#include "Empleado.h"

using namespace std;

int main() {
    const int MAX = 10;
    Empleado lista[MAX];
    int cantidadRegistrada = 0; 
    int opcion;

    Ordenamiento obMarge;

    int tempId;
    string tempNombre;

    do {
        cout << "\n=== Menu de Empleados ===" << endl;
        cout << "1. Agregar elemento " << endl;
        cout << "2. Quitar elemento " << endl;
        cout << "3. Mostrar registros (Ordenados por ID)" << endl;
        cout << "4. Verificar si esta vacia" << endl;
        cout << "5. Verificar si esta llena" << endl;
        cout << "6. Mostrar tamano de la lista" << endl;
        cout << "7. Salir" << endl;
        cout << "Elige una opcion: ";
        cin >> opcion;

        switch(opcion) {
            case 1:
                if (cantidadRegistrada >= MAX) {
                    cout << "-> ERROR: La lista esta llena. No puedes agregar mas de " << MAX << " empleados." << endl;
                } else {
                    cout << "\n--- REGISTRANDO EMPLEADO " << (cantidadRegistrada + 1) << " ---" << endl;
                    
                    cout << "ID del empleado: ";
                    cin >> tempId;
                    
                    cout << "Nombre del empleado: ";
                    cin.ignore(); 
                    getline(cin, tempNombre);
                    
                    lista[cantidadRegistrada] = Empleado(tempId, tempNombre);
                    cantidadRegistrada++;
                    cout << "-> Empleado agregado con exito." << endl;
                }
                break;
                
            case 2:
                if (cantidadRegistrada > 0) {
                    cantidadRegistrada--;
                    cout << "-> Se quito el ultimo registro: " << lista[cantidadRegistrada].nombre << endl;
                } else {
                    cout << "-> No se puede quitar, la lista ya esta vacia." << endl;
                }
                break;
                
            case 3:
                cout << "\n--- CONTENIDO ---" << endl;
                if (cantidadRegistrada == 0) {
                    cout << "La lista esta vacia. No hay empleados registrados." << endl;
                } else {
                    obMarge.marEmpleados(lista, 0, cantidadRegistrada - 1);
                    
                    cout << "Lista de empleados ordenados por ID (Usando Merge Sort):" << endl;
                    for (int i = 0; i < cantidadRegistrada; i++) {
                        cout << "ID: " << lista[i].id << " | Nombre: " << lista[i].nombre << endl;
                    }
                }
                break;
                
            case 4:
                if (cantidadRegistrada == 0) {
                    cout << "-> La lista SI esta vacia." << endl;
                } else {
                    cout << "-> La lista NO esta vacia." << endl;
                }
                break;
                
            case 5:
                if (cantidadRegistrada == MAX) {
                    cout << "-> La lista SI esta llena (Limite maximo: " << MAX << ")." << endl;
                } else {
                    cout << "-> La lista NO esta llena. (Espacio disponible: " << (MAX - cantidadRegistrada) << ")." << endl;
                }
                break;
                
            case 6:
                cout << "-> El tamano actual de la lista es de: " << cantidadRegistrada << " empleados registrados." << endl;
                break;
                
            case 7:
                cout << "Saliendo del programa..." << endl;
                break;
                
            default:
                cout << "Opcion no valida. Intenta de nuevo con un numero del 1 al 7." << endl;
                break;
        }

    } while (opcion != 7);

    return 0;
}
