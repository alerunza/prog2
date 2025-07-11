#include <stdlib.h>
#include <stdio.h>
#include "list_helpers.h"

/**
 * Crea una lista collegata da un array di interi.
 */
IntList creaLista(int* arr, int n) {
    if (arr == NULL || n <= 0) return NULL;

    IntList head = NULL, tail = NULL;

    for (int i = 0; i < n; i++) {
        IntList newNode = (IntList) malloc(sizeof(IntNode));
        if (newNode == NULL) return NULL;

        newNode->data = arr[i];
        newNode->next = NULL;

        if (head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    return head;
}

/**
 * Stampa la lista su una riga, valori separati da spazio.
 */
void stampaLista(IntList l) {
    while (l != NULL) {
        printf("%d ", l->data);
        l = l->next;
    }
    printf("\n");
}

/**
 * Libera la memoria di tutta la lista.
 */
void liberaLista(IntList l) {
    while (l != NULL) {
        IntList temp = l;
        l = l->next;
        free(temp);
    }
}

/**
 * Elimina l'ultimo nodo dalla lista.
 * Restituisce 1 se successo, 0 se lista vuota o NULL.
 */
int eliminaUltimo(IntList* head) {
    if (head == NULL || *head == NULL) return 0;

    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return 1;
    }

    IntList prev = NULL;
    IntList curr = *head;

    while (curr->next != NULL) {
        prev = curr;
        curr = curr->next;
    }

    prev->next = NULL;
    free(curr);
    return 1;
}

/**
 * Elimina il penultimo nodo dalla lista.
 * Restituisce 1 se successo, 0 se lista con meno di 2 nodi o NULL.
 */
int eliminaPenultimo(IntList* head) {
    if (head == NULL || *head == NULL || (*head)->next == NULL) return 0;

    if ((*head)->next->next == NULL) {
        // lista con esattamente 2 nodi: elimina il primo (penultimo)
        IntList temp = *head;
        *head = (*head)->next;
        free(temp);
        return 1;
    }

    IntList prevPrev = NULL;
    IntList prev = *head;
    IntList curr = (*head)->next;

    while (curr->next != NULL) {
        prevPrev = prev;
        prev = curr;
        curr = curr->next;
    }

    // ora prev è penultimo nodo
    if (prevPrev == NULL) {
        // solo 3 nodi, penultimo è il secondo (prev)
        *head = curr;
        free(prev);
    } else {
        prevPrev->next = curr;
        free(prev);
    }

    return 1;
}

/**
 * Elimina il terzultimo nodo dalla lista.
 * Restituisce 1 se successo, 0 se lista con meno di 3 nodi o NULL.
 */
int eliminaTerzultimo(IntList* head) {
    if (head == NULL || *head == NULL) return 0;

    // Conta i nodi
    int count = 0;
    IntList temp = *head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    if (count < 3) return 0;

    if (count == 3) {
        // Elimina il primo nodo (terzultimo in lista di 3)
        IntList del = *head;
        *head = (*head)->next;
        free(del);
        return 1;
    }

    // Scorri fino al nodo prima del terzultimo
    temp = *head;
    for (int i = 0; i < count - 4; i++) {
        temp = temp->next;
    }

    // temp->next è il terzultimo nodo
    IntList del = temp->next;
    temp->next = del->next;
    free(del);
    return 1;
}
