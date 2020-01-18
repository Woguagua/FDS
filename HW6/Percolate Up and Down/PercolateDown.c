void PercolateDown( int p, PriorityQueue H ){
    ElementType temp = H->Elements[p];
    int i,child;
    for(i = 1;i*2 <= H->Size;i = child){
        child = i * 2;
        if(child != H->Size && H->Elements[child+1] < H->Elements[child]){
            child++;
        }
        if(H->Elements[child] < temp){
            H->Elements[i] = H->Elements[child];
        }
        else break;
    }
    H->Elements[i] = temp;
}