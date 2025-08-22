#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node* createNode(int data) {
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}

void traverse(struct Node* head) {
    struct Node* temp = head;
    printf("list is: ");
    while(temp != NULL) {
        printf("%d ->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void insertatbeginning(struct Node** head, int data) {
    struct Node* newnode = createNode(data);
    newnode->next = *head;
    *head = newnode;
}

void insertatend(struct Node** head, int data) {
    struct Node* newnode = createNode(data);
    if (*head == NULL) {
        *head = newnode;
        return;
    }
    struct Node* temp = *head;
    while(temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newnode;
}

void deleteatbeg(struct Node** head) {
    if (*head == NULL) return;
    struct Node* temp = *head;
    *head = (*head)->next;
    free(temp);
}

void search(struct Node* head, int key) {
    int pos = 1;
    struct Node* temp = head;
    while(temp != NULL) {
        if(temp->data == key) {
            printf("The element %d found at position %d\n", key, pos);
            return;
        }
        temp = temp->next;
        pos++;
    }
    printf("Element %d not found in the list\n", key);
}

int main() {
    struct Node* head = NULL;
    insertatend(&head, 10);
    insertatend(&head, 20);
    insertatend(&head, 30);
    insertatend(&head, 50);
    traverse(head);
    deleteatbeg(&head);
    traverse(head);
    search(head, 20);
    search(head, 100);  // test not found
    return 0;
}
