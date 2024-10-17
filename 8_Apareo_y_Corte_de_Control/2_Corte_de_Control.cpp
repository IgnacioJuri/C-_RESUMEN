#include <iostream>
#include <cstring>
#include <stdio.h>

using namespace std;

// Condiciones de uso para corte de control

// Pre Condiciones:
// Tener un archivo Agrupado por una clave, y que dicha clave se repita

// Post condiciones: 
// Tener que utilizar claves repetidas para algo

// Ejemplo: Las multas tienen un costo y estan vinculadas a una patente
// Pueden haber mas de una multa vinculadas a dicha patente
// Al querer calcular el total a pagar de una patente podemos usar corte de control

// Struct de multa
struct multa{

    int dominio;
    int tipo;
    int importe; 
};


int main(){

    // Puntero del archivo 
    FILE* mul = fopen("Multas.dat", "rb");

    // Variable auxiliar
    multa raux;
    // Variable para guardar el domino anterior
    int anterior;
    // Contador para el valor total de las multas
    int sumaMultas;
    
    // Lectura del archivo
    fread(&raux, sizeof(struct multa), 1, mul);

    // While para recorrer el archivo hasta que se encuentre el final de archivo
    while(!feof(mul)){

        // Grabar en la variable el dominio
        anterior = raux.dominio;
        // Setear el contador del valor de las multas en 0
        sumaMultas = 0;

        // Si el archivo no llego al final y el dominio anterior es igual al dominio nuevo:
        while( (!feof(mul)) && (anterior == raux.dominio) ){

            // Agregar el importe nuevo al contador de valor de multas 
            sumaMultas = sumaMultas + raux.importe;
            // Leer el archivo
            fread(&raux, sizeof(struct multa), 1, mul);
        };

        // Mostrar el contador de multas del dominio analizado
        cout << "El domino " << anterior << "Tiene un total de multas de: " << sumaMultas << endl;
    };

    // Cerrar archivo
    fclose(mul);

    // El algoritmo mira cual es el primer domino y lo guarda en una varriable para leer de nuevo el archivo
    // Si el siguiente domino es igual al anterior agrega el importe a pagar a un contador
    // Luego se lee el archivo y se repite el proceso hasta encontrar un dominio que no es igual al anterior
    // Cuando esto pasa se guarda ese dominio en la variable anterior y se recetea el contador de multas
    // Inicia el proceso de nuevo hasta llegar al final de archivo
    return 0;
};