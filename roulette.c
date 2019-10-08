#include <stdio.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

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


typedef struct puntata{
    char tipo[MAX];
    int numeri[MAXNUM];
    int valore;
	struct puntata *next;
} punt;/*L: la struct è da rifinire una volta che decidiamo assieme come
            codificare le puntate"*/


/*int ricarica(int, int);*/
int ricarica(int s){
  int tmp;
  printf("inserisci il valore della ricarica che si vuole effettuare-> \n" );
  scanf("%d", &tmp);
  s=s+tmp;
  return s;
}
/*AF:int generator(){
  int n;
  srand(time(NULL));
  n=0+rand()%37;
  printf(" numero generato %d\n",n );
  return n;
}*/
void gioco();


int  main(int argc, char *argv[]) {
    char sceltaMenu, nweLine;
    int bilancio = 10000, quit = 0;

    /* printf("Benvenuto, bonus di primo accesso di 10000pt \n");*/
    while(!quit){
        printf("\n\n MENU \n"
            "1->carica credito \n"
            "2->gioca \n"
            "3->visulizza saldo \n"
            "Q->esci \n\n"
            "Inserisci la scelta e premi invio: ");

        scanf("%c%c", &sceltaMenu, &newLine);

        switch (sceltaMenu){

            case '1':
                printf("Ricarica \n\n");
                bilancio=ricarica(bilancio);
                break;

            case '2':
                gioco();
                break;

            case '3':
                printf("La disponibilità è di %d crediti \n\n", bilancio);
                break;

            case 'Q':
                quit = 1;
                break;

            default:
                printf("Errore nella scelta del menu");
                break;
        }
    }
    printf("vaffanculo\n");
    return 0;
}

void gioco(){
    char sceltaGioco, newLine;
    int quitGioco = 0;

    while (!quitGioco){
        printf("\n\n MENU GIOCATE \n"
               "1->punta sui neri \n"
               "2->punta sui rossi \n"
               "3->punta su un numero \n"
               "4->punta su una sestina\n"
               "5->punta su una colonna\n"
               "6->punta su un passe\n"
               "7->punta su un manque\n"
               "8->punta su una dozzina (prima, seconda o terza)\n"
               "9->punta sui cavalli\n"
               "P->punta sui pari\n"
               "D->punta sui dispari\n"
               "C->punta sui carrè\n"
               "T->punta su una terzina\n"
               "B->menu precedente \n"
               "Inserisci la scelta e premi invio: ");

        scanf("%c%c", &sceltaGioco, &newLine);

        switch (sceltaGioco){

            case '1':
                printf("Punta sui neri");
                break;

            case '2':
                printf("Punta sui rossi");
                break;

            case '3':
                printf("Punta su un numero");
                break;
            case '4':
                printf("Punta su una sestina");
                break;
            case '5':
                printf("Punta su una colonna");
                break;
            case '6':
                printf("Punta su un passe");
                break;
            case '7':
                printf("Punta su un manque");
                break;
            case '8':
                printf("Punta su una dozzina");
                break;
            case '9':
                printf("Punta sui cavalli");
                break;
            case 'P':
                printf("Punta sui pari");
                break;
            case 'D':
                printf("Punta sui dispari");
                break;
            case 'C':
                printf("Punta su un carre");
                break;
            case 'T':
                printf("Punta su una terzina");
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
