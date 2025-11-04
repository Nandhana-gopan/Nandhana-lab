#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = data;
    newnode->prev = NULL;
    newnode->next = NULL;
    return newnode;
}

// Function to traverse and print the list
void traverse(struct Node *head) {
    struct Node* temp = head;
    printf("List is: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
void traverse2(struct Node *head)
 {
    if(head==NULL) return;
    while(head->next!=NULL)
    {
        head=head->next;
    }
    struct Node* temp = head;
    printf("List is: ");
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->prev;
    }
    printf("NULL\n");
}

// Insert at beginning
void insertatbeginning(struct Node** head, int data) {
    struct Node* newnode = createNode(data);
    newnode->next = *head;
    if (*head != NULL) {
        (*head)->prev = newnode;
    }
    *head = newnode;
}

// Insert at end
void insertatend(struct Node** head, int data) {
    struct Node* newnode = createNode(data);
    if (*head == NULL) {
        *head = newnode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newnode;
    newnode->prev = temp;
}

// Insert at specific position
void insertatpos(struct Node** head, int data, int pos) {
    if (pos == 1) {
        insertatbeginning(head, data);
        return;
    }

    struct Node* newnode = createNode(data);
    struct Node* temp = *head;

    for (int i = 1; temp != NULL && i < pos - 1; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position out of bounds\n");
        free(newnode);
        return;
    }

    newnode->next = temp->next;
    newnode->prev = temp;

    if (temp->next != NULL) {
        temp->next->prev = newnode;
    }
    temp->next = newnode;
}

// Delete at beginning
void deleteatbeg(struct Node** head) {
    if (*head == NULL) return;

    struct Node* temp = *head;
    *head = (*head)->next;
    if (*head != NULL) {
        (*head)->prev = NULL;
    }
    free(temp);
}

// Delete at end
void deleteatend(struct Node** head) {
    if (*head == NULL) return;

    struct Node* temp = *head;

    if (temp->next == NULL) {
        free(temp);
        *head = NULL;
        return;
    }

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->prev->next = NULL;
    free(temp);
}

// Delete at specific position
void deleteatpos(struct Node** head, int pos) {
    if (*head == NULL) return;

    if (pos == 1) {
        deleteatbeg(head);
        return;
    }

    struct Node* temp = *head;

    for (int i = 1; temp != NULL && i < pos - 1; i++) {
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL) return;

    struct Node* delNode = temp->next;

    temp->next = delNode->next;
    if (delNode->next != NULL) {
        delNode->next->prev = temp;
    }

    free(delNode);
}

// Search an element
void search(struct Node* head, int key) {
    int pos = 1;
    struct Node* temp = head;
    while (temp != NULL) {
        if (temp->data == key) {
            printf("The element %d found at position %d\n", key, pos);
            return;
        }
        temp = temp->next;
        pos++;
    }
    printf("Element %d not found in the list\n", key);
}

// Free the entire list to avoid memory leaks
void freeList(struct Node** head) {
    struct Node* temp;
    while (*head != NULL) {
        temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}

// Main function to test the operations
int main() {
    struct Node* head1 = NULL;

    insertatend(&head1, 10);
    insertatend(&head1, 20);
    insertatend(&head1, 30);
    insertatend(&head1, 50);
    insertatbeginning(&head1, 5);
    insertatpos(&head1, 15, 3);
    insertatend(&head1, 45);
    insertatbeginning(&head1, 90);
    insertatend(&head1, 89);
    insertatpos(&head1, 13, 4);
    insertatend(&head1, 50);
    insertatpos(&head1, 5, 5);

    traverse(head1);
    traverse2(head1);
    deleteatbeg(&head1);
    deleteatend(&head1);
    deleteatpos(&head1, 4);

    traverse(head1);

    search(head1, 20);
    search(head1, 100);

    freeList(&head1);  // Clean up memory

    return 0;
}
