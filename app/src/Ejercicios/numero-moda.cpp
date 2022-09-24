#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include "ejercicios.hpp"

using namespace std;

unordered_map<int, int> obtenerFrecuencias(vector<int> numeros);
vector<vector<int>> ingresarConjuntosNumericos();
void mostrarConjuntosNumericos(vector<vector<int>> conjuntos);

unordered_map<int, int> obtenerFrecuencias(vector<int> numeros);
int obtenerFrecuenciaMayor(unordered_map<int, int> frecuencias);
void mostrarFrecuenciasMayores(vector<vector<int>> conjuntos);

/*
    Funcion que reune todo el ejercicio
*/
void ejercicioNumeroModa()
{
    cout << endl
         << "Número de moda (mas repetido)" << endl
         << "-----------------------------" << endl;

    // Pedir conjuntos de numeros
    vector<vector<int>> grupos_numericos = ingresarConjuntosNumericos();

    // Mostrar grupo por grupo de numeros
    mostrarConjuntosNumericos(grupos_numericos);

    mostrarFrecuenciasMayores(grupos_numericos);
}

/*
    Funcion para mostrar cada conjunto y sus numeros
*/
void mostrarConjuntosNumericos(vector<vector<int>> conjuntos)
{
    cout << endl
         << "Conjuntos numéricos:" << endl;

    for (size_t i = 0; i < conjuntos.size(); i++)
    {
        vector<int> numeros = conjuntos[i];

        cout << "Posición [" << i << "]: ";

        for (size_t j = 0; j < numeros.size(); j++)
        {
            cout << numeros[j] << " ";
        }
        cout << endl;
    }
}

/*
    Funcion para ingresar cada conjunto y sus numeros
*/
vector<vector<int>> ingresarConjuntosNumericos()
{
    size_t size = 0;
    vector<vector<int>> conjuntos; // Conjunto padre

    do
    {
        cout << endl
             << "Tamaño del conjunto numérico: ";
        cin >> size;
        cin.ignore();

        // Saltar hasta el final del while, para luego salir
        if (size == 0)
            continue;

        vector<int> numeros; // Conjunto hijo
        int numero = 0;

        for (size_t i = 0; i < size; i++)
        {
            cout << "Conjunto [" << i << "]: ";
            cin >> numero;
            cin.ignore();

            numeros.push_back(numero);
        }

        // Añadir el conjunto de numeros al conjunto padre
        conjuntos.push_back(numeros);

    } while (size > 0);

    // Retornar el conjunto de conjuntos
    return conjuntos;
}

/*
    Obtener todas las frecuencias de cada numero del conjunto y devolver un diccionario/map/hash
*/
unordered_map<int, int> obtenerFrecuencias(vector<int> numeros)
{
    unordered_map<int, int> frecuencias;

    for (size_t i = 0; i < numeros.size(); i++)
    {
        int numero = numeros[i];
        frecuencias[numero]++;
    }

    return frecuencias;
}

/*
    Obtener el numero con mayor frecuencia
*/
int obtenerFrecuenciaMayor(unordered_map<int, int> frecuencias)
{
    int clave_maximo = frecuencias.begin()->first;
    int valor_maximo = frecuencias.begin()->second;

    for (auto item : frecuencias)
    {
        if (valor_maximo < item.second)
        {
            clave_maximo = item.first;
            valor_maximo = item.second;
        }
    }

    return clave_maximo;
}

void mostrarFrecuenciasMayores(vector<vector<int>> conjuntos)
{
    cout << endl
         << "Frecuencia mayor:" << endl;

    for (size_t i = 0; i < conjuntos.size(); i++)
    {
        vector<int> conjunto = conjuntos[i];
        unordered_map<int, int> frecuencias = obtenerFrecuencias(conjunto);
        cout << "Conjunto [" << i << "]: " << obtenerFrecuenciaMayor(frecuencias) << endl;
    }
}