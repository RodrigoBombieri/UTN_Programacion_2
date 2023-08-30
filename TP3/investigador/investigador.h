#ifndef INVESTIGADOR_H_INCLUDED
#define INVESTIGADOR_H_INCLUDED
#include <iostream>
#include <string.h>

using namespace std;

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



class Fecha{
    private:
        int dia, mes, anio;
    public:
        void Cargar(){
            cout<<"DIA: ";
            cin>>dia;
            cout<<"MES: ";
            cin>>mes;
            cout<<"ANIO: ";
            cin>>anio;
        }
        void Mostrar(){
            cout<<"DIA: "<<dia<<endl;
            cout<<"MES: "<<mes<<endl;
            cout<<"ANIO: "<<anio<<endl;
        }
        void mostrarEnLinea(){
            cout<<dia<<"/"<<mes<<"/"<<anio<<endl;
        }

        void setDia(int d){
            if(d>=1 && d<=31) dia=d;
            else dia=-1;
        }
        void setMes(int m){
            if(m>=1 && m<=12) mes=m;
            else mes=-1;
        }
        void setAnio(int a){
            if(a>=1 && a<=31) anio=a;
            else anio=-1;
        }
        int getDia(){return dia;}
        int getMes(){return mes;}
        int getAnio(){return anio;}
};

class Investigador{
private:
    char _dni[10], _nombre[30], _apellido[30];
    Fecha _fechaNacimiento;
    int _unidadAcademica, _categoria, _especialidad;
public:
    void Cargar();
    void Mostrar();

    void setDni(const char *d){strcpy(_dni, d);}
    void setNombre(const char *n){strcpy(_nombre, n);}
    void setApellido(const char *a){strcpy(_apellido, a);}
    void setUnidadAcademica(int uni){_unidadAcademica = uni;}
    void setCategoria(int cat){_categoria = cat;}
    void setEspecialidad(int esp){_especialidad = esp;}

    const char *getDni(){return _dni;}
    const char *getNombre(){return _nombre;}
    const char *getApellido(){return _apellido;}
    int getUnidadAcademica(){return _unidadAcademica;}
    int getCategoria(){return _categoria;}
    int getEspecialidad(){return _especialidad;}


    Investigador();



};

Investigador::Investigador(){
    setDni(strcpy(_dni, ""));
    setNombre(strcpy(_nombre, ""));
    setApellido(strcpy(_apellido, ""));
    setUnidadAcademica(0);
    setCategoria(0);
    setEspecialidad(0);
    _fechaNacimiento.setDia(1);
    _fechaNacimiento.setMes(1);
    _fechaNacimiento.setAnio(1900);

}

void Investigador::Cargar(){
    cout << "Ingrese DNI: ";
    cargarCadena(_dni, 9);
    cout << "Ingrese Nombre: ";
    cargarCadena(_nombre, 9);
    cout << "Ingrese Apellido: ";
    cargarCadena(_apellido, 9);
    cout << "Ingrese Unidad academica (1 al 30): ";
    cin >> _unidadAcademica;
    cout << "Ingrese Categoria (1 al 5): ";
    cin >> _categoria;
    cout << "Ingrese Especialidad (1 al 10): ";
    cin >> _especialidad;
    _fechaNacimiento.Cargar();
    cout << endl;
}


void Investigador::Mostrar(){
    cout << "Dni: ";
    cout << _dni << endl;
    cout << "Nombre: ";
    cout << _nombre << endl;
    cout << "Apellido: ";
    cout << _apellido << endl;
    cout << "Unidad academica: ";
    cout << _unidadAcademica << endl;
    cout << "Categoria: ";
    cout << _categoria << endl;
    cout << "Especialidad: ";
    cout << _especialidad << endl;
    cout << "Fecha de Nacimiento: ";
    _fechaNacimiento.mostrarEnLinea();
    cout << endl;
}

#endif // INVESTIGADOR_H_INCLUDED
