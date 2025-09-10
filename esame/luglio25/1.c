#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* INSERIRE QUI EVENTUALI FUNZIONI AUSILIARIE (CON UN COMMENTO SIGNIFICATIVO IN
 * TESTA) */
typedef struct node CharNode, *CharList;
struct node {
  char data;
  CharList next;
};

void charListInsert(CharList *ptr, char c) {
  CharList n = (CharList)malloc(sizeof(CharNode));
  n->data = c;
  n->next = *ptr;
  *ptr = n;
}
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
 * (1) data *ptr == [A,x,8] ed s == "k$2e" restituisce 1 e causa *ptr ==
 * [A,x,8,k,$,2,e] (2) data ptr == NULL ed s == "Pluto" restituisce 0 e non
 * modifica ptr (3) data *ptr == [] ed s == "Pluto" restituisce 1 e causa *ptr
 * == [P,l,u,t,o] (4) data *ptr == [P,A,Z,Z,O] ed s == "Pluto" restituisce 1 e
 * causa *ptr == [P,A,Z,P,l,u,t,o,Z,O] (5) data *ptr == [p,a,z,z,o] ed s ==
 * "Pluto" restituisce 1 e causa *ptr == [p,a,z,z,o,P,l,u,t,o] (6) data *ptr ==
 * [p,a,z,z,o] ed s == NULL restituisce 1 e non modifica ptr
 */

int insert(CharList *ptr, char const *s) {

  if (ptr == NULL)
    return 0;
  if (s == NULL || s[0] == '\0')
    return 1;

  if (*ptr == NULL) {
    charListInsert(ptr, s[0]);
    CharList t = *ptr;
    for (int i = 1; s[i] != '\0'; i++) {
      CharList n = (CharList)malloc(sizeof(CharNode));
      n->data = s[i];
      n->next = NULL;
      t->next = n;
      t = n;
    }
    return 1;
  }

  CharList tmp = *ptr;
  while (tmp->next != NULL && tmp->data != 'Z')
    tmp = tmp->next;

  if (tmp->data == 'Z') {
    CharList after = tmp->next, t = tmp;
    for (int i = 0; s[i] != '\0'; i++) {
      CharList n = (CharList)malloc(sizeof(CharNode));
      n->data = s[i];
      n->next = NULL;
      t->next = n;
      t = n;
    }
    t->next = after;
  } else {
    CharList t = tmp;
    for (int i = 0; s[i] != '\0'; i++) {
      CharList n = (CharList)malloc(sizeof(CharNode));
      n->data = s[i];
      n->next = NULL;
      t->next = n;
      t = n;
    }
  }
  return 1;
}

/**
* Invoca la funzione insert sulla lista [Z,E] e sulla stringa "ELANT"
, stampa il
* valore int restituito dalla funzione, poi libera la memoria occupata dalla
lista.
*/
int main() {
  CharList list = (CharList)malloc(sizeof(CharNode));
  list->data = 'Z';
  list->next = (CharList)malloc(sizeof(CharNode));
  list->next->data = 'E';
  list->next->next = NULL;

  int r = insert(&list, "ELANT");
  printf("RISULTATO: %d\n", r);

  CharList t;
  while (list != NULL) {
    t = list->next;
    free(list);
    list = t;
  }
  return 0;
}
