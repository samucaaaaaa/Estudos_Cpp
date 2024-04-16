#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int& trocaElemento(int, int[]);

int main()
{
    int* ptrInt = nullptr;

    cout << "ptrInt: " << ptrInt << endl;
    cout << "Endereco de ptrInt: " << &ptrInt << "\n\n";

    // iTeste2 é um ponteiro que aponta para um ponteiro que aponta para um inteiro
    // ele é um ponteiro que aponta para o endereço de outro ponteiro
    int** iTeste2 = &ptrInt;

    cout << "iTeste2: " << iTeste2 << endl;
    cout << "Endereco de iTeste2: " << &iTeste2 << "\n\n";

    // Agora quero fazer com que o ponteiro aponte para uma variável
    int iValor = 10;
    ptrInt = &iValor; // O ponteiro só pode receber o endereço de algo
    
    // Vou printar o valor e endereço do iValor
    cout << "iValor: " << iValor << ". Endereco de iValor: " << &iValor << "\n\n";
    
    // Vou printar o valor de ptrInt e seu endereço
    cout << "ptrInt: " << ptrInt << ". Endereco de ptrInt: " << &ptrInt << "\n\n";

    // Agora quero printar o valor para o qual ptrInt aponta
    cout << "Valor que ptrInt aponta: " << *ptrInt << endl;
    cout << "======================================================" << endl;

    string strNome = "Yuri Saporito";
    string strTeste = strNome; // strTeste tem o mesmo valor strNome, mas é uma nova variável e fica em outro lugar de memória
    // Criando apelido para strNome
    string& strrefNome = strNome; // strrefNome tem o mesmo valor de strNome e fica no mesmo local de memória

    cout << "Valor da strNome: " << strNome << ". Endereco da strNome: " << &strNome << "\n\n";
    cout << "Valor da strTeste: " << strTeste << ". Endereco da strTeste: " << &strTeste << "\n\n";
    cout << "Valor da strrefNome: " << strrefNome << ". Endereco da strrefNome: " << &strrefNome << endl;
    cout << "======================================================" << endl;

    // Criando um vetor
    int iVetor[4] = {2, 4, 6, 8};

    for(int i = 0; i < 4; i++)
    {
        cout << "Elemento[" << i << "] = " << iVetor[i] << endl;
    }

    cout << "\n";

    // A função trocaElemento retorna uma referência para o elemento na posição 2 do vetor
    int& refElemento = trocaElemento(2, iVetor); // A variável refElemento recebe essa referência, logo, ao mudar seu valor, mudamos o valor do elemento
    refElemento = 3; 
    // OBS: eu poderia fazer apenas isso que funcionaria:   trocaElemento(2, iVetor) = 3;

    for(int i = 0; i < 4; i++)
    {
        cout << "Elemento[" << i << "] = " << iVetor[i] << endl;
    }
    cout << "======================================================" << endl;

    // OBS: Ponteiros são resetáveis, enquanto referências não

    int iValor1 = 10;
    int iValor2 = 20;

    cout << "Valor de iValor1: " << iValor1 << "\n";
    int& ref = iValor1; // ref é uma referência para valor1
    ref = iValor2;

    cout << "Novo valor de iValor1: " << iValor1 << endl;
    cout << "======================================================" << endl;

    int iNum1 = 42;
    int iNum2 = 666;

    cout << "Valor de iNum1: " << iNum1 << endl;
    cout << "Valor de iNum2: " << iNum2 << "\n\n";

    // Criando um ponteiro constante para inteiro
    int* const ptrNum1 = &iNum1;
    *ptrNum1 = 7;
    // ERRO
    // ptrNum1 = &iNum2;
    // Ele não pode apontar para outra variável, mas pode alterar o valor dessa variável
    cout << "ptrNum1 aponta para: " << ptrNum1 << endl;
    cout << "Novo valor de iNum1: " << iNum1 << "\n\n";

    // Ponteiro para inteiro constante
    const int* ptrNum2 = &iNum1;
    ptrNum2 = &iNum2;
    // ERRO
    // *ptrNum2 = 7;
    // Ele pode apontar para outra variável, mas não pode alterar o valor dessa variável
    cout << "ptrNum2 aponta para: " << ptrNum2 << "\n\n";

    // Ponteiro constante para inteiro constante
    const int* const ptrNum3 = &iNum1;
    // ptrNum3 = &iNum2;
    // *ptrNum3 = 7;
    // Ele não pode apontar para outra variável e nem alterar o valor dessa variável
    cout << "ptrNum3 aponta para: " << ptrNum3 << endl;

    // OBS: ptrNum1 e ptrNum3 estão apontando para a mesma variável
    cout << "======================================================" << endl;

    // Criando matrizes
    int arriTest1[2][3] = {2,4,5,9,0,19};
    int arriTest2[2][3] = {{2,4,5},{9,0,19}}; // Essa forma é melhor

    cout << "--- Testando arriTest2 ---" << endl;

    for (int i=0; i < 2; i++)
    {
        for (int j=0; j < 3; j++)
        {
            cout << "arriTest1 em [" << i << "][" << j << "] = " << arriTest2[i][j] << ", Endereco: " << &arriTest1[i][j] << endl;
        }
    }

    // Printando a matriz
    cout << "\n--- printando arriTest2 ---" << endl;
    for (int i = 0; i < 2; i++)
    {
        cout << "| ";
        for (int j = 0; j < 3; j++)
        {
            cout << arriTest2[i][j] << " ";
        }
        cout << "|" << endl;
    }

    return 0;
}

int& trocaElemento(int iElemento, int arriVetor[])
{
    return arriVetor[iElemento];
}