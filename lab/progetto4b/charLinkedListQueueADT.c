#ifndef GUARD_CharQueueADT
#define GUARD_CharQueueADT
#include "linkedListQueue.h"
#include <stdlib.h>

/* Un tipo di dato astratto per le code di char */
typedef struct charQueue *CharQueueADT;

/* @brief Restituisce una coda vuota, se non trova memoria restituisce NULL */
CharQueueADT mkQueue(){
	CharQueueADT newQueue = (CharQueueADT)malloc(sizeof(char));
	
	if(newQueue==NULL){
		return NULL;
	}
	newQueue->front=NULL;
	newQueue->rear=NULL;
	
	return newQueue;
}

/* @brief Distrugge la coda, recuperando la memoria */
void dsQueue(CharQueueADT *pq){
	if(pq==NULL || *pq==NULL){
		return;
	}
	
	ListNodePtr current=*pq->front;
	
	while(current != NULL){
		ListNodePtr temp = current;
		current = current->next;
		free(temp);
	}
	
    free(pq);
    pq = NULL;
}

/* @brief Aggiunge un elemento in fondo alla coda, restituisce esito 0/1 */
_Bool enqueue(CharQueueADT q, const char e){
	if(q==NULL){
		return 0;
	}
	
	ListNodePtr newList = (ListNodePtr)malloc(sizeof (ListNode));
	
	if(newList==NULL){
		return 0;
	}
	
	newList -> data=e;
    newList -> next=NULL;
	
	if(isEmpty(q)){
		
	
	return 1;
}

/* @brief Toglie e restituisce l'elemento in testa alla coda, restituisce esito 0/1 */
_Bool dequeue(CharQueueADT q, char*res);

/* @brief Controlla se la coda è vuota */
_Bool isEmpty(CharQueueADT q){
    
}

/* @brief Restituisce il numero degli elementi presenti nella coda */
int size(CharQueueADT q);

/* @brief Restituisce l'elemento nella posizione data (a partire dalla testa con indice zero) (senza toglierlo), restituisce esito 0/1 */
_Bool peek(CharQueueADT q, int position, char* res);

#endif