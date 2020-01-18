//The program required
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main(){
    int In[50];
    int Stack[50];
    int top = 0;
    int num = 1;
    int left = 1;
    int max;
    int i = 0;
    int j = 0;
    int count = 0;
    scanf("%d",&max);
    char operation[4];
    while(j++ < max*2){
        scanf("%s",operation);
        if(operation[1] == 'u'){
            scanf("%d",&num);
            In[i++] = num;
        }
        else    In[i++] = 0;
    }
    In[i] = 0;
    Stack[0] = In[0];
    j = 0;
    if(max >1){
    while(j < max*2){
        if(In[j] != 0){
            Stack[top++] = In[j++];
        }
        else if(In[j] == 0){
            if(In[j+1] == 0){
                if(Stack[top-1] > 0){
                    printf("%d ",Stack[--top]);
                    count++;
                }
                else if(Stack[top-1] < 0){
                    while(Stack[top-1] < 0){
                        printf("%d ",-1*Stack[--top]);
                        count++;
                        if(count >=  max-1) break;
                    }
                    Stack[top-1]*=-1;
                }
                if(count >=  max-1) break;
                j++;
            }
            else if(Stack[top-1] > 0){
                Stack[top-1]*= -1;
                j++;
            }
            else if(Stack[top-1] < 0){
                printf("%d ",-1*Stack[--top]);
                Stack[top-1]*= -1;
                count++;
                j++;
            }
            if(j >= max*2) break;
        }
    }
    }
    else printf("%d",In[0]);
    while(top > 1){
        if(Stack[top-1]>0)  printf("%d ",Stack[--top]);
        else                printf("%d ",-1*Stack[--top]);
    }
    if(top > 0){
        if(Stack[0] > 0)    printf("%d",Stack[0]);
        else                printf("%d",-1*Stack[0]);
    }
    
}
