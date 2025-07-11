#include <stdio.h>
#include <stdlib.h>

typedef struct treeNode IntTreeNode, *IntTree;
struct treeNode {
    IntTree left;
    int data;
    IntTree right;
    IntTree parent; // puntatore al padre(vale NULL alla radice)
};


/* CREAZIONE DI NODI */
IntTree creanodo(int value){
    IntTree newNode = (IntTree)malloc(sizeof(IntTreeNode));
    newNode -> data = value;
    newNode -> left = NULL;
    newNode -> right = NULL;
    return newNode;
}

/* CONTAFOGLIE */
int contafoglie(IntTree tree){
    if(tree == NULL){
        return 0;
    }
    else if(tree -> left == NULL && tree -> right == NULL){
        return 1;
    }
    else{
        return 1 + contafoglie(tree-> left) + contafoglie(tree -> right);
    }
}

/* CONTAFOGLIE IN UN INTERVALLO m E n */
int n_foglie_n_m_ric(IntTree tree, int m, int n, int curr_prof){
    if(tree == NULL){
        return 0;
    }
    
    else if(curr_prof >= m && curr_prof <= n){
        return 1;
    }
    else{
        return 1 + n_foglie_n_m_ric(tree -> left, m, n, curr_prof+1) 
                 + n_foglie_n_m_ric(tree -> right, m, n, curr_prof+1);
                    
    }
}
int n_foglie_m_n(IntTree tree, int m, int n){
    return n_foglie_n_m_ric(tree, m, n, 0);
}

/* FA IN MODO CHE L'ALBERO SIA ORDINATO E CRESCENTE DA DESTRA VERSO SINISTRA */
void order_sort(IntTree tree){
    if(tree == NULL){
        return;
    }
    if(tree -> left > tree -> right && tree -> left -> data > tree -> right -> data){
        IntTree temp = tree -> left;
        tree -> left = tree -> right;
        tree -> right = temp;
    }
    order_sort(tree -> left);
    order_sort(tree -> right);
}

/* Specchia l'albero */
void mirror(IntTree tree){
    if(tree == NULL){
        return;
    }
    else{
        IntTree temp = tree -> left;
        tree -> left = tree -> right;
        tree -> right = temp;

        mirror(tree -> left);
        mirror(tree -> right);
    }
}

/* PROFONDITA' DI UN ALBERO, RICORDARE CHE SE UN ALBERO E' VUOTO LA SUA PROFONDITA' E' -1 */
int profondita(IntTree tree){
    if(tree == NULL){
        return -1;
    }
    else{
        int p_right = profondita(tree -> right);
        int p_left = profondita(tree -> left);
        return 1 + (p_right > p_left ? p_right : p_left);
    }
}

int contanodi(IntTree tree){
    if(tree == NULL){
        return 0;
    }
    else{
        return 1 + contanodi(tree -> left) + contanodi(tree -> right);
    }
}


/* Dato un albero binario tree, restituisce la somma di tutte le foglie 
che sono filgie uniche del proprio parent 
-Dato l'albero vuoto restituisce 0
-Dato l'albero che contiene un solo nodo restituire il valore di quel nodo
-Dato l'abero in esempio restituisce 17
albero d'esempio :
      1
     / \
    2   3 
   /\.   \
  4  5.   7
    /      
   10

RESTITUISCE LA SOMMA DI 10 + 7 PERCHE SONO LE FIGLIE UNICHE DI 3 E DI 5   
*/

int somma_figli(IntTree tree){
    if(tree == NULL){
        return 0;
    }
    else{
        int somma = 0;
        if(tree -> left != NULL && tree -> right == NULL){
            if((tree -> left -> left == NULL) && (tree -> left -> right == NULL)){
                somma += tree -> left -> data;
            }
        }
        if(tree -> left == NULL && tree -> right != NULL){
            if((tree -> right -> left == NULL) && (tree -> right -> right == NULL)){
                somma += tree -> right -> data;
            }
        }

        somma += somma_figli(tree -> left);
        somma += somma_figli(tree -> right);

        return somma;
    }

}

int main(){
    IntTree root = creanodo(1);
    root -> left = creanodo(2);
    root -> right = creanodo(3);
    root -> left -> left = creanodo(4);
    root -> left -> right = creanodo(5);
    root -> right -> right = creanodo(7);
    root -> left -> right -> left = creanodo(10);
   

    printf("La somma delle foglie figlie uniche è : %d" , somma_figli(root));
return 0;

}
