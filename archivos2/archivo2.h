#ifndef ARCHIVO2_H_INCLUDED
#define ARCHIVO2_H_INCLUDED

void mostrarMenu(){
    cout << " ************** MENU **************" << endl;
    cout << " 1 - Agregar registro: " << endl;
    cout << " 2 - Baja Logica registro: " << endl;
    cout << " 3 - Mostrar registro: " << endl;

    cout << " 0 - Salir." << endl;
    cout << " **********************************" << endl;
    cout << endl;

}

/// PROTOTIPOS

int buscarLegajo(int legajo);
Alumno leerRegistro(int pos);
bool sobreEscribirRegistro(Alumno reg, int pos);

/// FIN PROTOTIPOS


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

bool cargarRegistro(){
    /*Alumno alumno;
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
    return escribio;*/
    //const int CANT_REG=1;
    Alumno reg;
    ArchivoAlumnos archiAlu("alumnos.dat");
    cout << "Ingresar los valores del registro: " << endl;
    reg.Cargar();
    bool escribio=archiAlu.grabarRegistros(reg);
    return escribio;

}

bool mostrarRegistro(){
    /*Alumno alumno;
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
    return true;*/

    ArchivoAlumnos archi("alumnos.dat");
    bool quePaso=archi.listarRegistros();
    return quePaso;
}

bool bajaLogicaRegistro(){
/// 1 -  INGRESAR EL VALOR QUE IDENTIFICA EL REGISTRO A BORRAR
    int legajo, pos;
    cout << "Ingresar el legajo del alumno a dar de baja: ";
    cin >> legajo;

    /// BUSCAR SI EL LEGAJO EXISTE EN EL ARCHIVO
    /// La funcion devuelve la posicion del registro en el archivo. si no encuentra el legajo devuelve -1.
    pos = buscarLegajo(legajo);
        if(pos==-1){
            cout << "No existe ese legajo.";
            return false;
        }
/// 2 - LEER EL REGiSTRO DEL ARCHIVO Y PONERLO EN UNA VARIABLE DE MEMORIA
    Alumno reg;
    reg=leerRegistro(pos);
/// 3 - CAMBIAR EL CAMPO estado
    cout << "Registro a borrar: "<< endl;
    reg.Mostrar();
    cout << endl;
    char opc;
    cout << "Desea borrarlo? (S/N): ";
    cin >> opc;
    if(opc=='s' || opc=='S'){
        reg.setEstado(false);
/// 4 - SOBREESCRIBIR EL REGISTRO EN EL ARCHIVO EN LA MISMA POSICION QUE TENIA
        bool quePaso = sobreEscribirRegistro(reg, pos);
        return quePaso;
    }
    return false;
}

/// Busca si el legajo existe o no en el archivo, si lo encuentra, devuelve la pos.
/// si no lo encuentra en esa vuelta, incrementa el valor de pos (pos++), o sea lee, y luego corre el puntero FILE al registro que sigue.
/// si no lo encuentra devuelve -1.

int buscarLegajo(int legajo){
    Alumno reg;
    FILE *pAlu;
    pAlu=fopen("alumnos.dat", "rb");
    int pos=0;
    if(pAlu==NULL){
        return -2;
    }
    while(fread(&reg,sizeof reg,1,pAlu)==1){
        if(legajo==reg.getlegajo()){
            fclose(pAlu);
            return pos;
        }
        pos++;
    }

    fclose(pAlu);
    return -1;
}

Alumno leerRegistro(int pos){
    /// FORMA 1 ///

    /*Alumno reg;
    reg.setEstado(false);
    FILE *pAlu;
    pAlu=fopen("alumnos.dat", "rb");
    int posLectura=0;
    if(pAlu==NULL){
        return reg; /// no pudo abrir el archivo
    }
    while(fread(&reg,sizeof reg,1,pAlu)==1){
        if(pos==posLectura){
            fclose(pAlu);
            return reg; /// funciono bien y deviuelve el registro
        }
        posLectura++; /// contador que va contando los registros hasta que coincida
    }

    fclose(pAlu);
    reg.setEstado(false);
    return reg;*/ /// nunca coincidio la posicion

    /// FORMA 2 ///

    Alumno reg;
    reg.setEstado(false);
    FILE *pAlu;
    pAlu=fopen("alumnos.dat", "rb");
    if(pAlu==NULL){
        return reg;
    }

    /// Quiero ubicarme en el registor pos del archivo
    /// fseek(pFILE,CANT_BYTES_A_MOVERSE, DESDE_DONDE) /// permite ubicar el puntero en posiciones especificas dentro del archivo.
    /// fseek(pAlu, 0,0) -> el puntero queda al principio del archivo
    /// fseek(pAlu, 0,2) -> el puntero queda al final del archivo

    ///DESDE_DONDE:
        /// 0 PRINCIPIO                     SEEK_SET (es lo mismo que poner un 0)
        /// 1 POSICION ACTUAL               SEEK_CUR (es lo mismo que poner un 1)
        /// 2 DESDE EL FIN DEL ARCHIVO      SEEK_END (es lo mismo que poner un 2)
    fseek(pAlu, sizeof reg*pos,SEEK_SET);
    /// Ubicarme en el registro pos del archivo
    fread(&reg, sizeof reg, 1,pAlu);
    fclose(pAlu);
    return reg;
}

bool sobreEscribirRegistro(Alumno reg, int pos){
    FILE *pAlu;
    pAlu=fopen("alumnos.dat", "rb+");/// el + agrega el modo que le falta (en este caso agrega la funcion de escribir),
                                        /// se usa el "rb+" ya que "read" es la unica accion que entiende el fseek
    if(pAlu==NULL){
        return false;
    }

    fseek(pAlu, sizeof reg*pos,0);
    bool escribio = fwrite(&reg, sizeof reg, 1, pAlu);
    fclose(pAlu);
    return escribio;
}

#endif // ARCHIVO2_H_INCLUDED
