#ifndef ARTICULO_H_INCLUDED
#define ARTICULO_H_INCLUDED
#include <string.h>
using namespace std;


class Articulo{
    private:
        char vCodigo[5];
        char vDescripcion[30];
        float _precio;
        int _stock;
        bool _estado;
    public:
        void Cargar();
        void Mostrar();
        void Menu();

        void setCodigo(char *codigo);
        void setDescripcion(char *descripcion);
        void setPrecio(float precio);
        void setStock(int stock);
        void setEstado(bool estado);

        char getCodigo();
        char getDescripcion();
        float getPrecio();
        int getStock();
        bool getEstado();

        Articulo();
        Articulo(char *vDescripcion);
};


void Articulo::setCodigo(char *codigo){
    strcpy(vCodigo, codigo);
}
void Articulo::setDescripcion(char *descripcion){
    strcpy(vDescripcion, descripcion);
}
void Articulo::setPrecio(float precio){
    _precio = precio;
}
void Articulo::setStock(int stock){
    _stock = stock;
}
void Articulo::setEstado(bool estado){
    _estado = estado;
}

char Articulo::getCodigo(){
    return *vCodigo;
}
char Articulo::getDescripcion(){
    return *vDescripcion;
}
float Articulo::getPrecio(){
    return _precio;
}
int Articulo::getStock(){
    return _stock;
}
bool Articulo::getEstado(){
    return _estado;
}



void Articulo::Cargar(){

}

void Articulo::Mostrar(){

}

void Menu(){
    cout << "---------------- ARTICULO -----------------------------------------------------------------" << endl;
    cout << "-------------------------------------------------------------------------------------------" << endl;
    cout << " 1 - Cargar vector de 10 articulos                                                         " << endl;
    cout << " 2 - Listar articulos cargados                                                             " << endl;
    cout << " 3 - Articulos con precio mayor a precio de referencia                                     " << endl;
    cout << " 4 - Posicion del objeto que esta en el codigo indicado por parametro                      " << endl;
    cout << " 5 - Devuelve el objeto completo que contiene el codigo                                    " << endl;
    cout << " 6 - Mostrar stock de articulos de valor inferior al recibido                              " << endl;
    cout << " 7 - Modificar el precio de todos los objetos con un % de incremento recibido por parametro" << endl;
    cout << "-------------------------------------------------------------------------------------------" << endl;
    cout << " 0 - Salir.                                                                                " << endl;
}

Articulo::Articulo(){
    *vCodigo={};
    *vDescripcion={};
    setPrecio(0);
    setStock(0);
    setEstado(false);
}


Articulo::Articulo(char *descripcion){
    vDescripcion[30] = *descripcion;
}

#endif // ARTICULO_H_INCLUDED
