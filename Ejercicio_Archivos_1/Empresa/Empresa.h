#ifndef EMPRESA_H_INCLUDED
#define EMPRESA_H_INCLUDED



class Empresa{
private:
    int _numEmpresa, _cantidadEmpleados, _categoria, _numMunicipio;
    char _nombre[30];
    char _nombreMuni[30];
    bool _estado;
    Municipio muni;
public:

    void setNumEmpresa(int ne)
    {
        while(ne < 0 || ne > 100){
            cout << "Numero de empresa inválido. Ingrese nuevamente."<< endl;
            cin >> ne;
        }
        _numEmpresa = ne;

    }
    void setNombre(const char *nomb)
    {
        cout << "El nombre debe tener como maximo 30 caracteres."<<endl;
        strcpy(_nombre, nomb);
    }
    void setCantEmpleados(int cantE)
    {
        while(cantE < 0){
            cout << "Numero invalido. Ingrese nuevamente."<<endl;
            cin >> cantE;
        }
        _cantidadEmpleados = cantE;
    }
    void setCategoria(int cat)
    {
        while(cat < 0 || cat > 80){
            cout << "Ingrese un numero de categoria entre 1 y 80."<<endl;
            cin >> cat;
        }
        _categoria = cat;

    }
    void setNumeroMunicipio(int numMuni)
    {
        while(numMuni < 0 || numMuni>135){
            cout << "Ingrese un numero de municipio entre 1 y 135."<<endl;
            cin >> numMuni;
        }
        _numMunicipio = numMuni;
    }

    void setEstado(bool estado){_estado = estado;}

    int getNumEmpresa()const {return _numEmpresa;}
    const char *getNombreEmpresa()const{return _nombre;}
    int getCantEmpleados()const{return _cantidadEmpleados;}
    int getCategoria()const{return _categoria;}
    int getNumMunicipio()const{return _numMunicipio;}
    bool getEstado(){return _estado;}





    /// hacer validaciones en todos los campos
void Cargar(){
        cout << "CARGAR EMPRESA: " << endl;
        cout << "Ingrese el ID de la empresa: ";
        cin >> _numEmpresa;
        cout << "Ingrese el nombre: ";
        cargarCadena(_nombre, 29);
        cout << "Ingrese la cantidad de empleados: ";
        cin >> _cantidadEmpleados;
        cout << "Ingrese la categoria (1 a 80): ";
        cin >> _categoria;
        cout << "Ingrese el numero de municipio (1 a 135): ";
        cin >> _numMunicipio;
        cout << "Ingrese el nombre del municipio: ";
        cargarCadena(_nombreMuni, 29);
        _estado = true;
        cout << endl << endl;

    }

    void Mostrar(){
        if(_estado==true){
        cout << "DATOS DE LA EMPRESA: " << endl;
        cout << "Nombre: ";
        cout << _nombre << endl;
        cout << "ID: ";
        cout << _numEmpresa << endl;
        cout << "Cantidad empleados: ";
        cout << _cantidadEmpleados << " empleados." << endl;
        cout << "Categoria: ";
        cout << _categoria << endl;
        cout << "Numero de municipio: ";
        cout << _numMunicipio << endl;
        cout << "Nombre del municipio: ";
        cout << _nombreMuni<<endl;
        cout << endl;
        }
    }
};




#endif // EMPRESA_H_INCLUDED
