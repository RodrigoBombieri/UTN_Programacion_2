#ifndef FGLOBALES_H_INCLUDED
#define FGLOBALES_H_INCLUDED

#include <string.h>
#include "Empresa.h"


void cargarCadena(char *palabra, int tam){
    int i = 0;
    fflush(stdin);
    for (i = 0 ; i < tam ; i++ ){
        palabra[i] = cin.get();
        if(palabra[i] == '\n') break;
    }
    palabra[i] = '\0';
    fflush(stdin);
}

void mostrarMenu()
{
cout << "**********************************" << endl;
cout << "************** MENU **************" << endl;
cout << "1 - Cargar un registro" << endl;
cout << "2 - Mostrar Registros" << endl;
cout << "3 - Cargar varios registros" << endl;

cout << "**********************************" << endl;
cout << "5 - Punto A: " << endl;
cout << "6 - Punto B: " << endl;
cout << "7 - Punto C: " << endl;
cout << "**********************************" << endl;
cout << "0 - Salir " << endl;
cout << endl << endl;
}

/*
/// PUNTO A
void cantidadDeEmpresasPorMunicipio(Empresa *empresas){
    int vCon[5]={};
    for(int i=0; i<5; i++){
        if(empresas[i].getEstado()==true){
            vCon[i]++;
        }
    }

    for(int i=0; i<5; i++){
        cout << "El municipio: " << empresas[i].getNumMunicipio() << ", tiene: " << vCon[i] << " empresas." << endl;
    }
}
*/



#endif // FGLOBALES_H_INCLUDED
