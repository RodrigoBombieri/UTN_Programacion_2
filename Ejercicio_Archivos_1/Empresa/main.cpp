#include <iostream>
#include <string.h>
#include <cstring>

using namespace std;
#include "Municipios.h"
#include "Empresa.h"
#include "ArchivoEmpresa.h"
#include "fGlobales.h"

int main()
{
    int opcion, opcSubMenu;
    bool corte=true, corteSubMenu=true;
    int numEmpresa;
    Empresa e;
    Empresa vE[5];



    while(corte==true){
        system("cls");
        corteSubMenu=true;
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
        case 2:if(bajaLogicaUnRegistro())cout << "Baja logica correcta."<< endl;
                else{
                    cout << "Error en la baja logica."<< endl;
                }

            break;
        case 3: if(modificarCategoriaEmpresa())cout << "Registro modificado correctamente."<<endl;
                else{
                    cout << "Error en la modificacion del registro."<<endl;
                }
            break;
        case 4: {

            while(corteSubMenu==true){
                system("cls");
                subMenuListar();
                cout << "Elija una opcion: ";
                cin >> opcSubMenu;
                cout << endl << endl;
                switch(opcSubMenu){

                case 1:if(!mostrarRegistros()){
                    cout << "No existe el archivo." << endl;
                    }
                    break;
                case 2:
                    cout << "Ingrese un numero de empresa para listar: "<<endl;
                    cin >> numEmpresa;
                    mostrarRegistrosFiltrados(numEmpresa);
                    break;
                case 0:
                    corteSubMenu=false;
                    break;
                }
            system("pause");
            }


        }
            break;
        case 5: cargarVariosRegistros(vE);
            break;
        case 6: cantidadDeEmpresasPorMunicipio();
            break;
        case 7: empresasConMasDe200Empleados();
            break;
        case 8: categoriaEmpresaConMasEmpleados();
            break;
        case 9: municipiosConMenosDe200MilHabitantes();
            break;
        case 10: seccionConMayorCantidadDeHabitantes();
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
