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
int peek(struct stack* ptr,int i){
    int peekresult=ptr->top-i+1;
    if(ptr->top-i+1<0){
        printf("Not a valid option");
        return -1;
    }
    else{
        return ptr->arr[peekresult];
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
    printf("\nPrint all the elements in the stack\n");
    for(int j=1;j<sp->top+1;j++){
        printf("Value   at %d position is %d\n",j,peek(sp,j));
    }
return 0;
}