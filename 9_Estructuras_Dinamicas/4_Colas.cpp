#include <iostream>
#include <cstring>
#include <stdio.h>

using namespace std;

// Las colas son estructuras compuestas por nodos que se encargan de acomodar estos nodos por orden de llegada
// Los nodos se acomodan de tal forma que el primero en entrar es el primero en salir como la cola del bondi 
// Usamos dos punteros principales, uno mirando al inicio de la cola y otro al final de la cola 

// NO SE PUEDEN RECORRER, LOS ELEMENTOS SE AGREGAN O SE SACAN SOLO ESO

// Struct de nodo
struct nodo{

    int info;
    nodo *siguiente;
};

// Prototipo de funciones
void agregar(nodo *&colaInicio, nodo *&colaFin, int info);
int suprimir(nodo *&colaInicio, nodo *&colaFin);

int main(){

    // Crear punteros de inicio de cola y final de cola 
    nodo *colaInicio = NULL;
    nodo *colaFin = NULL;

    int carga;

    cout << "Ingrese un valor o finalize escribiendo 0: " ;
    cin >> carga;
    cout << endl;

    while(carga != 0){

        agregar(colaInicio, colaFin, carga);
        cout << "Ingrese un valor o finalize escribiendo 0: " ;
        cin >> carga;
        cout << endl;
    };

    int resultado;

    while(colaInicio !=NULL){

        resultado = suprimir(colaInicio, colaFin);
        cout << resultado << endl;
    };

    return 0;
}

// Funcion para agregar elementos a la cola 
void agregar(nodo *&colaInicio, nodo *&colaFin, int info){

    // Pedir espacio a la memoria
    nodo *nuevo = new nodo();

    // Cargar con informacion al nuevo nodo
    nuevo->info = info;
    // Al ser el ultimo en la lista su puntero apunta a NULL
    nuevo->siguiente = NULL;

    // Verifico si la cola tiene elementos cargados 
    if( colaInicio == NULL){
        // Lo que sucede si tiene elementos cargados
        // Como no hay elementos en la lista colaInicio apunta al nuevo nodo
        colaInicio = nuevo;

    // Lo que sucede si la cola tiene elementos cargados 
    }else{

        // Apunta el ultimo de la lista al nuevo elemento 
        colaFin->siguiente = nuevo;
    };

    // Apunta colaFin al nuevo elemento que es el ultimo de la lista 
    colaFin = nuevo;
};

int suprimir(nodo *&colaInicio, nodo *&colaFin){

    // Variable para almacenar la info del nodo a eliminar
    int ret; 
    ret = colaInicio->info;

    // Nodo auxiliar que apunta al inicio de la cola 
    nodo *aux = colaInicio;

    // Se apunta colaInicio al siguiente nodo de la lista, ya que el primer nodo es el nodo a eliminar
    colaInicio = aux->siguiente;

    // Se verifica si la cola esta vacia despues de eliminar el nodo
    if( colaInicio == NULL){

        // Si esta vacia colaInicio y colaFin pasan a apuntar a NULL
        colaFin = NULL;
    };

    // Se borra el primerr nodo de la cola 
    delete(aux);

    // Se retorna la informacion que contenia el nodo eliminado 
    return ret;
};