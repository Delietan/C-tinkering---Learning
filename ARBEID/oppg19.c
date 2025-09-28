/**
 * Min løsning på oppgave 19
 * @author Martinus Nordgård
 * @date 28 sept
 * @file oppg19.c
 */

 #include <stdio.h>

 const int ANTALLTALLIARRAY = 5; ///<
 const int ANTALLGRUPPERINGER = 5; ///<

/**
 * Hovedprogrammet starter her:
 */

 int main()
 {

    int innlestTall;
    int intArray[ANTALLTALLIARRAY];
    int annenIntArray[ANTALLGRUPPERINGER];

    int intervall1min = 1, intervall1max = 20;
    int intervall2min = 21, intervall2max = 40;
    int intervall3min = 41, intervall3max = 60;
    int intervall4min = 61, intervall4max = 80;
    int intervall5min = 81, intervall5max = 100;

    //initialisering av array
    for (int i = 0; i < ANTALLGRUPPERINGER; i++) {
        annenIntArray[i] = 0;
    };

    
    for (int i = 0; i < ANTALLTALLIARRAY; i++){
        do {
            printf("\tSkriv inn tall nr.%i: ", i+1);
            scanf("%i", &innlestTall);
            intArray[i] = innlestTall;
        } while (innlestTall > 100 || innlestTall < 0);
    }
    printf("\n");

    for (int i = 0; i < ANTALLTALLIARRAY; i++){
        if (intArray[i] >= intervall1min && intArray[i] <= intervall1max){
            annenIntArray[0]++;
        } else if (intArray[i] >= intervall2min && intArray[i] <= intervall2max) {
            annenIntArray[1]++;
        } else if (intArray[i] >= intervall3min && intArray[i] <= intervall3max) {
            annenIntArray[2]++;
        } else if (intArray[i] >= intervall4min && intArray[i] <= intervall4max) {
            annenIntArray[3]++;
        } else if (intArray[i] >= intervall5min && intArray[i] <= intervall5max) {
            annenIntArray[4]++;
        }
    }

    for (int i = 0; i < 1; i++){
        printf("Antall tall i intervallet %3i - %3i: %5i \n", intervall1min, intervall1max, annenIntArray[0]);
        printf("Antall tall i intervallet %3i - %3i: %5i \n", intervall2min, intervall2max, annenIntArray[1]);
        printf("Antall tall i intervallet %3i - %3i: %5i \n", intervall3min, intervall3max, annenIntArray[2]);
        printf("Antall tall i intervallet %3i - %3i: %5i \n", intervall4min, intervall4max, annenIntArray[3]);
        printf("Antall tall i intervallet %3i - %3i: %5i \n", intervall5min, intervall5max, annenIntArray[4]);
    }

 }