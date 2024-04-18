#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main() {
    int n;

    cout << "Informe um numero: " << endl;
    cin >> n;

    for (int i = 1; i <= n; i++) 
    {
        // Imprimir espaços à esquerda
        for (int j = 1; j <= n - i; j++) 
        {
            cout << " ";
        }

        // Imprimir caracteres '#'
        for (int j = 1; j <= 2 * i; j++) 
        {
            cout << "#";
        }

        cout << endl;
    }

    for (int i = n-1; i > 0; i--)
    {
        for (int j = 0; j < n - i; j++)
        {
            cout << " ";
        }

        for (int j = 1; j <= 2 * i; j++)
        {
            cout << "#";
        }
        cout << endl;
    }

    return 0;
}