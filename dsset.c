#include <stdio.h>
#include <string.h>

#define MAX 32
#define STRLEN 20

char universalSet[MAX][STRLEN];
int universalSize;

void readUniversalSet();
void readSubset(char bitstring[], const char* name);
int findIndexInUniversalSet(char* element);
void printUniversalSet();
void printSet(char bitstring[]);
void printBitstring(char bitstring[]);
void unionSet(char a[], char b[], char result[]);
void intersectionSet(char a[], char b[], char result[]);
void differenceSet(char a[], char b[], char result[]);

int main() 
{
    char setA[MAX] = {0};
    char setB[MAX] = {0};
    char unionResult[MAX] = {0};
    char intersectionResult[MAX] = {0};
    char differenceResult[MAX] = {0};

    printf("Enter the size of the universal set (max %d): ", MAX);
    scanf("%d", &universalSize);

    if (universalSize <= 0 || universalSize > MAX) {
        printf("Invalid universal set size.\n");
        return 1;
    }

    readUniversalSet();
    readSubset(setA, "A");
    readSubset(setB, "B");

    // Print Universal Set directly from universalSet array
    printf("\nUniversal Set: ");
    printUniversalSet();

    printf("Bitstring: ");
    for (int i = 0; i < universalSize; i++) printf("1");
    printf("\n");

    // Print Set A
    printf("\nSet A: ");
    printSet(setA);
    printf("Bitstring: ");
    printBitstring(setA);

    // Print Set B
    printf("\nSet B: ");
    printSet(setB);
    printf("Bitstring: ");
    printBitstring(setB);

    // Operations
    unionSet(setA, setB, unionResult);
    intersectionSet(setA, setB, intersectionResult);
    differenceSet(setA, setB, differenceResult);

    printf("\nA ∪ B: ");
    printSet(unionResult);
    printf("Bitstring: ");
    printBitstring(unionResult);

    printf("\nA ∩ B: ");
    printSet(intersectionResult);
    printf("Bitstring: ");
    printBitstring(intersectionResult);

    printf("\nA - B: ");
    printSet(differenceResult);
    printf("Bitstring: ");
    printBitstring(differenceResult);

    return 0;
}

void readUniversalSet() 
{
    printf("Enter %d elements of the universal set:\n", universalSize);
    for (int i = 0; i < universalSize; i++) 
    {
        printf("Element %d: ", i + 1);
        scanf("%s", universalSet[i]);
    }
}

void readSubset(char bitstring[], const char* name)
{
    int count;
    char temp[STRLEN];

    printf("\nEnter number of elements in Set %s: ", name);
    scanf("%d", &count);

    if (count < 0 || count > universalSize) 
    {
        printf("Invalid number of elements.\n");
        return;
    }

    printf("Enter %d elements for Set %s:\n", count, name);
    for (int i = 0; i < count; i++) {
        printf("Element %d: ", i + 1);
        scanf("%s", temp);
        int index = findIndexInUniversalSet(temp);
        if (index != -1) {
            bitstring[index] = 1;
        } else {
            printf("Warning: '%s' not found in universal set. Ignored.\n", temp);
        }
    }
}

int findIndexInUniversalSet(char* element)
{
    for (int i = 0; i < universalSize; i++)
    {
        if (strcmp(universalSet[i], element) == 0) {
            return i;
        }
    }
    return -1;
}

void printUniversalSet()
{
    printf("{ ");
    for (int i = 0; i < universalSize; i++) {
        printf("%s ", universalSet[i]);
    }
    printf("}\n");
}

void printSet(char bitstring[]) 
{
    printf("{ ");
    for (int i = 0; i < universalSize; i++) {
        if (bitstring[i]) {
            printf("%s ", universalSet[i]);
        }
    }
    printf("}\n");
}

void printBitstring(char bitstring[]) 
{
    for (int i = 0; i < universalSize; i++) {
        printf("%d", bitstring[i]);
    }
    printf("\n");
}

void unionSet(char a[], char b[], char result[]) 
{
    for (int i = 0; i < universalSize; i++) {
        result[i] = a[i] | b[i];
    }
}

void intersectionSet(char a[], char b[], char result[]) 
{
    for (int i = 0; i < universalSize; i++) {
        result[i] = a[i] & b[i];
    }
}

void differenceSet(char a[], char b[], char result[]) 
{
    for (int i = 0; i < universalSize; i++)
    {
        result[i] = a[i] & (!b[i]);
    }
}
