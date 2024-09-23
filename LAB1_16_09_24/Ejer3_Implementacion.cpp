#include <iostream>
#include <ctime>
#include <algorithm> // el  min
using namespace std;

#define N 100 // tam matriz
#define blockSize 20 // tam bloque

void inicializarMatriz(int A[N][N], int B[N][N], int C[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            A[i][j] = rand() % 10; //aleatorios
            B[i][j] = rand() % 10;
            C[i][j] = 0;
        }
    }
}

//multiplicación por bloques
void multiplicacionBloques(int A[N][N], int B[N][N], int C[N][N]) {
    for (int k = 0; k < N; k += blockSize) {
        for (int l = 0; l < N; l += blockSize) {
            for (int m = 0; m < N; m += blockSize) {
                //multiplicación dentro de bloques
                for (int i = k; i < min(k + blockSize, N); i++) {
                    for (int j = l; j < min(l + blockSize, N); j++) {
                        int sum = 0;
                        for (int p = m; p < min(m + blockSize, N); p++) {
                            sum += A[i][p] * B[p][j];
                        }
                        C[i][j] += sum;
                    }
                }
            }
        }
    }
}

int main() {
    int A[N][N], B[N][N], C[N][N];
    inicializarMatriz(A, B, C);

    //comienza tiempo
    clock_t inicio, end;
    inicio = clock();
    multiplicacionBloques(A, B, C);
    end = clock();

    double tiempoTotal = double(end - inicio) / CLOCKS_PER_SEC;
    cout << "Tiempo de multiplicación por bloques: " << tiempoTotal << " segundos." << endl;

    return 0;
}
