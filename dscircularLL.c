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


void traverse(struct Node *head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = head;
    printf("List is: ");
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(head)\n");
}

void insertatbeginning(struct Node** head, int data) {
    struct Node* newnode = createNode(data);
    if (*head == NULL) 
    {
        newnode->next = newnode; 
        *head = newnode;
        return;
    }

    struct Node* temp = *head;
    while (temp->next != *head) { // ✅ Find last node
        temp = temp->next;
    }

    temp->next = newnode;
    newnode->next = *head;
    *head = newnode;
}

// ✅ No change needed: already circular-aware
void insertatend(struct Node** head, int data) {
    struct Node* newnode = createNode(data);
    if (*head == NULL) {
        newnode->next = newnode; // ✅ Circular link to self
        *head = newnode;
        return;
    }

    struct Node* temp = *head;
    while (temp->next != *head) {
        temp = temp->next;
    }

    temp->next = newnode;
    newnode->next = *head; // ✅ Circular link back to head
}

// ✅ UPDATED: supports circular list without NULL check
void insertatpos(struct Node** head, int data, int pos) {
    if (pos == 1) {
        insertatbeginning(head, data);
        return;
    }

    struct Node* newnode = createNode(data);
    struct Node* temp = *head;

    // ✅ Traverse till one node before position
    for (int i = 1; i < pos - 1 && temp->next != *head; i++) {
        temp = temp->next;
    }

    newnode->next = temp->next;
    temp->next = newnode;
}

// ✅ FIXED: delete first node in circular list
void deleteatbeg(struct Node** head) {
    if (*head == NULL) return;

    struct Node* temp = *head;

    // ✅ Only one node
    if (temp->next == *head) {
        free(temp);
        *head = NULL;
        return;
    }

    struct Node* last = *head;
    while (last->next != *head) {
        last = last->next;
    }

    last->next = (*head)->next;
    *head = (*head)->next;
    free(temp); // ✅ Free first node
}

// ✅ FIXED: updated for circular list (no NULL checks)
void deleteatend(struct Node** head) {
    if (*head == NULL) return;

    struct Node* temp = *head;

    // ✅ Only one node
    if (temp->next == *head) {
        free(temp);
        *head = NULL;
        return;
    }

    struct Node* prev = NULL;
    while (temp->next != *head) {
        prev = temp;
        temp = temp->next;
    }

    prev->next = *head;
    free(temp); // ✅ Free last node
}

// ✅ FIXED: rewritten for circular list
void deleteatpos(struct Node** head, int pos) {
    if (*head == NULL) return;

    if (pos == 1) {
        deleteatbeg(head);
        return;
    }

    struct Node* temp = *head;
    struct Node* prev = NULL;
    int count = 1;

    // ✅ Loop with position counter and head check
    do {
        if (count == pos) break;
        prev = temp;
        temp = temp->next;
        count++;
    } while (temp != *head);

    if (count != pos || temp == *head) {
        printf("Position %d out of bounds\n", pos);
        return;
    }

    prev->next = temp->next;
    free(temp); // ✅ Free node at given position
}

// ✅ FIXED: updated to circular logic using do-while
void search(struct Node* head, int key) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node* temp = head;
    int pos = 1;

    do {
        if (temp->data == key) {
            printf("The element %d found at position %d\n", key, pos);
            return;
        }
        temp = temp->next;
        pos++;
    } while (temp != head);

    printf("Element %d not found in the list\n", key);
}

// ✅ FIXED: merge two circular lists
struct Node* merge(struct Node* head1, struct Node* head2) {
    if (head1 == NULL) return head2;
    if (head2 == NULL) return head1;

    struct Node* tail1 = head1;
    while (tail1->next != head1) {
        tail1 = tail1->next;
    }

    struct Node* tail2 = head2;
    while (tail2->next != head2) {
        tail2 = tail2->next;
    }

    // ✅ Link end of each list to other
    tail1->next = head2;
    tail2->next = head1;

    return head1; // Return merged head
}

// ✅ NO changes here; test logic remains same
int main() {
    struct Node* head1 = NULL;
    struct Node* head2 = NULL;

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

    deleteatbeg(&head1);
    deleteatend(&head1);
    deleteatpos(&head1, 4);
    traverse(head1);

    search(head1, 20);
    search(head1, 100); // not found

    insertatend(&head2, 190);
    insertatend(&head2, 200);
    insertatend(&head2, 300);
    insertatend(&head2, 500);
    insertatbeginning(&head2, 590);
    insertatpos(&head2, 150, 3);
    insertatend(&head2, 456);
    insertatbeginning(&head2, 900);
    insertatend(&head2, 890);
    insertatpos(&head2, 13, 2);
    insertatend(&head2, 50);
    insertatpos(&head2, 598, 5);
    traverse(head2);

    deleteatbeg(&head2);
    deleteatend(&head2);
    deleteatpos(&head2, 4);
    traverse(head2);

    search(head2, 20);
    search(head2, 150);

    struct Node* mergehead = merge(head1, head2);
    printf("\nAfter merging:\n");
    traverse(mergehead);

    return 0;
}
