#include <iostream>
#include <string>
#include <vector>
#include "ejercicios.hpp"

using namespace std;

void selectionSort(vector<int> &numeros);
void swap(int *a, int *b);

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

    // Ordenando el vector
    selectionSort(numeros);

    // Mostrando los resultados
    cout << endl
         << "Numeros ordenados: ";
    for (int a = 0; a < tam; a++)
    {
        cout << numeros[a];
    }
    cout << endl;
}

/*
    Ordenamiento de un vector por selección
*/
void selectionSort(vector<int> &conjunto)
{
    size_t size = conjunto.size(); // Guardar el tamaño del vector

    for (int step = 0; step < size - 1; step++) // Iterar paso por paso
    {
        int min_i = step; // Guardar momentaneamente, la posicion actual como el valor minimo actual para comparar

        for (int i = step + 1; i < size; i++) // Iterar desde el paso hasta el final
        {
            if (conjunto[i] < conjunto[min_i])
                min_i = i; // Guardar la nueva posicion menor
        }

        // Intercambiar valores de las posiciones
        swap(conjunto[min_i], conjunto[step]);
    }
}

/*
    Intercambio tipico de valores entre dos variables
*/
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}