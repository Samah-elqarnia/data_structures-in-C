#include "../include/bst.h"
#include "../include/queue.h"
#include <stdio.h>
#include <stdlib.h>

BSTNode* create_bst_node(int data){
    BSTNode *NE;
    NE=(BSTNode*)malloc(sizeof(BSTNode));
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
    BSTNode *NE,*temp;
    NE=create_bst_node(data);
    if(B->root==NULL){
        B->root=NE;
        B->taille++;
    }
    temp=B->root;
    while(1){
        if(NE->data>temp->data){
            if(temp->right==NULL){
                temp->right=NE;
                B->taille ++;
                break;
            }
            else{
                temp=temp->right;
            }

        }
        if(NE->data<temp->data){
            if(temp->left==NULL){
                temp->left=NE;
                B->taille++;
                break;
            }
            else{
                temp=temp->left;
            }
        }
    }
}

void print_by_level(BST* B){
    Queue *q;
    initialiser_queue(q);
    BSTNode *temp;
    temp=B->root;
    while(temp!=NULL){
        if(temp->left!=NULL){
            enqueue(q,temp->left);
        }
        if(temp->right!=NULL){
            enqueue(q,temp->right);
        }
        printf("%d",temp->data);
        temp=dequeue(q);
    }
}

int search_bst(BST* B, int data){
    while(B->root!=NULL && data != B->root->data){
        if(data < B->root->data){
            B->root= B->root->left;
        }
        else{
            B->root= B->root->right;
        }
    }
    if(root==NULL){
        return 0;
    }
    else{
        return 1;
    }
}
void prefixe_traversal(BST* B){
    if(B->root!=NULL){
        printf("%d",B->root->data);
        prefixe_traversal(B->root->left);
        prefixe_traversal(B->root->right);
    }
}
void suffixe_traversal(BST* B){
    if(B->root!=NULL){
        suffixe_traversal(B->root->left);
        suffixe_traversal(B->root->right);
        printf("%d",B->root->data);
    }
}
void infixe_traversal(BST* B){
    if(B->root!=NULL){
        infixe_traversal(B->root->left);
        printf("%d",B->root->data);
        infixe_traversal(B->root->right);
    }
}

BSTNode* min_bst(BST* B){
 BSTNode *temp;
 if(B->root ==NULL){
    printf("arbre vide\n");
    return NULL;
 }
 temp=B->root;
 while(temp->left!=NULL){
    temp=temp->left;
 }
 return temp;
}
BSTNode* max_bst(BST* B){
    BSTNode *temp;
    if(B->root ==NULL){
        printf("arbre vide\n");
        return NULL;
    }
    temp=B->root;
    while(temp->right!=NULL){
        temp=temp->right;
    }
    return temp;
}
BSTNode* delete_bst(BST* B, int data){
    
}