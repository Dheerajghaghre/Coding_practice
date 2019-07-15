#include<iostream>
#include<malloc.h>
using namespace std;

struct arrayStack{
    int top;
    int capasity;
    int *arr;
};

struct arrayStack *createStack(){
     struct arrayStack *S = (struct arrayStack*)malloc(sizeof(struct arrayStack));
     if(!S)
     return NULL;

     cout<<"enter size of array:- "<<endl;
     cin>>S->capasity;
     S->top=-1;
     S->arr = (int *)malloc(S->capasity*sizeof(int));
     return S;
}

void isStackEmpty(struct arrayStack *S){
    if(S->top == -1)
    cout<<"stack is empty"<<endl;
    else
    {
        cout<<"stack has some value"<<endl;
    }
    
    
}
void isStackFull(struct arrayStack *S){
    if(S->top == S->capasity - 1)
    cout<<"stack is full"<<endl;
    else
    {
        cout<<"stack has some empty place"<<endl;
    }
    
    
}
void top(struct arrayStack *S){
    if(S->top == -1)
    cout<<"stack is empty"<<endl;
    else
    {
        int val=0;
        val = S->arr[S->top];
        cout<<"Top value of Stack is:- "<<val<<endl;
    }
}
void push(struct arrayStack *S){
    if(S->top == S->capasity - 1)
    cout<<"stack is full"<<endl;
    else
    {   
        int val;
        cout<<"Enter the value:- "<<endl;
        cin>>val;
        S->arr[++S->top] = val;
        cout<<"Value is inserted in staack  "<<endl;
    }
}
void pop(struct arrayStack *S){
    if(S->top == - 1)
    cout<<"stack is Empty"<<endl;
    else
    {   
        int val;
        val= S->arr[S->top--];

        cout<<"Poped value of stack is:- "<<val<<endl;
    }
}

void deleteStack(struct arrayStack *S){
    if(S->arr)
    free(S->arr);
    free(S);
    cout<<"stack is deleted:"<<endl;
}

int main(){
    int choice,value=1;
    struct arrayStack *temp = NULL;
    while(value){
    cout<<"stack operation"<<endl;
    cout<<"1. Create Stack"<<endl;
    cout<<"2. Push the value in stack"<<endl;
    cout<<"3. Pop the value from the stack"<<endl;
    cout<<"4. Get the top of stack"<<endl;
    cout<<"5. Is stack is empty"<<endl;
    cout<<"6. Is stack is full"<<endl;
    cout<<"7. Delete the stack"<<endl;
    cout<<"0. exit"<<endl;
    cout<<"Please enter the choice"<<endl;
    cin>>choice;

    switch(choice){
        case 1:
            if(temp)
            cout<<"stack is already crested:"<<endl;
            else{
              temp =  createStack();
              if(temp)
              cout<<"stack is created"<<endl;
            }
              break;
        case 2:
                if(temp==NULL)
                cout<<"stack is not created"<<endl;
                else{
                    push(temp);
                }
                break;


        case 3:
                if(temp==NULL)
                cout<<"stack is not created"<<endl;
                else{
                    pop(temp);
                }
                break;
        case 4:
                if(temp==NULL)
                cout<<"stack is not created"<<endl;
                else{
                    top(temp);
                }
                break;

        case 5:
                if(temp==NULL)
                cout<<"stack is not created"<<endl;
                else{
                    isStackEmpty(temp);
                }
                break;
        case 6:
                if(temp==NULL)
                cout<<"stack is not created"<<endl;
                else{
                    isStackFull(temp);
                }
                break;
        case 7:
                if(temp==NULL)
                cout<<"stack is not created"<<endl;
                else{
                    deleteStack(temp);
                }
                break;
        case 0:
                value = 0;
                break;
        default:
                cout<<"Please enter the right value:- "<<endl;
                break;

    }
    }

}
