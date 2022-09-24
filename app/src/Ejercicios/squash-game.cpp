#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
#include "ejercicios.hpp"

using namespace std;

bool isSetTerminado(int a, int b);
string generarSets(string message);

void ejercicioSquashGame()
{
    cout << endl
         << "Partido de Squash" << endl
         << "-----------------" << endl;

    string msg = "BF";
    // string msg = "AABBBABBF";
    // cout << "Ingrese los tantos de los jugadores A y B y finalize con F: ";
    // getline(cin, msg);

    cout << endl
         << "Partido (tantos): " << msg << endl
         << "Partido (sets): " << generarSets(msg) << endl
         << endl;
}

string generarSets(string message)
{
    size_t size = message.size();             // Guardar el tamaño del string
    char ultimo_caracter = message[size - 1]; // Último caracter del string
    char final_partido = 'F';

    // Si el último caracter no es el final del partido, entonces es invalido el string y se retorna nada
    if (ultimo_caracter != final_partido)
        return "";

    stringstream partido;

    int puntaje_a = 0;
    int puntaje_b = 0;

    // Recorrer todo el partido, tanto por tanto (caracter por caracter)
    for (size_t i = 0; i < size; i++)
    {
        char tanto_anterior = (i == 0) ? 'A' : message[i - 1];
        char tanto_actual = message[i];
        char tanto_siguiente = message[i + 1];

        // Si el jugador que hace este tanto es distinto del anterior, saltar al siguiente tanto
        if (tanto_anterior != tanto_actual)
            continue;

        // Suma simple de puntos
        switch (tanto_actual)
        {
        case 'A':
            puntaje_a++;
            break;
        case 'B':
            puntaje_b++;
            break;

        default:
            break;
        }

        // Si el set está terminado, escribir los puntajes y resetear los tantos
        if (isSetTerminado(puntaje_a, puntaje_b))
        {
            partido << puntaje_a << "-" << puntaje_b;

            // Limpiar los puntajes para el siguiente set
            puntaje_a = 0;
            puntaje_b = 0;

            // Si el siguiente caracter no es el final del partido, agregar espacio
            if (tanto_siguiente != final_partido)
                partido << " ";
        }
    }

    // Agregar el ultimo set, hasta donde haya llegado
    partido << puntaje_a << "-" << puntaje_b;

    // Retornar todo el partido completo
    return partido.str();
}

/*
    Funcion para confirmar si el set está terminado
*/
bool isSetTerminado(int a, int b)
{
    // Si alguno de los jugadores alcanzó 9 o mas y la diferencia entre ambos de 2, entonces devolver TRUE
    return (a >= 9 || b >= 9) && (abs(a - b) == 2);
}