#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

// Assinaturas das funções
int square(int*);

int somaVetor(const int*, const size_t);

int main()
{
    // EXEMPLO 1:
    /*
    //int* ptrInt = 0;

    // Ponteiro Vazio:
    //int* ptrInt = NULL;
    int* ptrInt = nullptr;

    cout << "PTR: " << ptrInt << endl;
    cout << "Endereco de PTR: " << &ptrInt << endl;
    cout << "======================================================" << endl; 

    int iNumMagico = 42;

    cout << "Endereco de iNumMagico: " << &iNumMagico << endl;

    ptrInt = &iNumMagico;
    cout << "PTR: " << ptrInt << endl;
    cout << "Endereco de PTR: " << &ptrInt << endl;
    cout << "Conteudo de iNumMagico: " << *ptrInt << endl;
    cout << "======================================================" << endl; 

    int iNumSagrado = 7;

    cout << "Endereco de iNumSagrado: " << &iNumSagrado << endl;

    ptrInt = &iNumSagrado;
    cout << "PTR: " << ptrInt << endl;
    cout << "Endereco de PTR: " << &ptrInt << endl;
    cout << "Conteudo de iNumSagrado: " << *ptrInt << endl;
    cout << "======================================================" << endl; 

    // OBS: Ponteiros são resetáveis, enquanto referências não.
    */


    
    //EXEMPLO 2:
    /*
    int iNum1 = 42;
    int iNum2 = 666;

    // Criando um ponteiro constante para inteiro
    int* const ptrNum1 = &iNum1;
    *ptrNum1 = 7;
    //ERRO
    //ptrNum1 = &iNum2;

    // Ponteiro para inteiro constante
    const int* ptrNum2 = &iNum1;
    ptrNum2 = &iNum2;
    //ERRO
    //*ptrNum2 = 7;

    // Ponteiro constante para inteiro constante
    const int* const ptrNum3 = &iNum1;
    //ptrNum3 = &iNum2;
    //*ptrNum3 = 7;

    cout << "======================================================" << endl; 

    cout << "Quadrado" << square(&iNum1) << endl; 

    int arriValores[3] = {0,1,2};

    cout << "somaVetor: " << somaVetor(arriValores, 3) << endl;
    */


    //EXEMPLO 3:

    int arriValores[5] = {0,7,13,42,666};
    cout << "Endereco de [0]: " << arriValores << endl;

    int* ptrArrayValores1 = arriValores;
    cout << "PTR1: " << ptrArrayValores1 << endl;

    // OBS: arrivalores = &arriValores[0]
    int* ptrArrayValores2 = &arriValores[0];
    cout << "PTR2: " << ptrArrayValores2 << endl;

    cout << "======================================================" << endl; 

    cout << "Valor de ptrArrayValores1[0]: " << *ptrArrayValores1 << endl;
    cout << "Endereco de ptrArrayValores1[0]: " << ptrArrayValores1 << endl;

    ptrArrayValores1++; // Precisa disso para ele avançar para o próximo elemento do vetor
    cout << "Valor de ptrArrayValores1[1]: " << *ptrArrayValores1 << endl;
    cout << "Endereco de ptrArrayValores1[1]: " << ptrArrayValores1 << endl;

    ptrArrayValores1+=3; // Sai do [1] e soma 3, chega no [4] elemento
    cout << "Valor de ptrArrayValores1[3]: " << *ptrArrayValores1 << endl;
    cout << "Endereco de ptrArrayValores1[3]: " << ptrArrayValores1 << endl;

    ptrArrayValores1-=2; // Sai do [4] e subtrai 2,  chega no [2] elemento
    cout << "Valor de ptrArrayValores1[2]: " << *ptrArrayValores1 << endl;
    cout << "Endereco de ptrArrayValores1[2]: " << ptrArrayValores1 << endl;

    cout << "Subtracao de Ponteiros: " << ptrArrayValores1 - ptrArrayValores2 << endl;

    return 0;
}

int square(int* ptrNum)
{
    return *ptrNum * *ptrNum;
}

// OBS: int* é a mesma coisa que int[]
int somaVetor(const int valores[], const size_t tamVetor)
{
    return -1;
}
