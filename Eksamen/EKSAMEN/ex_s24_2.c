/**
 *   Løsningsforslag til eksamen i GrProg (i C), august 2024, oppgave 2.
 *
 *   Programmet holder orden på EN klubbs resultater i ulike kamper,
 *   mot (u)like motstandere, samt alle egne målscorere i disse kampene.
 *
 *   @file     EX_S24_2.C
 *   @author   Frode Haug, NTNU
 */


#include <stdio.h>               //  printf, FILE
#include <stdlib.h>              //  sizeof, malloc
#include <string.h>              //  strcpy, strlen, strcmp
#include "LesData.h"             //  Verktøykasse for lesing av diverse data


#define   MAXSCORERE       10    ///<  Max. antall målscorere i EN kamp.
#define   MAXKAMPER        40    ///<  Max. antall kamper å registrere.
#define   STRLEN           20    ///<  Max. tekstlengde.
const int MAXMAAL =        40;   ///<  Max. antall mål scoret/sluppet inn.


/**
 *  Kamp (med motstanders navn, antall scorede/innslupne mål og målscorerne).
 */
struct Kamp  {                   //  En kamps:
  char* navn;                    //    - motstandernavn
  int   antFor, antMot;          //    - antall mål scoret og innsluppet
  int   antScorere;              //    - antall målscorere
  char* scorere[MAXSCORERE];     //    - UNIKT ett-ords fornavn på målscorerne
  int   antall[MAXSCORERE];      //    - antall mål scoret av nr. 'i'
};


void skrivMeny();                                              //  Ferdiglaget
void skrivAlleResultater();                                    //  Oppgave 2A
void kampSkrivResultat(const struct Kamp* kamp);               //  Oppgave 2A
void skrivEttResultat();                                       //  Oppgave 2B
void kampSkrivAlt(const struct Kamp* kamp);                    //  Oppgave 2B
void registrerResultat();                                      //  Oppgave 2C
void kampRegistrerResultat(struct Kamp* kamp);                 //  Oppgave 2C
void beregnPoengsumOgMaal();                                   //  Oppgave 2D
void kampHent(const struct Kamp* kamp, int* maalFor, int* maalMot); //Oppg.2D
void beregnPoengsumOgMaal2();                                  //  Oppgave 2E
void skrivToppscorere();                                       //  Oppgave 2F
void lesFraFil();                                              //  Oppgave 2G
void kampLesFraFil(FILE* inn, struct Kamp* kamp);              //  Oppgave 2G


int    gAntallKamper = 0;           ///<  Antall kamper hittil registrert.
struct Kamp* gKamper[MAXKAMPER];    ///<  Alle kampene i registeret.


/**
 *  Hovedprogrammet:
 */
int main()  {
  char kommando;

  lesFraFil();                                              //  Oppgave 2G

  skrivMeny();
  kommando = lesChar("\nValg");

  while (kommando != 'Q') {
    switch (kommando) {
      case 'A':  skrivAlleResultater();      break;    //  Oppgave 2A
      case 'E':  skrivEttResultat();         break;    //  Oppgave 2B
      case 'R':  registrerResultat();        break;    //  Oppgave 2C
      case 'B':  beregnPoengsumOgMaal();     break;    //  Oppgave 2D
      case 'T':  beregnPoengsumOgMaal2();    break;    //  Oppgave 2E
      case 'S':  skrivToppscorere();         break;    //  Oppgave 2F
      default:   skrivMeny();                break;
    }
    kommando = lesChar("\nValg");
  }

  return 0;
}


/**
 *  Skriver/presenterer programmets muligheter/valg for brukeren.
 */
void skrivMeny() {
  printf("\nFOLGENDE KOMMANDOER ER LOVLIG:\n");
  printf("\tA   = skriv noe om Alle kampene/resultatene\n");
  printf("\tE   = skriv alt om En kamp/resultat\n");
  printf("\tR   = Registrer resultatet for en kamp\n");
  printf("\tB   = Beregn og skriv total poengsum og antall maal for/imot\n");
  printf("\tT   = beregn og skriv alt paa en Tabellinje\n");
  printf("\tS   = finn og skriv toppScoreren(e)\n");
  printf("\tQ   = Quit/avslutt\n");
}


/**
 *  Oppgave 2A - Skriver ALLE kampene og resultatene fra disse.
 *
 *  @see   kampSkrivResultat(...)
 */
void skrivAlleResultater()  {
  printf("\n\tAlle kampene og deres resultater:\n");
  for (int i = 0;  i < gAntallKamper;  i++)  {
      printf("\t\tKamp nr.%2i:   ", i+1);
      kampSkrivResultat(gKamper[i]);         //  Hver skriver seg selv.
  }
}


/**
 *  Oppgave 2A - Skriver motstandernavn og antall scorede/innslupne kampmål.
 *
 *  @param  kamp  -  Kampen det skrives ut noen data for
 */
void kampSkrivResultat(const struct Kamp* kamp)  {
  printf("%-20s  %i - %i\n", kamp->navn, kamp->antFor, kamp->antMot);
}


/**
 *  Oppgave 2B - Skriver ALT om EN gitt kamp.
 *
 *  @see   kampSkrivAlt(...)
 */
void skrivEttResultat()  {
  int nr;

  if (gAntallKamper > 0)  {
     nr = lesInt("\tKampnummer", 1, gAntallKamper);
     kampSkrivAlt(gKamper[nr-1]);             //  ALT om aktuell kamp skrives.
  } else                                      //  Ingen resultat finnes:
    printf("\n\tIngen kamper/resultater ennaa registrert!\n\n");
}


/**
 *  Oppgave 2B - Skriver ALT om en kamp.
 *
 *  @param  kamp  -  Kampen det skrives ut ALT om
 *  @see    kampSkrivResultat(...)
 */
void kampSkrivAlt(const struct Kamp* kamp)  {
  printf("\n\t");
  kampSkrivResultat(kamp);                    //  Skriver HOVEDdataene:
  printf("\tEgne maalscorere var:\n");
  if (kamp->antFor > 0)  {                    //  Har selv scoret mål:
     for (int i = 0;  i <  kamp->antScorere;  i++)  //  Scorerne skrives:
         printf("\t\t%-20s med %i maal\n", kamp->scorere[i], kamp->antall[i]);
  } else
     printf("\t\tIngen (selvsagt)\n");
}


/**
 *  Oppgave 2C - Legger (om mulig) inn en ny kamp inn i datastrukturen.
 *
 *  @see   kampRegistrerResultat(...)
 */
void registrerResultat()  {
 if (gAntallKamper < MAXKAMPER)  {      //  Plass til flere kamper:
    gKamper[gAntallKamper] = (struct Kamp*) malloc(sizeof(struct Kamp));
                                        //  Kampens data leses, antallet økes:
    kampRegistrerResultat(gKamper[gAntallKamper++]);
 } else                                 //  Fullt:
     printf("\n\tFullt med %i kamper allerede!\n\n", MAXKAMPER);
}


/**
 *  Oppgave 2C - Leser inn ALT om EN kamp sine resultater.
 *
 *  @param   kamp  -  Kampen det leses inn alle data for
 */
void kampRegistrerResultat(struct Kamp* kamp)  {
  int  antall = 0;                  //  Holder orden på antall scorede mål.
                                    //  Leser og lagrer unna data om kampen:
  kamp->navn   = lagOgLesText("\tMotstanderlagets navn:  ");
  kamp->antFor = lesInt("\tAntall maal selv scoret", 0, MAXMAAL);
  kamp->antMot = lesInt("\tAntall maal innslupet  ", 0, MAXMAAL);
  if (kamp->antFor > 0)  {          //  Har selv scoret mål:
     kamp->antScorere =             //  Leser antall ulike målscorere:
                   lesInt("\tAntall ulike egne maalscorere", 1, kamp->antFor);
     for (int i = 0;  i < kamp->antScorere;  i++)  { // Lagrer målscorers navn:
       kamp->scorere[i] = lagOgLesText("\tMaalscorer sitt navn:    ");
       kamp->antall[i]  = lesInt("\t\tAntall maal", 1, kamp->antFor-antall);
       antall += kamp->antall[i];    //  Teller opp antallet selv scoret.
     }
  } else
    kamp->antScorere = 0;           //  Ingen mål scoret - ingen målscorere.
}


/**
 *  Oppgave 2D - Regner og skriver ut TOTALpoengsum og ALLE målene for laget.
 *
 *  @see  kampHent(...)
 */
void beregnPoengsumOgMaal()  {
  int sumPoeng = 0, sumFor = 0, sumMot = 0, antFor, antMot;

  for (int i = 0;  i < gAntallKamper;  i++)  {
      kampHent(gKamper[i], &antFor, &antMot); //  Henter mål for og imot.
      sumFor += antFor;   sumMot += antMot;   //  Teller opp totalen for dette.
      if (antFor > antMot)  sumPoeng += 3;    //  Vunnet:   +3 poeng
      else if (antFor == antMot)  sumPoeng++; //  Uavgjort: +1 poeng
  }
  printf("\n\tPoengsum totalt:             %3i\n", sumPoeng);
  printf("\tAntall maal totalt scoret:     %3i\n", sumFor);
  printf("\tAntall maal totalt innsluppet: %3i\n", sumMot);
}


/**
 *  Oppgave 2D - Henter antall scorede/innslupne mål i en gitt kamp.
 *
 *  @param   kamp      -  Kampen det skal hentes scorede/innslupne mål fra
 *  @param   maalFor   -  Antall mål selv scoret ("referanseoverført")
 *  @param   maalMot   -  Antall mål innslupet ("referanseoverført")
 */
void kampHent(const struct Kamp* kamp, int* maalFor, int* maalMot)  {
  *maalFor = kamp->antFor;
  *maalMot = kamp->antMot;
}


/**
 *  Oppgave 2E - Lager en "tabellinje" for laget.
 *
 *  @see  kampHent(...)
 */
void beregnPoengsumOgMaal2()  {
  int sumPoeng = 0, sumFor = 0, sumMot = 0, antFor, antMot;
  int sumV = 0, sumU = 0, sumT = 0;                   //  NYTT  ift. 2D

  for (int i = 0;  i < gAntallKamper;  i++)  {
      kampHent(gKamper[i], &antFor, &antMot);
      sumFor += antFor;   sumMot += antMot;
      if (antFor > antMot) {
         sumPoeng +=3;
         sumV++;                                      //  NYTT  ift. 2D
      }
      else if (antFor == antMot) {
         sumPoeng++;
         sumU++;                                      //  NYTT  ift. 2D
      } else                                          //  NYTT  ift. 2D
         sumT++;                                      //  NYTT  ift. 2D

  }                                                   //  3x linjer som
  printf("\n\t  K   V   U   T   Maal   Poeng\n");     //    erstatter 3x siste
  printf("\t%3i %3i %3i %3i %3i - %-3i %3i\n", gAntallKamper, // printf i 2D:
                 sumV, sumU, sumT, sumFor, sumMot, sumPoeng);
}


/**
 *  Oppgave 2F - Teller opp og finner navnet til lagets toppscorer(e).
 */
void skrivToppscorere()  {
  int  totalScore[MAXSCORERE*3];             //  Totale mål for scorerne.
  char navn[MAXSCORERE*3][STRLEN],           //  De ulike målscorernes navn.
       buffer[STRLEN];                       //  Kopi av EN spillers navn.

                                             //  'antNavn' er antall ULIKE
                                             //    målscorere:
                                             //  'storst' er flest mål hittil.
  int i, j, k, antScorere, antNavn = 0, storst = 0;
                                             //  MEGET VIKTIG at nullstiller!:
  for (k = 0;  k < MAXSCORERE*3;  k++)  totalScore[k] = 0;

  for (i = 0;  i < gAntallKamper;  i++)  {  // Går gjennom alle kampene:
      antScorere = gKamper[i]->antScorere;  // Henter antall scorere i EN kamp.
      for (j = 0;  j < antScorere;  j++)  { // Går gjennom alle kampens scorere:
          strcpy(buffer, gKamper[i]->scorere[j]);  //  Henter aktuelt navn.
          for (k = 0;  k < antNavn;  k++)          //  Lagret dette navnet?
              if (!strcmp(navn[k], buffer)) break; //  Ja!
          if (k == antNavn)                        //  Nei:
             strcpy(navn[antNavn++], buffer);      //  Lagrer navnet bakerst.
          totalScore[k] += gKamper[i]->antall[j];  //  Teller opp totalscore
                                                   //    for DEN spilleren.
          if (totalScore[k] > storst)  storst = totalScore[k]; // Ny rekord?
      }
  }

  printf("\n\tStorste TOTALscore er %i maal. Dette er utfort av:\n\t\t", storst);
  for (j = 0;  j < antNavn;  j++)          //  Går igjennom alle målscorere:
      if (totalScore[j] == storst)         //  Er en toppscorer.
         printf("%s   ",  navn[j]);        //  Skriver vedkommendes navn.
  printf("\n\n");
}


/**
 *  Oppgave 2G - Leser ALLE kampene/resultatene inn fra fil.
 *
 *  @see   kampLesFraFil(...)
 */
void lesFraFil()  {
  FILE* innfil  = fopen("EX_S24_KAMPER.DTA", "r");   //  Åpner aktuell fil:

  if (innfil) {                                      //  Filen finnes:
     fscanf(innfil, "%i", &gAntallKamper);  //  Leser antall kamper.
     getc(innfil);                          //  Leser avsluttende '\n'.
                                            //  Alle resultater lages og leses:
     for (int i = 0;  i < gAntallKamper;  i++) {
       gKamper[i] = (struct Kamp*) malloc(sizeof(struct Kamp));
       kampLesFraFil(innfil, gKamper[i]);     // Leser selv.
     }
     printf("\n\n\tResultater er lest inn fra 'EX_S24_KAMPER.DTA'!\n\n");
  } else                                       //  Filen ikke funnet:
     printf("\n\tFant ikke filen 'EX_S24_KAMPER.DTA'!\n\n");

  fclose(innfil);                              //  Lukker åpen fil.
}


/**
 *  Oppgave 2G - Leser ALT om EN kamp inn fra fil.
 *
 *  @param  inn   -  Filen det skal leses inn fra
 *  @param  kamp  -  Kampen som får innlest sine data
 */
void kampLesFraFil(FILE* inn, struct Kamp* kamp)  {
  char buffer[STRLEN];
  fscanf(inn, "%s", buffer);
  kamp->navn = (char*) malloc((strlen(buffer) + 1) * sizeof(char));
  strcpy(kamp->navn, buffer);       //  Lagrer unna motstanders navn.
                                    //  Leser antall scorede og innslupne mål:
  fscanf(inn, "%i %i", &(kamp->antFor), &(kamp->antMot));
  fscanf(inn, "%i", &(kamp->antScorere));         //  Leser antall målscorere.
  for (int i = 0;  i < kamp->antScorere;  i++)  {
      fscanf(inn, "%s", buffer);                  //  Leser målscorers navn,
      kamp->scorere[i] = (char*) malloc((strlen(buffer) + 1) * sizeof(char));
      strcpy(kamp->scorere[i], buffer);
      fscanf(inn, "%i", &(kamp->antall[i]));      //    og antall scorede mål.
  }
  getc(inn);                                 //  Forkaster avsluttende '\n'.
}
