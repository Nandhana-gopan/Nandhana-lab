#include<stdio.h>
#include<stdlib.h>
#define MAX 7

int queue[MAX];
front=-1;
rear=-1;
void enqueue(int value)
{
    if(rear == MAX - 1)
    {
        printf("Queue overflow, cannot insert %d\n", value);
        return -1;
    }
    else
    {
        if(front == -1) // If queue is empty
            front = 0;
        rear++;
        queue[rear] = value;
        printf("Inserted %d into the queue\n", value);
        return 0;    
    }

    }

void dequeue()
{
    if(front==-1||front>rear)
    {
        printf("Queue underflow, cannot dequeue\n");
    }
    else{
        front++;
        printf("Dequeued element is %d\n", queue[front - 1]);
        if(front > rear) // Reset queue if it becomes empty
        {
            front = -1;
            rear = -1;
        }   
    }
}
void display()
{
    printf("Queue elements are: ");
    for(int i = front; i <= rear; i++)
    {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main()
{
    int choice,value,i = 1;
    while(i==1)
    {
        printf("Enter your choice (1: Enqueue, 2: Dequeue, 3: Display, 4: Exit): ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
        }
    }

}

