#include <stdio.h>
#include <stdlib.h>
#include "../include/stack.h"

int main() {
    Stack* pile = NULL;

    printf("=== Test de la pile (Stack) ===\n\n");

    printf("1. Initialisation de la pile:\n");
    initialiser_pile(&pile);
    print_pile(pile);

    printf("\n2. Empiler (push) 10, 20 et 30:\n");
    push(&pile, 10);
    push(&pile, 20);
    push(&pile, 30);
    print_pile(pile);

    printf("\n3. Depiler (pop) le sommet (30):\n");
    pop(&pile);
    print_pile(pile);

    printf("\n4. Depiler (pop) encore un element (20):\n");
    pop(&pile);
    print_pile(pile);

    printf("\n5. Depiler le dernier element (10):\n");
    pop(&pile);
    print_pile(pile);

    printf("\n6. Essayer de depiler une pile vide:\n");
    pop(&pile);

    printf("\n=== Fin des tests ===\n");

    return 0;
}
