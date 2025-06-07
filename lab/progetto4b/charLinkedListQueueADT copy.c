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
};

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
	
	ListNodePtr current=(*pq)->front;
	
	while(current != NULL){
		ListNodePtr temp = current;
		current = current->next;
		free(temp);
	}
	
    free(*pq);
    *pq = NULL;
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
	
	return 1;
}