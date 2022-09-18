#include <iostream>
#include <string>
#include <sstream>
#include "ejercicios.hpp"

using namespace std;

string contarConsecutivos(string message);

void ejercicioCountingChars()
{
    string msg = "BBBBAVAAAAACC-123cCCC";
    cout << "Ingrese caracteres: ";
    getline(cin, msg);

    cout << endl
         << "Original: " << msg << endl
         << "Resultado: " << contarConsecutivos(msg) << endl
         << endl;
}

string contarConsecutivos(string message)
{
    stringstream result;

    for (size_t i = 0; i < message.size(); i++)
    {
        int contador = 1;

        while (message[i] == message[i + 1])
        {
            i++;
            contador++;
        }

        if (contador > 1)
            result << '(' << message[i] << contador << ')';
        else
            result << message[i];
    }

    return result.str();
}