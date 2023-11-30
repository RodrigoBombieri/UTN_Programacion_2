///Ejercicio: Recuperatorio Parcial 2 de Programación II - UTN
///Autor: Rodrigo Sebastián Bombieri
///Fecha: 13/11/2023


#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>

using namespace std;

#include "parcial2.h"


void punto1();
void punto2();

int main()
{

    punto1();
    punto2();

    return 0;
}

class sociosMasDeDosTurnos{
private:
    char codigoSocio[5];
    char nombre[30];
    float importeTotal;
public:
    sociosMasDeDosTurnos(const char* codigo = "vacio", const char* nombre = "vacio", float importe = 0.0) {
        strcpy(this->codigoSocio, codigo);
        strcpy(this->nombre, nombre);
        this->importeTotal = importe;
    }

    void setCodigoSocio(const char *cs){strcpy(codigoSocio,cs);}
    void setNombre(const char *n){strcpy(nombre,n);}
    void setImporte(float im){importeTotal=im;}
    const char *getCodigoSocio(){return codigoSocio;}
    const char *getNombre(){return nombre;}
    float getImporteTotal(){return importeTotal;}

};


class ArchivoSociosMasDeDosTurnos{
private:
    char nombre[30];
public:
    ArchivoSociosMasDeDosTurnos(const char *n){
        strcpy(nombre, n);
    }
    sociosMasDeDosTurnos leerRegistro(int pos){
        sociosMasDeDosTurnos reg;
        FILE *p;
        p=fopen(nombre, "rb");
        if(p==NULL) return reg;
        fseek(p, sizeof reg*pos,0);
        fread(&reg, sizeof reg,1, p);
        fclose(p);
        return reg;
    }
    int contarRegistros(){
        FILE *p;
        p=fopen(nombre, "rb");
        if(p==NULL) return -1;
        fseek(p, 0,2);
        int tam=ftell(p);
        fclose(p);
        return tam/sizeof(sociosMasDeDosTurnos);
    }
    bool grabarRegistro(sociosMasDeDosTurnos reg){
        FILE *p;
        p=fopen(nombre, "ab");
        if(p==NULL) return false;
        bool escribio=fwrite(&reg, sizeof reg,1, p);
        fclose(p);
        return escribio;
    }

};


void punto1(){
    Socio soci;
    ArchivoSocios archiSocio("socios.dat");
    int cantSocios = archiSocio.contarRegistros();

    Turno tur;
    ArchivoTurnos archiTurno("turnos.dat");
    int cantTurnos = archiTurno.contarRegistros();


    sociosMasDeDosTurnos aux;
    ArchivoSociosMasDeDosTurnos archiAux("masDeDosTurnos.dat");

    for(int i=0; i<cantSocios; i++){
        soci = archiSocio.leerRegistro(i);

        int conTurnos=0;
        float importeTotal=0;

        for(int j=0; j<cantTurnos; j++){
            tur = archiTurno.leerRegistro(j);

            if(strcmp(soci.getCodigoSocio(), tur.getCodigoSocio()) == 0 && soci.getEstado()==true && tur.getEstado() == true){
                conTurnos++;
                importeTotal += tur.getImporte();

            }
        }

        if(conTurnos>=2){
            aux.setCodigoSocio(soci.getCodigoSocio());
            aux.setNombre(soci.getNombre());
            aux.setImporte(importeTotal);

            if(archiAux.grabarRegistro(aux)==false){
                cout << "Error en la creacion del nuevo archivo " <<endl;
                return;
            }


        }
    }

            int cantSociosDosTurnos = archiAux.contarRegistros();
            for (int i=0; i<cantSociosDosTurnos; i++) {
                sociosMasDeDosTurnos aux = archiAux.leerRegistro(i);
                cout << "Código: " << aux.getCodigoSocio() << ", Nombre: " << aux.getNombre() << ", Importe Total: " << aux.getImporteTotal() << endl;
            }

}

void punto2() {
    int anio;
    cout << "Ingrese el año para buscar socios inscritos: ";
    cin >> anio;

    Socio soci;
    ArchivoSocios archiSocio("socios.dat");
    int cantSocios = archiSocio.contarRegistros();

    Socio* sociosInscritos = new Socio[cantSocios];
    int cantSociosInscritos = 0;

    for (int i = 0; i < cantSocios; i++) {
        soci = archiSocio.leerRegistro(i);

        if (soci.getInscripcion().getAnio() == anio) {
            sociosInscritos[cantSociosInscritos] = soci;
            cantSociosInscritos++;
        }
    }


    cout << "Socios inscritos en el año " << anio << ":" << endl;
    for (int i = 0; i < cantSociosInscritos; i++) {
        cout << "Código: " << sociosInscritos[i].getCodigoSocio() << ", Nombre: " << sociosInscritos[i].getNombre() << endl;
    }

    delete[] sociosInscritos;
}


