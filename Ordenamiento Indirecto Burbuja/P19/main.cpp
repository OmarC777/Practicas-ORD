#include <iostream>
#include <string>
#include <cstdlib>
#include "Pasajeros.h"

using namespace std;

int main(int argc, char** argv)
 {
    Ordenamiento ord;
    int opcion;

	const int MAX = 20;
    Pasajeros listaPasajeros[MAX];
    int totalPasajeros = 0;

    do {
        cout << "\n **** MENU DE ABORDAJE **** " << endl;
        cout << "  1. Ordenar Numeros y Caracteres" << endl;
        cout << "  2. Agregar Pasajero" << endl;
        cout << "  3. Quitar Pasajero (Por Asiento)" << endl;
        cout << "  4. Mostrar total de pasajeros" << endl;
        cout << "  5. Ordenar y Mostrar Pasajeros" << endl;
        cout << "  6. Salir" << endl;
        cout << "=========================================" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion)
		{
            case 1: {
                int nNum, nLet;
                cout << "--- ENTRADA DE NUMEROS ---" << endl;
                cout << "Cuantos numeros: "; cin >> nNum;
                int vNum[nNum];
                for(int i=0; i<nNum; i++) {
                    cout << "Numero " << i+1 << ": "; cin >> vNum[i];
                }
                ord.burbujaEnteros(vNum, nNum);
                cout << "\nOrdenados: ";
                for(int i=0; i<nNum; i++) cout << vNum[i] << " ";

                cout << "\n\n--- ENTRADA DE CARACTERES ---" << endl;
                cout << "Cuantos caracteres: "; cin >> nLet;
                char vLet[nLet];
                for(int i=0; i<nLet; i++) {
                    cout << "Caracter " << i+1 << ": "; cin >> vLet[i];
                }
                ord.burbujaCaracteres(vLet, nLet);
                cout << "\nOrdenados: ";
                for(int i=0; i<nLet; i++) cout << vLet[i] << " ";
                cout << endl;
                break;
            }
            case 2: {
                if (totalPasajeros < MAX) 
				{
                    cout << "Numero de asiento: ";
                    cin >> listaPasajeros[totalPasajeros].numeroAsiento;
                    cout << "Nombre del pasajero: ";
                    cin.ignore();
                    getline(cin, listaPasajeros[totalPasajeros].nombre);
                    totalPasajeros++;
                    cout << "\n[!] Pasajero agregado.";
                } else {
                    cout << "\n[!] Lista llena.";
                }

                break;
            }
            case 3: {
                int asientoBorrar;
                cout << "Asiento a eliminar: "; cin >> asientoBorrar;
                bool encontrado = false;
                for (int i = 0; i < totalPasajeros; i++) {
                    if (listaPasajeros[i].numeroAsiento == asientoBorrar) 
					{
                        for (int j = i; j < totalPasajeros - 1; j++) {
                            listaPasajeros[j] = listaPasajeros[j + 1];
                        }
                        totalPasajeros--;
                        encontrado = true;
                        cout << "\nPasajero eliminado.";
                        break;
                    }
                }
                if (!encontrado) cout << "\nNo encontrado.";
                break;
            }
            case 4: {
                cout << "Total de pasajeros: " << totalPasajeros << endl;
                break;
            }
            case 5: {
                if (totalPasajeros > 0) {
                    ord.burbujaPasajeros(listaPasajeros, totalPasajeros);
                    cout << "--- LISTA ORDENADA ---\n";
                    for (int i = 0; i < totalPasajeros; i++) {
                        cout << "Asiento: " << listaPasajeros[i].numeroAsiento 
                             << " | Nombre: " << listaPasajeros[i].nombre << endl;
                    }
                } else {
                    cout << "No hay registros.";
                }
                break;
            }
            case 6:
                cout << "Saliendo..." << endl;
                break;
            default:
                cout << "Opcion invalida." << endl;
        }
    } while (opcion != 6);
    return 0;
}
