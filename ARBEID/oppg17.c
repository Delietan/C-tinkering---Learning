/**
 * Min løsning på oppgave 17
 * @author Martinus Nordgård
 * @file oppg17.c
 * @date 28. sept
 */

#include <stdio.h>

const int MAXLOPERE = 10;
const int antallEgenskaper = 3;

/**
 * Hovedprogrammer starter her
 */

 int main(){

    char vilDuKjore = 'a';

    do {
        int distanse, inputtaDistanse;
        int antallFemhundremetre;
        int inputtaLopere;
        int i, j;
        int inputtaMin, inputtaSek, inputtaCenti;
        float poeng;

        //innlesning av distanse
        do {
            printf("Skriv ønsket distanse: ");
            scanf("%i", &inputtaDistanse);
        } while (inputtaDistanse != 500 && inputtaDistanse != 1500 &&
                inputtaDistanse != 3000 && inputtaDistanse != 5000 );
        distanse = inputtaDistanse;

        //poengberegning
        antallFemhundremetre = inputtaDistanse / 500;

        printf("Distanse: %i", distanse);
        printf("\nAntall 500-metere: %i", antallFemhundremetre);

        //******************************************************************************

        // innlesning av antall løpere
        do {
            printf("\nSkriv antall løpere: ");
            scanf("%i", &inputtaLopere);
        } while (inputtaLopere < 1 || inputtaLopere > MAXLOPERE);
        int antallLopere = inputtaLopere;
        int loperArray[antallLopere][antallEgenskaper];

        //************************************************************************

        //tildeling av tider til hver løper

        for (i = 0; i < inputtaLopere; i++){
            do {
                printf("Skriv minutter brukt for løper nr.%i: ", i+1);
                scanf("%i", &inputtaMin);
            } while (60 < inputtaMin || inputtaMin < 0);

            do {
                printf("Skriv sekunder brukt for løper nr.%i: ", i+1);
                scanf("%i", &inputtaSek);
            } while (59 < inputtaSek || inputtaSek < 0);

            do {
                printf("Skriv hundredeler brukt for løper nr.%i: ", i+1);
                scanf("%i", &inputtaCenti);
            } while (99 < inputtaCenti || inputtaCenti < 0);

            loperArray[i][0] = inputtaMin;
            loperArray[i][1] = inputtaSek;
            loperArray[i][2] = inputtaCenti;
            
            printf("\n");
        };

        //****************************************************************************

        //poengtildeling
        //utskrift av tider
        for (i = 0; i < antallLopere; i++){
            printf("Løper %i. fikk tid: ", i+1);
            for (j = 0; j < antallEgenskaper; j++){
                printf("%i ", loperArray[i][j]);
            };
            poeng = ((loperArray[i][0]*60) + loperArray[i][1] + (loperArray[i][2]/100)) / antallFemhundremetre;
            printf("og poengscore: %.3f", poeng);
            printf("\n");
        };

        printf("\nProgrammet avsluttes...");
        printf("\nVaribler nullstilles...");
        printf("\nVil du kjøre på nytt? (J/n) ");
        scanf(" %c", &vilDuKjore);
    } while (vilDuKjore == 'J' || vilDuKjore == 'j');
 }