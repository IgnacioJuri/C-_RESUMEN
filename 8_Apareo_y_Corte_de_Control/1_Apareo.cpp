#include <iostream>
#include <cstring>
#include <stdio.h>

using namespace std; 

// Condiciones para usar apareamiento 

// Pre Condiciones:
// Tener dos o mas archivos 
// Archivos con el mismo tipo de dato
// Tienen que estar orrdenados bajo el mismo criterio, ejemplo:  Ordenados por legajo, id, Dni, etc

// Post condiciones: 
// Integrar los archivos en uno solo

// Ejemplo: Ordenar alumnos de dos archivos distintos en un nuevo archivo ordenandolos de menor a mayor por legajo
// Los archivos existentes ya deben estar ordenados de mayor a menor por legajo 

// Struct de alumno
struct alumno{

    int legajo;
    int dni;
    int nota1;
    int nota2;
};

int main(){

    //  Punteros a los 3 archivos, A y B tienen a los alumnos, C es el nuevo archivo
    FILE* A = fopen("ArchivoA.dat", "wb");
    FILE* B = fopen("ArchivoB.dat", "rb");
    FILE* C = fopen("ArchivoC.dat", "wb");

    // Variables auxiliares
    alumno rauxA;
    alumno rauxB;

    // Leer los dos archivos, A y B
    fread(&rauxA,sizeof(struct alumno), 1, A);
    fread(&rauxB,sizeof(struct alumno), 1, B);

    // Creo un while que pare cuando se llega al final de alguno de los dos archivos
    while( (!feof(A)) && (!feof(B)) ){

        // Si el legajo del alumno leido del archivo A es mas chico que el del archivo B: 
        if( rauxA.legajo > rauxB.legajo ){

            // Escribo en el archivo C el alumno del archivo A
            fwrite(&rauxA, sizeof(struct alumno), 1, C);
            // Leo nuevamente el archivo A para que rauxA ahora tenga un nuevo alumno
            fread(&rauxA,sizeof(struct alumno), 1, A);

        // En el caso en el que el legajo del alumno B sea mas chico que A:
        }else{

            // Escribo en el archivo C el alumno del archivo B 
            fwrite(&rauxB, sizeof(struct alumno), 1, C);
            // Leo nuevamente el archivo B para que rauxB tenga un nuevo alumno
            fread(&rauxB, sizeof(struct alumno), 1, B);
        };
    };

    // Cuando salgo de este while significa que uno de los dos archivos A o B se quedaron sin alumnos
    // Ante esto podemos cargar a C todos los alumnos que quedan en el archivo que sigue teniendo alumnos

    // Si el archivo B se queda sin alumnos se ejecuta este codigo que carga a C los alumnos que quedan en A 
    while(!feof(A)){

        fwrite(&rauxA, sizeof(struct alumno), 1, C);
        fread(&rauxA,sizeof(struct alumno), 1, A);
    };

    // Si el archivo A se queda sin alumnos se ejecuta este codigo que carga a C los alumnos que quedan en B
    while(!feof(B)){

        fwrite(&rauxB, sizeof(struct alumno), 1, C);
        fread(&rauxB, sizeof(struct alumno), 1, B);        
    };

    // Cerramos los archivos usados 
    fclose(A);
    fclose(B); 
    fclose(C);

    // Este algoritmo lee los dos archivos y guarda lo que leen en una variable auxiliar A y B
    // Se comparan estas dos variables y se guarda una de ellas en el archivo C
    // El archivo del cual se acaba de guardar el dato se vuelve a leer y se repite el proceso
    // Cuando uno de los dos archivos queda vacio se agrega todo el contenido del archivo que aun tiene contenido a C
}