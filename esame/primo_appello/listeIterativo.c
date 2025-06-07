typedef struct node {
    int data;
    struct node *next;
} IntNode, *IntList;

IntList mixAlternate(IntList *lsPtr1, IntList *lsPtr2) {
    IntList head = NULL, tail = NULL;
    IntList *lists[2] = {lsPtr1, lsPtr2};
    int i = 0;

    while (*lists[0] || *lists[1]) {
        if (*lists[i]) {
            IntList tmp = *lists[i];
            *lists[i] = tmp->next;
            tmp->next = NULL;

            if (!head) {
                head = tail = tmp;
            } else {
                tail->next = tmp;
                tail = tmp;
            }
        }
        i = 1 - i;
    }

    return head;
}
