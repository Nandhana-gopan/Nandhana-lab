#include <stdio.h>
#include <stdlib.h>

struct Node 
{
    int data;
    struct Node *next;
    struct Node *prev;

};
struct Node* createNode(int data) 
{
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = data;
    newnode->prev = NULL;
    newnode->next = NULL;
    return newnode;
}
void traverse(struct Node * head)
{
    struct Node* temp = head;
    printf("list is: ");
    while(temp != NULL) {
        printf("%d ->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
void insertatbeginning(struct Node** head, int data)
{
    struct Node* newnode = createNode(data);
    newnode->next = *head;
    if (*head != NULL) 
    {
    (*head)->prev = newnode;
    }
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

    for(int i = 1; temp != NULL && i < pos - 1; i++)
     {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position out of bounds\n");
        free(newnode);
        return;
    }
newnode->next = temp->next;
newnode->prev = temp;

if (temp->next != NULL)
{
    temp->next->prev = newnode;
}
temp->next = newnode;
}


void insertatend(struct Node** head, int data) 
{
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
    newnode->prev=temp;

}
void deleteatbeg(struct Node** head) 
{
    if (*head == NULL) return;
    struct Node* temp = *head;
    *head = (*head)->next;
    (*head)->prev=NULL;
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

    while(temp->next!= NULL) 
    {
        temp = temp->next;
    }
    temp->prev->next=NULL;
    free(temp);
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

    for(int i = 1; temp != NULL && i < pos - 1; i++) 
    {
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL) return;
    struct Node* delNode = temp->next;
if (delNode == NULL) return;

temp->next = delNode->next;
if (delNode->next != NULL) {
    delNode->next->prev = temp;
}
free(delNode);

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
int main() 

{

    struct Node* head1 = NULL;
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
    search(head1, 100);

}
