#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node *next;
};

typedef struct node nodeT;

void printList(nodeT *list) {
  nodeT *temp = list;

  while (temp != NULL) {
    printf("%d - ", temp->data);
    temp = temp->next;
  }

  printf("\n");
}

int main() {
  nodeT n1, n2, n3;
  nodeT *head;

  n1.data = 45;
  n2.data = 8;
  n3.data = 32;

  head = &n1;
  n3.next = NULL;
  n2.next = &n3;
  n1.next = &n2;

  printList(head);

  return 0;
}
