#include <stdio.h>
#include <stdlib.h>

typedef struct charListNode CharListNode, *CharList;

struct charListNode {
  char data;
  CharList next;
};

// esempi visite di una lista

void printCharList(CharList ls) {
  for (CharList currentPtr = ls; currentPtr != NULL;
       currentPtr = currentPtr->next) {
    printf("%c\n", currentPtr->data);
  }
}

size_t lenght(CharList ls) {
  size_t noe = 0;

  for (CharList currentPtr = ls; currentPtr != NULL;
       currentPtr = currentPtr->next) {
    noe++;
  }

  return noe;
}

size_t sumIntList(List ls) {
  int sum = 0;

  for (List currentPtr = ls; currentPtr != NULL;
       currentPtr = currentPtr->next) {
    sum += currentPtr->data;
  }

  return sum;
}

size_t count(List ls, _Bool (*predicate)(T e)) {
  size_t noe = 0;

  for (List currentPtr = ls; currentPtr != NULL;
       currentPtr = currentPtr->next) {
    if (predicate(currentPtr->data)) {
      noe++;
    }
  }

  return noe;
}
