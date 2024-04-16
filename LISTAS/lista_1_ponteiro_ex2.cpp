#include <iostream>

using std::cout;
using std::endl;
using std::string;

// Definindo estruturas
typedef struct Disco
{
    int iData;
    Disco* ptrNext;
} Disco;

typedef struct Pino
{
    int iData;
    Disco* ptrTop;
} Pino;

// Assinaturas das funções
Disco* newDisco(int);
Pino* newPino(int);
void showPino(Pino* const);
void addDisco(Pino* const, int);
void dellDisco(Pino* const);
bool verificaOrdem(Pino* const);

int main()
{
    Pino* pino1 = newPino(1);
    Pino* pino2 = newPino(2);
    Pino* pino3 = newPino(3);

    addDisco(pino1, 5);
    addDisco(pino1, 4);
    addDisco(pino1, 3);
    addDisco(pino1, 2);
    addDisco(pino1, 1);

    cout << "------Voce possui 3 pinos------" << "\n\n";
    cout << "------Pino 1:------" << endl;
    showPino(pino1);
    cout << "\n\n";
    cout << "------Pino 2:------" << endl;
    showPino(pino2);
    cout << "\n\n";
    cout << "------Pino 3:------" << endl;
    showPino(pino3);
    cout << "\n\n";
    cout << "-------------------------------" << endl;

    return 0;
}

Disco* newDisco(int iValorDisco)
{
    Disco* disco = (Disco*) malloc(sizeof(Disco));
    disco->iData = iValorDisco;
    disco->ptrNext = nullptr;

    return disco; 
}

Pino* newPino(int iNumeroPino)
{
    Pino* pino = (Pino*) malloc(sizeof(Pino));
    pino->ptrTop = nullptr;
    pino->iData = iNumeroPino;

    return pino;
}

void showPino(Pino* const pino)
{
    if (pino->ptrTop == nullptr)
    {
        cout << "Pino vazio!" << endl;
    }
    
    Disco* current = pino->ptrTop;
    
    while (current != nullptr)
    {
        cout << "Disco: " << current->iData << endl;
        current = current->ptrNext;
    }
}

void addDisco(Pino* const pino, int iValor)
{
    Disco* disco = newDisco(iValor);

    disco->ptrNext = pino->ptrTop;
    pino->ptrTop = disco;

    if (verificaOrdem(pino) == true)
    {
        cout << "Disco " << disco->iData << " adicionado no pino " << pino->iData << endl;
    }
    else
    {
        dellDisco(pino);
        cout << "Voce nao pode adicionar um disco maior em cima de um disco menor!" << endl;
    }

    return;
}

void dellDisco(Pino* const pino)
{
    Disco* disco = pino->ptrTop;
    pino->ptrTop = pino->ptrTop->ptrNext;
    free(disco);
}

bool verificaOrdem(Pino* const pino)
{
    Disco* disco = pino->ptrTop;

    while (disco != nullptr && disco->ptrNext != nullptr)
    {
        if ((disco->iData) > (disco->ptrNext->iData))
        {
            return false;
        }
        disco = disco->ptrNext;
    }
    return true;
}

