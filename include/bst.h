#ifndef BST_H
#define BST_H

typedef struct BSTNode {
    int data;
    struct BSTNode* left;
    struct BSTNode* right;
} BSTNode;

typedef struct {
    BSTNode *root;
    int taille;
} BST;

BSTNode* create_bst_node(int data);
void initialiser_bst(BST* B);
void insert_bst(BST* B, int data);
void print_by_level(BST* B);
int search_bst(BST* B, int data);
void prefixe_traversal(BST* B);
void suffixe_traversal(BST* B);
void infixe_traversal(BST* B);
BSTNode* min_bst(BST* B);
BSTNode* max_bst(BST* B);
BSTNode* delete_bst(BST* B, int data);

#endif