/**
 * 
 * Oblig 2 - Min løsning
 * @author Martinus Nordgård
 * @date 28. sept 2025
 * @file oblig2.c
 * 
 */

 #include <stdio.h>             //printf, scanf
 #include <stdbool.h>           //bool
 #include <string.h>            //strcpy
 #include <ctype.h>             //toupper

 const int MAXBANER = 18; ///<
 const int STRLEN = 100; ///<

 /**
  * Hovedprogrammet starter her:
  */

  int main () 
  {
    char baneBeskrivelse[MAXBANER][STRLEN];     // Beskrivelse av banene
    int  baneLengde[MAXBANER];                  // Banens lengde i meter (i meter)
    int  banePar[MAXBANER];                     // Forventet antall kast (par)
                                                // for hver enkelt bane.

    bool baneOB[MAXBANER];                      // Har banene OB eller ei.

    int antallBaner;                            // Antall baner pr.nå.
    char valg;                                  // Brukerens valg (L, S, Q)

    char inputOB;                               // Brukes i scanf()
    int  inputPar;                              // Brukes i scanf()
    int  inputLengde;                           // Brukes i scanf()  
    int  sumForPar;                             // Totalsummen for par

    //*****************************************************************

    //Hardkoding av bane 1 og 2
    // Bane 1
    strcpy(baneBeskrivelse[0], "Bane med mange trær og kratt.");
           baneLengde[0]       = 62;
           banePar[0]          = 3;
           baneOB[0]           = true;
           antallBaner = 1;

    // Bane 2
    strcpy(baneBeskrivelse[1], "Flatt terreng gjennom hele banen");
           baneLengde[1]       = 93;
           banePar[1]          = 3;
           baneOB[1]           = false;
           antallBaner++;

    //*****************************************************************

    //Viser meny
    printf("\n\nMenyvalg: \n\tL - Legg til bane\n\tS - Se alle baner\n\tQ - Avslutt");
    printf("\n\tValg: ");
    scanf(" %c", &valg);
    valg = toupper(valg);

    
    while (valg != 'Q') {        
        switch (valg) {
            
            case 'L':
                if (antallBaner < MAXBANER) {
                    int i = antallBaner;
                    printf("\n\tDu skrev L - Du har valgt å legge til en bane\n\n");

                    // Kontrollerer lovlig verdi for banens lengde
                    do {
                        printf("Hvor lang er den %i. banen (0 = cancel): ", i+1);
                        scanf("%i", &inputLengde);
                    } while (inputLengde < 0);
                    if (inputLengde == 0) {
                        printf("\n\t0 registrert -Tilordning AVBRYTES");
                        break;
                    }
                    baneLengde[i] = inputLengde;

                    // Kontrollerer lovlig verdi for par på banen
                    do {
                        printf("Par på banen (2-8): ");
                        scanf("%i", &inputPar);
                    } while (inputPar < 2 || inputPar > 8);
                    banePar[i] = inputPar;

                    // Kontrollerer lovlig boolsk verdi på bane-OB
                    do {
                        printf("Har banen OB (J/N): ");
                        scanf(" %c", &inputOB);
                        inputOB = toupper(inputOB);
                    } while (inputOB != 'J' && inputOB != 'N');
                    baneOB[i] = (inputOB == 'J'); // True hvis 'J', False hvis ikke

                    // Tømmer inputbufferen før gets()
                    getchar();

                    // Henter banebeskrivelse
                    printf("Banebeskrivelse: ");
                    gets(baneBeskrivelse[i]);

                    antallBaner++;
                    printf("\nBane ble lagt til.");
                } else {
                    printf("\n\tKan ikke legge til bane. Maxen på %i er nådd", MAXBANER);
                }
                break;

            case 'S':
                //gir brukeres oversikt over alle baner
                printf("\n\tDu skrev S - Du har valgt å se alle baner");
                for (int i = 0; i < antallBaner; i++) {
                    printf("\n\nBane %i:", i+1);
                    printf("\n\tLengde: %i meter", baneLengde[i]);
                    printf("\n\tPar: %i\n\t", banePar[i]);
                    baneOB[i] == true ? printf("Med OB") : printf("Uten OB");
                    printf("\n\tBeskrivelse: %s", baneBeskrivelse[i]);
                };

                //utregning av par
                sumForPar = 0;
                for (int i = 0; i < antallBaner; i++) {
                    sumForPar += banePar[i];
                }

                //printer ut oppsummering på slutten av oversikten
                printf("\n\nAntall baner: %i", antallBaner);
                printf("\nFor å havne på par brukes %i kast", sumForPar);
                break;

            default :  
                printf("\n\tUgyldig kommand - Prøv igjen");
                break;
        }


    printf("\n\nMenyvalg: \n\tL Legg til bane\n\tS - Se alle baner\n\tQ - Avslutt");
    printf("\n\tValg: ");
    scanf(" %c", &valg);
    valg = toupper(valg);
    }

    printf("\n\t- Programmet er avsluttet -");

    return 0;
  };