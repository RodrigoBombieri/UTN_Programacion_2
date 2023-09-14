#ifndef CLSARCHIVOALUMNOS_H_INCLUDED
#define CLSARCHIVOALUMNOS_H_INCLUDED

class ArchivoAlumnos{
private:
    char nombre[30];
public:
    ArchivoAlumnos(const char *n){
        strcpy(nombre, n);
    }

    bool listarRegistros();
    bool grabarRegistros(Alumno);

};

bool ArchivoAlumnos::listarRegistros(){
    Alumno reg;
    FILE *pAlu;
    pAlu=fopen(nombre, "rb");
        if(pAlu==NULL){
            return false;
        }
    while(fread(&reg,sizeof reg,1,pAlu)==1){
        reg.Mostrar();
        cout << endl;
        //system("pause");
    }
    fclose(pAlu);
    return true;
}

bool ArchivoAlumnos::grabarRegistros(Alumno reg){
    FILE *pAlu;
    pAlu=fopen(nombre, "ab");
    if(pAlu==NULL){
        return false;
    }
    bool escribio = fwrite(&reg, sizeof reg, 1,pAlu);
    fclose(pAlu);
    return escribio;
}
#endif // CLSARCHIVOALUMNOS_H_INCLUDED
