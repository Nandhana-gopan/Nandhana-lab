#include <stdio.h>
#define MAX 32  // Universe size
typedef unsigned int BitSet;

void add(BitSet *set, int element) 
{
    if (element >= 0 && element < MAX)
        *set |= (1U << element);
}
void removeElement(BitSet *set, int element)
{
    if (element >= 0 && element < MAX)
        *set &= ~(1U << element);
}
int contains(BitSet set, int element)
 {
    if (element >= 0 && element < MAX)
        return (set & (1U << element)) != 0;
    return 0;
}
void printSet(BitSet set) 
{
    printf("{ ");
    for (int i = 0; i < MAX; i++) {
        if (contains(set, i))
            printf("%d ", i);
    }
    printf("}\n");
}
int main() 
{
    BitSet mySet = 0;  // Start with empty set (all bits 0)

    add(&mySet, 5);
    add(&mySet, 10);
    add(&mySet, 31);

    printf("Set after adding 5, 10, 31: ");
    printSet(mySet);

    removeElement(&mySet, 10);

    printf("Set after removing 10: ");
    printSet(mySet);

    if (contains(mySet, 5))
        printf("Set contains 5\n");
    else
        printf("Set does not contain 5\n");

    if (contains(mySet, 10))
        printf("Set contains 10\n");
    else
        printf("Set does not contain 10\n");

    return 0;
}

