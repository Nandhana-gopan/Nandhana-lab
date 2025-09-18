#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node *next;
};
struct node *rear=NULL;
struct node *front=NULL;

void enqueue(int value)
{
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data=value;
    if (rear == NULL) 
    { 
        front = rear = newnode;
        newnode->next=newnode;
    } 
    else 
    {
        rear->next =newnode;
        newnode->next = front; // Circular link to front
        rear = newnode;    }

    printf("Enqueued: %d\n", value);
}


void dequeue()
{
    if (front == NULL) 
    {
        printf("Queue underflow\n");
        return;
    }

    int value = front->data;
    if (front == rear)  // Only one node in queue
    {
        free(front);
        front = rear = NULL;
    }
    else
    {
        struct node* temp = front;
        front = front->next;
        rear->next = front; // Maintain circular link
        free(temp);
    }
    printf("Dequeued: %d\n", value);
}

void traverse()
{
    if (front == NULL)
    {
        printf("Queue is empty\n");
        return;
    }

    struct node* temp = front;
    printf("Queue elements: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != front);
    printf("\n");
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    traverse();

    dequeue();
    traverse();
    return 0;
}