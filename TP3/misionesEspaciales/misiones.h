#ifndef MISIONES_H_INCLUDED
#define MISIONES_H_INCLUDED
#include <string.h>

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



class Fecha{
    private:
        int dia, mes, anio;
    public:
        void Cargar(){
            cout<<"DIA: ";
            cin>>dia;
            cout<<"MES: ";
            cin>>mes;
            cout<<"ANIO: ";
            cin>>anio;
        }
        void Mostrar(){
            cout<<"DIA: "<<dia<<endl;
            cout<<"MES: "<<mes<<endl;
            cout<<"ANIO: "<<anio<<endl;
        }
        void mostrarEnLinea(){
            cout<<dia<<" / "<<mes<<" / "<<anio<<endl;
        }

        void setDia(int d){
            if(d>=1 && d<=31) dia=d;
            else dia=-1;
        }
        void setMes(int m){
            if(m>=1 && m<=12) mes=m;
            else mes=-1;
        }
        void setAnio(int a){
            if(a>=1 && a<=31) anio=a;
            else anio=-1;
        }
        int getDia(){return dia;}
        int getMes(){return mes;}
        int getAnio(){return anio;}
};


class Mision{
private:
    char _numMision[5], _nombreMision[30], _nombreAstronauta[30], _apellidoAstronauta[30];
    Fecha _fechaInicio, _fechaFin;
    float _presupuesto;
public:
    void Cargar();
    void Mostrar();

    void setNumMision(const char *nm){strcpy(_numMision, nm);}
    void setNombreMision(const char *nomMis){strcpy(_nombreMision, nomMis);}
    void setNombreAstronauta(const char *nomAst){strcpy(_nombreAstronauta, nomAst);}
    void setApellidoAstronauta(const char *apeAst){strcpy(_apellidoAstronauta, apeAst);}
    void setPresupuesto(int presup){_presupuesto = presup;}

    const char *getNumMision(){return _numMision;}
    const char *getNombreMision(){return _nombreMision;}
    const char *getNombreAstronauta(){return _nombreAstronauta;}
    const char *getApellidoAstronauta(){return _apellidoAstronauta;}
    int getPresupuesto(){return _presupuesto;}

    Mision();

};

Mision::Mision(){
    setNumMision(strcpy(_numMision, "nada"));
    setNombreMision(strcpy(_nombreMision, "nada"));
    setNombreAstronauta(strcpy(_nombreAstronauta, "nada"));
    setApellidoAstronauta(strcpy(_apellidoAstronauta, "nada"));
}

void Mision::Cargar(){
    cout << "Numero de mision: ";
    cargarCadena(_numMision, 4);
    cout << "Nombre de la mision: ";
    cargarCadena(_nombreMision, 29);
    cout << "Nombre astronauta a cargo: ";
    cargarCadena(_nombreAstronauta, 29);
    cout << "Apellido: ";
    cargarCadena(_apellidoAstronauta, 29);
    cout << "Fecha de inicio: ";
    _fechaInicio.Cargar();
    cout << "Fecha de fin: ";
    _fechaFin.Cargar();
    cout << "Presupuesto disponible: ";
    cin >> _presupuesto;
    cout << endl;
}

void Mision::Mostrar(){
    cout << "Numero de mision: ";
    cout << _numMision  << endl;
    cout << "Nombre de la mision: ";
    cout << _nombreMision << endl;
    cout << "Nombre astronauta a cargo: ";
    cout << _nombreAstronauta << endl;
    cout << "Apellido: " ;
    cout << _apellidoAstronauta<< endl;
    cout << "Fecha de inicio: " ;
    _fechaInicio.mostrarEnLinea();
    cout << "Fecha de fin: ";
    _fechaFin.mostrarEnLinea();
    cout << "Presupuesto disponible: ";
    cout << _presupuesto << endl;
    cout << endl;
}

#endif // MISIONES_H_INCLUDED
