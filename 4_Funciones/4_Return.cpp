#include <iostream>
using namespace std;

// El return lo usamos para cuando queremos que una funcion nos devuelva un valor para usarlo en el main
// Para esto la funcion no debe empezar con void como lo vimos antes
// Debe comenzar con el tipo de dato que queremos retornar

// Prototipado para la funcion areaCuadrado
int areaCuadrado(int lado);

int main(){

    // Variable con la longitud del lado
    int lado = 5;
    // Pido el valor del area a la funcion y lo cargo en una variable
    int area = areaCuadrado(lado);
    // Muesto la variable
    cout << area << " cm^2";
}

// Declaro la funcion y le digo que va a usar la variable lado de tipo int
int areaCuadrado(int lado){

    // Indico que el area es multiplicar el lado por el lado
    int area = lado * lado;
    // Retorno el valor de la variable area, que debe ser el mismo tipo de dato que la funcion
    return area;
}