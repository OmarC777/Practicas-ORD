#include "EstructurasDatos.h"
#include <iostream>

//logica de navegador (pila)
VisitaWeb::VisitaWeb(string direccion, int tiempo) { url = direccion; timeMin = tiempo; }
string VisitaWeb::obtenerUrl() const { return url; }
int VisitaWeb::obtenerTiempo() const { return timeMin; }

NavegadorEstructura::NavegadorEstructura() {}
void NavegadorEstructura::Pagina(const VisitaWeb &visita) {
    pilaHistorial.push(visita);
    cout << "Visitando: " << visita.obtenerUrl() << " (Estuviste " << visita.obtenerTiempo() << " min en la pagina web)\n";
}
void NavegadorEstructura::Anterior() {
    if(pilaHistorial.empty()) cout << "Ya no hay paginas pendientes, historial vacio\n";
    else {
        cout << "Saliendo de: " << pilaHistorial.top().obtenerUrl() << "\n";
        pilaHistorial.pop(); 
        if(!pilaHistorial.empty()) cout << "Ahora estas en: " << pilaHistorial.top().obtenerUrl() << "\n";
        else cout << "Estas en una pagina en blanco\n";
    }
}
void NavegadorEstructura::agregar() {
    string url; int tiempo;
    cout << "Ingresa la URL (ej. www.upiicsa.ipn.mx): "; cin >> url;
    cout << "Ingresa el tiempo de visita en minutos: "; cin >> tiempo;
    Pagina(VisitaWeb(url, tiempo));
}
void NavegadorEstructura::quitar() { Anterior(); }
void NavegadorEstructura::mostrar() {
    if(pilaHistorial.empty()) cout << "No hay paginas activas\n";
    else cout << "Pagina actual: " << pilaHistorial.top().obtenerUrl() << "\n";
}
bool NavegadorEstructura::estaVacia() { return pilaHistorial.empty(); }
bool NavegadorEstructura::estaLlena() { return false; }
int NavegadorEstructura::tamano() { return pilaHistorial.size(); }
string NavegadorEstructura::getNombre() { return "Navegador Web (Pila STL)"; }

//logica de hotel (cola)
RecepcionHotel::RecepcionHotel() { contadorReservas = 10; }
void RecepcionHotel::registrar(const string &nombre, const string &habitacion) {
    Huesped nvHues; nvHues.nombre = nombre; nvHues.tipoHab = habitacion; nvHues.numReserva = contadorReservas++;
    filaEspera.push(nvHues);
    cout << "REGISTRO:\nHuesped " << nombre << " , tiene una habitacion " << habitacion << " (Num. Reserva:" << nvHues.numReserva << ")\n";
}
void RecepcionHotel::realizarCheckIn() {
    if (filaEspera.empty()) cout << "No hay nadie en recepcion\n";
    else {
        Huesped h = filaEspera.front();
        cout << "Realizando Check-in de: " << h.nombre << " - Habitacion: " << h.tipoHab << "\n";
        filaEspera.pop();
    }
}
void RecepcionHotel::agregar() {
    string nombre, habitacion;
    cout << "\nIngrese el nombre del huesped: "; cin >> ws; getline(cin, nombre);
    cout << "Ingrese el tipo de habitacion (Sencilla/Doble/Suite): "; getline(cin, habitacion);
    registrar(nombre, habitacion);
}
void RecepcionHotel::quitar() { realizarCheckIn(); }
void RecepcionHotel::mostrar() {
    if (filaEspera.empty()) cout << "La recepcion esta vacia\n";
    else cout << "El proximo en ser atendido es: " << filaEspera.front().nombre << "\nPersonas esperando: " << filaEspera.size() << "\n";
}
bool RecepcionHotel::estaVacia() { return filaEspera.empty(); }
bool RecepcionHotel::estaLlena() { return false; }
int RecepcionHotel::tamano() { return filaEspera.size(); }
string RecepcionHotel::getNombre() { return "Recepcion de Hotel (Cola STL)"; }

//logica de papelria (pila)
Articulos::Articulos(string _codigo, string _nombre, int _cant, string _pasillo) {
    codigo = _codigo; nombre = _nombre; stock.cantidad = _cant; stock.pasillo = _pasillo;
}
void Articulos::mostrarDet() const {
    cout << "Codigo: " << codigo << "\nNombre: " << nombre << "\nCantidad: " << stock.cantidad << "\nPasillo: " << stock.pasillo << "\n\n";
}

PapeleriaLista::PapeleriaLista() {}
void PapeleriaLista::agregar() {
    string t_codigo, t_nombre, t_pasillo; int t_cantidad;
    cout << "\n--- Ingresar Datos del Articulo ---\nCodigo: "; cin >> t_codigo;
    cout << "Nombre: "; cin >> t_nombre;
    cout << "Cantidad: "; cin >> t_cantidad;
    cout << "Pasillo: "; cin >> t_pasillo;
    obInv.push_back(Articulos(t_codigo, t_nombre, t_cantidad, t_pasillo));
    cout << "-> Articulo agregado con exito.\n";
}
void PapeleriaLista::quitar() {
    if (!obInv.empty()) {
        string codigoEliminar; cout << "\nIngrese el Codigo del articulo a quitar: "; cin >> codigoEliminar;
        bool encontrado = false;
        for(auto it = obInv.begin(); it != obInv.end(); ++it) {
            if (it->codigo == codigoEliminar) {
                cout << "-> Articulo eliminado: " << it->nombre << " (Codigo: " << it->codigo << ")\n";
                obInv.erase(it); encontrado = true; break;
            }
        }
        if (!encontrado) cout << "-> Error: No se encontro ningun articulo con el codigo '" << codigoEliminar << "'.\n";
    } else cout << "-> Error: El inventario ya esta vacio.\n";
}
void PapeleriaLista::mostrar() {
    if (obInv.empty()) cout << "\n-> El inventario esta vacio.\n";
    else {
        cout << "\n--- I N V E N T A R I O ---\n";
        for(auto it = obInv.begin(); it != obInv.end(); ++it) it->mostrarDet();
    }
}
bool PapeleriaLista::estaVacia() { return obInv.empty(); }
bool PapeleriaLista::estaLlena() { return false; }
int PapeleriaLista::tamano() { return obInv.size(); }
string PapeleriaLista::getNombre() { return "Inventario Papeleria (Lista STL)"; }
