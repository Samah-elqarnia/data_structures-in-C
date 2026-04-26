#include "../include/priority_queue.h"
#include <stdio.h>
#include <stdlib.h>

PQNode* create_pq_node(int data, int priority){
    PQNode *NE;
    NE=(PQNode*)malloc(sizeof(PQNode));
    if(NE==NULL){
        printf("memoire insuffisante\n");
        exit(-1);
    }
    else{
        NE->data=data;
        NE->priority=priority;
        NE->next=NULL;
        return NE;
    }
}
void initialiser_priority_queue(PriorityQueue* PQ){
    if(PQ==NULL) return;
    PQ->debut=NULL;     
    PQ->taille=0;
}
void insert_priority_queue(PriorityQueue* PQ, int data, int priority){
    PQNode *NE=create_pq_node(data, priority);
    // Cas 1 : File vide ou insertion en tête (priorité plus petite que le début)
    if(PQ->debut==NULL || priority < PQ->debut->priority){
        NE->next=PQ->debut;
        PQ->debut=NE;
    }
    else{
        // Cas 2 : Insertion au milieu ou à la fin
        PQNode *courant=PQ->debut;
        while (courant->next!=NULL && courant->next->priority <= priority){
            courant=courant->next;
        }
        NE->next=courant->next;
        courant->next=NE;
    }
    PQ->taille++;
}
void delete_priority_queue(PriorityQueue* PQ){
    if(PQ->debut==NULL){
        printf("la file est vide\n");
    }
    else{
        PQNode *elem_supp=PQ->debut;
        PQ->debut=PQ->debut->next;
        free(elem_supp);
        PQ->taille--;
    }
}
void print_priority_queue(PriorityQueue* PQ){
    PQNode *courant=PQ->debut;
    while(courant!=NULL){
        printf("%d -> ", courant->data);
        courant=courant->next;
    }
    printf("NULL\n");
}
