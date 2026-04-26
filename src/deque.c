#include "../include/deque.h"
#include <stdio.h>
#include <stdlib.h>

Node* create_node(int data){
    Node * NE;
    // allouer la memoire pour le nouveau Node
    NE= (Node*)malloc(sizeof(Node));
    // verifier si la memoire est allouee
    if(NE==NULL){
        printf("memoire insuffisante\n"); 
        exit(-1);
    } 
    // initialiser le nouveau Node
    else{
        NE->data=data;
        NE->next= NULL;
        NE->prev= NULL;
        return NE;
    }
}

void insertFirst(Deque* D, int data) {
    Node* NE = create_node(data);
    if (D->debut == NULL) {
        D->debut = D->fin = NE;
    } else {
        NE->next = D->debut;
        D->debut->prev = NE;
        D->debut = NE;
    }
    D->taille++;
}

void insertLast(Deque* D, int data) {
    Node* NE = create_node(data);
    if (D->fin == NULL) {
        D->debut = D->fin = NE;
    } else {
        D->fin->next = NE;
        NE->prev = D->fin;
        D->fin = NE;
    }
    D->taille++;
}

void deleteFirst(Deque* D) {
    if (D->debut == NULL) {
        printf("Deque vide\n");
        return;
    }
    Node* temp = D->debut;
    D->debut = D->debut->next;
    if (D->debut == NULL) {
        D->fin = NULL;
    } else {
        D->debut->prev = NULL;
    }
    free(temp);
    D->taille--;
}

void deleteLast(Deque* D) {
    if (D->fin == NULL) {
        printf("Deque vide\n");
        return;
    }
    Node* temp = D->fin;
    D->fin = D->fin->prev;
    if (D->fin == NULL) {
        D->debut = NULL;
    } else {
        D->fin->next = NULL;
    }
    free(temp);
    D->taille--;
}

void getFirst(Deque* D) {
    if (D->debut != NULL) {
        printf("Premier element: %d\n", D->debut->data);
    } else {
        printf("Deque vide\n");
    }
}

void getLast(Deque* D) {
    if (D->fin != NULL) {
        printf("Dernier element: %d\n", D->fin->data);
    } else {
        printf("Deque vide\n");
    }
}

void isEmpty(Deque* D) {
    if (D->taille == 0) {
        printf("La file est vide\n");
    } else {
        printf("La file n'est pas vide\n");
    }
}

void size(Deque* D) {
    printf("Taille de la file: %d\n", D->taille);
}

void print_deque(Deque* D) {
    Node* temp = D->debut;
    printf("Deque: [ ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("]\n");
}
