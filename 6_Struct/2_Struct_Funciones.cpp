#include <iostream>
#include <cstring>
using namespace std;

// Para utilizar una struct en una funcion debemos pasar el tipo de dato del struct
// Luego hay que ponerle un identificador a su lado, el mismo nombre que el struct es lo mas comodo

// Crear el struct autos con sus variables
struct autos{

    const char* marca;
    int  año;
    const char* color;
};

// Prototipo de funciones
void mostrarAuto(autos &autos);
void pintarAuto(autos &autos);


int main(){

    // Otra forma de crear variables del tipo "autos"
    autos auto1 {"Honda", 2022, "Rojo"};
    autos auto2{"Ford", 1999, "Azul"};

    // LLamar a las funciones mostrarAuto y pintarAuto
    mostrarAuto(auto1);
    mostrarAuto(auto2);
    pintarAuto(auto1);
    mostrarAuto(auto1);

}

// Funcion para mostrar los datos del auto que le pasamos
void mostrarAuto(autos &autos){

    cout << "Marca: " << autos.marca << endl;
    cout << "Año: " << autos.año << endl;
    cout << "Color: " << autos.color << endl;
}   

// Funcion para cambiar el color, lo utilizamos por referencia ya que de lo contrario no se aplica el cambio
void pintarAuto(autos &autos){

    autos.color = "Negro";
}