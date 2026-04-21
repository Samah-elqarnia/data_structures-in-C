#include <stdio.h>
#include <stdlib.h>
#include "../include/doubly_linked_list.h"

int main() {
    Node* head = NULL;

    printf("=== Test de la liste doublement chainee ===\n\n");

    printf("1. Insertion en tete (10, 20):\n");
    insert_head(&head, 10);
    insert_head(&head, 20);
    print_list(head);

    printf("\n2. Insertion en queue (30):\n");
    insert_tail(&head, 30);
    print_list(head);

    printf("\n3. Insertion a la position 2 (valeur 15):\n");
    insert(&head, 15, 2);
    print_list(head);

    printf("\n4. Suppression a la position 1 (tete):\n");
    delete(&head, 1);
    print_list(head);

    printf("\n5. Suppression a la position 3 (queue):\n");
    delete(&head, 3);
    print_list(head);

    printf("\n6. Insertion en liste vide (40):\n");
    insert_voidlist(&head, 40);
    print_list(head);

    printf("\n=== Fin des tests ===\n");

    return 0;
}
