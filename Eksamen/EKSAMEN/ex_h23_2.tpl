/**
 *   Skjelett eksamen i GrProg (i C), desember 2023, oppgave 2.
 *
 *   Programmet holder orden på ulike fugler og observasjonene av disse.
 *
 *   @file     EX_H23_2.TPL
 *   @author   Frode Haug, NTNU
 */


#include <stdio.h>               //  printf, FILE
#include <stdlib.h>              //  sizeof, malloc, free
#include <string.h>              //  strcpy, strlen
#include "LesData.h"             //  Verktøykasse for lesing av diverse data


#define   MAXFUGLER      200     ///<  Max. antall fuglearter/-typer.
#define   ANTDAGER       365     ///<  Dagantall i ETT år (ignorerer skuddår).
const int STRLEN  =       80;    ///<  Max. tekstlengde.


/**
 *  Fugl (med navn, antall observasjoner og datoene for disse observasjonene).
 */
struct Fugl  {                   //  En fuglearts/-types:
  char* navn;                    //    - navn
  int   antObs;                  //    - antall observasjoner i ETT kalenderår
  int   observasjoner[ANTDAGER]; //    - datoer for observasjonene.
};                               //        Lagres på formen: MMDD


int  dagnummer(const int dag, const int mnd);                  //  | Ferdig-
int  finnFugl(const char* nvn);                                //  |  laget:
void skrivMeny();                                              //  |
void nyFugl();                                                 //  Oppgave 2A
void fuglSettData(struct Fugl* fugl, char* nvn);               //  Oppgave 2A
void skrivDato(const int dato);                                //  Oppgave 2A
void skrivAlleFugler();                                        //  Oppgave 2B
void fuglSkrivNoe(const struct Fugl* fugl);                    //  Oppgave 2B
void skrivEnFugl();                                            //  Oppgave 2C
void fuglSkrivAlt(const struct Fugl* fugl);                    //  Oppgave 2C
void nyObservasjon();                                          //  Oppgave 2D
void fuglNyObservasjon(struct Fugl* fugl);                     //  Oppgave 2D
void dagenMedFlestObservasjoner();                             //  Oppgave 2E
void skrivTilFil();                                            //  Oppgave 2F
void fuglSkrivTilFil(FILE* ut, const struct Fugl* fugl);       //  Oppgave 2F
void lesFraFil();                                              //  Oppgave 2G
void fuglLesFraFil(FILE* inn, struct Fugl* fugl, const char* nvn); // Oppg.2G


int    gAntallFugler = 0;               ///<  Antall fugler hittil registrert.
struct Fugl* gFugler[MAXFUGLER];        ///<  Alle fuglene i registeret.


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
      case 'F':  nyFugl();                      break;    //  Oppgave 2A
      case 'A':  skrivAlleFugler();             break;    //  Oppgave 2B
      case 'E':  skrivEnFugl();                 break;    //  Oppgave 2C
      case 'O':  nyObservasjon();               break;    //  Oppgave 2D
      case 'D':  dagenMedFlestObservasjoner();  break;    //  Oppgave 2E
      default:   skrivMeny();                   break;
    }
    kommando = lesChar("\nValg");
  }

  skrivTilFil();                                            //  Oppgave 2F

  return 0;
}


/**
 *  Beregner (om mulig) dagnummeret i året for en gitt dato (IGNORERER skuddår).
 *
 *  @param   dag  -  Dag
 *  @param   mnd  -  Måned
 *  @return  Dagnummeret (1-365) i året (om gyldig dato) ellers 0 (null)
 */
int dagNummer(const int dag, const int mnd) {
  int dagnr;                        //  Setter opp antall dager i månedene:
  int dagerPrMnd[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

  if (mnd < 1 || mnd > 12)                return 0;  //  Ulovlig måned.
  if (dag < 1 || dag > dagerPrMnd[mnd-1]) return 0;  //  Ulovlig dag.
  dagnr = dag;
  for (int i = 0;  i < mnd-1;  i++)         //  Regner ut datoens dagnummer.
      dagnr += dagerPrMnd[i];
  return dagnr;                             //  Returnerer dagnummeret.
}


/**
 *  Prøver å finne indeksen i 'gFugler' for en navngitt fugl.
 *
 *  @param   nvn  - Søkt fugls navn
 *  @return  Indeksen for fuglen, evt. -1 om ikke ble funnet
 */
int finnFugl(const char* nvn)  {
  for (int i = 0;  i < gAntallFugler;  i++)
      if (!strcmp(gFugler[i]->navn, nvn))  return i;   //  Funn/match!

  return -1;                           //  Ikke funnet noen med dette 'nvn'.
}


/**
 *  Skriver/presenterer programmets muligheter/valg for brukeren.
 */
void skrivMeny() {
  printf("\nFOLGENDE KOMMANDOER ER LOVLIG:\n");
  printf("\tF   = ny Fugl\n");
  printf("\tA   = skriv Alle fuglene og antall observasjoner\n");
  printf("\tE   = skriv alt om En fugl\n");
  printf("\tO   = ny Observasjon av en fugl\n");
  printf("\tD   = Dagen med flest fugleobservasjoner\n");
  printf("\tQ   = Quit/avslutt\n");
}



/**
 *  Oppgave 2A - Legger (om mulig) inn en ny fugl inn i datastrukturen.
 */
void nyFugl()  {

   //   LAG INNMATEN
}


/**
 *  Oppgave 2A - Leser KUN inn en fugl navn/art/type.
 *
 *  @param   fugl  -  Fuglen det leses inn navnet til
 *  @param   nvn   -  Fuglens allerede innleste og memoryallokerte vnavn
 */
void fuglSettData(struct Fugl* fugl, char* nvn)  {

   //   LAG INNMATEN
}


/**
 *  Oppgave 2A - Skriver dato (på formen MMDD) som DD/MM.
 *
 *  @param   dato  -   Datoen som skal skrives ut som DD/MM
 */
void skrivDato(const int dato)  {

   //   LAG INNMATEN
}


/**
 *  Oppgave 2B - Skriver ALLE fuglenes navn og antall observasjoner.
 */
void skrivAlleFugler()  {

   //   LAG INNMATEN
}


/**
 *  Oppgave 2B - Skriver navn og antall observasjoner for EN fugl.
 *
 *  @param  fugl  -  Fuglen det skrives ut navn og antall observasjoner om
 */
void fuglSkrivNoe(const struct Fugl* fugl)  {

   //   LAG INNMATEN
}


/**
 *  Oppgave 2C - Skriver ALT om EN gitt fugl.
 */
void skrivEnFugl()  {

   //   LAG INNMATEN
}


/**
 *  Oppgave 2C - Skriver ALT om en fugl.
 *
 *  @param  fugl  -  Fuglen det skrives ut ALT om
 */
void fuglSkrivAlt(const struct Fugl* fugl)  {

   //   LAG INNMATEN
}


/**
 *  Oppgave 2D - Registrerer (om mulig) EN ny observasjon av EN fugl.
 */
void nyObservasjon()  {

   //   LAG INNMATEN
}


/**
 *  Oppgave 2D - Registrerer (om mulig) EN ny observasjon av fuglen.
 *
 *  @param  fugl  -  Fuglen det registreres EN ny observasjon av
 */
void fuglNyObservasjon(struct Fugl* fugl)  {

   //   LAG INNMATEN
}


/**
 *  Oppgave 2E - Finner og skriver datoen med flest fugleobservasjoner.
 */
void dagenMedFlestObservasjoner()  {

   //   LAG INNMATEN
}


/**
 *  Oppgave 2F - Skriver HELE datastrukturen (ALLE fuglene) til fil.
 */
void skrivTilFil()  {

   //   LAG INNMATEN
}


/**
 *  Oppgave 2F - Skriver ALT om EN fugl til fil.
 *
 *  @param   ut    -  Filen det skal skrives ut til
 *  @param   fugl  -  Fuglen som får skrevet ut sine data
 */
void fuglSkrivTilFil(FILE* ut, const struct Fugl* fugl)  {

   //   LAG INNMATEN
}


/**
 *  Oppgave 2G - Leser ALLE fuglene inn fra fil.
 */
void lesFraFil() {

   //   LAG INNMATEN
}


/**
 *  Oppgave 2G - Leser ALT om EN fugl inn fra fil.
 *
 *  @param  inn   -  Filen det skal leses inn fra
 *  @param  fugl  -  Fuglen som får innlest sine data
 *  @param  nvn   -  Fuglens navn som hittil er lest inn fra fil
 */
void fuglLesFraFil(FILE* inn, struct Fugl* fugl, const char* nvn)  {

   //   LAG INNMATEN
}
