#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* create_node(int data);
void insert_voidlist(Node** L, int data);
void insert_head(Node** L, int data);
void insert_tail(Node** L, int data);
void insert(Node** L, int data, int pos);
void delete_head(Node** L);
void destroy(Node** L);
void print_list(Node* L);

#endif // LINKED_LIST_H
