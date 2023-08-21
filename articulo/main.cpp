#include <iostream>
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
        void MostrarC(int n, int mayor);

        void setCodigo(char *codigo){
            strcpy(vCodigo, codigo);
        }
        void setDescripcion(char *descripcion){
            strcpy(vDescripcion, descripcion);
        }
        void setPrecio(float precio){
            _precio = precio;
        }
        void setStock(int stock){
            _stock = stock;
        }
        void setEstado(bool estado){
            _estado = estado;
        }

        char* getCodigo(){
            return vCodigo;
        }
        char* getDescripcion(){
            return vDescripcion;
        }
        float getPrecio(){
            return _precio;
        }
        int getStock(){
            return _stock;
        }
        bool getEstado(){
            return _estado;
        }


        Articulo(){
            *vCodigo={};
            *vDescripcion={};
            setPrecio(0);
            setStock(0);
            setEstado(false);
        }

        Articulo(char *descripcion){
            vDescripcion[30] = *descripcion;
        }


        void cargarCadena(char *palabra, int tamano){
            int i=0;
            fflush(stdin);
            for (i=0; i<tamano; i++){
                palabra[i]=cin.get();
                if (palabra[i]=='\n'){
                    break;
                }
            }
            palabra[i]='\0';
            fflush(stdin);

}

};





void Articulo::Cargar(){
    char codigo[5], descripcion[30];
    float precio;
    bool estado;
    int stock;

        cout << "Ingrese el codigo: ";
        cargarCadena(codigo, 5);
        setCodigo(codigo);

        cout << "Ingrese la descripcion: ";
        cargarCadena(descripcion, 30);
        setDescripcion(descripcion);

        cout << "Precio: $ ";
        cin >> precio;
        setPrecio(precio);

        cout << "Stock: ";
        cin >> stock;
        setStock(stock);

        cout << "Estado: ";
        cin >> estado;
        setEstado(estado);
}


void Articulo::Mostrar(){
    cout << endl;
    cout << "Codigo: " << getCodigo() << endl;
    cout << "Descripcion: " << getDescripcion() << endl;
    cout << "Precio: " << getPrecio() << endl;
    cout << "Stock: " << getStock() << endl;
    cout << "Estado: " << getEstado() << endl;
}

void Articulo::MostrarC(int n, int mayor){
    if(getPrecio() > mayor){
        cout << "Listado de articulos mayores al precio de referencia: " << endl;
        cout << "Articulo # " << n << endl;
        cout << "Codigo: " << getCodigo() << endl;
        cout << "Descripcion: " << getDescripcion() << endl;
        cout << "Precio: " << getPrecio() << endl;
        cout << "Stock: " << getStock() << endl;
        cout << "Estado: " << getEstado() << endl;
    }
}

/// Punto A
void CargarVectorArticulos(Articulo *vArticulos){
    for(int x=0; x<10; x++){
        cout << "Articulo # " << x+1 << endl;
        vArticulos[x].Cargar();
    }
}

/// Punto B
void MostrarArticulos(Articulo *vArticulos){
    cout << " ------- LISTADO DE ARTICULOS -------- " << endl;
    for(int x=0; x<10; x++){
        vArticulos[x].Mostrar();
    }
}

/// Punto C

void MostrarArticulosMayorAReferencia(Articulo *vArticulos){
    int valorReferencia;
    cout << "Listar los articulos cuyo valor sea mayor a: " << endl;
    cin >> valorReferencia;
    for(int x=0; x<10; x++){
        vArticulos[x].MostrarC((x+1), valorReferencia);
    }
}

/// Punto D

void puntoD(Articulo *vArticulos){
    char codComparar[5];
    int con=0;
    cout << "Ingrese un codigo de articulo para devolver su posicion: " << endl;
    cin >> codComparar;

    for(int x=0; x<10; x++){
        if(strcmp(vArticulos[x].getCodigo(), codComparar) == 0){
            cout << "El articulo # " << x+1 << ", esta en la posicion " << x << " y contiene ese codigo." << endl;
        }else{
            con++;
        }
    }
    if(con == 10){
        cout << "-1" << endl;
    }

}


/// Punto E

void puntoE(Articulo *vArticulos){
     char codComparar[5];
     int con=0;
     cout << "Ingrese un codigo de articulo para devolver su posicion: " << endl;
     cin >> codComparar;

     for(int x=0; x<10; x++){
         if(strcmp(vArticulos[x].getCodigo(), codComparar) == 0){
             vArticulos[x].Mostrar();
         }else{
             con++;
         }
     }
     if(con == 10){
         Articulo puntE;
         puntE.setStock(-1);
         puntE.Mostrar();
     }
}

/// Punto F

void puntoF(Articulo *vArticulos){
    int stockReferencia;
    int conStock=0;
    cout << "Ingrese un valor de Stock de referencia: " << endl;
    cin >> stockReferencia;

    for(int x=0; x<10; x++){
        if(stockReferencia > vArticulos[x].getStock()){
            conStock++;
        }
    }
    cout << "Hay: " << conStock << " articulos con stock inferior a: " << stockReferencia << "." << endl;
}

/// Punto G

void puntoG(Articulo *vArticulos){
    float porcIncrementoPrecio, porcAplicar, d;
    cout << "Ingrese un porcentaje para incrementar todos los precios de los articulos: " << endl;
    cin >> porcIncrementoPrecio;
    porcAplicar = (porcIncrementoPrecio+100)/100;

    for(int x=0; x<10; x++){
        d=vArticulos[x].getPrecio()*porcAplicar;
        vArticulos[x].setPrecio(d);
    }
    cout << "Articulos con precio actualizado con aumento del: " << porcIncrementoPrecio << " %" << endl;
    for (int x=0; x<10; x++){
        vArticulos[x].Mostrar();
    }
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


int main()
{
    Articulo vArticulos[10];

    bool corteMenu = true;
    int opcion;

    while(corteMenu == true){
        Menu();
        cin >> opcion;

        switch(opcion){
        case 1:
            CargarVectorArticulos(vArticulos);
            break;
        case 2:
            MostrarArticulos(vArticulos);
            break;
        case 3:
            MostrarArticulosMayorAReferencia(vArticulos);
            break;
        case 4:
            puntoD(vArticulos);
            break;
        case 5:
            puntoE(vArticulos);
            break;
        case 6:
            puntoF(vArticulos);
            break;
        case 7:
            puntoG(vArticulos);
            break;
        case 0:
            corteMenu = false;
            break;
        }

    }

    return 0;
}
