#include "charQueueADT.h"
#include <stdio.h>
#include <string.h>
/* il valore 8 può essere cambiato */
#define INITIAL_CAPACITY 8

struct charQueue {
    int capacity; /* capacity == INITIAL CAPACITY*2^n, per qualche numero naturale n >= 0 */
    char* a; /* array, di dimensione capacity, che memorizza gli elementi presenti nella coda */
    int size; /* numero di elementi presenti nella coda (0 <= size <= capacity) */
    int rear; /* prima posizione libera in a (dove sarà memorizzato il prossimo elemento della coda (0 <= rear <= capacity-1) */
    int front; /* posizione in a dove (se size > 0) è memorizzato il primo elemento della coda (0 <= front <= capacity-1) */
    /* (front==rear) se e solo se ((size == 0) || (size == capacity)) */
    /* Gli elementi della coda sono in: a[front..rear-1] se rear > front, e in a[front..capacity-1],a[0..rear-1], se rear <= front */
    /* L'array si espande di un fattore due quando si riempie, e si dimezza (se capacity > INITIAL_CAPACITY) */
    /* quando size scende a capacity/4 (parametri personalizzabili) */      
    /* Se capacity > INITIAL_CAPACITY, allora il numero di elementi in coda è >= capacity/4 */
};


/* @brief Restituisce una coda vuota, se non trova memoria restituisce NULL */
CharQueueADT mkQueue(){
       
    CharQueueADT newQueue = (CharQueueADT)malloc(sizeof(struct charQueue));

    if(newQueue==NULL){
        return NULL;
    }

    newQueue->capacity = INITIAL_CAPACITY;
    newQueue->a = (char *)malloc(sizeof(char) * newQueue->capacity);
    
    if(newQueue->a==NULL){
        return NULL;
    }
    
    newQueue->size = 0;
    newQueue->rear = 0;
    newQueue->front = 0;

    return newQueue;
}

/* @brief Distrugge la coda, recuperando la memoria */
void dsQueue(CharQueueADT *pq){
    
    if(pq == NULL || *pq == NULL){
        return;
    }
    
    free((*pq)->a);
    free(*pq);
    *pq = NULL;
}

_Bool isEmpty(CharQueueADT q) {
    return (q == NULL || q->size == 0);
}

/* @brief Aggiunge un elemento in fondo alla coda, restituisce esito 0/1 */
_Bool enqueue(CharQueueADT q, const char e){
    
    //is full
    if(q->size == q->capacity){
        
        // ho l'array pieno quindi ne creo uno nuovo di dimensione raddoppiata
        char *temp = (char *)malloc(sizeof(char) * q->capacity * 2);
        if(temp == NULL){
            return 0;   
        }
        
        // copio gli elementi che ho dall'array pieno a quello vuoto
        for(int i = 0; i < q->size; i++) {
            temp[i] = q->a[(q->front + i) % q->capacity];
        }
        
        // libero l'array "vecchio" che era pieno e non serve più
        free(q->a);
        
        // sovrascrivo l'array nuovo nello spazio giusto della struttura (q->a)
        q->a = temp;
        q->capacity *= 2;
        q->front = 0;
        q->rear = q->size;
    }
    
    q->a[q->rear] = e;
    q->rear = (q->rear + 1) % q->capacity;
    q->size++;
    
    return 1;
}

/* @brief Toglie e restituisce l'elemento in testa alla coda, restituisce esito 0/1 */
_Bool dequeue(CharQueueADT q, char*res){
    if(isEmpty(q) || q==NULL || res==NULL){
        return 0;
    }
    
    // metto l'elemento in testa nella variabile res e faccio puntare front all'elemento successivo
    *res = q->a[q->front];
    q->front = (q->front+1) % q->capacity;
    q->size--;
    
    if(q->capacity > INITIAL_CAPACITY && q->size <= q->capacity / 4) {
        char *temp = (char *)malloc(sizeof(char) * (q->capacity / 2));
        if(temp == NULL){
            return 1;   
        }
        
        for(int i = 0; i < q->size; i++) {
            temp[i] = q->a[(q->front + i) % q->capacity];
        }
        
        free(q->a);
        q->a = temp;
        q->capacity /= 2;
        q->front = 0;
        q->rear = q->size;
    }
    
    return 1;
}

/* @brief Restituisce il numero degli elementi presenti nella coda */
int size(CharQueueADT q){
    if(q == NULL){
        return 0;
    } else {
        return q->size; 
    }
}

/* @brief Restituisce l'elemento nella posizione data (a partire dalla testa con indice zero) (senza toglierlo), restituisce esito 0/1 */
_Bool peek(CharQueueADT q, int position, char* res){
    if(q == NULL || position < 0 || position >= q->size || res == NULL){
        return 0;
    } else {
        // cerco la posizione data considerando che è un array circolare
        *res = q->a[(q->front + position) % q->capacity];
        return 1;
    }
}