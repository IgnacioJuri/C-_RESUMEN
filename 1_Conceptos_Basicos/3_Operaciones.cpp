#include <iostream>
using namespace std;

int main(){
    // Las operaciones se pueden usar en las variables entre variables y en los cout. 

    // tipos de operaciones: 
    // Suma (+)
    // Resta (-)
    // Divicion (/)
    // Multiplicacion (*)
    // Resto de una divicion (%) "usar solo con nums enteros".

    // Operacion en una variable.
    int num;
    num = 2 + 5;

    // Operacion entre variables 
    int num2 = 1;
    int num3 = 3;
    int num4 = num2 * num3;

    // Operacion entre un numero y una variable. 
    int num5 = 5;
    int num6 = num4 / 2;

    // operacion en los cout
    int num7 = 22;
    int num8 = 2;
    cout << num7 - num8 + 10; 
}