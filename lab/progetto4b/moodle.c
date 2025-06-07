#include "charQueueADT.h"
#include <stdlib.h>

typedef struct listNode ListNode, *ListNodePtr;
struct listNode {
    char data;
    ListNodePtr next;
};

struct charQueue {
    ListNodePtr front; /* Punta al primo nodo della lista, che contiene l'elemento in testa alla coda, se la coda è vuota vale NULL */
    ListNodePtr rear; /* Punta all'ultimo nodo della lista, che contiene l'elemento in fondo alla coda, se la coda è vuota vale NULL */
    
    /* aggiungere eventuali altre variabili per ottenere una implementazione più efficiente */
    int size; /* Numero di elementi presenti nella coda */
};

/* @brief Restituisce una coda vuota, se non trova memoria restituisce NULL */
CharQueueADT mkQueue() {
    CharQueueADT newQueue = (CharQueueADT)malloc(sizeof(struct charQueue));

    if(newQueue == NULL) {
        return NULL;
    }

    newQueue->front = NULL;
    newQueue->rear = NULL;
    newQueue->size = 0;

    return newQueue;
}

/* @brief Distrugge la coda, recuperando la memoria */
void dsQueue(CharQueueADT *pq) {
    if(pq == NULL || *pq == NULL) {
        return;
    }

    ListNodePtr current = (*pq)->front;

    while(current != NULL) {
        ListNodePtr temp = current;
        current = current->next;
        free(temp);
    }

    free(*pq);
    *pq = NULL;
}

/* @brief Controlla se la coda è vuota */
_Bool isEmpty(CharQueueADT q) {
    return (q == NULL || q->size == 0);
}

/* @brief Aggiunge un elemento in fondo alla coda, restituisce esito 0/1 */
_Bool enqueue(CharQueueADT q, const char e) {
    if(q == NULL) {
        return 0;
    }

    ListNodePtr newNode = (ListNodePtr)malloc(sizeof(ListNode));
    if(newNode == NULL) {
        return 0;
    }

    newNode->data = e;
    newNode->next = NULL;

    if(q->rear == NULL) {
        q->front = newNode;
        q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }

    q->size++;
    return 1;
}

/* @brief Toglie e restituisce l'elemento in testa alla coda, restituisce esito 0/1 */
_Bool dequeue(CharQueueADT q, char *res) {
    if(isEmpty(q) || res == NULL) {
        return 0;
    }

    ListNodePtr temp = q->front;
    *res = temp->data;

    q->front = temp->next;

    if(q->front == NULL) {
        q->rear = NULL;
    }

    free(temp);
    q->size--;
    return 1;
}

/* @brief Restituisce il numero degli elementi presenti nella coda */
int size(CharQueueADT q) {
    if(q == NULL) {
        return 0;
    }

    return q->size;
}

/* @brief Restituisce l'elemento nella posizione data (a partire dalla testa con indice zero) (senza toglierlo), restituisce esito 0/1 */
_Bool peek(CharQueueADT q, int position, char *res) {
    if(q == NULL || position < 0 || position >= q->size || res == NULL) {
        return 0;
    }

    ListNodePtr current = q->front;
    for(int i = 0; i < position; i++) {
        current = current->next;
    }

    *res = current->data;
    return 1;
}