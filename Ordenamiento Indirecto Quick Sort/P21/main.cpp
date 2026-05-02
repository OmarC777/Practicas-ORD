#include <iostream>
#include <string>
#include "Empleado.h"

using namespace std;

int main(int argc, char** argv) 
{
    OrdenadorQS obQuick;
    
    const int MAX_EMPLEADOS = 20; 
    Empleado empleadosRegistrados[MAX_EMPLEADOS];
    int totalEmpleados = 0;
    int opcion;

    do {
        cout << "\n--- MENU ---" << endl;
        cout << "1. Ordenar numeros y caracteres" << endl;
        cout << "2. Agregar Empleado" << endl;
        cout << "3. Quitar Empleado (Por ID)" << endl;
        cout << "4. Mostrar total de empleados" << endl;
        cout << "5. Ordenar y Mostrar Empleados" << endl;
        cout << "6. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) 
		{
            case 1: {
                const int MAX_ELEMENTOS = 20; 
              
                cout << "\n--- QUICK SORT INDIRECTO: ENTEROS ---" << endl;
                int tamNumerosQ;
                cout << "Cuantos numeros deseas ingresar? (Max " << MAX_ELEMENTOS << "):\n ";
                cin >> tamNumerosQ;

                if (tamNumerosQ > MAX_ELEMENTOS) tamNumerosQ = MAX_ELEMENTOS;
                if (tamNumerosQ <= 0) tamNumerosQ = 1;

                int numerosQ[MAX_ELEMENTOS];
                int indNumeros[MAX_ELEMENTOS];

                for (int i = 0; i < tamNumerosQ; i++) 
				{
                    cout << "Ingresa el numero [" << i + 1 << "]: ";
                    cin >> numerosQ[i];
                    indNumeros[i] = i; 
                }

                obQuick.ordenarEnteros(numerosQ, indNumeros, 0, tamNumerosQ - 1);

                cout << "Numeros ordenados: ";
                for(int i = 0; i < tamNumerosQ; i++) {
                    cout << numerosQ[indNumeros[i]] << " ";
                }
				cout << "\n\n";
				
				cout << "--- QUICK SORT INDIRECTO: CARACTERES ---" << endl;
                int tamLetras;
                cout << "Cuantos caracteres deseas ingresar? (Max " << MAX_ELEMENTOS << "):\n";
                cin >> tamLetras;

                if (tamLetras > MAX_ELEMENTOS) tamLetras = MAX_ELEMENTOS;
                if (tamLetras <= 0) tamLetras = 1;

                char letras[MAX_ELEMENTOS];
                int indLetras[MAX_ELEMENTOS];

                for (int i = 0; i < tamLetras; i++) 
				{
                    cout << "Ingresa el caracter [" << i + 1 << "]: ";
                    cin >> letras[i];
                    indLetras[i] = i; 
                }

                obQuick.ordenarCaracteres(letras, indLetras, 0, tamLetras - 1);

                cout << "Caracteres ordenados: ";
                for(int i = 0; i < tamLetras; i++) {
                    cout << letras[indLetras[i]] << " ";
                }
                cout << "\n\n";
                break;
            }
            case 2: {
                if (totalEmpleados < MAX_EMPLEADOS) {
                    int id;
                    string nombre;
                    cout << "Ingrese el ID del empleado: ";
                    cin >> id;
                    cout << "Ingrese el Nombre del empleado: ";
                    cin >> nombre; 
                    
                    empleadosRegistrados[totalEmpleados] = Empleado(id, nombre);
                    totalEmpleados++;
                    cout << "Empleado agregado exitosamente.\n";
                } else {
                    cout << "No se pueden agregar mas empleados (Limite alcanzado).\n";
                }
                break;
            }
            case 3: {
                if (totalEmpleados == 0) {
                    cout << "No hay empleados para eliminar.\n";
                    break;
                }
                int idBuscar;
                bool encontrado = false;
                cout << "Ingrese el ID del empleado a quitar: ";
                cin >> idBuscar;

                for (int i = 0; i < totalEmpleados; i++)
				 {
                    if (empleadosRegistrados[i].id == idBuscar) 
					{
                        encontrado = true;
                        for (int j = i; j < totalEmpleados - 1; j++) 
						{
                            empleadosRegistrados[j] = empleadosRegistrados[j + 1];
                        }
                        totalEmpleados--;
                        cout << "Empleado eliminado exitosamente.\n";
                        break;
                    }
                }
                if (!encontrado) {
                    cout << "Empleado con ID " << idBuscar << " no encontrado.\n";
                }
                break;
            }
            case 4: {
                cout << "Total de empleados registrados actualmente: " << totalEmpleados << endl;
                break;
            }
            case 5: {
                if (totalEmpleados > 0) {
                    cout << "\nQUICK SORT INDIRECTO: EMPLEADOS" << endl;
                    
                    int indEmpleados[MAX_EMPLEADOS];
                    for(int i = 0; i < totalEmpleados; i++) {
                        indEmpleados[i] = i;
                    }

                    obQuick.ordenarEmpleados(empleadosRegistrados, indEmpleados, 0, totalEmpleados - 1);

                    for(int i = 0; i < totalEmpleados; i++) {
                        cout << "ID: " << empleadosRegistrados[indEmpleados[i]].id 
                             << " - Nombre: " << empleadosRegistrados[indEmpleados[i]].nombre << endl;
                    }
                    cout << "\n";
                } else {
                    cout << "No hay empleados registrados para ordenar. Agregue empleados primero.\n";
                }
                break;
            }
            case 6: {
                cout << "Saliendo del programa...\n";
                break;
            }
            default: {
                cout << "Opcion invalida. Intente de nuevo.\n";
                break;
            }
        }
    } while (opcion != 6);
    return 0;
}

