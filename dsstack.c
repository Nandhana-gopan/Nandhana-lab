#include<stdio.h>
#include<stdlib.h>
#define MAX 5

int stack[MAX];
int top=-1;

void display()
{
    for(int i=top;i>=0;i--)
    printf("%d",stack[i]);
}
void push()
{
    int value;
    // printf("enter the value to be inserted");
    // scanf("%d",&value);
    printf("at pusg");
    if(top==MAX-1)
    {
        printf("stack overflow cannot insert");
    }
    else
    {
        // printf("reached else11");
        for(int i=0;i<MAX;i++)
        {
        printf("enter the value to be inserted");
        scanf("%d",&value);
        stack[++top]=value;
        printf("inserted the number %d",value);
        display();
        }
    }
}

void pop()
{
    int data;
    if(top==-1)
    {
        printf("underflow,cannot be deleted %d",top
        );
    }
    else
    {
        data=stack[top];
        top--;
        printf("the item %d has been deleted",data);
    }
}

int main()
{
int choice;
printf("enter the choice");
scanf("%d",&choice);
int i = 1;
while(i == 1)
{
    printf("Enter your choice:\n1. Push\n2. Pop\n3. Display\n");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1: push();
                break;
        case 2: pop();
                break;
        case 3: display();
                break;
        default: printf("done\n");
    }
    printf("Do you want to continue? Enter 1 for Yes, any other number for No: ");
    scanf("%d", &i);
}
}