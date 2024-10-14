#include <iostream>
#include <cstring>
#include <stdio.h>

using namespace std;

// 2.	Una empresa de medicina prepaga decide hacer una estadística sobre el uso del servicio de guardias y pagar un bono a las guardias mas solicitadas. Para ello cuenta con un archivo de especialidades (son 25): id de especialidad, nombre, un archivo de consultas: id de paciente, id de especialidad, mes de consulta (son todas del mismo año, hay datos de los 12 meses y no importa el día), importe abonado por la prepaga para dicha consulta.


// Para dicho reconocimiento abonará al servicio de guardia de las 3 especialidades mas solicitadas el 7% extra sobre el total abonado a dicha guardia.
// Se le pide entonces que desarrolle la función que dados los dos archivos emita un listado con las 3 primeras especialidades, sus nombres, el total abonado originalmente para cada mes y el extra a abonar a cada guardia ordenado por importe total abonado.

struct especialidad{

    int idEspecialidad;
    char nombre[20 + 1];
};

struct consulta{

    int idPaciente;
    int idEspecialidad;
    int mes;
    float importe;
};

struct gordito{

    int idEspecialidad;
    char nombre[20 + 1];
    int consultasTotales = 0; 
    float importeAnual = 0;
    float extra = 0;
};

void leerEspecialidades(especialidad especialidades[]);
void leerConsultas(consulta consultas[]);
void crearGorditos(gordito gorditos[], especialidad especialidades[]);
void contarConsultas(gordito gorditos[], consulta consultas[]);
void ordenarGorditos(gordito gorditos[]);
void calcularTotalAnual(gordito gorditos[], consulta consultas[]);
void bonificarGorditos(gordito gorditos[]);
void ordenarGorditosTop3(gordito gorditosTop3[], gordito gorditos[]);

int main(){

    especialidad especialidades[25];
    consulta consultas[1000];
    gordito gorditos[25];
    gordito gorditosTop3[3];
    leerEspecialidades(especialidades);
    leerConsultas(consultas);
    crearGorditos( gorditos, especialidades);
    contarConsultas(gorditos, consultas);
    ordenarGorditos(gorditos);
    calcularTotalAnual(gorditos, consultas);
    bonificarGorditos(gorditos);
    ordenarGorditosTop3( gorditosTop3,  gorditos);


    for(int i=0; i <25; i++){

        cout << gorditos[i].idEspecialidad << endl;
        cout << gorditos[i].nombre << endl;
        cout << gorditos[i].consultasTotales << endl;
        cout << gorditos[i].importeAnual << endl;
        cout << gorditos[i].extra << endl;
        cout << endl;
    }

    cout << "Gorditos top3: " << endl;

    for(int i = 0; i < 3; i++){

        cout << gorditosTop3[i].idEspecialidad << endl;
        cout << gorditosTop3[i].nombre << endl;
        cout << gorditosTop3[i].consultasTotales << endl;
        cout << gorditosTop3[i].importeAnual << endl;
        cout << gorditosTop3[i].extra << endl;
        cout << endl;
    }
}

void leerEspecialidades(especialidad especialidades[]){
    int i = 0;
    especialidad raux;
    FILE * esp = fopen("Archivo_Especialidades.dat", "rb");

    fread(&raux, sizeof(especialidad), 1, esp);

    while(!feof(esp)){

        especialidades[i].idEspecialidad = raux.idEspecialidad;
        strcpy(especialidades[i].nombre, raux.nombre);

        i++;

        fread(&raux, sizeof(especialidad), 1, esp);
    }
    fclose(esp);
}

void leerConsultas(consulta consultas[]){

    int i = 0;
    consulta raux;

    FILE * con = fopen("Archivo_Consultas.dat", "rb");
    fread(&raux, sizeof(consulta), 1, con);

    while(!feof(con)){

        consultas[i].idEspecialidad = raux.idEspecialidad;
        consultas[i].idPaciente = raux.idPaciente;
        consultas[i].mes = raux.mes;
        consultas[i].importe = raux.importe;

        i++;
        fread(&raux, sizeof(consulta), 1, con);


    }
    fclose(con);
}

void crearGorditos(gordito gorditos[], especialidad especialidades[]){

    for(int i = 0; i < 25; i++){

        gorditos[i].idEspecialidad = especialidades[i].idEspecialidad;
        strcpy(gorditos[i].nombre, especialidades[i].nombre);

    }

}

void contarConsultas(gordito gorditos[], consulta consultas[]){

    for(int i = 0; i < 1000; i++){

        int aux = consultas[i].idEspecialidad;

        gorditos[aux].consultasTotales++; 
    }
}

void ordenarGorditos(gordito gorditos[]){

    for(int i = 0; i < 24; i++){

        gordito raux;

        for(int j = 0; j < 24; j++){

            if(gorditos[j].consultasTotales < gorditos[j + 1].consultasTotales){

                raux = gorditos[j];
                gorditos[j] = gorditos[j + 1];
                gorditos[j + 1] = raux;
            }
        }
    }
}

void calcularTotalAnual(gordito gorditos[], consulta consultas[]){

    for(int i = 0; i < 1000; i++){

        int aux = consultas[i].idEspecialidad;

        gorditos[aux].importeAnual += consultas[i].importe; 
    }
}

void bonificarGorditos(gordito gorditos[]){

    for(int i = 0; i < 3; i++){

        gorditos[i].extra = (gorditos[i].importeAnual * 7) / 100;
    }
}

void ordenarGorditosTop3(gordito gorditosTop3[], gordito gorditos[]){

    for(int i = 0; i < 3; i++){

        gorditosTop3[i] = gorditos[i];
    }

}