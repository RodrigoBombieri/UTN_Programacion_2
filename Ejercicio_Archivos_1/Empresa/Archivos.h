#ifndef ARCHIVOS_H_INCLUDED
#define ARCHIVOS_H_INCLUDED


void cargarVectorEmpresa(Empresa *vReg, int cant){
    int i;
    for(i=0; i<5; i++){
        vReg[i].Cargar();
    }
}



bool cargarUnRegistro(){
    Empresa reg;
    bool escribio;
    FILE *pEmp;

    pEmp=fopen("Empresas.dat", "wb");
        if(pEmp==NULL){
            cout << "Error de archivo.";
            return false;
        }

    for(int i=0; i<5; i++){
        reg.Cargar();
        escribio=fwrite(&reg, sizeof (Empresa), 1, pEmp);
        if(escribio==0){
            fclose(pEmp);
            return false;
        }
    }

    fclose(pEmp);
    return escribio;
}

bool mostrarRegistros(){
    Empresa reg;
    FILE *pEmp;
    bool quePaso;

    pEmp=fopen("Empresas.dat", "rb");
        if(pEmp==NULL){
            cout << "Error de archivo.";
            return false;
        }
    /*for(int i=0; i<5; i++){
        quePaso=fread(&reg, sizeof (Empresa),1,pEmp);
        reg.Mostrar();
        cout << endl;
    }*/

    while(quePaso=fread(&reg, sizeof (Empresa),1,pEmp)==1){
        reg.Mostrar();
        cout << endl;
    }


    fclose(pEmp);
    return true;
}


bool cargarVariosRegistros(){
    Empresa vReg[5];
    bool escribio;
    FILE *pEmp;

    pEmp=fopen("Empresas.dat", "ab");
    if(pEmp==NULL){
        cout << "Error de archivo.";
        exit(1);
    }

    cargarVectorEmpresa(vReg, 5);
    escribio=fwrite(vReg, sizeof(Empresa),5,pEmp);
    fclose(pEmp);
    return escribio;
}


#endif // ARCHIVOS_H_INCLUDED
