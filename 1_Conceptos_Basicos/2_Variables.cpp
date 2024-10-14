#include <iostream>
#include <cstring>
using namespace std;

int main(){
    // Las variables son un espacio en la memoria asignado para guardar un dato.
    // Para cada tipo de dato existe un tipo de variable.
    // El orden de escritura es tipo de variable, nombre, valor (si hay).
    // TipoDeDato NombreVariable = Valor;

    // int: se usa para declarar una variable para numeros enteros.
    int numeroEntero = 3;

    // float: se usa para declarar una variable para numeros no enteros.
    float numeroNoEntero = 0.25;

    // bool: se usa para declarar una variable para valores booleanos, true or false.
    bool valorBooleano = true;

    // char: se usa para declarar una variable para caracteres como letras.
    char Caracter = 'A';

    // char cstring: Podemos poner mas de 1 caracter, especificamos la cantidad que es posible.
    char Caracteres[20+1] = "Nacho"; 

    // Podemos declarar una variable y luego asignarle un valor, o cambiarselo si ya tiene uno.
    int num; 
    num = 25;

    float num2 = 1.15;
    num2 = 5.5;

    // Podemos pedirle a un usuario que ingrese un valor. 
    int num3;
    cin >> num3; 
}