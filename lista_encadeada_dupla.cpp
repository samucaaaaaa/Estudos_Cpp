#include <iostream>

using std::cout;
using std::endl;
using std::string;

// Lista duplamente encadeada

// Criando nova estrutura para um nó, para fazer lista duplamente encadeada
typedef struct Node
{
    int iPayload;
    Node* ptrNext;
    Node* ptrPrev;
} Node;

Node* createNode(int);
void insertFront(Node**, int);
void insertEnd(Node**, int);
void insertAfter(Node**, int);
void deleteNode(Node**, Node*);
void displayList(Node*);

// Das atividades.
Node* searchNodebyValue(Node**, int);
void insertBefore(Node*, int);
void deleteNodebyValue(Node**, int);

int main()
{
    // Lista duplamente encadeada
    Node* head = nullptr;
    //displayList(head);

    cout << "====================================================================" << endl;
    cout << "------------------------- Atividade de ED -------------------------" << "\n\n";

    cout << "-------------------------- Lista inicial --------------------------" << endl;

    // Adicionando elementos para lista inicial
    insertEnd(&head, 0);
    insertEnd(&head, 1);
    insertEnd(&head, 3);
    insertEnd(&head, 7);
    insertEnd(&head, 10);
    insertEnd(&head, 13);
    displayList(head);
    cout << "====================================================================" << endl;

    cout << "--------------- Inserindo valor 25 antes do valor 7 ---------------" << endl;

    Node* node = searchNodebyValue(&head, 7);

    insertBefore(node, 25);
    displayList(head);
    cout << "====================================================================" << endl;

    cout << "------------------------ Deletando valor 25 ------------------------" << endl;

    deleteNodebyValue(&head, 25);
    displayList(head);

    return 0;
}

Node* createNode(int iPayload)
{
    Node* temp = (Node*) malloc(sizeof(Node));     
    temp->iPayload = iPayload;
    temp->ptrNext = nullptr;
    temp->ptrPrev = nullptr;

    return temp;
}

void displayList(Node* node)
{
    if (node == nullptr)
    {
        cout << "Lista vazia: Nao foi possivel realizar displayList" << endl;
        return;
    }

    if (node->ptrPrev != nullptr)
    {
        cout << "Meio da Lista: Nao foi possivel realizar displayList" << endl;
        return;
    }

    Node* temp = node;

    cout << "Payload: ";

    //Percorremos a lista até o fim (ptrNext do último é NULL) 
    while (temp != nullptr)
    {
        cout << temp->iPayload << " ";
        temp = temp->ptrNext;
    }

    cout << endl;
}

void insertFront(Node** head, int iPayload)
{
    Node* newNode = createNode(iPayload);
	// newNode->ptrPrev = nullptr;
	
	if (*head != nullptr)
	{
		(*head)->ptrPrev = newNode;
		newNode->ptrNext = (*head);
		(*head) = newNode;
		return;
	}
	
	(*head) = newNode;
	
}

void insertEnd(Node** head, int iPayload)
{
    Node* newNode = createNode(iPayload);
    //newNode->ptrNext = nullptr;

    if (*head == nullptr)
    {
        //newNode->ptrPrev = nullptr;   
        (*head) = newNode;
        return;            
    }

    Node* temp = (*head);

    //Percorremos a lista até o fim (ptrNext do último é NULL) 
    while (temp->ptrNext != nullptr) temp = temp->ptrNext;

    newNode->ptrPrev = temp; //newNode aponta para o fim da lista
    temp->ptrNext = newNode; //antigo último elemento aponta para o novo nó

}

void insertAfter(Node* ptrLocation, int iPayLoad)
{
	if (ptrLocation == nullptr)
	{
		cout << "Location é NULL" << endl;
	}
	
	Node* newNode = createNode(iPayLoad);
	
	// Corrigir nó a ser inserido
	newNode->ptrNext = ptrLocation->ptrNext;
	newNode->ptrPrev = ptrLocation;
	
	// Corrigir o ponto de inserção
	ptrLocation->ptrNext = newNode;
	
	if (newNode->ptrNext != nullptr) newNode->ptrNext->ptrPrev = newNode;
}

void deleteNode(Node** head, Node* ptrDelete)
{
	if (*head == nullptr || ptrDelete == nullptr)
	{
		cout << " Não foi possível remover." << endl;
		return;
	}
	
	// Caso o ptrDelete seja o primeiro elemento da lista
	if (*head == ptrDelete) (*head) = ptrDelete->ptrNext;
	
	// Se o ptrDelete não é o último nó
	if (ptrDelete->ptrNext != nullptr) ptrDelete->ptrNext->ptrPrev = ptrDelete->ptrPrev;

	// Se o ptrDelete não é o primeiro nó
	if (ptrDelete->ptrPrev != nullptr) ptrDelete->ptrPrev->ptrNext = ptrDelete->ptrNext;
	
	free(ptrDelete);
}

// Exercício 1: Elaborar o método void insertBefore(Node**, int);

void insertBefore(Node* ptrLocation, int iPayLoad)
{
    if (ptrLocation == nullptr)
	{
		cout << "Location é NULL" << endl;
        
        return;
	}
	
	Node* newNode = createNode(iPayLoad);

    // Corrigindo nó a ser inserido
    newNode->ptrPrev = ptrLocation->ptrPrev;
    newNode->ptrNext = ptrLocation;

    // Corrigindo o ponto de inserção
    ptrLocation->ptrPrev = newNode;

    if (newNode->ptrPrev != nullptr) newNode->ptrPrev->ptrNext = newNode;
}

// Exercício 2: Elaborar a função void deleteNodebyValue(Node**, int);

void deleteNodebyValue(Node** head, int iValue)
{
    Node* node = searchNodebyValue(head, iValue);
    deleteNode(head, node);
}

// Exercício 3: Elaborar a função Node* searchNodebyValue(Node**, int);

Node* searchNodebyValue(Node** head, int iValue)
{
    if (*head == nullptr)
    {
        cout << "Lista vazia: Nao foi possivel realizar searchNodebyValue" << endl;
        return nullptr;
    }

    Node* current = (*head);

    while(current != nullptr){
        if(current -> iPayload == iValue) return current;
        current = current -> ptrNext;
    }

    return nullptr;
}









