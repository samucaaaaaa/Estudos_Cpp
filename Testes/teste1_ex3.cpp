#include <iostream>

using std::cout;
using std::cin;
using std::endl;

const int ROWS = 6;
const int COLS = 7;

// Função para imprimir o tabuleiro
void printBoard(char board[][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

// Função para fazer uma jogada
bool fazerJogada(char board[][COLS], char piece, int coluna) {
    // Verificar se a coluna está dentro dos limites
    if (coluna < 1 || coluna > COLS) {
        cout << "Jogada inválida. Escolha uma coluna entre 1 e 7." << endl;
        return false;
    }

    // Verificar se a coluna está cheia
    if (board[0][coluna - 1] != 'O') {
        cout << "A coluna selecionada está cheia. Escolha outra coluna." << endl;
        return false;
    }

    // Encontrar a posição onde a peça será inserida
    int row = ROWS - 1;
    while (row >= 0 && board[row][coluna - 1] != 'O') {
        row--;
    }

    // Fazer a jogada
    board[row][coluna - 1] = piece;

    // Imprimir o tabuleiro após a jogada
    printBoard(board);

    // Verificar se o jogador venceu
    // Aqui você pode implementar a lógica para verificar se o jogador venceu

    return true;
}

int main() {
    char board[ROWS][COLS];

    // Inicializar o tabuleiro com espaços vazios
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = 'O';
        }
    }

    // Loop do jogo
    while (true) {
        // Imprimir o tabuleiro atual
        printBoard(board);

        // Fazer a jogada do jogador 1 (peça 'X')
        int coluna;
        cout << "Jogador 1 (X), faça sua jogada (coluna de 1 a 7): ";
        cin >> coluna;
        fazerJogada(board, 'X', coluna);

        // Fazer a jogada do jogador 2 (peça 'L')
        cout << "Jogador 2 (L), faça sua jogada (coluna de 1 a 7): ";
        cin >> coluna;
        fazerJogada(board, 'L', coluna);
    }

    return 0;
}