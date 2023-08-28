#ifndef EMPLEADOS_H_INCLUDED
#define EMPLEADOS_H_INCLUDED
#include <string.h>
#include <iostream>

using namespace std;

class Empleado{
private:
    int _dni, _cargo, _dia, _mes, _anio;
    char _nombre[30], _apellido[30], _domicilio[30], _email[30];
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

    void setDomicilio(char *domicilio){
        strcpy(_domicilio, domicilio);
    }

    void setEmail(char *email){
        strcpy(_email, email);
    }

    void setDia(int dia){
        _dia = dia;
    }

    void setMes(int mes){
        _mes = mes;
    }

    void setAnio(int anio){
        _anio = anio;
    }

    void setCargo(int cargo){
        _cargo = cargo;
    }

    char getNombre(){return *_nombre;};
    int getDni(){return _dni;};
    char getApellido(){return *_apellido;};
    char getDomicilio(){return *_domicilio;};
    char getEmail(){return *_email;};
    int getDia(){return _dia;};
    int getMes(){return _mes;};
    int getAnio(){return _anio;};
    int getCargo(){return _cargo;};

    Empleado();

};


Empleado::Empleado(){
    setDni(0);
    setNombre(strcpy(_nombre, ""));
    setApellido(strcpy(_apellido, ""));
    setDomicilio(strcpy(_domicilio, ""));
    setEmail(strcpy(_email, ""));
    setDia(1);
    setMes(1);
    setAnio(1900);
    setCargo(0);

}

void Empleado::Cargar(){
    int doc, cargo, d, m, a;
    char nomb[20], ape[20], domi[20], mail[20];
    cout << "Ingrese su DNI: ";
    cin >> doc;
    setDni(doc);
    cout << "Ingrese su nombre: ";
    cin >> nomb;
    setNombre(nomb);
    cout << "Ingrese su apellido: ";
    cin >> ape;
    setApellido(ape);
    cout << "Ingrese su domicilio: ";
    cin >> domi;
    setDomicilio(domi);
    cout << "Ingrese su email: ";
    cin >> mail;
    setEmail(mail);
    cout << "Ingrese su dia de nacimiento: ";
    cin >> d;
    setDia(d);
    cout << "Ingrese su mes de nacimiento: ";
    cin >> m;
    setMes(m);
    cout << "Ingrese su dia de nacimiento: ";
    cin >> a;
    setAnio(a);
    cout << "Ingrese su cargo: ";
    cin >> cargo;
    setCargo(cargo);

}

void Empleado::Mostrar(){
    cout << "DNI: " <<getDni() << endl;
    cout << "NOMBRE: " <<_nombre << endl;
    cout << "APELLIDO: " <<_apellido << endl;
    cout << "DOMICILIO: " <<_domicilio << endl;
    cout << "EMAIL: " <<_email << endl;
    cout << "DIA: " <<getDia() << endl;
    cout << "MES: " <<getMes() << endl;
    cout << "ANIO: " <<getAnio() << endl;
    cout << "CARGO: " <<getCargo() << endl;

}

void mostrarMenu(){
cout << " ---------------------- M E N U ----------------------" << endl;
cout << " -----------------------------------------------------" << endl;
cout << " 1 - CARGAR EMPLEADO - - - - - - ---------------------" << endl;
cout << " 2 - MOSTRAR EMPLEADO - - - - - - --------------------" << endl;
cout << " -----------------------------------------------------" << endl;
cout << " 0 - SALIR- - - - - - - - - - - ----------------------" << endl;


}

void cargarEmpleado(Empleado *e, int tam){
    int i;
    for(i=0; i<tam; i++){
        e[i].Cargar();
    }
}

void mostrarEmpleado(Empleado *e, int tam){
    int i;
    for(i=0; i<tam; i++){
        e[i].Mostrar();
        cout << endl;
    }
}

#endif // EMPLEADOS_H_INCLUDED
