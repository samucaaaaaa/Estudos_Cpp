#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::string;

void troca(int&, int&);
int& trocaElemento(int, int[]);

int main()
{
    string strNome = "Yuri Saporito";
    int iValor = 42;
    int iValorFuturo = 666;

    cout << "Valor da String: " << strNome << ". Endereco da String: " << &strNome << endl;
    cout << "Valor do Inteiro: " << iValor << ". Endereco do Inteiro: " << &iValor << endl;
    cout << "================================================================" << endl;

    // Essa linha quer dizer que estamos criando um apelido para strNome, ou seja,
    // o que for auterado em strrefNome também será auterado em strNome 
    string& strrefNome = strNome;
    int irefValor = iValor;

    cout << "Valor da da Ref.String: " << strrefNome << ". Endereco da String: " << &strrefNome << endl;
    cout << "Valor da Ref.Inteiro: " << irefValor << ". Endereco do Inteiro: " << &irefValor << endl;
    cout << "================================================================" << endl;

    strrefNome = "C. Camacho";
    irefValor = iValorFuturo;

    cout << "Valor da da Ref.String: " << strrefNome << ". Endereco da String: " << &strrefNome << endl;
    cout << "Valor da Ref.Inteiro: " << irefValor << ". Endereco do Inteiro: " << &irefValor << endl;
    cout << "================================================================" << endl;

    int iNum1 = 7;
    int iNum2 = 42;

    cout << "iNum1: " << iNum1 << endl;
    cout << "iNum2: " << iNum2 << endl;

    cout << "================================================================" << endl;

    int arriVetor[5] = {0, 7, 13, 42, 666};

    for (int i = 0; i < 5; i++)
    {
        cout << "Vetor[" << i << "] = " << arriVetor[i] << endl;
    }

    cout << "-----" << endl;

    trocaElemento(3, arriVetor) = 111;

    for (int i = 0; i < 5; i++)
    {
        cout << "Vetor[" << i << "] = " << arriVetor[i] << endl;
    }

    return 0;

}

void troca(int& irefValor1, int& irefValor2)
{
    int iTemp = irefValor1;
    irefValor1 = irefValor2;
    irefValor2 = iTemp;
}

int& trocaElemento(int iElemento, int arriVetor[])
{
    return arriVetor[iElemento];
}