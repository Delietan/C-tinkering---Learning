/**
 *   Skjellett eksamen i GrProg (i C), desember 2024, oppgave 2.
 *
 *   Programmet holder orden på ulike havner og (båt)rutene som går innom
 *   de ulike havnene.
 *
 *   @file     EX_H24_2.TPL
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


int    gAntallHavner = 0,             ///<  Antall havner hittil registrert.
       gAntallRuter  = 0;             ///<  Antall båtruter hittil registrert.
struct Havn* gHavner[MAXHAVNER];      ///<  Alle havner i registeret.
struct Rute* gRuter[MAXRUTER];        ///<  Alle havner i registeret.


/**
 *  Hovedprogrammet.
 */
int main()  {
  char kommando;

  lesRuterFraFil();                                       //  Oppgave 2G
//  lesHavnerFraFil();                                    //  Skal IKKE lages.

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

   //   LAG INNMATEN
}


/**
 *  Oppgave 2A - Skriver havnenavn og om ulikt: øynavnet.
 *
 *  @param  havn  -  Havnen det skrives ut noen data for
 */
void havnSkrivData(const struct Havn* havn)  {

   //   LAG INNMATEN
}


/**
 *  Oppgave 2B - Skriver ALLE rutene.
 *
 *  @see   ruteSkrivData(...)
 */
void skrivAlleRuter()  {

   //   LAG INNMATEN
}


/**
 *  Oppgave 2B - Skriver båtnavn og antall havner ruten er innom.
 *
 *  @param  rute  -  Ruten det skrives ut noen data for
 */
void ruteSkrivData(const struct Rute* rute) {

   //   LAG INNMATEN
}


/**
 *  Oppgave 2C - Skriver ALT om EN gitt rute.
 *
 *  @see   ruteSkrivAlt(...)
 */
void skrivAltOmEnRute()  {

   //   LAG INNMATEN
}


/**
 *  Oppgave 2C - Skriver ALT om en rute.
 *
 *  @param  rute  -  Ruten det skrives ut ALT om
 *  @see    ruteSkrivData(...)
 *  @see    havnSkrivData(...)
 */
void ruteSkrivAlt(const struct Rute* rute)  {

   //   LAG INNMATEN
}


/**
 *  Oppgave 2D - Legger (om mulig) en ny havn inn i datastrukturen.
 *
 *  @see   havnLesData(...)
 */
void nyHavn()  {

   //   LAG INNMATEN
}


/**
 *  Oppgave 2D - Leser inn ALT om EN havn.
 *
 *  @param   havn  -  Havnen det leses inn alle data for
 *  @param   nvn   -  Havnens allerede innleste og memoryallokerte navn
 */
void havnLesData(struct Havn* havn, char* nvn)  {

   //   LAG INNMATEN
}


/**
 *  Oppgave 2E - Legger (om mulig) en ny rute inn i datastrukturen.
 *
 *  @see   ruteLesData(...)
 */
void nyRute()  {

   //   LAG INNMATEN
}


/**
 *  Oppgave 2E - Leser inn ALT om EN rute.
 *
 *  @param   rute  -  Ruten det leses inn alle data for
 */
void ruteLesData(struct Rute* rute)  {

   //   LAG INNMATEN
}


/**
 *  Oppgave 2F - Finner og skriver havnen(e) med flest båtanløp.
 *
 *  @see   ruteTellAnlop(...)
 *  @see   havnSkrivData(...)
 */
void mestTravleHavn()  {

   //   LAG INNMATEN
}


/**
 *  Oppgave 2F - Registrerer rutens antall anløp i dets ulike havner.
 *
 *  @param   rute    -  Ruten det skal telles opp havneanløp for
 *  @param   antall  -  Array med antall anlop i hver av havnene
 */
void ruteTellAnlop(const struct Rute* rute, int antall[])  {

   //   LAG INNMATEN
}


/**
 *  Oppgave 2G - Leser ALLE bårutene inn fra fil.
 *
 *  @see   ruteLesFraFil(...)
 */
void lesRuterFraFil()  {

   //   LAG INNMATEN
}


/**
 *  Oppgave 2G - Leser ALT om EN rute inn fra fil.
 *
 *  @param  inn   -  Filen det skal leses inn fra
 *  @param  rute  -  Båtruten som får innlest sine data
 */
void ruteLesFraFil(FILE* inn, struct Rute* rute)  {

   //   LAG INNMATEN
}
