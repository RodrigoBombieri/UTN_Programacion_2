#include <iostream>

using namespace std;

#include "animales.h"

int main()
{
    Animal perro;
    Pez _pescado;
    Anfibio _ranita;
    Marino _marino;

    _marino.Cargar();
    _marino.Mostrar();

    //_pescado.Cargar();
    //_pescado.Mostrar();

    cout << "Hello world!" << endl;
    return 0;
}
