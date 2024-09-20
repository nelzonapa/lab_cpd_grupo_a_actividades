#include <iostream>
#include <vector>
#include <ctime>
#include <fstream>

using namespace std;

void inicializarMatrices(vector<vector<int>> &A, vector<vector<int>> &B, vector<vector<int>> &C, int N) {
    for(int i = 0; i < N; ++i){
        for(int j = 0; j < N; ++j){
            A[i][j] = 1; 
            B[i][j] = 1; 
            C[i][j] = 0; 
        }
    }
}


void multiplicarMatrices(vector<vector<int>> &A, vector<vector<int>> &B, vector<vector<int>> &C, int N) {
    for(int i = 0; i < N; ++i){
        for(int j = 0; j < N; ++j){
            for(int k = 0; k < N; ++k){
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main() {
    // tamanios de matriz
    vector<int> tamanios = {100, 400, 700, 1000}; 


    for (int i = 0; i < tamanios.size(); i++) {
        int N = tamanios[i];
        // Crear matrices dinámicamente
        vector<vector<int>> A(N, vector<int>(N));
        vector<vector<int>> B(N, vector<int>(N));
        vector<vector<int>> C(N, vector<int>(N));

        inicializarMatrices(A, B, C, N);

        // Medir el tiempo de multiplicación
        clock_t inicio = clock();
        multiplicarMatrices(A, B, C, N);
        clock_t fin = clock();
        double tiempo = double(fin - inicio) / CLOCKS_PER_SEC;

        cout << "Tamaño de Matriz: " << N << "x" << N << " - Tiempo: " << tiempo << " segundos" << endl;
    }

    return 0;
}
