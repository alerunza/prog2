#include <stdio.h>
#include <stdlib.h>

typedef struct node IntNode, *IntList;
struct node {
  int data;
  IntList next;
};

IntList create_from_array(int *a, int n) {
  IntList h = NULL, t = NULL;
  int i = 0;
  while (i < n) {
    IntList x = (IntList)malloc(sizeof(IntNode));
    x->data = a[i];
    x->next = NULL;
    if (h == NULL) {
      h = x;
      t = x;
    } else {
      t->next = x;
      t = x;
    }
    i++;
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

int length(IntList l) {
  int n = 0;
  while (l) {
    n++;
    l = l->next;
  }
  return n;
}

void push_front(IntList *h, IntList *t, int x) {
  IntList n = (IntList)malloc(sizeof(IntNode));
  n->data = x;
  n->next = *h;
  *h = n;
  if (*t == NULL)
    *t = n;
}

void push_back(IntList *h, IntList *t, int x) {
  IntList n = (IntList)malloc(sizeof(IntNode));
  n->data = x;
  n->next = NULL;
  if (*h == NULL) {
    *h = n;
    *t = n;
  } else {
    (*t)->next = n;
    *t = n;
  }
}

void insert_after(IntList *t, IntList pos, int x) {
  if (pos == NULL)
    return;
  IntList n = (IntList)malloc(sizeof(IntNode));
  n->data = x;
  n->next = pos->next;
  pos->next = n;
  if (pos == *t)
    *t = n;
}

void insert_at(IntList *h, IntList *t, int k, int x) {
  if (k <= 1 || *h == NULL) {
    push_front(h, t, x);
    return;
  }
  IntList p = *h;
  int i = 1;
  while (p->next && i < k - 1) {
    p = p->next;
    i++;
  }
  IntList n = (IntList)malloc(sizeof(IntNode));
  n->data = x;
  n->next = p->next;
  p->next = n;
  if (p == *t)
    *t = n;
}

void sorted_insert(IntList *h, IntList *t, int x) {
  IntList n = (IntList)malloc(sizeof(IntNode));
  n->data = x;
  n->next = NULL;
  IntList *pp = h;
  while (*pp && (*pp)->data < x)
    pp = &(*pp)->next;
  n->next = *pp;
  *pp = n;
  if (n->next == NULL)
    *t = n;
  if (*t == NULL)
    *t = n;
}

void sorted_insert_unique(IntList *h, IntList *t, int x) {
  IntList *pp = h;
  while (*pp && (*pp)->data < x)
    pp = &(*pp)->next;
  if (*pp && (*pp)->data == x)
    return;
  IntList n = (IntList)malloc(sizeof(IntNode));
  n->data = x;
  n->next = *pp;
  *pp = n;
  if (n->next == NULL)
    *t = n;
  if (*t == NULL)
    *t = n;
}

int pop_front(IntList *h, IntList *t, int *out) {
  if (*h == NULL)
    return 0;
  IntList x = *h;
  if (out)
    *out = x->data;
  *h = x->next;
  if (*h == NULL)
    *t = NULL;
  free(x);
  return 1;
}

int pop_back(IntList *h, IntList *t, int *out) {
  if (*h == NULL)
    return 0;
  if ((*h)->next == NULL) {
    if (out)
      *out = (*h)->data;
    free(*h);
    *h = NULL;
    *t = NULL;
    return 1;
  }
  IntList p = *h;
  while (p->next && p->next->next)
    p = p->next;
  if (out)
    *out = p->next->data;
  free(p->next);
  p->next = NULL;
  *t = p;
  return 1;
}

void remove_at(IntList *h, IntList *t, int k) {
  if (*h == NULL || k <= 0)
    return;
  if (k == 1) {
    int tmp;
    pop_front(h, t, &tmp);
    return;
  }
  IntList p = *h;
  int i = 1;
  while (p && i < k - 1) {
    p = p->next;
    i++;
  }
  if (p && p->next) {
    IntList x = p->next;
    p->next = x->next;
    if (x == *t)
      *t = p;
    free(x);
  }
}

void remove_value_first(IntList *h, IntList *t, int x) {
  if (*h == NULL)
    return;
  if ((*h)->data == x) {
    int tmp;
    pop_front(h, t, &tmp);
    return;
  }
  IntList p = *h;
  while (p->next && p->next->data != x)
    p = p->next;
  if (p->next) {
    IntList xnode = p->next;
    p->next = xnode->next;
    if (xnode == *t)
      *t = p;
    free(xnode);
  }
}

void remove_value_all(IntList *h, IntList *t, int x) {
  while (*h && (*h)->data == x) {
    int tmp;
    pop_front(h, t, &tmp);
  }
  IntList p = *h;
  while (p && p->next) {
    if (p->next->data == x) {
      IntList q = p->next;
      p->next = q->next;
      if (q == *t)
        *t = p;
      free(q);
    } else {
      p = p->next;
    }
  }
}

void reverse_iter(IntList *h) {
  IntList p = NULL, c = *h, nx = NULL;
  while (c) {
    nx = c->next;
    c->next = p;
    p = c;
    c = nx;
  }
  *h = p;
}

IntList reverse_rec(IntList h) {
  if (h == NULL || h->next == NULL)
    return h;
  IntList nh = reverse_rec(h->next);
  h->next->next = h;
  h->next = NULL;
  return nh;
}

void split_even_odd_positions(IntList *src, IntList *evenPos, IntList *oddPos) {
  *evenPos = NULL;
  *oddPos = NULL;
  if (src == NULL || *src == NULL)
    return;
  IntList he = NULL, te = NULL, ho = NULL, to = NULL, c = *src;
  int pos = 1;
  while (c) {
    IntList nx = c->next;
    c->next = NULL;
    if (pos % 2 == 0) {
      if (he == NULL) {
        he = c;
        te = c;
      } else {
        te->next = c;
        te = c;
      }
    } else {
      if (ho == NULL) {
        ho = c;
        to = c;
      } else {
        to->next = c;
        to = c;
      }
    }
    c = nx;
    pos++;
  }
  *evenPos = he;
  *oddPos = ho;
  *src = NULL;
}

void partition_pivot(IntList *src, IntList *less, IntList *ge, int x) {
  *less = NULL;
  *ge = NULL;
  if (src == NULL || *src == NULL)
    return;
  IntList hl = NULL, tl = NULL, hg = NULL, tg = NULL, c = *src;
  while (c) {
    IntList nx = c->next;
    c->next = NULL;
    if (c->data < x) {
      if (hl == NULL) {
        hl = c;
        tl = c;
      } else {
        tl->next = c;
        tl = c;
      }
    } else {
      if (hg == NULL) {
        hg = c;
        tg = c;
      } else {
        tg->next = c;
        tg = c;
      }
    }
    c = nx;
  }
  *less = hl;
  *ge = hg;
  *src = NULL;
}

void split_half(IntList src, IntList *a, IntList *b) {
  if (src == NULL) {
    *a = NULL;
    *b = NULL;
    return;
  }
  IntList slow = src, fast = src->next;
  while (fast && fast->next) {
    slow = slow->next;
    fast = fast->next->next;
  }
  *a = src;
  *b = slow->next;
  if (slow)
    slow->next = NULL;
}

IntList merge_sorted_lists(IntList a, IntList b) {
  IntNode d;
  IntList t = &d;
  d.next = NULL;
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
  if (a)
    t->next = a;
  else
    t->next = b;
  return d.next;
}

void merge_sort(IntList *h) {
  if (h == NULL || *h == NULL || (*h)->next == NULL)
    return;
  IntList a = NULL, b = NULL;
  split_half(*h, &a, &b);
  merge_sort(&a);
  merge_sort(&b);
  *h = merge_sorted_lists(a, b);
}

void remove_duplicates_sorted(IntList h) {
  if (h == NULL)
    return;
  IntList p = h;
  while (p && p->next) {
    if (p->data == p->next->data) {
      IntList q = p->next;
      p->next = q->next;
      free(q);
    } else {
      p = p->next;
    }
  }
}

void remove_duplicates_unsorted(IntList *h) {
  if (h == NULL || *h == NULL)
    return;
  IntList a = *h;
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

void rotate_right_k(IntList *h, int k) {
  if (h == NULL || *h == NULL || k <= 0)
    return;
  int n = length(*h);
  if (n <= 1)
    return;
  k %= n;
  if (k == 0)
    return;
  IntList tail = *h;
  while (tail->next)
    tail = tail->next;
  tail->next = *h;
  int steps = n - k;
  IntList newtail = *h;
  int i = 1;
  while (i < steps) {
    newtail = newtail->next;
    i++;
  }
  *h = newtail->next;
  newtail->next = NULL;
}

IntList kth_from_end(IntList h, int k) {
  if (h == NULL || k <= 0)
    return NULL;
  IntList a = h, b = h;
  int i = 0;
  while (i < k && b) {
    b = b->next;
    i++;
  }
  if (i < k)
    return NULL;
  while (b) {
    a = a->next;
    b = b->next;
  }
  return a;
}

IntList middle_node(IntList h) {
  if (h == NULL)
    return NULL;
  IntList slow = h, fast = h;
  while (fast && fast->next) {
    slow = slow->next;
    fast = fast->next->next;
  }
  return slow;
}

int has_cycle(IntList h) {
  IntList slow = h, fast = h;
  while (fast && fast->next) {
    slow = slow->next;
    fast = fast->next->next;
    if (slow == fast)
      return 1;
  }
  return 0;
}

void concat_lists(IntList *h1, IntList *t1, IntList h2, IntList t2) {
  if (h2 == NULL)
    return;
  if (*h1 == NULL) {
    *h1 = h2;
    *t1 = t2;
    return;
  }
  (*t1)->next = h2;
  *t1 = t2;
}

IntList interleave_lists(IntList a, IntList b) {
  IntNode d;
  IntList t = &d;
  d.next = NULL;
  while (a || b) {
    if (a) {
      t->next = a;
      a = a->next;
      t = t->next;
      t->next = NULL;
    }
    if (b) {
      t->next = b;
      b = b->next;
      t = t->next;
      t->next = NULL;
    }
  }
  return d.next;
}

IntList copy_list(IntList h) {
  IntList nh = NULL, nt = NULL;
  while (h) {
    IntList n = (IntList)malloc(sizeof(IntNode));
    n->data = h->data;
    n->next = NULL;
    if (nh == NULL) {
      nh = n;
      nt = n;
    } else {
      nt->next = n;
      nt = n;
    }
    h = h->next;
  }
  return nh;
}

int compare_lists(IntList a, IntList b) {
  while (a && b) {
    if (a->data != b->data)
      return 0;
    a = a->next;
    b = b->next;
  }
  if (a || b)
    return 0;
  return 1;
}

int is_palindrome(IntList h) {
  if (h == NULL || h->next == NULL)
    return 1;
  IntList slow = h, fast = h;
  while (fast && fast->next) {
    slow = slow->next;
    fast = fast->next->next;
  }
  IntList second = reverse_rec(slow);
  IntList p1 = h, p2 = second;
  int ok = 1;
  while (p2) {
    if (p1->data != p2->data)
      ok = 0;
    p1 = p1->next;
    p2 = p2->next;
  }
  reverse_iter(&second);
  return ok;
}

int main() {
  IntList h = NULL, t = NULL;
  push_back(&h, &t, 10);
  push_back(&h, &t, 30);
  push_front(&h, &t, 5);
  insert_at(&h, &t, 2, 7);
  insert_after(&t, h->next, 20);
  printList(h);

  sorted_insert(&h, &t, 15);
  sorted_insert_unique(&h, &t, 20);
  sorted_insert_unique(&h, &t, 20);
  printList(h);

  remove_value_first(&h, &t, 7);
  remove_value_all(&h, &t, 30);
  remove_at(&h, &t, 3);
  printList(h);

  reverse_iter(&h);
  printList(h);
  h = reverse_rec(h);
  printList(h);

  IntList even = NULL, odd = NULL, src = h;
  split_even_odd_positions(&src, &even, &odd);
  printList(even);
  printList(odd);
  concat_lists(&h, &t, even, even ? even : NULL);
  concat_lists(&h, &t, odd, odd ? odd : NULL);
  printList(h);

  rotate_right_k(&h, 2);
  printList(h);
  IntList mid = middle_node(h);
  if (mid)
    printf("mid=%d\n", mid->data);
  IntList k3 = kth_from_end(h, 3);
  if (k3)
    printf("k3=%d\n", k3->data);

  int b1[] = {1, 3, 5, 7}, b2[] = {2, 4, 6, 8, 9};
  IntList A = create_from_array(b1, 4), B = create_from_array(b2, 5);
  IntList M = merge_sorted_lists(A, B);
  printList(M);
  merge_sort(&M);
  printList(M);
  remove_duplicates_sorted(M);
  printList(M);

  IntList C = copy_list(M);
  printf("%d\n", compare_lists(M, C));
  printf("%d\n", has_cycle(M));
  int pal[] = {1, 2, 3, 2, 1};
  IntList P = create_from_array(pal, 5);
  printf("%d\n", is_palindrome(P));

  freeList(h);
  freeList(M);
  freeList(C);
  freeList(P);
  return 0;
}
