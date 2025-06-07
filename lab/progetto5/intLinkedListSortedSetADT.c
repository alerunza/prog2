#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

#include "intSortedSetADT.h"
#include "intLinkedListSortedSetADT.h"

IntSortedSetADT mkSSet() {
    IntSortedSetADT ss = (IntSortedSetADT)malloc(sizeof(struct intSortedSet));
    if (ss == NULL) return NULL;
    
    ss->first = NULL;
    ss->last = NULL;
    ss->size = 0;
    return ss;
}

_Bool dsSSet(IntSortedSetADT *ssptr) {
    if (ssptr == NULL || *ssptr == NULL) return false;
    
    IntSortedSetADT ss = *ssptr;
    ListNodePtr current = ss->first;
    while (current != NULL) {
        ListNodePtr next = current->next;
        free(current);
        current = next;
    }
    
    free(ss);
    *ssptr = NULL;
    return true;
}

_Bool sset_add(IntSortedSetADT ss, const int elem) {
    if (ss == NULL) return false;
    
    // ora cerco se l'elemento esiste già
    ListNodePtr prev = NULL;
    ListNodePtr current = ss->first;
    
    while (current != NULL && current->elem < elem) {
        prev = current;
        current = current->next;
    }
    
    // se l'elemento esiste già, non fare nulla
    if (current != NULL && current->elem == elem) {
        return false;
    }
    
    // creo il nuovo nodo
    ListNodePtr newNode = (ListNodePtr)malloc(sizeof(struct listNode));
    if (newNode == NULL) return false;
    newNode->elem = elem;
    newNode->next = current;
    
    // inserisco il nuovo nodo
    if (prev == NULL) {
        ss->first = newNode;
    } else {
        prev->next = newNode;
    }
    
    // aggiorno last se necessario
    if (newNode->next == NULL) {
        ss->last = newNode;
    }
    
    ss->size++;
    return true;
}

_Bool sset_remove(const IntSortedSetADT ss, const int elem) {
    if (ss == NULL || ss->size == 0) return false;
    
    ListNodePtr prev = NULL;
    ListNodePtr current = ss->first;
    
    while (current != NULL && current->elem < elem) {
        prev = current;
        current = current->next;
    }
    
    if (current == NULL || current->elem != elem) {
        return false;
    }
    
    if (prev == NULL) {
        ss->first = current->next;
    } else {
        prev->next = current->next;
    }
    
    if (current->next == NULL) {
        ss->last = prev;
    }
    
    free(current);
    ss->size--;
    return true;
}

_Bool sset_member(const IntSortedSetADT ss, const int elem) {
    if (ss == NULL) return false;
    
    ListNodePtr current = ss->first;
    while (current != NULL && current->elem < elem) {
        current = current->next;
    }
    
    return (current != NULL && current->elem == elem);
}

_Bool isEmptySSet(const IntSortedSetADT ss) {
    if (ss == NULL) return false; // NULL non è un insieme valido
    return (ss->first == NULL);   // insieme vuoto se first è NULL
}

int sset_size(const IntSortedSetADT ss) {
    if (ss == NULL) return -1;
    return ss->size;
}

_Bool sset_extract(IntSortedSetADT ss, int *ptr) {
    if (ss == NULL || ptr == NULL || ss->size == 0) return false;
    
    ListNodePtr firstNode = ss->first;
    *ptr = firstNode->elem;
    
    ss->first = firstNode->next;
    if (ss->first == NULL) {
        ss->last = NULL;
    }
    
    free(firstNode);
    ss->size--;
    return true;
}

_Bool sset_equals(const IntSortedSetADT s1, const IntSortedSetADT s2) {
    if (s1 == NULL || s2 == NULL) return false;
    if (s1->size != s2->size) return false;
    
    ListNodePtr p1 = s1->first;
    ListNodePtr p2 = s2->first;
    
    while (p1 != NULL && p2 != NULL) {
        if (p1->elem != p2->elem) return false;
        p1 = p1->next;
        p2 = p2->next;
    }
    
    return true;
}

_Bool sset_subseteq(const IntSortedSetADT s1, const IntSortedSetADT s2) {
    if (s1 == NULL || s2 == NULL) return false;
    if (s1->size > s2->size) return false;
    
    ListNodePtr p1 = s1->first;
    ListNodePtr p2 = s2->first;
    
    while (p1 != NULL && p2 != NULL) {
        if (p1->elem == p2->elem) {
            p1 = p1->next;
            p2 = p2->next;
        } else if (p1->elem > p2->elem) {
            p2 = p2->next;
        } else {
            return false;
        }
    }
    
    return (p1 == NULL);
}

_Bool sset_subset(const IntSortedSetADT s1, const IntSortedSetADT s2) {
    if (!sset_subseteq(s1, s2)) return false;
    return (s1->size < s2->size);
}

IntSortedSetADT sset_union(const IntSortedSetADT s1, const IntSortedSetADT s2) {
    if (s1 == NULL || s2 == NULL) return NULL;
    
    IntSortedSetADT result = mkSSet();
    if (result == NULL) return NULL;
    
    ListNodePtr p1 = s1->first;
    ListNodePtr p2 = s2->first;
    
    while (p1 != NULL && p2 != NULL) {
        if (p1->elem < p2->elem) {
            if (!sset_add(result, p1->elem)) {
                dsSSet(&result);
                return NULL;
            }
            p1 = p1->next;
        } else if (p1->elem > p2->elem) {
            if (!sset_add(result, p2->elem)) {
                dsSSet(&result);
                return NULL;
            }
            p2 = p2->next;
        } else {
            if (!sset_add(result, p1->elem)) {
                dsSSet(&result);
                return NULL;
            }
            p1 = p1->next;
            p2 = p2->next;
        }
    }
    
    // aggiungo gli elementi rimanenti di s1
    while (p1 != NULL) {
        if (!sset_add(result, p1->elem)) {
            dsSSet(&result);
            return NULL;
        }
        p1 = p1->next;
    }
    
    // aggiungo gli elementi rimanenti di s2
    while (p2 != NULL) {
        if (!sset_add(result, p2->elem)) {
            dsSSet(&result);
            return NULL;
        }
        p2 = p2->next;
    }
    
    return result;
}

IntSortedSetADT sset_intersection(const IntSortedSetADT s1, const IntSortedSetADT s2) {
    if (s1 == NULL || s2 == NULL) return NULL;
    
    IntSortedSetADT result = mkSSet();
    if (result == NULL) return NULL;
    
    ListNodePtr p1 = s1->first;
    ListNodePtr p2 = s2->first;
    
    while (p1 != NULL && p2 != NULL) {
        if (p1->elem < p2->elem) {
            p1 = p1->next;
        } else if (p1->elem > p2->elem) {
            p2 = p2->next;
        } else {
            if (!sset_add(result, p1->elem)) {
                dsSSet(&result);
                return NULL;
            }
            p1 = p1->next;
            p2 = p2->next;
        }
    }
    
    return result;
}

IntSortedSetADT sset_subtraction(const IntSortedSetADT s1, const IntSortedSetADT s2) {
    if (s1 == NULL || s2 == NULL) return NULL;
    
    IntSortedSetADT result = mkSSet();
    if (result == NULL) return NULL;
    
    ListNodePtr p1 = s1->first;
    ListNodePtr p2 = s2->first;
    
    while (p1 != NULL && p2 != NULL) {
        if (p1->elem < p2->elem) {
            if (!sset_add(result, p1->elem)) {
                dsSSet(&result);
                return NULL;
            }
            p1 = p1->next;
        } else if (p1->elem > p2->elem) {
            p2 = p2->next;
        } else {
            p1 = p1->next;
            p2 = p2->next;
        }
    }
    
    // aggiungo gli elementi rimanenti di s1
    while (p1 != NULL) {
        if (!sset_add(result, p1->elem)) {
            dsSSet(&result);
            return NULL;
        }
        p1 = p1->next;
    }
    
    return result;
}

_Bool sset_min(const IntSortedSetADT ss, int *ptr) {
    if (ss == NULL || ptr == NULL || ss->size == 0) return false;
    *ptr = ss->first->elem;
    return true;
}

_Bool sset_max(const IntSortedSetADT ss, int *ptr) {
    if (ss == NULL || ptr == NULL || ss->size == 0) return false;
    *ptr = ss->last->elem;
    return true;
}

_Bool sset_extractMin(IntSortedSetADT ss, int *ptr) {
    if (ss == NULL || ptr == NULL || ss->size == 0) return false;
    *ptr = ss->first->elem;
    return sset_remove(ss, *ptr);
}

_Bool sset_extractMax(IntSortedSetADT ss, int *ptr) {
    if (ss == NULL || ptr == NULL || ss->size == 0) return false;
    *ptr = ss->last->elem;
    return sset_remove(ss, *ptr);
}