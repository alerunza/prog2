#include <stdio.h>
#include <stdlib.h>

typedef struct node IntNode, *IntList;
struct node {
  int data;
  IntList next;
};

/*
CONSEGNA
Scrivere la funzione

void separaMaggioreDellaMedia(IntList *lstPtr, IntList *mag, IntList *nonMag)

che, data una lista singolarmente linkata di interi, separa i nodi in due nuove
liste preservando l'ordine relativo originario:

  - in *mag vanno tutti e soli i nodi con valore strettamente maggiore
    della media aritmetica dei valori presenti nella lista originale;
  - in *nonMag vanno tutti i restanti nodi (valore <= media).

Al termine *lstPtr deve risultare NULL (tutti i nodi sono stati spostati).
Se lstPtr == NULL oppure *lstPtr == NULL, la funzione non fa nulla
e pone *mag == NULL e *nonMag == NULL.

Nota: la media va calcolata sulla lista di partenza; usare due passaggi:
      prima si calcola media, poi si spostano i nodi.
*/

void separaMaggioreDellaMedia(IntList *lstPtr, IntList *mag, IntList *nonMag) {
  *mag = NULL, *nonMag = NULL;

  if (lstPtr == NULL || *lstPtr == NULL) {
    return;
  }

  IntList nodoSomma = *lstPtr;

  int count = 0;
  int sum = 0;

  while (nodoSomma != NULL) {
    sum += nodoSomma->data;
    count++;
    nodoSomma = nodoSomma->next;
  }

  int average = sum / count;

  IntList magHead = NULL, magTail = NULL;
  IntList nonMagHead = NULL, nonMagTail = NULL;

  IntList curr = *lstPtr, next = NULL;

  while (curr != NULL) {
    next = curr->next;
    curr->next = NULL;
    if (curr->data >= average) {
      if (magHead == NULL) {
        magHead = curr;
        magTail = curr;
      } else {
        magTail->next = curr;
        magTail = curr;
      }
    } else {
      if (nonMagHead == NULL) {
        nonMagHead = curr;
        nonMagTail = curr;
      } else {
        nonMagTail->next = curr;
        nonMagTail = curr;
      }
    }
    curr = next;
  }

  *mag = magHead;
  *nonMag = nonMagHead;

  *lstPtr = NULL;
}

/* utility per i test */
IntList createList(int *a, int n) {
  IntList head = NULL, tail = NULL;
  for (int i = 0; i < n; i++) {
    IntList x = (IntList)malloc(sizeof(IntNode));
    x->data = a[i];
    x->next = NULL;
    if (head == NULL) {
      head = tail = x;
    } else {
      tail->next = x;
      tail = x;
    }
  }
  return head;
}

void printList(IntList l) {
  if (l == NULL) {
    printf("(vuota)\n");
    return;
  }
  while (l) {
    printf("%d", l->data);
    if (l->next)
      printf(" -> ");
    l = l->next;
  }
  printf("\n");
}

void freeList(IntList l) {
  while (l) {
    IntList t = l;
    l = l->next;
    free(t);
  }
}

int main(void) {
  /* caso 1: valori misti */
  int v1[] = {10, 20, 30, 40, 50};
  IntList L1 = createList(v1, sizeof(v1) / sizeof(v1[0]));
  IntList mag1 = NULL, non1 = NULL;

  printf("Caso 1 - Lista iniziale: ");
  printList(L1);

  separaMaggioreDellaMedia(&L1, &mag1, &non1);

  printf("  > Maggiore della media: ");
  printList(mag1);
  printf("  > Non maggiore della media: ");
  printList(non1);
  printf("  > Lista originale dopo separazione: ");
  printList(L1);

  freeList(mag1);
  freeList(non1);

  /* caso 2: tutti uguali */
  int v2[] = {5, 5, 5, 5};
  IntList L2 = createList(v2, sizeof(v2) / sizeof(v2[0]));
  IntList mag2 = NULL, non2 = NULL;

  printf("\nCaso 2 - Lista iniziale: ");
  printList(L2);

  separaMaggioreDellaMedia(&L2, &mag2, &non2);

  printf("  > Maggiore della media: ");
  printList(mag2);
  printf("  > Non maggiore della media: ");
  printList(non2);
  printf("  > Lista originale dopo separazione: ");
  printList(L2);

  freeList(mag2);
  freeList(non2);

  /* caso 3: lista vuota */
  IntList L3 = NULL, mag3 = NULL, non3 = NULL;
  printf("\nCaso 3 - Lista iniziale: ");
  printList(L3);
  separaMaggioreDellaMedia(&L3, &mag3, &non3);
  printf("  > Maggiore della media: ");
  printList(mag3);
  printf("  > Non maggiore della media: ");
  printList(non3);
  printf("  > Lista originale dopo separazione: ");
  printList(L3);

  return 0;
}
