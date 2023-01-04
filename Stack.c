#include <stdio.h>
#include <stdlib.h>
#define MaxOfStack 10
int toCount = 0;

struct stack{
    int data[MaxOfStack];
    int top;
};

typedef struct stack st;

int isStackEmpty(st *myStack){
    if(myStack->top == -1){
        return 1;
    }else{
        return 0;
    }
}

int isStackFull(st *myStack){
    if(myStack->top == MaxOfStack-1){
        return 1;
    }else{
        return 0;
    }
}

void creat_Empty_Stack(st *myStack){
    myStack->top = -1;
}

void pushToStack(st *myStack,int value){
    if(isStackFull(myStack)){
        printf("Stack is full !\n");
    }else{
        myStack->top++;
        myStack->data[myStack->top] = value;
        toCount++;
    }
    
}

void popFromStack(st *myStack){
    if(isStackEmpty(myStack)){
        printf("Stack is Empty !\n");
    }else{
        printf("Pop from stack is : %d\n",myStack->data[myStack->top]);
        myStack->top--;
        toCount--;
    }
    
}

void PrintDataFromStack(st *myStack){
    if(isStackEmpty(myStack)){
        printf("Stack is Empty !\n");
    }else{
        printf("Stack have %d data\n",toCount);
        for(int temp = myStack->top; temp >= 0; temp--){
            printf("%d\n",myStack->data[temp]);
        }
        
    }
}

int main(){

    st *myStack = (st*)malloc(sizeof(st));
    creat_Empty_Stack(myStack);

    pushToStack(myStack,10);
    pushToStack(myStack,12);
    pushToStack(myStack,13);
    pushToStack(myStack,14);
    pushToStack(myStack,15);

    PrintDataFromStack(myStack);

    popFromStack(myStack);
    popFromStack(myStack);
    popFromStack(myStack);
    popFromStack(myStack);
    popFromStack(myStack);

    return 0;
}
