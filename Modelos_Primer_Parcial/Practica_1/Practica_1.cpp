#include <iostream>
#include <cstring>
#include <stdio.h>

using namespace std;

struct paciente{

    int id;
    char nombre[20 + 1];
    char apellido [20 + 1];
    int edad;
    char diagnostico[99 + 1];
};

struct medicamento{

    int ean;
    char nombre[50 + 1];
    int dosis;
};

struct prescripcion{

    int idPaciente;
    int ean;
    int interbalo;
    int horaInicio;
};

struct prescripcionCompleta{

    int id;
    char nombre[20 + 1];
    char apellido[20 + 1];
    int ean;
    char nombreMedicamento[50 + 1];
    int dosis;
    int hora;
};

struct pacienteSinPrescripcion{

    int id;
    char nombre[20 + 1];
    char apellido[20 + 1];
};

void leerPaciente(paciente pacientes[]);
void leerMedicamento(medicamento medicamentos[]);
void crearPrescripciones(prescripcion prescripciones[], medicamento medicamentos[]);
void crearPrescripcionesCompletas(prescripcionCompleta prescripcionesCompletas[],prescripcion prescripciones[], medicamento medicamentos[], paciente pacientes[]);
void ordenarPrescripcionesCompletas(prescripcionCompleta prescripcionesCompletas[]);
void buscarPacientesSinPrrescripcion(pacienteSinPrescripcion pacientesSinPrescripcion[], paciente pacientes[], prescripcion prescripciones[]);



int main(){

    srand(1);
    paciente pacientes[100];
    medicamento medicamentos[100];
    prescripcion prescripciones[75];
    prescripcionCompleta prescripcionesCompletas[75];
    pacienteSinPrescripcion pacientesSinPrescripcion[100];

    leerPaciente(pacientes);
    leerMedicamento(medicamentos);
    crearPrescripciones(prescripciones, medicamentos);
    crearPrescripcionesCompletas(prescripcionesCompletas, prescripciones, medicamentos, pacientes);
    ordenarPrescripcionesCompletas(prescripcionesCompletas);
    buscarPacientesSinPrrescripcion( pacientesSinPrescripcion,  pacientes, prescripciones);

    cout << "Info completa y ordenada de los pacientes con prescripcion" << endl;

    for(int i=0; i<75; i++){

        cout << prescripcionesCompletas[i].id << endl;
        cout << prescripcionesCompletas[i].nombre << endl;
        cout << prescripcionesCompletas[i].apellido << endl;
        cout << prescripcionesCompletas[i].ean << endl;
        cout << prescripcionesCompletas[i].nombreMedicamento << endl;
        cout << prescripcionesCompletas[i].dosis << endl;
        cout << prescripcionesCompletas[i].hora << endl;
        cout << endl;
    }

    cout << "Lista de pacientes sin prescripcion" << endl;

    for(int i = 0; i<100; i++){

        cout << pacientesSinPrescripcion[i].id << endl;
        cout << pacientesSinPrescripcion[i].nombre << endl;
        cout << pacientesSinPrescripcion[i].apellido << endl;
        cout << endl;
    }

    
}

void leerPaciente(paciente pacientes[]){

    FILE * pac = fopen("Archivo_Paciente.dat","rb");

    paciente raux;

    fread(&raux,sizeof(paciente),1,pac);

    int i = 0;

    while(!feof(pac)){
        
        
        pacientes[i].id = raux.id;
        strcpy(pacientes[i].nombre, raux.nombre);
        strcpy(pacientes[i].apellido, raux.apellido);
        pacientes[i].edad = raux.edad;
        strcpy(pacientes[i].diagnostico, raux.diagnostico);

        i++;
        fread(&raux,sizeof(paciente),1,pac);
    }

    fclose(pac);
}

void leerMedicamento(medicamento medicamentos[]){

    FILE * med = fopen("Archivo_Medicamento.dat", "rb");

    medicamento raux;
    int i = 0;

    fread(&raux, sizeof(medicamento),1,med);

    while(!feof(med)){

        medicamentos[i].ean = raux.ean;
        strcpy(medicamentos[i].nombre, raux.nombre);
        medicamentos[i].dosis = raux.dosis;

        i++;

        fread(&raux, sizeof(medicamento),1,med); 
    }

    fclose(med);
}

void crearPrescripciones(prescripcion prescripciones[], medicamento medicamentos[] ){

    for(int i = 0; i < 75; i++){
    
        prescripciones[i].idPaciente = 0 + rand() % (40 - 0 + 1);
        prescripciones[i].ean = medicamentos[0 + rand() % (100 - 0 + 1)].ean;
        prescripciones[i].interbalo = 12;
        prescripciones[i].horaInicio = 0 + rand() % (24 - 0 + 1);
    }
}

void crearPrescripcionesCompletas(prescripcionCompleta prescripcionesCompletas[],prescripcion prescripciones[], medicamento medicamentos[], paciente pacientes[]){

    for(int i = 0; i < 75; i++){

        prescripcionesCompletas[i].id = prescripciones[i].idPaciente;
        prescripcionesCompletas[i].ean = prescripciones[i].ean;
        prescripcionesCompletas[i].hora = prescripciones[i].horaInicio;

        //buscar nombre y apellido que corresponda al id. 
        for(int j = 0; j<100; j++){

            if(prescripcionesCompletas[i].id == pacientes[j].id){

                strcpy(prescripcionesCompletas[i].nombre, pacientes[j].nombre);
                strcpy(prescripcionesCompletas[i].apellido, pacientes[j].apellido);
            }
        }

        // Buscar nombre del medicamento y dosis que corresponde al ean
        for(int j = 0; j<100; j++){

            if(prescripcionesCompletas[i].ean == medicamentos[j].ean){

                strcpy(prescripcionesCompletas[i].nombreMedicamento, medicamentos[j].nombre);
                prescripcionesCompletas[i].dosis = medicamentos[j].dosis;
            }
        }

    }
}

void ordenarPrescripcionesCompletas(prescripcionCompleta prescripcionesCompletas[]){

    // ordena por id de menor a mayor
    for(int i = 0; i<74; i++){

        prescripcionCompleta aux;

        
        for(int j = 0; j < 74; j++){

            if(prescripcionesCompletas[j].id > prescripcionesCompletas[j + 1].id){

                aux = prescripcionesCompletas[j];
                prescripcionesCompletas[j] = prescripcionesCompletas[j + 1];
                prescripcionesCompletas[j + 1] = aux;

            }
        }
    }

    // Subordenar por hora
    for(int i = 0; i < 74; i++){

        prescripcionCompleta aux;

        for(int j = 0; j < 74; j++){

            if(prescripcionesCompletas[j].id == prescripcionesCompletas[j + 1].id && prescripcionesCompletas[j].hora > prescripcionesCompletas[j + 1].hora){

                aux = prescripcionesCompletas[j];
                prescripcionesCompletas[j] = prescripcionesCompletas[j + 1];
                prescripcionesCompletas[j + 1] = aux;
            }
        }
    }
}

void buscarPacientesSinPrrescripcion(pacienteSinPrescripcion pacientesSinPrescripcion[], paciente pacientes[], prescripcion prescripciones[]){

    bool tienePrescripcion = false;
    int contador = 0;

    for(int i = 0; i< 100; i++){
        
        tienePrescripcion = false;
        
        for(int j = 0; j<75; j++){

            if(pacientes[i].id == prescripciones[j].idPaciente){

                tienePrescripcion = true;
            }
        }

        if(tienePrescripcion == false){

            pacientesSinPrescripcion[contador].id = pacientes[i].id;
            strcpy(pacientesSinPrescripcion[contador].nombre, pacientes[i].nombre);
            strcpy(pacientesSinPrescripcion[contador].apellido, pacientes[i].apellido);

            contador++;
        }
    }
}