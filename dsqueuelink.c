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
    newnode->next=NULL;
    if (rear == NULL) 
    { 
        front = rear = newnode;
    } else {
        rear->next = newnode;
        rear = newnode;
    }

    printf("Enqueued: %d\n", value);
}
void dequeue()
{
    if (front==NULL)
    {
        printf("Queue underflow\n");
        return -1;
    }
    else
    {
       struct node* temp = front;
       int value=temp->data;
       front=temp->next;
       free(temp);
       printf("dequeued %d\n",value);
       return temp;
    }
}
void traverse()
{
    if(front==NULL)
    {
        printf("the list is empty");
    }
     struct node* temp = front;
     while(temp!=NULL)
     {
        printf("%d\n",temp->data);
        temp=temp->next;
     }

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