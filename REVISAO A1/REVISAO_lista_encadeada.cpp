#include <iostream>

using std::cout;
using std::endl;
using std::string;

typedef struct Node
{
    int iData;
    Node* next;
}Node;

typedef struct LinkedList
{
    Node* ptrFirst;
}LinkedList;

Node* newNode(int);
LinkedList* newLinkedList();
void showFirstElement(LinkedList* const);
void showLastElement(LinkedList* const);
void showElements(LinkedList* const);
void addElement(LinkedList* const, int);
void dellElement(LinkedList* const, int);
void ordenaLista(LinkedList* const, bool);//TODO: fazer função que pega os elementos de uma lista e ordena eles
void deletaIguais(LinkedList* const);//TODO: fazer função que deleta todos os elementos iguais da lista
void deletaTodosN(LinkedList* const, int);//TODO: fazer função que deleta todos os elementos 'n' da lista

int main()
{
    LinkedList* linkedList = newLinkedList();
    showFirstElement(linkedList);
    cout << "---------------" << endl;

    addElement(linkedList, 2);
    addElement(linkedList, 4);
    addElement(linkedList, 6);
    addElement(linkedList, 8);
    addElement(linkedList, 10);

    showFirstElement(linkedList);
    cout << "---------------" << endl;

    showElements(linkedList);
    cout << "---------------" << endl;

    dellElement(linkedList, 2);
    showElements(linkedList);
    cout << "---------------" << endl;

    dellElement(linkedList, 2);
    cout << "---------------" << endl;

    dellElement(linkedList, 8);
    showElements(linkedList);
    cout << "---------------" << endl;

    addElement(linkedList, 1);
    showElements(linkedList);
    cout << "---------------" << endl;

    ordenaLista(linkedList, false);
    showElements(linkedList);
    cout << "---------------" << endl;

    addElement(linkedList, 10);
    addElement(linkedList, 4);
    showElements(linkedList);
    cout << "---" << endl;
    deletaIguais(linkedList);
    showElements(linkedList);
    cout << "---------------" << endl;

    addElement(linkedList, 10);
    addElement(linkedList, 10);
    showElements(linkedList);
    deletaTodosN(linkedList, 10);

    return 0;
}

Node* newNode(int iValor)
{
    Node* temp = (Node*) malloc(sizeof(Node)); 
    temp->iData = iValor;
    temp->next = nullptr;

    return temp;
}

LinkedList* newLinkedList()
{
    LinkedList* temp = (LinkedList*) malloc(sizeof(LinkedList));
    temp->ptrFirst = nullptr;

    return temp;
}

void showFirstElement(LinkedList* const linkedList)
{
    if (linkedList == nullptr || linkedList->ptrFirst == nullptr)
    {
        cout << "Lista vazia" << endl;
    }
    else
    {
        cout << "Primeiro elemento: " << (linkedList->ptrFirst)->iData << endl;
    }
}

void showLastElement(LinkedList* const linkedList)
{
    if (linkedList == nullptr || linkedList->ptrFirst == nullptr)
    {
        cout << "Lista vazia" << endl;
    }
    else
    {
        Node* lastNode = linkedList->ptrFirst;

        while (lastNode->next != nullptr)
        {
            lastNode = lastNode->next;
        }
        cout << "Ultimo elemento: " << lastNode->iData << endl;
    }
}

void showElements(LinkedList* const linkedList)
{
    if (linkedList == nullptr || linkedList->ptrFirst == nullptr)
    {
        cout << "Lista vazia" << endl;
    }
    else
    {
        Node* current = linkedList->ptrFirst;

        while (current != nullptr)
        {
            cout << "Elemento: " << current->iData << endl;
            current = current->next;
        }
    }
}

void addElement(LinkedList* const linkedList, int iValor)
{
    Node* temp = newNode(iValor);

    if (linkedList->ptrFirst == nullptr)
    {
        linkedList->ptrFirst = temp;
    }
    else
    {
        Node* lastNode = linkedList->ptrFirst;

        while (lastNode->next != nullptr)
        {
            lastNode = lastNode->next;
        }
        lastNode->next = temp;
    }
}

void dellElement(LinkedList* const linkedList, int iValor)
{
    // 1° Caso: Lista inexistente ou vazia
    if (linkedList == nullptr || linkedList->ptrFirst == nullptr)
    {
        cout << "Lista vazia" << endl;

        return;
    }

    Node* current = linkedList->ptrFirst;

    // 2° Caso: O primeiro elemento da lista foi o selecionado
    if (current->iData == iValor)
    {
        linkedList->ptrFirst = linkedList->ptrFirst->next;
        free(current);

        return;
    }

    Node* previous = linkedList->ptrFirst;

    while (current != nullptr && current->iData != iValor)
    {
        previous = current;
        current = current->next;
    }
    
    // 3° Caso: O elemento não foi encontrado na lista
    if (current == nullptr)
    {
        cout << "Esse elemento nao esta na lista!" << endl;

        return;
    }

    // Quando ele é encontrado fazemos:
    previous->next = current->next;
    free(current); 

    return;
}

void ordenaLista(LinkedList* const linkedList, bool ordem)
{
    Node* current = linkedList->ptrFirst;

    while (current->next != nullptr)
    {
        Node* current2 = current->next;
        while (current2 != nullptr)
        {
            if (ordem == true)
            {
                if (current->iData > current2->iData)
                {
                    int aux = current->iData;
                    current->iData = current2->iData;
                    current2->iData = aux;
                }
                current2 = current2->next;
            }
            else
            {
                if (current->iData < current2->iData)
                {
                    int aux = current->iData;
                    current->iData = current2->iData;
                    current2->iData = aux;
                }
                current2 = current2->next;
            }    
        }
        current = current->next;
    }
}

void deletaIguais(LinkedList* const linkedList)
{
    Node* current = linkedList->ptrFirst;

    while (current->next != nullptr)
    {
        Node* prev = current;
        Node* current2 = current->next;
        while (current2 != nullptr)
        {
            if (current->iData == current2->iData)
            {
                prev->next = current2->next;
                free(current2);
                current2 = prev->next;
            }
            else 
            {
                prev = current2;
                current2 = current2->next;
            }
        }
        current = current->next;
    }
}

void deletaTodosN(LinkedList* const linkedList, int iValor)
{
    Node* current = linkedList->ptrFirst;

    // Caso o primeiro foi selecionado
    if (current->iData == iValor)
    {
        linkedList->ptrFirst = linkedList->ptrFirst->next;
        free(current);
    }

    while (current->next != nullptr)
    {
        Node* temp = current;
        Node* future = current->next;
        while (future != nullptr)
        {
            if (future->iData == iValor)
            {
                temp->next = future->next;
                free(future);
                future = temp->next;
            }
            else
            {
                temp = future;
                future = future->next;
            }
        }
        current = current->next;
    }
}

