#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED
#include <string.h>
#include <iostream>

using namespace std;


class Fecha{
    private:
        int _dia, _mes, _anio;
    public:
        void Cargar();
        void Mostrar();

        void setDia(int dia){
            _dia = dia;
        }

        void setMes(int mes){
            _mes = mes;
        }

        void setAnio(int anio){
            _anio = anio;
        }

        int getDia(){return _dia;}
        int getMes(){return _mes;}
        int getAnio(){return _anio;}

        Fecha();

};

Fecha::Fecha(){
    setDia(1);
    setMes(1);
    setAnio(1900);
}

void Fecha::Cargar(){
    int d, m, a;
    cout << "Ingrese el dia: ";
    cin >> d;
    setDia(d);
    cout << "Ingrese el mes: ";
    cin >> m;
    setMes(m);
    cout << "Ingrese el anio: ";
    cin >> a;
    setAnio(a);

}

void Fecha::Mostrar(){
    cout << _dia << " / " << _mes << " / " << _anio << endl;
}




#endif // FECHA_H_INCLUDED
