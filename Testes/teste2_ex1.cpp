#include <iostream>

using std::cout;
using std::endl;
using std::string;
using std::to_string;

void calcularAno(int anosPassados)
{
    int ano = 2024 - anosPassados;
    string era = "";

    if (ano > 0)
    {
        cout << abs(ano) << " D.C";
    }
    else
    {
        cout << abs(ano) << " A.C";
    }
}

int main()
{
    calcularAno(10);
    return 0;
}