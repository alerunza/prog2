#include <stdio.h>
#include <stdlib.h>

typedef struct charListNode CharListNode, *CharList;

struct charListNode {
  char data;
  CharList next;
};

_Bool deleteFromCharList(CharList *sPtr, char value) {
  CharList previousPtr = NULL;
  CharList currentPtr = *sPtr;

  while (currentPtr != NULL && currentPtr->data != value) {
    previousPtr = currentPtr;
    currentPtr = currentPtr->next;
  }

  if (currentPtr == NULL)
    return 0;

  if (previousPtr == NULL) {
    *sPtr = (*sPtr)->next;
  } else {
    previousPtr->next = currentPtr->next;
  }

  free(currentPtr);
  return 1;
}

_Bool deleteFromSortedCharList(CharList *sPtr, char value) {
  CharList previousPtr = NULL;
  CharList currentPtr = *sPtr;

  while (currentPtr != NULL && currentPtr->data < value) {
    previousPtr = currentPtr;
    currentPtr = currentPtr->next;
  }

  if (currentPtr == NULL || currentPtr->data != value)
    return 0;

  if (previousPtr == NULL) {
    *sPtr = (*sPtr)->next;
  } else {
    previousPtr->next = currentPtr->next;
  }

  free(currentPtr);
  return 1;
}

_Bool delete(CharList *sPtr, CharList positionPtr) {
  if (*sPtr == NULL || positionPtr == NULL)
    return 0;

  CharList previousPtr = NULL;
  CharList currentPtr = *sPtr;

  while (currentPtr != NULL && currentPtr != positionPtr) {
    previousPtr = currentPtr;
    currentPtr = currentPtr->next;
  }

  if (currentPtr == NULL)
    return 0;

  if (previousPtr == NULL) {
    *sPtr = (*sPtr)->next;
  } else {
    previousPtr->next = currentPtr->next;
  }

  free(currentPtr);
  return 1;
}

_Bool deleteAfter(CharList *sPtr, CharList positionPtr) {
  if (*sPtr == NULL)
    return 0;

  if (positionPtr == NULL)
    return 0;

  CharList target = positionPtr->next;
  if (target == NULL)
    return 0;

  positionPtr->next = target->next;
  free(target);
  return 1;
}

/* utility */
CharList createNode(char c) {
  CharList n = malloc(sizeof(CharListNode));
  if (!n)
    return NULL;
  n->data = c;
  n->next = NULL;
  return n;
}

void printCharList(CharList ls) {
  for (CharList p = ls; p != NULL; p = p->next) {
    printf("%c -> ", p->data);
  }
  printf("NULL\n");
}

CharList findChar(CharList ls, char c) {
  for (CharList p = ls; p != NULL; p = p->next)
    if (p->data == c)
      return p;
  return NULL;
}

void freeCharList(CharList ls) {
  while (ls) {
    CharList tmp = ls->next;
    free(ls);
    ls = tmp;
  }
}

int main(void) {
  // creo lista ordinata [A, B, C, D, E]
  CharList s = createNode('A');
  s->next = createNode('B');
  s->next->next = createNode('C');
  s->next->next->next = createNode('D');
  s->next->next->next->next = createNode('E');

  printf("Lista iniziale: ");
  printCharList(s);

  deleteFromCharList(&s, 'C');
  printf("Dopo deleteFromCharList('C'): ");
  printCharList(s);

  deleteFromSortedCharList(&s, 'D');
  printf("Dopo deleteFromSortedCharList('D'): ");
  printCharList(s);

  CharList posB = findChar(s, 'B');
  delete(&s, posB);
  printf("Dopo delete nodo 'B': ");
  printCharList(s);

  CharList posA = findChar(s, 'A');
  deleteAfter(&s, posA);
  printf("Dopo deleteAfter(A): ");
  printCharList(s);

  freeCharList(s);
  return 0;
}
