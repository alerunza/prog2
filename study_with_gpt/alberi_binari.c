#include <stdio.h>
#include <stdlib.h>

typedef struct nodo {
    int valore;
    struct nodo* sinistro;
    struct nodo* destro;
} Nodo;

Nodo* creaNodo(int valore) {
    Nodo* nuovo = malloc(sizeof(Nodo));
    nuovo->valore = valore;
    nuovo->sinistro = NULL;
    nuovo->destro = NULL;
    return nuovo;
}

Nodo* inserisci(Nodo* radice, int valore) {
    if (radice == NULL) return creaNodo(valore);
    if (radice->sinistro == NULL)
        radice->sinistro = inserisci(radice->sinistro, valore);
    else
        radice->destro = inserisci(radice->destro, valore);
    return radice;
}

Nodo* inserisciBST(Nodo* radice, int valore) {
    if (radice == NULL) return creaNodo(valore);
    if (valore < radice->valore)
        radice->sinistro = inserisciBST(radice->sinistro, valore);
    else
        radice->destro = inserisciBST(radice->destro, valore);
    return radice;
}

Nodo* cerca(Nodo* radice, int valore) {
    if (radice == NULL || radice->valore == valore)
        return radice;
    if (valore < radice->valore)
        return cerca(radice->sinistro, valore);
    else
        return cerca(radice->destro, valore);
}

void inorder(Nodo* radice) {
    if (radice != NULL) {
        inorder(radice->sinistro);
        printf("%d ", radice->valore);
        inorder(radice->destro);
    }
}

void preorder(Nodo* radice) {
    if (radice != NULL) {
        printf("%d ", radice->valore);
        preorder(radice->sinistro);
        preorder(radice->destro);
    }
}

void postorder(Nodo* radice) {
    if (radice != NULL) {
        postorder(radice->sinistro);
        postorder(radice->destro);
        printf("%d ", radice->valore);
    }
}

int contaNodi(Nodo* radice) {
    if (radice == NULL) return 0;
    return 1 + contaNodi(radice->sinistro) + contaNodi(radice->destro);
}

int contaFoglie(Nodo* radice) {
    if (radice == NULL) return 0;
    if (radice->sinistro == NULL && radice->destro == NULL) return 1;
    return contaFoglie(radice->sinistro) + contaFoglie(radice->destro);
}

int altezza(Nodo* radice) {
    if (radice == NULL) return 0;
    int h_sin = altezza(radice->sinistro);
    int h_des = altezza(radice->destro);
    return 1 + (h_sin > h_des ? h_sin : h_des);
}

int sommaValori(Nodo* radice) {
    if (radice == NULL) return 0;
    return radice->valore + sommaValori(radice->sinistro) + sommaValori(radice->destro);
}

void distruggi(Nodo* radice) {
    if (radice != NULL) {
        distruggi(radice->sinistro);
        distruggi(radice->destro);
        free(radice);
    }
}

int main() {
    Nodo* radice = NULL;

    // Inserimento valori in un BST
    radice = inserisciBST(radice, 8);
    radice = inserisciBST(radice, 3);
    radice = inserisciBST(radice, 10);
    radice = inserisciBST(radice, 1);
    radice = inserisciBST(radice, 6);
    radice = inserisciBST(radice, 14);

    printf("Inorder: ");
    inorder(radice);
    printf("\n");

    printf("Preorder: ");
    preorder(radice);
    printf("\n");

    printf("Postorder: ");
    postorder(radice);
    printf("\n");

    printf("Numero di nodi: %d\n", contaNodi(radice));
    printf("Numero di foglie: %d\n", contaFoglie(radice));
    printf("Altezza dell'albero: %d\n", altezza(radice));
    printf("Somma dei valori: %d\n", sommaValori(radice));

    int valoreDaCercare = 6;
    Nodo* trovato = cerca(radice, valoreDaCercare);
    if (trovato != NULL)
        printf("Valore %d trovato nell'albero.\n", valoreDaCercare);
    else
        printf("Valore %d non trovato.\n", valoreDaCercare);

    distruggi(radice);
    return 0;
}
