#include <iostream>
#include <string>
#include "Persona.h" 

using namespace std;

int main() 
{
    Persona lista[5]; 
    int cantidadRegistrada = 0; 
    int opcion;
    string tempString;
    int tempInt;
    double tempDouble;

    do {
        cout << "\n=== Menu de Personas y Autos ===" << endl;
        cout << "1. Agregar elemento " << endl;
        cout << "2. Quitar elemento " << endl;
        cout << "3. Mostrar registros" << endl;
        cout << "4. Verificar si esta vacia" << endl;
        cout << "5. Verificar si esta llena" << endl;
        cout << "6. Mostrar tamano de la lista" << endl;
        cout << "7. Salir" << endl;
        cout << "Elige una opcion: ";
        cin >> opcion;

        switch(opcion) {
            case 1: 
                if (cantidadRegistrada >= 5) {
                    cout << "-> ERROR: La lista esta llena. No puedes agregar mas de 5 personas." << endl;
                } else {
                    cout << "\n--- REGISTRANDO PERSONA " << (cantidadRegistrada + 1) << " ---" << endl;
                    
                    cout << "Nombre: "; 
                    cin >> tempString;
                    lista[cantidadRegistrada].setNombre(tempString);
                    
                    cout << "Ap. Paterno: "; 
                    cin >> tempString;
                    lista[cantidadRegistrada].setAp(tempString);
                    
                    cout << "Ap. Materno: "; 
                    cin >> tempString;
                    lista[cantidadRegistrada].setAm(tempString);
                    
                    cout << "Edad: "; 
                    cin >> tempInt;
                    lista[cantidadRegistrada].setEdad(tempInt);
                    
                    cout << "Genero: "; 
                    cin >> tempString;
                    lista[cantidadRegistrada].setGenero(tempString);
                    
                    cout << ">>> Datos de su auto <<<" << endl;
                    cout << "Precio: $"; 
                    cin >> tempDouble;
                    cout << "Anio: "; 
                    cin >> tempInt;
                    
                    lista[cantidadRegistrada].setVehiculo(tempDouble, tempInt);
                    
                    cantidadRegistrada++;
                    cout << "-> Elemento agregado con exito." << endl;
                }
                break;
                
            case 2:
                if (cantidadRegistrada > 0) {
                    cantidadRegistrada--; 
                    cout << "-> Se quito el ultimo elemento registrado: " << lista[cantidadRegistrada].nombre << endl;
                } else {
                    cout << "-> No se puede quitar, la lista ya esta vacia." << endl;
                }
                break;
                
            case 3:
                cout << "\n--- CONTENIDO ---" << endl;
                if (cantidadRegistrada == 0) {
                    cout << "La lista esta vacia. No hay registros para mostrar." << endl;
                } else {
                    for (int i = 0; i < cantidadRegistrada; i++) {
                        cout << "\nPersona #" << (i + 1) << ":" << endl;
                        lista[i].mostrarInformacion();
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
                if (cantidadRegistrada == 5) {
                    cout << "-> La lista SI esta llena (Limite maximo: 5)." << endl;
                } else {
                    cout << "-> La lista NO esta llena. (Espacio disponible: " << (5 - cantidadRegistrada) << ")." << endl;
                }
                break;
                
            case 6:
                cout << "-> El tamano actual de la lista es de: " << cantidadRegistrada << " elementos registrados." << endl;
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
