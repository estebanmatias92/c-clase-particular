#include <iostream>
#include <vector> // Faltaba agregar la cabecera del vector
using namespace std;

class Num
{
    // Todo lo que se declare en la clase, va a estar disponible durante toda la vida del objeto y para todos los metodos
private:
    int num1; // Propiedad "num1"
    int num2;
    int num3;
    vector<float> numeros; // Me parecio mas comodo declarar y luego rellenar en el constructor, una sola vez el vector para luego poder usarlo en todas las operaciones

public:
    Num(int n1, int n2, int n3); // Metodo constructor. Es "case sensitive", asi que debe llevar examente las mismas "minusculas y mayusculas" que la clase, para que funcione
    float max();                 // Metodo "max()"
    float min();                 // Metodo "min()"
    float prom();                // Metodo "prom()"
    vector<float> par();         // Metodo "par()"
    vector<float> impar();       // Metodo "impar()"
    vector<float> todo();        // Metodo "todo()"
};

// Constructor
// Esta "operacion" es llamada primero en todo el ciclo de vida del objeto y nos sirve para rellnear con datos nuestro objeto a usar
Num::Num(int n1, int n2, int n3)
{
    num1 = n1; // Asignando el valor que me pasen por argumento (linea 91: "Num ejemplo(4, 10, 1);"), a mi propidad "num1"
    num2 = n2; // Asignando n2 a propiedad num3
    num3 = n3; // ...
    // Ahora las propiedades "num1", "num2" y "num3" van a disponer de datos nuevos para ser accedidos por todo el objeto

    // Estas lineas son para rellenar el vector cuando se crea el objeto
    // Directamente se puede hacer numeros.push_back(n1); y eliminar las 3 lineas de arriba
    // Creando el vector acá, en el constructor, va a estar disponible desde el inicio para todo el objeto y todas las operaciones
    numeros.push_back(num1);
    numeros.push_back(num2);
    numeros.push_back(num3);
    // Ahora la propiedad "numeros" va a disponer de datos nuevos para ser accedidos por todo el objeto
}

// Operacion Maximo
float Num::max() // Habia que especificar el tipo de dato que devuelve cada operacion, en este caso "float"
{
    // Esta operacion pareciera estar usando la variable "numeros" de la nada.
    // En realidad, "numeros" es el vector ya definido (linea 11) cuando definimos clase y ya fue rellenado cuando definimos el constructor
    // El resto son todas variables locales a esta operacion, mientras que el vector es global para todo el objeto
    int size = numeros.size();

    float max = numeros[0]; // Maximo no sabemos que numero puede ser, lo inicializamos con el primer valor del vector

    for (int i = 0; i < size; i++)
    {
        if (numeros[i] > max)
            max = numeros[i]; // Operacion tipica de maximo, si es mayor, lo asigna
    }

    return max; // Retornar lo que haya quedado como maximo
}

// Falta definir el resto de operaciones
// min()
// prom()
// par()
// impar()
// todo()

// Operacion minimo
// ,,,

// Operacion promedio
// ,,,

// Operacion par
// ,,,

// Operacion impar
// ,,,

// Operacion todo
// ,,,

void ejemplo_ObjetosCNumber()
{
    // preparacion de variables locales en main(), donde guardar los datos que devuelvan las operaciones (o "metodos") del objeto
    float maximo, minimo, promedio;
    vector<float> pares, impares, todos;

    // Aca empieza la vida del objeto que vamos a usar, acá se está llamando al constructor
    // y los datos va a ser guardados en nuestras propiedades de clase (num1, num2, num3, numeros)
    Num ejemplo(4, 10, 1); // Crear el objeto e inicializarlo con datos

    // maximo = ejemplo.max(4, 10, 1); Una vez que los datos fueron tomados en el
    // momento de inicializacion (osea, en el constructor), no es necesario volver a pasarle
    // los mismos datos a cada operacion, pues ya los tiene disponibles cuando asignamos "num1 = n1" en el constructor
    maximo = ejemplo.max();                // Llamar a la primera operación del objeto y guardar el valor de retorno
    cout << "Maximo = " << maximo << endl; // Mostrar lo guardado del retorno

    // Como el resto de las operaciones faltaban, al llamarlas de todas formas,
    // el programa no las reconocia, solo estaban declaradas en la clase, pero no definidas como max()
    /*
    minimo = ejemplo.min();
    cout << "Minimo = " << minimo  << endl;

    promedio = ejemplo.prom();
    cout << "Promedio = " << promedio  << endl;



    // Los metodos "par()", "impar()" y "todos()", parece que devuelven conjuntos (vectores en este caso),
    // por lo que habria que usar un bucle para mostrar cada elemento en cada caso

    pares = ejemplo.par();
    cout << "Pares = ";
    for (size_t i = 0; i < pares.size(); i++)
        cout << pares[i] << " ";

    cout << endl;

    impares = ejemplo.impar();
    // Faltaba mostrar los impares
    cout << "Impares = ";
    for (size_t i = 0; i < impares.size(); i++)
        cout << impares[i] << " ";

    cout << endl;

    todos = ejemplo.todo(); // faltaba también llamar a al metodo "todo()"
    cout << "Todos = ";
    for (size_t i = 0; i < todos.size(); i++)
        cout << todos[i] << " ";

    cout << endl;
    */
}
