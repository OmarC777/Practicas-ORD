#include "Alumnos.h"
#include <iostream>
#include <string>
using namespace std;

Alumnos::Alumnos():nombre(""), promedio(0.0) {}
Alumnos::Alumnos(string n, float p) : nombre(n), promedio(p)
{
}
Alumnos::~Alumnos()
{
}

float Alumnos::getPromedio() 
{
    return promedio;
}

string Alumnos::getNombre() 
{
    return nombre;
}

void Alumnos::imprimir()
{
    cout << "Nombre: " << nombre << " | Promedio: " << promedio << endl;
}

void Alumnos::burOb(Alumnos grupo[], int n)
 {
	for (int i = 0; i < n - 1; i++) 
	{
        for (int j = 0; j < n - i - 1; j++) 
		{
            if (grupo[j].getPromedio() > grupo[j + 1].getPromedio()) 
			{
                Alumnos temp = grupo[j];
                grupo[j] = grupo[j + 1];
                grupo[j + 1] = temp;
            }
        }
    }
}

void Alumnos::burChar(char arr[], int n) 
{
    for (int i = 0; i < n - 1; i++) 
	{
        for (int j = 0; j < n - i - 1; j++) 
		{
            if (arr[j] > arr[j + 1]) 
			{
                char temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
