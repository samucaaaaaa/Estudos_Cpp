#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::string;

// Pilha - LIFO (Primeiro a entrar é o último a sair)

typedef struct Node
{
    int iData;
    Node* ptrNext;
} Node;

typedef struct Stack
{
    Node* ptrTop;
} Stack;

Node* newNode(int);
Stack* newStack();
void showTopElement(Stack* const);
void showElements(Stack* const);
void push(Stack* const, int);
void pop(Stack* const);

int main()
{
    Stack* stack = newStack();
    pop(stack);
    cout << "---" << endl;
    showTopElement(stack);
    showElements(stack);
    push(stack, 0);
    showTopElement(stack);
    showElements(stack);
    push(stack, 3);
    showTopElement(stack);
    showElements(stack);
    push(stack, 7);
    showTopElement(stack);
    showElements(stack);
    push(stack, 10);
    showTopElement(stack);
    showElements(stack);
    push(stack, 13);
    showTopElement(stack);
    showElements(stack);
    push(stack, 42);
    showTopElement(stack);
    cout << "---" << endl;
    showElements(stack);
    cout << "---" << endl;
    pop(stack);
    showTopElement(stack);
    cout << "---" << endl;
    cout << "=======================================================" << endl;
     
    return 0; 
}

Node* newNode(int iValue)
{
    Node* temp = (Node*) malloc(sizeof(Node));
    temp->iData = iValue;
    temp->ptrNext = nullptr;

    return temp;
}

Stack* newStack()
{
    Stack* temp = (Stack*) malloc(sizeof(Stack));
    temp->ptrTop = nullptr;

    return temp;
}

void push(Stack* const stack, int iValue)
{
    Node* temp = newNode(iValue);

    temp->ptrNext = stack->ptrTop;
    stack->ptrTop = temp;

    return;
}

void showTopElement(Stack* const stack)
{
    cout << "Topo da Pilha: " << ((stack->ptrTop != nullptr) ? stack->ptrTop->iData : -1) << endl;
}

void showElements(Stack* const stack)
{
    if(stack->ptrTop == nullptr)
    {
        cout << "Pilha Vazia" << endl;
        return;
    }

    Node* current = stack->ptrTop;

    while(current != nullptr)
    {
        cout << "Elemento: " << current->iData << endl;
        current = current->ptrNext;
    }
}

void pop(Stack* const stack)
{
    if(stack->ptrTop == nullptr)
    {
        cout << "Pilha Vazia" << endl;
        return;
    }

    cout << "Elemento Removido: " << stack->ptrTop->iData << endl;

    Node* temp = stack->ptrTop;

    stack->ptrTop = stack->ptrTop->ptrNext;

    free(temp);
}



