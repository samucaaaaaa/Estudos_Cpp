#include <iostream>
#include <cmath>

using std::cout;
using std::cin;
using std::endl;
using std::string;

unsigned long long fatorial(int n)
{
    if (n <= 1)
    {
        return 1;
    }

    return n * fatorial(n-1);
}

void imprimiSequenciaFatorial(int n)
{
    for (int i = 1; i <= n; i++)
    {
        cout << fatorial(i) << " ";
    }
}

void imprimiFatorial(int n)
{
    for (int i = n; i > 0; i--)
    {
        if (i == 1)
        {
            cout << i << " = " << fatorial(n);
        }
        else
        {
            cout << i << ".";
        }
    }
}

int main ()
{
    //imprimiSequenciaFatorial(5);

    imprimiFatorial(5);

    return 0;
}