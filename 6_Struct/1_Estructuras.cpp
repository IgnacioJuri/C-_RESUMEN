#include <iostream>
#include <cstring>
using namespace std;

// Las estructuras son aquellas que pueden almacenar datos de diferentes tipos
// Se deben declarar fuera de la funcion principal
// Se inicia con la palabra struct y luego se pone un identificador
// Dicho identificador se puede considerar como un nuevo tipo de dato
// Dentro del struct se indica el nombre de las variables que contiene y su tipo de dato

// Crreamos el struct con su identificador o tipo de dato
struct estudiante{
    // Indicamos las variables y su tipo de dato que va a contener
    const char* nombre;
    int nota;
};

int main(){

    // Creamos una variable de tipo "estudiante" y establecemos los valores de sus variables
    estudiante estudiante1;
    estudiante1.nombre = "Nacho";
    estudiante1.nota = 2;

    estudiante estudiante2;
    estudiante2.nombre = "Juan";
    estudiante2.nota = 5;

    // Mostramos las variables estudiante1 y estudiante2 
    cout << "El alumno: " << estudiante1.nombre << " Saco un : " << estudiante1.nota <<endl;
    cout << "El alumno: " << estudiante2.nombre << " Saco un : " << estudiante2.nota <<endl;
}