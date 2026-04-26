#include <stdio.h>
#include <stdlib.h>
#include "../include/priority_queue.h"

int main() {
    printf("=== Lancement des tests pour Priority Queue ===\n");

    PriorityQueue PQ;
    initialiser_priority_queue(&PQ);

    printf("\n--- Test: File Vide ---\n");
    print_priority_queue(&PQ);
    printf("Taille: %d\n", PQ.taille);

    printf("\n--- Test: Insertion de plusieurs elements ---\n");
    printf("Insertion de 10 (priorite 3)...\n");
    insert_priority_queue(&PQ, 10, 3);
    
    printf("Insertion de 20 (priorite 1)...\n");
    insert_priority_queue(&PQ, 20, 1);
    
    printf("Insertion de 30 (priorite 2)...\n");
    insert_priority_queue(&PQ, 30, 2);

    printf("Insertion de 40 (priorite 5)...\n");
    insert_priority_queue(&PQ, 40, 5);

    printf("\nEtat de la file (triee par priorite croissante):\n");
    print_priority_queue(&PQ);
    printf("Taille: %d\n", PQ.taille);

    printf("\n--- Test: Suppression de l'element prioritaire (debut) ---\n");
    printf("Suppression...\n");
    delete_priority_queue(&PQ);
    print_priority_queue(&PQ);
    printf("Taille: %d\n", PQ.taille);

    printf("\nSuppression...\n");
    delete_priority_queue(&PQ);
    print_priority_queue(&PQ);
    
    printf("\n--- Test: Vider la file ---\n");
    delete_priority_queue(&PQ);
    delete_priority_queue(&PQ);
    print_priority_queue(&PQ);
    printf("Taille: %d\n", PQ.taille);

    printf("\n=== Tests termines avec succes ===\n");

    return 0;
}
