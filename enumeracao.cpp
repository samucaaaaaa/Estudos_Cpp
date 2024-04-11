#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::string;

//TODO: Revisar Enum

int main()
{
    enum Streaming {AppleTV, AmazonPrime, CrunchyRoll, DisneyPlus, NetFlix, MAx};

    Streaming streamingSubscription = CrunchyRoll;

    switch (streamingSubscription)
    {
    case AppleTV:
        cout << "Nunca usei... não sei como é... [" << streamingSubscription << "]" << endl; 
        break;
    
    case CrunchyRoll:
        cout << "Muito bom... [" << streamingSubscription << "]" << endl;
        break;
    default:
        cout << "NADA" << endl;
    }

    cout << "=========================================================" << endl;

    enum Mes {JANEIRO = 1, FEVEREIRO, MARCO, ABRIL, MAIO};

    Mes mesProvas = MAIO;
    cout << mesProvas << endl;

    enum Semana {SEGUNDA = 10, TERCA = 1, QUARTA = -3};

    Semana diaPalestra = QUARTA;
    cout << diaPalestra << endl;

    return 0;
}