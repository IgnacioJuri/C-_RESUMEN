#include <iostream>
#include <cstring>
#include <stdio.h>
using namespace std;

// Para leer y escribirr archivos al mismo tiempo sin tener que usar rb y wb por separado podemos usar rb+ o wb+

// Rb+ :
// Abre un archivo binario existente para lectura y escritura
// El archivo debe existir; si no existe, la operación de apertura fallará
// Se utiliza cuando necesitas leer y modificar datos en un archivo binario sin perder la información original.
// Leer datos de un archivo binario, modificarlos y escribirlos de nuevo en el mismo archivo.

// Wb+ : 
// Abre un archivo binario para lectura y escritura
// Si el archivo no existe, se crea. Si existe, se trunca (se borra su contenido).
// Se utiliza cuando necesitas crear un nuevo archivo binario o sobrescribir completamente un archivo existente

// Para ambos casos se sigue la misma estructura para completar la tarea 
// 1) Se abre el archivo
// 2) Se lee el archivo
// 3) Se modifica el archivo
// 4) Se cierra el archivo

// Crearr struct de alumnos 
struct alumnos{
    int legajo;
    int dni;
    int nota1;
    int nota2;
};

int main(){

    // Ejemplo de rb+ 
    // Modificamos la nota1 del tercer alumno del archivo

    // Declaracion del Registro Auxiliar
    alumnos raux;

    // Defino el puntero, donde esta mi archivo 
    // Abro el archivo en modo lectura y escritura rb+
    // En los parentesis del fopen va ("direccion del archivo", "rb+") rb+ es el modo de lectura y escritura
    FILE * alum = fopen("Archivo_Alumnos.dat", "rb+");

    // fseek mueve el puntero en la posicion que queramos dentro del archivo
    // En este caso lo movemos a la tercera posicion, [0, 1, 2] el 2 representa la tercera posicion 
    // En el parentesis ponemos (puntero al archivo, N posicion * sizeog(estructura), SEEK_SET) 
    fseek(alum, 2 * sizeof(alumnos), SEEK_SET);

    // Leo el struct del alumno ubicado en la tercera posicion
    fread(&raux, sizeof(struct alumnos), 1, alum);

    // Modifico la nota 
    raux.nota1 = 5;

    // Cargo el archivo modificado al archivo original
    fwrite(&raux, sizeof(alumnos), 1, alum);

    // Cierro el archivo
    fclose(alum);


    // Ejemplo de wb+ 
    // Crear alumnos en un archivo y luego verificar que uno de ellos se haya escrito bien

    // Creamos la variable auxiliar 
    alumnos raux;

    // Defino el puntero que apunta al archivo y que tipo de operacion le voy a hacer, en este caso wb+
    FILE *alum = fopen("Archivo_Alumnos.dat", "wb+");

    // Crear tres registros de alumnos
    alumnos alumno1 = {1, 12345678, 7, 8};
    alumnos alumno2 = {2, 23456789, 6, 9};
    alumnos alumno3 = {3, 34567890, 5, 10};

    // Escribir en el archivo los tres registros
    fwrite(&alumno1, sizeof(alumnos), 1, alum);
    fwrite(&alumno2, sizeof(alumnos), 1, alum);
    fwrite(&alumno3, sizeof(alumnos), 1, alum);

    // Ubico mi puntero en el tercer registro 
    fseek(alum, 2 * sizeof(alumnos), SEEK_SET);

    // Leo los datos del tercer alumno
    fread(&raux, sizeof(alumnos), 1, alum);

    // Cierro el archivo
    fclose(alum);
}