#include <iostream>

using namespace std;

#include "inmueble.h"

int main()
{
    //Direccion domicilio1;
    Inmueble inmueble1;
    Departamento depto1;
    Terreno terreno1;

    //inmueble1.Cargar();
    //inmueble1.Mostrar();

    //depto1.Cargar();
    //depto1.Mostrar();

    terreno1.Cargar();
    terreno1.Mostrar();

    cout << "Hello world!" << endl;
    return 0;
}
