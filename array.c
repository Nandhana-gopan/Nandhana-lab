#include<stdio.h>
int main()
{
    int arr[6],ele;
    printf("enter array elements\n");
    for(int i=0;i<6;i++)
    {
        scanf("%d",&arr[i]);
    }
    for(int i=0;i<6;i++)
    {
        printf("%d",arr[i]);
    }
    printf("enter the element to be searched");
    scanf("%d",&ele);
    for(int i=0;i<6;i++)
    {
        if(arr[i]==ele)
        {
            printf("element found at %d",i);
            break;
        }
        else
        {
            printf("not found");
        }
    }
    
}