#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void insertAtEnd(Node** head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void deleteNode(Node** head, int key) {
    Node* temp = *head;
    Node* prev = NULL;
    if (temp != NULL && temp->data == key) {
        *head = temp->next;
        free(temp);
        return;
    }
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) return;
    prev->next = temp->next;
    free(temp);
}

void printList(Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// void reverseList(Node ** head)
// {
//     // Solution provided
//     Node * prev = NULL;
//     Node * current = *head;
//     Node * next = NULL;
//     while (current != NULL)
//     {
//         next = current->next;
//         current->next = prev;
//         prev = current;
//         current = next;
//     }
//     *head = prev;
// }

// void reverseList(Node * current)
// {
//     // by Nguyen
//     if (current == NULL)
//     {
//         return;
//     }
//     reverseList(current->next);

//     printf("%d -> ",current->data);
// }

Node * reverseList (Node * head)
{
    // solution by Apodaca
    Node * prev = NULL;
    Node * next;
    while (head)
    {
        next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }
    return prev;
}

int getLength (Node * head)
{
    int length = 0;
    while (head)
    {
        length++;
        head = head->next;
    }
    return length;
}

int getMiddle(Node * head)
{
    int length = getLength(head);
    int midIndexInt = length / 2;

    while (midIndexInt--)
    {
        head = head->next;
    }
    return head->data;
}

int main() {
    Node* head = NULL;
    insertAtEnd(&head, 1);
    insertAtEnd(&head, 2);
    insertAtEnd(&head, 3);
    printf("Linked List: ");
    printList(head);
    deleteNode(&head, 2);
    printf("After Deletion: ");
    printList(head);
    for (int i=4; i < 10; i++)
    {
        insertAtEnd(&head,i);
    }
    printf("New linked list: ");
    printList(head);
    head = reverseList(head);
    printf("\n");
    printf("Reversed list: ");
    printList(head);

    printf("Data of center: %d\n", getMiddle(head));
    return 0;
}