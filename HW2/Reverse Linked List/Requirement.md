//Copy from PTA\
Write a nonrecursive procedure to reverse a singly linked list in O(N) time using constant extra space.
# Format of function
```c
List Reverse( List L );
```

## where Lise is defined as the following:
```c
typedef struct Node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;
struct Node {
    ElementType Element;
    Position Next;
};
```

The function Reverse is supposed to return the reverse linked list of L, with a dummy header.


# Sample program of judge:
```c
#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;
struct Node {
    ElementType Element;
    Position Next;
};

List Read(); /* details omitted */
void Print( List L ); /* details omitted */
List Reverse( List L );

int main()
{
    List L1, L2;
    L1 = Read();
    L2 = Reverse(L1);
    Print(L1);
    Print(L2);
    return 0;
}

/* Your function will be put here */


```

# Sample Input
>5\
>1 3 4 5 2


# Sample Output
>2 5 4 3 1\
>2 5 4 3 1


