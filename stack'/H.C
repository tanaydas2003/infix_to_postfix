#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Stack {
  unsigned int size;
  int top;
  char *arr;
};

struct Stack *createStack(unsigned int size) {
  struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
  stack->size = size;
  stack->top = -1;
  stack->arr = (char *)malloc(size * sizeof(char));
  return stack;
};

int isFull(struct Stack *stack) {
  if (stack->size == stack->top + 1) {
    return 1;
  }
  return 0;
}

int isEmpty(struct Stack *stack) {
  if (stack->top == -1) {
    return 1;
  }
  return 0;
}

void push(struct Stack *stack, int elem) {
  if (isFull(stack)) {
    // printf("Overflow\n");
  } else {
    stack->top++;
    stack->arr[stack->top] = elem;
    // printf("Element %d Pushed to Stack\n", elem);
  }
}

char pop(struct Stack *stack) {
  if (isEmpty(stack)) {
    return '\0';
    // printf("Underflow\n");
  } else {
    // printf("Element %d Removed From Stack\n", stack->arr[stack->top]);
    char temp = stack->arr[stack->top];
    stack->top--;
    return temp;
  }
}

void peek(struct Stack *stack) {
  if (isEmpty(stack)) {
    // printf("Empty Stack\n");
  } else {
    int temp = stack->top;
    printf("Elements in Stack Are: ");
    while (temp > -1) {
      printf("%c", stack->arr[temp--]);
    }
    printf("\n");
  }
}

int precedence(char ch) {
  if (ch == '*' || ch == '/') {
    return 2;
  } else if (ch == '+' || ch == '-') {
    return 1;
  } else {
    return 0;
  }
}

int isOperator(char ch) {
  if (ch == '+' || ch == '-' || ch == '/' || ch == '*') {
    return 1;
  } else if (ch == '(' || ch == ')') {
    return 2;
  } else {
    return 0;
  }
}

char *infixToPostfix(char *infix) {
  struct Stack *sp = (struct Stack *)malloc(sizeof(struct Stack));
  sp->size = 100;
  sp->top = -1;
  sp->arr = (char *)malloc(sp->size * sizeof(char));
  char *postfix = (char *)malloc((strlen(infix)) * sizeof(char));
  int i = (int)strlen(infix), p = 0;
  for (int j = 0; j < i; j++) {
    // peek(sp);
    char temp = *(infix + j);
    // printf("%d %c\n", j, temp);
    if (isOperator(temp) == 2) {
      if (temp == '(') {
        push(sp, temp);
      } else {
        while (sp->top != -1 && sp->arr[sp->top] != '(') {
          char t = pop(sp);
          if (isOperator(t) == 1) {
            postfix[p++] = t;
            // printf("%c to postfix\n", t);
          }
        }
        pop(sp);
      }
    } else if (isOperator(temp) == 0) {
      postfix[p++] = temp;
      // printf("%c to postfix\n", temp);
    } else {
      // printf("op %c to %c\n", temp, sp->arr[sp->top]);
      if (precedence(temp) > precedence(sp->arr[sp->top])) {
        push(sp, temp);
      } else {
        while (precedence(temp) <= precedence(sp->arr[sp->top])) {
          int t = pop(sp);
          postfix[p++] = t;
          // printf("%c to postfix\n", t);
        }
        push(sp, temp);
      }
    }
  }
  while (sp->top != -1) {
    int t = pop(sp);
    postfix[p++] = t;
    // printf("%c to postfix\n", t);
  }
  // peek(sp);
  // printf("%s", postfix);
  return postfix;
}

int main() {
  char *infix = (char *)"(a+b)*(c-d)";
  printf("Postfix Expression of %s is %s", infix, infixToPostfix(infix));
  return 0;
}
