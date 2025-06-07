#include <stdlib.h>
#include <stdbool.h>

#include "intSortedSetADT.h"
#include "intLinkedListSortedSetADT.h"

IntSortedSetADT mkSSet(){ // restituisce un insieme vuoto

    IntSortedSetADT newSet = (IntSortedSetADT)malloc(sizeof(struct intSortedSet));

    if(newSet==NULL){
		return NULL;
	}

    newSet->first = NULL;
    newSet->last = NULL;
    newSet->size = 0;

    return newSet;
}

_Bool dsSSet(IntSortedSetADT *ssptr){ // distrugge l'insieme, recuperando la memoria
    if(ssptr == NULL || *ssptr == NULL){
        return 0;
    }

    IntSortedSetADT ss = *ssptr;

    ListNodePtr current = ss->first;

    while(current != NULL){
        ListNodePtr next = current->next;
        free(current);

        current = next;
    }

    free(ss);
    *ssptr = NULL;

    return 1;
}

_Bool sset_add(IntSortedSetADT ss, const int elem) {
    if(ss == NULL){
        return 0;
    }
    
    ListNodePtr prev = NULL;
    ListNodePtr current = ss->first;
    
    while(current != NULL && current->elem < elem){
        prev = current;
        current = current->next;
    }
    
    if(current != NULL && current->elem == elem){
        return 0; // elem già presente
    }
    
    ListNodePtr newNode = (ListNodePtr)malloc(sizeof(struct intSortedSet));
    
    if(newNode == NULL){
        return 0;
    }
    
    newNode->elem = elem;
    newNode->next = current;
    
    if(prev == NULL){
        ss->first = newNode;
    } else{
        prev->next = newNode;
    }
    
    if(newNode->next == NULL){
        ss->last = newNode;
    }
    
    ss->size++;
    
    return 1;
    
}

_Bool sset_remove(const IntSortedSetADT ss, const int elem) {
    if(ss == NULL || ss->size == 0){
        return 0;
    }
    
    ListNodePtr prev = NULL;
    ListNodePtr current = ss->first;
    
    while(current != NULL && current->elem < elem){
        prev = current;
        current = current->next;
    }
    
    if(current == NULL || current->elem != elem){
        return 0; // elem non presente
    }
    
    if(prev == NULL){
        ss->first = current->next;
    } else{
        prev->next = current->next;
    }
    
    if(current->next == NULL){
        ss->last = prev;
    }
    
    free(current);
    ss->size--;
    
    return 1;
    
}

_Bool sset_member(const IntSortedSetADT ss, const int elem) {
    if(ss == NULL){
        return 0;
    }
    
    ListNodePtr current = ss->first;
    
    while(current != NULL && current->elem < elem){
        current = current->next;
    }
    
    return (current != NULL && current->elem == elem);
}

_Bool isEmptySSet(const IntSortedSetADT ss) {
    if(ss == NULL){
        return 0;
    }
    
    return (ss->first == NULL); // insieme vuoto se first è NULL
}

int sset_size(const IntSortedSetADT ss) {
    if(ss == NULL){
        return -1;
    }
    
    return ss->size;
}

_Bool sset_extract(IntSortedSetADT ss, int *ptr) {
    if(ss == NULL || ptr == NULL || ss->size == 0){
        return 0;
    }
    
    ListNodePtr firstNode = ss->first;
    *ptr = firstNode->elem;
    
    ss->first = firstNode->next;
    
    if(ss->first == NULL){
        ss->last = NULL;
    }
    
    free(firstNode);
    
    ss->size--;
    
    return 1;
}

_Bool sset_equals(const IntSortedSetADT s1, const IntSortedSetADT s2) {
    if(s1 == NULL || s2 == NULL){
        return 0;
    }
    
    if(s1->size != s2->size){
        return 0;
    }
    
    ListNodePtr p1 = s1->first;
    ListNodePtr p2 = s2->first;
    
    while(p1 != NULL && p2 != NULL){
        if(p1->elem != p2->elem){
            return 0;
        }
        
        p1 = p1->next;
        p2 = p2->next;
    }
    
    return 1;
}

_Bool sset_subseteq(const IntSortedSetADT s1, const IntSortedSetADT s2) {
    if(s1 == NULL || s2 == NULL){
        return 0;
    }
    
    if(s1->size > s2->size){
        return 0;
    }
    
    ListNodePtr p1 = s1->first;
    ListNodePtr p2 = s2->first;
    
    while (p1 != NULL && p2 != NULL) {
        if (p1->elem == p2->elem) {
            p1 = p1->next;
            p2 = p2->next;
        } else if (p1->elem > p2->elem) {
            p2 = p2->next;
        } else {
            return 0;
        }
    }
    
    return (p1 == NULL);
}

_Bool sset_subset(const IntSortedSetADT s1, const IntSortedSetADT s2) {
    if (!sset_subseteq(s1, s2)){
        return 0;    
    }
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