#include <iostream>
#include <string>
#include "caesar-cipher.hpp"

using namespace std;

int main()
{
    string msg = "\nHello World!!!\n";

    cout << msg;
    cout << caesarCipher(msg) << endl;

    return 0;
}