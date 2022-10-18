#include <iostream>
#include <vector>
//#include <string>
#include "ejercicios.hpp"

using namespace std;

void passByValue(vector<int> lista);
void passByReference(vector<int> &lista);
void passAsPointer(vector<int> *lista);

void ejemploPointers()
{
    cout << endl
         << "Punteros, referencia y de-referencia: " << endl
         << endl;
    /*
    char x = 'a';
    char *ptr_x = &x;
    cout << "Value of x: " << x << endl;
    cout << "Address of x: " << ptr_x << endl;
    printf("Address of x: %p \n", ptr_x);

    cout << endl;

    int y{5};
    int *ptr_y = &y;
    cout << "Value of y: " << y << endl;
    cout << "Reference (Address) of y: " << &y << endl;
    printf("Reference (Address) of y: %p \n", ptr_y);
    cout << "De-reference the reference of y: " << *(&y) << endl;

    cout << endl;
    */
    vector<int> lista_num{82, 35, 48, 99};
    vector<int> &lista_ref = lista_num;
    vector<int> *lista_ptr = &lista_num;
    lista_ref[0] = 49;
    (*lista_ptr)[0] = 51;

    cout << endl
         << "lista_num" << endl
         //<< "  Value: \t\t\t" << lista_num.data() << endl
         << "  Address: \t\t\t" << &lista_num << endl
         << "  Value at [0]: \t\t" << lista_num[0] << endl
         << "  Address of array at [0]:\t" << &lista_num[0] << endl;
    cout << endl
         << "lista_ref" << endl
         //<< "  Value: \t\t\t" << lista_ref.data() << endl
         << "  Address: \t\t\t" << &lista_ref << endl
         << "  Value at [0]: \t\t" << lista_ref[0] << endl
         << "  Address of array at [0]:\t" << &lista_ref[0] << endl;
    cout << endl
         << "lista_ptr" << endl
         << "  Value: \t\t\t" << lista_ptr << endl
         << "  Address: \t\t\t" << &lista_ptr << endl
         << "  Value at [0]: \t\t" << lista_ptr->at(0) << endl
         << "  Address of array at [0]:\t" << &lista_ptr->at(0) << endl;

    cout
        << endl;
    /*
    int lista_num_2[]{82, 35, 48, 99};
    int *lista_ref_2 = lista_num_2;
    lista_ref_2[0] = 51;
    cout << "lista_num_2" << endl
         << "\tValue: " << *(lista_num_2 + 0) << endl
         << "\tAddress: " << &lista_num_2 << endl;
    cout << "lista_ref_2" << endl
         << "\tValue: " << lista_ref_2[0] << endl
         << "\tAddress: " << lista_ref_2 << endl;
    */
}

void passByValue(vector<int> lista)
{
    cout << "Vector Passed By Value:" << endl
         << "\tValue: " << lista[0] << endl
         << "\tAddress: " << &lista << endl;
}

void passByReference(vector<int> &lista)
{
    cout << "Vector Passed By Reference:" << endl
         << "\tValue: " << lista[0] << endl
         << "\tAddress: " << &lista << endl;
}

void passAsPointer(vector<int> *lista)
{
    cout << "Vector Passed By Reference as a Pointer:" << endl
         << "\tValue: " << lista->at(0) << endl
         << "\tAddress: " << &lista << endl;
}