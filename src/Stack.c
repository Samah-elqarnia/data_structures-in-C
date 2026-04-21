#include "../include/stack.h"
#include <stdio.h>
#include <stdlib.h>

void initialiser_pile(Stack** P){
   *P=NULL;
}

void push(Stack** P, int data){
    Stack *NE = (Stack*)malloc(sizeof(Stack));
    if (NE == NULL) {
        printf("Memoire insuffisante\n");
        exit(-1);
    }
    NE->data = data;
    NE->next = *P;
    *P = NE;
}

void pop(Stack** P){
    Stack *elem_supp;
    if (*P == NULL){
        printf("Pile vide\n");
        return;
    }
    elem_supp = *P;
    *P = (*P)->next;
    free(elem_supp);
}

void print_pile(Stack* P){
    Stack *courant;
    courant = P;
    while(courant != NULL){
        printf("%d -> ", courant->data);
        courant = courant->next;
    }
    printf("NULL\n");
}