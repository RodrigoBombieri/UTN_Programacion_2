#ifndef ARCHIVOMUNI_H_INCLUDED
#define ARCHIVOMUNI_H_INCLUDED



class ArchivoMuni{
private:
    char nombre[30];
public:
    ArchivoMuni(const char *n){
        strcpy(nombre, n);
    }

    bool listarRegistros();
    bool grabarRegistro(Municipio muni);
    bool verificarExistenciaMuni(int numMuni);

};


bool ArchivoMuni::listarRegistros(){
    Municipio muni;
    FILE *p;
    bool quePaso;

    p=fopen(nombre, "rb");
        if(p==NULL){
            cout << "Error de archivo.";
            return false;
        }
    while(quePaso=fread(&muni, sizeof(Municipio),1,p)==1){
        muni.Mostrar();
        cout << endl;
    }
    fclose(p);
    return quePaso;
}

bool ArchivoMuni::verificarExistenciaMuni(int numMuni) {
    FILE *p = fopen("Municipios.dat", "rb");
    if (p == NULL) {
        return false;
    }

    Municipio muni;
    while (fread(&muni, sizeof(Municipio), 1, p)) {
        if (muni.getNumeroMunicipio() == numMuni) {
            fclose(p);
            return true; // El número de empresa ya existe en el archivo
        }
    }

    fclose(p);
    return false; // El número de empresa no existe en el archivo
}


bool ArchivoMuni::grabarRegistro(Municipio muni){
    bool escribio;
    FILE *p;
    p = fopen(nombre, "ab");
    if (p == NULL) {
        cout << "Error de archivo.";
        return false;
    }
    // Leer el número de empresa que deseas ingresar
    int numMuni;
    cout << "Ingrese el número de municipio para verificar existencia: ";
    cin >> numMuni;
    // Verificar si el número de empresa ya existe en el archivo
    bool existe = verificarExistenciaMuni(numMuni);
    if (existe) {
        cout << "El número de municipio ya existe en el archivo." << endl;
        fclose(p);
        return false;
    }

    // Escribir el registro en el archivo
    escribio = fwrite(&muni, sizeof(Municipio), 1, p);
    if (escribio == 0) {
        cout << "Error al escribir en el archivo." << endl;
        fclose(p);
        return false;
    }

    fclose(p);
    return escribio;
}


#endif // ARCHIVOMUNI_H_INCLUDED
