#include <stdlib.h>
#include <stdio.h>

typedef struct node {
    int data;
    struct node *next;
} IntNode, *IntList;

void raddoppiaValori(IntList l){
    while(l != NULL){
        l->data *= 2;
        l = l->next;
    }
}

IntList creaLista(int a[], int len){
    IntList head = NULL;
    IntList tail = NULL;

    for (int i = 0; i < len; i++){
        IntList nuovo = (IntList)malloc(sizeof(IntNode));
        
        if(nuovo == NULL){
            return NULL;
        }

        nuovo->data = a[i];
        nuovo->next = NULL;

        if(head == NULL){
            head = nuovo;
            tail = nuovo;
        } else{
            tail->next = nuovo;
            tail = nuovo;
        }
    }

    return head;
}

/* void stampaLista(IntList l){
    while(l != NULL){
        printf("%d ", l->data);
        l = l->next;
    }
    printf("\n");
}
 */

//stampa "figa"
void stampaLista(IntList l) {
    printf("[");
    while (l != NULL) {
        printf("%d", l->data);
        if (l->next != NULL)
            printf(" -> ");
        l = l->next;
    }
    printf("]\n");
}


void libera(IntList l){
    while(l != NULL){
        IntList temp = l;
        l = l->next;
        free(temp);
    }
}

int main() {
    int dati[] = {1, 3, 5, 7};
    IntList lista = creaLista(dati, 4);

    stampaLista(lista);
    raddoppiaValori(lista);
    stampaLista(lista);

    libera(lista);
    return 0;
}
