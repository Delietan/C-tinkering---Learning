/**
 * @author Martinus Nordgård
 * @date 9. sept 2025
 * @file oppg11.c
 * 
 */


 #include <stdio.h> // printf()

 /**
  *  Hovedprogrammet starter her!
  */


  int main ()
  {
    int tall[5];
    int tall2[] = {6, 2, 10, 12, 19, 3, 7};

    char tekst[5];
    char navn[] = "Lars Hansen";
    char adresse[] = "Ringgata 111";

    tall[0] = 13;
    tall[1] = 67;
    
    tall[2] = tall[0] + tall[1];

    printf("%i\n\n", tall[2]);
    printf("%i\n\n", tall[2] / 2);

    tall[3] = tall2[0] + tall2[1] + tall2[2] + tall2[3];
    printf("test test %i\n\n", tall[3]);

    tall[4] = tall2[4] + tall2[5] + tall2[6];
    printf("printer %i\n", tall[4]);

    printf("to siste %i %i\n\n", tall[3], tall[4]);

    tall[2]++,  tall[2]++, ++tall[2], ++tall[2],

    printf("etter oppdatering %i\n\n", tall[2]);

    tekst[1] = 'A';
    tekst[3] = 'E';
    tekst[0] = navn[5];
    tekst[2] = navn[0];

    printf("Kua har %c%c%c%c\n", tekst[0], tekst[1], tekst[2], tekst[3]);
    printf("%c%c%c", adresse[9], adresse[10], adresse[11]);
    printf("\n%s", navn);
    printf("\n%s", adresse);
  }