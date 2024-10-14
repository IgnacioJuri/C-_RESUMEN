#include <iostream>
#include <cstring>
using namespace std;

// Al intentar utilizar una varibale que pertenece al main en una funcion va a dar error
// Para evitar esto tenemos que "Enviar" y "Recivir" la varibale

// Utilizo el prototipo de funcion y le "aviso" que voy a usar ina varriable "nombre" de tipo char
void felizCumpleaños(const char* nombre);

int main(){

    // Creo la variable nombre de tipo char 
    char nombre[10+1] = "Nacho";
    // Llamo a la funcion felizCumpleaños y le digo que va a usar la variable "nombre"
    felizCumpleaños (nombre);
}

// Creo la funcion felizCumpleaños y le digo que al invocarla le va a llegar un dato de tipo char
void felizCumpleaños(const char* nombre){

    // LLamo a la variable nombre que llega desde el main
    cout << "Feliz Cumpleaños " << nombre;
}

// Para usar mas de un dato se pone coma al lado de los primeros datos y se repite el proceso 