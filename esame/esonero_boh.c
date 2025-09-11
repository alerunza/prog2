#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node CharNode, *CharList;
struct node {
  char data;
  CharList next;
};

void printList(CharList ls) {
  while (ls) {
    printf("%c ", ls->data);
    ls = ls->next;
  }
  printf("\n");
}

void freeList(CharList ls) {
  while (ls) {
    CharList t = ls;
    ls = ls->next;
    free(t);
  }
}

void push_back(CharList *h, CharList *t, char c) {
  CharList n = (CharList)malloc(sizeof(CharNode));
  n->data = c;
  n->next = NULL;
  if (*h == NULL) {
    *h = n;
    *t = n;
  } else {
    (*t)->next = n;
    *t = n;
  }
}

CharList stringToList_upper_to_lower(char *s) {
  if (s == NULL || *s == '\0')
    return NULL;
  CharList h = NULL, t = NULL;
  int i = 0;
  while (s[i]) {
    char c = s[i];
    if (isupper(c))
      push_back(&h, &t, (char)tolower(c));
    i++;
  }
  return h;
}

CharList stringToList_all_letters_lower(char *s) {
  if (s == NULL || *s == '\0')
    return NULL;
  CharList h = NULL, t = NULL;
  int i = 0;
  while (s[i]) {
    char c = s[i];
    if (isalpha(c))
      push_back(&h, &t, (char)tolower(c));
    i++;
  }
  return h;
}

CharList stringToList_vowels_lower(char *s) {
  if (s == NULL || *s == '\0')
    return NULL;
  CharList h = NULL, t = NULL;
  int i = 0;
  while (s[i]) {
    char c = (char)tolower(s[i]);
    if (isalpha(c)) {
      if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
        push_back(&h, &t, c);
    }
    i++;
  }
  return h;
}

CharList stringToList_upper_unique_lower(char *s) {
  if (s == NULL || *s == '\0')
    return NULL;
  CharList h = NULL, t = NULL;
  int seen[26] = {0};
  int i = 0;
  while (s[i]) {
    char c = s[i];
    if (isupper(c)) {
      int idx = c - 'A';
      if (idx >= 0 && idx < 26 && !seen[idx]) {
        seen[idx] = 1;
        push_back(&h, &t, (char)tolower(c));
      }
    }
    i++;
  }
  return h;
}

int main(void) {
  char str[] = "Coordination@DisCoTec-2025";
  CharList a = stringToList_upper_to_lower(str);
  CharList b = stringToList_all_letters_lower(str);
  CharList c = stringToList_vowels_lower(str);
  CharList d = stringToList_upper_unique_lower(str);
  printList(a);
  printList(b);
  printList(c);
  printList(d);
  freeList(a);
  freeList(b);
  freeList(c);
  freeList(d);
  return 0;
}
