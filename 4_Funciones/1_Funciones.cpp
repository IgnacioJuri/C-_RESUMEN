#include <iostream>
using namespace std;
// Usamos las funciones para no repetir codigo.
// Si vamos a usar mucho un codigo lo metemos en una funcion y la llamamos cuando es necesario
// Existen dos tipos, con valor y sin valor
// Con valor: retornan un valor al terminar su ejecucion, inician con el tipo de dato que retornan. 
// Sin valor: no retornan una valor al terminar su ejecucion, inician con void.
// Las funciones van por fuera del main().

int sumar ( int a, int b){
    return a + b;
}
// Esta funcion va a devolber un tipo de dato int, su nombre es sumar y sus parametros son a y b

int main(){
    // llamar funcion
    int resultado = sumar(1,5);

}