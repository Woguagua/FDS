//The function required
Stack CreateStack( int MaxElements ){
    Stack stacknew;
    stacknew = (Stack)malloc(sizeof(struct StackRecord));
    stacknew->Array = (int*)malloc(MaxElements*sizeof(int));
    stacknew->Capacity = MaxElements;
    stacknew->Top1 = 0;
    stacknew->Top2 = 0;
    return stacknew;
}