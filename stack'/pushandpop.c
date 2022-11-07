#include<stdio.h>
#include<stdlib.h>
struct stack{
    int top;
    int size;
    int *arr;
};
int isfull(struct stack* ptr){
    if(ptr->top==ptr->size-1){
        return 1;
    }
    else{
        return 0;
    }
}
int isempty(struct stack* ptr){
    if(ptr->top==-1){
        return 1;
    }
    else{
        return 0;
    }
}
int push(struct stack* ptr,int val){
    if(isfull(ptr)){
        printf("Stack overflow");
    }
    else{
        ptr->top++;
        ptr->arr[ptr->top]=val;
    }
}
int  pop(struct stack* ptr){
    if(isempty(ptr)){
        printf("Stack Underflow cannot be used for pop operation");
    }
    else{ 
        int val=ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}
int main(){
    struct stack *sp=(struct stack*)malloc(sizeof(struct stack));
    sp->size=10;
    sp->top=-1;
    sp->arr=(int *)malloc(sp->size * sizeof(int));
    printf("Stack has been created successfully\n");
    printf("%d\n",isfull(sp));
    printf("%d\n",isempty(sp));
    push(sp,13);
    push(sp,45);
    push(sp,56);
    push(sp,7);
    push(sp,1);
    push(sp,99);
    push(sp,69);
    printf("After pushing %d\n",isfull(sp));
    printf("After pushing %d\n",isempty(sp));
    printf("Popped %d element from stack\n",pop(sp));
return 0;
}