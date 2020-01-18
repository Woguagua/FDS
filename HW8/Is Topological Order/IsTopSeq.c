//The function required
bool IsTopSeq( LGraph Graph, Vertex Seq[] ){
    int i;
    PtrToAdjVNode p;
    Vertex degree[2000];
    for(i = 0;i < Graph->Nv;i++){
        degree[i] = 0;
    }
    for(i = 0;i < Graph->Nv;i++){
        p = Graph->G[i].FirstEdge;
        while(p){
            degree[p->AdjV]++;
            p = p->Next;
        }
    }
    
    for(i = 0;i < Graph->Nv;i++){
        if(degree[Seq[i]-1] != 0)    return false;
        else{
            p = Graph->G[Seq[i]-1].FirstEdge;
            while(p){
                degree[p->AdjV]--;
                p = p->Next;
            }
        }
    }
    return true;
}