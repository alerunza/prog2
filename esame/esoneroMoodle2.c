#include <ctype.h>
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

void printList(CharList list) {
  while (list != NULL) {
    printf("%c ", list->data);
    list = list->next;
  }
}

void freeList(CharList list) {
  while (list != NULL) {
    CharList temp = list;
    list = list->next;
    free(temp);
  }
}

/**
 * Data una stringa s, restituisce una lista di caratteri che contiene tutti
 * e soli i caratteri alfabetici maiuscoli (A - Z) trasformati in minuscoli
 * (a - z) della stringa s nell'ordine in cui occorrono in s.
 *
 * Non considera l'eventualità che la malloc fallisca.
 * Se s == NULL, restituisce NULL.
 *
 * ESEMPI:
 * (1) data s == NULL  restituisce NULL
 * (2) data s == "" restituisce NULL
 * (3) data s == "A" restituisce [a]
 * (4) data s == "AZbCuu12R" restituisce [a,z,c,r]
 */
CharList stringToList(char *s) {

  if (s == NULL || strlen(s) == 0) {
    return NULL;
  }

  CharList head = NULL, tail = NULL;

  int i = 0;
  while (s[i] != '\0') {
    if (isalpha(s[i]) && isupper(s[i])) {
      CharList newS = (CharList)malloc(sizeof(CharNode));
      if (newS == NULL) {
        return NULL;
      }

      newS->data = tolower(s[i]);
      newS->next = NULL;

      if (head == NULL) {
        head = newS;
        tail = newS;
      } else {
        tail->next = newS;
        tail = newS;
      }
    }
    i++;
  }

  return head;
}

/**
 * Invoca la funzione stringToList sulla stringa "Coordination@DisCoTec-2025",
 * stampa la lista restituita (in un formato a scelta, ma tutto su una sola
 * riga), e poi libera la memoria occupata dalla lista.
 */
int main() {

  char *str = "Coordination@DisCoTec-2025";

  CharList newS = stringToList(str);

  printList(newS);
  freeList(newS);

  return 0;
}
