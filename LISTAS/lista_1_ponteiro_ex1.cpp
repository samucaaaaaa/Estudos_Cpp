#include <iostream>

using std::cout;
using std::endl;
using std::string;

// Estruturas utilizadas
typedef struct Aluno
{
    int iMatricula;
    Aluno* ptrNext;
} Aluno;

typedef struct LinkedList
{
    Aluno* ptrFirst;
} LinkedList;

// Assinaturas das funções
Aluno* newAluno(int);
LinkedList* newLinkedList();
void showElements(LinkedList* const);
void addAluno(LinkedList* const, int);
void dellAluno(LinkedList* const, int);
void trocaPosicoes(LinkedList* const);
LinkedList* encontraIntersecao(LinkedList* const, LinkedList* const);
bool encontraLoop(LinkedList* const);
//int tamanhoLoop(LinkedList* const); //TODO: fazer essa função

int main()
{
    LinkedList* linkedList1 = newLinkedList();
    showElements(linkedList1);
    cout << "----------------" << endl;

    addAluno(linkedList1, 1);
    addAluno(linkedList1, 2);
    addAluno(linkedList1, 3);
    addAluno(linkedList1, 4);
    addAluno(linkedList1, 1);
    addAluno(linkedList1, 5);
    addAluno(linkedList1, 6);
    addAluno(linkedList1, 1);
    addAluno(linkedList1, 7);
    showElements(linkedList1);
    cout << "----------------" << endl;

    dellAluno(linkedList1, 1);
    showElements(linkedList1);
    cout << "----------------" << endl;

    trocaPosicoes(linkedList1);
    showElements(linkedList1);
    cout << "----------------" << endl;

    LinkedList* linkedList2 = newLinkedList();
    
    addAluno(linkedList2, 2);
    addAluno(linkedList2, 4);
    addAluno(linkedList2, 6);
    addAluno(linkedList2, 8);
    addAluno(linkedList2, 2);
    showElements(linkedList2);
    cout << "----------------" << endl;

    LinkedList* novaLista = encontraIntersecao(linkedList1, linkedList2);
    showElements(novaLista);
    cout << "----------------" << endl;

    //LinkedList* lista3 = newLinkedList();
    if (encontraLoop(linkedList2)) {
        cout << "Loop encontrado na lista linkedList2!" << endl;
    } else {
        cout << "Nenhum loop encontrado na lista linkedList2." << endl;
    }
    cout << "----------------" << endl;

    //cout << tamanhoLoop(linkedList2) << endl;


    return 0;
}

Aluno* newAluno(int iValor)
{
    Aluno* temp = (Aluno*) malloc(sizeof(Aluno));
    temp->iMatricula = iValor;
    temp->ptrNext = nullptr;

    return temp;
}

LinkedList* newLinkedList()
{
    LinkedList* temp = (LinkedList*) malloc(sizeof(LinkedList));
    temp->ptrFirst = nullptr;

    return temp;
}

void showElements(LinkedList* const linkedList)
{
    if (linkedList == nullptr || linkedList->ptrFirst == nullptr)
    {
        cout << "Lista vazia!" << endl;
    }
    else
    {
        Aluno* current = linkedList->ptrFirst;

        while (current != nullptr)
        {
            cout << "Matricula: " << current->iMatricula << endl;
            current = current->ptrNext;
        }
    }
}

void addAluno(LinkedList* const linkedList, int iNumero)
{
    Aluno* temp = newAluno(iNumero);
    
    if (linkedList->ptrFirst == nullptr)
    {
        linkedList->ptrFirst = temp;
    }
    else
    {
        Aluno* lastAluno = linkedList->ptrFirst;

        while (lastAluno->ptrNext != nullptr)
        {
            lastAluno = lastAluno->ptrNext;
        }
        lastAluno->ptrNext = temp;
    }    
}

void dellAluno(LinkedList* const linkedList, int iNumero)
{

    if (linkedList == nullptr || linkedList->ptrFirst == nullptr)
    {
        cout << "Lista vazia!" << endl;
    }

    Aluno* current = linkedList->ptrFirst;

    // Verificando se a matrícula é do primeiro aluno da lista
    if (current->iMatricula == iNumero)
    {
        cout << "Aluno deletado: " << current->iMatricula << endl;
        linkedList->ptrFirst = linkedList->ptrFirst->ptrNext;
        free(current);

        return;
    }

    Aluno* previous = linkedList->ptrFirst;

    while (current->ptrNext != nullptr)
    {
        previous = current;
        current = current->ptrNext;
    }

    // Verificando se o aluno foi encontrado
    if (current == nullptr)
    {
        cout << "Esse aluno nao esta na lista de matriculas!" << endl;
    }

    // Quando o aluno é encontrado
    previous->ptrNext = current->ptrNext;
    free(current);

    return;
}

void trocaPosicoes(LinkedList* const linkedList)
{
    if (linkedList == nullptr || linkedList->ptrFirst == nullptr)
    {
        cout << "Lista vazia!" << endl;
    }
    else if (linkedList->ptrFirst->ptrNext == nullptr)
    {
        cout << "A lista tem apenas 1 elemento!" << endl;
    }

    Aluno* firstAluno = linkedList->ptrFirst;
    Aluno* lastAluno = linkedList->ptrFirst;

    while (lastAluno->ptrNext != nullptr)
    {
        lastAluno = lastAluno->ptrNext;
    }

    // Trocando posições
    int auxiliar = firstAluno->iMatricula;
    firstAluno->iMatricula = lastAluno->iMatricula;
    lastAluno->iMatricula = auxiliar;
}

LinkedList* encontraIntersecao(LinkedList* const lista1, LinkedList* const lista2)
{
    LinkedList* resultado = newLinkedList();
    Aluno* current1 = lista1->ptrFirst;
    
    while (current1 != nullptr)
    {
        Aluno* current2 = lista2->ptrFirst;
        while (current2 != nullptr)
        {
            if (current1->iMatricula == current2->iMatricula)
            {
                addAluno(resultado, current1->iMatricula);
                break; // Se encontrou, sai do loop interno
            }
            current2 = current2->ptrNext;
        }
        current1 = current1->ptrNext;
    }
    return resultado;
}

bool encontraLoop(LinkedList* const linkedList)
{
    if (linkedList == nullptr || linkedList->ptrFirst == nullptr)
    {
        return false;
    }
    
    if (linkedList->ptrFirst->ptrNext == nullptr)
    {
        return false;
    }

    Aluno* firstAluno = linkedList->ptrFirst;
    Aluno* current1 = linkedList->ptrFirst;

    // Verificando se há loop 
    while (current1->ptrNext != nullptr)
    {
        Aluno* current2 = current1->ptrNext;
        while (current2->ptrNext != nullptr)
        {
            if (current1->iMatricula == current2->iMatricula)
            {
                return true;
            }
            current2 = current2->ptrNext;
        }
        if (firstAluno->iMatricula == current2->iMatricula)
        {
            return true;
        }
        if (current1->iMatricula == current2->iMatricula)
        {
            return true;
        }
        current1 = current1->ptrNext;
    }

    // Caso não tenha encontrado loop
    return false;
}







