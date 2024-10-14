#include <iostream>
#include <cstring>
using namespace std;

// Recorremos el array para mostrar todo su contenido, ya queno hay una forma automatica de hacerlo
// Para esto podemos hacer un cout de cada elemeno por separado, que es ineficiente, o con un for

int main(){

    // Crear un array
    const char* alumnos[3] = {"Nacho", "Juan", "Pedro"};

    // Recorrer el array la cantidad de veces que sea necesario, 3 en este caso por el tamaño del array
    for( int i=0; i < 3; i++){

        // Mostrar el dato del array alumnos en la posicion i, que va cambiando hasta llegar a 3
        cout << alumnos[i] << endl;
    }
}