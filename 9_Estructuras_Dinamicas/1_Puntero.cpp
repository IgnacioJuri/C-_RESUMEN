#include <iostream>
#include <cstring>
#include <stdio.h>

using namespace std;

// Un puntero es una varaible con un tipo de dato que contiene una direccion de memoria 
// El puntero seria la direccion a la que hay que enviar una carta, no se el contenido de ella pero si adonde mandarla


int main(){

    // a es una variable del tipo int a la cual se le asigna un valor de 10
    int a = 10;

    // p es una variable a la cual le asigno la direccion de memoria en donde se encuentra guardado a 
    // Al int se le tiene que agregar si o si un "*" y la variable a hay que pasarla por referencia, con "&"
    int* p = &a;

    // Mostramos el valor de a, 10
    cout << a << endl;

    // Mostramos el valor de p, "direccion de memoria: 0014547"
    cout << p << endl;

    // Mostramos el contenido de la direccion de memoria donde se guarda la variable a, 10
    // Es lo mismo que poner cout << a; solo que en este caso lo busco por direccion de memoria en vez de por nombre
    // Al poner el * pido que me muestren el contenido de la direccion y sin ella veo solo la direccion
    cout << *p << endl;

};