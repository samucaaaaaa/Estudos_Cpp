#include <iostream>

//using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
    /*
    int iValor = 42;
    int iValorLido = 0;
    int iResultado = 0;

    cin >> iValorLido;

    // Operador Ternário
    iResultado = (iValorLido < iValor) ? 0 : 1;

    cout << "Resultado: " << iResultado << endl;
    */
    
    int iDia = 1;

    switch (iDia)
    {
        case 1:
            cout << "Segunda-feira" << endl;
            break;
        case 2:
            cout << "Terça-feira" << endl;  
            break;
        case 3:
            cout << "Quarta-feira" << endl;
            break;      
    }

    return 0;
}