#include <stdio.h>
#include <stdlib.h>

// typedef struct listNode ListNode, *ListNodePtr;
//
// struct listNode {
//   int data;
//   ListNodePtr next;
// };

#include "list_iter.h"

// Ritorna una lista contenente tutti i numeri interi compresi tra @m ed @n,
// estremi inclusi.
ListNodePtr fromTo_iter(int m, int n) {

  ListNodePtr p = NULL;

  // I.C.: p e' la lista di tutti i numeri da i+1 a n, estremi inclusi
  for (int i = n; i >= m; i--) {
    ListNodePtr new = (ListNodePtr)malloc(sizeof(ListNode));
    new->data = i;
    new->next = p;
    p = new;
  }

  return p;
}

// Ritorna true se tutti gli elementi nella lista @ls1 compaiono nello stesso
// ordine anche nella lista @ls2.
_Bool included_iter(ListNodePtr ls1, ListNodePtr ls2) {

  // I.C.: Gli elementi di ls1' - ls1  compaiono nello stesso ordine anche nella
  // lista ls2'-ls1
  while ((ls1 != NULL) && (ls2 != NULL)) {
    if (ls1->data == ls2->data) {
      ls1 = ls1->next;
    }
    ls2 = ls2->next;
  }
  return (ls1 == NULL);
}

// Ritorna una nuova lista con gli elementi di @ls in ordine inverso (non
// modifica la lista @ls).
ListNodePtr reverse_iter(ListNodePtr ls) {
  ListNodePtr p = NULL;

  // I.C.: p e' una lista che contiene gli elementi di ls'-ls in ordine inverso
  while (ls != NULL) {
    ListNodePtr new = (ListNodePtr)malloc(sizeof(ListNode));
    new->data = ls->data;
    new->next = p;
    p = new;
    ls = ls->next;
  }

  return p;
}

// Ritorna la lista i cui elementi sono le somme a coppie degli elementi
// corrispondenti di due liste @ls1 e @ls2 di uguale lunghezza (non modifica la
// liste @ls1 e @ls2).
ListNodePtr zipSum_iter(ListNodePtr ls1, ListNodePtr ls2) {
  ListNodePtr head = NULL, tail = NULL;
  while ((ls1 != NULL) && (ls2 != NULL)) {
    ListNodePtr sum = (ListNodePtr)malloc(sizeof(ListNode));
    sum->data = ls1->data + ls2->data;
    sum->next = NULL;

    if (head == NULL) {
      head = sum;
      tail = sum;
    } else {
      tail->next = sum;
      tail = sum;
    }
    ls1 = ls1->next;
    ls2 = ls2->next;
  }

  return head;
}

// Conta il numero di occorrenze di @x nella lista @ls.
int occurrences_iter(ListNodePtr ls, int x) {
  int count = 0;
  while (ls != NULL) {
    if (ls->data == x) {
      count++;
    }
    ls = ls->next;
  }

  return count;
}

// Toglie tutte le occorrenze di @x dalla lista *@p_ls  (modifica *@p_ls).
void remove_all_iter(ListNodePtr *p_ls, int x) {
  ListNodePtr *curr = p_ls;

  while (*curr != NULL) {
    if ((*curr)->data == x) {
      ListNodePtr temp = *curr;
      *curr = (*curr)->next;
      free(temp);
    } else {
      curr = &((*curr)->next);
    }
  }
}

// Duplica tutti i nodi della lista @ls che contengono un numero pari (modifica
// @ls).
void duplicate_even_iter(ListNodePtr ls) {
  ListNodePtr curr = ls;
  while (curr != NULL) {
    if ((curr->data % 2) == 0) {
      ListNodePtr temp = (ListNodePtr)malloc(sizeof(ListNode));
      temp->data = curr->data;
      temp->next = curr->next;
      curr->next = temp;
      curr = temp->next;
    } else {
      curr = curr->next;
    }
  }
}

/* utility functions */

void print_list(const char *label, ListNodePtr ls) {
  printf("%s", label);
  printf("[");
  for (ListNodePtr p = ls; p != NULL; p = p->next) {
    printf("%d", p->data);
    if (p->next)
      printf(" -> ");
  }
  printf("]\n");
}

void free_list(ListNodePtr ls) {
  while (ls) {
    ListNodePtr tmp = ls->next;
    free(ls);
    ls = tmp;
  }
}

int main(void) {
  printf("=== Test Programmazione 2: liste iterate ===\n\n");

  /* ---- fromTo_iter ---- */
  ListNodePtr a = fromTo_iter(3, 7);     // 3..7
  ListNodePtr b = fromTo_iter(1, 5);     // 1..5
  ListNodePtr vuota = fromTo_iter(5, 3); // m > n -> NULL

  print_list("fromTo_iter(3,7): ", a);
  print_list("fromTo_iter(1,5): ", b);
  print_list("fromTo_iter(5,3): ", vuota);

  /* ---- included_iter (sottosequenza) ---- */
  // ls1 = [3,5,7] è sottosequenza di [1..7]
  ListNodePtr ls1 = fromTo_iter(3, 7);
  // per creare [3,5,7] partiamo da ls1 e togliamo 4 e 6
  // (oppure facciamo una lista a mano)
  // Qui faccio una lista a mano per chiarezza:
  ListNodePtr sub = NULL;
  // costruisco 7 -> 5 -> 3
  {
    ListNodePtr n;
    n = malloc(sizeof(ListNode));
    n->data = 7;
    n->next = sub;
    sub = n;
    n = malloc(sizeof(ListNode));
    n->data = 5;
    n->next = sub;
    sub = n;
    n = malloc(sizeof(ListNode));
    n->data = 3;
    n->next = sub;
    sub = n;
  }

  print_list("\nls2: ", ls1);
  print_list("ls1 (sottosequenza attesa): ", sub);
  printf("included_iter(ls1, ls2) = %s\n",
         included_iter(sub, ls1) ? "true" : "false");

  // caso negativo: [2,4,6,8] non è sottosequenza di [3..7]
  ListNodePtr neg_sub = NULL;
  {
    ListNodePtr n;
    n = malloc(sizeof(ListNode));
    n->data = 8;
    n->next = neg_sub;
    neg_sub = n;
    n = malloc(sizeof(ListNode));
    n->data = 6;
    n->next = neg_sub;
    neg_sub = n;
    n = malloc(sizeof(ListNode));
    n->data = 4;
    n->next = neg_sub;
    neg_sub = n;
    n = malloc(sizeof(ListNode));
    n->data = 2;
    n->next = neg_sub;
    neg_sub = n;
  }
  ListNodePtr base = fromTo_iter(3, 7);
  print_list("\nls2: ", base);
  print_list("ls1 (non sottosequenza): ", neg_sub);
  printf("included_iter(ls1, ls2) = %s\n",
         included_iter(neg_sub, base) ? "true" : "false");

  /* ---- reverse_iter ---- */
  ListNodePtr r = reverse_iter(a); // a resta intatta, r è nuova lista
  print_list("\nreverse_iter of fromTo_iter(3,7): ", r);
  print_list("originale rimasto uguale:         ", a);

  /* ---- zipSum_iter ---- */
  // somma elemento a elemento di [1..5] e [6..10] => [7,9,11,13,15]
  ListNodePtr c = fromTo_iter(6, 10);
  ListNodePtr z = zipSum_iter(b, c);
  print_list("\nls1: ", b);
  print_list("ls2: ", c);
  print_list("zipSum_iter(ls1, ls2): ", z);

  /* ---- occurrences_iter ---- */
  // creo una lista: 1 -> 2 -> 3 -> 2 -> 4 -> 2
  ListNodePtr occ = NULL;
  {
    int vals[] = {2, 4, 2, 3, 2, 1};
    for (int i = 0; i < 6; ++i) {
      ListNodePtr n = malloc(sizeof(ListNode));
      n->data = vals[i];
      n->next = occ;
      occ = n;
    }
  }
  print_list("\nlista per occurrences/remove/duplicate: ", occ);
  printf("occurrences_iter(x=2) = %d\n", occurrences_iter(occ, 2));
  printf("occurrences_iter(x=5) = %d\n", occurrences_iter(occ, 5));

  /* ---- remove_all_iter ---- */
  // rimuovo tutte le occorrenze di 2
  remove_all_iter(&occ, 2);
  print_list("dopo remove_all_iter(x=2):           ", occ);

  /* ---- duplicate_even_iter ---- */
  // su b = [1..5], duplica i pari => 1,2,2,3,4,4,5
  print_list("\nprima di duplicate_even_iter: ", b);
  duplicate_even_iter(b);
  print_list("dopo  duplicate_even_iter:   ", b);

  /* ---- test extra: reverse di lista singolo elemento e NULL ---- */
  ListNodePtr one = fromTo_iter(42, 42);
  ListNodePtr one_r = reverse_iter(one);
  print_list("\nreverse di [42]: ", one_r);
  ListNodePtr nil_r = reverse_iter(NULL);
  print_list("reverse di []:    ", nil_r);

  /* --- cleanup: libera tutte le liste allocate --- */
  free_list(a);
  free_list(r);
  free_list(b);
  free_list(c);
  free_list(z);
  free_list(ls1);
  free_list(sub);
  free_list(neg_sub);
  free_list(base);
  free_list(occ);
  free_list(one);
  free_list(one_r);
  free_list(nil_r);
  free_list(vuota); // vuota e' NULL, ok

  printf("\n=== Fine test ===\n");
  return 0;
}
