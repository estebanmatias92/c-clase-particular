#include <iostream>
#include <string>
#include "ejercicios.hpp"

using namespace std;

void saludar();
void saludarConParametros(string nombre);

// Scope GLOBAL
string nombre = "Carlos";

void ejemploScopes()
{
    string nombre = "Gregorio"; // LOCAL a esta funcion

    saludar();

    saludarConParametros(nombre); // Pasar variable LOCAL adentro de una funcion
}

void saludar()
{
    // Scope LOCAL
    string nombre2 = "Matias";
    cout << endl
         << "Hola " << nombre << endl;
}

void saludarConParametros(string nombre) // Parametros, tambien son LOCALES a la funcion
{
    cout << endl
         << "Hola " << nombre << endl;
}