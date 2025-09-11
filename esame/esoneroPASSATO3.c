#include <stdio.h>
#include <stdlib.h>

typedef struct node CharNode, *CharList;

struct node {
  char data;
  CharList next;
};

/* INSERIRE QUI EVENTUALI FUNZIONI AUSILIARIE */

void printList(CharList l) {
  while (l != NULL) {
    printf("%c ", l->data);
    l = l->next;
  }
}

void freeList(CharList l) {
  while (l != NULL) {
    CharList temp = l;
    l = l->next;
    free(temp);
  }
}

/**
 * Date due liste di caratteri l ed r, restituire una nuova lista p (senza
 * modificare le liste l ed r) che contenga il più lungo prefisso di l per
 * cui nessun suo carattere ha un carattere uguale nella posizione
 * corrispondente di r.
 *
 * Si definisce "prefisso" di una lista una qualunque sotto-lista di nodi
 * dall'inizio. Non considera l'eventualità che la malloc fallisca.
 *
 * ESEMPI (rappresentando le liste senza separare i caratteri, per compattezza):
 * (1) date l=[] e s=[], restituisce p=[]
 * (2) date l=[] e s=[p,i,p,p,o], restituisce p=[]
 * (3) date l=[p,i,p,p,o] e s=[], restituisce p=[p,i,p,p,o]
 * (4) date l=[p,i,p,p,o] e s=[p,i,p,p,o], restituisce p=[]
 * (5) date l=[s,u,p,e,r,p,i,p,p,o] e s=[p,l,u,t,o], restituisce
 * p=[s,u,p,e,r,p,i,p,p,o] (6) date l=[p,l,u,t,o] e s=[s,u,p,e,r,p,i,p,p,o],
 * restituisce p=[p,l,u,t,o] (7) date l=[s,u,p,e,r,p,i,p,p,o] e s=[p,i,p,p,o],
 * restituisce p=[s,u], perché la p seguente è in comune (8) date l=[p,i,p,p,o]
 * e s=[s,u,p,e,r,p,i,p,p,o], restituisce p=[p,i], perché la p seguente è in
 * comune
 *
 * NOTA: questa funzione compare negli errori di compilazione come
 * "student_antiPrefix" NOTA: questa funzione viene testata anche
 * indipendentemente dal vostro main
 */
CharList antiPrefix(CharList l, CharList r) {

  CharList pHead = NULL, pTail = NULL;

  while ((l != NULL && r != NULL) && (l->data != r->data)) {
    CharList newP = (CharList)malloc(sizeof(CharNode));

    newP->data = l->data;
    newP->next = NULL;

    if (pHead == NULL) {
      pHead = newP;
      pTail = newP;
    } else {
      pTail->next = newP;
      pTail = newP;
    }

    l = l->next;
    r = r->next;
  }

  while (l != NULL && r == NULL) {
    CharList newP = (CharList)malloc(sizeof(CharNode));

    newP->data = l->data;
    newP->next = NULL;

    if (pHead == NULL) {
      pHead = newP;
      pTail = newP;
    } else {
      pTail->next = newP;
      pTail = newP;
    }

    l = l->next;
  }

  return pHead;
}

/**
 * Invoca la funzione antiPrefix sulle liste [C,I,A,O] e [Q,U,A], stampa la
 * lista restituita dalla funzione, poi libera la memoria occupata da tutte le
 * liste.
 *
 * NOTA: questa funzione compare negli errori di compilazione come
 * "student_main" NOTA: cercate come prima cosa di far compilare il vostro
 * codice, piuttosto anche commentando codice nel main, per avere feedback
 * almeno sui test della funzione
 */
int main() {

  CharList left = (CharList)malloc(sizeof(CharNode));
  left->data = 'C';
  left->next = (CharList)malloc(sizeof(CharNode));
  left->next->data = 'I';
  left->next->next = (CharList)malloc(sizeof(CharNode));
  left->next->next->data = 'A';
  left->next->next->next = (CharList)malloc(sizeof(CharNode));
  left->next->next->next->data = 'O';
  left->next->next->next->next = NULL;

  CharList right = (CharList)malloc(sizeof(CharNode));
  right->data = 'Q';
  right->next = (CharList)malloc(sizeof(CharNode));
  right->next->data = 'U';
  right->next->next = (CharList)malloc(sizeof(CharNode));
  right->next->next->data = 'A';
  right->next->next->next = NULL;

  // CharList list = antiPrefix(['C','I','A','O'], ['Q', 'U', 'A']);

  CharList list = antiPrefix(left, right);

  freeList(left);
  freeList(right);

  printList(list);
  freeList(list);

  return 0;
}
