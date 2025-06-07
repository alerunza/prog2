#include "charArrayQueue.h"
#include <stdio.h>
#include <string.h>

/* @brief Restituisce una coda vuota, se non trova memoria restituisce NULL */
CharQueueADT mkQueue(){

    /* if(capacity == NULL){
        return;
        } */
       
    CharQueueADT newQueue = (CharQueueADT)malloc(sizeof(struct charQueue));

    newQueue->capacity = INITIAL_CAPACITY;
    newQueue->a = (char *)malloc(sizeof(char) * newQueue->capacity);
    newQueue->size = 0;
    newQueue->rear = 0;
    newQueue->front = 0;

    return newQueue;
}

/* @brief Distrugge la coda, recuperando la memoria */
void dsQueue(CharQueueADT *pq){
    free((*pq)->a);
    free(*pq);
    *pq = NULL;
}

_Bool isEmpty(CharQueueADT q) {
    return (q->size == 0);
}

int full(CharQueueADT q) {
    return (q->size == q->capacity);
}

/* @brief Aggiunge un elemento in fondo alla coda, restituisce esito 0/1 */
_Bool enqueue(CharQueueADT q, const char e){

    if(full(q)){
        char *temp = q->a;
        int tempCapacity = q->capacity;

        q->capacity *= 2;
        q->a = (char *)malloc(sizeof(char) * q->capacity);
        
        if(q->a == -1){ // da verificare
            return 0;
        }

        int x = 0;
        for (int i = q->front; i < tempCapacity; i++, x++){
            q->a[x] = temp[i];
        }

        for (int i = 0; i < q->rear; i++, x++){
            q->a[x] = temp[i];
        }

        free(temp);
        temp = NULL;

        q->front = 0;
        q->rear = x;
    }
    q->a[q->rear] = e;

    (q->rear)++;

    return 1;
}

/* @brief Toglie e restituisce l'elemento in testa alla coda, restituisce esito 0/1 */
_Bool dequeue(CharQueueADT q, char*res){
    if(isEmpty(q)){
        return 0;
    }

    *res = q->a[q->front];
    (q->front)++;
    
    if(q->size == (q->capacity/4)){
        char *temp = q->a;
        int tempCapacity = q->capacity;

        q->capacity /= 2;
        q->a = (char *)malloc(sizeof(char) * q->capacity);

        if(q->a == -1){ // da verificare
            return 0;
        }

        int x = 0;
        if(q->front > q->rear){
            for (int i = q->front; i < tempCapacity; i++, x++){
                q->a[x] = temp[i];
            }
            
            for (int i = 0; i < q->rear; i++, x++){
                q->a[x] = temp[i];
            }
        } else if(q->rear > q->front){
            for (int i = q->front; i < q->rear; i++, x++){
                q->a[x] = temp[i];
            }
        }

        free(temp);
        temp = NULL;

        q->front = 0;
        q->rear = x;
    }


    return 1;
}