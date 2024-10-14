#include <iostream>
#include <cstring>
#include <stdio.h>
using namespace std;

// Para leer archivos tambien necesitamos la libreria stdio.h
// Tenemos que seguir 5 pasos para una lectura de archivos
// 1) definir el puntero del archivo
// 2) Abrir el archivo en modo lectura 
// 3) Leer el archivo
// 4) Utilizar la informacion obtenida
// 5) Cerrar el archivo

// Crear el struct alumnos
struct alumnos{
    int legajo;
    int dni;
    int nota1;
    int nota2;
};

int main(){

    // Declaracion del Registro Auxiliar
    alumnos raux;
    int suma = 0;
    int contador = 0;

    // Defino el puntero, donde esta mi archivo
    FILE * alum;

    // Abro el archivo en modo lectura
    // en los parentesis del fopen va ("direccion del archivo", "rb") rb es el modo de lectura
    alum = fopen("Archivo_Alumnos.dat", "rb");

    // Lectura de mi archivo, dentro del fread va:
    // (Registro auxiliar, Tamaño del tipo de dato, Cantidad de bloques de lectura, Puntero)
    // El registro auxiliar es una variable auxiliar para ir almacenando los datos obtenidos
    fread(&raux, sizeof(struct alumnos), 1, alum);

    // While que verifica que el archivo no haya terminado
    while(!feof(alum)){

        // En cada ciclo while el raux cambia su valor por cada uno de los alumnos que tengo almacenados
        // Hago lo que se me pide con ese dato y el ciclo inicia nuevamente
        // Para este nuevo ciclo el raux toma el valor del alumno siguiente

        // Se suma la nota 1 y la cantidad de notas estas variables 
        suma = suma + raux.nota1;
        contador ++;

        // Demuestro que estoy obteniendo lo que esta en el archivo
        cout << "Registro legajo: " << raux.legajo << endl;
        cout << "Registro dni: " << raux.dni << endl;
        cout << "Registro nota1: " << raux.nota1 << endl;
        cout << "Registro nota2: " << raux.nota2 << endl;
        cout << endl;

        // Leo nuevamente el archivo para que el while continue y no sea infinito
        fread(&raux, sizeof(struct alumnos), 1, alum);
    }

    // Cierro el archivo ni bien termino de usarlo, al terminar el while 
    fclose(alum);

    // Muestro el promedio de notas 1 de mi archivo
    cout <<"Promedio nota 1: " << suma/contador;


}