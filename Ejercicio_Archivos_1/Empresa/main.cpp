#include <iostream>

using namespace std;
#include "Empresa.h"

int main()
{
    Empresa empresa1, empresas[5];

    int opcion;
    bool corte=true;

    while(corte==true){
        mostrarMenu();
        cout << "Elija una opcion: ";
        cin >> opcion;
        cout << endl << endl;

        switch(opcion){
        case 1:
            cargarUnRegistro();
            break;
        case 2:
            mostrarUnRegistro();
            break;
        case 3:
            cargarVariosRegistros(empresas);
            break;
        case 4:
            mostrarVariosRegistros(empresas);
            break;
        case 0:
            corte =false;
            break;
        }

    }



    cout << "Hello world!" << endl;
    return 0;
}
