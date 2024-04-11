#include <iostream>

using std::cout;
using std::endl;
using std::string;

// Criar uma estrutura para um nó
typedef struct Node
{
    int iData;
    struct Node* next;
}Node;

// Criar uma estrutura para uma fila
typedef struct Queue
{
    Node* front;
    Node* rear;
}Queue;

// Assinaturas das funções
Node* newNode(int);
Queue* newQueue();
void addElementQueue(Queue* const, int);
void dellFisrtElementQueue(Queue* const);
void showFirstElementQueue(Queue* const);
void showLastElementQueue(Queue* const);
void showElementsQueue(Queue* const);

int main()
{
    Queue* queue = newQueue();
    showFirstElementQueue(queue);
    cout << "--------" << endl;

    addElementQueue(queue, 2);
    addElementQueue(queue, 4);
    addElementQueue(queue, 6);
    addElementQueue(queue, 8);
    addElementQueue(queue, 10);

    showFirstElementQueue(queue);
    cout << "--------" << endl;
    showElementsQueue(queue);
    cout << "--------" << endl;
    dellFisrtElementQueue(queue);
    showElementsQueue(queue);
    cout << "--------" << endl;
    addElementQueue(queue, 1);
    showElementsQueue(queue);

    // OBS: em uma fila, quando adicionamos um novo elemento, ele irá para o final da fila

    return 0;
}

// Criar função que cria novo nó
Node* newNode(int iValor)
{
    Node* temp = (Node*) malloc(sizeof(Node));
    temp->iData = iValor;
    temp->next = nullptr;

    return temp;
}

// Criar função que cria uma nova fila
Queue* newQueue()
{
    Queue* temp = (Queue*) malloc(sizeof(Queue));
    temp->front = nullptr;
    temp->rear = nullptr;

    return temp;
}

// Criar função que adiciona um elemento na fila
void addElementQueue(Queue* const queue, int iValor)
{
    Node* temp = newNode(iValor);
    if (queue->front == nullptr)
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

// Criar função que exclui o primeiro elemento da fila
void dellFisrtElementQueue(Queue* const queue)
{
    if (queue->front == nullptr)
    {
        cout << "Fila vazia" << endl;
        return;
    }
    
    Node* temp = queue->front;

    cout << "Elemento removido: " << temp->iData << endl;

    queue->front = queue->front->next;

    if (queue->front == nullptr)
    {
        queue->rear == nullptr;
    }

    free(temp);

    return;
}

// Criar função que mostra o primeiro elemento da fila
void showFirstElementQueue(Queue* const queue)
{
    if (queue->front != nullptr)
    {
        cout << "Primeiro elemento: " << (queue->front)->iData << endl;
    }
    else
    {
        cout << "Fila vazia" << endl;
    }
}

// Criar função que mostra o último elemento da fila
void showLastElementQueue(Queue* const queue)
{
    if (queue->front != nullptr)
    {
        cout << "Ultimo elemento: " << (queue->rear)->iData << endl;
    }
    else
    {
        cout << "Fila vazia" << endl;
    }
}

// Criar função que mostra os elementos da fila
void showElementsQueue(Queue* const queue)
{
    if (queue->front == nullptr)
    {
        cout << "Fila vazia" << endl;
    }

    Node* current = queue->front;

    while (current != nullptr)
    {
        cout << "Elemento: " << current->iData << endl;
        current = current->next;
    }
}