#include <iostream>

using namespace std;

#include "misiones.h"

int main()
{
    Mision mision1;

    mision1.Cargar();
    mision1.Mostrar();

    cout << "Feliz Mision!" << endl;
    return 0;
}
