#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

typedef struct PQNode {
    int data;
    int priority;       
    struct PQNode* next;
} PQNode;

typedef struct {
    PQNode *debut;      
    int taille;
} PriorityQueue;

PQNode* create_pq_node(int data, int priority);
void initialiser_priority_queue(PriorityQueue* PQ);
void insert_priority_queue(PriorityQueue* PQ, int data, int priority);
void delete_priority_queue(PriorityQueue* PQ);
void print_priority_queue(PriorityQueue* PQ);

#endif
