#ifndef EMPRESA_H_INCLUDED
#define EMPRESA_H_INCLUDED

#include <string.h>


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


class Empresa{
private:
    int _numEmpresa, _cantidadEmpleados, _categoria, _numMunicipio;
    char _nombre[30];
    bool _estado;
public:
    void setNumEmpresa(int ne){_numEmpresa = ne;}
    void setNombre(const char *nomb){strcpy(_nombre, nomb);}
    void setCantEmpleados(int cantE){_cantidadEmpleados = cantE;}
    void setCategoria(int cat){_categoria = cat;}
    void setNumeroMunicipio(int numMuni){_numMunicipio = numMuni;}
    void setEstado(bool estado){_estado = estado;}

    int getNumEmpresa()const {return _numEmpresa;}
    const char *getNombreEmpresa()const{return _nombre;}
    int getCantEmpleados()const{return _cantidadEmpleados;}
    int getCategoria()const{return _categoria;}
    int getNumMunicipio()const{return _numMunicipio;}
    bool getEstado(){return _estado;}



    void Cargar(){
        cout << "CARGAR EMPRESA: " << endl;
        cout << "Ingrese el ID de la empresa: ";
        cin >> _numEmpresa;
        cout << "Ingrese el nombre: ";
        cargarCadena(_nombre, 29);
        cout << "Ingrese la cantidad de empleados: ";
        cin >> _cantidadEmpleados;
        cout << "Ingrese la categoria (1 a 80): ";
        cin >> _categoria;
        cout << "Ingrese el numero de municipio (1 a 135): ";
        cin >> _numMunicipio;
        _estado = true;
        cout << endl << endl;
    }
    void Mostrar(){
        cout << "DATOS DE LA EMPRESA: " << endl;
        cout << "Nombre: ";
        cout << _nombre << endl;
        cout << "ID: ";
        cout << _numEmpresa << endl;
        cout << "Cantidad empleados: ";
        cout << _cantidadEmpleados << " empleados." << endl;
        cout << "Categoria: ";
        cout << _categoria << endl;
        cout << "Numero de municipio: ";
        cout << _numMunicipio << endl;
        cout << endl;
    }
};


void mostrarMenu()
{
cout << "**********************************" << endl;
cout << "************** MENU **************" << endl;
cout << "1 - Cargar un registro" << endl;
cout << "2 - Mostrar un registro" << endl;
cout << "3 - Cargar varios registros" << endl;
cout << "4 - Mostrar varios registros" << endl;
cout << "**********************************" << endl;
cout << "**********************************" << endl;
cout << "0 - Salir " << endl;
cout << endl << endl;
}

bool cargarUnRegistro(){
    FILE *pemp;
    Empresa empresa1;

    pemp=fopen("Empresas.dat", "wb");
        if(pemp==NULL){
            cout << "Error de archivo.";
            exit(1);
        }
    cout << "Cargar empresa: ";
    empresa1.Cargar();
    bool escribio=fwrite(&empresa1, sizeof empresa1, 1, pemp);
        fclose(pemp);

    return escribio;
}

bool mostrarUnRegistro(){
    FILE *pemp;
    Empresa empresa1;

    pemp=fopen("Empresas.dat", "rb");
        if(pemp==NULL){
            cout << "Error de archivo.";
            exit(1);
        }
    while(fread(&empresa1, sizeof empresa1, 1, pemp)==1){
        empresa1.Mostrar();
        cout << endl;
    }

    fclose(pemp);
    return true;
}


bool cargarVariosRegistros(Empresa *empresas){
    FILE *pEmp;

    pEmp=fopen("Empresas.dat", "ab");
    if(pEmp==NULL){
        cout << "Error de archivo.";
        exit(1);
    }

    for(int i=0; i<5; i++){
        empresas[i].Cargar();
    }

    bool escribio=fwrite(empresas, sizeof(Empresa),5,pEmp);
    fclose(pEmp);

    return escribio;

}

void mostrarVector(Empresa *empresas, int tam){
    for(int i=0; i<tam; i++){
        empresas[i].Mostrar();
        cout << endl;
    }

}

void mostrarVariosRegistros(Empresa *empresas){
    FILE *pEmp;

    pEmp=fopen("Empresas.dat", "rb");
        if(pEmp==NULL){
            cout << "Error de archivo.";
            exit(1);
        }

    fread(empresas, sizeof(Empresa),5,pEmp);
    fclose(pEmp);
    mostrarVector(empresas, 5);

}


#endif // EMPRESA_H_INCLUDED
