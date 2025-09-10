#include <stdio.h>
#include <stdlib.h>

typedef struct charListNode CharListNode, *CharList;
struct charListNode {
  char data;
  CharList next;
};

_Bool insertInSortedCharList(CharList *sPtr, char value) {
  CharList newPtr = malloc(sizeof(CharListNode));

  if (newPtr == NULL)
    return 0;

  newPtr->data = value;
  newPtr->next = NULL;

  CharList previousPtr = NULL;
  CharList currentPtr = *sPtr;

  while (currentPtr != NULL && value > currentPtr->data) {
    previousPtr = currentPtr;
    currentPtr = currentPtr->next;
  }

  if (previousPtr == NULL) {
    newPtr->next = newPtr;
    *sPtr = newPtr;
  } else {
    previousPtr->next = newPtr;
    newPtr->next = currentPtr;
  }

  return 1;
}

_Bool insertBefore(CharList *sPtr, char value, CharList positionPtr) {
  CharList newPtr = malloc(sizeof(CharListNode));
  if (newPtr == NULL)
    return 0;

  newPtr->data = value;
  newPtr->next = NULL;

  CharList previousPtr = NULL;
  CharList currentPtr = *sPtr;

  while (currentPtr != NULL && currentPtr != positionPtr) {
    previousPtr = currentPtr;
    currentPtr = currentPtr->next;
  }

  if (currentPtr != positionPtr)
    return 0;

  if (previousPtr == NULL) {
    newPtr->next = *sPtr;
    *sPtr = newPtr;
  } else {
    previousPtr->next = newPtr;
    newPtr->next = currentPtr;
  }

  return 1;
}

_Bool insertAfter(CharList *sPtr, char value, CharList positionPtr) {
  CharList newPtr = malloc(sizeof(CharListNode));

  if (newPtr == NULL)
    return 0;

  newPtr->data = value;
  newPtr->next = NULL;

  if (positionPtr == NULL) {
    newPtr->next = *sPtr;
    *sPtr = newPtr;
  } else {
    newPtr->next = positionPtr->next;
    positionPtr->next = newPtr;
  }

  return 1;
}

/* utility */
void printCharList(CharList ls) {
  for (CharList p = ls; p != NULL; p = p->next) {
    printf("%c ->", p->data);
  }
  printf("NULL\n");
}

CharList createNode(char c) {
  CharList n = malloc(sizeof(CharListNode));
  n->data = c;
  n->next = NULL;

  return n;
}

CharList findChar(CharList ls, char c) {
  for (CharList p = ls; p != NULL; p = p->next)
    if (p->data == c)
      return p;
  return NULL;
}

void freeCharList(CharList ls) {
  while (ls) {
    CharList nx = ls->next;
    free(ls);
    ls = nx;
  }
}

int main(void) {
  CharList s = createNode('A');
  s->next = createNode('B');
  s->next->next = createNode('D');
  s->next->next->next = createNode('E');

  printCharList(s);
  insertInSortedCharList(&s, 'C');
  printCharList(s);

  CharList posA = findChar(s, 'A');
  insertBefore(&s, 'Z', posA);
  printf("Dopo insertBefore 'Z' prima di 'A': ");
  printCharList(s);

  CharList posD = findChar(s, 'D');
  insertBefore(&s, 'X', posD);
  printf("Dopo insertBefore 'X' prima di 'D': ");
  printCharList(s);

  CharList posC = findChar(s, 'C');
  insertAfter(&s, 'Y', posC);
  printf("Dopo insertAfter  'Y' dopo 'C':     ");
  printCharList(s);

  insertAfter(&s, 'H', NULL);
  printf("Dopo insertAfter 'H' con pos=NULL:  ");
  printCharList(s);

  freeCharList(s);
  return 0;
}
