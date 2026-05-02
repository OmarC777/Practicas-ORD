#ifndef PERSONA_H
#define PERSONA_H
#include <string>
using namespace std;
class Auto 
{
	public:
		double precio;
    	int anio;
    	Auto(); 
    	void setPrecio(double p);
    	void setAnio(int a);
    	double getPrecio();
    	int getAnio();
};
class Persona
{
	public:
		string nombre;
    	string ap;
    	string am;
    	string genero;
    	int edad;
    	Auto vehiculo;
    	void setNombre(std::string n);
    	void setAp(std::string p);
    	void setAm(std::string m);
    	void setGenero(std::string g);
    	void setEdad(int e);
    	void setVehiculo(double precio, int anio);
    	void mostrarInformacion();
		Persona();
		~Persona();
};
#endif
