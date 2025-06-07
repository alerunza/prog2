typedef struct node {
    int data;
    struct node *next;
} IntNode, *IntList;


int contaPari(IntList l){
    int conta = 0;
    while(l != NULL){
        if(l->data % 2 == 0){
            conta++;
        }
        l = l->next;
    }

    return conta;
}