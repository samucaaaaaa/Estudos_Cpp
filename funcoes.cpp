#include <iostream>
#include <cmath>

using std::cin;
using std::cout;
using std::endl;
using std::string;

void minhaFuncao(int arriNumeros[], int iTamanhoVetor)
{
    for(int i=0; i<iTamanhoVetor; i++)
    {
        cout << arriNumeros[i] << endl;
    }
}

void frasePreferida()
{
    cout << "Eu adoro a EMap!" << endl;
}

void montaFrase(char chArtigo, string strPalavra)
{
    cout << "Eu adoro " << chArtigo << " " << strPalavra << "!" << endl; 
}

void montaFrasePadrao(char chArtigo = 'a', string strPalavra = "EMAp")
{
    cout << "Eu adoro " << chArtigo << " " << strPalavra << "!" << endl; 
}

int potenciao(int iBase, int iExpoente)
{
    return pow(iBase, iExpoente);
}

int modulo(int iValor)
{
    return abs(iValor);
}

float modulo_f(float iValor)
{
    return fabs(iValor);
}

int main()
{

    int arriVetorTeste[5] = {0, 7, 13, 42, 666};
    int iTamanhoVetor = sizeof(arriVetorTeste)/sizeof(arriVetorTeste[0]);

    minhaFuncao(arriVetorTeste, iTamanhoVetor);
    cout << "==============================" << endl;

    frasePreferida();
    cout << "==============================" << endl;

    montaFrase('a', "EMap");
    montaFrase('o', "Yuri");
    cout << "==============================" << endl;

    // Para a função com argumentos padrão não precisa passar parâmetro
    montaFrasePadrao();

    // Pode passar só um também, mas tem que respeitar a ordem
    montaFrasePadrao('a');
    //montaFrasePadrao("EMap")

    // Pode passar parâmetros novos, substituindo os padrões
    montaFrasePadrao('o', "Yuri");
    cout << "==============================" << endl;

    cout << "potenciao(2,10) " << potenciao(2,10) << endl;
    cout << "potenciao(3,5) " << potenciao(3,5) << endl;
    cout << "==============================" << endl;

    cout << "modulo(2) " << modulo(2) << endl;
    cout << "modulo(-2) " << modulo(-2) << endl;

    // Funciona porque a função retorna inteiro
    cout << "modulo(-2.7) " << modulo(-2.7) << endl;

    cout << "modulo_f(-2.7) " << modulo_f(-2.7) << endl;

    return 0;
}