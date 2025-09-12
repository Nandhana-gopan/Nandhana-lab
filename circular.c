#include <stdio.h>
#include <stdlib.h>

struct Node 
{
    int data;
    struct Node *next;
};
struct Node* createNode(int data) 
{
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}
void traverse(struct Node * head)
{
    struct Node* temp = head;
    printf("list is: ");
   do {
        printf("%d ->", temp->data);
        temp = temp->next;
    } while(temp != head);
    printf("NULL\n");
}
void insertatbeginning(struct Node** head, int data)
{
    struct Node* newnode = createNode(data);
    if (*head == NULL) {
        *head = newnode;
        newnode->next = newnode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != *head) {
        temp = temp->next;
    }
    newnode->next = *head;
    temp->next = newnode;
    *head = newnode;
}
void insertatpos(struct Node** head, int data,int pos)
{
    if(pos==1)
    {
        
        insertatbeginning(head, data);
        return;
    }

    struct Node* newnode = createNode(data); 
    struct Node* temp = *head;

    for (int i = 1; i < pos - 1 && temp->next != *head; i++)
     {
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
void insertatend(struct Node** head, int data) 
{
    struct Node* newnode = createNode(data);
    if (*head == NULL) {
        newnode->next=newnode;
        *head = newnode;
        return;
    }
    struct Node* temp = *head;
    while(temp->next != *head) {
        temp = temp->next;
    }
    newnode->next = *head;
    temp->next = newnode;
}
void deleteatbeg(struct Node** head) 
{
    if (*head == NULL) return;
    struct Node* last = *head;
while (last->next != *head) {
    last = last->next;
}
last->next = (*head)->next;
*head = (*head)->next;
free(last);

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

    
    struct Node* temp = *head;

    for (int i = 1; i < pos && temp->next != *head; i++) {
    prev = temp;
    temp = temp->next;
}
    if (temp == NULL || temp->next == NULL) return;

    struct Node* todelete = temp->next;
    temp->next = todelete->next;
    free(todelete);
}
void search(struct Node* head, int key) 
{
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
struct Node* merge(struct Node* head1,struct Node* head2)
{
    if(head1==NULL)
    return head2;
    if(head2==NULL)
    return head1;
    struct Node* temp = head1;
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = head2;
    return head1;
}

int main() 

{

    struct Node* head1 = NULL;
    struct Node* head2 = NULL;
    insertatend(&head1, 10);
    insertatend(&head1, 20);
    insertatend(&head1, 30);
    insertatend(&head1, 50);
    insertatbeginning(&head1,5);
    insertatpos(&head1,15,3);
    insertatend(&head1, 45);
    insertatbeginning(&head1,90);
    insertatend(&head1, 89);
    insertatpos(&head1,13,4);
    insertatend(&head1, 50);
    insertatpos(&head1,5,5);
    traverse(head1);
    deleteatbeg(&head1);
    deleteatend(&head1);
    deleteatpos(&head1,4);
    traverse(head1);
    search(head1, 20);
    search(head1, 100);// test not found



    insertatend(&head2, 190);
    insertatend(&head2, 200);
    insertatend(&head2, 300);
    insertatend(&head2, 500);
    insertatbeginning(&head2,590);
    insertatpos(&head2,150,3);
    insertatend(&head2, 456);
    insertatbeginning(&head2,900);
    insertatend(&head2, 890);
    insertatpos(&head2,13,2);
    insertatend(&head2, 50);
    insertatpos(&head2,598,5);
    traverse(head2);
    deleteatbeg(&head2);
    deleteatend(&head2);
    deleteatpos(&head2,4);
    traverse(head2);
    search(head2, 20);
    search(head2, 150);  
    

    struct Node* mergehead=merge(head1,head2);
    printf("\nafter merging:\n");
    traverse(mergehead);
    return 0;
}

