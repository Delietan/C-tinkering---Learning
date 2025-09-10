/**
 * Welcome to my code
 * Løsning på oppgave 10 i heftet
 * @author martinus
 * @file oppg10.c
 * lets go
 */

 #include <stdio.h>             // printf()


 /**
  * HOVEDPROGRAMMET LETS GO
  */

  int main ()
  {
    char tegn1, tegn2;

    float flyt1, flyt2;

    int intVar1, intVar2;

    tegn1 = 'F';
    tegn2 = 'H';

    flyt1 = 17.52;
    flyt2 = 451.87;

    printf("LETS GO %f %f %c %c\n\n", flyt2, flyt1, tegn2, tegn1);
    printf("LETS GO %e \n\n", flyt2);

    printf("LETS GO %i %i \n\n", (int) flyt1, (int) flyt2);

    // dette kommer antakeligvis ut som ASCII tegn. A er 60 of F er 70.
    printf("LETS GO %i  \n\n", (int) tegn1);

    printf("dette er en b på ascii: %i", (int) 'b');

    // intVar1 = flyt1;
    // intVar2 = flyt2;
    // printf("LETS GO %i %i \n\n", intVar1, intVar2);

    return 0;
  };