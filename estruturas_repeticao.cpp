# include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
    int iContador = 0;
    while (iContador <= 5)
    {
        cout << iContador << "\n";
        iContador++;
    }


    iContador = 42;
    do
    {
        cout << iContador << "\n";
        iContador++;
    } while (iContador <= 5);


    for (int i = 1; i < 11; i++)
    {
        for (int j = 1; j < 11; j++)
        {
            for (int k = 1; k < 11; k++)
            {
                cout << "(" << i << "," << j << "," << k << ")" << "\n";
            }
        }
    }

    return 0;
}