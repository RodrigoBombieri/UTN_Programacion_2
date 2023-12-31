#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED
#include <string.h>
#include "fecha.h"
#include <iostream>

using namespace std;



class Cliente{
    private:
        int _dni, _telefono;
        char _nombre[20], _apellido[20], _email[25];
        Fecha _fechaNacimiento;
    public:
        void Cargar();
        void Mostrar();

        void setDni(int dni){
            _dni = dni;
        }

        void setNombre(char *nombre){
            strcpy(_nombre, nombre);
        }

        void setApellido(char *apellido){
            strcpy(_apellido, apellido);
        }

        void setEmail(char *email){
            strcpy(_email, email);
        }

        void setTelefono(int telefono){
            _telefono = telefono;
        }

        void setFecha(Fecha fechaNacimiento){
            _fechaNacimiento = fechaNacimiento;
        }

        int getDni(){return _dni;}
        char getNombre(){return *_nombre;}
        char getApellido(){return *_apellido;}
        char getEmail(){return *_email;}
        int getTelefono(){return _telefono;}
        Fecha getFechaNacimiento(){return _fechaNacimiento;}


        /// Constructor con valores por omision
        Cliente();
        Cliente(char *nombre);

};

Cliente::Cliente(){
    setDni(0);
    setNombre(strcpy(_nombre, ""));
    setApellido(strcpy(_apellido, ""));
    setTelefono(0);
    setEmail(strcpy(_email, ""));
    _fechaNacimiento.setDia(0);
    _fechaNacimiento.setMes(0);
    _fechaNacimiento.setAnio(0);
}

Cliente::Cliente(char *nomb){
    strcpy(_nombre, nomb);
}

void Cliente::Cargar(){
    Fecha fechaNacimiento;
    int doc, telef, d, m, a;
    char nomb[20], apell[20], mail[30];
    cout << "Ingrese su DNI: ";
    cin >> doc;
    setDni(doc);
    cout << "Ingrese su nombre: ";
    cin >> nomb;
    setNombre(nomb);
    cout << "Ingrese su apellido: ";
    cin >> apell;
    setApellido(apell);
    cout << "Ingrese su telefono: ";
    cin >> telef;
    setTelefono(telef);
    cout << "Ingrese su email: ";
    cin >> mail;
    setEmail(mail);
    cout << "Ingrese su fecha de nacimiento: ";
    cin >> d >> m >> a;
    fechaNacimiento.setDia(d);
    fechaNacimiento.setMes(m);
    fechaNacimiento.setAnio(a);
}

void Cliente::Mostrar(){
    cout << _dni << endl;
    cout << _nombre << endl;
    cout << _apellido << endl;
    cout << _email << endl;
    cout << _telefono << endl;
    _fechaNacimiento.Mostrar();

}


void mostrarMenu(){
    cout << "--------------------- MENU ----------------------------" << endl;
    cout << "-------------------------------------------------------" << endl;
    cout << "1 - PUNTO A Cargar un vector de 10 clientes -----------" << endl;
    cout << "2 - PUNTO B Listar todos los clientes del vector ------" << endl;
    cout << "3 - PUNTO C Listar todos los clientes cuyo DNI sea mayor ";
    cout << " a un valor que se ingresa por teclado." << endl;
    cout << "4 - PUNTO D A partir de un valor de DNI recibido como par�metro,";
    cout << "devolver la posici�n del objeto que contiene ese DNI. De no encontrarlo devolver -1." << endl;
    cout << "5 - PUNTO E Igual a la funci�n del punto anterior,";
    cout << "pero debe devolver el objeto completo que contiene el DNI.";
    cout << "De no encontrar el c�digo la funci�n debe devolver un objeto Cliente con un valor de -1 en el DNI." << endl;
    cout << "6 - PUNTO F Dado una fecha que se recibe como par�metro";
    cout << " devolver la cantidad de clientes cuyo nacimiento sea anterior a ese valor recibido." << endl;
    cout << "-------------------------------------------------------" << endl;
    cout << "0 - SALIR ---------------------------------------------" << endl;
}



void cargarCliente(Cliente *c, int tam){
    int i;
    for(i=0; i<tam; i++){
        c[i].Cargar();
    }
}

void mostrarCliente(Cliente *c, int tam){
    int i;
    for(i=0; i<tam; i++){
        c[i].Mostrar();
        cout << endl;
    }
}


void dniMayorAReferencia(Cliente *c, int tam){
    int dniReferencia, i;
    cout << "Ingrese un DNI de referencia para listar los mayores: ";
    cin >> dniReferencia;

    for(i=0; i<tam; i++){
        if(dniReferencia > c[i].getDni()){
            c[i].Mostrar();
            cout << endl;
        }
    }
}


void posicionDniReferencia(Cliente *c, int tam, int dniRef){
    int i;
    for(i=0; i<tam; i++){
        if(dniRef == c[i].getDni()){
            cout << i << endl;
        }else{
            cout << "-1" << endl;
        }
    }
}

void posicionObjetoDniReferencia(Cliente *c, int tam, int dniRef){
    int i;
    for(i=0; i<tam; i++){
        if(dniRef == c[i].getDni()){
            c[i].Mostrar();
        }else{
            c[i].setDni(-1);
            c[i].Mostrar();
        }
    }
}


void fechaNacimientoAnteriorReferencia(Cliente *c, int tam, Fecha f){

    int i, con=0;
    cout << "Ingrese una fecha de referencia: ";
    f.Cargar();

    cout << "La fecha de referencia es: ";
    f.Mostrar();

    for(i=0; i<tam;i++){
        if(c[i].getFechaNacimiento() < f){
            con++;
        }
    }
    cout << "La cantidad de clientes con Fecha de nacimiento anterior a la fecha de referencia es de: " << con << endl;
}

#endif // CLIENTE_H_INCLUDED
