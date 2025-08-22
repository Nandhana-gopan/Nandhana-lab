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

// ✅ FIXED: changed parameter from Node* to Node**
void insertatpos(struct Node** head, int data,int pos)
{
    if(pos==1)
    {
        // ✅ FIXED: pass head as Node** (already is)
        insertatbeginning(head, data);
        return;
    }

    struct Node* newnode = createNode(data); 
    struct Node* temp = *head;

    for(int i = 1; temp != NULL && i < pos - 1; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position out of bounds\n");
        free(newnode);
        return;
    }

    newnode->next = temp->next;
    temp->next = newnode;
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

void deleteatend(struct Node** head)
{
    if (*head == NULL) return;
    struct Node* temp = *head;

    if (temp->next == NULL) {
        free(temp);
        *head = NULL;
        return;
    }

    while(temp->next->next != NULL) {
        temp = temp->next;
    }

    free(temp->next);
    temp->next = NULL;
}

void deleteatpos(struct Node** head, int pos)
{
    if (*head == NULL) return;

    if(pos == 1)
    {
        deleteatbeg(head);
        return;
    }

    // ✅ FIXED: Removed second definition of temp
    struct Node* temp = *head;

    for(int i = 1; temp != NULL && i < pos - 1; i++) {
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL) return;

    struct Node* todelete = temp->next;
    temp->next = todelete->next;
    free(todelete);
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

int main() 
{
    struct Node* head = NULL;
    insertatend(&head, 10);
    insertatend(&head, 20);
    insertatend(&head, 30);
    insertatend(&head, 50);
    insertatbeginning(&head,5);
    insertatpos(&head,15,3);
    insertatend(&head, 45);
    insertatbeginning(&head,90);
    insertatend(&head, 89);
    insertatpos(&head,13,4);
    insertatend(&head, 50);
    insertatpos(&head,5,5);
    traverse(head);
    deleteatbeg(&head);
    deleteatend(&head);
    deleteatpos(&head,4);
    traverse(head);
    search(head, 20);
    search(head, 100);  // test not found
    return 0;
}

