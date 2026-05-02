#include "EstructurasDatos.h"
#include <iostream>
using namespace std;
//logica de makup (lista)
ListaMaquillaje::ListaMaquillaje() { cabeza = NULL; }
ListaMaquillaje::~ListaMaquillaje() {
    Nodo* actual = cabeza;
    while(actual != NULL) {
        Nodo* temp = actual;
        actual = actual->sig;
        delete temp;
    }
}
void ListaMaquillaje::insertar(Maquillaje m) {
    Nodo* NuNodo = new Nodo();
    NuNodo->dato = m; NuNodo->sig = NULL;
    if (cabeza == NULL) cabeza = NuNodo;
    else {
        Nodo* actual = cabeza;
        while (actual->sig != NULL) actual = actual->sig;
        actual->sig = NuNodo;
    }
}
bool ListaMaquillaje::quitarNodo(int codigoBuscar, Maquillaje &m) {
    if(cabeza == NULL) return false; 
    if (cabeza->dato.codigo == codigoBuscar) {
        Nodo* ex = cabeza; m = ex->dato; 
        cabeza = cabeza->sig; delete ex; return true;
    }
    Nodo* actual = cabeza;
    while (actual->sig != NULL && actual->sig->dato.codigo != codigoBuscar) actual = actual->sig;
    if (actual->sig != NULL) {
        Nodo* ex = actual->sig; m = ex->dato; 
        actual->sig = ex->sig; delete ex; return true;
    }
    return false; 
}
void ListaMaquillaje::agregar() {
    Maquillaje maqAux;
    cout << "\nIngrese el codigo: "; cin >> maqAux.codigo;
    cin.ignore(); cout << "Ingrese el nombre del producto: "; getline(cin, maqAux.nombre);
    cout << "Ingrese el precio: $"; cin >> maqAux.precio;
    insertar(maqAux);
    cout << "-> Producto agregado con exito." << endl;
}
void ListaMaquillaje::quitar() {
    int codigoEliminar; Maquillaje maqAux;
    cout << "\nIngrese el codigo del producto que desea quitar: "; cin >> codigoEliminar;
    if (quitarNodo(codigoEliminar, maqAux)) {
        cout << "\n-> Producto extraido de la lista:\nCodigo: " << maqAux.codigo << "\nNombre Producto: " << maqAux.nombre << "\nPrecio: $" << maqAux.precio << endl;
    } else {
        cout << "\n-> Error: No se encontro ningun producto con ese codigo o el carrito esta vacio.\n";
    }
}
void ListaMaquillaje::mostrar() {
    if (estaVacia()) { cout << "La lista esta vacia." << endl; return; }
    Nodo* actual = cabeza;
    while (actual != NULL) {
        cout << "Codigo: " << actual->dato.codigo << " | Producto: " << actual->dato.nombre << " | Precio: $" << actual->dato.precio << endl;
        actual = actual->sig; 
    }
}
bool ListaMaquillaje::estaVacia() { return cabeza == NULL; }
bool ListaMaquillaje::estaLlena() { return false; }
int ListaMaquillaje::tamano() {
    int contador = 0; Nodo* actual = cabeza;
    while (actual != NULL) { contador++; actual = actual->sig; }
    return contador;
}
string ListaMaquillaje::getNombre() { return "Makeup Store (Lista)"; }

//logica de clientes (cola)
Cliente::Cliente() { nombre = ""; idCliente = 0; }
Cliente::Cliente(string nom, int id) { nombre = nom; idCliente = id; }

ColaClientes::ColaClientes() { prim = NULL; fin = NULL; limiteMaximo = 5; }
ColaClientes::~ColaClientes() {
    Cliente aux; 
    while (!estaVacia()) quitarCliente(aux);
}
void ColaClientes::insertarCliente(Cliente valor) {
    Nodo* NuNodo = new Nodo(); NuNodo->dato = valor; NuNodo->sig = NULL;
    if (estaVacia()) prim = NuNodo;
    else fin->sig = NuNodo;
    fin = NuNodo;
    cout << "Se formo al cliente: " << valor.nombre << " (ID: " << valor.idCliente << ")" << endl;
}
void ColaClientes::quitarCliente(Cliente &valorRec) {
    valorRec = prim->dato; Nodo* nEliminar = prim;
    if (prim == fin) { prim = NULL; fin = NULL; } 
    else prim = prim->sig;
    delete nEliminar;
    cout << "Se atendio y salio el cliente: " << valorRec.nombre << " (ID: " << valorRec.idCliente << ")" << endl;
}
void ColaClientes::agregar() {
    if (estaLlena()) { cout << "La cola esta llena. No puedes agregar mas." << endl; return; }
    string nombreTemp; int idTemp;
    cout << "Ingresa el nombre del cliente: "; cin >> ws; getline(cin, nombreTemp);
    cout << "Ingresa el ID del cliente (numero): "; cin >> idTemp;
    insertarCliente(Cliente(nombreTemp, idTemp));
}
void ColaClientes::quitar() {
    Cliente clienteAtendido;
    if (!estaVacia()) quitarCliente(clienteAtendido);
    else cout << "La cola esta vacia. No hay clientes por atender." << endl;
}
void ColaClientes::mostrar() {
    if (estaVacia()) { cout << "La cola esta vacia." << endl; return; }
    Nodo* actual = prim; int posicion = 1;
    cout << "Frente -> Final: \n";
    while (actual != NULL) {
        cout << posicion << ". Nombre: " << actual->dato.nombre << " | ID: " << actual->dato.idCliente << endl;
        actual = actual->sig; posicion++;
    }
}
bool ColaClientes::estaVacia() { return prim == NULL; }
bool ColaClientes::estaLlena() { return tamano() >= limiteMaximo; }
int ColaClientes::tamano() {
    int contador = 0; Nodo* actual = prim;
    while (actual != NULL) { contador++; actual = actual->sig; }
    return contador;
}
string ColaClientes::getNombre() { return "Fila de Clientes (Cola)"; }

//logica de alumnos (pila)
PilaAlumnos::PilaAlumnos() { tope = NULL; }
PilaAlumnos::~PilaAlumnos() {
    Alumno aux;
    while(!estaVacia()) desapilar(aux);
}
void PilaAlumnos::apilar(Alumno nuevoAlumno) {
    Nodo* nuNodo = new Nodo();
    nuNodo->dato = nuevoAlumno; nuNodo->sig = tope; tope = nuNodo;
}
bool PilaAlumnos::desapilar(Alumno& alumnoExtraido) {
    if (tope == NULL) { cout << "La pila esta vacia" << endl; return false; }
    Nodo* ex = tope; alumnoExtraido = ex->dato; tope = ex->sig; delete ex; return true;
}
void PilaAlumnos::agregar() {
    Alumno nuevo;
    cout << "\nIngresa la boleta: "; cin >> nuevo.boleta;
    cout << "Ingresa el nombre: "; cin >> ws; getline(cin, nuevo.nombre);
    cout << "Ingresa el promedio: "; cin >> nuevo.promedio;
    apilar(nuevo);
    cout << "Alumno apilado correctamente." << endl;
}
void PilaAlumnos::quitar() {
    Alumno nuevo;
    cout << "\nExtrayendo alumno de la pila:\n";
    if (desapilar(nuevo)) {
        cout << "Nombre: " << nuevo.nombre << "\nBoleta: " << nuevo.boleta << "\nPromedio: " << nuevo.promedio << endl;
    }
}
void PilaAlumnos::mostrar() {
    if (estaVacia()) { cout << "Pila Vacia. No hay alumnos que mostrar." << endl; return; }
    Nodo* actual = tope;
    while (actual != NULL) {
        cout << "Boleta: " << actual->dato.boleta << " | Nombre: " << actual->dato.nombre << " | Promedio: " << actual->dato.promedio << endl;
        actual = actual->sig;
    }
}
bool PilaAlumnos::estaVacia() { return tope == NULL; }
bool PilaAlumnos::estaLlena() { return false; }
int PilaAlumnos::tamano() {
    int contador = 0; Nodo* actual = tope;
    while (actual != NULL) { contador++; actual = actual->sig; }
    return contador;
}
string PilaAlumnos::getNombre() { return "Registro de Alumnos (Pila)"; }
