/**
 * Min løsning på oppgave 21
 * @author Martinus Nordgård
 * @date 1. okt 2025
 * @file oppg21.c
 */

 #include <stdio.h>

 // Deklarasjon av funksjoner
 void skrivTid(int time, int min, int sek);

 /**
  * Hovedprogrammet starter her:
  */

  int main()
  {
    printf("\tLets go\n");
    skrivTid(1,0,3);
  }

  void skrivTid (int time, int min, int sek){
    int sekkk = 60;
    printf("\tTiden er nå: ");
    if ( time / 10 > 0){
        printf("%i", time);
    } else {
        printf("0%i", time);
    };

    printf(":");

    if ( min / 10 > 0){
        printf("%i", min);
    } else {
        printf("0%i", min);
    };

    printf(":");

    if ( sek / 10 > 0){
        printf("%i", sek);
    } else {
        printf("0%i", sek);
    };

    sekkk = (3600 * time) + (60 * min) + sek;
    printf(", og dette er faktisk %i sekunder", sekkk);
  }