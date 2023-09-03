#ifndef ANIMALES_H_INCLUDED
#define ANIMALES_H_INCLUDED
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

class Denominacion{
protected:
    char _nombreCientifico[30], _nombreComun[30], _nombreDadoPuebloOriginario[30];
public:
    void setNombreCientifico(const char *nomCient){strcpy(_nombreCientifico, nomCient);}
    void setNombreComun(const char *nomComun){strcpy(_nombreComun, nomComun);}
    void setNombreDadoPuebloOriginario(const char *nomPuebOrig){strcpy(_nombreDadoPuebloOriginario, nomPuebOrig);}

    const char *getNombreCientifico(){return _nombreCientifico;}
    const char *getNombreComun(){return _nombreComun;}
    const char *getNombreDadoPuebloOriginario(){return _nombreDadoPuebloOriginario;}

    void Cargar(){
        cout << "Ingrese el nombre cientifico: ";
        cargarCadena(_nombreCientifico, 29);
        cout << "Ingrese el nombre comun: ";
        cargarCadena(_nombreComun, 29);
        cout << "Ingrese el nombre dado por los pueblos originarios: ";
        cargarCadena(_nombreDadoPuebloOriginario, 29);
        cout << endl;
    }

    void Mostrar(){
        cout << "DENOMINACION: " << endl;
        cout << "Nombre Cientifico: ";
        cout << _nombreCientifico << endl;
        cout << "Nombre Comun: ";
        cout << _nombreComun << endl;
        cout << "Nombre dado por pueblo originario: ";
        cout << _nombreDadoPuebloOriginario << endl;
        cout << endl;
    }


    Denominacion(){
        setNombreCientifico(strcpy(_nombreCientifico, ""));
        setNombreComun(strcpy(_nombreComun, ""));
        setNombreDadoPuebloOriginario(strcpy(_nombreDadoPuebloOriginario, ""));
    }

};

class Dimension{
protected:
    float _largo, _ancho, _alto;
public:

    void setLargo(int l){_largo = l;}
    void setAncho(int a){_ancho = a;}
    void setAlto(int al){_alto = al;}

    float getLargo(){return _largo;}
    float getAncho(){return _ancho;}
    float getAlto(){return _alto;}

    void Cargar(){
        cout << "Ingrese el largo del animal: ";
        cin >> _largo;
        cout << "Ingrese el ancho del animal: ";
        cin >> _ancho;
        cout << "Ingrese el alto del animal: ";
        cin >> _alto;
        cout << endl;
    }

    void Mostrar(){
        cout << "DIMENSIONES: ";
        cout << "Largo: ";
        cout << _largo << endl;
        cout << "Ancho: ";
        cout << _ancho << endl;
        cout << "Alto: ";
        cout << _alto << endl;
        cout << endl;
    }

    Dimension(){
        setLargo(0);
        setAncho(0);
        setAlto(0);
    }

};

class Animal{
   protected:
        Denominacion _denominacion;
        Dimension _dimension;
        int _tiempoVidaPromedio, _poblacionEstimada;
        float _peso;
        char _zonaHabitatPrincipal[20], _tipoAlimentacion[20];
    public:

        void setTiempoVidaPromedio(int tv){_tiempoVidaPromedio = tv;}
        void setPeso(float p){_peso = p;}
        void setZonaHabitatPrincipal(const char *zhp){strcpy(_zonaHabitatPrincipal, zhp);}
        void setTipoAlimentacion(const char *ta){strcpy(_tipoAlimentacion, ta);}
        void setPoblacionEstimada(int pa){_poblacionEstimada = pa;}

        int getTiempoVidaPromedio(){return _tiempoVidaPromedio;}
        float getPeso(){return _peso;}
        const char *getZonaHabitatPrincipal(){return _zonaHabitatPrincipal;}
        const char *getTipoAlimentacion(){return _tipoAlimentacion;}
        int getPoblacionEstimada(){return _poblacionEstimada;}

        void Cargar(){
            cout << "Ingrese la Denominacion: " << endl;
            _denominacion.Cargar();
            cout << "Ingrese el tiempo de vida promedio: ";
            cin >> _tiempoVidaPromedio;
            cout << "Ingrese las dimensiones: " << endl;
            _dimension.Cargar();
            cout << "Ingrese el peso: ";
            cin >> _peso;
            cout << "Ingrese la Zona de Habitat Principal: ";
            cargarCadena(_zonaHabitatPrincipal, 19);
            cout << "Ingrese el tipo de alimentacion: ";
            cargarCadena(_tipoAlimentacion, 19);
            cout << "Ingrese la poblacion estimada: ";
            cin >> _poblacionEstimada;
            cout << endl;
        }

        void Mostrar(){
            _denominacion.Mostrar();
            cout << "Tiempo de vida promedio: ";
            cout << _tiempoVidaPromedio << endl;
            _dimension.Mostrar();
            cout << "Peso: ";
            cout << _peso <<endl;
            cout << "Zona Habitat Principal: ";
            cout << _zonaHabitatPrincipal << endl;
            cout << "Tipo de alimentacion: ";
            cout << _tipoAlimentacion << endl;
            cout << "Poblacion estimada: ";
            cout << _poblacionEstimada << endl;
            cout << endl;
        }

        Animal(){
            Denominacion();
            setTiempoVidaPromedio(0);
            Dimension();
            setPeso(0);
            setZonaHabitatPrincipal(strcpy(_zonaHabitatPrincipal, ""));
            setTipoAlimentacion(strcpy(_tipoAlimentacion, ""));
            setPoblacionEstimada(0);
        }

};

class Pez : public Animal{
private:
    Animal _pescadito;
    char _color[10];
    char _sonido[10];
public:
    void setColor(const char *col){strcpy(_color, col);}
    void setSonido(const char *son){strcpy(_sonido, son);}

    const char *getColor(){return _color;}
    const char *getSonido(){return _sonido;}

    void Cargar(){
        cout << "CARGAR PEZ: " << endl;
        _pescadito.Cargar();
        cout << "Ingrese el color: ";
        cargarCadena(_color, 9);
        cout << "Que sonido hace?: ";
        cargarCadena(_sonido, 9);
    }
    void Mostrar(){
        cout << "Mostrar Pez: " << endl;
        _pescadito.Mostrar();
        cout << "Color: ";
        cout << _color << endl;
        cout << "Sonido: ";
        cout << _sonido << endl;

    }

};

class Anfibio : public Animal{
private:
    Animal _anfibio;
    char _color[10];

char _sonido[10];
public:

    void setColor(const char *col){strcpy(_color, col);}
    void setSonido(const char *son){strcpy(_sonido, son);}

    const char *getColor(){return _color;}
    const char *getSonido(){return _sonido;}


    void Cargar(){
        cout << "CARGAR ANFIBIO: " << endl;
        _anfibio.Cargar();
        cout << "Ingrese el color: ";
        cargarCadena(_color, 9);
        cout << "Que sonido hace?: ";
        cargarCadena(_sonido, 9);
    }
    void Mostrar(){
        cout << "Mostrar Anfibio: " << endl;
        _anfibio.Mostrar();
        cout << _color << endl;
        cout << "Sonido: ";
        cout << _sonido << endl;

    }

};

class Mamifero : public Animal{
protected:
    Animal _mamifero;
    int _cantidadPatas;
public:
    void Cargar(){
        cout << "CARGAR MAMIFERO: " << endl;
        _mamifero.Cargar();
        cout << "Ingrese la cantidad de patas: ";
        cin >> _cantidadPatas;
    }
    void Mostrar(){
        cout << "Mostrar Mamifero: " << endl;
        _mamifero.Mostrar();
        cout << "Cantidad de Patas: ";
        cout << _cantidadPatas << endl;
    }

};

class Ave : public Animal{
private:

public:

};

class Reptil : public Animal{
private:

public:

};

class Terrestre : public Mamifero{
private:
    Mamifero _terrestre;
    char _color[10];
    char _sonido[10];
public:

    void setColor(const char *col){strcpy(_color, col);}
    void setSonido(const char *son){strcpy(_sonido, son);}

    const char *getColor(){return _color;}
    const char *getSonido(){return _sonido;}

    void Cargar(){
        cout << "CARGAR MAMIFERO TERRESTRE: " << endl;
        _terrestre.Cargar();
        cout << "Ingrese el color: ";
        cargarCadena(_color, 9);
        cout << "Que sonido hace?: ";
        cargarCadena(_sonido, 9);
    }
    void Mostrar(){
        cout << "Mostrar Mamifero Terrestre: " << endl;
        _terrestre.Mostrar();
        cout << "Color: ";
        cout << _color << endl;
        cout << "Sonido: ";
        cout << _sonido << endl;
    }



};

class Marino : public Mamifero{
private:
    Mamifero _marino;
    char _color[10];
    char _sonido[10];
public:

    void setColor(const char *col){strcpy(_color, col);}
    void setSonido(const char *son){strcpy(_sonido, son);}

    const char *getColor(){return _color;}
    const char *getSonido(){return _sonido;}


    void Cargar(){
        cout << "CARGAR MAMIFERO MARINO: " << endl;
        _marino.Cargar();
        cout << "Ingrese el color: ";
        cargarCadena(_color, 9);
        cout << "Que sonido hace?: ";
        cargarCadena(_sonido, 9);
    }
    void Mostrar(){
        cout << "Mostrar Mamifero Marino: " << endl;
        _marino.Mostrar();
        cout << "Color: ";
        cout << _color << endl;
        cout << "Sonido: ";
        cout << _sonido << endl;
    }

};


#endif // ANIMALES_H_INCLUDED
