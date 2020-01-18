//The function required 
int Findmin(MGraph Graph,int d[],int visit[]);
void ShortestDist( MGraph Graph, int dist[], int count[], Vertex S ){
    int i;
    int visit[Graph->Nv +1];
    for(i = 0;i < Graph->Nv;i++){
        dist[i] = 10000;
        visit[i] = 0;
        count[i] = 0;
    }
    dist[S] = 0;
    count[S] = 1;
    int V,W;
    for(;;){
        V = Findmin(Graph, dist, visit);
        if(V == -1)     break;
        for(W = 0;W < Graph->Nv; W++){
            if(Graph->G[V][W] > 0){
                if(dist[W] == dist[V] + Graph->G[V][W]){
                    count[W] += count[V];
                }
                else if(dist[W] > dist[V] + Graph->G[V][W]){
                    dist[W]=dist[V]+Graph->G[V][W];
                    count[W]=count[V];
                }
            }
        }
        visit[V] = 1;
    }
    for(i = 0;i<Graph->Nv;i++){
        if(dist[i] == 10000){
            count[i] = 0;
            dist[i] = -1;
        }
    }
}

int Findmin(MGraph Graph,int d[],int visit[]){
    int count = 0;
    int min;
    int i;
    for(min = 0;min< Graph->Nv;min++){
        if(visit[min] == 0) break;
    }
    for(i = 0;i<Graph->Nv;i++){
        if(visit[i]==0 && d[min]>d[i])  min = i;
        if(visit[i] == 1)   count++;
    }
    if(count < Graph->Nv)   return min;
    else return -1;
}