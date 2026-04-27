#include "../include/bst.h"
#include <stdio.h>
#include <stdlib.h>

BSTNode* create_bst_node(int data){
    BSTNode *NE = (BSTNode*)malloc(sizeof(BSTNode));
    if(NE==NULL){
        printf("memoire insuffisante\n");
        exit(-1);
    }
    NE->left=NULL;
    NE->right=NULL;
    NE->data=data;
    return NE;
}

void initialiser_bst(BST* B){
    B->root=NULL;
    B->taille=0;
}

void insert_bst(BST* B, int data){
    BSTNode *NE = create_bst_node(data);
    if(B->root==NULL){
        B->root=NE;
        B->taille++;
        return;
    }
    BSTNode *temp=B->root;
    while(1){
        if(data > temp->data){
            if(temp->right==NULL){
                temp->right=NE;
                B->taille++;
                break;
            }
            else{
                temp=temp->right;
            }
        }
        else if(data < temp->data){
            if(temp->left==NULL){
                temp->left=NE;
                B->taille++;
                break;
            }
            else{
                temp=temp->left;
            }
        }
        else {
            free(NE); // element already exists, avoid duplicates
            break;
        }
    }
}

void print_by_level(BST* B){
    if (B->root == NULL) return;
    int size = (B->taille > 0) ? B->taille : 100;
    BSTNode** queue = (BSTNode**)malloc(size * sizeof(BSTNode*));
    int front = 0, rear = 0;
    
    queue[rear++] = B->root;
    while(front < rear) {
        BSTNode* temp = queue[front++];
        printf("%d ", temp->data);
        if (temp->left != NULL) queue[rear++] = temp->left;
        if (temp->right != NULL) queue[rear++] = temp->right;
    }
    printf("\n");
    free(queue);
}

int search_bst(BST* B, int data){
    BSTNode *temp = B->root;
    while(temp!=NULL && data != temp->data){
        if(data < temp->data){
            temp = temp->left;
        }
        else{
            temp = temp->right;
        }
    }
    if(temp==NULL){
        return 0;
    }
    else{
        return 1;
    }
}

void prefixe_node(BSTNode* node) {
    if(node!=NULL){
        printf("%d ",node->data);
        prefixe_node(node->left);
        prefixe_node(node->right);
    }
}

void prefixe_traversal(BST* B){
    prefixe_node(B->root);
    printf("\n");
}

void suffixe_node(BSTNode* node) {
    if(node!=NULL){
        suffixe_node(node->left);
        suffixe_node(node->right);
        printf("%d ",node->data);
    }
}

void suffixe_traversal(BST* B){
    suffixe_node(B->root);
    printf("\n");
}

void infixe_node(BSTNode* node) {
    if(node!=NULL){
        infixe_node(node->left);
        printf("%d ",node->data);
        infixe_node(node->right);
    }
}

void infixe_traversal(BST* B){
    infixe_node(B->root);
    printf("\n");
}

BSTNode* min_bst(BST* B){
    if(B->root == NULL){
        printf("arbre vide\n");
        return NULL;
    }
    BSTNode *temp = B->root;
    while(temp->left!=NULL){
        temp=temp->left;
    }
    return temp;
}

BSTNode* max_bst(BST* B){
    if(B->root == NULL){
        printf("arbre vide\n");
        return NULL;
    }
    BSTNode *temp = B->root;
    while(temp->right!=NULL){
        temp=temp->right;
    }
    return temp;
}

BSTNode* min_bst_node(BSTNode* root) {
    if (root == NULL) return NULL;
    while(root->left != NULL) root = root->left;
    return root;
}

BSTNode* delete_node(BSTNode* root, int data) {
    if (root == NULL) return NULL;
    if (data < root->data) {
        root->left = delete_node(root->left, data);
    } else if (data > root->data) {
        root->right = delete_node(root->right, data);
    } else {
        if (root->left == NULL && root->right == NULL) {
            free(root);
            return NULL;
        } else if (root->left == NULL) {
            BSTNode* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            BSTNode* temp = root->left;
            free(root);
            return temp;
        } else {
            BSTNode* temp = min_bst_node(root->right);
            root->data = temp->data;
            root->right = delete_node(root->right, temp->data);
        }
    }
    return root;
}

BSTNode* delete_bst(BST* B, int data) {
    if (B->root == NULL) return NULL;
    int found = search_bst(B, data);
    if (found) {
        B->root = delete_node(B->root, data);
        B->taille--;
    }
    return B->root;
}