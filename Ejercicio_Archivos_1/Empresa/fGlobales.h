#ifndef FGLOBALES_H_INCLUDED
#define FGLOBALES_H_INCLUDED

#include <string.h>
#include "Empresa.h"

Empresa leerRegistro(int pos);

void mostrarMenu()
{
cout << "**********************************" << endl;
cout << "************** MENU **************" << endl;
cout << "1 - ALTA EMPRESA" << endl;
cout << "2 - BAJA EMPRESA" << endl;
cout << "3 - MODIFICAR CATEGORIA EMPRESA" << endl;
cout << "4 - LISTAR EMPRESAS" << endl;
cout << "**********************************" << endl;
cout << "5 - Cargar varios registros" << endl;
cout << "6 - Cantidad de empresas de cada municipio" << endl;
cout << "7 - Empresas con mas de 200 empleados: " << endl;
cout << "8 - Categoria de empresa con mas empleados: " << endl;
cout << "**********************************" << endl;
cout << "0 - Salir " << endl;
cout << endl << endl;
}


void subMenuListar(){
cout << "***********************************" << endl;
cout << "********* SUB MENU LISTAR *********" << endl;
cout << "1 - LISTAR EMPRESAS" << endl;
cout << "2 - LISTAR EMPRESAS POR NUMERO" << endl;
cout << "**********************************" << endl;
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


bool cargarUnRegistro() {
    Empresa emp;
    bool escribio;
    FILE *pEmp;

    pEmp = fopen("Empresas.dat", "ab");
    if (pEmp == NULL) {
        cout << "Error de archivo.";
        return false;
    }

    // Leer el número de empresa que deseas ingresar
    int numEmpresa;
    cout << "Ingrese el número de empresa: ";
    cin >> numEmpresa;

    // Verificar si el número de empresa ya existe en el archivo
    bool existe = verificarExistencia(numEmpresa);

    if (existe) {
        cout << "El número de empresa ya existe en el archivo." << endl;
        fclose(pEmp);
        return false;
    }

    // Asignar el número de empresa y cargar otros datos de la empresa
    emp.setNumEmpresa(numEmpresa);
    emp.Cargar();

    // Escribir el registro en el archivo
    escribio = fwrite(&emp, sizeof(Empresa), 1, pEmp);
    if (escribio == 0) {
        cout << "Error al escribir en el archivo." << endl;
        fclose(pEmp);
        return false;
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

Empresa leerRegistro(int pos){
    Empresa emp;
    /// seteamos en false el estado para identificar el registro a borrar
    emp.setEstado(false);
    FILE *pEmp;
    /// si no pudo abrirlo, devuelve el objeto como esta
    pEmp=fopen("Empresas.dat", "rb");
    if(pEmp==NULL){
        return emp;
    }
    /// colocamos el puntero desde el inicio en la posicion*tamaño de la clase.
    fseek(pEmp,sizeof (Empresa)*pos,0);
    /// una vez posicionado leemos el registro (lo traemos del disco a la memoria) y lo devuelve a la funcion bajaLogica
    fread(&emp,sizeof(Empresa),1,pEmp);
    fclose(pEmp);
    return emp;
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

int buscarNumEmpresa(int numEmpresa){
    Empresa emp;
    FILE *pEmp;
    /// si el legajo no existe, devuelvo un valor para cortar el programa en bajaLogica.
    pEmp=fopen("Empresas.dat", "rb");
    int pos=0;
        if(pEmp==NULL){
            return -2;
        }
        /// mientras lea los registros validos, pregunta si el numero de empresa es igual a alguno de los ya cargados.
        /// si encuentra, cierra el puntero y devuelve la posicion del registro a borrar. Sino, incrementa una posicion y busca nuevamente.
    while(fread(&emp, sizeof(Empresa),1,pEmp)==1){
        if(numEmpresa==emp.getNumEmpresa()){
            fclose(pEmp);
            return pos;
        }
        pos++;
    }
    fclose(pEmp);
    /// si no encuentra ninguno, devuelve -1
    return -1;
}

bool sobreescribirRegistro(Empresa emp, int pos){
    FILE *pEmp;
    pEmp=fopen("Empresas.dat", "rb+");
    if(pEmp==NULL){
        return false;
    }
    /// posicionamos el puntero y escribimos en ese registro el parametro que seteamos en la funcion
    fseek(pEmp,sizeof (Empresa)*pos,0);
    bool escribio=fwrite(&emp,sizeof (Empresa),1,pEmp);
    fclose(pEmp);
    return escribio;
}


bool bajaLogicaUnRegistro(){
    /// Decidir con que valor voy a dar de baja el registro (en este caso por numero de empresa)
    int numEmpresa, pos;
    cout << "Numero de la empresa a dar de baja: "<<endl;
    cin >> numEmpresa;
    /// busco la posicion de la empresa dentro del registro (hago una funcion y le mando el numero de empresa ingresado para borrar)
    pos=buscarNumEmpresa(numEmpresa);
    if(pos==-2){
        cout << "No existe el legajo."<<endl;
        return false;
    }

    Empresa emp;
    /// creo el objeto y hago una funcion para leer los registros, le envio la posicion que encontre
    emp=leerRegistro(pos);
    /// devuelve el objeto que leyo en la funcion y lo muestra
    cout << "Registro a borrar: "<<endl;
    emp.Mostrar();
    cout << endl;

    char opc;
    /// por las dudas verificamos si se quiere borrar
    cout<<"Desea borrarlo? (S/N): " <<endl;
    cin >> opc;
    /// si se elige Si, seteamos el estado a false y llamamos a la funcion para sobreescribir el registro.
    if(opc== 'S' || opc== 's'){
        emp.setEstado(false);
        /// se sobreescribe con todos sus datos originales, pero cambia el ESTADO a false, entonces no se ve.
        bool quePaso=sobreescribirRegistro(emp, pos);
        return quePaso;
    }
    return false;

}


bool modificarCategoriaEmpresa(){
    ///
    int numEmpresa, nuevaCategoria, pos;
    cout << "Numero de la empresa a modificar: "<<endl;
    cin >> numEmpresa;
    /// Llama a la funcion que devuelve la posicion de la empresa en el registro
    pos=buscarNumEmpresa(numEmpresa);
    if(pos==-2){
        cout << "No existe el legajo."<<endl;
        return false;
    }
    Empresa emp;
    /// Lee el registro de la posicion que buscamos antes, y devuelve el objeto que leyó
    emp=leerRegistro(pos);

    /// Mostramos la empresa que se va a modificar con todos sus datos
    cout << "Empresa a modificar: "<<endl;
    emp.Mostrar();
    cout << endl;
    char opc;
    cout << "Desea modificar? (S/N)";
    cin >> opc;

    /// Pedimos la nueva categoria, la seteamos en el objeto, y llamamos a la funcion sobreescribir registro, que va a cambiar el parametro
    /// seteado, y devuelve true si lo cambió correctamente.
    if(opc=='s' || opc=='S'){
        cout << "Ingrese el nuevo numero de categoria: "<<endl;
        cin >> nuevaCategoria;
        emp.setCategoria(nuevaCategoria);
        bool quePaso=sobreescribirRegistro(emp, pos);
        return quePaso;
    }
    return false;


}


bool mostrarRegistrosFiltrados(int numEmpresa){
    Empresa emp;
    FILE *pEmp;
    bool quePaso;

    pEmp=fopen("Empresas.dat", "rb");
        if(pEmp==NULL){
            cout << "Error de archivo.";
            return false;
        }
    while(quePaso=fread(&emp, sizeof(Empresa),1,pEmp)==1){
        if(numEmpresa == emp.getNumEmpresa()){
            emp.Mostrar();
            cout << endl;
        }
    }
    fclose(pEmp);
    return quePaso;

}


#endif // FGLOBALES_H_INCLUDED
