#include <iostream>
#include "empleados.h"

using namespace std;

int main()
{
    int opcion;
    bool corte=true;
    Empleado empleado1[5];

    while(corte==true){
        mostrarMenu();
        cout << "Elija una opcion: ";
        cin >> opcion;
        switch(opcion){
        case 1:
            cargarEmpleado(empleado1, 1);
            break;
        case 2:
            mostrarEmpleado(empleado1, 1);
            break;
        case 0:
            corte = false;
            break;


        }


    }

    return 0;
}
