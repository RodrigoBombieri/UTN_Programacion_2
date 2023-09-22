#ifndef ARCHIVOEMPRESA_H_INCLUDED
#define ARCHIVOEMPRESA_H_INCLUDED

class ArchivoEmpresa{
private:
    char nombre[30];
public:
    ArchivoEmpresa(const char *n){
        strcpy(nombre, n);
    }

    bool mostrarRegistros();




};


#endif // ARCHIVOEMPRESA_H_INCLUDED
