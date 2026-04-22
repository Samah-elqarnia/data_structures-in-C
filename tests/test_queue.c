#include <stdio.h>
#include <stdlib.h>
#include "../include/queue.h"

int main() {
    Queue maFile;

    printf("=== Test de la file (Queue) ===\n\n");

    printf("1. Initialisation de la file:\n");
    initialiser_queue(&maFile);
    print_queue(&maFile);

    printf("\n2. Enfiler (enqueue) 10, 20 et 30:\n");
    enqueue(&maFile, 10);
    enqueue(&maFile, 20);
    enqueue(&maFile, 30);
    print_queue(&maFile);
    printf("Taille: %d\n", maFile.taille);

    printf("\n3. Defiler (dequeue) le premier element (10):\n");
    dequeue(&maFile);
    print_queue(&maFile);

    printf("\n4. Defiler le deuxieme element (20):\n");
    dequeue(&maFile);
    print_queue(&maFile);

    printf("\n5. Defiler le dernier element (30):\n");
    dequeue(&maFile);
    print_queue(&maFile);
    printf("Taille: %d\n", maFile.taille);

    printf("\n6. Essayer de defiler une file vide:\n");
    dequeue(&maFile);

    printf("\n=== Fin des tests ===\n");

    return 0;
}
