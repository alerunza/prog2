#include <stdio.h>
#include <stdlib.h>

typedef struct intListNode IntListNode, *IntList;

struct intListNode {
  int data;
  IntList next;
};

int main() {
  IntList ls = malloc(sizeof(IntListNode));
  ls->data = 12;
  ls->next = malloc(sizeof(IntListNode));
  ls->next->data = 7;
  ls->next->next = malloc(sizeof(IntListNode));
  ls->next->next->data = 11;
  ls->next->next->next = NULL;

  return 0;
}
