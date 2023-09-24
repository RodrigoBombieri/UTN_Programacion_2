#ifndef ARCHIVOEMPRESA_H_INCLUDED
#define ARCHIVOEMPRESA_H_INCLUDED

bool verificarExistencia(int numEmpresa) {
    FILE *pEmp = fopen("Empresas.dat", "rb");
    if (pEmp == NULL) {
        return false;
    }

    Empresa emp;
    while (fread(&emp, sizeof(Empresa), 1, pEmp)) {
        if (emp.getNumEmpresa() == numEmpresa) {
            fclose(pEmp);
            return true; // El número de empresa ya existe en el archivo
        }
    }

    fclose(pEmp);
    return false; // El número de empresa no existe en el archivo
}


class ArchivoEmpresa{
private:
    char nombre[30];
public:
    ArchivoEmpresa(const char *n){
        strcpy(nombre, n);
    }

    bool listarRegistros();
    bool grabarRegistro(Empresa);

};


bool ArchivoEmpresa::listarRegistros(){
    Empresa emp;
    FILE *pEmp;
    bool quePaso;

    pEmp=fopen(nombre, "rb");
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
}

bool ArchivoEmpresa::grabarRegistro(Empresa emp){
    bool escribio;
    FILE *pEmp;
    pEmp = fopen(nombre, "ab");
    if (pEmp == NULL) {
        cout << "Error de archivo.";
        return false;
    }
    // Leer el número de empresa que deseas ingresar
    int numEmpresa;
    cout << "Ingrese el número de municipio para verificar existencia: ";
    cin >> numEmpresa;
    // Verificar si el número de empresa ya existe en el archivo
    bool existe = verificarExistencia(numEmpresa);
    if (existe) {
        cout << "El número de empresa ya existe en el archivo." << endl;
        fclose(pEmp);
        return false;
    }

    // Escribir el registro en el archivo
    escribio = fwrite(&emp, sizeof(Empresa), 1, pEmp);
    if (escribio == 0) {
        cout << "Error al escribir en el archivo." << endl;
        fclose(pEmp);
        return false;
    }

    fclose(pEmp);
    return escribio;
}


#endif // ARCHIVOEMPRESA_H_INCLUDED
