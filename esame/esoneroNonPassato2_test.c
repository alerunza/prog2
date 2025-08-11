#include <stdio.h>
#include <stdlib.h>
typedef struct node IntNode, *IntList;

struct node {
  int data;
  IntList next;
};

void printList(IntList l) {
  while (l != NULL) {
    printf("%d", l->data);
    if (l->next != NULL)
      printf(" -> ");
    l = l->next;
  }
  printf("\n");
}

IntList createList(int *arr, int n) {
  if (n == 0)
    return NULL;
  IntList head = NULL, tail = NULL;
  for (int i = 0; i < n; i++) {
    IntList newnode = malloc(sizeof(IntNode));
    newnode->data = arr[i];
    newnode->next = NULL;
    if (head == NULL) {
      head = tail = newnode;
    } else {
      tail->next = newnode;
      tail = newnode;
    }
  }
  return head;
}

void freeList(IntList l) {
  while (l != NULL) {
    IntList temp = l;
    l = l->next;
    free(temp);
  }
}

/**@brief Modifica  la lista *lstPtr, separando i nodi in posizione multipla 3
 * dai nodi in posizione non multipla di 3. I nodi in posizione multipla 3
 * verranno inseriti (nello stesso ordine rispetto alla lista originaria)
 * nella lista *posTre, quelli in posizione non multipla di 3 verranno inseriti
 * (nello stesso rispetto alla lista originaria) nella lista *posNonTre.
 * La posizione del primo nodo di una lista è 1.
 */

void separaTreNonTre(IntList *lstPtr, IntList *posTre, IntList *posNonTre) {

  *posTre = NULL, *posNonTre = NULL;

  if (lstPtr == NULL || *lstPtr == NULL) {
    return;
  }

  IntList headTre = NULL, tailTre = NULL;
  IntList headNonTre = NULL, tailNonTre = NULL;

  IntList curr = *lstPtr, next = NULL;
  int pos = 1;

  while (curr != NULL) {
    next = curr->next;
    curr->next = NULL;

    if (pos % 3 == 0) {
      if (headTre == NULL) {
        headTre = curr;
        tailTre = curr;
      } else {
        tailTre->next = curr;
        tailTre = curr;
      }
    } else {
      if (headNonTre == NULL) {
        headNonTre = curr;
        tailNonTre = curr;
      } else {
        tailNonTre->next = curr;
        tailNonTre = curr;
      }
    }
    curr = next;
    pos++;
  }

  *posTre = headTre;
  *posNonTre = headNonTre;

  *lstPtr = NULL;
}

int main() {
  int arr[] = {10, 20, 30, 40, 50, 60, 70};
  int n = sizeof(arr) / sizeof(arr[0]);
  IntList l = createList(arr, n);

  printf("Lista di partenza: ");
  printList(l);

  IntList tre = NULL, nonTre = NULL;
  separaTreNonTre(&l, &tre, &nonTre);

  printf("Lista posTre: ");
  printList(tre);

  printf("Lista posNonTre: ");
  printList(nonTre);

  printf("Lista originale dopo separazione (vuota): ");
  printList(l);

  freeList(tre);
  freeList(nonTre);

  return 0;
}
