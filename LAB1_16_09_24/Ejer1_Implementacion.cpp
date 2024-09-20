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
    double time_first = double(stop - inicio_tiempo) / CLOCKS_PER_SEC;  // Calculamos el tiempo
    cout << "Tiempo del primer  for " << time_first << " s" << endl;
    
    // Reiniciamos el vector y a 0
    for (int i = 0; i < MAX; i++) y[i] = 0;
    

    inicio_tiempo = clock(); 
    segundo_for();   
    stop = clock();   
    double time_second = double(stop - inicio_tiempo) / CLOCKS_PER_SEC;
    cout << "Tiempo del segundo for: " << time_second << " s"<<endl;

    return 0;
}

/*
Se puede ver en los resultados que si aumentamos el número de elementos, podemos ver la diferencia:

50:

1000:

5000:

10000:

*/