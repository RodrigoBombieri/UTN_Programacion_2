#ifndef CATEGORIA_H_INCLUDED
#define CATEGORIA_H_INCLUDED

class Categoria{
private:
    int numeroCategoria;
    char nombreCat[30];
    bool estadoCategoria;
public:
    void setNumeroCategoria(int nm){numeroCategoria = nm;}
    int getNumeroCategoria(){return numeroCategoria;}

    void setNombreCategoria(const char *nom){strcpy(nombreCat,nom);}
    const char *getNombreCategoria(){return nombreCat;}

    void Cargar(){
        cout << "CARGAR CATEGORIA: "<<endl;
        cout << "Ingrese el numero (1 a 80): "<<endl;
        cin >> numeroCategoria;
        cout << "Ingrese el nombre: "<<endl;
        cargarCadena(nombreCat, 29);
        estadoCategoria = true;
        cout << endl;

    }

    void Mostrar(){
        if(estadoCategoria==true){
            cout << "CATEGORIA: "<<endl;
            cout << "Numero: "<<endl;
            cout << numeroCategoria;
            cout << "Nombre: "<<endl;
            cout << nombreCat;
            cout << endl;
        }

    }

};

#endif // CATEGORIA_H_INCLUDED
