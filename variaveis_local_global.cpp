#include <iostream>

using namespace std;

// Variáveis globais:
int n4, n5;

int main(){
    
    // Variáveis locais:
    int n1, n2, n3;
    int resultado1, resultado2;
    
    // Operadores Matemáticos: + - / * %
    n1 = 11;
    n2 = 3;
    n3 = 5;
    n4 = 2;
    
    resultado1 = n1+n2+n3+n4;
    resultado2 = n1%n2;
    
    cout << "Soma das variáveis: " << resultado1 << "\n\n";
    cout << "Resto da divisão de n1 por n2: " << resultado2 << "\n\n";
    
    // Incremento:
    
    cout << "Incremento:\n"; 
    cout << n1 << "\n";
    
    // n1 = n1+1;
    // n1 += 1;
    n1++;
    
    cout << n1 << "\n\n";
    
    // Decremento:
    
    cout << "Decremento:\n";
    cout << n1 << "\n";
    
    // n1 = n1 - 1;
    // n1 -= 1;
    n1--;
    
    cout << n1 << "\n\n";
    
    // Pré e Pós incremento:
    
    // (pós)n1++ = (pré)++n1 
    
    /* A única diferença vista é na hora de imprimir o valor.
       
       Quando queremos imprimir o valor incrementado, é mais útil
       utilizar pré-incremento. Observe:
    */
    
    // Valor de n1:
    cout << "Valor de n1: " << n1 << "\n";
    
    // Pós-incremento (não funciona na hora):
    cout << "Pós-incremento: " << n1++ << "\n";
    
    // Novo valor de n1:
    cout << "Novo valor de n1: " << n1 << "\n";
    
    // Pré-incremento (funciona):
    cout << "Pré-incremento: " << ++n1 << "\n";
    
    return 0;
}



