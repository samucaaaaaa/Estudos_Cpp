#include <iostream>

using std::cout;
using std::endl;

int main()
{
    /*
    // Não é bom utilizar o auto (que faz o próprio compilador decidir o tipo da variável)
    auto i = 1;
    
    cout << "Exemplo de incrementos: " << "\n";
    cout << "Valor de i: " << i << "\n";
    
    auto c = ++i; // Pré incremento
    
    cout << "Valor de c: " << c << "\n";
    
    return 0;
    */
    
    // Hungarian Notation. Systems Hungarian x Apps. Hungarian 
    
    int iNum = 42;
    
    cout << "Valor de Num: " << iNum << endl;
    
    iNum = 111;
    
    cout << "Valor de Num: " << iNum << endl;
    cout << "Endereço de Num: " << &iNum << endl; // O & serve para saber em qual local da memória que a minha variável está armazenada
    
    return 0;
}

