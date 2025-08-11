// typedef struct listNode ListNode, *ListNodePtr;
//
// struct listNode {
//  int data;
//  ListNodePtr next;
// };

#include "list_rec.h"

// Ritorna una lista contenente tutti i numeri interi compresi tra @m ed @n,
// estremi inclusi.
ListNodePtr fromTo_rec(int m, int n) {
  if (m > n)
    return NULL;

  ListNodePtr p = malloc(sizeof(ListNode));
  p->data = m;
  p->next = fromTo_rec(m + 1, n);

  return p;
}

// VERSIONE ricorsiva di coda
ListNodePtr fromTo(int m, int n) { return fromTo_tailrec(m, n, NULL); }
ListNodePtr fromTo_tailrec(int m, int n, ListNodePtr acc) {
  if (m > n)
    return acc;

  ListNodePtr p = malloc(sizeof(ListNode));
  p->data = n;
  p->next = acc;

  return fromTo_tailrec(m, n - 1, p);
}

// Ritorna true se tutti gli elementi nella lista @ls1 compaiono nello stesso
// ordine anche nella lista @ls2.
_Bool included_rec(ListNodePtr ls1, ListNodePtr ls2) {
  return (ls1 == NULL) ||
         (ls2 != NULL &&
          ((ls1->data == ls2->data && included_rec(ls1->next, ls2->next)) ||
           included_rec(ls1, ls2->next)));
}
// Versione più leggibile
_Bool included_rec(ListNodePtr ls1, ListNodePtr ls2) {
  if (ls1 == NULL)
    return true;
  if (ls2 == NULL)
    return false;
  if (ls1->data == ls2->data) return included_rec(ls1->next,ls2->next))
	else return included_rec(ls1, ls2->next);
}

// Ritorna una nuova lista con gli elementi di @ls in ordine inverso (non
// modifica la lista @ls).
ListNodePtr
reverse_rec(ListNodePtr ls) { // complessità temporale THETA(length(ls)^2)
  if (ls == NULL)
    return NULL;

  ListNodePtr result = reverse_rec(ls->next);
  ListNodePtr new = malloc(sizeof(ListNode));
  new->data = ls->data;
  new->next = NULL;
  << INSERISCI new IN CODA A
              result >> // complessità temporale THETA(lenght(ls))
      return result;
}

// VERSIONE ricorsiva di coda;
ListNodePtr reverse(ListNodePtr ls) { return reverse_tailrec(ls, NULL); }
// Ritorna una nuova lista con gli elementi di @ls in ordine inverso (non
// modifica la lista @ls) seguiti dagli elementi di acc
ListNodePtr reverse_tailrec(ListNodePtr ls, ListNodePtr acc) {
  if (ls == NULL)
    return acc;

  ListNodePtr new = malloc(sizeof(ListNode));
  new->data = ls->data;
  new->next = acc;
  return reverse_tailrec(ls->next, new);
}

// Ritorna la lista i cui elementi sono le somme a coppie degli elementi
// corrispondenti di due liste @ls1 e @ls2 di uguale lunghezza (non modifica le
// liste @ls1 e @ls2).
ListNodePtr zipSum_rec(ListNodePtr ls1, ListNodePtr ls2) {
  if (ls1 == NULL)
    return NULL;

  ListNodePtr p = malloc(sizeof(ListNode));
  p->data = ls1->data + ls2->data;
  p->next = zipSum_rec(ls1->next, ls2->next);

  return p;
}

// VERSIONE ricorsiva di coda
ListNodePtr zipSum(ListNodePtr ls1, ListNodePtr ls2) {
  ListNodePtr result = NULL;
  zipSum_tailrec(ls1, ls2, &result);
  return result;
}
ListNodePtr zipSum_tailrec(ListNodePtr ls1, ListNodePtr ls2, ListNodePtr *p_r) {
  if (ls1 == NULL) {
    return;
  }

  ListNodePtr p = malloc(sizeof(ListNode));
  p->data = ls1->data + ls2->data;
  p->next = *p_r;
  *p_r = p;
  zipSum_tail_rec(ls1->next, ls2->next, &(p->next));
}

// Conta il numero di occorrenze di @x nella lista @ls.
int occurrences_rec(ListNodePtr ls, int x) {
  if (ls == NULL)
    return 0;
  else if (ls->data == x)
    return 1 + occurrences_rec(ls->next, x);
  else
    return occurrences_rec(ls->next, x);
}

// VERSIONE ricorsiva di coda
int occurrences(ListNodePtr ls, int x) { return occurrences_tailrec(ls, x, 0); }
int occurrences_tailrec(ListNodePtr ls, int x, int acc) {
  if (ls == NULL)
    return acc;
  else if (ls->data == x)
    return occurrences_tailrec(ls->next, x, 1 + acc);
  else
    return occurrences_tailrec(ls->next, x, acc);
}

// Toglie tutte le occorrenze di @x dalla lista *@p_ls (modifica *@p_ls) --
// assume @p_ls != NULL NOTA: E`ricorsiva di coda
void remove_all_rec(ListNodePtr *p_ls, int x) {
  if (*p_ls == NULL)
    return;

  if ((*p_ls)->data != x) {
    remove_all_rec(&((*p_ls)->next), x);
  } else {
    ListNodePtr tmp = *p_ls;
    *p_ls = (*p_ls)->next;
    free(tmp);
    remove_all_rec(&((*pls)->next), x);
  }
}

// VERSIONE non ricorsiva di coda
void remove_all_rec(ListNodePtr *p_ls, int x) {
  if (*p_ls == NULL)
    return;

  remove_all_rec(&((*p_ls)->next), x);

  if ((*p_ls)->data == x) {
    ListNodePtr tmp = *p_ls;
    *p_ls = (*p_ls)->next;
    free(tmp);
  }
}

// Duplica tutti i nodi della lista @ls che contengono un numero pari (modifica
// @ls).
void duplicate_even_rec(ListNodePtr ls) {
  if (*p_ls == NULL)
    return NULL;

  if (((*p_ls)->data % 2) != 0) {
    duplicate_even_rec(&((*pls)->next));
  } else {
    ListNodePtr p = malloc(sizeof(ListNode));
    p->data = (*p_ls)->data;
    p->next = (*p_ls)->next;
    (*p_ls)->next = p;
    duplicate_even_rec(&(p->next), x);
  }
}
