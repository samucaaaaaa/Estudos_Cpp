#include <iostream>
#include <cmath>

using std::cout;
using std::cin;
using std::endl;
using std::string;

int is_prime(int);
void count_primes(int);

int main() 
{
    //cout << is_prime(1);

    count_primes(7);

    return 0;
}

int is_prime(int n)
{
    if (n >= 100000)
    {
        cout << "O numero e maior que 100000" << endl;
    }

    if (n <= 1)
    {
        return 0;
    }

    for (int i = 2; i <= n-1; i++)
    {
        if (n % i == 0)
        {
            return 0;
        }
    }
    return 1;
}

void count_primes(int n)
{
    for (int i = 1; i <= n; i++)
    {
        if (is_prime(i) == 1)
        {
            cout << i << endl;
        }
    }
}