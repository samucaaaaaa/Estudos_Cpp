#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

typedef struct Node
{
    int iData;
    Node* ptrNext;
} Node;

typedef struct LinkedList
{
    Node* ptrFirst;
} LinkedList;

LinkedList* newLinkedList();
Node* newNode(int);
void showFirstElement(LinkedList* const);
void showLastElement(LinkedList* const);
void showElements(LinkedList* const);
void addElement(LinkedList* const, int);
void removeElement(LinkedList* const, int);

int main()
{
    LinkedList* linkedList = newLinkedList();
    showFirstElement(linkedList);
    showLastElement(linkedList);
    showElements(linkedList);
    removeElement(linkedList, 666);
    cout << "===========================" << endl;
    addElement(linkedList, 0);
    showFirstElement(linkedList);
    showLastElement(linkedList);
    showElements(linkedList);
    addElement(linkedList, 3);
    showFirstElement(linkedList);
    showLastElement(linkedList);
    showElements(linkedList);
    cout << "===========================" << endl;
    addElement(linkedList, 7);
    addElement(linkedList, 10);
    addElement(linkedList, 13);
    addElement(linkedList, 42);
    showFirstElement(linkedList);
    showLastElement(linkedList);
    showElements(linkedList);
    cout << "===========================" << endl;
    removeElement(linkedList, 0);
    removeElement(linkedList, 3);
    showFirstElement(linkedList);
    showLastElement(linkedList);
    showElements(linkedList);
    removeElement(linkedList, 666);
    removeElement(linkedList, 10);
    removeElement(linkedList, 13);
    showFirstElement(linkedList);
    showLastElement(linkedList);
    showElements(linkedList);
    
    return 0;
}

LinkedList* newLinkedList()
{
    LinkedList* temp = (LinkedList*) malloc(sizeof(LinkedList));
    temp->ptrFirst = nullptr;

    return temp;
}

Node* newNode(int iValue)
{
    Node* temp = (Node*) malloc(sizeof(Node));
    temp->iData = iValue;
    temp->ptrNext = nullptr;

    return temp;
}

void showFirstElement(LinkedList* const linkedList)
{
    if (linkedList == nullptr || linkedList->ptrFirst == nullptr)
    {
        cout << "showFirstElement: Lista Vazia" << endl;
    }
    else
    {
        cout << "Primeiro da Lista: " << linkedList->ptrFirst->iData << endl;
    }
}

void showLastElement(LinkedList* const linkedList)
{
    if (linkedList == nullptr || linkedList->ptrFirst == nullptr)
    {
        cout << "showLastElement: Lista Vazia" << endl;
    }
    else
    {
        Node* lastNode = linkedList->ptrFirst;

        while (lastNode->ptrNext != nullptr)
        {
            lastNode = lastNode->ptrNext;
        }
        cout << "Último da Lista: " << lastNode->iData << endl;
    }
}

void showElements(LinkedList* const linkedList)
{
    if (linkedList == nullptr || linkedList->ptrFirst == nullptr)
    {
        cout << "showElements: Lista Vazia" << endl;
    }
    else
    {
        Node *current = linkedList->ptrFirst;

        cout << "Elementos da Lista:";

        while (current != nullptr)
        {
            cout << " " << current->iData;
            current = current->ptrNext;
        }

        cout << endl;
    }
}

void addElement(LinkedList* const linkedList, int iValue)
{
    Node* temp = newNode(iValue);

    if (linkedList->ptrFirst == nullptr)
    {
        linkedList->ptrFirst = temp;
    }
    else
    {
        Node* lastNode = linkedList->ptrFirst;

        while (lastNode->ptrNext != nullptr)
        {
            lastNode = lastNode->ptrNext;
        }
        lastNode->ptrNext = temp;
    }
}

void removeElement(LinkedList* const linkedList, int iValue)
{
    //Saindo de fininho - caso especial 1: lista vazia ou inexistente
    if (linkedList == nullptr || linkedList->ptrFirst == nullptr)
    {
        cout << "removeElement: Lista Vazia" << endl;
        return;
    }

    Node* current = linkedList->ptrFirst;

    //Segundo caso especial - o primeiro nó é o escolhido
    if (current->iData == iValue)
    {
        linkedList->ptrFirst = linkedList->ptrFirst->ptrNext;

        free(current);
        return;
    }
    Node* previous = linkedList->ptrFirst;
    while (current != nullptr && current->iData != iValue)
    {
        previous = current;
        current = current->ptrNext;
    }

    // Saimos de fininho - terceiro caso especial - elemento não encontrado
    if (current == nullptr) return;

    //Reparar a lista para remoção
    previous->ptrNext = current->ptrNext;

    free(current);
}