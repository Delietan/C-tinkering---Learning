/**
 *   Skjelett eksamen i GrProg (i C), august 2024, oppgave 2.
 *
 *   Programmet holder orden på EN klubbs resultater i ulike kamper,
 *   mot (u)like motstandere, samt alle egne målscorere i disse kampene.
 *
 *   @file     EX_S24_2.TPL
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


void skrivMeny();                                             //  Ferdiglaget.
void skrivAlleResultater();                                   //  Oppgave 2A
void kampSkrivResultat(const struct Kamp* kamp);              //  Oppgave 2A
void skrivEttResultat();                                      //  Oppgave 2B
void kampSkrivAlt(const struct Kamp* kamp);                   //  Oppgave 2B
void registrerResultat();                                     //  Oppgave 2C
void kampRegistrerResultat(struct Kamp* kamp);                //  Oppgave 2C
void beregnPoengsumOgMaal();                                  //  Oppgave 2D
void kampHent(const struct Kamp* kamp, int* maalFor, int* maalMot); //Oppg.2D
void beregnPoengsumOgMaal2();                                 //  Oppgave 2E
void skrivToppscorere();                                      //  Oppgave 2F
void lesFraFil();                                             //  Oppgave 2G
void kampLesFraFil(FILE* inn, struct Kamp* kamp);             //  Oppgave 2G


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

   //   LAG INNMATEN
}


/**
 *  Oppgave 2A - Skriver motstandernavn og antall scorede/innslupne kampmål.
 *
 *  @param  kamp  -  Kampen det skrives ut noen data for
 */
void kampSkrivResultat(const struct Kamp* kamp)  {

   //   LAG INNMATEN
}


/**
 *  Oppgave 2B - Skriver ALT om EN gitt kamp.
 *
 *  @see   kampSkrivAlt(...)
 */
void skrivEttResultat()  {

   //   LAG INNMATEN
}


/**
 *  Oppgave 2B - Skriver ALT om en kamp.
 *
 *  @param  kamp  -  Kampen det skrives ut ALT om
 */
void kampSkrivAlt(const struct Kamp* kamp)  {

   //   LAG INNMATEN
}


/**
 *  Oppgave 2C - Legger (om mulig) inn en ny kamp inn i datastrukturen.
 *
 *  @see   kampRegistrerResultat(...)
 */
void registrerResultat()  {

   //   LAG INNMATEN
}


/**
 *  Oppgave 2C - Leser inn ALT om EN kamp sine resultater.
 *
 *  @param   kamp  -  Kampen det leses inn alle data for
 */
void kampRegistrerResultat(struct Kamp* kamp)  {

   //   LAG INNMATEN
}


/**
 *  Oppgave 2D - Regner og skriver ut TOTALpoengsum og ALLE målene for laget.
 *
 *  @see  kampHent(...)
 */
void beregnPoengsumOgMaal()  {

   //   LAG INNMATEN
}


/**
 *  Oppgave 2D - Henter antall scorede/innslupne mål i en gitt kamp.
 *
 *  @param   kamp      -  Kampen det skal hentes scorede/innslupne mål fra
 *  @param   maalFor   -  Antall mål selv scoret ("referanseoverført")
 *  @param   maalMot   -  Antall mål innslupet ("referanseoverført")
 */
void kampHent(const struct Kamp* kamp, int* maalFor, int* maalMot)  {

   //   LAG INNMATEN
}


/**
 *  Oppgave 2E - Lager en "tabellinje" for laget.
 */
void beregnPoengsumOgMaal2()  {

   //   LAG INNMATEN
}


/**
 *  Oppgave 2F - Teller opp og finner navnet til lagets toppscorer(e).
 */
void skrivToppscorere()  {

   //   LAG INNMATEN
}


/**
 *  Oppgave 2G - Leser ALLE kampene/resultatene inn fra fil.
 *
 *  @see   kampLesFraFil(...)
 */
void lesFraFil()  {

   //   LAG INNMATEN
}


/**
 *  Oppgave 2G - Leser ALT om EN kamp inn fra fil.
 *
 *  @param  inn   -  Filen det skal leses inn fra
 *  @param  kamp  -  Kampen som får innlest sine data
 */
void kampLesFraFil(FILE* inn, struct Kamp* kamp)  {

   //   LAG INNMATEN
}
