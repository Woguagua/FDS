//The program required
#include<stdio.h>
#include<stdlib.h>


struct treenode{
	int Data;
	int Level;
	struct treenode * Left;
	struct treenode * Right;
};
typedef struct treenode * Tree;
Tree BuildTree(int*Postorder,int*Inorder,int posthead,int posttail,int inhead,int intail,int level);
void OutputTree(int N,Tree BT);

int main(){
	int N;
	int i;
	scanf("%d",&N);
	int Postorder[N+1];
	int Inorder[N+1];
	for(i = 1;i <= N;i++){
		if(i == N)	scanf("%d",&Inorder[i]);
		else		scanf("%d ",&Inorder[i]);
	}
	for(i = 1;i <= N;i++){
		if(i == N)	scanf("%d",&Postorder[i]);
		else		scanf("%d ",&Postorder[i]);
	}
	Tree T;
	T = BuildTree(Postorder,Inorder,1,N,1,N,1);
	OutputTree(N,T);
	return 0;
}

Tree BuildTree(int*Postorder,int*Inorder,int posthead,int posttail,int inhead,int intail,int level){
	Tree T;
	int j;
	T = (Tree)malloc(sizeof(struct treenode));
	T->Data = Postorder[posttail];
	T->Level = level;
	T->Left = NULL;
	T->Right = NULL;
	if(inhead == intail)	return T;
	for(j = intail;j >= inhead;j--){
		if(Postorder[posttail] == Inorder[j]){
			if(j != inhead)     T->Left = BuildTree(Postorder,Inorder,posthead,posttail-(intail-j)-1,inhead,j-1,level+1);
			if(j != intail)		T->Right = BuildTree(Postorder,Inorder,posttail-(intail-j),posttail-1,j+1,intail,level+1);
			return T;
		}
	}
}

void OutputTree(int N,Tree BT){
	Tree Q[N+3];
	int head = 1;
	int tail = 1;
	Tree T;
	int direction = 0;
	int levelnow = 2;
	int temp = 0;
	int tempstore[N+3];
    int count = 1;
	if(!BT)	return;
    if(N == 1){  printf("%d",BT->Data);return;}
	Q[tail++] = BT;
	while(head != tail){
		T = Q[head++];
		if(T->Level > levelnow){
			direction = !direction;
			levelnow++;
			while(temp > 0){
				if(count == N)  printf("%d",tempstore[temp--]);
                else            printf("%d ",tempstore[temp--]);
                count++;
			}
		}
		if(direction == 0){
		    if(count == N)  printf("%d",T->Data);
            else            printf("%d ",T->Data);
            count++;
        }
		else{
			tempstore[++temp] = T->Data;
		}
		if(T->Left)		Q[tail++] = T->Left;
		if(T->Right)	Q[tail++] = T->Right;
	}
	while(temp > 0){
		if(count == N)  printf("%d",tempstore[temp--]);
        else            printf("%d ",tempstore[temp--]);
        count++;
	}


/*	while(head != tail){
		T = Q[head++];
		printf("%d ",T->Data);
		if(T->Left)		Q[tail++] = T->Left;
		if(T->Right)	Q[tail++] = T->Right;
	}
	*/

}
