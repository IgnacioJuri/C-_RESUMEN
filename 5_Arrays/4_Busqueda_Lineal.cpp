#include <iostream>
#include <cstring>
using namespace std;

// La busqueda lineal es un metodo de busqueda dentro de una lista que no tiene requizitos previos
// Recorre la lista viendo si el elemento buscado coincide con el leido 


// Prototipo de funcion buscadorNumeros
int buscadorNumeros(int numeros[], int miNum);

int main(){

    // Array con numeros
    int numeros[5] = {1,2,3,4,5};

    // Numero que queremos buscar
    int miNum = 4;

    // Llamado a la funcion buscadorNumeros
    int buscarNum = buscadorNumeros(numeros, miNum); 

    // If para determinar si se encontro el numero con exito 
    if(buscarNum != -1){

        cout << "El numero "<< miNum << " Esta en la posicion " << buscarNum;
    }else{

        cout << "Error al encontrar el numero";
    }
}

// Funcion buscadorNumeros
int buscadorNumeros(int numeros[], int miNum){

    // Ciclo for para recorrer el array buscando si los elementos son iguales al dato ingresado
    for(int i = 0; i < 5; i++){

        // Se retorna la posicion en la que esta el dato que buscamos
        if( numeros[i] == miNum){

            return i;
        }
    }
    
    // En el caso de que no encuentre el numero, no se haga un return, se ejecuta este return -1
    // Esto no lo ponemos en el for, ya que retornaria -1 si el dato no esta en la posicion 0
    // Nosotrros queremos saber si esta en el arreglo y su posicion, no si esta o no en la 0
    return -1;
}