/**
 *   Løsningsforslag til eksamen i GrProg (i C), desember 2023, oppgave 2.
 *
 *   Programmet holder orden på ulike fugler og observasjonene av disse.
 *
 *   @file     EX_H23_2.C
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
                                                       //  Ny ifm. oppgave 2E:
void fuglTellObservasjoner(const struct Fugl* fugl, int antall[], int datoer[]);
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
 *
 *  @see   finnFugl(...)
 *  @see   fuglSettData(...)
 */
void nyFugl()  {
 char* navn;                             //  Ny fugls navn.

 if (gAntallFugler < MAXFUGLER)  {       //  Plass til flere fugler:
    navn = lagOgLesText("\tNavn");       //  Leser/lager ny(?) fugl navn.
    if (finnFugl(navn) == -1)  {         //  Ingen med dette navnet allerede:
                                         //  Allokerer plass til en ny fugl:
       gFugler[gAntallFugler] = (struct Fugl*) malloc(sizeof(struct Fugl));
                                         //  Andre data settes, antallet økes:
       fuglSettData(gFugler[gAntallFugler++], navn);
    } else  {                            //  Fuglen finnes:
      printf("\n\tFinnes en fugl med dette navnet allerede!\n\n");
      free(navn);                        //  FRIGIR MEMORY - SKAL IKKE LAGRES!
    }
 } else                                      //  Fullt:
     printf("\n\tFullt med %i fugler allerede!\n\n", MAXFUGLER);
}


/**
 *  Oppgave 2A - Leser KUN inn en fugl navn/art/type.
 *
 *  @param   fugl  -  Fuglen det leses inn navnet til
 *  @param   nvn   -  Fuglens allerede innleste og memoryallokerte navn
 */
void fuglSettData(struct Fugl* fugl, char* nvn)  {
  fugl->navn = nvn;                      //  Lagrer unna innlest navn.
  fugl->antObs = 0;                      //  Nullstiller antall observasjoner.
}


/**
 *  Oppgave 2A - Skriver dato (på formen MMDD) som DD/MM.
 *
 *  @param   dato  -   Datoen som skal skrives ut som DD/MM
 */
void skrivDato(const int dato)  {
  printf("%i/%i", dato % 100, dato /100);
}


/**
 *  Oppgave 2B - Skriver ALLE fuglenes navn og antall observasjoner.
 *
 *  @see   fuglSkrivNoe(...)
 */
void skrivAlleFugler()  {
  printf("\n\tAlle fuglene og antall observasjoner av hver:\n");
  for (int i = 0;  i < gAntallFugler;  i++) {
      printf("\t   Nr.%3i:  ", i+1);             //  Skriver fuglens nummer.
      fuglSkrivNoe(gFugler[i]);                  //  Hver skriver seg selv.
  }
}


/**
 *  Oppgave 2B - Skriver navn og antall observasjoner for EN fugl.
 *
 *  @param  fugl  -  Fuglen det skrives ut navn og antall observasjoner om
 */
void fuglSkrivNoe(const struct Fugl* fugl)  {
  printf("%-20s  %3i observasjoner\n", fugl->navn, fugl->antObs);
}


/**
 *  Oppgave 2C - Skriver ALT om EN gitt fugl.
 *
 *  @see   finnFugl(...)
 *  @see   fuglSkrivAlt(...)
 */
void skrivEnFugl()  {
  char navn[STRLEN];                                //  Fuglens navn.
  int  nr;                                          //  Fuglens indeks.

  if (gAntallFugler > 0)  {
     lesText("\tALT om fuglen", navn, STRLEN);      //  Leser fuglenavn.
     if ((nr = finnFugl(navn)) != -1)               //  Fuglen finnes:
        fuglSkrivAlt(gFugler[nr]);                  //  Skriver ALT om fuglen.
     else                                           //  Fuglen finnes ikke:
        printf("\n\tFinnes ingen fugl med dette navnet!\n\n");
  } else                                            //  Ingen fugler finnes:
    printf("\n\tIngen fugler ennaa registrert!\n\n");
}


/**
 *  Oppgave 2C - Skriver ALT om en fugl.
 *
 *  @param  fugl  -  Fuglen det skrives ut ALT om
 *  @see    skrivDato(...)
 */
void fuglSkrivAlt(const struct Fugl* fugl)  {
  printf("\n\t%i observasjon(er) paa folgende dato(er):\n\t", fugl->antObs);
  for (int i = 0;  i < fugl->antObs;  i++)  {
//  Evt. bytte ut if-setning rett nedenfor med:  if (i > 0)  printf(",  ");
      skrivDato(fugl->observasjoner[i]);           //  Dato på formen: DD/MM
      if (i < fugl->antObs-1) printf(",  ");       //  ",  " mellom hver,
  }                                                //   unntatt den siste.
  printf("\n");                                    //  Avsluttende linjeskift.
}


/**
 *  Oppgave 2D - Registrerer (om mulig) EN ny observasjon av EN fugl.
 *
 *  @see   finnFugl(...)
 *  @see   fuglNyObservasjon(...)
 */
void nyObservasjon()  {
  char navn[STRLEN];                                //  Fuglens navn.
  int  nr;                                          //  Fuglens indeks.

  if (gAntallFugler > 0)  {
     lesText("\tNy observasjon av fuglen", navn, STRLEN); // Leser fuglenavn.
     if ((nr = finnFugl(navn)) != -1)               //  Fuglen finnes:
        fuglNyObservasjon(gFugler[nr]);             //  Registrerer ny obs.
     else                                           //  Fuglen finnes ikke:
        printf("\n\tFinnes ingen fugl med dette navnet!\n\n");
  } else                                            //  Ingen fugler finnes:
    printf("\n\tIngen fugler ennaa registrert!\n\n");
}


/**
 *  Oppgave 2D - Registrerer (om mulig) EN ny observasjon av fuglen.
 *
 *  @param  fugl  -  Fuglen det registreres EN ny observasjon av
 *  @see    dagNummer(...)
 *  @see    skrivDato(...)
 */
void fuglNyObservasjon(struct Fugl* fugl)  {
  int dag, maaned,                              //  Dag (DD) og måned (MM).
      dagnr, mmdd;                              //  Dagnummer i året og datoen
                                                //   på formen:  MMDD
  if (fugl->antObs < ANTDAGER)  {               //  Fortsatt plass til obs:
     do  {
       printf("\n\tNy observasjon paa:\n");     //  Leser og sikrer at datoen
       dag    = lesInt("\t\tDag   ", 1, 31);    //   er en lovlig dag i året:
       maaned = lesInt("\t\tMaaned", 1, 12);
       dagnr  = dagNummer(dag, maaned);
     } while (dagnr == 0);

     mmdd = maaned*100 + dag;                  //  Omgjør til formatet: MMDD
                                               //  1.obs eller ny større dato:
     if (fugl->antObs == 0  ||  fugl->observasjoner[fugl->antObs-1] < mmdd)
        fugl->observasjoner[fugl->antObs++] = mmdd;  //  Lagrer den unna.
     else  {                          //  En tidligere dato enn siste lagrede:
        printf("\n\tMå være større enn forrige registrerte - som er: ");
        skrivDato(fugl->observasjoner[fugl->antObs-1]);  printf("\n");
     }
  } else
    printf("\n\tRegistrert %i observasjoner av fuglen allerede!\n", ANTDAGER);
}


/**
 *  Oppgave 2E - Finner og skriver datoen med flest fugleobservasjoner.
 *
 *  @see  fuglTellObservasjoner(...)
 *  @see  skrivDato(...)
 */
void dagenMedFlestObservasjoner()  {
  int i,                            //  Løkketeller.
      storst = -1,                  //  Størst antall observasjoner,
      dagen  = -1;                  //    og dagnummeret dette er på.
  int antallene[ANTDAGER],          //  Antall observasjoner dag nr.i (0-364).
      datoene[ANTDAGER];            //  Datoen (på formen MMDD) for dag nr.i.

  for (i = 0;  i < ANTDAGER;  i++)  //  Nullstiller begge arrayene:
       antallene[i] = datoene[i] = 0;
                                    //  Registrer/tell opp ALLE observasjoner:
  for (i = 0;  i < gAntallFugler;  i++)
      fuglTellObservasjoner(gFugler[i], antallene, datoene);

  for (i = 0;  i < ANTDAGER;  i++)  //  Finner datoen med flest observasjoner:
      if (antallene[i] > storst)  {
          storst = antallene[i];
          dagen = i;
      }
  printf("\n\tDagen med flest observasjoner var ");
  skrivDato(datoene[dagen]);                    //  Skriver funnet dato
  printf(" med %i stk\n\n", antallene[dagen]);  //    og antall observasjoner.
}


/**
 *  Oppgave 2E - Teller opp antall observasjoner og registrerer datoer.
 *
 *  @param   fugl    -  Fuglen det skal telles opp observasjoner om
 *  @param   antall  -  TOTALT antall observasjoner på ALLE datoene
 *  @param   datoer  -  Dagnumrene (0-364) lagret på formatet MMDD
 *  @see     dagNummer(...)
 */
void fuglTellObservasjoner(const struct Fugl* fugl, int antall[], int datoer[]) {
  int dagnr;

  for (int i = 0;  i < fugl->antObs;  i++)  {
      dagnr = dagNummer(fugl->observasjoner[i] % 100,
                        fugl->observasjoner[i] / 100);
      antall[dagnr-1]++;
      datoer[dagnr-1] = fugl->observasjoner[i];
  }
}


/**
 *  Oppgave 2F - Skriver HELE datastrukturen (ALLE fuglene) til fil.
 *
 *  @see   fuglSkrivTilFil(...)
 */
void skrivTilFil()  {
  FILE* utfil  = fopen("EX_H23_FUGLER.DT2", "w");  //  Åpner aktuell fil:

  if (utfil) {                                     //  Filen kan åpnes:
    printf("\n\tSkriver til filen 'EX_H23_FUGLER.DT2'.....\n\n");

    for (int i = 0;  i < gAntallFugler;  i++)
        fuglSkrivTilFil(utfil, gFugler[i]);        //  Hver fugl skrives.
  } else
    printf("Klarte ikke å åpne filen 'EX_H23_FUGLER.DT2'!\n\n");

  fclose(utfil);                                   //  Lukker filen.
}


/**
 *  Oppgave 2F - Skriver ALT om EN fugl til fil.
 *
 *  @param   ut    -  Filen det skal skrives ut til
 *  @param   fugl  -  Fuglen som får skrevet ut sine data
 */
void fuglSkrivTilFil(FILE* ut, const struct Fugl* fugl)  {
 fprintf(ut, "%s\n%i", fugl->navn, fugl->antObs); //  Skriver navn og ant.obs.
 for (int i = 0;  i < fugl->antObs;  i++)         //  Skriver ALLE
     fprintf(ut, " %i", fugl->observasjoner[i]);  //    observasjonene.
 fprintf(ut, "\n");
}


/**
 *  Oppgave 2G - Leser ALLE fuglene inn fra fil.
 *
 *  @see   fuglLesFraFil(...)
 */
void lesFraFil() {
  char buffer[STRLEN];
  FILE* innfil  = fopen("EX_H23_FUGLER.DTA", "r"); //  Åpner aktuell fil:

  if (innfil) {                                  //  Filen finnes:
     gAntallFugler = 0;                          //  Nullstiller fugletelling.
     fgets(buffer, STRLEN, innfil);              //  Prøver å lese 1.post.
     while (!feof(innfil)  &&  gAntallFugler < MAXFUGLER)  {
       buffer[strlen(buffer)-1] = '\0';          // Tar vekk avsluttende '\n'.
       gFugler[gAntallFugler] = (struct Fugl*) malloc(sizeof(struct Fugl));
       fuglLesFraFil(innfil, gFugler[gAntallFugler], buffer);  //  Leser selv.
       gAntallFugler++;                          //  Antall fugler økes.
       fgets(buffer, STRLEN, innfil);            //  Prøver å lese neste post.
     }
     printf("\n\n\tFuglene er lest inn fra 'EX_H23_FUGLER.DTA'\n\n");
  } else                                       //  Filen ikke funnet:
     printf("\n\tFant ikke filen 'EX_H23_FUGLER.DTA'!\n\n");

  fclose(innfil);                              //  Lukker åpen fil.
}


/**
 *  Oppgave 2G - Leser ALT om EN fugl inn fra fil.
 *
 *  @param  inn   -  Filen det skal leses inn fra
 *  @param  fugl  -  Fuglen som får innlest sine data
 *  @param  nvn   -  Fuglens navn som hittil er lest inn fra fil
 */
void fuglLesFraFil(FILE* inn, struct Fugl* fugl, const char* nvn)  {
  fugl->navn = (char*) malloc((strlen(nvn) + 1) * sizeof(char));
  strcpy(fugl->navn, nvn);                   //  Lagrer unna fuglens navn.

  fscanf(inn, "%i", &(fugl->antObs));        //  Leser antall observasjoner.
  for (int i = 0;  i < fugl->antObs;  i++)   //  Leser inn observasjonene:
      fscanf(inn, "%i", &(fugl->observasjoner[i]));
  getc(inn);                                 //  Forkaster avsluttende '\n'.
}
