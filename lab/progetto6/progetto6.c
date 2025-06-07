#include "ram.h"
#include <stdlib.h>
/**
•⁠  ⁠@brief Crea una struttura RAM con una certa quantità di memoria
•⁠  ⁠@param M la quantità di memoria voluta, espressa in KB (deve essere una potenza di 2, maggiore o uguale a 1)
•⁠  ⁠@return Il puntatore alla struttura creata, oppure NULL in caso di errore
*/
RAM initram(int M){
RAM r = (RAM) malloc(sizeof(struct nodo));
if(!r) return NULL;

 if(M<1 || (M & (M-1)) != 0) return NULL;

 r->KB=M;
 r->s=LIBERO;
 r->parent=NULL;
 r->lbuddy=NULL;
 r->rbuddy=NULL;

return r;
}
/**
•⁠  ⁠@brief Tenta di allocare una data quantità di memoria entro una RAM
•⁠  ⁠@param K la quantità di memoria richiesta, in KB
•⁠  ⁠@param ram la RAM entro cui cercare la memoria richiesta
•⁠  ⁠@return Il puntatore al nodo che può ospitare la quantità richiesta, oppure NULL se non trovato
*/
RAM allocram(int K, RAM ram){
 if(!ram || K<1 || ram->KB<K) return NULL;

 if((ram->s == LIBERO) && ((ram->KB == K)||((ram->KB/2) < K))){
 ram->s=OCCUPATO;
 return ram;
 }

 if (ram->s == INTERNO){
 RAM res = allocram(K, ram->lbuddy);
 if (res) return res;

 res = allocram(K, ram->rbuddy);
 if (res) return res;

 return NULL; // NON risali
 }

 if(ram->s == LIBERO){
 RAM left = initram((ram->KB / 2));//creo i nuovi nodi figli
 RAM right = initram((ram->KB / 2));
 if(!left || !right) return NULL;

 left->parent=ram;
 right->parent=ram;

 ram->lbuddy=left;
 ram->rbuddy=right;
 ram->s = INTERNO; //aggiorno ram che diventa nodo interno

 return allocram(K, ram->lbuddy);
 }

return NULL;
}
/**
•⁠  ⁠@brief Libera un nodo RAM precedentemente ottenuto con allocram
•⁠  ⁠@param ram il nodo RAM da liberare
•⁠  ⁠@return Il successo della operazione
*/
Risultato deallocram(RAM ram){
 if (!ram || ram->s != OCCUPATO || ram->lbuddy || ram->rbuddy) return NOK;

 ram->s = LIBERO;

RAM curr = ram;
 while(curr->parent){
 RAM padre = curr->parent;
 RAM fratello = (curr == padre->lbuddy ? padre->rbuddy : padre->lbuddy);
 if(fratello && fratello->s == LIBERO){
 padre->s=LIBERO;
 free(padre->rbuddy);
 free(padre->lbuddy);

 padre->rbuddy=NULL;
 padre->lbuddy=NULL;

 curr=padre;
 }
 else{
 return OK;
 }

 }

return OK;
}
/**
•⁠  ⁠@brief calcola il numero di KB di memoria ancora liberi all'interno di una struttura RAM
•⁠  ⁠@param ram la struttura RAM
•⁠  ⁠@return La quantità di memoria libera, oppure -1 in caso di errore
*/
int numfree(RAM ram){
 if(!ram) return -1;

 if(ram->s == LIBERO && !ram->lbuddy && !ram->rbuddy){
 return ram->KB;
 }

 if(ram->s==OCCUPATO) return 0;

 int left=numfree(ram->lbuddy);
 int right=numfree(ram->rbuddy);

return left+right;
}
/**
•⁠  ⁠@brief crea una rappresentazione dello stato interno della RAM sotto forma di una stringa (in un formato a piacere,
•⁠  ⁠purchè completo di tutte le informazioni, ovvero tale che si possa ricreare dalla stringa esattamente lo stesso stato)
•⁠  ⁠@param ram la struttura RAM di cui creare la stringa
•⁠  ⁠@return la stringa creata, vuota in caso di RAM nulla o errore
*/
char* ram2str(RAM ram){
char* str_vuoto= malloc(1);
if (!str_vuoto) return NULL;
 str_vuoto[0]='\0';

if(!ram) return str_vuoto;

 // Ricorsione preOrder
 char* sinistra = ram2str(ram->lbuddy);
 char* destra = ram2str(ram->rbuddy);

char stato;
 if(ram->s==LIBERO){
 stato='L';
 }
 else{
 stato=(ram->s==OCCUPATO ? 'O' : 'I');
 }

 int len_KB = snprintf(NULL, 0, "%d", ram->KB);
 char kb_radice[len_KB + 1];
 sprintf(kb_radice, "%d", ram->KB);
 // Calcolo lunghezza totale stringa da allocare
 size_t lungh_tot = len_KB + 1 + strlen(sinistra) + strlen(destra) + 1;//len_KB+char per stato+sin+des+'\0'

 char* str = malloc(lungh_tot);
 if (!str) {
 free(sinistra);
 free(destra);
 return NULL;
 }
 // Costruisco la stringa finale
 strcpy(str, kb_radice);
 str[len_KB] = stato;
 str[len_KB + 1] = '\0';
 strcat(str, sinistra);
 strcat(str, destra);
 free(sinistra);
 free(destra);
 return str;
}
/**
•⁠  ⁠@brief ricostruisce una struttura RAM a partire dalla sua rappresentazione sotto forma di stringa creata da ram2str
•⁠  ⁠@param s la stringa che contiene la rappresentazione della RAM, eventualmente vuota
•⁠  ⁠@return la RAM creata, oppure NULL in caso di errore o stringa vuota
*/
RAM str2ram(char *str){
 if (!str || *str == '\0') {
 return NULL;
 }

int kb=0;
 while (isdigit(*str)) {
 kb = kb * 10 + (*str - '0');
 str++;
 }

RAM ram=initram(kb);
if(!ram) return NULL;

 if(kb!=0){
 ram->KB=kb;
 }
 else if(ram->parent){ //se non è il nodo radice
 ram->KB=(ram->parent->KB)/2;
 }

 if(*str=='O'){
 ram->s = OCCUPATO;
 return ram;
 }

 else if(*str=='L'){
 ram->s = LIBERO;
 return ram;
 }
 else if(*str=='I'){
 ram->s = INTERNO;
 str++;

 char *left_str = str; //per scorrere la stringa
 char *right_str = NULL;


 int conta=1;
 while (*str && conta>0) {// Trova dove finisce il sottoalbero sinistro
 if (*str=='I'){conta++;} // se trovo interno vada avanti
 else if (*str=='O' || *str=='L') {conta--;}
 str++;
 }
 right_str = str;
 RAM left = str2ram(left_str);
 RAM right = str2ram(right_str);
 if (left) left->parent = ram;
 if (right) right->parent = ram;
 ram->lbuddy = left;
 ram->rbuddy = right;
 return ram;
 }

return NULL;
}
/**
•⁠  ⁠@brief cancella dallo heap la struttura dati di un nodo RAM e di tutti i suoi figli
•⁠  ⁠@param ram il nodo RAM da cancellare
•⁠  ⁠@return Restituisce OK se la funzione ha effettivamente liberato della memoria, NOK altrimenti
*/
Risultato freeram(RAM* ramptr){
 if (ramptr == NULL || *ramptr == NULL) return NOK;
 freeram(&(*ramptr)->lbuddy);
 freeram(&(*ramptr)->rbuddy);
 free(*ramptr);
 *ramptr = NULL;
 return OK;
}