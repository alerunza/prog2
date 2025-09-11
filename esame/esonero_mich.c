#include <stdio.h>
#include <stdlib.h>

typedef struct node IntNode, *IntList;
struct node {
  int data;
  IntList next;
};

void separaPariDispari(IntList *lst, IntList *pari, IntList *dispari,
                       IntList *restanti) {
  *pari = NULL, *dispari = NULL, *restanti = NULL;
  IntList lasteven = NULL, lastdisp = NULL, lastrest = NULL;
  if (lst == NULL || *lst == NULL) {
    return;
  }
  IntList curr = *lst, next = NULL;
  while (curr != NULL) {
    next = curr->next;
    curr->next = NULL;

    if (curr->data > 0 && curr->data % 2 == 0) {
      if (*pari == NULL) {
        *pari = curr;
      } else {
        lasteven->next = curr;
      }
      lasteven = curr;
    } else if (curr->data > 0 && curr->data % 2 != 0) {
      if (*dispari == NULL) {
        *dispari = curr;
      } else {
        lastdisp->next = curr;
      }
      lastdisp = curr;
    } else {
      if (*restanti == NULL) {
        *restanti = curr;
      } else {
        lastrest->next = curr;
      }
      lastrest = curr;
    }
    curr = next;
  }
  *lst = NULL;
}

void print_lista(IntList l) {
  for (; l != NULL; l = l->next) {
    printf("%d ", l->data);
  }
  printf("\n");
}

void separaPosizioni(IntList *lst, IntList *pos2, IntList *pos3) {
  *pos2 = NULL, *pos3 = NULL;
  IntList lastpari = NULL, lastdip = NULL;
  if (lst == NULL || *lst == NULL) {
    return;
  }
  int pos = 1;
  IntList curr = *lst, next = NULL;
  while (curr != NULL) {
    next = curr->next;
    curr->next = NULL;
    if (pos % 2 == 0) {
      if (*pos2 == NULL) {
        *pos2 = curr;
      } else {
        lastpari->next = curr;
      }
      lastpari = curr;
    } else {
      if (*pos3 == NULL) {
        *pos3 = curr;
      } else {
        lastdip->next = curr;
      }
      lastdip = curr;
    }
    curr = next;
    pos++;
  }
  *lst = NULL;
}

/* IntList mergeSorted(IntList lst1, IntList lst2){
    if(*lst1 == NULL){
        *lst1 = *lst2;
    }
    else{
        IntLit curr = *lst1;
        while(curr != NULL){
            curr = curr -> next;
        }
        curr -> next = *lst2;
    }
    *lst2 = NULL;
} */

void eliminaDuplicati(IntList *lst) {
  if (lst == NULL || *lst == NULL) {
    return;
  }
  IntList curr = *lst;
  while (curr != NULL) {
    IntList prev = curr;
    IntList check = curr->next;
    while (check != NULL) {
      if (curr->data == check->next) {
        prev->next = check->next;
        free(check);
        check = prev->next;
      } else {
        prev = check;
        check = check->next;
      }
    }
    curr = curr->next;
  }
}

void invertiLista(IntList *lst) {
  if (lst == NULL || *lst == NULL) {
    return;
  }
  IntList curr = *lst, prev = NULL, next = NULL;
  while (curr != NULL) {
    next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
  }
  *lst = prev;
}

int main() {

  IntList pari = NULL, dispari = NULL, restanti = NULL;
  IntList head = NULL, tail = NULL;
  for (int i = 1; i < 11; i++) {
    IntList newNode = (IntList)malloc(sizeof(IntNode));
    newNode->data = i;
    newNode->next = NULL;
    if (head == NULL) {
      head = tail = newNode;
    } else {
      tail->next = newNode;
      tail = newNode;
    }
  }
  for (int i = 1; i < 11; i++) {
    IntList newNode = (IntList)malloc(sizeof(IntNode));
    newNode->data = i;
    newNode->next = NULL;
    if (head == NULL) {
      head = tail = newNode;
    } else {
      tail->next = newNode;
      tail = newNode;
    }
  }

  print_lista(head); // ora hai insieme 10..1 e -1..-5
  /*
  separaPariDispari(&head, &pari, &dispari, &restanti);
  print_lista(lista);  print_lista(pari); print_lista(dispari);
  print_lista(restanti);
  */

  /*
  separaPosizioni(&head, &pari, &dispari);
  print_lista(pari);
  print_lista(dispari);
  */

  /*
  printf("\nLista con duplicati: "); print_lista(head);
  eliminaDuplicati(&head);
  printf("Dopo eliminazione: "); print_lista(head);
  */

  invertiLista(&head);
  print_lista(head);
}
