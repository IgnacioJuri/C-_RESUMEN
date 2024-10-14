#include <iostream>
using namespace std;

int main(){
    // El while es un ciclo como el for, pero no sabemos cuantas veces se va a repetir. 
    // Le establecemos una condicion y mientras que esta se cumpla se va a seguir ejecutando.
    // While (condicion)
    int num;
    cin >> num;
    while (num != 0){
        cout << num << endl;
        cin >> num;
    }

    // Pido un numero al usuario, si el num es 0 no pasa nada
    // Si no es cero me pide otro numero, y asi hasta que ponga 0.
    // A diferencia del for no se cuantas veces el usuario va a poner numeros hasta que ponga 0.
}