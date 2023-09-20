#include <iostream>

using namespace std;
#include "Empresa.h"
#include "Archivos.h"
#include "fGlobales.h"

int main()
{
    int opcion;
    bool corte=true;
    Empresa e;
    Empresa vE[5];


    while(corte==true){
        system("cls");
        mostrarMenu();
        cout << "Elija una opcion: ";
        cin >> opcion;
        cout << endl << endl;

        switch(opcion){
        case 1:
            if(cargarUnRegistro())cout << "Registro cargado correctamente."<< endl;
                else{
                    cout << "Error en carga de registro."<< endl;
                }
            break;
        case 2:
            if(!mostrarRegistros()){
                cout << "No existe el archivo." << endl;
            }
            break;
        case 3:
            cargarVariosRegistros(vE);
            break;
        case 4:
            cantidadDeEmpresasPorMunicipio();
            break;
        case 5:
            empresasConMasDe200Empleados();
            break;
        case 6:categoriaEmpresaConMasEmpleados();
            break;
        case 7:
            break;
        case 0:
            corte=false;
            break;
        }
        system("pause");

    }



    cout << "Hello world!" << endl;
    return 0;
}
