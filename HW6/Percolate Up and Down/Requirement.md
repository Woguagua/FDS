//Copy from PTA\
Write the routines to do a "percolate up" and a "percolate down" in a binary min-heap.


# Format of function
```c
void PercolateUp( int p, PriorityQueue H );
void PercolateDown( int p, PriorityQueue H );
```
where int p is the position of the element, and PriorityQueue is defined as the following
```c
typedef struct HeapStruct *PriorityQueue;
struct HeapStruct {
    ElementType  *Elements;
    int Capacity;
    int Size;
};
```
The function CheckBST is supposed to return the K-th largest key if T is a binary search tree; or if not, return the negative height of T (for example, if the height is 5, you must return −5).
Here the height of a leaf node is defined to be 1.  T is not empty and all its keys are positive integers.  K is positive and is never more than the total number of nodes in the tree.

# Sample program of judge:
```c
#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
#define MinData -1

typedef struct HeapStruct *PriorityQueue;
struct HeapStruct {
    ElementType  *Elements;
    int Capacity;
    int Size;
};

PriorityQueue Initialize( int MaxElements ); /* details omitted */

void PercolateUp( int p, PriorityQueue H );
void PercolateDown( int p, PriorityQueue H );

void Insert( ElementType X, PriorityQueue H ) 
{
    int p = ++H->Size;
    H->Elements[p] = X;
    PercolateUp( p, H );
}

ElementType DeleteMin( PriorityQueue H ) 
{ 
    ElementType MinElement; 
    MinElement = H->Elements[1];
    H->Elements[1] = H->Elements[H->Size--];
    PercolateDown( 1, H );
    return MinElement; 
}

int main()
{
    int n, i, op, X;
    PriorityQueue H;

    scanf("%d", &n);
    H = Initialize(n);
    for ( i=0; i<n; i++ ) {
        scanf("%d", &op);
        switch( op ) {
        case 1:
            scanf("%d", &X);
            Insert(X, H);
            break;
        case 0:
            printf("%d ", DeleteMin(H));
            break;
        }
    }
    printf("\nInside H:");
    for ( i=1; i<=H->Size; i++ )
        printf(" %d", H->Elements[i]);
    return 0;
}

/* Your function will be put here */


```

# Sample Input
>9\
>1 10\
>1 5\
>1 2\
>0\
>1 9\
>1 1\
>1 4\
>0\
>0

# Sample Output
>2 1 4 \
>Inside H: 5 10 9



