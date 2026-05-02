#include "Persona.h"
#include <iostream>
Auto::Auto()
{
	precio = 0.0;
	anio = 0;
}
void Auto::setPrecio(double p) 
{
    precio = p;
}

void Auto::setAnio(int a) 
{
    anio = a;
}

double Auto::getPrecio() 
{
    return precio;
}

int Auto::getAnio() 
{
    return anio;
}
Persona::Persona()
{
	nombre = "";
    ap = "";
    am = "";
    genero = "";
    edad = 0;
}

Persona::~Persona()
{
}
void Persona::setNombre(string n) 
{ 
	nombre = n; 
}
void Persona::setAp(string p) 
{ 
	ap = p; 
}
void Persona::setAm(string m) 
{
	am = m; 
}
void Persona::setGenero(string g) 
{
	genero = g; 
}
void Persona::setEdad(int e) 
{
	edad = e; 
}

void Persona::setVehiculo(double precio, int anio) 
{
    vehiculo.setPrecio(precio);
    vehiculo.setAnio(anio);
}

void Persona::mostrarInformacion() 
{
    cout << "Nombre: " << nombre << endl;
    cout << "Apellido Paterno: " << ap << endl; 
    cout << "Apellido Materno: " << am << endl;
    cout << "Genero: " << genero << endl;
    cout << "Edad: " << edad << endl;
    cout << "Precio del auto: $" << vehiculo.getPrecio() << endl; 
    cout << "Modelo: " << vehiculo.getAnio() << endl;
    cout << "____________________________" << endl;
}
