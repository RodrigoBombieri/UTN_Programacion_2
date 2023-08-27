#include <iostream>
#include "fecha.h"
#include "Cliente.h"

using namespace std;

int main()
{
    Fecha fechaRef;
    bool corte = true;
    int opcion, dniReferenciaPuntoD, dniReferenciaPuntoE;
    Cliente vCliente1[10];

   while(corte==true){
    mostrarMenu();
    cout << "Elija una opcion: ";
    cin >> opcion;
    switch(opcion){
    case 1:  /// Punto a
        cargarCliente(vCliente1,1);
        break;
    case 2:/// Punto b
        mostrarCliente(vCliente1,1);
        break;
    case 3:
        /// Punto c
        dniMayorAReferencia(vCliente1,1);
        break;
    case 4:
        cout << "Ingrese un dni de referencia: ";
        cin >> dniReferenciaPuntoD;
        /// Punto d
        posicionDniReferencia(vCliente1, 1,dniReferenciaPuntoD);
        break;
    case 5:
        cout << "Ingrese un dni de referencia: ";
        cin >> dniReferenciaPuntoE;
        /// Punto e
        posicionObjetoDniReferencia(vCliente1, 1,dniReferenciaPuntoE);
        break;
    case 6:
        /// Punto f
        cout << "Ingrese una fecha de referencia: ";
        fechaRef.Cargar();
        fechaNacimientoAnteriorReferencia(vCliente1, 1, fechaRef);
        break;
    case 0: corte = false;
        break;

    }


   }




    return 0;
}
