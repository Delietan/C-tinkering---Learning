/**
 * Løsning på oppgave nr 9.
 * 
 * 
 * @file oppg9.c
 * @author Martinus Nordgård, NTNU
 * 
 */


 #include <stdio.h>             // printf()

 /**
  * Hovedprogrammet
  * 
  */

  int main()
  {
    int totaltSekunder = 312304,
        timer = 0,
        minutter = 0,
        sekunder = 0;

        timer = totaltSekunder / (60 * 60);
        minutter = (totaltSekunder / 60) % 60;
        sekunder = totaltSekunder % 60;
        // sekunder = (totaltSekunder % (60 * 60)) % 60;

        printf("TEST: %i\n\n", totaltSekunder % 60);
        printf("TEST2: %i\n\n", totaltSekunder / 60);
        printf("TEST3: %i\n\n", totaltSekunder / 60 / 60);
        printf("TEST4: %i\n\n", totaltSekunder / 60 % 60);


        printf("%i sekunder er %i timer, %i minutter og %i sekunder\n\n", totaltSekunder, timer, minutter, sekunder);

  }