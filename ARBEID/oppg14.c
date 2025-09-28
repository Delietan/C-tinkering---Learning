/**
 * Min løsning på oppgave 14.
 * @author Martinus Nordgård
 * @date 27. sept
 * @file oppg14.c
 */

 #include <stdio.h>

 /**
  * Hovedprogrammet begynner her
  */

  int main() {

    int tall, summen = 0, antallTall = 0;


    printf("Skriv inn et heltall større enn 0: ");
    scanf("%i",  &tall);

    while (tall > 0) {
        printf("Brukeren skrev: %i\n", tall);
        summen += tall;
        antallTall++;
        printf("Summen er nå: %i", summen);
        printf("\nSkriv et nytt tall: ");
        
        scanf("%i",  &tall);
    }
    printf("Tall lavere enn 1 oppdaget. Programmet avsluttes.");
    printf("\nSummen ble totalt:  %i", summen);
    printf("\nAntall tall ble:    %i", antallTall);
    printf("\nGjennomsnittet ble: %i", summen/antallTall);
    

  }