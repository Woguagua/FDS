//The function required
BinTree Empty;
int RightBST ( BinTree T );
int FindKMax(BinTree T,int K);
int FindHeight(BinTree T);
BinTree FindMaxRoot(BinTree T);
BinTree DeleteHead(BinTree T);
void DeleteMax(BinTree MaxRoot);
BinTree Insert(int NewData,BinTree T);
int RightBST ( BinTree T ){
    if(T->Left == NULL && T->Right == NULL)     return 1;
    if(T->Left){
        if(T->Key <= T->Left->Key || !RightBST(T->Left))   return 0;
        if(T->Right == NULL)        return 1;
    }
    if(T->Right){
        if(T->Key >= T->Right->Key || !RightBST(T->Right))   return 0;
        if(T->Left == NULL)         return 1;
    }
    
    BinTree LeftMax;
    LeftMax = T->Left;
    while(LeftMax->Right)   LeftMax = LeftMax->Right;
    if(LeftMax->Key >= T->Key)      return 0;
    
    BinTree RightMin;
    RightMin = T->Right;
    while(RightMin->Left)   RightMin = RightMin->Left;
    if(RightMin->Key <= T->Key)      return 0;
    
    return 1;
}
int CheckBST ( BinTree T, int K ){
    int right;
    right = RightBST(T);
    if(right == 1)      return FindKMax(T,K);
    if(right == 0)      return -1*FindHeight(T);
    return 1;
}
int FindKMax(BinTree T,int K){
    BinTree MaxRoot;
    BinTree Max;
    while(K > 1){
        MaxRoot = FindMaxRoot(T);
        if(MaxRoot == Empty)    T = DeleteHead(T);
        else                    DeleteMax(MaxRoot);
        K--;
    }
    MaxRoot = FindMaxRoot(T);
    if(MaxRoot == Empty)     return T->Key;
    else{
        Max = MaxRoot->Right;
        return Max->Key;
    }
}
int FindHeight(BinTree T){
    int Hleft = 0,Hright = 0;
    if(T->Left)     Hleft = FindHeight(T->Left);
    if(T->Right)    Hright = FindHeight(T->Right);
    if(Hleft >= Hright)     return Hleft + 1;
    else                    return Hright + 1;
}

BinTree FindMaxRoot(BinTree T){
    if(T->Right == NULL)   return Empty;
    while(T->Right->Right){
        T = T->Right;
    }
    return T;
}

BinTree DeleteHead(BinTree T){
    if(T->Right == NULL)        T = T->Left;
    else if(T->Left == NULL)    T = T->Right;
    else{
        BinTree RightMin;
        RightMin = T->Right;
        while(RightMin->Left)   RightMin = RightMin->Left;
        RightMin->Left = T->Left;
        T = T->Right;
    }
    return T;
}

void DeleteMax(BinTree MaxRoot){
    if(MaxRoot->Right->Left == NULL){
        MaxRoot->Right = NULL;
    }
    else{
        MaxRoot->Right = MaxRoot->Right->Left;
    }
}

BinTree Insert(int NewData,BinTree T){
    if(T == NULL){
        T = (BinTree)malloc(sizeof(struct TNode));
        T->Key = NewData;
        T->Left = NULL;
        T->Right = NULL;
    }
    else{
        if(NewData < T->Key){
            T->Left = Insert(NewData,T->Left);
        }
        else if(NewData > T->Key){
            T->Right = Insert(NewData,T->Right);
        }
    }
    return T;
}

