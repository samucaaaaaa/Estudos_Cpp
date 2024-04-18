#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
    /*
    
    // Criando um vetor
    // TIPO NOME TAMANHO
    int x[100] = {0};
    cout << "x[0] = " << x[0] << ", endereco: " << &x[0] << endl; //&x[0] pega o endereço do x[0]
    cout << "x[1] = " << x[1] << ", endereco: " << &x[1] << endl;
    cout << "x[99] = " << x[99] << ", endereco: " << &x[99] << endl;
    cout << "Tamanho de x = " << sizeof(x)/sizeof(x[0]) << endl; //sizeof(x) pega o tamanho de bytes do vetor x e sizeof(x[0]) pega o tamanho em bytes do 1° elemento
    cout << "----------------------------------------------"<< endl;

    int array[4];
    
    array[0] = 8;
    array[1] = 64;
    array[2] = 256;
    array[3] = 512;

    cout << "array[0] = " << array[0] << ", endereco: " << &array[0] << endl;
    cout << "array[1] = " << array[1] << ", endereco: " << &array[1] << endl;
    cout << "array[2] = " << array[2] << ", endereco: " << &array[2] << endl;
    cout << "array[3] = " << array[3] << ", endereco: " << &array[3] << endl;
    cout << "array[4] = " << array[4] << ", endereco: " << &array[4] << endl;
    cout << "Tamanho de array = " << sizeof(array)/sizeof(array[0]) << endl; 
    if (&array[0] == array) {cout << "Faz sentido!" << endl;}
    cout << "----------------------------------------------"<< endl;
    
    */

    // Row Major
    int arriTest1[2][3] = {2,4,5,9,0,19};
    int arriTest2[2][3] = {{2,4,5},{9,0,19}};

    cout << "--- Testando Array 1 ---" << endl;

    for (int i=0; i < 2; i++)
    {
        for (int j=0; j < 3; j++)
        {
            cout << "Array 1 em [" << i << "][" << j << "] = " << arriTest1[i][j] << ", Endereco: " << &arriTest1[i][j] << endl;
        }
    }

    cout << "--- Aluno: Diagnosticado com TDAH ---" << endl;
    // Matriz_m_n em (i, j) = (i*n + j) * sizeof(elemento)

    for (int i=0; i < 3; i++)
    {
        for (int j=0; j < 2; j++)
        {
            cout << "Array 2 em [" << i << "][" << j << "] = " << arriTest2[i][j] << ", Endereco: " << &arriTest2[i][j] << endl;
        }
    }

    cout << "--- Aluno: Diagnosticado com Transtorno Psicotico ---" << endl;
    // Matriz_m_n em (i, j) = (i*n + j) * sizeof(elemento)

    for (int i=0; i < 3; i++)
    {
        for (int j=0; j < 8; j++)
        {
            cout << "Array 2 em [" << i << "][" << j << "] = " << arriTest2[i][j] << ", Endereco: " << &arriTest2[i][j] << endl;
        }
    }

    int array[3][6] = {10, 20, 30, 40, 50, 60, 1, 2, 3, 4, 5, 6, 100, 200, 300, 400, 500, 600};

    //cout << sizeof(array)/sizeof(array[0][0]) << endl;

    return 0;
}
