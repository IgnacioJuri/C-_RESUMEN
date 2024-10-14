#include <iostream>
using namespace std;
// Los prototipos se usan para usar una funcion antes de declararla.
// Le avisas al compilador que tipo de parametros y que funcion va a recibir.

// Prototipo
// Avisa que habra una funcion que debuelve un tipo de dato int 
// Avisa que su nombre es sumar.
// Avisa que toma dos argumentos de tipo int. 
int sumar(int,int);

int main(){
    // Llamar funcion
    int resultado = sumar(25,5);
    cout << resultado;
}

// Definición de la función
int sumar(int a, int b) {
    return a + b;
}

