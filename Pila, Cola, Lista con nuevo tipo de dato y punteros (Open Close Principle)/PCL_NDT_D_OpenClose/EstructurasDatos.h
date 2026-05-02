#ifndef ESTRUCTURASDATOS_H
#define ESTRUCTURASDATOS_H
#include <iostream>
#include <string>
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

struct Maquillaje {
    int codigo;
    string nombre;
    double precio;
};

class ListaMaquillaje : public EstructurasDatos {
private:
    struct Nodo {
        Maquillaje dato;
        Nodo* sig;
    };
    Nodo* cabeza;

public:
    ListaMaquillaje();
    ~ListaMaquillaje();
    void insertar(Maquillaje m);
    bool quitarNodo(int codigoBuscar, Maquillaje &m);

    void agregar() override;
    void quitar() override;
    void mostrar() override;
    bool estaVacia() override;
    bool estaLlena() override;
    int tamano() override;
    string getNombre() override;
};

class Cliente {
public:
    string nombre;
    int idCliente;
    Cliente();
    Cliente(string nom, int id);
};

class ColaClientes : public EstructurasDatos {
private:
    struct Nodo {
        Cliente dato;
        Nodo* sig;
    };
    Nodo* prim;
    Nodo* fin;
    int limiteMaximo;

public:
    ColaClientes();
    ~ColaClientes();
    void insertarCliente(Cliente valor);    
    void quitarCliente(Cliente &valorRec);

    void agregar() override;
    void quitar() override;
    void mostrar() override;
    bool estaVacia() override;
    bool estaLlena() override;
    int tamano() override;
    string getNombre() override;
};

struct Alumno {
    int boleta;
    string nombre;
    float promedio;
};

class PilaAlumnos : public EstructurasDatos {
private:
    struct Nodo {
        Alumno dato;
        Nodo* sig;
    };
    Nodo* tope;

public:
    PilaAlumnos();
    ~PilaAlumnos();
    void apilar(Alumno nuevoAlumno);
    bool desapilar(Alumno& alumnoExtraido);

    void agregar() override;
    void quitar() override;
    void mostrar() override;
    bool estaVacia() override;
    bool estaLlena() override;
    int tamano() override;
    string getNombre() override;
};
#endif
