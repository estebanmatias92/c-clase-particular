#include <iostream>
#include <string>
#include "ejercicios.hpp"

using namespace std;

void saludar();
void saludarConParametros(string variable_local);

// Scope GLOBAL
string variable_global = "Soy una variable global";

void ejemploScopes()
{
    string variable_global = "Hago de cuenta que soy global";
    string variable_local = "Soy una variable local en 'ejemploScopes()'"; // LOCAL a esta funcion

    cout << endl
         << "INICIO programa principal 'ejemploScopes()':" << endl
         << endl;

    // Primer llamado a una funcion
    saludar();

    cout << endl
         << endl;

    // Segundo llamado a una funcion
    saludarConParametros(variable_global); // Pasar variable LOCAL adentro de una funcion

    cout << endl
         << "FINAL programa principal 'ejemploScopes()'" << endl;
}

void saludar()
{
    // Scope LOCAL
    string variable_local = "Soy una variable local en 'saludar()'";

    cout << "  INICIO funcion 'saludar()':" << endl
         << "\tHola!, " << variable_local << endl
         << "\tHola!, " << variable_global << endl
         << "  FINAL funcion 'saludar()'" << endl;
}

void saludarConParametros(string variable_local) // Parametros, tambien son LOCALES a la funcion
{
    // Scope LOCAL
    string otra_variable_local = "Soy una variable local en 'saludarConParametros(string variable_local)'";

    cout << "  INICIO funcion 'saludarConParametros(string variable_local)':" << endl
         << "\tHola!, " << variable_local << endl
         << "\tHola!, " << otra_variable_local << endl
         << "\tHola!, " << variable_global << endl
         << "  FINAL funcion 'saludarConParametros(string variable_local)'" << endl;
}