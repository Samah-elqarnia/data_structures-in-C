#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

Node* create_node(int data);
void insert_voidlist(Node** L, int data);
void insert_head(Node** L, int data);
void insert_tail(Node** L, int data);
void insert(Node** L, int data, int pos);
void delete(Node** L, int pos);
void print_list(Node* L);

#endif // LINKED_LIST_H