#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <roulette.h>


#define EVEN_ODD_WIN 1
#define MANQUE_PASSE_WIN 1    /*(1-18, 19-36)*/
#define RED_BLK_WIN 1
#define DOZZ_WIN 2    /*(1-12, 13-24, 25-36)-*/
#define COLUMN_WIN 2
#define SEXTINE_WIN 5
#define CARRE_WIN 8    /*(gruppi da 4)*/
#define TRIPLET_WIN 11    /*(righe, 012, 023)*/
#define DOUBLE_WIN 17    /*(coppie)*/
#define SINGLE_WIN 35


/* COMUNICAZIONI
L: ho mosso la struct in roulette.h
*/


int ricarica(int);
int generatore();
void gioco();


int  main(int argc, char *argv[]){
    int rossi[]={1,3,5,7,9,12,14,16,18,19,21,23,25,27,30,32,34,36};
    int neri[]={2,4,6,8,10,11,13,15,17,20,22,24,26,28,29,31,33,35};
    char sceltaMenu;
    int bilancio = 10000, quit = 0;

    while(!quit){
        printf("\n\n"
               "-----MENU----- \n"
               "1 -> carica crediti \n"
               "2 -> gioca \n"
               "3 -> visulizza saldo bilancio \n"
               "Q -> esci \n\n"
               "Inserisci la scelta e premi invio: ");

        scanf("%c", &sceltaMenu);
        fflush(stdin);

        switch (sceltaMenu){

            case '1':
                bilancio = ricarica(bilancio);
                break;

            case '2':
                gioco();
                break;

            case '3':
                printf("Il saldo del bilancio e' di %d crediti \n\n", bilancio);
                break;

            case 'q':   /*per intercettare anche le minuscole*/
            case 'Q':
                quit = 1;
                break;

            default:
                printf("Errore nella scelta del menu");
                break;
        }
    }
    printf("\n\n"
           "Arrivederci! \n");
    return 0;
}


void gioco(){
    char sceltaGioco;
    int quitGioco = 0;

    while (!quitGioco){
        printf("\n\n -----MENU GIOCATE----- \n"
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
               "\t G -> lancia la pallina\n"
               "\t B -> menu precedente \n"
               "Inserisci la scelta e premi invio: ");

        scanf("%c", &sceltaGioco);
        fflush(stdin);

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

            case 'g':   /*per intercettare anche le minuscole*/
            case 'G':
                printf("numero vincente %d", generatore());
                break;

            case 'b':   /*per intercettare anche le minuscole*/
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
  fflush(stdin);
  return bilancio + importo;
}


int generatore(){
  srand(time(NULL));
  return rand() % 37;
}
