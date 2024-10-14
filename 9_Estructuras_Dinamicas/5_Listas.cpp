#include <iostream>
#include <cstring>
#include <stdio.h>

using namespace std;

// Las listas funcionan como los arrays pero los distintos elementos no tienen posiciones
// Para identifiacar al siguiente se utiliza un puntero que apunta al siguiente 
// Existe un solo puntero que apunta al inicio de la lista que se utiliza para recorrerla y leer el contenido

// Struct del nodo
struct nodo{
    
    int info;
    nodo *siguiente;
};

void agregarPrimero(nodo *&lista, int dato);
int eliminarPrimero( nodo *&lista );
void mostrarNodoLista(nodo *lista);
void liberarMemoria(nodo *&lista);
void insertarOrdeando( nodo *&lista, int valor);
nodo *buscar(nodo *lista, int valor);


void agregarPrimero(nodo *&lista, int dato){

    // Se agrega al inicio de la lista un nuevo elemento

    // Se pide espacio en la memoria 
    nodo *nuevo = new nodo();

    // Cargo el nuevo nodo con la informacion 
    nuevo->info = dato;

    // Apunto el nuevo nodo a donde apunta la lista, que es el primer elemento antes de agregar el nuevo
    nuevo->siguiente = lista;

    // Apunta lista al nuevo elemento, ya que se agrega al inicio de la lista 
    lista = nuevo;
};

int eliminarPrimero( nodo *&lista ){

    // Eliminar el primer nodo de la lista

    // Crear una variable y cargarla con la info del nodo
    int ret;
    ret = lista->info;

    // Crear un aux que apunte al principio de la lista
    nodo *aux = lista;

    // Mover el puntero de lista al sioguiente nodo, ya que el primero va a ser eliminado
    lista = aux->siguiente;

    // Eliminar el primer nodo que es al que apunta aux
    delete(aux);
    // Retornar el contenido del nodo eliminado
    return ret;
};

void mostrarNodoLista(nodo *lista){

    // Mostrarr el contenido de la lista sin eliminar los nodos

    // El puntero al inicio de la lista se pasa por valor, no por referencia
    // Esto es para no moverlo por accidente y perder al primer nodo de la lista
    // Como otra medida de seguridad no se mueve el puntero de lista, se usa una variable auxiliar

    // Crear un nodo auxiliar
    nodo *aux = lista;

    // Un while que se repite mientras que el puntero aux no sea NULL
    while(aux != NULL){

        // Mostrar la info
        cout << aux->info << endl;
        // Apuntar al siguiente en la lista
        aux = aux->siguiente;
    };
};

void liberarMemoria(nodo *&lista){

    // Se elimina la lista de memoria parra cuando ya no vmos a utilizarla 

    // Declarar un puntero auxiliar
    nodo *aux;

    // Un While que corta cuando lista apunta a NULL, que significa que no quedan elementos cargados en la lista
    while(lista != NULL){

        // A aux lo apunto a donde mira lista
        aux = lista; 
        // Lista mira al siguiente en la lista
        lista = lista->siguiente;
        // Se borra a quien apunta aux, que es quien este en ese momento primero en la lista
        delete(aux);
    };
};

void insertarOrdeando( nodo *&lista, int valor){

    // Creo el nuevo nodo y pido memoria para el
    nodo *nuevo = new nodo();

    // Cargo el nuevo nodo con el valor y lo apunto a NULL pq no se donde va a estar ubicado 
    nuevo->info = valor;
    nuevo->siguiente = NULL;

    // Creo mi nodo auxiliar para no usar lista 
    nodo *aux = lista;
    // Creo otro nodo auxiliarr para marcar el elemento anterior a la hora de recorrer la lista
    nodo *anterior = NULL;

    // Mientras que la lista no llegue a fu final y mientras que el valor que quiero agregar no sea mayor al leido
    while(aux != NULL && aux->info < valor){

        // Cargo a anterior lo que miraba aux a lahora de entrar al while 
        anterior = aux; 
        // Apunto aux a el siguiente nodo
        aux = aux->siguiente;
    };

    // Una vez encontrada la posicion en la lista se ejecuta el if

    // Si el anterior era null significa que el nuevo nodo va al inicio o la lista estaba vacia
    if(anterior == NULL){

        // Apunto lista al nuevo nodo, ya que es el primero de la lista
        lista = nuevo;

    // Si el nodo va ubicado al final de la lista o en el medio se ejecuta este codigo
    }else{
        
        // El puntero anterior apunta al nuevo nodo
        anterior->siguiente = nuevo;
    };

    // Se apunta el nuevo nodo al auxiliar
    // Si se da el primer caso apuntara al inicio de la lista o a null si esta vacia
    // Si se da el segundo apuntara al nodo siguiente ordenado por el criterio que queramos o a NULL si es el ultimo
    nuevo->siguiente = aux;

};

nodo *buscar(nodo *lista, int valor){

    // Nodo auxiliar para no usar el puntero lista para recorrer la lista
    nodo *aux = lista;

    // Corta cuando termina la lista o cuando encuentra el valor que estamos buscando
    while( aux != NULL && aux->info != valor){

        // Aux pasa a mirar al siguiente nodo
        aux = aux->siguiente;
    };

    // Retorna aux, si encontro el nodo nos retorna el puntero a el, si no encuentra nada retorna NULL
    return aux;
};

int main(){
    nodo *lista = NULL;

    insertarOrdeando(lista, 5);
    insertarOrdeando(lista, 2);
    insertarOrdeando(lista, 33);
    insertarOrdeando(lista, 1);
    insertarOrdeando(lista, 0);
    
    mostrarNodoLista(lista);
    return 0;
};