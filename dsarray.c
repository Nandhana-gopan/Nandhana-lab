#include <stdio.h>
int main() {
    int arr1[20], arr2[10], merged[30];
    int size1 = 6, size2;
    int i, j, ele, found = 0;

    printf("Enter 6 elements:\n");
    for(i = 0; i < size1; i++) 
    {
        scanf("%d", &arr1[i]);
    }

    printf("Array is: ");
    for(i = 0; i < size1; i++) 
    {
        printf("%d ", arr1[i]);
    }
    printf("\n");

    // Search
    printf("Enter element to search: ");
    scanf("%d", &ele);
    for(i = 0; i < size1; i++)
     {
        if(arr1[i] == ele) 
        {
            printf("Element found at position %d\n", i);
            found = 1;
            break;
        }
      }
    if(!found)
     {
        printf("Element not found\n");
     }

    // Delete
    printf("Enter element to delete: ");
    scanf("%d", &ele);
    found = 0;
    for(i = 0; i < size1; i++)
    {
        if(arr1[i] == ele) 
        {
            found = 1;
            break;
        }
    }

    if(found)
    {
        for(j = i; j < size1 - 1; j++)
        {
            arr1[j] = arr1[j + 1];
        }
        size1--;
        printf("Array after deletion: ");
        for(i = 0; i < size1; i++) {
            printf("%d ", arr1[i]);
        }
        printf("\n");
    }
    else
    {
        printf("Element not found, cannot delete\n");
    }

    // Merge with another array
    printf("Enter number of elements for second array: ");
    scanf("%d", &size2);
    printf("Enter elements:\n");
    for(i = 0; i < size2; i++) 
    {
        scanf("%d", &arr2[i]);
    }

    // Copy arr1 to merged
    for(i = 0; i < size1; i++) 
    {
        merged[i] = arr1[i];
    }
    // Copy arr2 to merged
    for(j = 0; j < size2; j++)
    {
        merged[i + j] = arr2[j];
    }

    printf("Merged array: ");
    for(i = 0; i < size1 + size2; i++)
    {
        printf("%d ", merged[i]);
    }

    return 0;
}
