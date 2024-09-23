#include <iostream>
#include <ctime>

using namespace std;

#define MAX 10000 
//puedo cambiuar tam MAtriz vectores


int A[MAX][MAX], x[MAX], y[MAX]; 

//Incializamos valores de A, x ,y
void inicializar() {
    for (int i = 0; i < MAX; i++) {
        x[i] = 1;  
        y[i] = 0;  
        for (int j = 0; j < MAX; j++) {
            A[i][j] = 1;  // Todos los valores de A serán 1 por ahora
        }
    }
}


void primer_for() {
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            y[i] += A[i][j] * x[j]; //multiplico
        }
    }
}


void segundo_for() {
    for (int j = 0; j < MAX; j++) {
        for (int i = 0; i < MAX; i++) {
            y[i] += A[i][j] * x[j];  //multiplico
        }
    }
}

int main() {
    inicializar();
    
    clock_t inicio_tiempo, stop;  // Para medir el tiempo


    inicio_tiempo = clock();  //Inicia clock de inicio
    primer_for();
    stop = clock();    //termina el conteo
    double tiempo_primer_for = double(stop - inicio_tiempo) / CLOCKS_PER_SEC;  //calculamos tiempo
    cout << "Tiempo del primer  for " << tiempo_primer_for << " s" << endl;
    
    // Reiniciamos vector "y" a 0
    for (int i = 0; i < MAX; i++) y[i] = 0;
    

    inicio_tiempo = clock(); 
    segundo_for();   
    stop = clock();   
    double tiempo_Segundo_for = double(stop - inicio_tiempo) / CLOCKS_PER_SEC;
    cout << "Tiempo del segundo for: " << tiempo_Segundo_for << " s"<<endl;

    return 0;
}