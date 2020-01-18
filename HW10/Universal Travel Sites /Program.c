//The program required
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define Infinity 100000;
#define MAX 1000
#define min(a,b)  a>b?b:a;
char CharToIndex[MAX][4];
int weight[MAX][MAX];
int used[MAX];
int Exist(char*place,int num);
int maxflow(int source,int destination);
int dfs(int source,int destination,int f);
int main(){
    int i;
    int num = 0;
    char source[4],destination[4];
    char place1[4],place2[4];
    int index1,index2;
    int w;
    int edge = 0;
    scanf("%s %s %d",source,destination,&edge);
    strcpy(CharToIndex[num++],destination);//index0==>destination
    strcpy(CharToIndex[num++],source);//index1==>source
    for(i = 1;i <= edge;i++){
        scanf("%s %s %d",place1,place2,&w);
        index1 = Exist(place1,num);
        if(index1 == -1){
            strcpy(CharToIndex[num],place1);
            index1 = num++;
        }
        index2 = Exist(place2,num);
        if(index2 == -1){
            strcpy(CharToIndex[num],place2);
            index2 = num++;
        }
        weight[index1][index2] = w;
    }
    strcpy(CharToIndex[num],destination);
    for(i = 1;i < num;i++)  weight[i][num] = weight[i][0];
    printf("%d",maxflow(1,num));
}

int Exist(char*place,int num){
    int i = 0;
    for(i = 0;i<num;i++){
        if(strcmp(place,CharToIndex[i]) == 0)        return i;
    }
    return -1;
}

int maxflow(int source,int destination){
    int flow = 0;
    int f;
    int i;
    while(1){
        for(i = source;i <=destination;i++)     used[i] = 0;
        f = dfs(source,destination,100000);
        if(f == 0)  return flow;
        flow +=f;
    }
}

int dfs(int source,int destination,int f){
    int i;
    int d;
    if(source == destination)   return f;
    for(i = 1;i <= destination;i++){
        if(weight[source][i] > 0 && !used[i]){
            used[i] = 1;
            f = min(f,weight[source][i]);
            d = dfs(i,destination,f);
            if(d > 0){
                weight[source][i] -=d;
                weight[i][source] +=d;
                return d;
            }
        }
    }
    return 0;
}