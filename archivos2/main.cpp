#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

#include "prototipos.h"
#include "clsFecha.h"
#include "personaAlumno.h"
#include "clsArchivoAlumnos.h"
#include "archivo2.h"

int main(){
    int opc;
    bool corte = true;

    while(corte==true){
        system("cls");
        mostrarMenu();
        cout << "Ingrese una opcion: ";
        cin >> opc;
        switch(opc){
        case 1: if(cargarRegistro()) cout << "registro agregado" << endl;
                else cout << "No se pudo agregar registro." << endl;
            break;
        case 2: if(!bajaLogicaRegistro()) cout << "Error al dar de baja el registro." << endl;
                else {
                        cout << "Registro dado de baja." << endl;
                }
            break;
        case 3: if(!mostrarRegistro()) cout << "Error al leer archivo de alumnos." << endl;
            break;
        case 0:
            corte=false;
            break;
        }
        system("pause");
    }

	system("pause");
	return 0;
}
