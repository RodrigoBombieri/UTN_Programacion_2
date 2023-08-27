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
    setNombre({});
    setApellido({});
    setTelefono(0);
    setEmail({});
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
    //cout << fecha << endl;

}


void mostrarMenu(){
    cout << "--------------------- MENU ----------------------------" << endl;
    cout << "-------------------------------------------------------" << endl;
    cout << "1 - PUNTO A -------------------------------------------" << endl;
    cout << "2 - PUNTO B -------------------------------------------" << endl;
    cout << "3 - PUNTO C -------------------------------------------" << endl;
    cout << "4 - PUNTO D -------------------------------------------" << endl;
    cout << "5 - PUNTO E -------------------------------------------" << endl;
    cout << "6 - PUNTO F -------------------------------------------" << endl;
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
    for(i=0; i<tam;i++){
        if(f > c[i].getFechaNacimiento()){
            con++;
        }
    }
    cout << "La cantidad de clientes con Fecha de nacimiento anterior a " << f << ", es de: " << con << endl;
}

#endif // CLIENTE_H_INCLUDED
