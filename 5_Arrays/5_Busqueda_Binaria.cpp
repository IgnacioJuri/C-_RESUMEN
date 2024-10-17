#include <iostream>
#include <cstring>

using namespace std;

// La busqueda binaria requiere que la lista este ordenada 
// Se parte la lista en varias partes y se va preguntando si el valor buscado es mayor o menor que la mitad
// Se hace esto varias veces hasta dar con el elemento buscado
// Si el elemento no se encuetra se puede ver en que posciion deberia estar ubicado 
// Es mucho mas eficiente que la busqueda lineal en archivos de gran tamaño
// Cuantos mas elementos tenga una lista mas eficiente se vuelve en comparacion


int main(){

    // Array de numeros
    int numeros[10] = {5,12,20,35,38,55,70,84,99,100};

    // Numero buscado 
    int nuemeroBuscado = 84;

    // Variables que apuntan al inicio y al final del array 
    int izquierda = 0;
    int derecha = sizeof(numeros) -1;

    // Ciclo while que se cotra cuando el int izquierda es mayor que el de la derecha o son iguales
    while (izquierda <= derecha){

        // int que apunta a la mitad del array
        int medio = izquierda + (derecha - izquierda) / 2;

        // Si el medio del array es el numero buscado se lo muestra en consola
        if(numeros[medio] == nuemeroBuscado ){

            cout << numeros[medio]; 
        };

        // Si el numero buscado es mas grande que el medio 
        if(numeros[medio] < nuemeroBuscado){

            // a izquierda lo movemos al medio 
            izquierda = medio + 1;

        // Si el numero buscado es mas chico que el medio
        }else{

            // a derecha lo movemos al medio
            derecha = medio - 1;
        };
    };

    // Esto parte el array a la mitad y va viendo si el resultado buscado es mayor, menor o igual 

    // Ejemplo buscando el 99, cada linea es una ejecucion del while
    // Las variables apuntan a la posicion de memoria no al numero pero pongo el num para ver a quien apuntan


    // Izq = 5 / medio = 38 / der = 100;   
    // {5,12,20,35,38,55,70,84,99,100}

    // izq = 55 / medio = 84 / der = 100
    // {5,12,20,35,38,55,70,84,99,100} 

    // izq = 99 medio = 99 / der = 100
    // {5,12,20,35,38,55,70,84,99,100}

    // Como medio es igual al num buscado el while se corta y se muestra en pantalla el 99 
};