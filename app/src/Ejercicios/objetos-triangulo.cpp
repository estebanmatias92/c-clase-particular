#include <iostream>
using namespace std;

class Triangulo
{
private:
    int lado1;
    int lado2;
    int lado3;

public:
    Triangulo(int l1, int l2, int l3);
    bool esEscaleno();
    bool esIsosceles();
    bool esEquilatero();
    bool tieneAnguloRecto();
};

Triangulo::Triangulo(int l1, int l2, int l3)
{
    lado1 = l1;
    lado2 = l2;
    lado3 = l3;
};

bool Triangulo::esEscaleno()
{
    if (lado1 != lado2 && lado2 != lado3 && lado3 != lado1)
    {
        return true;
    }
    else
    {
        return false;
    }
};

bool Triangulo::esIsosceles()
{
    if (lado1 == lado2 && lado2 == lado3 && lado3 == lado2)
    {
        return false;
    }
    else
    {
        if (lado1 == lado2 || lado2 == lado3 || lado3 == lado1)
        {
            return true;
        }
    }
    return false;
};

bool Triangulo::esEquilatero()
{
    if (lado1 == lado2 && lado2 == lado3 && lado3 == lado2)
    {
        return true;
    }
    return false;
};

void ejercicioObjetosTriangulo()
{
    int l1 = 300, l2 = 120, l3 = 100;
    cout << "Datos-" << endl
         << "Lado1=" << l1 << endl
         << "Lado2=" << l2 << endl
         << "Lado3=" << l3;
    cout << endl
         << "1=verdadero" << endl
         << "0=falso" << endl;

    Triangulo Datos(l1, l2, l3);

    cout << "Equilatero: " << Datos.esEquilatero() << endl; // asi tampoco funciona no
    cout << "Escaleno: " << Datos.esEscaleno() << endl;
    cout << "Isosceles: " << Datos.esIsosceles() << endl;
}