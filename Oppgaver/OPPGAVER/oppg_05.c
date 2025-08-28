/**
 *   L�sningsforslag til oppgave nr 5.
 *
 *   @file	  OPPG_05.C
 *   @author	Frode Haug, NTNU
 */


#include <stdio.h>                //  printf

/**
 *  Hovedprogrammet:
 */
int main()  {
    int lengde =  8,              //  Definerer og delvis initierer variable:
        bredde = 12,
        hoyde =  16,              //  NB:  ALDRI, ALDRI '�', '�' og '�'
        volum,                    //       i selvp�fundne navn!
        dato = 19600406,
        aar;                      //       ALDRI, ALDRI, ALDRI !!!

    volum = lengde * bredde * hoyde;  //  Beregner volumet.

    printf("Volumet av en firkantet prisme (kloss) med lengde %i, ", lengde);
    printf("bredde %i og hoyde %i er: %i\n\n", bredde, hoyde, volum);
                                      //  Alternativt, om 'volum' IKKE brukes:
    printf("Volumet av en firkantet prisme (kloss) med lengde %i, ", lengde);
    printf("bredde %i og hoyde %i er: %i\n\n", bredde, hoyde, lengde*bredde*hoyde);


    aar = dato / 10000;               //  Henter ut bare �rstallet.
    printf("Datoen %i inneholder aarstallet: %i\n\n", dato, aar);
                                      //  Alternativt, om 'aar' IKKE brukes:
    printf("Datoen %i inneholder aarstallet: %i\n\n", dato, dato / 10000);

    return 0;
}
