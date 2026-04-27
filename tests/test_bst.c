#include <stdio.h>
#include <stdlib.h>
#include "../include/bst.h"

int main() {
    BST my_bst;
    initialiser_bst(&my_bst);

    printf("--- Test Insertion ---\n");
    insert_bst(&my_bst, 50);
    insert_bst(&my_bst, 30);
    insert_bst(&my_bst, 70);
    insert_bst(&my_bst, 20);
    insert_bst(&my_bst, 40);
    insert_bst(&my_bst, 60);
    insert_bst(&my_bst, 80);

    printf("Taille du BST : %d\n", my_bst.taille);

    printf("--- Traversals ---\n");
    printf("Infixe (devrait etre trie) : ");
    infixe_traversal(&my_bst);
    
    printf("Prefixe : ");
    prefixe_traversal(&my_bst);

    printf("Suffixe : ");
    suffixe_traversal(&my_bst);

    printf("Level-order : ");
    print_by_level(&my_bst);

    printf("--- Test Search ---\n");
    printf("Recherche 40 : %s\n", search_bst(&my_bst, 40) ? "Trouve" : "Non Trouve");
    printf("Recherche 90 : %s\n", search_bst(&my_bst, 90) ? "Trouve" : "Non Trouve");

    printf("--- Test Min/Max ---\n");
    BSTNode* min_node = min_bst(&my_bst);
    if (min_node) printf("Min : %d\n", min_node->data);
    BSTNode* max_node = max_bst(&my_bst);
    if (max_node) printf("Max : %d\n", max_node->data);

    printf("--- Test Deletion ---\n");
    printf("Suppression de 20 (feuille)... \n");
    delete_bst(&my_bst, 20);
    printf("Infixe : ");
    infixe_traversal(&my_bst);

    printf("Suppression de 30 (un enfant)... \n");
    delete_bst(&my_bst, 30);
    printf("Infixe : ");
    infixe_traversal(&my_bst);

    printf("Suppression de 50 (deux enfants, root)... \n");
    delete_bst(&my_bst, 50);
    printf("Infixe : ");
    infixe_traversal(&my_bst);
    
    if(my_bst.root) {
        printf("Nouvelle racine : %d\n", my_bst.root->data);
    }
    printf("Taille du BST : %d\n", my_bst.taille);

    return 0;
}
