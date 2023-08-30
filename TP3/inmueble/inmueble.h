#ifndef INMUEBLE_H_INCLUDED
#define INMUEBLE_H_INCLUDED

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
            cout<<dia<<"/"<<mes<<"/"<<anio<<endl;
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

class Direccion{
private:
    char _nombreCalle[20], _numeroCalle[5], _codPostal[7], _localidad[20], _numPiso[5];
public:
    void Cargar(){
        cout << "Ingrese el nombre de la calle: ";
        cargarCadena(_nombreCalle, 19);
        cout << "Ingrese el numero de la calle: ";
        cargarCadena(_numeroCalle, 4);
        cout << "Ingrese el Codigo Postal: ";
        cargarCadena(_codPostal, 6);
        cout << "Ingrese la Localidad: ";
        cargarCadena(_localidad, 19);
        cout << "Ingrese el numero de piso: ";
        cargarCadena(_numPiso, 4);
        cout << endl << endl;
    }
    void Mostrar(){
        cout << "Nombre de Calle: ";
        cout << _nombreCalle << endl;
        cout << "Numero: ";
        cout << _numeroCalle << endl;
        cout << "Codigo Postal: ";
        cout << _codPostal << endl;
        cout << "Localidad: ";
        cout << _localidad << endl;
        cout << "Numero de piso: ";
        cout << _numPiso << endl;
        cout << endl << endl;

    }

    void setNombreCalle(const char *nombCalle){strcpy(_nombreCalle, nombCalle);}
    void setNumeroCalle(const char *numCalle){strcpy(_nombreCalle, numCalle);}
    void setCodigoPostal(const char *codPos){strcpy(_codPostal, codPos);}
    void setLocalidad(const char *localid){strcpy(_localidad, localid);}
    void setNumPiso(const char *numPiso){strcpy(_numPiso, numPiso);}

    const char *getNombreCalle(){return _nombreCalle;}
    const char *getNumeroCalle(){return _numeroCalle;}
    const char *getCodPostal(){return _codPostal;}
    const char *getLocalidad(){return _localidad;}
    const char *getNumPiso(){return _numPiso;}
};


class Inmueble{
private:

protected:
    float _superficieTotal;
    int _tipoOperacion;
    Direccion _direccion1;
    Fecha _fechaIngreso;
    Fecha _fechaOperacion;
public:
    void Cargar(){
        cout << "Ingrese la direccion: " << endl;
        _direccion1.Cargar();
        cout << "Tipo de operacion (1-Venta, 2-Alquiler): ";
        cin >> _tipoOperacion;

        if(_tipoOperacion==1){
            cout << "Fecha de operacion: ";
            _fechaOperacion.Cargar();
        }else if(_tipoOperacion==2){
            cout << "Fecha de ingreso: ";
            _fechaIngreso.Cargar();
        }

        cout << "Superficie total: ";
        cin >> _superficieTotal;
        cout << endl << endl;


    }

    void Mostrar(){
        cout << "Direccion: ";
        _direccion1.Mostrar();
        cout << "Tipo Operacion: ";
        if(_tipoOperacion==1){
            cout << "Venta: " << endl;
            _fechaOperacion.mostrarEnLinea();
        }else if(_tipoOperacion==2){
            cout << "Alquiler: " << endl;
            _fechaIngreso.mostrarEnLinea();
        }else{
            cout << "Operacion no valida.";
        }

        cout << "Superficie Total: ";
        cout << _superficieTotal << endl;

    }

    void setSuperficieTotal(float sup){_superficieTotal = sup;}
    void setTipoOperacion(int tipoOp){_tipoOperacion = tipoOp;}

    float getSuperficieTotal(){return _superficieTotal;}
    int getTipoOperacion(){return _tipoOperacion;}


};


class Casa: public Inmueble{
private:
    int _cantAmbientes;
    float _superficieConstruida;
public:
    void Cargar();
    void Mostrar();

    void setCantAmbientes(int cantAmb){_cantAmbientes = cantAmb;}
    void setSuperficieConstruida(float supConstr){_superficieConstruida = supConstr;}

    int getCantidadAmbientes(){return _cantAmbientes;}
    float getSuperficieConstruida(){return _superficieConstruida;}

};

#endif // INMUEBLE_H_INCLUDED
