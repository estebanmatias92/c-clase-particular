#include <iostream>
#include <string>
using namespace std;

class PlanoAuto
{
private:
    string estado = "apagado";
    int velocidad_maxima;
    string direccion;

public:
    string color;
    string marca;
    string modelo;
    int año;

public:
    PlanoAuto(string color, string marca, string modelo, int año)
    {
        this->color = color;
        this->marca = marca;
        this->modelo = modelo;
        this->año = año;
    }
    string encender();
    void acelerar(string dirección, int velocidad);
};

void ejercicioObjetosNuevo()
{
    cout << endl
         << "Este es un nuevo ejercicio de objetos!" << endl
         << endl;

    PlanoAuto nuevo_auto = PlanoAuto("Negro", "AMC", "Rambler", 1965);

    cout << "Detalles auto" << endl
         << "Color: " << nuevo_auto.color << endl
         << "Marca: " << nuevo_auto.marca << endl
         << "Modelo: " << nuevo_auto.modelo << endl
         << "Año: " << nuevo_auto.año << endl
         << endl;
}