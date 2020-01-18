//The function required
void PercolateUp( int p, PriorityQueue H ){
    int i;
    ElementType temp = H->Elements[p];
    for(i = p;H->Elements[i/2] > temp;i /= 2){
        H->Elements[i] = H->Elements[i/2];
    }
    H->Elements[i] = temp;
}