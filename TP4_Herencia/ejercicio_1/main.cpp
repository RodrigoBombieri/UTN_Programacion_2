#include <iostream>

using namespace std;

#include "Persona.h"

int main()
{
    Persona p1;
    Empleado empleado1;

    empleado1.Cargar();
    empleado1.Mostrar();
    p1.Mostrar();

    cout << "Hello world!" << endl;
    return 0;
}
