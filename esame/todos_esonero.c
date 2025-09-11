#include <stdio.h>
#include <stdlib.h>

typedef struct node IntNode, *IntList;
struct node {
  int data;
  IntList next;
};

IntList createList(int *a, int n) {
  IntList h = NULL, t = NULL;
  int i = 0;
  while (i < n) {
    IntList x = (IntList)malloc(sizeof(IntNode));
    x->data = a[i++];
    x->next = NULL;
    if (!h) {
      h = t = x;
    } else {
      t->next = x;
      t = x;
    }
  }
  return h;
}

void printList(IntList l) {
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

void separaTreNonTre(IntList *lstPtr, IntList *posTre, IntList *posNonTre) {
  *posTre = NULL;
  *posNonTre = NULL;
  if (!lstPtr || !*lstPtr)
    return;
  IntList hT = NULL, tT = NULL, hN = NULL, tN = NULL, c = *lstPtr, nx = NULL;
  int pos = 1;
  while (c) {
    nx = c->next;
    c->next = NULL;
    if (pos % 3 == 0) {
      if (!hT) {
        hT = tT = c;
      } else {
        tT->next = c;
        tT = c;
      }
    } else {
      if (!hN) {
        hN = tN = c;
      } else {
        tN->next = c;
        tN = c;
      }
    }
    c = nx;
    pos++;
  }
  *posTre = hT;
  *posNonTre = hN;
  *lstPtr = NULL;
}

void separaPariDispariRestanti(IntList *lst, IntList *pari, IntList *dispari,
                               IntList *restanti) {
  *pari = NULL;
  *dispari = NULL;
  *restanti = NULL;
  if (!lst || !*lst)
    return;
  IntList ep = NULL, op = NULL, rp = NULL, c = *lst, nx = NULL;
  while (c) {
    nx = c->next;
    c->next = NULL;
    if (c->data > 0 && c->data % 2 == 0) {
      if (!*pari) {
        *pari = ep = c;
      } else {
        ep->next = c;
        ep = c;
      }
    } else if (c->data > 0 && c->data % 2 != 0) {
      if (!*dispari) {
        *dispari = op = c;
      } else {
        op->next = c;
        op = c;
      }
    } else {
      if (!*restanti) {
        *restanti = rp = c;
      } else {
        rp->next = c;
        rp = c;
      }
    }
    c = nx;
  }
  *lst = NULL;
}

void separaPosizioniPariDispari(IntList *lst, IntList *posPari,
                                IntList *posDispari) {
  *posPari = NULL;
  *posDispari = NULL;
  if (!lst || !*lst)
    return;
  IntList hp = NULL, tp = NULL, ho = NULL, to = NULL, c = *lst, nx = NULL;
  int pos = 1;
  while (c) {
    nx = c->next;
    c->next = NULL;
    if (pos % 2 == 0) {
      if (!hp) {
        hp = tp = c;
      } else {
        tp->next = c;
        tp = c;
      }
    } else {
      if (!ho) {
        ho = to = c;
      } else {
        to->next = c;
        to = c;
      }
    }
    c = nx;
    pos++;
  }
  *posPari = hp;
  *posDispari = ho;
  *lst = NULL;
}

void invertiLista(IntList *lst) {
  if (!lst || !*lst)
    return;
  IntList p = NULL, c = *lst, nx = NULL;
  while (c) {
    nx = c->next;
    c->next = p;
    p = c;
    c = nx;
  }
  *lst = p;
}

void eliminaDuplicati(IntList *lst) {
  if (!lst || !*lst)
    return;
  IntList a = *lst;
  while (a) {
    IntList prev = a, b = a->next;
    while (b) {
      if (b->data == a->data) {
        prev->next = b->next;
        free(b);
        b = prev->next;
      } else {
        prev = b;
        b = b->next;
      }
    }
    a = a->next;
  }
}

IntList mergeSorted(IntList a, IntList b) {
  IntNode dummy;
  IntList t = &dummy;
  dummy.next = NULL;
  while (a && b) {
    if (a->data <= b->data) {
      t->next = a;
      a = a->next;
    } else {
      t->next = b;
      b = b->next;
    }
    t = t->next;
    t->next = NULL;
  }
  t->next = a ? a : b;
  return dummy.next;
}

void removeAt(IntList *lst, int k) {
  if (!lst || !*lst || k <= 0)
    return;
  if (k == 1) {
    IntList t = *lst;
    *lst = (*lst)->next;
    free(t);
    return;
  }
  IntList p = *lst;
  int i = 1;
  while (p && i < k - 1) {
    p = p->next;
    i++;
  }
  if (p && p->next) {
    IntList t = p->next;
    p->next = t->next;
    free(t);
  }
}

void removeValueAll(IntList *lst, int x) {
  if (!lst || !*lst)
    return;
  while (*lst && (*lst)->data == x) {
    IntList t = *lst;
    *lst = (*lst)->next;
    free(t);
  }
  IntList p = *lst;
  while (p && p->next) {
    if (p->next->data == x) {
      IntList t = p->next;
      p->next = t->next;
      free(t);
    } else
      p = p->next;
  }
}

int main() {
  int a1[] = {10, 20, 30, 40, 50, 60, 70}, n1 = 7;
  IntList L = createList(a1, n1);
  printList(L);

  IntList T = NULL, NT = NULL;
  separaTreNonTre(&L, &T, &NT);
  printList(T);
  printList(NT);
  printList(L);
  freeList(T);
  freeList(NT);

  int a2[] = {-3, 0, 2, 7, 8, -1, 4}, n2 = 7;
  L = createList(a2, n2);
  IntList P = NULL, D = NULL, R = NULL;
  separaPariDispariRestanti(&L, &P, &D, &R);
  printList(P);
  printList(D);
  printList(R);
  printList(L);
  freeList(P);
  freeList(D);
  freeList(R);

  int a3[] = {1, 2, 3, 4, 5, 6, 7, 8}, n3 = 8;
  L = createList(a3, n3);
  IntList PE = NULL, PO = NULL;
  separaPosizioniPariDispari(&L, &PE, &PO);
  printList(PE);
  printList(PO);
  printList(L);
  freeList(PE);
  freeList(PO);

  int a4[] = {5, 3, 5, 2, 3, 2, 5, 1, 1, 4}, n4 = 10;
  L = createList(a4, n4);
  eliminaDuplicati(&L);
  printList(L);
  invertiLista(&L);
  printList(L);
  removeAt(&L, 3);
  printList(L);
  removeValueAll(&L, 5);
  printList(L);
  freeList(L);

  int s1[] = {1, 3, 5, 7, 9}, s2[] = {0, 2, 4, 6, 8, 10}, n5 = 5, n6 = 6;
  IntList A = createList(s1, n5), B = createList(s2, n6);
  IntList M = mergeSorted(A, B);
  printList(M);
  freeList(M);

  return 0;
}
