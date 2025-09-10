// Dato un albero binario definito da :
typedef struct treeNode IntTreeNode, *IntTree;
struct treeNode {
  IntTree left;
  int data;
  IntTree right;
};

/*
e la specifica di funzione :
* Dato un albero binario tree, lo modifica nel seguente modo:
* 1) per ciascun nodo interno avente un solo figlio, aggiunge un secondo figlio
con valore * pari alla somma dei valori dei nodi sul cammino dalla radice al
nodo considerato
* 2) per ciascuna foglia, aggiunge un figlio destro e un figlio sinistro,
ciascuno dei quali con * valore pari al risultato della divisione intera per due
del valore della foglia considerata
*/

void modifica(IntTree tree);
