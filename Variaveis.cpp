#include <iostream>

using namespace std;

int main(){
    
    // VARIÁVEIS:
    
    // TIPO NOME;
    // TIPO NOME = VALOR;
    // TIPO NOME1, NOME2, NOME3;
    
    int vidas; 
    char letra = 'S'; // Para um caracter se usa '' 
    double decimal;
    float decimal2;
    bool vivo;
    string nome = "Samuel";
    char letras[11] = "SamuelLima"; // Podemos usar um char como um vetor, fazendo assim, tipo uma palvra
    // OBS: Há 10 caracteres, mas devemos colocar 11 pq existe o nulo
    
    vidas = 7;
    
    // Fazendo o usuário add um valor a variável:
    cout << "Informe '1' para true ou '0' para false na variável vivo: ";
    cin >> vivo;
    
    cout << endl <<letra << endl; 
    cout << nome << "\n";
    cout << letras << endl;
    cout << decimal << "\n" << decimal2 << endl << vidas << endl << vivo;
    
    return 0;
}



