#ifndef COMPRAS_H_INCLUDED
#define COMPRAS_H_INCLUDED
#include "string.h"


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


class Compra{
private:
    int _numCompra, _tipoProducto, _formaPago, _cantidad;
    float _importeTotal;
    char _nombreProducto[30];
    Fecha _fechaCompra;
public:
    void Cargar();
    void Mostrar();

    void setNumCompra(int nc){_numCompra = nc;}
    void setTipoProducto(int tp){_tipoProducto = tp;}
    void setFormaPago(int fp){_formaPago = fp;}
    void setCantidad(int c){_cantidad = c;}
    void setImporteTotal(float it){_importeTotal = it;}

    void setNombreProducto(const char *np){strcpy(_nombreProducto, np);}

    int getNumCompra(){return _numCompra;}
    int getTipoProducto(){return _tipoProducto;}
    int getFormaPago(){return _formaPago;}
    int getCantidad(){return _cantidad;}
    float getImporteTotal(){return _importeTotal;}
    const char *getNombreProducto(){return _nombreProducto;}

};

void Compra::Cargar(){
    cout << "Ingrese el numero de compra: ";
    cin >> _numCompra;
    cout << "Ingrese la fecha: ";
    _fechaCompra.Cargar();
    cout << "Ingrese el nombre del producto: ";
    cargarCadena(_nombreProducto, 29);
    cout << "Tipo de producto (1 a 15): ";
    cin >> _tipoProducto;
    cout << "Forma de pago acordada (1 a 5): ";
    cin >> _formaPago;
    cout << "Cantidad: ";
    cin >> _cantidad;
    cout << "Importe total: ";
    cin >> _importeTotal;
    cout << endl;

}

void Compra::Mostrar(){
    cout << "Numero de compra: " << endl;
    cout << _numCompra;
    cout << "Fecha de compra: "<< endl;
    _fechaCompra.mostrarEnLinea();
    cout << "Nombre del producto: "<< endl;
    cout << _nombreProducto;
    cout << "Tipo de producto (1 a 15): "<< endl;
    cout << _tipoProducto;
    cout << "Forma de pago acordada (1 a 5): "<< endl;
    cout << _formaPago;
    cout << "Cantidad: "<< endl;
    cout << _cantidad;
    cout << "Importe total: "<< endl;
    cout << _importeTotal;
    cout << endl;

}

#endif // COMPRAS_H_INCLUDED
