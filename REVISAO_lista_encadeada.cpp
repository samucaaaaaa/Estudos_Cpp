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
