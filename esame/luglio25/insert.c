#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node CharNode, *CharList;
struct node {
  char data;
  CharList next;
};

/**
 * Data una lista di caratteri *ptr e una stringa str, modifica *ptr inserendo
 * un nodo nuovo per ciascun carattere di str. I nodi nuovi vanno inseriti dopo
 * la prima occorrenza del carattere 'Z' nella lista. Se 'Z' non occorre vanno
 * inseriti in coda alla lista. I nuovi nodi vanno inseriti nello stesso ordine
 * con cui si susseguono nella stringa.
 *
 * Non considera l'eventualità che la malloc fallisca.
 * Se ptr == NULL restituisce 0, altrimenti restituisce 1.
 * Se s == NULL o ptr == NULL, non modifica ptr.
 *
 * ESEMPI:
 (1) data *ptr == [A,x,8] ed s == "k$2e" restituisce 1 e causa *ptr == *
 [A,x,8,k,$,2,e] (2) data ptr == NULL ed s == "Pluto" restituisce 0 e non *
 modifica ptr (3) data *ptr == [] ed s == "Pluto" restituisce 1 e causa *ptr *
 == [P,l,u,t,o] (4) data *ptr == [P,A,Z,Z,O] ed s == "Pluto" restituisce 1 e *
 causa *ptr == [P,A,Z,P,l,u,t,o,Z,O] (5) data *ptr == [p,a,z,z,o] ed s == *
 "Pluto" restituisce 1 e causa *ptr == [p,a,z,z,o,P,l,u,t,o] (6) data *ptr == *
 [p,a,z,z,o] ed s == NULL restituisce 1 e non modifica ptr
 */
int insert(CharList *ptr, char const *s) {
  if (ptr == NULL) {
    return 0;
  }

  if (s == NULL) {
    return 1;
  }

  while (*ptr != NULL && (*ptr)->data != 'Z') {
    ptr = &((*ptr)->next);
  }
  if (*ptr != NULL) {
    ptr = &((*ptr)->next);
  }

  int i = 0;
  while (s[i] != '\0') {
    CharList newN = (CharList)malloc(sizeof(CharNode));

    newN->data = s[i];
    newN->next = *ptr;

    *ptr = newN;
    ptr = &((*ptr)->next);

    i++;
  }

  return 1;
}
