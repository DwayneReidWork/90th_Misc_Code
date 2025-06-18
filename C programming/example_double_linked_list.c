#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

void insertAtFront(Node** head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = *head;
    newNode->prev = NULL;
    if (*head != NULL) {
        (*head)->prev = newNode;
    }
    *head = newNode;
}

void deleteNode(Node** head, Node* del) {
    if (*head == NULL || del == NULL) return;
    if (*head == del) *head = del->next;
    if (del->next != NULL) del->next->prev = del->prev;
    if (del->prev != NULL) del->prev->next = del->next;
    free(del);
}

void printList(Node* head) {
    Node* last;
    printf("Traversal in forward direction: ");
    while (head != NULL) {
        printf("%d -> ", head->data);
        last = head;
        head = head->next;
    }
    printf("NULL\n");
    printf("Traversal in reverse direction: ");
    while (last != NULL) {
        printf("%d -> ", last->data);
        last = last->prev;
    }
    printf("NULL\n");
}

Node * createNode(int data)
{
    Node * newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;

    return newNode;
}

void insertSorted(Node ** head, int data)
{
    Node * newNode = createNode(data);
    // if the list is empty
    if (*head == NULL)
    {
        *head = newNode;
        return;
    }
    
    // if we need to insert the node at the beginning
    if (data < (*head)->data)
    {
        newNode->next = *head;
        (*head)->prev = newNode;
        *head = newNode;
        return;
    }

    // search through list to find correct insertion point
    Node * current = *head;
    while ((current->next != NULL) && (current->next->data < data))
    {
        current = current->next;
    }

    // sweet comment: insert newNode after the current node
    newNode->next = current->next;
    newNode->prev = current;
    if (current->next != NULL)
    {
        current->next->prev = newNode;
    }
    current->next = newNode;
}

Node * mergeSortedList(Node * list_A, Node * list_B)
{
    Node * result = NULL;
    if(list_A == NULL)
    {
        return list_B;
    }
    else if (list_B == NULL)
    {
        return list_A;
    }
    
    if (list_A->data <= list_B->data)
    {
        result = list_A; //result = 0x1
        result->next = mergeSortedList(list_A->next, list_B); //result->next = 0x2
        result->next->prev = result; //result->next(0x2)->prev(??) = result(0x1)
        result->prev = NULL; //ensures that the head->prev is NULL
    }
    else
    {
        result = list_B;
        result->next = mergeSortedList(list_A, list_B->next);
        result->next->prev = result;
        result->prev = NULL;
    }

    return result;
}

int main() {
    Node * head1 = NULL;
    Node * head2 = NULL;

    for (int i = 1; i < 11; i++)
    {
        insertSorted(&head1, i*2);
    }
    for (int i = 1; i < 11; i++)
    {
        insertSorted(&head2, i*3);
    }

    printf("Created Double Linked List:\n");
    printList(head1);
    printList(head2);

    Node * result = mergeSortedList(head1, head2);
    printList(result);
    // Node * temp = result;
    // while (temp)
    // {
    //     printf("%d -> ", temp->data);
    //     temp = temp->next;
    // }
    // printf("\n");
    // insertSorted(&head1, 22);
    // printList(head1);
    // deleteNode(&head, head->next);
    // printf("After Deletion:\n");
    // printList(head);
    return 0;
}