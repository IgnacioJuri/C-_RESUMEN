#include <iostream>
#include <cstring>
using namespace std;
// Para ordenar una lista de numeros de menor a mayor utilizamos un algoritmo
// Vemos si el numero en la posicion siguiente es menor que nuestro numero
// De ser asi, los cambiamos de lugar y repetimos esto con todos los numeros 
// Ejecutamos esto las veces que sea necesario
// Video Explicativo: https://youtu.be/eammCZfvSUM?si=ytwvgvl2FY2uM1HU

// Prototipo de la funcion ordenar lista
void ordenarLista(int lista[]);

int main(){

    // Lista con los numeros
    int lista[10] = {10,3,2,5,9,7,8,1,4,6};

    // Mostrar la lista inicial
    for(int i = 0; i < 10; i++){

        cout << lista[i] << " ";
    }

    cout << endl;

    // Llamado a la funcion ordenarLista
    ordenarLista(lista);

    // Mostrar la lista ya ordenada
    for(int i = 0; i < 10; i++){

        cout << lista[i] << " ";
    }
}

// Funcion ordenarLista
void ordenarLista(int lista[]){

    // Variable para guarrrdar los numeros temporalmente
    int temp;

    // For para ejecutar el algoritmo que "ordena", la cantidad de veces necesaria
    // Lo ejecutamos 9 veces, ya que el ultimo numero no tiene un sucesivo 
    for(int i = 0; i < 10 - 1; i++){
        
        // For para ordenar los numeros
        // Se ejecuta 9 veces por el mismo motivo que antes
        for(int j = 0; j < 10 - 1; j++){

            // If para verificar si el numero sucesivo es menor
            if(lista[j] > lista[j + 1]){

                // Guardo el numero en la varriable temporal
                temp = lista[j];

                // Guardo el numero sucesivo en el anterior, ya que es menor
                lista[j] = lista[j+1];

                // Guardo el numero sucesivo en la posicion inicial
                lista[j + 1] = temp;
            }
        }
    }
}