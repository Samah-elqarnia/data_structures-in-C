#ifndef DEQUE_H
#define DEQUE_H

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

typedef struct {
    Node *debut;
    Node *fin;
    int taille;
} Deque;

Node* create_node(int data);
void initialiser_deque(Deque* D);
void insertFirst(Deque* D, int data);
void insertLast(Deque* D, int data);
void deleteFirst(Deque* D);
void deleteLast(Deque* D);
void getFirst(Deque* D);
void getLast(Deque* D);
void isEmpty(Deque* D);
void size(Deque* D);
void print_deque(Deque* D);

#endif