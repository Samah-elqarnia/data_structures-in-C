#include "../include/queue.h"
#include <stdio.h>
#include <stdlib.h>

void initialiser_queue(Queue* Q){
    Q->debut = NULL;
    Q->fin = NULL;
    Q->taille = 0;
}

void enqueue(Queue* Q, int data){
    Element *NE = (Element*)malloc(sizeof(Element));
    if (NE == NULL){
        printf("memoire insuffisante\n");
        exit(-1);
    }
    NE->data = data;
    NE->next = NULL;

    if (Q->fin == NULL){ 
        Q->debut = NE;
        Q->fin = NE;
    } else {
        Q->fin->next = NE;
        Q->fin = NE;
    }
    Q->taille++;
}

void dequeue(Queue* Q){
    if (Q->debut == NULL){
        printf("queue vide\n");
        return;
    }
    
    Element *elem_supp = Q->debut;
    Q->debut = Q->debut->next;
    
    if (Q->debut == NULL) {
        Q->fin = NULL;
    }
    
    free(elem_supp);
    Q->taille--;
}

void print_queue(Queue* Q){
    Element *courant = Q->debut;
    while(courant != NULL){
        printf("%d -> ", courant->data);
        courant = courant->next;
    }
    printf("NULL\n");
}