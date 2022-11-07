#include<ctype.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max 100
char st[max];
int top=-1;
void push(char st[], char);
char pop(char st[]);
void InfixToPostfix(char infix[], char postfix[]);
int getPriority(char);
int main()
{
    char infix[100], postfix[100];
    printf("\nEnter any infix expression: ");
    gets(infix);
    strcpy(postfix, "");
    InfixToPostfix(infix, postfix);
    printf("\nThe corresponding postfix expression is: ");
    puts(postfix);
    return 0;
}

void InfixToPostfix(char infix[], char postfix[])
{
    int i=0, j=0;
    strcpy(postfix, "");
    while(infix[i]!='\0')
    {
        if(infix[i]=='(')
        {
            push(st, infix[i]);
            i++;
        }
        else if(infix[i]==')')
        {
            while((top!=-1)&& (st[top]!='('))
            {
                postfix[j]=pop(st);
                j++;
            }
            if(top==-1)
            {
                printf("\nIncorrect expression");
                exit(1);
            }
            pop(st);
            i++;
        }
        else if(isdigit(infix[i]) || isalpha(infix[i]))
        {
            postfix[j]=infix[i];
            j++; 
            i++;
        }
        else if(infix[i]=='+' || infix[i]=='-' ||infix[i]=='*' ||infix[i]=='/' ||infix[i]=='%')
        {
            while((top!=-1) && (st[top]!='(') && (getPriority(st[top]) > getPriority(infix[i])))
            {
                postfix[j]=pop(st);
                j++;
            }
            push(st, infix[i]);
            i++;
        }
        else
        {
            printf("\nIncorrect Element in expression");
            exit(1);
        }
    }
    while((top!=-1) && (st[top]!='('))
    {
        postfix[j]=pop(st);
        j++;
    }
    postfix[j]='\0';
}

int getPriority(char op)
{
    if(op=='/' || op=='*'|| op=='%')
        return 1;
    else if(op=='+' || op=='-')
        return 0;
}

void push(char st[], char val)
{
    if(top==max-1)
        printf("\nStack overflow");
    else
    {
        top++;
        st[top]=val;
    }
}

char pop(char st[])
{
    char val=' ';
    if(top==-1)
        printf("\nStack Underflow");
    else
    {
        val=st[top];
        top--;
    }
    return val;
}

