#include <iostream>
#include "Alumnos.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	const int MAX = 10;
    Alumnos lista[MAX]; 
    int cantidadRegistrada = 0; 
    int opcion;
    
    
    string tempNombre;
    float tempPromedio;

    do {
        
        cout << "\n=== Menu de Alumnos ===" << endl;
        cout << "1. Agregar elemento " << endl;
        cout << "2. Quitar elemento " << endl;
        cout << "3. Mostrar registros (Ordenados por promedio)" << endl;
        cout << "4. Verificar si esta vacia" << endl;
        cout << "5. Verificar si esta llena" << endl;
        cout << "6. Mostrar tamano de la lista" << endl;
        cout << "7. Salir" << endl;
        cout << "Elige una opcion: ";
        cin >> opcion;

        switch(opcion) {
            case 1: 
                
                if (cantidadRegistrada >= MAX) {
                    cout << "-> ERROR: La lista esta llena. No puedes agregar mas de " << MAX << " alumnos." << endl;
                } else {
                    cout << "\n--- REGISTRANDO ALUMNO " << (cantidadRegistrada + 1) << " ---" << endl;
                    
                    cout << "Nombre del alumno: "; 
                    cin.ignore(); 
                    getline(cin, tempNombre);
                    
                    cout << "Promedio: "; 
                    cin >> tempPromedio;

                    lista[cantidadRegistrada] = Alumnos(tempNombre, tempPromedio);
                    
                    cantidadRegistrada++; 
                    cout << "-> Alumno agregado con exito." << endl;
                }
                break;
                
            case 2:
                if (cantidadRegistrada > 0) {
                    cantidadRegistrada--; 
                    cout << "-> Se quito el ultimo registro: " << lista[cantidadRegistrada].getNombre() << endl;
                } else {
                    cout << "-> No se puede quitar, la lista ya esta vacia." << endl;
                }
                break;
                
            case 3:
                cout << "\n--- CONTENIDO ---" << endl;
                if (cantidadRegistrada == 0) {
                    cout << "La lista esta vacia. No hay alumnos registrados." << endl;
                } else {
                    lista[0].burOb(lista, cantidadRegistrada);
                    
                    cout << "Lista de alumnos ordenados por promedio:" << endl;
                    for (int i = 0; i < cantidadRegistrada; i++) {
                        lista[i].imprimir();
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
                cout << "-> El tamano actual de la lista es de: " << cantidadRegistrada << " alumnos registrados." << endl;
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

