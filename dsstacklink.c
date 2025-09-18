#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node *next;
};


void traverse(struct node *top)
{
printf("stack is:");
if(top==NULL)
  printf("list is empty");
while(top!=NULL)
{
    printf("%d\n",top->data);
    top=top->next;
}
}
void push(struct node **top,int value)
{
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data=value;
    newnode->next=*top;
    *top=newnode;
}
int pop(struct node **top)
{
 struct node* temp = *top;
 int item =temp->data;
 *top=temp->next;
 free(temp);
 printf("deleted item is %d\n",item);
 return item;
}
int main() 

{
    struct node* top = NULL;
    push(&top,2);
    push(&top,6);
    push(&top,8);
    push(&top,45);
    traverse(top);
    pop(&top);
    traverse(top);
    return 0;
}


