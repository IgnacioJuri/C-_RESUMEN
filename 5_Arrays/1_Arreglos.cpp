#include <iostream>
#include <cstring>
using namespace std;

// Los Arreglos o Arrays son estructuras de datos que pueden contener multiples valores
// Son una lista de datos del mismo tipo que se almacenan juntos
// Para crearlos se indica tipo de dato + nombre del array + cantidad de datos a guardar + los datos
// Int Numeros[cantidad de datos] = {"1", "2"...};

int main(){
    // Declaro el Array, la cantidad de datos y los datos en si
    int numeros[5] = {1, 2, 3, 4, 5};

    // Muestro el dato que ocupara la posicion 0 en el array
    // Los arrays se ordenan por posiciones, que van desde la 0 a la que sea
    // Como se quiere mostrar el numero 1, y es el primer dato, se encuentra en la posicion 0
    cout << numeros[0];

    // Podemos tambien crear un arreglo e ir cargando sus datos o modificandolos despues
    const char* marcaAutos[5];

    // Modifico los datos en cada posicion
    marcaAutos[0] = "Honda";
    marcaAutos[1] = "Chevrolet";
    marcaAutos[2] = "Ford";

    // Muestro los datos
    cout << marcaAutos[0] << endl;
    cout << marcaAutos[1] << endl;
    cout << marcaAutos[2] << endl;
}