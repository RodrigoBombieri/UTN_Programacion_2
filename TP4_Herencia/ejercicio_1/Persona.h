#ifndef PERSONA_H_INCLUDED
#define PERSONA_H_INCLUDED

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



class Persona{
protected:
    char nombre[30], apellido[30], direccion[30];
    char email[30], telefono[30];
    int DNI;
    Fecha fechaNacimiento;
public:
    void Cargar();
    void Mostrar();
    void setDNI(int d){DNI=d;}
    int getDNI(){return DNI;}

};

void Persona::Cargar(){
    cout<<"NOMBRE: ";
    cargarCadena(nombre, 29);
    cout<<"APELLIDO: ";
    cargarCadena(apellido, 29);
    cout<<"DIRECCION: ";
    cargarCadena(direccion, 29);
    cout<<"EMAIL: ";
    cargarCadena(email, 29);
    cout<<"TELEFONO: ";
    cargarCadena(telefono, 29);
    cout<<"DNI: ";
    cin>>DNI;
    cout<<"FECHA DE NACIMIENTO "<<endl;
    fechaNacimiento.Cargar();
}

void Persona::Mostrar(){
    cout<<"NOMBRE: ";
    cout<<nombre<<endl;
    cout<<"APELLIDO: ";
    cout<<apellido<<endl;
    cout<<"DIRECCION: ";
    cout<<direccion<<endl;
    cout<<"EMAIL: ";
    cout<<email<<endl;
    cout<<"TELEFONO: ";
    cout<<telefono<<endl;
    cout<<"DNI: ";
    cout<<DNI<<endl;
    cout<<"FECHA DE NACIMIENTO "<<endl;
    fechaNacimiento.Mostrar();
}


class Empleado : public Persona{
private:
    int _categoria;
    float _sueldo;
    Fecha _fechaIngreso;
public:
    void setCategoria(int cat){_categoria = cat;}
    void setSueldo(int sueld){_sueldo = sueld;}

    int getCategoria(){return _categoria;}
    float getSueldo(){return _sueldo;}

    void Cargar(){
        Persona::Cargar();
        cout << "Ingrese la categoria (1 a 5): ";
        cin >> _categoria;
        cout << "Ingrese el sueldo: ";
        cin >> _sueldo;
        cout << "Fecha de ingreso: ";
        _fechaIngreso.Cargar();
    }
    void Mostrar(){
        Persona::Mostrar();
        cout << "Categoria: ";
        cout << _categoria << endl;
        cout << "Sueldo: ";
        cout << _sueldo << endl;
        cout << "Fecha de ingreso: ";
        _fechaIngreso.mostrarEnLinea();
        cout << endl << endl;
    }

    Empleado(){
        setCategoria(0);
        setSueldo(0);
        _fechaIngreso.setDia(1);
        _fechaIngreso.setMes(1);
        _fechaIngreso.setAnio(1900);
    }

};

class Proveedor : public Persona{
private:
    char _numeroCuil[15], _condicionPago[2];
    int _tipoProductos;
public:
    void setNumeroCuil(const char *numCu){strcpy(_numeroCuil, numCu);}
    void setTipoProductos(int tp){_tipoProductos = tp;}
    void setCondicionPago(const char *condPa){strcpy(_condicionPago, condPa);}

    const char *getNumeroCuil(){return _numeroCuil;}
    int getTipoProducto(){return _tipoProductos;}
    const char *getCondicionPago(){return _condicionPago;}

    void Cargar(){
        Persona::Cargar();
        cout << "Ingrese su numero de CUIL: ";
        cargarCadena(_numeroCuil, 14);
        cout << "Ingrese el tipo de producto (1 a 10): ";
        cin >> _tipoProductos;
        cout << "Ingrese la condicion de pago (A-..., B-..., C-...): ";
        cargarCadena(_condicionPago, 1);
        cout << endl << endl;
    }
    void Mostrar(){
        Persona::Mostrar();
        cout << "CUIL: ";
        cout << _numeroCuil << endl;
        cout << "Tipo de Producto: ";
        cout << _tipoProductos << endl;
        cout << "Condicion de pago: ";
        if(*_condicionPago=='A'){
            cout << "A - ..... " << endl;
        }else if(*_condicionPago=='B'){
            cout << "B - ..... " << endl;
        }else if(*_condicionPago=='C'){
            cout << "C- ...... " << endl;
        }else{
            cout << "Metodo de pago no valido." << endl;
        }
    }

    Proveedor(){
        setNumeroCuil(strcpy(_numeroCuil, ""));
        setTipoProductos(0);
        setCondicionPago(strcpy(_condicionPago, "A"));
    }

};

class Docente : public Persona{
private:
    int _legajo;
    char _cargo[15];
    Fecha _fechaIngreso;
public:
    void setLegajo(int leg){_legajo = leg;}
    void setCargo(const char *cargo){strcpy(_cargo, cargo);}

    int getLegajo(){return _legajo;}
    const char *getCargo(){return _cargo;}

    void Cargar(){
        Persona::Cargar();
        cout << "Ingrese el numero de legajo: ";
        cin >> _legajo;
        cout << "Ingrese el cargo: ";
        cargarCadena(_cargo, 14);
        cout << "Ingrese la fecha de ingreso: ";
        _fechaIngreso.Cargar();
        cout << endl << endl;
    }

    void Mostrar(){
        Persona::Mostrar();
        cout << "Legajo: ";
        cout << _legajo << endl;
        cout << "Cargo: ";
        cout << _cargo << endl;
        cout << "Fecha de Ingreso: ";
        _fechaIngreso.mostrarEnLinea();
        cout << endl << endl;
    }

    Docente(){
        setLegajo(0);
        setCargo(strcpy(_cargo, ""));
        _fechaIngreso.setDia(1);
        _fechaIngreso.setMes(1);
        _fechaIngreso.setAnio(1900);
    }
};

#endif // PERSONA_H_INCLUDED
