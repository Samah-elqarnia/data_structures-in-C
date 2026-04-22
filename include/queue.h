#ifndef QUEUE_H
#define QUEUE_H

typedef struct Element {
    int data;
    struct Element* next;
} Element;

typedef struct {
    Element *debut;
    Element *fin;
    int taille;
} Queue;

void initialiser_queue(Queue* Q);
void enqueue(Queue* Q, int data);
void dequeue(Queue* Q);
void print_queue(Queue* Q);

#endif