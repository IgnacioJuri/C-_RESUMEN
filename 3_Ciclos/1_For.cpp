#include <iostream>
using namespace std;

int main(){
    // Los ciclos se usan para repetir varias veces un mismo codigo. 
    // For se usa para repetir un numero de veces fijo el codigo. 
    // Siempre sabemos cuantas veces se va a repetir el ciclo
    // Se pone su inicilizacion, su condicion y su actualizacion. 
    // inicializacion: donde empieza el ciclo.
    // Condicion: que tiene que pasar para que se siga ejecutando.
    // Actualizacion: actualiza la variable de la inicializacion.
    // for (Donde inicia, Que se cumple para que siga, Actualiza la primera parte)
    int i = 0;
    for (i; i < 10; i++){
        cout << i << endl;
    }

    // El for inicia en 0, y cada vez q se ejecuta se le suma 1 a esa variable i
    // Cuando i vale 10 o mas se corta el ciclo.  


}