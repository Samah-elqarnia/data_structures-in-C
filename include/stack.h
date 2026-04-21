#ifndef STACK_H
#define STACK_H

typedef struct Stack {
    int data;
    struct Stack* next;
} Stack;

void initialiser_pile(Stack** P);
void push(Stack** P, int data);
void pop(Stack** P);
void print_pile(Stack* P);

#endif