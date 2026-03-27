// linked_list.c
#include "../include/linked_list.h"
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
        return NE;
    }
}

void insert_voidlist(Node** L, int data){
    Node* NE;
    NE= create_node(data);
    *L=NE; // Utiliser *L pour modifier le pointeur original
}

void insert_head(Node** L, int data){
    Node* NE;
    NE = create_node(data); // Remplacement de ^ par =
    if (*L == NULL) {
        *L = NE;
    } else {
        NE->next = *L;
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

    if(pos >= 1 && pos <= taille + 1){ // Remplacement de => par >=
        courant = *L;
        // On s'arrete au noeud (pos - 1)
        for (i = 1; i < pos - 1 && courant->next != NULL; i++){
            courant = courant->next;
        }
        NE->next = courant->next;
        courant->next = NE;
    } else {
        free(NE); // Liberer si position invalide
        printf("Position invalide\n");
    }
}

// cas au debut
void delete_head(Node** L){
    Node *elem_supp;
    if(*L == NULL) { 
        return; 
    }
    elem_supp = *L;
    *L = (*L)->next;
    free(elem_supp);
}

void destroy(Node** L){
    // on supprime le debut de la liste jusqu'a que L soit egal a NULL
    while(*L != NULL){
        delete_head(L);
    }
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