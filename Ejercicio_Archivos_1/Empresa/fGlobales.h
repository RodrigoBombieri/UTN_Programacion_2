#ifndef FGLOBALES_H_INCLUDED
#define FGLOBALES_H_INCLUDED

#include <string.h>
#include "Empresa.h"

void mostrarMenu()
{
cout << "**********************************" << endl;
cout << "************** MENU **************" << endl;
cout << "1 - Cargar un registro" << endl;
cout << "2 - Mostrar Registros" << endl;
cout << "3 - Cargar varios registros" << endl;
cout << "**********************************" << endl;
cout << "4 - Cantidad de empresas de cada municipio" << endl;
cout << "5 - Empresas con mas de 200 empleados: " << endl;
cout << "6 - Categoria de empresa con mas empleados: " << endl;
cout << "**********************************" << endl;
cout << "0 - Salir " << endl;
cout << endl << endl;
}

void cargarVectorEmpresa(Empresa *vReg, int cant){
    int i;
    for(i=0; i<5; i++){
        vReg[i].Cargar();
    }
}


bool cargarUnRegistro(){
    Empresa emp;
    bool escribio;
    FILE *pEmp;

    pEmp=fopen("Empresas.dat", "ab");
        if(pEmp==NULL){
            cout << "Error de archivo.";
            return false;
        }

    for(int i=0; i<1; i++){
        emp.Cargar();
        escribio=fwrite(&emp, sizeof(Empresa),1,pEmp);
        if(escribio==0){
            fclose(pEmp);
            return false;
        }
    }
    fclose(pEmp);
    return escribio;
    /*
    Empresa reg;
    ArchivoEmpresa archi("Empresa.dat");
    cout <<"Ingresar los valores del registro"<<endl;
    reg.Cargar();
    bool escribio= archi.grabarRegistro(reg);
    return escribio;
    */
}


bool cargarVariosRegistros(Empresa *vE){
    //Empresa vReg[5];
    bool escribio;
    FILE *pEmp;

    pEmp=fopen("Empresas.dat", "ab");
    if(pEmp==NULL){
        cout << "Error de archivo.";
        return false;
    }
    cargarVectorEmpresa(vE, 5);
    escribio=fwrite(vE, sizeof(Empresa),5,pEmp);
    fclose(pEmp);
    return escribio;
}


bool mostrarRegistros(){
    Empresa emp;
    FILE *pEmp;
    bool quePaso;

    pEmp=fopen("Empresas.dat", "rb");
        if(pEmp==NULL){
            cout << "Error de archivo.";
            return false;
        }
    while(quePaso=fread(&emp, sizeof(Empresa),1,pEmp)==1){
        emp.Mostrar();
        cout << endl;
    }
    fclose(pEmp);
    return quePaso;
   /*
    /// creo un objeto para que me maneje el archivo de empresas
    ArchivoEmpresa archi("Empresas.dat");
    bool quePaso = archi.listarRegistro();
    return quePaso;
    */
}

/// PUNTO A
void cantidadDeEmpresasPorMunicipio() {
    Empresa emp;
    const int numMunicipios = 135; // Suponemos que hay 135 municipios
    int vCon[numMunicipios] = {0}; // Inicializar el arreglo con ceros
    FILE *pEmp;

    pEmp=fopen("Empresas.dat", "rb");
        if(pEmp==NULL){
            cout << "Error de archivo.";
        }
    /// si lee y el registro da true
    while(fread(&emp, sizeof(Empresa),1,pEmp)==1){
        if (emp.getEstado() == true) {
            int numMunicipio = emp.getNumMunicipio();
            if (numMunicipio >= 1 && numMunicipio <= numMunicipios) {
                vCon[numMunicipio-1]++;
            }
        }
    }
    fclose(pEmp);

    for (int i = 0; i < 135; i++) {
        if(vCon[i]!=0){
            cout << "El municipio " << i + 1 << " tiene " << vCon[i] << " empresas." << endl;
        }
    }
}

/// PUNTO B

void empresasConMasDe200Empleados(){
    Empresa emp;
    FILE *pEmp;

    pEmp=fopen("Empresas.dat", "rb");
        if(pEmp==NULL){
            cout << "Error de archivo.";
        }
    cout << "Empresas con mas de 200 empleados: " << endl;
    while(fread(&emp, sizeof(Empresa),1,pEmp)==1){
        if(emp.getCantEmpleados()>200){
            cout << emp.getNombreEmpresa() << " tiene " <<emp.getCantEmpleados() << " empleados." <<endl;
        }
    }
    fclose(pEmp);

}

void categoriaEmpresaConMasEmpleados(){
    Empresa emp;
    FILE *pEmp;
    int bmax = 0, catMax, maxEmpleados=0;


    pEmp=fopen("Empresas.dat", "rb");
        if(pEmp==NULL){
            cout << "Error de archivo.";
        }
    cout << "Categoria de la empresa con mas empleados: " << endl;
    while(fread(&emp, sizeof(Empresa),1,pEmp)==1){
        if(bmax==0){
            maxEmpleados = emp.getCantEmpleados();
            catMax = emp.getCategoria();
            bmax=1;
        }else if(emp.getCantEmpleados()>maxEmpleados){
            maxEmpleados = emp.getCantEmpleados();
            catMax = emp.getCategoria();
        }
    }

    cout << "La categoria: " << catMax << " es la que tiene mas empleados, con: " << maxEmpleados << " empleados."<<endl;

    fclose(pEmp);

}





#endif // FGLOBALES_H_INCLUDED
