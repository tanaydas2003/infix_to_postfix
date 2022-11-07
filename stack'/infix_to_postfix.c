#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct stack{
    int top;
    int size;
    char *arr;
};
int stackTop(struct stack* sp){
    return sp->arr[sp->top];
}
int isfull(struct stack* ptr){
    if(ptr->top==ptr->size-1){
        return 1;
    }
    else{
        return 0;
    }
}
int isEmpty(struct stack* ptr){
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
    if(isEmpty(ptr)){
        printf("Stack Underflow cannot be used for pop operation");
    }
    else{ 
        int val=ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}
int precedence(char ch){
    if(ch=='*' || ch=='/'){
        return 3;
    }
    else if(ch=='+' || ch=='-'){
        return 2;
    }
    else{
        return 0;
    }
}
int isOperator(char ch){
    if(ch=='+' || ch=='-' || ch=='/' || ch=='*'){
        return 1;
    }
    else if (ch == '(' || ch == ')') {
    return 2;
    }
    else{
        return 0;
    }
}
char * infixToPostfix(char* infix){
    struct stack *sp=(struct stack*)malloc(sizeof(struct stack));
        sp->size =100;
        sp->top=-1;
        sp->arr=(char *)malloc(sp->size * sizeof(char));
        char * postfix=(char *)malloc((strlen(infix)+1) * sizeof(char));
        int i=0,j=0;
        while (infix[i]!='\0')
        {   
            if(infix[i]=='('){
                push(sp,infix[i]);
                i++;
            }
            else if(infix[i]==')'){
                while((stackTop(sp)!=-1) && (stackTop(sp)!='(')){
                    postfix[j]=pop(sp);
                    j++;
                }
                if(stackTop(sp)==-1){
                    printf("Invalid Expression");
                    exit(1);
                }
                pop(sp);
                i++;
            }
            if(!isOperator(infix[i])){
                postfix[j]=infix[i];
                j++;
                i++;
            }
            else{
                if(precedence(infix[i])>precedence(stackTop(sp))){
                    push(sp,infix[i]);
                    i++;
                }
                else{
                    postfix[j]=pop(sp);
                    j++;
                }
            }
        }
        while(!isEmpty(sp)){
            postfix[j]=pop(sp);
            j++;
        }
        postfix[j]='\0';
        return postfix;
        
}
int main(){
    char * infix="(a-b)*(c-d)";
    //printf("Enter aninfix expression to get converted to postfix expression: ");
    //scanf("%s",&infix);
    printf("Postfix is %s",infixToPostfix(infix));
return 0;
}