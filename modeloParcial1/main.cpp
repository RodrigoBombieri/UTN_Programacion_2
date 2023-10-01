#include <iostream>
#include <cstring>

using namespace std;
#include "parcialm1.h"

void punto1();
void punto2();
void puntoA1();
void puntoA2();
void puntoA3();
void puntoA4();
void puntoA5();
void puntoA6();
void puntoA7();


int main()
{
    //punto1();
    //punto2();
    //puntoA1();
    //puntoA2();
    //puntoA3();
    //puntoA4();
    puntoA5();
    //puntoA6();
    //puntoA7();


    cout << endl;
    system("pause");
    return 0;
}

/// PUNTO 1
/// Generar un archivo con el codigo de obra, la direccion y la provincia,
/// de las obras cuyo estado de ejecucion sea "en ejecucion".

class ObraEnEjecucion
{
private:
    char codigoObra[5];
    char direccion[30];
    int provincia;
    bool activo;
public:
    void setCodigoObra(const char *co)
    {
        strcpy(codigoObra,co);
    }
    void setDireccion(const char *d)
    {
        strcpy(direccion,d);
    }
    void setProvincia(int p)
    {
        provincia=p;
    }
    void setActivo(bool e)
    {
        activo=e;
    }
};

bool grabarObraEnEjecucion(ObraEnEjecucion aux)
{
    FILE *p;
    p=fopen("obrasEjecucion.dat", "ab");
    if(p==NULL)
    {
        cout << "Error de archivo."<<endl;
        return false;
    }
    bool escribio = fwrite(&aux, sizeof aux,1,p);
    fclose(p);
    return escribio;
}


void punto1()
{
    Obra reg;
    /// llamo al constructor de archi obras
    ArchivoObras archiObras("obras.dat");
    /// creo una instancia del objeto que cree, para utilizar como auxiliar en el archivo
    ObraEnEjecucion aux;
    /// llamo a la funcion de contar registros, y lo guardo en una variable para utilizarlo
    int cantReg = archiObras.contarRegistros();
    int i;
    /// lee registro a registro el archivo de obras
    for(i=0; i<cantReg; i++)
    {
        reg=archiObras.leerRegistro(i);
        /// por cada registro ve si el estado de ejecucion es el 3 y esta activo
        if(reg.getEstadoEjecucion()==3 && reg.getActivo())
        {
            /// si es verdadero, copia los campos correspondientes en una variable de memoria
            /// que tenga lo que se definio para el archivo nuevo.
            aux.setCodigoObra(reg.getCodigoObra());
            aux.setDireccion(reg.getDireccion());
            aux.setProvincia(reg.getProvincia());
            aux.setActivo(true);
            /// grabar el registro en el archivo nuevo.
            if(grabarObraEnEjecucion(aux)==false)
            {
                cout << "Error en la creacion del archivo nuevo."<<endl;
                return;
            }
        }
        ///si no ignora ese registro y continua con la lectura.
    }

}

/// PUNTO 2
///La provincia con menos proveedores
/// (ignorando las provincias sin proveedores).

int buscarMinimo(Proveedor prov, int *v, int tam)
{

    int bmin = 0, provMin = 0,provinciaMin;
    for(int i = 0; i < tam; i++) {
        if (bmin == 0) {
            provMin = v[i];
            provinciaMin = prov.getProvincia();
            bmin = 1;
        } else if (v[i]< provMin) {
            provMin = v[i];
            provinciaMin = prov.getProvincia();
        }
    }
    return provinciaMin;
}

void punto2()
{
    Proveedor reg;
    ArchivoProveedor archiProv("proveedores.dat");
    int cantReg = archiProv.contarRegistros();
    int i;
    int vProv[24]={0};
    for(i=0; i<cantReg; i++)
    {
        reg=archiProv.leerRegistro(i);

        vProv[reg.getProvincia()-1]++;
    }

    int posMin = buscarMinimo(reg, vProv, 24);
    cout << "La provincia con menos proveedores es la: " << posMin <<endl;
}

/// Preguntas adicionales de práctica:
/// a1) Para cada material la cantidad de compras que se hayan realizado entre todas las compras.

void puntoA1()
{
    Compra com;
    ArchivoCompra archiCom("compras.dat");
    int cantCom = archiCom.contarRegistros();

    Material mat;
    ArchivoMaterial archiMat("materiales.dat");
    int cantMat = archiMat.contarRegistros();

    for(int i=0; i<cantMat; i++){
        mat = archiMat.leerRegistro(i);
        int con=0;
        for(int j=0; j<cantCom; j++){
            com=archiCom.leerRegistro(j);
            if(mat.getCodigoMaterial() == com.getCodigoMaterial()){
                con++;
            }
        }
        if(con!=0){
            cout << "El material #: " << mat.getCodigoMaterial() << " tuvo " << con << " compras." << endl;
        }
    }

}

/// a2) El nombre del proveedor que mayor importe haya obtenido entre todas las compras que se le realizaron.


void puntoA2(){
    float mayorImporte=0;
    int bmax=0;
    char nombre[30];

    Compra com;
    ArchivoCompra archiCom("compras.dat");
    int cantCom = archiCom.contarRegistros();

    Proveedor prov;
    ArchivoProveedor archiProv("proveedores.dat");
    int cantProv = archiProv.contarRegistros();

    for(int i=0; i<cantProv; i++){
        prov=archiProv.leerRegistro(i);

        for(int j=0; j<cantCom; j++){
            com=archiCom.leerRegistro(j);
            if(prov.getNumeroProveedor()== com.getNumeroproveedor()){
                if(bmax==0){
                    mayorImporte = com.getImporte();
                    strcpy(nombre, prov.getNombre());
                    bmax=1;
                }else if(com.getImporte()>mayorImporte){
                    mayorImporte = com.getImporte();
                    strcpy(nombre, prov.getNombre());
                }
            }
        }
    }

    cout << "El mayor importe fue de: $ " << mayorImporte << endl;
    cout << "El nombre del proveedor: " << nombre << endl;
}


/// a3) Los número de los proveedores a los que no se les compró nada el año pasado.

void puntoA3(){
    int provSinCompra;
    float importe;
    Compra com;
    ArchivoCompra archiCom("compras.dat");
    int cantCom = archiCom.contarRegistros();

    Proveedor prov;
    ArchivoProveedor archiProv("proveedores.dat");
    int cantProv = archiProv.contarRegistros();

    for(int i=1; i<cantProv; i++){
        prov=archiProv.leerRegistro(i);
        int con=0;
        for(int j=1; j<cantCom; j++){
            com=archiCom.leerRegistro(j);

            if(prov.getNumeroProveedor() == com.getNumeroproveedor()){
                if(com.getImporte()>0){
                con++;
                }
            }

        }
            if(con==0){
                cout << "El proveedor #" << prov.getNumeroProveedor() << " no tuvo compras el anio pasado." << endl;

        }

    }
}


/// a4) El gasto en obra gruesa para cada uno de las obras.
/// (analizar bien. Es el punto más complejo porque requiere del uso de 3 archivos)

void puntoA4(){
    float gastoTotal;

    Obra obra;
    ArchivoObras archiObra("obras.dat");
    int cantObras = archiObra.contarRegistros();

    Compra com;
    ArchivoCompra archiCompra("compras.dat");
    int cantCompra = archiCompra.contarRegistros();

    Material mat;
    ArchivoMaterial archiMat("materiales.dat");
    int cantMat = archiMat.contarRegistros();


    for(int i=0; i<cantObras; i++){
        obra = archiObra.leerRegistro(i);
        gastoTotal = 0;
        for(int j=0; j<cantCompra; j++){
            com = archiCompra.leerRegistro(j);
            if(strcmp(obra.getCodigoObra(), com.getCodigoObra()) == 0){
                for(int k=0; k<cantMat; k++){
                    mat = archiMat.leerRegistro(k);
                    if(com.getCodigoMaterial()==mat.getCodigoMaterial()){
                        if(mat.getTipo()==1){
                            gastoTotal+=com.getCantidad()*mat.getPU();

                        }

                    }
                }
            }

        }

        cout << "La obra #" << obra.getCodigoObra() << " tuvo de gastos: $ " << gastoTotal << endl;
    }

}


/// a5) La/s provincia/s con más de 22 proveedores

void puntoA5(){
}

/// a6) Dar de baja lógica a todas las compras del año 2020.

void puntoA6(){
}
/// a7) Modificar el precio de las aberturas en el archivo de materiales. Incrementar un 10% todos los materiales de ese tipo.

void puntoA7(){
}
