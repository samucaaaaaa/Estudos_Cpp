#include <iostream>

using std::cout;
using std::endl;
using std::string;

typedef struct Node
{
    int iData;
    Node* next;
}Node;

typedef struct Stack
{
    Node* ptrTop;
}Stack;

Node* newNode(int);
Stack* newStack();
void showTopElements(Stack* const);
void showElementsStack(Stack* const);
void addElementStack(Stack* const, int);
void dellElementStack(Stack* const);

int main()
{
    Stack* stack = newStack();
    showTopElements(stack);
    cout << "----------------------" << endl;

    addElementStack(stack, 2);
    addElementStack(stack, 4);
    addElementStack(stack, 6);
    addElementStack(stack, 8);
    addElementStack(stack, 10);

    showTopElements(stack);
    cout << "----------------------" << endl;
    
    showElementsStack(stack);
    cout << "----------------------" << endl;

    dellElementStack(stack);
    cout << "----------------------" << endl;

    dellElementStack(stack);
    cout << "----------------------" << endl;

    showElementsStack(stack);
    cout << "----------------------" << endl;

    addElementStack(stack, 1);
    showElementsStack(stack);
    
    return 0;
}

Node* newNode(int iValor)
{
    Node* temp = (Node*) malloc(sizeof(Node));
    temp->iData = iValor;
    temp->next = nullptr;

    return temp;
}

Stack* newStack()
{
    Stack* temp = (Stack*) malloc(sizeof(Stack));
    temp->ptrTop = nullptr;

    return temp;
}

// Função que mostra o topo da pilha
void showTopElements(Stack* const stack)
{
    if (stack->ptrTop != nullptr)
    {
        cout << "Elemento do topo: " << (stack->ptrTop)->iData << endl;
    }
    else
    {
        cout << "Pilha vazia" << endl;
    }
}

// Função que mostra os elementos da pilha
void showElementsStack(Stack* const stack)
{
    if (stack->ptrTop == nullptr)
    {
        cout << "Pilha vazia" << endl;
    }

    Node* current = stack->ptrTop;

    while (current != nullptr)
    {
        cout << "Elemento: " << current->iData << endl;
        current = current->next;
    }
}

// Função que adiciona um elemento na pilha
void addElementStack(Stack* const stack, int iValor)
{
    Node* temp = newNode(iValor);

    temp->next = stack->ptrTop; // O ponteiro next vai apontar pro ponteiro que está no topo da pilha
    stack->ptrTop = temp; // O topo da pilha será atualizado para ser o novo nó 

    return;
}

// Função que deleta um elemento da pilha
void dellElementStack(Stack* const stack)
{
    if (stack->ptrTop == nullptr)
    {
        cout << "Pilha vazia" << endl;
    }

    cout << "Elemento removido: " << (stack->ptrTop)->iData << endl;

    Node* temp = stack->ptrTop;
    stack->ptrTop = stack->ptrTop->next;

    free(temp);
}