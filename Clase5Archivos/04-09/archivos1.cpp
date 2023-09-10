///Ejercicio:
///Autor:DEK
///Fecha:
///Comentario:

# include<iostream>
/*# include<cstdlib>
# include<cstring>
# include<cstdio>*/

using namespace std;

#include "herencia1.cpp"

void mostrarMenu(){
    cout << " ************** MENU **************" << endl;
    cout << " 1 - Cargar registro: " << endl;
    cout << " 2 - Mostrar registro: " << endl;
    cout << " 0 - Salir." << endl;
    cout << " **********************************" << endl;
    cout << endl;

}

bool cargarRegistro(){
    Alumno alumno;
    FILE *pAlu;
    pAlu=fopen("alumnos.dat", "ab");
    if(pAlu==NULL){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return false;
    }
    cout << "Cargar valores del registro: " << endl;
    alumno.Cargar();///el objeto tiene la info que quiero llevar al disco
    bool escribio=fwrite(&alumno,sizeof alumno,1,pAlu);
	fclose(pAlu);
    return escribio;

}

bool mostrarRegistro(){
    Alumno alumno;
    FILE *pAlu;
    pAlu=fopen("alumnos.dat", "rb");
    if(pAlu==NULL){
        return false;
    }
    while(fread(&alumno,sizeof alumno,1,pAlu)==1){
        alumno.Mostrar();
        cout << endl;
    }

    fclose(pAlu);
    return true;
}

int main(){
    int opc;
    bool corte = true;

    while(corte==true){
        mostrarMenu();
        cout << "Ingrese una opcion: ";
        cin >> opc;
        switch(opc){
        case 1: if(cargarRegistro()) cout << "registro agregado";
                else cout << "No se pudo agregar registro." << endl;
            break;
        case 2: mostrarRegistro();
            break;
        case 0:
            corte=false;
            break;
        }
    }

	system("pause");
	return 0;
}
