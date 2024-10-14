// Una empresa de venta de muebles decide pagar un bono a los empleados que mas ventas han tenido en el último año. Para ello cuenta con un archivo de empleados (son 100): id de empleado y nombre, y un archivo de ventas: id de vendedor, mes de venta (son todas del mismo año, hay datos de los 12 meses y no importa el día), importe total vendido en ese mes.
// Para dicho reconocimiento abonará 10% a los primeros 5, 7% a los siguientes 5, 5% a los siguientes 5 y 3% al resto de los empleados.
// Se le pide entonces que desarrolle una función que dados los dos archivos emita un listado ordenado por importe de ventas con el nombre de los empleados, el total vendido por cada uno y el extra a abonar en concepto de bonificación.


#include <iostream>
#include <cstring>
using namespace std;

// Structs

struct empleado{

    int idEmpleado;
    char nombre[20 + 1];
};

struct venta{

    int idVendedor;
    int mesVenta;
    float totalMes;
    // float totalAnual = 0;
};

struct gordito{

    int idEmpleado;
    char nombre [20 + 1];
    float totalAnual = 0;
    float extra = 0;
};

// Prototipo Funciones

void leerEmpleado( empleado empleados[]);
void leerVenta( venta ventas[]);
void crearGorditos(gordito gorditos[], empleado empleados[], venta ventas[]);
void ordenarGorditos(gordito gorditos[]);
void bonificarGorditos(gordito gorditos[]);
void imprimirGorditos(gordito gorditos[]);

int main(){

    empleado empleados[100];
    venta ventas[1200];
    gordito gorditos[100];

    leerEmpleado(empleados);
    leerVenta(ventas);
    crearGorditos(gorditos, empleados, ventas);
    ordenarGorditos(gorditos);
    bonificarGorditos(gorditos);
    imprimirGorditos(gorditos);

}

void leerEmpleado( empleado empleados[]){

    empleado raux;

    FILE * emp = fopen("Archivo_Empleados.dat", "rb");
    
    fread(&raux ,sizeof(empleado) ,1 ,emp);

    int i= 0;

    while(!feof(emp)){

        empleados[i].idEmpleado = raux.idEmpleado;
        strcpy(empleados[i].nombre, raux.nombre);

        i++;

        fread(&raux ,sizeof(empleado) ,1 ,emp);
    }

    fclose(emp);
}

void leerVenta( venta ventas[]){

    venta raux;

    FILE * vent = fopen("Archivo_Ventas.dat", "rb");
    
    fread(&raux ,sizeof(venta) ,1 ,vent);

    int i= 0;

    while(!feof(vent)){

        ventas[i].idVendedor = raux.idVendedor;
        ventas[i].mesVenta = raux.mesVenta;
        ventas[i].totalMes = raux.totalMes;
    
        i++;

        fread(&raux ,sizeof(venta) ,1 ,vent);
    }

    fclose(vent);
}

void crearGorditos(gordito gorditos[], empleado empleados[], venta ventas[]){

    for(int i=0; i <100; i++){

        float contador = 0;
        for(int j =0; j<1200; j++){

            if(i == ventas[j].idVendedor){

                contador += ventas[j].totalMes;
            }
        }

        gorditos[i].totalAnual = contador;  
        gorditos[i].idEmpleado = i;
        strcpy(gorditos[i].nombre, empleados[i].nombre);
    }
}

void ordenarGorditos(gordito gorditos[]){

    gordito aux;
    for(int i =0 ; i<100 -1 ; i++){

        for(int j=0; j <100 -1 -i; j++){

            if(gorditos[j].totalAnual < gorditos[j+1].totalAnual){

                aux = gorditos[j];
                gorditos[j] = gorditos[j+1];
                gorditos[j+1] = aux;

            }
        }
    }
}

void bonificarGorditos(gordito gorditos[]){

    for(int i =0; i<5; i++){

        gorditos[i].extra = (gorditos[i].totalAnual *10) / 100; 
    }

    for(int i =5; i<10; i++){

        gorditos[i].extra = (gorditos[i].totalAnual *7) / 100; 
    }

    for(int i =10; i<15; i++){

        gorditos[i].extra = (gorditos[i].totalAnual *5) / 100; 
    }

    for(int i =15; i<100; i++){

        gorditos[i].extra = (gorditos[i].totalAnual *3) / 100; 
    }
}

void imprimirGorditos(gordito gorditos[]){

    for(int i=0; i<100; i++){

        cout << "Nombre: "<< gorditos[i].nombre << endl;
        cout << "Total anual: "<< gorditos[i].totalAnual << endl;
        cout << "Bonificacion:  "<< gorditos[i].extra << endl;

        cout << endl;
    }
}

