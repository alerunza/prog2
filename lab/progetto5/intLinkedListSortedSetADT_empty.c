#include <stdlib.h>
#include <stdbool.h>

#include "intSortedSetADT.h"
#include "intLinkedListSortedSetADT.h"

IntSortedSetADT mkSSet() {
    return NULL;
}

_Bool dsSSet(IntSortedSetADT *ssptr) {
    return false;
}

_Bool sset_add(IntSortedSetADT ss, const int elem) {
    return false;
}

_Bool sset_remove(const IntSortedSetADT ss, const int elem) {
    return false;
}

_Bool sset_member(const IntSortedSetADT ss, const int elem) {
    return false;
}

_Bool isEmptySSet(const IntSortedSetADT ss) {
    return false;
}

int sset_size(const IntSortedSetADT ss) {
    return -1;
}

_Bool sset_extract(IntSortedSetADT ss, int *ptr) {
    return false;
}

_Bool sset_equals(const IntSortedSetADT s1, const IntSortedSetADT s2) {
    return false;
}

_Bool sset_subseteq(const IntSortedSetADT s1, const IntSortedSetADT s2) {
    return false;
}

_Bool sset_subset(const IntSortedSetADT s1, const IntSortedSetADT s2) {
    return false;
}

IntSortedSetADT sset_union(const IntSortedSetADT s1, const IntSortedSetADT s2) {
    return NULL; 
}

IntSortedSetADT sset_intersection(const IntSortedSetADT s1, const IntSortedSetADT s2) {
    return NULL;
}

IntSortedSetADT sset_subtraction(const IntSortedSetADT s1, const IntSortedSetADT s2) {
    return NULL;   
}

_Bool sset_min(const IntSortedSetADT ss, int *ptr) {
    return false;
}

_Bool sset_max(const IntSortedSetADT ss, int *ptr) {
    return false;
}

_Bool sset_extractMin(IntSortedSetADT ss, int *ptr) {
    return false;    
}

_Bool sset_extractMax(IntSortedSetADT ss, int *ptr) {
    return false;       
}