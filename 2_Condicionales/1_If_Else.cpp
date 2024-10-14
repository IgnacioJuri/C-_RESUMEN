#include <iostream>
using namespace std;

int main(){
    // Los condicionales se usan para realizar una accion u otra dependiendo del condicional.
    // Primero se establece la condicion y lo que pasa si esta se cumple (condicional = true). 
    // Despues se establece lo que pasa si esta no se cumple (condicional = false) (Esto es opcional).

    // La estructura es If (Condicion){ accion si se cumple} else {accion si no se cumple}
    int num = 5;
    if (num == 5){
        cout << "El numero es 5";
    } else {
        cout << "El numero no es 5";
    }

    // Para los condicionales usamos diferentes tipos de signos para darle sentido al condicional.
    // Menor (<)
    // Mayor (>)
    // Menor o igual (<=)
    // Mayor o igual (>=)
    // Igual (==)
    // Diferente (!=)
    // And Logico (&&) "las dos parates del condiconal se cumplen para que de true"
    // Or Logico (||) "una de las dos parates se tiene que cumplir para que de true"
    
    int num2 = 22;
    if (num2 < 30 && num2 % 2 == 0){
        cout <<"El numero es menor a 30 y divisible por 2";
    } else {
        cout <<"El numero no es menor a 30 y divisible por 2";
    }

    // se pueden anidar los if, es decir poner un if dentro de otro if.
    int num3 = 5;
    if (num3 == 10){
        cout << "El numero es 10";
    } else {
        if (num3 > 0){
            cout << "El numero no es 10 y es positivo";
        } else {
            cout << "El Numero no es 10 y es negativo";
        }
    }
}