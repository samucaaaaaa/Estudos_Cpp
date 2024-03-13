#include <iostream>
#include <cmath>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int soma(int iValor1, int iValor2)
{
    return iValor1 + iValor2;
}

int soma(int iValor1, int iValor2, int iValor3)
{
    return iValor1 + iValor2 + iValor3;
}

float soma(float iValor1, float iValor2, float iValor3)
{
    return iValor1 + iValor2 + iValor3;
}

int main()
{
    int iNum1 = 10;
    int iNum2 = 20;
    int iNum3 = 30;

    cout << soma(iNum1, iNum3) << endl;
    cout << soma(iNum1, iNum2, iNum3) << endl;

    cout << "=================================";
}