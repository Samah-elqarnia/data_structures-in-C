#include <stdio.h>
#include <stdlib.h>
#include "../include/deque.h"

int main() {
    printf("=== Lancement des tests pour Deque ===\n");

    // Initialisation du Deque
    Deque D;
    D.debut = NULL;
    D.fin = NULL;
    D.taille = 0;

    printf("\n--- Test: File Vide ---\n");
    isEmpty(&D);
    size(&D);

    printf("\n--- Test: Insertion au debut ---\n");
    printf("Insertion de 10...\n");
    insertFirst(&D, 10);
    print_deque(&D);

    printf("Insertion de 5...\n");
    insertFirst(&D, 5);
    print_deque(&D);

    printf("\n--- Test: Insertion a la fin ---\n");
    printf("Insertion de 20...\n");
    insertLast(&D, 20);
    print_deque(&D);

    printf("\n--- Test: Verification de la taille et des extremites ---\n");
    size(&D);
    getFirst(&D);
    getLast(&D);

    printf("\n--- Test: Suppression au debut ---\n");
    deleteFirst(&D);
    print_deque(&D);
    size(&D);

    printf("\n--- Test: Suppression a la fin ---\n");
    deleteLast(&D);
    print_deque(&D);
    size(&D);

    printf("\n--- Test: Vider la file ---\n");
    deleteLast(&D);
    print_deque(&D);
    isEmpty(&D);

    printf("\n=== Tests termines avec succes ===\n");

    return 0;
}
