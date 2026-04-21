#include "../include/doubly_linked_list.h"
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
void insert_voidlist(Node** L, int data){
    Node* NE;
    NE= create_node(data);
    *L=NE; 
}
void insert_head(Node** L, int data){
    Node* NE;
    NE = create_node(data); 
    if (*L == NULL) {
        *L = NE;
    } else {
        NE->next = *L;
        (*L)->prev = NE;
        *L = NE;
    }
}

void insert_tail(Node** L, int data){
    Node *NE, *courant;
    NE = create_node(data);
    if (*L == NULL) { 
        *L = NE;
    } else {
        courant = *L;
        // Parcourir jusqu'au dernier element
        while(courant->next != NULL){
            courant = courant->next;
        }
        courant->next = NE;
        NE->prev= courant;
    }
}

void insert(Node** L, int data, int pos){
    int i, taille = 0;
    Node *NE, *courant;
    // Si la liste est vide ou pos=1, on insere en tete
    if (*L == NULL || pos <= 1) {
        insert_head(L, data);
        return;
    }

    NE = create_node(data);
    
    // Calcul de la taille de la liste
    for (courant = *L; courant != NULL; courant = courant->next) {
        taille++;
    }

    if(pos >= 1 && pos <= taille + 1){
        courant = *L;
        // On s'arrete au noeud (pos - 1)
        for (i = 1; i < pos - 1 && courant->next != NULL; i++){
            courant = courant->next;
        }
        NE->next = courant->next;
        NE->prev = courant;
        if (courant->next != NULL) {
            courant->next->prev = NE;
        }
        courant->next = NE;
    } else {
        free(NE); // Liberer si position invalide
        printf("Position invalide\n");
    }
}

// suppression selon la position 
void delete(Node** L, int pos){
    int i, taille = 0;
    Node *elem_supp, *courant;
    for (courant=*L;courant!=NULL;courant=courant->next){
        taille++;
    }
    if (taille == 0){
        printf("liste vide\n");
        return;
    }
    if (pos < 1 || pos > taille){
        printf("position invalide\n");
        return;
    } 
    //suppression du premier element
    if (pos == 1){
        elem_supp=*L;
        *L=(*L)->next;
        if (*L != NULL) {
            (*L)->prev=NULL;
        }
        free(elem_supp);
        return;
    }
    //suppression du dernier element
    if (pos == taille){
        courant=*L;
        while(courant->next!=NULL){
            courant=courant->next;
        }
        elem_supp=courant;
        if (courant->prev != NULL) {
            courant->prev->next=NULL;
        } else {
            *L = NULL;
        }
        free(elem_supp);
        return;
    }
    // suppression au milieu
    courant=*L;
    for(i=1;i<pos;i++){
        courant=courant->next;
    }
    elem_supp=courant;
    courant->next->prev=courant->prev;
    courant->prev->next= courant->next; 
    free(elem_supp);
}

void print_list(Node* L){
    Node *courant; // Remplacement de ^ par *
    courant = L;
    while(courant != NULL){
        printf("%d -> ", courant->data); // Guillemets doubles pour printf
        courant = courant->next;
    }
    printf("NULL\n");
} 


