/**
 * Mitt svar på oppgave 17
 * @author Martinus Nordgård
 * @date 28 sept 2025
 * @file oppg17.c
 */

#include <stdio.h>
#include <ctype.h>

const int MINVERDI = 1;
const int MAXVERDI = 10000;

/**
 * Hovedprogrammet starter her
 */

 int main() {

    int intArray[5];
    char charArray[10];

    // for (int i = 0; i < 5; i++){ 
    //     do {
    //         printf("Skriv inn en verdi for skuffe nummer %i. Minst %i og maks %i.\n", i+1, MINVERDI, MAXVERDI);
    //         scanf("%i", &intArray[i]);
    //     } while (intArray[i] < MINVERDI || intArray[i] > MAXVERDI);
    // };
    // for (int i = 0; i < 5; i++){
    //     printf("\nDin array er %i", intArray[i]);
    // };


    for (int i = 0; i < 5; i++){   
        do {
            printf("Skriv inn en bokstav som skal i skuffe nr %i: ", i+1);
            scanf(" %c", &charArray[i]);
        } while (toupper(charArray[i]) < 65 || toupper(charArray[i]) > 65+26);
    }

    for (int i = 0; i < 5; i++){      
        charArray[i] = toupper(charArray[i]);
    }

    printf("Dine innleste bokstaver: ");
    for (int i = 0; i < 5; i++){
        printf("%c", charArray[i]);
    }

 }