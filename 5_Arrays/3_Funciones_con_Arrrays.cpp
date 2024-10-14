#include <iostream>
#include <cstring>
using namespace std;

// Ejemplo de como se usan los arrays junto con las funciones

// Prototipo de la funcion obtenerTotal
int obtenerTotal(int precios[]);

int main(){

    // Array de precios
    int precios[5] = {34, 22, 45, 56, 100};

    // Variable que llama a la Funcion obtenerTotal y le pasa el arrray de precios
    int totalPrecios = obtenerTotal(precios);

    // Imprime el totalPrecios
    cout << totalPrecios;
}

// Funcion obtenerTotal
int obtenerTotal(int precios[]){

    // Variable total
    int total = 0;

    // For para sumar los precios
    for( int i=0; i < 5; i++){

        total = total + precios[i];
    }

    // Retorna los precios sumados
    return total;
}