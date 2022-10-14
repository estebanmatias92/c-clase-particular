#include <iostream>
#include <string>
#include <vector>
#include "ejercicios.hpp"

using namespace std;

void selectionSort();

void ejemploSort()
{
    cout << endl
         << "Ordenamiento por seleccion:" << endl
         << endl;

    vector<int> numeros;
    int tam, num;

    cout << "Ingrese el numero de datos: ";
    cin >> tam;

    // Pidiendo los numeros
    for (int i = 0; i < tam; i++)
    {
        int entero;

        cout << "Ingrese un numero: ";
        // cin >> numeros[i]; // Esta linea tira Segmentacion de Memoria "Segmentation fault error", esta tratando de asignar el valor como un array tradicional y el vecotr no conoce el elemento en "i" hasta que es creado
        cin >> entero;
        numeros.push_back(entero);
    }

    // Ordenando
    for (int j = 0; j < tam; j++)
    {
        for (int t = j + 1; t < tam; t++)
        {
            if (numeros[j] < numeros[t])
            {
                num = numeros[j];
                numeros[j] = numeros[t];
                numeros[t] = num;
            }
        }
    }

    // Mostrando los resultados
    cout << endl
         << "Numeros ordenados: ";
    for (int a = 0; a < tam; a++)
    {
        cout << numeros[a];
    }
    cout << endl;
}

void selectionSort() {}