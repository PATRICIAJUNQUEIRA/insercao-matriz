#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 100

// Estrutura da pilha
typedef struct {
    int array[ARRAY_SIZE];
    int top;
} Stack;

// Função para inicializar a pilha
void initStack(Stack *stack) {
    stack->top = -1;
}

// Função para inserir um elemento na pilha
void push(Stack *stack, int value) {
    if (stack->top < ARRAY_SIZE - 1) {
        stack->top++;
        stack->array[stack->top] = value;
    }
}

// Estrutura da fila
typedef struct {
    int array[ARRAY_SIZE];
    int front;
    int rear;
} Queue;

// Função para inicializar a fila
void initQueue(Queue *queue) {
    queue->front = -1;
    queue->rear = -1;
}

// Função para inserir um elemento na fila
void enqueue(Queue *queue, int value) {
    if (queue->rear < ARRAY_SIZE - 1) {
        if (queue->front == -1)
            queue->front = 0;
        queue->rear++;
        queue->array[queue->rear] = value;
    }
}

// Estrutura da lista
typedef struct Node {
    int value;
    struct Node *next;
} ListNode;

// Função para inserir um elemento na lista
void insert(ListNode **head, int value) {
    ListNode *newNode = (ListNode *)malloc(sizeof(ListNode));
    newNode->value = value;
    newNode->next = *head;
    *head = newNode;
}

// Estrutura da árvore
typedef struct TreeNode {
    int value;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

// Função para criar um novo nó da árvore
TreeNode* createNode(int value) {
    TreeNode *newNode = (TreeNode *)malloc(sizeof(TreeNode));
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Função para inserir um elemento na árvore
TreeNode* insertNode(TreeNode *root, int value) {
    if (root == NULL)
        return createNode(value);

    if (value <= root->value)
        root->left = insertNode(root->left, value);
    else
        root->right = insertNode(root->right, value);

    return root;
}

// Função para exibir o conteúdo de um array
void displayArray(int array[], int size) {
    printf("Array: ");
    for (int i = 0; i < size; i++)
        printf("%d ", array[i]);
    printf("\n");
}

// Função para exibir o conteúdo de uma pilha
void displayStack(Stack stack) {
    printf("Stack: ");
    for (int i = stack.top; i >= 0; i--)
        printf("%d ", stack.array[i]);
    printf("\n");
}

// Função para exibir o conteúdo de uma fila
void displayQueue(Queue queue) {
    printf("Queue: ");
    for (int i = queue.front; i <= queue.rear; i++)
        printf("%d ", queue.array[i]);
    printf("\n");
}

// Função para exibir o conteúdo de uma lista
void displayList(ListNode *head) {
    printf("List: ");
    ListNode *current = head;
    while (current != NULL) {
        printf("%d ", current->value);
        current = current->next;
    }
    printf("\n");
}

// Função para exibir o conteúdo de uma árvore (em ordem)
void displayTree(TreeNode *root) {
    if (root != NULL) {
        displayTree(root->left);
        printf("%d ", root->value);
        displayTree(root->right);
    }
}

// Função para gerar dados aleatórios para o array
void generateRandomData(int array[], int size) {
    srand(time(NULL));
    for (int i = 0; i < size; i++)
        array[i] = rand() % 1000;
}

// Função para ordenar o array em ordem ascendente
void sortArray(int array[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

int main() {
    int array[ARRAY_SIZE];
    generateRandomData(array, ARRAY_SIZE);

    // Inicializar as estruturas de dados
    Stack stack;
    initStack(&stack);

    Queue queue;
    initQueue(&queue);

    ListNode *list = NULL;

    TreeNode *tree = NULL;

    // Inserir elementos nas estruturas de dados
    for (int i = 0; i < ARRAY_SIZE; i++) {
        push(&stack, array[i]);
        enqueue(&queue, array[i]);
        insert(&list, array[i]);
        tree = insertNode(tree, array[i]);
    }

    // Exibir o conteúdo das estruturas de dados
    displayArray(array, ARRAY_SIZE);
    displayStack(stack);
    displayQueue(queue);
    displayList(list);
    displayTree(tree);

    return 0;
}
