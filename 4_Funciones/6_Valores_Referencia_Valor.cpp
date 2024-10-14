    #include <iostream>
    #include <cstring>
    using namespace std;

// Los valores por valor son los que pasamos habitualmente para usar las funciones
// Crean una copia de la variable original y la modifican
// Esto no siempre representa un problema pero hay casos en los que si
// Los valores por referencia utilizan la misma variable y la modifican

// Prototipo de las funciones
void porValor(std::string taza1, std::string taza2);
void porReferencia(std::string &taza1, std::string &taza2);

int main(){

    // Crea las variables
    // Std::string es otra forma de usar una cadena de caracteres
    std::string taza1 = "cafe";
    std::string taza2 = "agua";

    // Ejecuta la funcion por valor y la mustra 
    porValor( taza1,taza2 );

    cout << "taza1: "<< taza1 << " Taza2: " << taza2 << endl;

    // Ejecuta la funcion por referencia y la mustra 
    porReferencia(taza1,taza2);

    cout << "taza1: "<< taza1 << " Taza2: " << taza2 << endl;
    
}

// Funciones 
void porValor(std::string taza1, std::string taza2){

    std::string temp;
    temp = taza1;
    taza1 = taza2;
    taza2 = temp;
}

void porReferencia(std::string &taza1, std::string &taza2){

    std::string temp;
    temp = taza1;
    taza1 = taza2;
    taza2 = temp;
}

// Podemos ver que el codigo es el mismo en las dos funciones pero su resultado es diferente
// porValor copia las varrriables e intercambia su valor, pero al ser copias al llamarlo no cambian
// porReferencia utiliza las variables originales, por lo que el cambio se ve reflejado