#include <stdio.h>
#include <math.h>
#include <string.h>

#define MAX 10
#define MAXNUM 4




/* COMUNICAZIONI
L: "Puntate base:
        pari e dispari X1
        manque e passe X1 (1-18, 19-36)
        rosso e nero X1
        dozzine X2 (1-12, 13-24, 25-36)
        colonne X2
        sestine X5
        carrè X8 (gruppi da 4)
        terzine X11 (righe, 012, 023)
        cavalli X17 (coppie)
        singole X35"
*/


typedef struct puntata{
    char tipo[MAX];
    int numeri[MAXNUM];
    int valore;
	struct puntata *next;
} punt;/*L: la struct è da rifinire una volta che decidiamo assieme come
            codificare le puntate"*/

       
int ricarica(int, int);
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

        scanf("%c%c", &sceltaMenu, &nweLine);

        switch (sceltaMenu){

            case '1':
                printf("Ricarica \n\n");
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
               "B->menu precedente \n"
               "Inserisci la scelta e premi invio: ");
        
        scanf("%c%c", &sceltaGioco, &newLine);
        
        switch (sceltaGioco){

            case '1':
                printf("Punta sei neri");
                break;

            case '2':
                printf("Punta sui rossi");
                break;

            case '3':
                printf("Punta su un numero");
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