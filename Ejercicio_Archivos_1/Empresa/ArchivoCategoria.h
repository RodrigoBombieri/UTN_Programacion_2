#ifndef ARCHIVOCATEGORIA_H_INCLUDED
#define ARCHIVOCATEGORIA_H_INCLUDED

class ArchivoCategoria{
private:
    char nombre[30];
public:
    ArchivoCategoria(const char *n){
        strcpy(nombre, n);
    }

    bool listarRegistrosCategorias();
    bool grabarRegistroCategorias(Categoria);
    bool verificarExistenciaCategoria(int numCate);

};


bool ArchivoCategoria::listarRegistrosCategorias(){
    Categoria cate;
    FILE *p;
    bool quePaso;

    p=fopen(nombre, "rb");
        if(p==NULL){
            cout << "Error de archivo.";
            return false;
        }
    while(quePaso=fread(&cate, sizeof(Categoria),1,p)==1){
        cate.Mostrar();
        cout << endl;
    }
    fclose(p);
    return quePaso;
}

bool ArchivoCategoria::verificarExistenciaCategoria(int numCate) {
    FILE *p = fopen("Categorias.dat", "rb");
    if (p == NULL) {
        return false;
    }

    Categoria cate;
    while (fread(&cate, sizeof(Categoria), 1, p)) {
        if (cate.getNumeroCategoria() == numCate) {
            fclose(p);
            return true; // El número de empresa ya existe en el archivo
        }
    }

    fclose(p);
    return false; // El número de empresa no existe en el archivo
}


bool ArchivoCategoria::grabarRegistroCategorias(Categoria cate){
    bool escribio;
    FILE *p;
    p = fopen(nombre, "ab");
    if (p == NULL) {
        cout << "Error de archivo.";
        return false;
    }
    // Leer el número de empresa que deseas ingresar
    int numCate;
    cout << "Ingrese el número de categoria para verificar existencia: ";
    cin >> numCate;
    // Verificar si el número de empresa ya existe en el archivo
    bool existe = verificarExistenciaCategoria(numCate);
    if (existe) {
        cout << "El número de municipio ya existe en el archivo." << endl;
        fclose(p);
        return false;
    }

    // Escribir el registro en el archivo
    escribio = fwrite(&cate, sizeof(Categoria), 1, p);
    if (escribio == 0) {
        cout << "Error al escribir en el archivo." << endl;
        fclose(p);
        return false;
    }

    fclose(p);
    return escribio;
}

#endif // ARCHIVOCATEGORIA_H_INCLUDED
