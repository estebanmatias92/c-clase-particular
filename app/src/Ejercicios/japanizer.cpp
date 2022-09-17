#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include "ejercicios.hpp"

using namespace std;

/*
    Declaraciones de cabeceras
    --------------------------
*/
bool isAlphabet(char character);
bool isVowel(char character);
bool isConsonant(char character);

string japanize(const string name);

string inputName(const string message);
vector<string> inputNames(const string message = "Ingrese su nombre completo: ");

void showJapanizedNames(vector<string> names);

/*
    Definición de funciones
    -----------------------
*/
/*
    Funcion principal del ejercicio
*/
void ejercicioJapanizer()
{
    // Vector de strings para guardar los nombres
    vector<string> names;

    // Seccion ingreso de nombres
    cout << endl
         << endl
         << "Ingresando nombres" << endl
         << "------------------" << endl;

    names = inputNames();

    // Seccion mostrar lista de nombres
    cout << endl
         << endl
         << endl
         << "Mostrando nombres 'japanizados'" << endl
         << "-------------------------------" << endl;

    showJapanizedNames(names);
}

bool isAlphabet(char character)
{
    if ((character >= 'a' && character <= 'z') || (character >= 'A' && character <= 'Z'))
    {
        return true;
    }

    return false;
}

bool isVowel(char character)
{
    bool lowerVowel = (character == 'a' || character == 'e' || character == 'i' || character == 'o' || character == 'u');
    bool upperVowel = (character == 'A' || character == 'E' || character == 'I' || character == 'O' || character == 'U');

    if (lowerVowel || upperVowel)
    {
        return true;
    }

    return false;
}

bool isConsonant(char character)
{
    if (isAlphabet(character) && !isVowel(character))
    {
        return true;
    }

    return false;
}

/*
    Funcion que japoniza un nombre y agrega el sufijo "san"
*/
string japanize(const string name)
{
    // Variable string-stream para guardar el nombre una vez 'japanizado'
    stringstream japanized;

    for (size_t i = 0; i < name.size(); i++)
    {
        char current = name[i];
        char next = name[i + 1];

        japanized << current;

        if (isConsonant(current) && !isVowel(next))
        {
            japanized << 'u';
        }
    }

    // Agregamos sufijo formal al final
    japanized << "-san";

    // Retornamos el string, no el string-stream
    return japanized.str();
}

/*
    Funcion para ingresar un unico nombre completo
*/
string inputName(const string message)
{
    // Variable para guardar el nombre
    string name;

    cout << message;
    getline(cin, name); // Para captar el nombre completo con espacios

    // Devolver el nombre ingresado
    return name;
}

/*
    Funcion para ingresar multiples nombres completos y asignarlos a un vector
*/
vector<string> inputNames(const string message)
{
    // Vector de strings ir guardando cada nombre
    vector<string> names;

    // Contador y limite de ingresos
    int count = 0;
    int limit = 1000;

    // Caracter para guardar la respuesta del usuario
    char answer = 'Y';

    cout << endl; // Estetico

    // Ciclo para el ingreso de datos
    do
    {
        count++;

        // Pedir el nombre completo por teclado y guardarlo
        string name = inputName(message);

        // Si no está vacio añadirlo al vector
        if (!name.empty())
            names.push_back(name);

        // Preguntar si quiere seguir ingresando nombres
        cout << "¿Desea seguir ingresando nombres? (Y/N): ";

        // Guardar la respuesta
        cin >> answer;
        cin.ignore(); // Procurar no arrastrar en el buffer de 'Cin', ningun salto de linea cuando se presiona ENTER

    } while (answer == 'Y' && count < limit); // Mientras que la respuesta sea si, y no se exceda el limite, continuar

    // Al final de todo, devolver la lista (vector) con todos los nombres ingresados
    return names;
}

/*
    Funcion para mostrar la lista (vector) de nombres
*/
void showJapanizedNames(vector<string> names)
{
    cout << endl; // Estetico

    if (names.size() == 0)
    {
        // Si no hay nombres en la lista, avisar
        cout << "No hay nombres en la lista" << endl;
    }
    else
    {
        // Si hay, recorrer la lista (vector), japnizar el nombre y saludar en japones
        for (size_t i = 0; i < names.size(); i++)
        {
            string name = names[i];
            cout << "Konnichi wa, " << japanize(name) << endl;
        }
    }

    cout << endl; // Estetico
}