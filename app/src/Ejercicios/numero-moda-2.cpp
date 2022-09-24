#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include "ejercicios.hpp"

using namespace std;

vector<vector<int>> ingresarConjuntosNumericos();
void mostrarConjuntosNumericos(vector<vector<int>> conjuntos);

int obtenerItemMaximaFrecuencia(vector<int> conjunto);

/*
    Funcion que reune todo el ejercicio
*/
void ejercicioNumeroModa2()
{
    cout << endl
         << "Número de moda (mas repetido)" << endl
         << "-----------------------------" << endl;

    // Pedir conjuntos de numeros
    vector<vector<int>> grupos_numericos = ingresarConjuntosNumericos();

    // Mostrar grupo por grupo de numeros
    mostrarConjuntosNumericos(grupos_numericos);

    // Ahora recorrer cada conjunto del conjunto padre, obtener el item mas repetido y mostrarlo
    cout << endl
         << "Frecuencia mayor:" << endl;

    for (size_t i = 0; i < grupos_numericos.size(); i++)
    {
        cout << "Conjunto [" << i << "]: " << obtenerItemMaximaFrecuencia(grupos_numericos[i]) << endl;
    }
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
    Funcion para obtener el numero mas repetido de UN conjunto
*/
int obtenerItemMaximaFrecuencia(vector<int> conjunto)
{
    // Empezar inicializando el numero repetido y maximo de repeticiones con algun valor para poder comparar
    int repetido = conjunto[0];
    int maximo = 0;

    // Guardar aparte el tamaño del conjunto
    size_t size = conjunto.size();

    // Crear un vector del mismo tamaño que "conjunto" y rellenarlo con "false"
    vector<bool> revisados(size, false);

    // Recorrer el conjunto de numeros
    for (size_t i = 0; i < size; i++)
    {
        // Saltar al siguiente numero si el actual ya fue contado
        if (revisados[i] == true)
            continue;

        int count = 1; // Preparar variable para contar repeticiones

        // Ahora recorrer y comprobar si el item que se está leyendo ya fue contabilizado
        // Si no fue contabilizado tacharlo (asignar true) y contar + 1
        for (size_t j = i + 1; j < size; j++)
        {
            if (conjunto[i] == conjunto[j])
            {
                revisados[j] = true;
                count++;
            }
        }

        // Si la nueva contabilizacion (count) es mayor que ultimo maximo guardado, actualizar el maximo
        // y actualizar el numero que se repite
        if (maximo < count)
        {
            maximo = count;
            repetido = conjunto[i];
        }
    }

    // Al final siempre va a quedar el maximo de repeticiones y el numero que se repitió mas veces, entonces retornar
    return repetido;
}