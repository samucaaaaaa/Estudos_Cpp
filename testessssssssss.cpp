#include <iostream>

using std::cout;
using std::endl;

// Estrutura do nó
typedef struct Node
{
    int iPayload;
    Node* ptrNext;
    Node* ptrPrev;
} Node;

// Assinaturas das funções:
Node* createNode(int);
void displayList(Node*);
void insertFront(Node**, int);
void insertEnd(Node**, int);
void insertAfter(Node*, int);
void insertBefore(Node**, Node*, int);
Node* searchNodebyValue(Node**, int);
void deleteNode(Node**, Node*);
void deleteNodebyValue(Node**, int);
bool findNodebyValue(Node**, int);
void deleteAllNodesbyValue(Node**, int);
bool findCycle(Node**);
int findSizeOfCycle(Node**);

int main()
{
    Node* head = nullptr;

    /*
    insertEnd(&head, 1);
    insertEnd(&head, 2);
    insertFront(&head, 3);
    insertAfter(head, 4);
    insertAfter(head, 5);

    insertAfter(searchNodebyValue(&head, 4), 7);

    displayList(head);

    deleteNode(&head, searchNodebyValue(&head, 7));
    deleteNode(&head, searchNodebyValue(&head, 3));
    deleteNode(&head, searchNodebyValue(&head, 2));

    insertAfter(searchNodebyValue(&head, 1), 4);

    insertBefore(&head, searchNodebyValue(&head, 5), 9);

    displayList(head);

    deleteAllNodesbyValue(&head, 4);

    displayList(head);

    insertEnd(&head, 20);
    insertAfter(searchNodebyValue(&head, 9), 20);

    displayList(head);

    if (findCycle(&head) == true)
    {
        cout << "Tem ciclo" << endl;
    }

    cout << "Tamanho do ciclo: " << endl;
    cout << findSizeOfCycle(&head);
    */

    insertEnd(&head, 1);
    insertEnd(&head, 2);
    insertEnd(&head, 0);
    insertEnd(&head, 2);
    insertEnd(&head, 4);
    insertEnd(&head, 3);

    cout << findSizeOfCycle(&head);


    return 0;
}

Node* createNode(int iValor)
{
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->iPayload = iValor;
    newNode->ptrNext = nullptr;
    newNode->ptrPrev = nullptr;
}

// Funções:

void displayList(Node* head)
{
    // Verificando se a lista está vazia
    if (head == nullptr)
    {
        cout << "Erro! Lista vazia." << endl;

        return;
    }

    // Verificando se o ponteiro head não é o primeiro
    if (head->ptrPrev != nullptr)
    {
        cout << "Erro! O ponteiro nao e o primeiro da lista" << endl;

        return;
    }

    Node* temp = head;

    cout << "Lista: ";

    // Percorrendo todos os ponteiros da lista
    while (temp != nullptr)
    {
        cout << temp->iPayload << " ";
        temp = temp->ptrNext;
    }

    cout << endl;
}

void insertFront(Node** head, int iValor)
{
    Node* newNode = createNode(iValor);

    // Se a lista não for vazia
    if (*head != nullptr)
    {
        (*head)->ptrPrev = newNode;
        newNode->ptrNext = (*head);
        (*head) = newNode;

        return;
    }

    // Se a lista for vazia
    (*head) = newNode;
}

void insertEnd(Node** head, int iValor)
{
    Node* newNode = createNode(iValor);

    // Se a lista for vazia
    if (*head == nullptr)
    {
        (*head) = newNode;

        return;
    }

    // Se a lista não for vazia
    Node* temp = *head;

    // Encontrando o último nó
    while (temp->ptrNext != nullptr)
    {
        temp = temp->ptrNext;
    }

    temp->ptrNext = newNode;
    newNode->ptrPrev = temp;
}

void insertAfter(Node* ptrLocation, int iValor)
{
    Node* newNode = createNode(iValor);

    // Se ptrLocation for NULL
    if (ptrLocation == nullptr)
    {
        cout << "Erro! ptrLocation esta nulo." << endl;

        return;
    }

    // Corrigindo newNode
    newNode->ptrPrev = ptrLocation;
    newNode->ptrNext = ptrLocation->ptrNext;

    // Corrigindo ptrLocation
    ptrLocation->ptrNext = newNode;

    // Se newNode->ptrNext não for NULL, corrige o nó após newNode
    if (newNode->ptrNext != nullptr)
    {
        newNode->ptrNext->ptrPrev = newNode;
    }
}

void insertBefore(Node** head, Node* ptrLocation, int iValor)
{
    Node* newNode = createNode(iValor);

    // Se ptrLocation for NULL
    if (ptrLocation == nullptr)
    {
        cout << "Erro! ptrLocation esta nulo." << endl;

        return;
    }

    // Se ptrLocation é o primeiro nó da lista
    if (ptrLocation->ptrPrev == nullptr)
    {
        // Atualiza o ponteiro head para apontar para o newNode
        *head = newNode;
    }

    // Corrigindo newNode
    newNode->ptrNext = ptrLocation;
    newNode->ptrPrev = ptrLocation->ptrPrev;

    // Se ptrLocation->ptrPrev não for NULL, corrige o nó antes de ptrLocation
    if (ptrLocation->ptrPrev != nullptr)
    {
        ptrLocation->ptrPrev->ptrNext = newNode;
    }

    // Corrigindo ptrLocation
    ptrLocation->ptrPrev = newNode;
}

Node* searchNodebyValue(Node** head, int iValor)
{
    // Verificando se a lista é vazia
    if (*head == nullptr)
    {
        cout << "Erro! Lista vazia." << endl;

        return nullptr;
    }

    Node* current = *head;

    // Encontrando o nó
    while (current != nullptr)
    {
        if (current->iPayload == iValor)
        {
            return current;
        }
        current = current->ptrNext;
    }
    return nullptr;
}

void deleteNode(Node** head, Node* ptrDelete)
{
    // Verificando se há nó nulo
    if (*head == nullptr || ptrDelete == nullptr)
    {
        cout << "Erro! Ha um no nulo" << endl;

        return;
    }

    // Se ptrDelete for o primeiro nó
    if (ptrDelete == *head)
    {
        (*head) = ptrDelete->ptrNext;
    }

    // Se ptrDelete não for o ultimo nó
    if (ptrDelete->ptrNext != nullptr)
    {
        ptrDelete->ptrNext->ptrPrev = ptrDelete->ptrPrev;
    }

    // Se ptrDelete não é o primeiro nó
    if (ptrDelete->ptrPrev != nullptr)
    {
        ptrDelete->ptrPrev->ptrNext = ptrDelete->ptrNext;
    }

    free(ptrDelete);
}

void deleteNodebyValue(Node** head, int iValor)
{
    // Procurando o nó
    Node* temp = searchNodebyValue(head, iValor);

    // Deletando o nó
    deleteNode(head, temp);
}

bool findNodebyValue(Node** head, int iValor)
{
    bool encontrou = false;
    Node* current = *head;

    while (encontrou == false && current != nullptr)
    {
        if (current->iPayload == iValor)
        {
            encontrou = true;
            return encontrou;
        }
        current = current->ptrNext;
    }
    return false;
}

void deleteAllNodesbyValue(Node** head, int iValor)
{
    if (searchNodebyValue(head, iValor) == nullptr)
    {
        cout << "Nao tem esse valor na lista" << endl;

        return;
    }

    Node* current = *head;

    // Procurando os nós
    while (current != nullptr)
    {
        if (findNodebyValue(head, iValor) == true)
        {
            deleteNodebyValue(head, iValor);
        }
        current = current->ptrNext;
    }
}

bool findCycle(Node** head)
{
    bool encontrou = false;
    Node* current1 = *head;

    while (current1 != nullptr && encontrou == false)
    {
        Node* current2 = current1->ptrNext;
        while (current2 != nullptr && encontrou == false)
        {
            if (current1->iPayload == current2->iPayload)
            {
                encontrou = true;

                return encontrou;
            }
            current2 = current2->ptrNext;
        }
        current1 = current1->ptrNext;
    }
    return false;
}

// Encontra o tamanho do primeiro ciclo
int findSizeOfCycle(Node** head)
{
    // Lista vazia ou com apenas um nó, não há ciclo
    if (*head == nullptr || (*head)->ptrNext == nullptr)
    {
        return 0;
    }

    Node* tortoise = *head;
    Node* hare = *head;
    int iTamanho = 0;

    while (hare != nullptr)
    {
        tortoise = tortoise->ptrNext;
        hare = hare->ptrNext->ptrNext;

        // Se os valores dos nós se encontrarem, há um ciclo
        if (tortoise->iPayload == hare->iPayload)
        {
            // Tamanho do ciclo é contado a partir daqui

            do {
                iTamanho++;
                tortoise = tortoise->ptrNext;
            } while (tortoise != hare);

            return iTamanho;
        }
    }

    // Se o loop terminar, não há ciclo
    return 0;
}
