
// typedef struct listNode ListNode, *ListNodePtr;
//
// struct listNode {
//   int data;
//   ListNodePtr next;
// };

#include ``list_iter.h''

// Ritorna una lista contenente tutti i numeri interi compresi tra @m ed @n,
// estremi inclusi.
ListNodePtr fromTo_iter(int m, int n) {

  ListNodePtr p = NULL;

  // I.C.: p e' la lista di tutti i numeri da i+1 a n, estremi inclusi
  for (int i = n; i >= m; i--) {
        ListNodePtr new = malloc(sizeof(ListNode);
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
      ls1 = ls1 - next;
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
        ListNodePtr new = malloc(sizeof(ListNode);
        new->data = ls->data;
        new->next = p;
        p = new;
        ls = ls->next;
  }
}

// Ritorna la lista i cui elementi sono le somme a coppie degli elementi
// corrispondenti di due liste @ls1 e @ls2 di uguale lunghezza (non modifica la
// liste @ls1 e @ls2).
ListNodePtr zipSum_iter(ListNodePtr ls1, ListNodePtr ls2);

// Conta il numero di occorrenze di @x nella lista @ls.
int occurrences_iter(ListNodePtr ls, int x);

// Toglie tutte le occorrenze di @x dalla lista *@p_ls  (modifica *@p_ls).
void remove_all_iter(ListNodePtr *p_ls, int x);

// Duplica tutti i nodi della lista @ls che contengono un numero pari (modifica
// @ls).
void duplicate_even_iter(ListNodePtr ls);
