typedef struct node IntNode, *IntList;

struct node {
  int data;
  IntList next;
};

/**@brief Modifica  la lista *lstPtr, separando i nodi in posizione multipla 3
 * dai nodi in posizione non multipla di 3. I nodi in posizione multipla 3
 * verranno inseriti (nello stesso ordine rispetto alla lista originaria)
 * nella lista *posTre, quelli in posizione non multipla di 3 verranno inseriti
 * (nello stesso rispetto alla lista originaria) nella lista *posNonTre.
 * La posizione del primo nodo di una lista è 1.
 */
void stampa(IntList *posTre, IntList *posNonTre) {
  while (*posTre != NULL || (*posNonTre) != NULL) {
    if (*posTre != NULL) {
      printf("posTre: ");
      printf("%d ", (*posTre)->data);
      (*posTre) = (*posTre)->next;
    }

    if (*posNonTre != NULL) {
      printf("posNonTre: ");
      printf("%d ", (*posNonTre)->data);
      (*posNonTre) = (*posNonTre)->next;
    }
  }
}

void separaTreNonTre(IntList *lstPtr, IntList *posTre, IntList *posNonTre) {
  *posTre = NULL, *posNonTre = NULL;

  if (lstPtr == NULL || *lstPtr == NULL) {
    return;
  }

  IntList curr = *lstPtr, next = NULL;
  int pos = 1;

  while (curr != NULL) {
    next = curr->next;
    curr->next = next;

    if (pos % 3 == 0) {
      *posTre = curr;
      curr->next = next;
      (*posTre)->next = curr->next;
    } else {
      *posNonTre = curr;
      curr->next = next;
      (*posNonTre)->next = curr->next;
    }

    curr = next;
    pos++;
  }

  *lstPtr = NULL;
  // stampa(posTre, posNonTre);
}
