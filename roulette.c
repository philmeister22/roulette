#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX 10
#define MAXNUM 4


/* COMUNICAZIONI
L: "Puntate base:
        pari e dispari X1
        manque e passe X1 (1-18, 19-36)-
        rosso e nero X1-
        dozzine X2 (1-12, 13-24, 25-36)-
        colonne X2-
        sestine X5-
        carrè X8 (gruppi da 4)-
        terzine X11 (righe, 012, 023)-
        cavalli X17 (coppie)-
        singole X35"
*/


/* struct corrispondente a una giocata:
    tipo: nome della puntata fatta (rossi, pari, cavallo...)
    numeri: array contenente i numeri della giocata, vuoto nel caso siano
            puntate esterne
    valore: il valore in crediti della puntata
    vincente: bool per indicare se la giocata è vincente
    next: pointer alla struct successiva*/
typedef struct puntata{
    char tipo[MAX];
    int numeri[MAXNUM];
    int valore;
    int vincente;
	struct puntata *next;
} punt;


int ricarica(int);
int generatore();
void gioco();


int  main(int argc, char *argv[]) {
    char sceltaMenu, newLine;
    int bilancio = 10000, quit = 0;

    /* printf("Benvenuto, bonus di primo accesso di 10000pt \n");*/
    while(!quit){
        printf("\n\n MENU \n"
            "1 -> carica crediti \n"
            "2 -> gioca \n"
            "3 -> visulizza ssaldo bilancio \n"
            "Q -> esci \n\n"
            "Inserisci la scelta e premi invio: ");

        scanf("%c%c", &sceltaMenu, &newLine);
        /*FIXME: se si ricarica poi l'input ha problemi nella lettura/e successiva/e*/
        switch (sceltaMenu){

            case '1':
                bilancio = ricarica(bilancio);
                break;

            case '2':
                gioco();
                break;

            case '3':
                printf("Il saldo del bilancio è di %d crediti \n\n", bilancio);
                break;

            case 'Q':
                quit = 1;
                break;

            default:
                printf("Errore nella scelta del menu");
                break;
        }
    }
    printf("Arrivederci! \n");
    return 0;
}


void gioco(){
    char sceltaGioco, newLine;
    int quitGioco = 0;

    while (!quitGioco){
        printf("\n\n MENU GIOCATE \n"
               "Puntate semplici: \n"
               "\t 0 -> punta su pari o dispari  \n"
               "\t 1 -> punta su manque (1-18) o passe (19-36) \n"
               "\t 2 -> punta su rosso o nero \n"
               "\t 3 -> punta su 1a, 2a o 3a dozzina \n"
               "\t 4 -> punta su 1a, 2a o 3a colonna \n"
               "\t 5 -> punta su una sestina \n"
               "\t 6 -> punta su un carrè (quartina) \n"
               "\t 7 -> punta su una terzina \n"
               "\t 8 -> punta su un cavallo (coppia) \n"
               "\t 9 -> punta su un numero pieno\n"
               "\t B -> menu precedente \n"
               "Inserisci la scelta e premi invio: ");

        scanf("%c%c", &sceltaGioco, &newLine);

        switch (sceltaGioco){

            case '0':
                printf("pari dispari");
                break;

            case '1':
                printf("manque passe");
                break;

            case '2':
                printf("rosso nero");
                break;

            case '3':
                printf("dozzina");
                break;

            case '4':
                printf("colonna");
                break;

            case '5':
                printf("sestina");
                break;

            case '6':
                printf("carrè");
                break;

            case '7':
                printf("terzina");
                break;

            case '8':
                printf("cavallo");
                break;

            case '9':
                printf("numero pieno");
                break;

            case 'B':
                quitGioco = 1;
                break;

            default:
               printf("Errore nella scelta del menu");
               break;
        }
    }
}


int ricarica(int bilancio){
  int importo;
  printf("Inserire l'importo che si vuole ricaricare e premere invio: ");
  scanf("%d", &importo);
  return bilancio + importo;
}


int generatore(){
  int numVincente;
  srand(time(NULL));
  return rand() % 37; /* modulo 37 è per ottenere un numero tra 0 e 36*/

  /* numVincente = rand() % 37;
  printf("Il numero vincente è %d \n", numVincente);
  return n;*/
}
