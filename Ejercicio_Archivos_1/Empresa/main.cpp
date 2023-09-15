#include <iostream>

using namespace std;
#include "Empresa.h"
#include "fGlobales.h"
#include "Archivos.h"

int main()
{
    int opcion;
    bool corte=true;

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
            cargarVariosRegistros();
            break;
        case 4:
            ///
            break;
        case 5:
            //cantidadDeEmpresasPorMunicipio(empresas);
            break;
        case 6:
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
