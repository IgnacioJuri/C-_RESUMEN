#include <iostream>
#include <cstring>
using namespace std;

// Las variables locales solo pueden ser utilizadas dentro de la misma estructura en donde son creados
// Las variables globales pueden ser ejecutadas en cualquier parte

// Esta variable puede ser utilizada en todo el codigo al ser declarada fuera del main
int x = 5;

int main(){
    // Llamar a la variable x
    cout << x;

    if(x = 5){
        // Esta variable solo puede ser utilizada dentro del if, ya que fue creada ahi
        int a = 8;
        if(x=5){
            // En este caso puedo utilizar la variable a ya que este segundo if esta dentro del primero
            // La variable a esta declarada en el primer if, por lo que lo puedo utilizar aqui
            cout << a;
        }
    }

    // Al intenar llamar la variable a da error, ya que esta es local 
    // cout << a;
}