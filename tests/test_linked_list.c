#include <stdio.h>
#include <stdlib.h>
#include "../include/linked_list.h"

int main() {
    Node* list = NULL;
    
    printf("=== Test de la liste chainee ===\n\n");
    
    printf("1. Insertion en tete (10, 20): ");
    insert_head(&list, 10);
    insert_head(&list, 20);
    print_list(list); // Attendu: 20 -> 10 -> NULL
    
    printf("2. Insertion en queue (30): ");
    insert_tail(&list, 30);
    print_list(list); // Attendu: 20 -> 10 -> 30 -> NULL
    
    printf("3. Insertion a la position 2 (valeur 15): ");
    insert(&list, 15, 2);
    print_list(list); // Attendu: 20 -> 15 -> 10 -> 30 -> NULL
    
    printf("4. Suppression en tete: ");
    delete_head(&list);
    print_list(list); // Attendu: 15 -> 10 -> 30 -> NULL
    
    printf("5. Destruction de la liste...\n");
    destroy(&list);
    
    if (list == NULL) {
        printf("-> Destruction reussie, la liste est bien detruite (pointeur NULL).\n");
    } else {
        printf("-> Erreur lors de la destruction de la liste.\n");
    }
    
    printf("\n=== Fin des tests ===\n");
    
    return 0;
}
