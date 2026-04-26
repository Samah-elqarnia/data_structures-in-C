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

void initialiser_deque(Deque* D){
    D->debut = NULL;
    D->fin = NULL;
    D->taille = 0;
}

void insertFirst(Deque* D, int data){
    Node *NE;
    NE= create_node(data);
    if(D->debut==NULL){
        D->debut=NE;
        D->fin=NE;
        D->taille++;
    }
    else{
        NE->next=D->debut;
        D->debut->prev=NE;
        NE->prev=NULL;
        D->debut=NE;
        D->taille++;
    }    
}

void insertLast(Deque* D, int data){
    Node *NE;
 NE= create_node(data);
 if(D->debut==NULL){
    D->debut=NE;
    D->fin=NE;
    D->taille++;
 }
 else{
    D->fin->next=NE;
    NE->prev=D->fin;
    D->fin=NE;
    D->taille++;
 }
}
void deleteFirst(Deque* D){
    if(D->debut==NULL){
        print('deque vide');
        return;
    }
    Node *elem_supp=D->debut;
    D->debut=D->debut->next;
    D->debut->prev=NULL;
    free(elem_supp);
    D->taille--;
}
void deleteLast(Deque* D){
   if(D->debut==NULL){
        print('deque vide');
        return;
    }
    Node *elem_supp=D->fin;
    D->fin=D->fin->prev;
    D->fin->next=NULL;
    free(elem_supp);
    D->taille--;
}
void getFirst(Deque* D){
    if(D->debut==NULL){
        print('deque vide');
        return;
    }
    printf("%d\n", D->debut->data);
}
void getLast(Deque* D){
    if(D->debut==NULL){
        print('deque vide');
        return;
    }
    printf("%d\n", D->fin->data);
}
void isEmpty(Deque* D){
    if(D->taille==0){
        printf('deque vide');
        return;
    }
    printf('deque non vide');
}
void size(Deque* D){
    printf("%d\n", D->taille);
}
void print_deque(Deque* D){
    Node *courant=D->debut;
    while(courant!=NULL){
        printf("%d -> ", courant->data);
        courant=courant->next;
    }
    printf("NULL\n");
}
