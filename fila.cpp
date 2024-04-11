#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::string;

// Fila - FIFO (Primeiro a entrar é o o primeiro a sair)

typedef struct Node
{
    int iData;
    struct Node* next;
} Node;

typedef struct Queue
{
    Node* front;
    Node* rear;
} Queue;

Node* newNode(int iValue)
{
    Node* temp = (Node*) malloc(sizeof(Node));
    temp->iData = iValue;
    temp->next = nullptr;

    return temp;
}

Queue* newQueue()
{
    Queue* temp = (Queue*) malloc(sizeof(Queue));
    temp->front = nullptr;
    temp->rear = nullptr; 

    return temp;
}

// Adiciona um elemento na fila
void enQueue(Queue* const queue, int iValue)
{
    Node* temp = newNode(iValue);

    if (queue->rear == nullptr)
    {
        queue->front = temp;
        queue->rear = temp;
    }
    else 
    {
        queue->rear->next = temp;
        queue->rear = temp;
    }
    return;
}

// Remove o primeiro elemento da fila
void deQueue(Queue* const queue)
{
    if (queue->front == nullptr)
    {
        cout << "Fila Vazia" << endl;
        return;
    }

    Node* temp = queue->front;

    cout << "Elemento Removido: " << temp->iData << endl;

    queue->front = queue->front->next;

    if (queue->front == nullptr)
    {
        queue->rear = nullptr;
    }

    free(temp);    

    return;
}

void showFirstElement(Queue* const queue)
{
    cout << "Primeiro Elemento: " << ((queue->front != NULL) ? (queue->front)->iData : -1)  << endl;
}

void showLastElement(Queue* const queue)
{
    cout << "Ultimo Elemento: " << ((queue->front != NULL) ? (queue->rear)->iData : -1)  << endl;
}

void showElements(Queue* const queue)
{
    if (queue->front == nullptr)
    {
        cout << "Fila Vazia" << endl;
        return;
    }

    Node* current = queue->front;

    while (current != nullptr)
    {
        cout << "Elemento: " << current->iData << endl;
        current = current->next;
    }
}

int main()
{
    // 1. Estrutura de um nó
    // 2. Estrutura de uma fila
    // 3. Função que cria uma fila
    // 4. Funçaõ que cria im nó
    // 5. Função que enfileira um nó
    // 6. Função que exibe o primeiro elemento
    // 7. Função que exibe o último elemento
    // 8. Função que exibe os elementos
    // 9. Função que remove um nó

    Queue* queue = newQueue();
    showFirstElement(queue);
    showLastElement(queue);
    cout << "---" << endl;
    showElements(queue);
    deQueue(queue);
    cout << "===================================================" << endl;

    enQueue(queue, 0);
    showFirstElement(queue);
    showLastElement(queue);
    cout << "---" << endl;
    showElements(queue);
    deQueue(queue);
    cout << "===================================================" << endl;

    enQueue(queue, 3);
    enQueue(queue, 7);
    enQueue(queue, 13);
    enQueue(queue, 42);
    showFirstElement(queue);
    showLastElement(queue);
    cout << "---" << endl;
    showElements(queue);
    cout << "===================================================" << endl;

    return 0;   
}