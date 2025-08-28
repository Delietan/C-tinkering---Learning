/**
 *   Løsningsforslag til eksamen i GrProg (i C), august 2025, oppgave 2.
 *
 *   Programmet holder orden på antall besøk/visitasjoner på en legevakt
 *   - hvilke ukedager og timer/klokkeslett dette skjer.
 *
 *   @file     EX_S25_2.C
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
  printf("\n\tAlle dognene og TOTALT antall besok pr.dogn:\n");
  for (int i = 0;  i < DOGN;  i++)
      dognSkrivData(gDogn[i]);             //  Hver skriver seg selv.
}


/**
 *  Oppgave 2A - Skriver døgnnavn og TOTALT antall besøk det døgnet.
 *
 *  @param  dogn  -  Døgnet det skrives ut noen data for
 */
void dognSkrivData(const struct Dogn* dogn)  {
  int sum  = 0;

  printf("\t\t%-7s:", dogn->navn);          //  Oppsummerer døgnets besøk:
  for (int i = 0;  i < TIMER;  i++)  sum += dogn->antall[i];
  printf("  totalt  %6i  besok i dette dognet\n", sum);
}


/**
 *  Oppgave 2B - Skriver ALT om ETT gitt døgn.
 *
 *  @see   dognSkrivAlt(...)
 */
void skrivEttDogn()  {
  dognSkrivAlt(gDogn[lesInt("\tDognnr (1=man, 2=tirs, ... 6=lor, 7=son)",
                               1, DOGN)-1]);  //  ALT om aktuelt døgn skrives.
}


/**
 *  Oppgave 2B - Skriver ALT om ett døgn.
 *
 *  @param  dogn  -  Døgnet det skrives ut ALT om
 */
void dognSkrivAlt(const struct Dogn* dogn)  {
  printf("\n\t%s:  %s\n", dogn->navn, dogn->beskrivelse);
  printf("\n\tAntall besok i dognets ulike timer:\n");
  for (int i = 0;  i < TIMER;  i++)            //  Skriver ALLE døgnets besøk:
      printf("\t\t%2i: %6i\n", i, dogn->antall[i]);
}


/**
 *  Oppgave 2C - Leser inn et nytt besøk på legevakten.
 *
 *  @see   dognRegistrerBesok(...)
 */
void nyttBesok()  {
  dognRegistrerBesok(gDogn[lesInt("\tDognnr (1=man, 2=tirs, ... 6=lor, 7=son)",
                                     1, DOGN)-1]);
}


/**
 *  Oppgave 2C - Registrerer ETT besøk i aktuelt døgn.
 *
 *  @param  dogn  -  Døgnet det registreres ETT besøk i
 */
void dognRegistrerBesok(struct Dogn* dogn)  {
  dogn->antall[lesInt("\n\tTime", 0, TIMER-1)]++;  //  Teller opp timebesøket.
}


/**
 *  Oppgave 2D - Nytt besøk registreres AUTOMATISK ved å avlese systemklokka.
 *
 *  @see   dognRegistrerBesok2(...)
 */
void nyttBesok2()  {
  int dag = hentDag();                     //  Henter aktuell dag (1-7).
  printf("\n\tNytt besok registrert dag nr.%i  ", dag);
  dognRegistrerBesok2(gDogn[dag-1]);       //  Registrerer på ukedagen.
}


/**
 *  Oppgave 2D - Registrerer AUTOMATISK ETT besøk i aktuelt døgn.
 *
 *  @param  dogn  -  Døgnet det registreres ETT besøk i
 */
void dognRegistrerBesok2(struct Dogn* dogn)  {
  int time = hentTime();                   //  Henter aktuell time (0-23).
  printf("og time  %i\n", time);
  dogn->antall[time]++;                    //  Teller opp besøk i klokketimen.
}


/**
 *  Oppgave 2E - Finner og skriver dagen og timen med flest legevaktbesøk.
 */
void naarFlestBesok()  {
  int i, j, flest = -1, dag = 0, time = 0;   //  Initierer div.variable.

  for (i = 0;  i < DOGN;  i++)               //  Finner timen med flest besøk:
      for (j = 0;  j < TIMER;  j++)
          if (gDogn[i]->antall[j] > flest)  {  //  Lagrer unna:
             flest = gDogn[i]->antall[j];      //    - flest besøk
             dag = i;                          //    - dagen
             time = j;                         //    - timen
          }                                    //  Skriver ut alt dette, inkl.
  printf("\n\t%s  og timen  %i  har flest besok med  %i  stk\n",  //  dagnavn:
         gDogn[dag]->navn, time, flest);
}


/**
 *  Oppgave 2F - Finner og skriver timen TOTALT i HELE uka
 *               med flest legevaktbesøk.
 */
void naarFlestBesok2()  {
  int i, j, flest = -1, nr, totalt[TIMER];      //  Bl.a. array med TOTALT
                                                //    besøk pr.time.
  for (i = 0;  i < TIMER;  i++)  totalt[i] = 0; //  Nullstiller.

  for (j = 0;  j < DOGN;  j++)                  //  Teller opp TOTALT antall
      for (i = 0;  i < TIMER;  i++)             //    besøk for hver time:
          totalt[i] += gDogn[j]->antall[i];

  for (i = 0;  i < TIMER;  i++)                 //  Finner det største tallet:
      if (totalt[i] > flest)
         flest = totalt[i];

  printf("\n\t%i  er det TOTALT hoyeste antall besok i en time HELE uka.\n",
              flest);
  printf("\tDette er i timen(e): ");
  for (i = 0;  i < TIMER;  i++)                 //  Skriver (alle) timen(e)
      if (totalt[i] == flest)                   //    med flest besøk:
         printf("  %i", i);
  printf("\n");
}


/**
 *  Oppgave 2G - Skriver ALLE døgnene ut til fil.
 *
 *  @see   dognSkrivTilFil(...)
 */
void skrivDognTilFil()  {
  FILE* utfil  = fopen("EX_S25_LEGEVAKT.DT2", "w");  //  Åpner aktuell fil:

  for (int i = 0;  i < DOGN;  i++)
      dognSkrivTilFil(utfil, gDogn[i]);              // Skriver selv.

  printf("\n\n\tDogn er skrevet ut til 'EX_S25_LEGEVAKT.DT2'!\n\n");
}


/**
 *  Oppgave 2G - Skriver ALT om ETT døgn ut til fil.
 *
 *  @param  inn   -  Filen det skal skrives ut til
 *  @param  dogn  -  Døgnet som får skrevet ut sine data
 */
void dognSkrivTilFil(FILE* ut, struct Dogn* dogn)  {
  fprintf(ut, "%s\n%s\n", dogn->navn, dogn->beskrivelse);
  for (int i = 0;  i < TIMER;  i++)            //  Skriver antallet pr. time i
      fprintf(ut, " %i", dogn->antall[i]);     //    døgnets 24 timer.
  fprintf(ut, "\n");
}


/**
 *  Oppgave 2H - Leser ALLE døgnene inn fra fil.
 *
 *  @see   dognLesFraFil(...)
 */
void lesDognFraFil()  {
  FILE* innfil  = fopen("EX_S25_LEGEVAKT.DTA", "r");  //  Åpner aktuell fil:

  if (innfil) {                                 //  Filen finnes:
     for (int i = 0;  i < DOGN;  i++) {         //  Alle døgn lages og leses:
       gDogn[i] = (struct Dogn*) malloc(sizeof(struct Dogn));
       dognLesFraFil(innfil, gDogn[i]);         // Leser selv.
     }
     printf("\n\n\tDogn er lest inn fra 'EX_S25_LEGEVAKT.DTA'!\n\n");
  } else                                        //  Filen ikke funnet:
     printf("\n\tFant ikke filen 'EX_S25_LEGEVAKT.DTA'!\n\n");

  fclose(innfil);                               //  Lukker åpen fil.
}


/**
 *  Oppgave 2H - Leser ALT om ETT døgn inn fra fil.
 *
 *  @param  inn   -  Filen det skal leses inn fra
 *  @param  dogn  -  Døgnet som får innlest sine data
 */
void dognLesFraFil(FILE* inn, struct Dogn* dogn)  {
  char buffer[STRLEN];

  fgets(buffer, STRLEN, inn);             //  Lagrer unna døgnets navn.
  buffer[strlen(buffer)-1] = '\0';        //  Tar vekk '\n' bakerst.
  dogn->navn = (char*) malloc((strlen(buffer) + 1) * sizeof(char));
  strcpy(dogn->navn, buffer);

  fgets(buffer, STRLEN, inn);             //  Lagrer unna døgnets beskrivelse.
  buffer[strlen(buffer)-1] = '\0';        //  Tar vekk '\n' bakerst.
  dogn->beskrivelse = (char*) malloc((strlen(buffer) + 1) * sizeof(char));
  strcpy(dogn->beskrivelse, buffer);

  for (int i = 0;  i < TIMER;  i++)       //  Leser døgnets ulike timebesøk:
      fscanf(inn, "%i", &dogn->antall[i]);
  getc(inn);                              //  Forkaster avsluttende '\n'.
}
