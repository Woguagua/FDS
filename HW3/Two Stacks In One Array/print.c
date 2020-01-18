//Not required,used for test
void PrintStack( Stack S, int Stacknum ){
	int i =0;
	if(Stacknum == 1){
		for(i = S->Top1 - 1;i>=0;i--){
			printf("%d ",S->Array[i]);
		}
	}
	if(Stacknum == 2){
		for(i = S->Top2 + 1;i<=(S->Capacity-1);i++){
			printf("%d ",S->Array[i]);
		}
	}
}
