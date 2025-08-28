/**
 *   Løsningsforslag til eksamen i GrProg (i C), desember 2024, oppgave 2.
 *
 *   Programmet holder orden på ulike havner og (båt)rutene som går innom
 *   de ulike havnene.
 *
 *   @file     EX_H24_2.C
 *   @author   Frode Haug, NTNU
 */


#include <stdio.h>               //  printf, FILE
#include <stdbool.h>             //  bool
#include <stdlib.h>              //  sizeof, malloc
#include <string.h>              //  strcpy, strlen, strcmp
#include "LesData.h"             //  Verktøykasse for lesing av diverse data


#define   MAXHAVNER       100    ///<  Max. antall ulike havner.
#define   MAXRUTER        100    ///<  Max. antall ulike båtruter.
#define   MAXINNOM         20    ///<  Max. antall havneanløp på EN båtrute.
#define   STRLEN           80    ///<  Max. tekstlengde.
#define   DAGER             7    ///<  Antall dager i en uke.

                                 ///<  Ukedagenes navn.
char dagnavn[DAGER][5] = { "Man", "Tirs", "Ons", "Tors", "Fre", "Lor", "Son" };


/**
 *  Havn (med havnas navn, og evt. øynavnet den ligger på).
 */
struct Havn  {
  char* navn;                    //  Havnas navn.
  char* oy;                      //  Øynavnet havna ligger på - OM DETTE ER
};                               //   ULIKT HAVNENAVNET, ELLERS ER DEN 'NULL'.


/**
 *  Rute (med båtens navn, lengde, plass til antall biler og personer, antall
 *        havner ruten er innom og indeksen i 'gHavner' for disse havnene,
 *        samt hvilke ukedager ruten er innom disse havnene).
 */
struct Rute  {
  char* baatnavn;
  int   lengde, antBiler, antPersoner;
  int   antallHavner;
  int   havnene[MAXINNOM];
  bool  dag[DAGER];
};


int  finnHavn(const char* nvn);                                //  Ferdig-
void skrivMeny();                                              //   laget.
void skrivAlleHavner();                                        //  Oppgave 2A
void havnSkrivData(const struct Havn* havn);                   //  Oppgave 2A
void skrivAlleRuter();                                         //  Oppgave 2B
void ruteSkrivData(const struct Rute* rute);                   //  Oppgave 2B
void skrivAltOmEnRute();                                       //  Oppgave 2C
void ruteSkrivAlt(const struct Rute* rute);                    //  Oppgave 2C
void nyHavn();                                                 //  Oppgave 2D
void havnLesData(struct Havn* havn, char* nvn);                //  Oppgave 2D
void nyRute();                                                 //  Oppgave 2E
void ruteLesData(struct Rute* rute);                           //  Oppgave 2E
void mestTravleHavn();                                         //  Oppgave 2F
void ruteTellAnlop(const struct Rute* rute, int antall[]);     //  Oppgave 2F
void lesRuterFraFil();                                         //  Oppgave 2G
void ruteLesFraFil(FILE* inn, struct Rute* rute);              //  Oppgave 2G
void lesHavnerFraFil();                                        //  EXTRA
void havnLesFraFil(FILE* inn, struct Havn* havn);              //  EXTRA


int    gAntallHavner = 0,             ///<  Antall havner hittil registrert.
       gAntallRuter  = 0;             ///<  Antall båtruter hittil registrert.
struct Havn* gHavner[MAXHAVNER];      ///<  Alle havner i registeret.
struct Rute* gRuter[MAXRUTER];        ///<  Alle havner i registeret.


/**
 *  Hovedprogrammet.
 */
int main()  {
  char kommando;

  lesRuterFraFil();                                         //  Oppgave 2G
  lesHavnerFraFil();                                        //  EXTRA

  skrivMeny();
  kommando = lesChar("\nValg");

  while (kommando != 'Q') {
    switch (kommando) {
      case 'H':  skrivAlleHavner();          break;         //  Oppgave 2A
      case 'R':  skrivAlleRuter();           break;         //  Oppgave 2B
      case 'E':  skrivAltOmEnRute();         break;         //  Oppgave 2C
      case 'N':  nyHavn();                   break;         //  Oppgave 2D
      case 'U':  nyRute();                   break;         //  Oppgave 2E
      case 'T':  mestTravleHavn();           break;         //  Oppgave 2F
      default:   skrivMeny();                break;
    }
    kommando = lesChar("\nValg");
  }

//  skrivRuterTilFil();                                     //  Ikke laget
//  skrivHavnerTilFil();                                    //  Ikke laget

  return 0;
}


/**
 *  Prøver å finne indeksen i 'gHavner' for en navngitt havn.
 *
 *  @param   nvn  - Søkt havns navn
 *  @return  Indeksen for havnen, evt. -1 om ikke ble funnet
 */
int finnHavn(const char* nvn)  {
  for (int i = 0;  i < gAntallHavner;  i++)
      if (!strcmp(gHavner[i]->navn, nvn))  return i;   //  Funn/match!

  return -1;                           //  Ikke funnet noen med dette 'nvn'.
}


/**
 *  Skriver/presenterer programmets muligheter/valg for brukeren.
 */
void skrivMeny() {
  printf("\nFOLGENDE KOMMANDOER ER LOVLIG:\n");
  printf("\tH   = skriv alle Havner\n");
  printf("\tR   = skriv alle Ruter\n");
  printf("\tE   = skriv En rute\n");
  printf("\tN   = Ny havn\n");
  printf("\tU   = ny rUte\n");
  printf("\tT   = mest Travle havn\n");
  printf("\tQ   = Quit/avslutt\n");
}


/**
 *  Oppgave 2A - Skriver ALLE havnene (og om ulikt: øynavnet).
 *
 *  @see   havnSkrivData(...)
 */
void skrivAlleHavner()  {
  printf("\n\tAlle havnene (og evt. oyene de ligger paa):\n");
  for (int i = 0;  i < gAntallHavner;  i++)  {
      printf("\t\t%3i:   ", i+1);
      havnSkrivData(gHavner[i]);         //  Hver skriver seg selv.
  }
}


/**
 *  Oppgave 2A - Skriver havnenavn og om ulikt: øynavnet.
 *
 *  @param  havn  -  Havnen det skrives ut noen data for
 */
void havnSkrivData(const struct Havn* havn)  {
  printf("%-20s", havn->navn);
  if (havn->oy != NULL) printf("%s", havn->oy);  //  Øynavn ulikt havnenavn:
  printf("\n");                                  //    Skrives derfor ut.
}


/**
 *  Oppgave 2B - Skriver ALLE rutene.
 *
 *  @see   ruteSkrivData(...)
 */
void skrivAlleRuter()  {
  printf("\n\tAlle rutene:\n");
  for (int i = 0;  i < gAntallRuter;  i++)  {
      printf("\t\t%3i:   ", i+1);
      ruteSkrivData(gRuter[i]);         //  Hver skriver seg selv.
  }
}


/**
 *  Oppgave 2B - Skriver båtnavn og antall havner ruten er innom.
 *
 *  @param  rute  -  Ruten det skrives ut noen data for
 */
void ruteSkrivData(const struct Rute* rute) {
  printf("%-20s  gaar innom %2i havner\n", rute->baatnavn, rute->antallHavner);
}


/**
 *  Oppgave 2C - Skriver ALT om EN gitt rute.
 *
 *  @see   ruteSkrivAlt(...)
 */
void skrivAltOmEnRute()  {
  int nr;

  if (gAntallRuter > 0)  {
     nr = lesInt("\tRutenummer", 1, gAntallRuter);
     ruteSkrivAlt(gRuter[nr-1]);              //  ALT om aktuell rute skrives.
  } else                                      //  Ingen ruter finnes:
    printf("\n\tIngen ruter ennaa registrert!\n\n");
}


/**
 *  Oppgave 2C - Skriver ALT om en rute.
 *
 *  @param  rute  -  Ruten det skrives ut ALT om
 *  @see    ruteSkrivData(...)
 *  @see    havnSkrivData(...)
 */
void ruteSkrivAlt(const struct Rute* rute)  {
  printf("\n\t");
  ruteSkrivData(rute);                        //  Båtnavn og antall havner.
  printf("\tsom er:\n");
  for (int i = 0;  i < rute->antallHavner;  i++)  {  // Skriver ALLE havnenes
      printf("\t\t");                                //   navn som ruten er
      havnSkrivData(gHavner[rute->havnene[i]]);      //   innom:
  }
  printf("\tDisse er den innom paa:  ");      //  Skriver dagene ruten er
  for (int i = 0;  i < DAGER;  i++)           //    innom havnene:
      if (rute->dag[i])  printf("%sdag  ", dagnavn[i]);
                                              //  Skriver resten av dataene:
  printf("\n\tBaaten er %i meter lang, tar %i biler og %i passasjerer.\n\n",
         rute->lengde, rute->antBiler, rute->antPersoner);
}


/**
 *  Oppgave 2D - Legger (om mulig) en ny havn inn i datastrukturen.
 *
 *  @see   havnLesData(...)
 */
void nyHavn()  {
  char* navn;

  if (gAntallHavner < MAXHAVNER)  {     //  Plass til flere havner:
     navn = lagOgLesText("\tNy havns navn");
     if (finnHavn(navn) == -1)  {       //  Finnes IKKE fra før:
        gHavner[gAntallHavner] = (struct Havn*) malloc(sizeof(struct Havn));
                                 //  Havnens data settes/leses, antallet økes:
        havnLesData(gHavner[gAntallHavner++], navn);
     } else  {                          //  Finnes fra før:
        printf("\n\tFinnes en havn allerede med dette navnet!\n\n");
        free(navn);                     //  Skal IKKE lagres: FRIGIR MEMORY!
     }
  } else                                //  Fullt:
     printf("\n\tFullt med %i havner allerede!\n\n", MAXHAVNER);
}


/**
 *  Oppgave 2D - Leser inn ALT om EN havn.
 *
 *  @param   havn  -  Havnen det leses inn alle data for
 *  @param   nvn   -  Havnens allerede innleste og memoryallokerte navn
 */
void havnLesData(struct Havn* havn, char* nvn)  {
  havn->navn = nvn;                 //  Lagrer unna allerede innlest navn.
  havn->oy =   lagOgLesText("\tOynavn (kun ENTER om likt havnenavnet)");
                                    //  Intet øynavn:  FRIGIR ALLOKERT MEMORY,
                                    //     og NULLSTILLER pekeren:
  if (strlen(havn->oy) == 0)  {  free(havn->oy);  havn->oy = NULL;  }
}


/**
 *  Oppgave 2E - Legger (om mulig) en ny rute inn i datastrukturen.
 *
 *  @see   ruteLesData(...)
 */
void nyRute()  {
  if (gAntallRuter < MAXRUTER)  {   //  Plass til flere ruter:
     gRuter[gAntallRuter] = (struct Rute*) malloc(sizeof(struct Rute));
                                    //  ALLE rutens data leses, antallet økes:
     ruteLesData(gRuter[gAntallRuter++]);
  } else                            //  Fullt:
     printf("\n\tFullt med %i ruter allerede!\n\n", MAXRUTER);
}


/**
 *  Oppgave 2E - Leser inn ALT om EN rute.
 *
 *  @param   rute  -  Ruten det leses inn alle data for
 */
void ruteLesData(struct Rute* rute)  {
  char buffer[STRLEN];
  int n = 0, nr;
                                              //  Leser inn relevante data:
  rute->baatnavn     = lagOgLesText("\tNy rutes baatnavn");
  rute->lengde       = lesInt("\tBaatens lengde", 30, 200);
  rute->antBiler     = lesInt("\tPlass til antall biler", 20, 200);
  rute->antPersoner  = lesInt("\tPlass til antall passasjerer", 100, 1000);
  rute->antallHavner = lesInt("\tAntall havner ruten er innom", 3, MAXINNOM);
  do  {                                       //  Leser og lagrer LOVLIGE
    printf("\tHavn nr.%i", n+1);              //   havnenavn ruter er innom:
    lesText(" sitt navn", buffer, STRLEN);
    if ((nr = finnHavn(buffer)) != -1)        //  Havnen finnes, og dets
       rute->havnene[n++] = nr;               //    indeks lagres unna.
    else
       printf("\t\tHavnen finnes ikke!\n");
  } while (n < rute->antallHavner-1);         //  Leser TIL siste havnen,
                                              //    som settes til den første:
  printf("\tHavn nr.%i blir automatisk lik den forste.\n", n+1);
  rute->havnene[n] = rute->havnene[0];

  printf("\n\tHvilke ukedager kjores denne ruten:\n"); // Leser og registrerer
  for (int i = 0;  i < DAGER;  i++)  {                 //  hvilke dager ruten
      printf("\t\t%s", dagnavn[i]);                    //  er innom alle disse
      rute->dag[i] = (lesChar("dag (J/n)") != 'N');    //  havnene.
  }
}


/**
 *  Oppgave 2F - Finner og skriver havnen(e) med flest båtanløp.
 *
 *  @see   ruteTellAnlop(...)
 *  @see   havnSkrivData(...)
 */
void mestTravleHavn()  {
  int i, flest = 0, antallAnlop[MAXHAVNER];
                                               //  Nullstiller antall anløp i
  for (i = 0;  i < gAntallHavner;  i++)  antallAnlop[i] = 0;   //  hver havn.

  for (i = 0;  i < gAntallRuter;  i++)         //  Får telt opp antall anløp
      ruteTellAnlop(gRuter[i], antallAnlop);   //    for HVER RUTE.

  for (i = 0;  i < gAntallHavner;  i++)        //  Finner største antall anløp
      if (antallAnlop[i] > flest) flest = antallAnlop[i]; // for ALLE havnene.

  printf("\n\tFlest anlop i lopet av en uke er %i stk.\n", flest);
  printf("\n\tDette er i havnen(e):\n");
  for (i = 0;  i < gAntallHavner;  i++)        //  Skriver (alle) havnen(e)
      if (antallAnlop[i] == flest) {           //    med flest anløp:
         printf("\t\t");   havnSkrivData(gHavner[i]);
      }
}


/**
 *  Oppgave 2F - Registrerer rutens antall anløp i dets ulike havner.
 *
 *  @param   rute    -  Ruten det skal telles opp havneanløp for
 *  @param   antall  -  Array med antall anlop i hver av havnene
 */
void ruteTellAnlop(const struct Rute* rute, int antall[])  {
  for (int i = 1;  i < rute->antallHavner;  i++)  //  For rutens ALLE havner:
      for (int j = 0;  j < DAGER;  j++)           //  Og for ALLE ukedagene:
          if (rute->dag[j])                       //  Innom havn aktuell dag:
             antall[rute->havnene[i]]++;          //  TOTALT antall anløp pr.
}                                                 //  uke i havnen telles opp.


/**
 *  Oppgave 2G - Leser ALLE bårutene inn fra fil.
 *
 *  @see   ruteLesFraFil(...)
 */
void lesRuterFraFil()  {
  FILE* innfil  = fopen("EX_H24_RUTER.DTA", "r");  //  Åpner aktuell fil:

  if (innfil) {                                 //  Filen finnes:
     fscanf(innfil, "%i", &gAntallRuter);       //  Leser antall båtruter.
     getc(innfil);                              //  Leser avsluttende '\n'.
                                                //  Alle ruter lages og leses:
     for (int i = 0;  i < gAntallRuter;  i++) {
       gRuter[i] = (struct Rute*) malloc(sizeof(struct Rute));
       ruteLesFraFil(innfil, gRuter[i]);        // Leser selv.
     }
     printf("\n\n\tBaatruter er lest inn fra 'EX_H24_RUTER.DTA'!\n\n");
  } else                                        //  Filen ikke funnet:
     printf("\n\tFant ikke filen 'EX_H24_RUTER.DTA'!\n\n");

  fclose(innfil);                               //  Lukker åpen fil.
}


/**
 *  Oppgave 2G - Leser ALT om EN rute inn fra fil.
 *
 *  @param  inn   -  Filen det skal leses inn fra
 *  @param  rute  -  Båtruten som får innlest sine data
 */
void ruteLesFraFil(FILE* inn, struct Rute* rute)  {
  char buffer[STRLEN];
  char tegn;

  fgets(buffer, STRLEN, inn);                   //  Lagrer unna rutens båtnavn.
  buffer[strlen(buffer)-1] = '\0';              //  Tar vekk '\n' bakerst.
  rute->baatnavn = (char*) malloc((strlen(buffer) + 1) * sizeof(char));
  strcpy(rute->baatnavn, buffer);
                                               //  Leser lengde og 3x antall:
  fscanf(inn, "%i %i %i", &(rute->lengde), &(rute->antBiler), &(rute->antPersoner));
  fscanf(inn, "%i", &(rute->antallHavner));
  for (int i = 0;  i < rute->antallHavner;  i++) //  Leser indeksene for
      fscanf(inn, "%i", &rute->havnene[i]);      //    havnenavnen.
  for (int i = 0;  i < DAGER;  i++)  {           //  Leser ukedag innom ('+')
      fscanf(inn, " %c", &tegn);                 //    eller ei/ikke ('-'):
      rute->dag[i] = (tegn == '+');
  }
  getc(inn);                                   //  Forkaster avsluttende '\n'.
}


/**
 *  EXTRA - Leser ALLE havnene inn fra fil.
 *
 *  @see   havnLesFraFil(...)
 */
void lesHavnerFraFil() {
  FILE* innfil  = fopen("EX_H24_HAVNER.DTA", "r");  //  Åpner aktuell fil:

  if (innfil) {                                //  Filen finnes:
     fscanf(innfil, "%i", &gAntallHavner);     //  Leser antall havner.
     getc(innfil);                             //  Leser avsluttende '\n'.
                                               //  Alle havner lages og leses:
     for (int i = 0;  i < gAntallHavner;  i++) {
       gHavner[i] = (struct Havn*) malloc(sizeof(struct Havn));
       havnLesFraFil(innfil, gHavner[i]);      // Leser selv.
     }
     printf("\tHavner er lest inn fra 'EX_H24_HAVNER.DTA'!\n\n");
  } else                                       //  Filen ikke funnet:
     printf("\n\tFant ikke filen 'EX_H24_HAVNER.DTA'!\n\n");

  fclose(innfil);                              //  Lukker åpen fil.
}


/**
 *  EXTRA - Leser ALT om EN havn inn fra fil.
 *
 *  @param  inn   -  Filen det skal leses inn fra
 *  @param  havn  -  Havnen som får innlest sine data
 */
void havnLesFraFil(FILE* inn, struct Havn* havn)  {
  char buffer[STRLEN];

  fgets(buffer, STRLEN, inn);                  //  Lagrer unna havnens navn.
  buffer[strlen(buffer)-1] = '\0';             //  Tar vekk '\n' bakerst.
  havn->navn = (char*) malloc((strlen(buffer) + 1) * sizeof(char));
  strcpy(havn->navn, buffer);

  fgets(buffer, STRLEN, inn);                  //  Lagrer EVT. unna øyas navn.
  buffer[strlen(buffer)-1] = '\0';             //  Tar vekk '\n' bakerst.
  if (strcmp(buffer, "-"))  {                  //  Øynavn finnes:
     havn->oy = (char*) malloc((strlen(buffer) + 1) * sizeof(char));
     strcpy(havn->oy, buffer);
  } else                                       //  Havn og øy med samme navn:
     havn->oy = NULL;                          //  Da intet eget øynavn.
}
