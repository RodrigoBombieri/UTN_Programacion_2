#ifndef MUNICIPIOS_H_INCLUDED
#define MUNICIPIOS_H_INCLUDED

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

class Municipio{
private:
    int _numero, _seccion, _cantidadHabitantes;
    char _nombre[30];
    bool _estado;

public:
    void setNumeroMunicipio(int nm){_numero = nm;}
    int getNumeroMunicipio(){return _numero;}

    void setNombreMunicipio(const char *nom){strcpy(_nombre,nom);}
    const char *getNombreMunicipio(){return _nombre;}

    void setSeccion(int secc){_seccion = secc;}
    int getSeccion(){return _seccion;}

    void setCantidadHabitantes(int cantH){_cantidadHabitantes = cantH;}
    int getCantidadHabitantes(){return _cantidadHabitantes;}

    void Cargar(){
        cout << "CARGAR MUNICIPIO: "<<endl;
        cout << "Ingrese el numero (1 a 135): "<<endl;
        cin >> _numero;
        cout << "Ingrese el nombre: "<<endl;
        cargarCadena(_nombre, 29);
        cout << "Ingrese la seccion a la que pertenece (1 a 9): "<<endl;
        cin >> _seccion;
        cout << "Ingrese la cantidad de habitantes: "<<endl;
        cin >> _cantidadHabitantes;
        _estado = true;
        cout << endl;

    }

    void Mostrar(){
        if(_estado==true){
            cout << "CARGAR MUNICIPIO: "<<endl;
            cout << "Numero: "<<endl;
            cout << _numero;
            cout << "Nombre: "<<endl;
            cout << _nombre;
            cout << "Seccion: "<<endl;
            cout << _seccion;
            cout << "Cantidad de Habitantes: "<<endl;
            cout << _cantidadHabitantes;
            cout << endl;
        }

    }

};

#endif // MUNICIPIOS_H_INCLUDED
