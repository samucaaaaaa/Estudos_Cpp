#include <iostream>

// Define o tamanho da matriz e do vetor
const int ROWS = 3;
const int COLS = 3;
const int VECTOR_SIZE = 3;

// Função para multiplicar uma matriz por um vetor
void multiplyMatrixVector(double matrix[ROWS][COLS], double vector[VECTOR_SIZE], double result[ROWS]) {
    // Inicializa o vetor de resultado com zeros
    for (int i = 0; i < ROWS; i++) {
        result[i] = 0;
    }

    // Loop através das linhas da matriz
    for (int i = 0; i < ROWS; i++) {
        // Loop através das colunas da matriz
        for (int j = 0; j < COLS; j++) {
            // Multiplica cada elemento da linha da matriz pelo elemento correspondente do vetor
            result[i] += matrix[i][j] * vector[j];
        }
    }
}

int main() {
    // Definição da matriz, do vetor e do vetor de resultado
    double matrix[ROWS][COLS] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    double vector[VECTOR_SIZE] = {1, 2, 3};
    double result[ROWS];

    // Multiplica a matriz pelo vetor
    multiplyMatrixVector(matrix, vector, result);

    // Imprime o resultado
    std::cout << "Resultado da multiplicacao:" << std::endl;
    for (int i = 0; i < ROWS; i++) {
        std::cout << result[i] << std::endl;
    }

    return 0;
}