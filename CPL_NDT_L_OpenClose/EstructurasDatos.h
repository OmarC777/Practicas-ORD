#ifndef ESTRUCTURASDATOS_H
#define ESTRUCTURASDATOS_H
#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <list>
using namespace std;
class EstructurasDatos
{
	public:
		virtual ~EstructurasDatos() {}
	    virtual void agregar() = 0;
	    virtual void quitar() = 0;
	    virtual void mostrar() = 0;
	    virtual bool estaVacia() = 0;
	    virtual bool estaLlena() = 0;
	    virtual int tamano() = 0;
	    virtual string getNombre() = 0;
};

class VisitaWeb {
private:
    string url;
    int timeMin; 
public:
    VisitaWeb(string direccion, int tiempo);
    string obtenerUrl() const;
    int obtenerTiempo() const;
};

class NavegadorEstructura : public EstructurasDatos {
private:
    stack<VisitaWeb> pilaHistorial;
public:
    NavegadorEstructura();
    void Pagina(const VisitaWeb &visita);
    void Anterior();

    void agregar() override;
    void quitar() override;
    void mostrar() override;
    bool estaVacia() override;
    bool estaLlena() override;
    int tamano() override;
    string getNombre() override;
};

class Huesped {
public:
    string nombre;
    string tipoHab;
    int numReserva;
};

class RecepcionHotel : public EstructurasDatos {
private:
    queue<Huesped> filaEspera;
    int contadorReservas;
public:
    RecepcionHotel();
    void registrar(const string &nombre, const string &habitacion);
    void realizarCheckIn();

    void agregar() override;
    void quitar() override;
    void mostrar() override;
    bool estaVacia() override;
    bool estaLlena() override;
    int tamano() override;
    string getNombre() override;
};

class InventarioPapeleria {
public:
    int cantidad;
    string pasillo;
};
	
class Articulos {
public:
    string codigo;
    string nombre;
    InventarioPapeleria stock;
    Articulos(string _codigo, string _nombre, int _cant, string _pasillo);
    void mostrarDet() const;
};

class PapeleriaLista : public EstructurasDatos {
private:
    list<Articulos> obInv;
public:
    PapeleriaLista();

    void agregar() override;
    void quitar() override;
    void mostrar() override;
    bool estaVacia() override;
    bool estaLlena() override;
    int tamano() override;
    string getNombre() override;
};

#endif
