/**
 * @brief Converte una stringa in naturale (data la base).
 *
 * Calcola il numero intero rappresentato dalla stringa in argomento nella base
 * (la base deve essere un numero intero nel range 2..36) in argomento:
 * − saltando gli eventuali spazi bianchi iniziali,
 * − fermandosi al raggiungimento del primo carattere non cifra nella base data (le cifre per la base 36 sono: 0,..,9,A,..,Z).
 *
 * @param s: Una stringa da convertire.
 * @param b: La base.
 * @param r: L'indirizzo dell'intero dove memorizzare il risultato.
 * @return   Restituisce 0 se 'b' non è nell’intervallo ammesso, oppure se non trova nessuna cifra valida
 *           (e in tal caso il valore all'indirizzo r non è significativo).
 *           Altrimenti restituisce 1, e scrive all'indirizzo r il numero intero rappresentato nella stringa nella base data.
 *           Non si accorge dell'eventuale overflow (restituendo in questo caso un risultato tipicamente scorretto).
 */
#include <stdio.h>
#include <ctype.h>

int stoub(char *s, unsigned short b, int *r) {
    if (b < 2 || b > 36) return 0;
    
    while (isspace((unsigned char)*s)) s++;
    
    int sign = 1;
    if (*s == '+' || *s == '-') {
        if (*s == '-') sign = -1;
        s++;
    }
    
    int result = 0;
    int found = 0;
    int valid = 1;
    while (*s && valid) {
        int digit = -1;
        if (*s >= '0' && *s <= '9') digit = *s - '0';
        else if (*s >= 'A' && *s <= 'Z') digit = *s - 'A' + 10;
        else if (*s >= 'a' && *s <= 'z') digit = *s - 'a' + 10;
        else valid = 0;
        
        if (digit >= 0 && digit < b) {
            result = result * b + digit;
            found = 1;
            s++;
        } else valid = 0;
    }
    
    if (!found) return 0;
    
    *r = result * sign;
    return 1;
}
