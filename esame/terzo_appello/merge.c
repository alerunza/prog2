#include <stdio.h>
#include <stdlib.h>

typedef struct node IntNode, *IntList;

struct node {
    int data;
    IntList next;
};

IntList merge(IntList *lsPtr1, IntList *lsPtr2) {
    IntList head = NULL;
    IntList tail = NULL;

    while (*lsPtr1 != NULL || *lsPtr2 != NULL) {
        IntList *minList;

        if (*lsPtr1 == NULL)
            minList = lsPtr2;
        else if (*lsPtr2 == NULL)
            minList = lsPtr1;
        else if ((*lsPtr1)->data < (*lsPtr2)->data)
            minList = lsPtr1;
        else
            minList = lsPtr2;

        IntList node = *minList;
        *minList = node->next;
        node->next = NULL;

        if (head == NULL) {
            head = node;
            tail = node;
        } else {
            tail->next = node;
            tail = node;
        }
    }

    return head;
}

IntList creaLista(int *arr, int len) {
    IntList head = NULL, tail = NULL;
    for (int i = 0; i < len; i++) {
        IntList nuovo = (IntList)malloc(sizeof(IntNode));
        nuovo->data = arr[i];
        nuovo->next = NULL;
        if (head == NULL)
            head = tail = nuovo;
        else {
            tail->next = nuovo;
            tail = nuovo;
        }
    }
    return head;
}

void stampaLista(IntList l) {
    printf("[");
    while (l != NULL) {
        printf("%d", l->data);
        if (l->next != NULL) printf(" -> ");
        l = l->next;
    }
    printf("]\n");
}

void libera(IntList l) {
    while (l != NULL) {
        IntList tmp = l;
        l = l->next;
        free(tmp);
    }
}

int main() {
    int a1[] = {1, 5, 9};
    int a2[] = {0, 2, 4, 6, 8};

    IntList l1 = creaLista(a1, 3);
    IntList l2 = creaLista(a2, 5);

    printf("Lista 1: ");
    stampaLista(l1);
    printf("Lista 2: ");
    stampaLista(l2);

    IntList risultato = merge(&l1, &l2);

    printf("Merged:  ");
    stampaLista(risultato);

    libera(risultato);

    return 0;
}
