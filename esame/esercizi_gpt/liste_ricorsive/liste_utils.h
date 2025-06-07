#ifndef LISTE_UTILS_H
#define LISTE_UTILS_H

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} IntNode, *IntList;

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

#endif
