/**
 * MIN LØSNING PÅ OPPGAVE 18
 * @author Martinus Nordgård
 * @file oppg18.c
 * @date 28. sept 2025
 */

 #include <stdio.h>

 /**
  * Hovedprogrammet starter her
  */

  int main() 
  {
    // printf("\nDette er et tall: \n");
    // for (int kake = 0; kake < 10; kake++){
    //     for (int i = 0; i < 10; i++){
    //         if (i % 2 == 0)
    //             printf(" %i%i partall", kake, i);
    //         else
    //             printf(" %i%i oddetall", kake, i);
    //     }
    //     printf("\n");
    // };

    for (int i = 1; i <= 100; i++){
        printf("%3i - ", i);

        if (i % 2 == 0) {
            printf("Partall  ");
        } else {
            printf("Oddetall ");
        }
        printf("  ");

        if (i % 5 == 0)
            printf("\n");
    };

  }