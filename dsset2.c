#include <stdio.h>

#define MAX 32  // max elements 0 to 31
typedef unsigned int BitSet;

void add(BitSet *set, int element) {
    if (element >= 0 && element < MAX)
        *set |= (1U << element);
}

// Print set as elements (optional)
void printSet(BitSet set) {
    printf("{ ");
    for (int i = 0; i < MAX; i++) {
        if (set & (1U << i))
            printf("%d ", i);
    }
    printf("}\n");
}

// Print bit string from MSB (bit 31) to LSB (bit 0)
void printBitString(BitSet set) {
    for (int i = MAX - 1; i >= 0; i--) {
        int bit = (set >> i) & 1;
        printf("%d", bit);
    }
    printf("\n");
}

void inputSet(BitSet *set, BitSet universalSet, const char *setName) {
    int n, element;

    printf("Enter number of elements in %s: ", setName);
    scanf("%d", &n);

    if (n < 0 || n > MAX) {
        printf("Invalid number of elements for %s.\n", setName);
        return;
    }

    printf("Enter elements (must be in universal set):\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &element);

        if (element < 0 || element >= MAX || ((universalSet & (1U << element)) == 0)) {
            printf("Element %d is not in the universal set or out of range. Try again.\n", element);
            i--;
        } else {
            add(set, element);
        }
    }
}

int main() {
    BitSet universalSet = 0, subset1 = 0, subset2 = 0;
    int n, element;

    printf("Enter number of elements in universal set (max %d): ", MAX);
    scanf("%d", &n);

    if (n < 0 || n > MAX) {
        printf("Invalid number of elements.\n");
        return 1;
    }

    printf("Enter elements of universal set (0 to %d):\n", MAX - 1);
    for (int i = 0; i < n; i++) {
        scanf("%d", &element);
        if (element < 0 || element >= MAX) {
            printf("Element %d out of range. Try again.\n", element);
            i--;
        } else {
            add(&universalSet, element);
        }
    }

    printf("Universal set bit string: ");
    printBitString(universalSet);

    inputSet(&subset1, universalSet, "Subset 1");
    printf("Subset 1 bit string:       ");
    printBitString(subset1);

    inputSet(&subset2, universalSet, "Subset 2");
    printf("Subset 2 bit string:       ");
    printBitString(subset2);

    return 0;
}
