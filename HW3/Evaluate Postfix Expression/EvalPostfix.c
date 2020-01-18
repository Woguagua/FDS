//The function required
int Isomorphic( Tree T1, Tree T2 ){
    if(T1 == NULL || T2 == NULL){
        if(T1 == NULL  &&  T2 == NULL)  return 1;
        else    return 0;
    }
    if(T1->Element != T2->Element)  return 0;
    if(T1->Left == NULL){
        if(T1->Right == NULL){
            if(T2->Left == NULL  &&  T2->Right == NULL)     return 1;
            else    return 0;
        }
        else if(T2->Left == NULL){
            if(T2->Right == NULL)   return 0;
            else{
                if( Isomorphic(T1->Right,T2->Right) )   return 1;
                else    return 0;
            }
        }
        else if(T2->Right == NULL){
            if( Isomorphic(T1->Right,T2->Left) )   return 1;
            else    return 0;
        }
        else    return 0;
    }
    else if(T1->Right == NULL){
        if(T2->Left == NULL){
            if(T2->Right == NULL)   return 0;
            else{
                if( Isomorphic(T1->Left,T2->Right) )   return 1;
                else    return 0;
            }
        }
        else if(T2->Right == NULL){
            if( Isomorphic(T1->Left,T2->Left) )   return 1;
            else    return 0;
        }
        else    return 0;
    }
    if(T2->Left == NULL || T2->Right == NULL)   return 0;
    if(T1->Left->Element == T2->Left->Element){
        if( !Isomorphic(T1->Left,T2->Left)  ||  !Isomorphic(T1->Right,T2->Right) )  return 0;
    }
    else if(T1->Left->Element == T2->Right->Element){
        if( !Isomorphic(T1->Left,T2->Right)  ||  !Isomorphic(T1->Right,T2->Left) )  return 0;
    }
    return 1;
}