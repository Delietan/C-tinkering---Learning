/**
 * Min løsning på oppgave 15 lets goo
 * 
 * @author Martinus Nordgård
 * @date 27. sept
 * @file oppg15.c
 */

#include <stdio.h>

/**
 * Hovedprogrammet starter her:
 */

 int main() {

    int tall1, tall2;
    char svar;

    do {
        printf("Skriv inn to heltall: ");
        scanf("%i", &tall1);
        printf("Første tallet som ble skrevet var: %i", tall1);

        printf("\nNeste tall: ");
        scanf("%i", &tall2);
        printf("Andre tallet som ble skrevet var: %i", tall2);

            int add     = tall1+tall2,
            sub         = tall1-tall2,
            multi       = tall1*tall2;

        printf("\nHer er de addert: %i, sub: %i og mult: %i \n", add, sub, multi);
        printf("Vil du gjenta dette programmet? (j/n)\n");
        scanf(" %c", &svar);
    } while (svar == 'j' || svar == 'J');

    printf("Ferdig");

    return 0;
};