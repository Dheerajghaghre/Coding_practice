#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

struct arrStack{
    int top;
    int capacity;
    long int *arr;
};
struct arrStack *createStack(long int size){
    struct arrStack *S =(struct arrStack *)malloc(sizeof(struct arrStack));
    S->top = -1;
    S->capacity = size;
    S->arr = (long int *)malloc(S->capacity*sizeof(long int));
    return S;
}

void push(struct arrStack *S){
    long int val;
    scanf("%d",&val);
    S->arr[++S->top] = val;
}
void push1(struct arrStack *S, long int val){
    
    S->arr[++S->top] = val;
}
void delStack(struct arrStack *S){
    S->top--;
}
int pop(struct arrStack *S){
    return S->arr[S->top--];
}
void maxEle(struct arrStack *S){
   long int max=0;
    struct arrStack *temp2;
    temp2 = createStack(S->top);
    for(int i=0; i<=S->top;i++){
        int val=pop(S);
        if(max<val)
        max=val;
        push1(temp2,val);
    }
    for(int i=0; i<=S->top;i++){
        int val=pop(temp2);        
        push1(S,val);
    }
    printf("%d",max);
    printf("\n");
}
int main() {

    long int choice, size=0;
    struct arrStack *temp = NULL;
    scanf("%d",&size);
    temp = createStack(size);
    while(size){
        scanf("%d",&choice);
    switch(choice){
        case 1:
                push(temp);
                break;
        case 2:
                delStack(temp);
                break;
        case 3:
                maxEle(temp);
                break;
    } 
    size--;  
    } 
    return 0;
}