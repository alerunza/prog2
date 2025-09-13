#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node CharNode, *CharList;

struct node {
  char data;
  CharList next;
};

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
 * Data una lista di caratteri *ptr e una stringa str, modifica *ptr inserendo
 * un nodo nuovo per ciascun carattere di str.  I nodi nuovi vanno inseriti
 * prima della prima occorrenza del carattere 'Z' nella lista. Se 'Z' non
 * occorre vanno inseriti in testa alla lista. I nuovi nodi vanno inseriti nello
 * stesso ordine con cui si susseguono nella stringa.
 *
 * Non considera l'eventualità che la malloc fallisca.
 * Se ptr == NULL restituisce 0, altrimenti restituisce 1.
 * Se s == NULL o ptr == NULL, non modifica ptr.
 *
 * ESEMPI:
 * (1) data *ptr == [A,x,8] ed s == "k$2e"  restituisce 1 e causa *ptr ==
 * [k,$,2,e,A,x,8] (2) data ptr == NULL ed s == "Pluto" restituisce 0 e non
 * modifica ptr (3) data *ptr == [] ed s == "Pluto" restituisce 1 e causa *ptr
 * == [P,l,u,t,o] (4) data *ptr == [P,A,Z,Z,O] ed s == "Pluto" restituisce 1 e
 * causa *ptr == [P,A,P,l,u,t,o,Z,Z,O] (5) data *ptr == [p,a,z,z,o] ed s ==
 * "Pluto" restituisce 1 e causa *ptr == [P,l,u,t,o,p,a,z,z,o] (6) data *ptr ==
 * [p,a,z,z,o] ed s == NULL restituisce 1 e non modifica ptr
 */
int insert(CharList *ptr, char const *s) {

  if (ptr == NULL)
    return 0;

  if (s == NULL && *ptr != NULL)
    return 1;

  CharList curr = *ptr;
  CharList prev = NULL;
  // CharList next = NULL;

  int i = 0;

  while (curr != NULL) {
    if (curr->data == 'Z') {
      while (s[i] != '\0') {
        CharList newPtr = (CharList)malloc(sizeof(CharNode));
        if (prev) {
          *ptr = newPtr;
          newPtr->next = curr;
          newPtr->data = s[i];
          prev = newPtr;
        } else {
          prev->next = newPtr;
          newPtr->data = s[i];
          newPtr->next = curr;
        }
        i++;
      }
    } else {
      CharList head = NULL;
      CharList tail = NULL;

      CharList newPtr = (CharList)malloc(sizeof(CharNode));

      newPtr->data = curr->data;
      newPtr->next = NULL;

      if (head == NULL) {
        head = tail = newPtr;
      } else {
        tail->next = newPtr;
        tail = newPtr;
      }
    }

    curr = curr->next;
  }

  return 1;
}

/**
 * Invoca la funzione insert sulla lista [Z,A,N,T,E] e sulla stringa "RON",
 * stampa il valore int restituito dalla funzione, poi libera la memoria
 * occupata dalla lista.
 */
int main() {

  char *str = "RON";

  CharList list = (CharList)malloc(sizeof(CharNode));
  list->data = 'Z';
  list->next = (CharList)malloc(sizeof(CharNode));
  list->next->data = 'A';
  list->next->next = (CharList)malloc(sizeof(CharNode));
  list->next->next->data = 'N';
  list->next->next->next = (CharList)malloc(sizeof(CharNode));
  list->next->next->next->data = 'T';
  list->next->next->next->next = (CharList)malloc(sizeof(CharNode));
  list->next->next->next->next->data = 'E';
  list->next->next->next->next->next = NULL;

  printList(list);

  int risultato = insert(&list, str);

  printf("%d\n", risultato);

  printList(list);

  freeList(list);

  return 0;
}
