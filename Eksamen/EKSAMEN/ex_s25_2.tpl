/**
 *   Skjellett eksamen i GrProg (i C), august 2025, oppgave 2.
 *
 *   Programmet holder orden på antall besøk/visitasjoner på en legevakt
 *   - hvilke ukedager og timer/klokkeslett dette skjer.
 *
 *   @file     EX_S25_2.TPL
 *   @author   Frode Haug, NTNU
 */


#include <stdio.h>             //  printf, FILE
#include <stdlib.h>            //  sizeof, malloc
#include <string.h>            //  strcpy, strlen
#include <time.h>              //  Noen tidsfunksjoner for å få tak i dag/time
#include "LesData.h"           //  Verktøykasse for lesing av diverse data


#define   DOGN            7    ///<  Antall dager i en uke.
#define   TIMER          24    ///<  Antall timer i et døgn.
#define   STRLEN        120    ///<  Max. tekstlengde.


/**
 *  Døgn (med døgnets/dagens navn, beskrivelse av det,
 *        og antall besøk pr time i det aktuelle døgnet).
 */
struct Dogn  {
  char* navn;                  //  Dagen/døgnets navn.
  char* beskrivelse;           //  Beskrivelse av døgnet.
  int   antall[TIMER];         //  Antall besøk for hver klokketime i døgnet.
};


void skrivMeny();                                              //  Ferdig-
int  hentDag();                                                //    laget:
int  hentTime();                                               //
void skrivAlleDogn();                                          //  Oppgave 2A
void dognSkrivData(const struct Dogn* dogn);                   //  Oppgave 2A
void skrivEttDogn();                                           //  Oppgave 2B
void dognSkrivAlt(const struct Dogn* dogn);                    //  Oppgave 2B
void nyttBesok();                                              //  Oppgave 2C
void dognRegistrerBesok(struct Dogn* dogn);                    //  Oppgave 2C
void nyttBesok2();                                             //  Oppgave 2D
void dognRegistrerBesok2(struct Dogn* dogn);                   //  Oppgave 2D
void naarFlestBesok();                                         //  Oppgave 2E
void naarFlestBesok2();                                        //  Oppgave 2F
void skrivDognTilFil();                                        //  Oppgave 2G
void dognSkrivTilFil(FILE* ut, struct Dogn* dogn);             //  Oppgave 2G
void lesDognFraFil();                                          //  Oppgave 2H
void dognLesFraFil(FILE* inn, struct Dogn* dogn);              //  Oppgave 2H


struct Dogn* gDogn[DOGN];      ///<  Alle døgnene i registeret.


/**
 *  Hovedprogrammet.
 */
int main()  {
  char kommando;

  lesDognFraFil();                                          //  Oppgave 2H

  skrivMeny();
  kommando = lesChar("\nValg");

  while (kommando != 'Q') {
    switch (kommando) {
      case 'A':  skrivAlleDogn();          break;           //  Oppgave 2A
      case 'E':  skrivEttDogn();           break;           //  Oppgave 2B
      case 'N':  nyttBesok();              break;           //  Oppgave 2C
      case 'B':  nyttBesok2();             break;           //  Oppgave 2D
      case 'F':  naarFlestBesok();         break;           //  Oppgave 2E
      case 'T':  naarFlestBesok2();        break;           //  Oppgave 2F
      default:   skrivMeny();              break;
    }
    kommando = lesChar("\nValg");
  }

  skrivDognTilFil();                                        //  Oppgave 2G

  return 0;
}


/**
 *  Avleser maskinens systemklokke, og returnerer ukedagen (man=1, ... søn=7).
 *
 *  @return   Ukedagen (man=1, tirs=2, ... lør=6, søn=7)
 */
int hentDag()  {
  time_t result = time(0);                     //  Henter maskinens tidspunkt.
  struct tm tid = *localtime(&result);         //  Konverterer inn i struct.
  return ((tid.tm_wday == 0) ? 7 : tid.tm_wday);   //  Returnerer 1-7.
}


/**
 *  Avleser maskinens systemklokke, og returnerer hvilken time det er (0-23).
 *
 *  @return   Hvilken time det er (0-23).
 */
int hentTime()  {
  time_t result = time(0);                     //  Henter maskinens tidspunkt.
  struct tm tid = *localtime(&result);         //  Konverterer inn i struct.
  return (tid.tm_hour);                        //  Returnerer 0-23.
}


/**
 *  Skriver/presenterer programmets muligheter/valg for brukeren.
 */
void skrivMeny() {
  printf("\nFOLGENDE KOMMANDOER ER LOVLIG:\n");
  printf("\tA   = skriv Alle dogn\n");
  printf("\tE   = skriv Ett dogn\n");
  printf("\tN   = Nytt besok (versjon 1)\n");
  printf("\tB   = nytt Besok (versjon 2)\n");
  printf("\tF   = hvilket dogn og time med Flest besok\n");
  printf("\tT   = hvilken Time med totalt flest besok (uavhengig av dogn)\n");
  printf("\tQ   = Quit/avslutt\n");
}


/**
 *  Oppgave 2A - Skriver ALLE døgnene og TOTALT antall besøk pr døgn.
 *
 *  @see   dognSkrivData(...)
 */
void skrivAlleDogn()  {

//  LAG INNMATEN
}


/**
 *  Oppgave 2A - Skriver døgnnavn og TOTALT antall besøk det døgnet.
 *
 *  @param  dogn  -  Døgnet det skrives ut noen data for
 */
void dognSkrivData(const struct Dogn* dogn)  {

//  LAG INNMATEN
}


/**
 *  Oppgave 2B - Skriver ALT om ETT gitt døgn.
 *
 *  @see   dognSkrivAlt(...)
 */
void skrivEttDogn()  {

//  LAG INNMATEN
}


/**
 *  Oppgave 2B - Skriver ALT om ett døgn.
 *
 *  @param  dogn  -  Døgnet det skrives ut ALT om
 */
void dognSkrivAlt(const struct Dogn* dogn)  {

//  LAG INNMATEN
}


/**
 *  Oppgave 2C - Leser inn et nytt besøk på legevakten.
 *
 *  @see   dognRegistrerBesok(...)
 */
void nyttBesok()  {

//  LAG INNMATEN
}


/**
 *  Oppgave 2C - Registrerer ETT besøk i aktuelt døgn.
 *
 *  @param  dogn  -  Døgnet det registreres ETT besøk i
 */
void dognRegistrerBesok(struct Dogn* dogn)  {

//  LAG INNMATEN
}


/**
 *  Oppgave 2D - Nytt besøk registreres AUTOMATISK ved å avlese systemklokka.
 *
 *  @see   dognRegistrerBesok2(...)
 */
void nyttBesok2()  {

//  LAG INNMATEN
}


/**
 *  Oppgave 2D - Registrerer AUTOMATISK ETT besøk i aktuelt døgn.
 *
 *  @param  dogn  -  Døgnet det registreres ETT besøk i
 */
void dognRegistrerBesok2(struct Dogn* dogn)  {

//  LAG INNMATEN
}


/**
 *  Oppgave 2E - Finner og skriver dagen og timen med flest legevaktbesøk.
 */
void naarFlestBesok()  {

//  LAG INNMATEN
}


/**
 *  Oppgave 2F - Finner og skriver timen TOTALT i HELE uka
 *               med flest legevaktbesøk.
 */
void naarFlestBesok2()  {

//  LAG INNMATEN
}


/**
 *  Oppgave 2G - Skriver ALLE døgnene ut til fil.
 *
 *  @see   dognSkrivTilFil(...)
 */
void skrivDognTilFil()  {

//  LAG INNMATEN
}


/**
 *  Oppgave 2G - Skriver ALT om ETT døgn ut til fil.
 *
 *  @param  inn   -  Filen det skal skrives ut til
 *  @param  dogn  -  Døgnet som får skrevet ut sine data
 */
void dognSkrivTilFil(FILE* ut, struct Dogn* dogn)  {

//  LAG INNMATEN
}


/**
 *  Oppgave 2H - Leser ALLE døgnene inn fra fil.
 *
 *  @see   dognLesFraFil(...)
 */
void lesDognFraFil()  {

//  LAG INNMATEN
}


/**
 *  Oppgave 2H - Leser ALT om ETT døgn inn fra fil.
 *
 *  @param  inn   -  Filen det skal leses inn fra
 *  @param  dogn  -  Døgnet som får innlest sine data
 */
void dognLesFraFil(FILE* inn, struct Dogn* dogn)  {

//  LAG INNMATEN
}
