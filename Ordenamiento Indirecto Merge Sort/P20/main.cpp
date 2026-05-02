#include <iostream>
#include <string>
#include "Empleado.h"

using namespace std;

void imprimirEnteros(int arre[], int indices[], int tam) {
    for(int i = 0; i < tam; i++) {
        cout << arre[indices[i]] << " ";
    }
    cout << endl;
}
void imprimirCaracteres(char arre[], int indices[], int tam) {
    cout << "Caracteres ordenados: ";
    for(int i = 0; i < tam; i++) {
        cout << arre[indices[i]] << " ";
    }
    cout << endl;
}

void imprimirEmpleados(Empleado arre[], int indices[], int tam) {
    for(int i = 0; i < tam; i++) {
        cout << "ID: " << arre[indices[i]].id 
             << " - Nombre: " << arre[indices[i]].nombre << endl;
    }
}

int main(int argc, char** argv) 
{
    Ordenamiento obMarge;
    int opcion;
	
	int capacidadMaxima = 50; 
    Empleado* listaEmpleados = new Empleado[capacidadMaxima];
    int* indicesEmpleados = new int[capacidadMaxima];
    int totalEmpleados = 0; 

    do {
        cout << "\n========================================" << endl;
        cout << " *** ORDENAMIENTO INDIRECTO ***" << endl;
        cout << "1. Ordenar Numeros y Caracteres" << endl;
        cout << "2. Agregar Empleado" << endl;
        cout << "3. Quitar Empleado (Por ID)" << endl;
        cout << "4. Mostrar tamano de empleados" << endl;
        cout << "5. Ordenar y Mostrar Empleados" << endl;
        cout << "6. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch(opcion) {
            case 1: {
                int n;
                cout << "\n*ORDENAMIENTO NUMEROS*"<< endl;
                cout << "Cuantos numeros desea ingresar?: ";
                cin >> n;

                int* numeros = new int[n];
                int* indices = new int[n];

                for(int i = 0; i < n; i++) {
                    cout << "Ingrese numero [" << i + 1 << "]: ";
                    cin >> numeros[i];
                    indices[i] = i;
                }

                obMarge.marEnteros(numeros, indices, 0, n - 1);
                imprimirEnteros(numeros, indices, n);
                
                cout << "\n*ORDENAMIENTO CARACTERES*"<< endl;
                cout << "Cuantos caracteres desea ingresar?: ";
                cin >> n;

                char* caracteres = new char[n];
                int* indicesCar = new int[n];

                for(int i = 0; i < n; i++) {
                    cout << "Ingrese caracter [" << i + 1 << "]: ";
                    cin >> caracteres[i];
                    indicesCar[i] = i;
                }

                obMarge.marCaracteres(caracteres, indicesCar, 0, n - 1);
                imprimirCaracteres(caracteres, indicesCar, n);
                break;
            }

            case 2: { 
                if (totalEmpleados < capacidadMaxima) {
                    int idAux;
                    string nombreAux;
                    
                    cout << "\n--- Nuevo Empleado ---" << endl;
                    cout << "ID: ";
                    cin >> idAux;
                    cout << "Nombre: ";
                    cin.ignore();
                    getline(cin, nombreAux);

                    listaEmpleados[totalEmpleados] = Empleado(idAux, nombreAux);
                    totalEmpleados++; 
                    
                    cout << "Empleado agregado " << endl;
                } else {
                    cout << "Error: Capacidad maxima de empleados alcanzada." << endl;
                }
                break;
            }

            case 3: { 
                if (totalEmpleados == 0) {
                    cout << "\nNo hay empleados para eliminar." << endl;
                    break;
                }

                int idEliminar;
                cout << "\nIngrese el ID del empleado a eliminar: ";
                cin >> idEliminar;

                bool encontrado = false;
                for (int i = 0; i < totalEmpleados; i++) {
                    if (listaEmpleados[i].id == idEliminar) {
                        encontrado = true;
                        for (int j = i; j < totalEmpleados - 1; j++) {
                            listaEmpleados[j] = listaEmpleados[j + 1];
                        }
                        totalEmpleados--; 
                        cout << "Empleado con ID " << idEliminar << " eliminado." << endl;
                        break;
                    }
                }

                if (!encontrado) {
                    cout << "No se encontro ningun empleado con el ID " << idEliminar << "." << endl;
                }
                break;
            }
            case 4:
            	{
            	cout << "\n--- ESTADO DEL REGISTRO ---" << endl;
                cout << "Empleados actuales: " << totalEmpleados << endl;
                cout << "Capacidad maxima: " << capacidadMaxima << endl;
                cout << "Espacios disponibles: " << (capacidadMaxima - totalEmpleados) << endl;
                break;
				}

            case 5: { 
                if (totalEmpleados > 0) {
                    for(int i = 0; i < totalEmpleados; i++) {
                        indicesEmpleados[i] = i; 
                    }

                    obMarge.marEmpleados(listaEmpleados, indicesEmpleados, 0, totalEmpleados - 1);
                    imprimirEmpleados(listaEmpleados, indicesEmpleados, totalEmpleados);
                } else {
                    cout << "\nNo hay empleados registrados para ordenar." << endl;
                }
                break;
            }

            case 6:
                cout << "Saliendo del programa..." << endl;
                break;

            default:
                cout << "Opcion no valida." << endl;
        }
    } 
	while(opcion != 6);
    return 0;
}

