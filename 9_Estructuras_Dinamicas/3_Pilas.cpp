#include <iostream>
#include <cstring>
#include <stdio.h>

using namespace std;

// Las pilas son estrructuras conformadas por nodos que admiten solo dos operaciones: Poner o Sacar elementos
// El primer elemento que ingresa a la pila sera el ultimo en salir 
// La pila invierte el orden de los elementos

// NO SE PUEDEN RECORRER, LOS ELEMENTOS SE AGREGAN O SE SACAN SOLO ESO

// Struct del nodo
struct Nodo{

    int info;
    Nodo *sgate;
};

// Prototipo de funciones
void push(Nodo *&pila, int valor);
int pop(Nodo *&pila);



int main(){

    // Creo la pila
    Nodo *pila = NULL;

    // Cargar valores en la pila
    int carga;

    cout << "Ingrese un valor o termine con 0" << endl;
    cin >> carga; 

    while( carga != 0 ){

        push(pila, carga);

        cout << "Ingrese un valor o termine con 0" << endl;
        cin >> carga;
    };
    
    // Eliminar nodos de la pila y mostrar su valor
    int resultado;

    while( pila != NULL ){

        resultado = pop(pila);
        cout << resultado <<endl;
    };

    return 0;
};

// Funcion para añadir nodos a la pila
// Se tiene que crear un nuevo nodo al que vamos a cargar con datos y lo vamos a apuntar al nodo siguiente 
// Luego tenemos que apuntar la pila al ultimo elemento, que va a ser el que creamos

// Le paso el struct de Nodo y una variable que va a contener los datos del Nodo 
void push(Nodo *&pila, int valor){

    // Crear nodo y pedir espacio en la memoria
    Nodo *nuevo = new Nodo();
    // Cargar con datos el nodo
    // Le paso los datos que va a tener el campo de info
    nuevo->info = valor; 
    // Le paso el puntero al que debe mirar 
    nuevo->sgate = pila;

    // Conectar nuevo nodo a la pila
    // Le "digo" a la pila que mire al nuevo Nodo, ya que este es el ultimo en la Pila 
    pila = nuevo;
};

// Funcion para quitar nodos de la pila
// Se guarda el valor del nodo en una variable y se crea un nodo auxiliar igual a pila (mira al nodo que borramos)
// A pila se lo direcciona al nodo siguiente al que queremos borrar
// Se elimina el nodo al que mira aux y se retorna su valor
int pop(Nodo *&pila){

    // Guardar el valor que contiene el nodo
    int ret; 
    ret = pila->info;

    // Crear un Nodo auxiliar y cargarle pila
    Nodo *aux = pila;
    // Le digo a pila que mire al nodo siguiente del nodo que se quiere eliminar
    pila = aux->sgate; // pila = pila->sgate; 

    // Se borra el nodo y se retorna el valor que tenia ese nodo
    delete(aux);
    return ret; 
};