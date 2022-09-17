#include <iostream>
#include <string>
#include <vector>
#include "ejercicios.hpp"

using namespace std;

void ejercicioVectores()
{
    vector<string> conjuntoNombres;

    int count = 3;

    for (size_t i = 0; i < count; i++)
    {
        string nombre = "";

        cout << "Ingrese un nombre cualquiera: ";
        // cin >> nombre;
        getline(cin, nombre);

        conjuntoNombres.push_back(nombre);
        // conjuntoNombres[i] = nombre;
    }

    for (size_t i = 0; i < count; i++)
    {
        cout << "El nombre ingresado en la posicion [" << i << "] del conjunto, fue: " << conjuntoNombres[i] << "\n";
    }

    cout << "\n\n";
}