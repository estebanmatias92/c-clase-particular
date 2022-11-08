#include <iostream>
#include <vector>

using namespace std;

class Persona
{
private:
    int dni;
    int edad;
    float peso;   // La unica forma en que la ecuación de bien, es que la altura
    float altura; // y el peso sean decimales, sobretodo la altura, ingresarla en metros con centrimetros
    string nombre;

public:
    void pesoedad();
    void edadd();
    Persona(int dni, int edad, float peso, float altura, string nombre)
    {
        this->dni = dni;
        this->edad = edad;
        this->peso = peso;
        this->altura = altura;
        this->nombre = nombre;
    }
};

void Persona::pesoedad()
{
    float balance_peso_altura = peso / (altura * altura); // Mejor es hacer la ecuación una sola vez y guardar el resultado
    // Queremos el resultado tambien en decimal, para saber el numero exacto no redondeado
    // Luego comparar ese resultado las veces que necesitemos

    cout << endl
         << "Balance peso/altura: " << balance_peso_altura;

    cout << endl
         << "Peso ideal: "; // Cambio estético

    if (balance_peso_altura <= 20) // Si es menor o igual a 20
        cout << "-1";
    else if ((balance_peso_altura > 20) && (balance_peso_altura <= 25)) // Mayor a 20 y menor o igual a 25
        cout << "0";
    else // Por defecto si todo lo menor a 20 y entre 20 y 25 ya está contemplado, queda todo lo mayor a 25
        cout << "1";

    cout << endl; // Estetica
}

void Persona::edadd()
{
    bool es_mayor = (edad >= 18);
    // Esta expresion "(edad >= 18)" va a evualuar true o false, y eso va a ser guardado,
    // no hace falta todo el if-else, es lo mismo pero mas corto

    cout << endl
         << "Edad: " << edad;
    cout << endl
         << "¿Mayor edad?: " << es_mayor << endl; // Estetica y practicidad
}

void ejercicioObjetosPersona()
{
    int dni;
    int edad;
    float peso;
    float altura;
    string nombre;

    cout << "Ingrese su nombre: ";
    getline(cin, nombre);
    system("clear");

    cout << "Ingrese dni: ";
    cin >> dni;
    system("clear");

    cout << "Ingrese edad: ";
    cin >> edad;
    system("clear");

    cout << "Ingrese altura en metros: ";
    cin >> altura;
    system("clear");

    cout << "Ingrese peso en kg: ";
    cin >> peso;
    system("clear");

    Persona ga(dni, edad, peso, altura, nombre);
    ga.pesoedad();
    ga.edadd();
}