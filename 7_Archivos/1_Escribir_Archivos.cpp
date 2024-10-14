#include <iostream>
#include <cstring>
#include <stdio.h>
using namespace std;

// Los archivos los usamos para almacenar datos en la memoria
// Podemos ver donde se almacenan y no se borran cuando el programa termina su ejecucion
// Para poder manejar archivos utilizamos la libreria stdio.h
// Para crer un archivo y escribir sobre el seguimos 4 pasos
// 1) Definir el puntero
// 2) Abrir el archivo - crear el archivo y escribir 
// 3) Cargar el archivo 
// 4) Cerrar el archivo

// Creo el struct de alumnos
struct alumnos{
    int legajo;
    int dni;
    int nota1;
    int nota2;
};

int main(){

    // Declaro el Registro Auxiliar
    alumnos raux;

    // Defino el puntero
    FILE * alum;

    // Abro o creo el archivo en modo escritura
    // en el fopen va: ("Direccion del archivo", "wb"), wb es el modo escritura
    alum = fopen("Archivo_Alumnos.dat", "wb");

    // Pido que se ingrese un numero de legajo para mi variable auxiliar
    cout << "Ingresar numero de legajo o escribir 0 para terrminar" << endl;
    cin >> raux.legajo;

    // Creo un while que crea alumnos hasta que un legajo sea 0
    while(raux.legajo != 0){

        cout << "Ingresar el dni: " << endl;
        cin >> raux.dni;
        cout << "Ingresar la nota 1: " << endl;
        cin >> raux.nota1;
        cout << "Ingresar la nota 2: " << endl;
        cin >> raux.nota2;

        //  Escribir en el archivo lo cargado
        // Se usa la funcion fwrite que dentro tiene:
        // (Registro auxiliar, Tamaño del tipo de dato, Cantidad de bloques de escritura, Puntero)
        fwrite(&raux, sizeof(struct alumnos), 1, alum);
        
        // Se pide otro numero de legajo para que el while no sea infinito
        cout << "Ingresar numero de legajo o escribir 0 para terrminar" << endl;
        cin >> raux.legajo;
    }

    // Se cierra el archivo
    fclose(alum);

}


