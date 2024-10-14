#include <iostream>
#include <cstring>
#include <stdio.h>

using namespace std;

// Las estructuras dinamicas estan conformadas porr punteros y por nodos 
// A diferencia de los vectores estas estructuras tienen tamaño variable
// Para esto se les va asignando nuevo espacio en la memoria a medida que se lo va necesitando
// Los vectores garantizan que el elemento siguiente esta al lado del seleccionado pero en estas estructuras no
// Aca no podemos garantizar que el siguiente espacio en la memoria sea la continuacion de la estructura
// Ante esto usamos los punteros para direccionar las listas 

// Asignar espacio en la memoria o liberar espacio en la memoria 
// Para esto utilizamos new y delete 
// Estructura del new: int*p = new int(); nodo*p = new nodo();
// Estructura para el delete: delete p;

// Nodos
// Los nodos son structs que contienen dos partes
// La primera parte contiene la informacion que se este utilizando para llenar ese nodo
// La segunda contiene una direccion de memoria que direcciona a otro nodo del mismo tipo 
// Estructura: 
// struct Nodo{
//  int info;  "Parte de la info del nodo"
//  Nodo* sig; "Puntero que apunta a otro nodo"
// }
// En la parte de info le podemos pasar un struct que contenga distintos datos, no se limita a un int 

 
int main(){

}