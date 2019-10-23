#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef BETSTRUCT_H_
#define BETSTRUCT_H_

#define MAXCHAR 8
#define MAXINT 4


/* struct corrispondente a una giocata:
    tipo: nome della puntata fatta (rossi, pari, cavallo...)
    numeri: array contenente i numeri della giocata, vuoto nel caso siano
            puntate esterne
    valore: il valore in crediti della puntata
    vincente: bool per indicare se la giocata è vincente
    next: pointer alla struct successiva */
typedef struct puntata{
    char tipo[MAXCHAR];
    int numeri[MAXINT];
    int valore;
    int vincente;
	struct puntata *next;
} bet;


bet *append(bet *, char *, int[], int); /*append(listHead, tipo, valore)*/
void freelist(bet *); /*freelis(listHead)*/


/*aggiunge una struct alla lista fornita con head*/
bet *append(bet *head, char tipoPunt[], int numPunt[], int valPunt){

	bet *tmp;
	bet *ptr;

	if((tmp = (bet*)malloc(sizeof(bet)))){

        int i;

        for(i = 0; i <= strlen(tipoPunt); i++){
            tmp->tipo[i] = tipoPunt[i];
        }
        for(i = 0; i <= *(numPunt - 1); i++){
            tmp->numeri[i] = numPunt[i];
        }
		tmp->valore = valPunt;
		tmp->next=NULL;

		if(head==NULL)    /*se la lista è ancora vuota*/
			head = tmp;

		else{
			for(ptr = head; ptr->next!=NULL; ptr = ptr->next);    /*mi porto alla fine della lista*/

			ptr->next = tmp;
		}

	}else
		printf("Tentativo di allocazione memoria fallito: la puntata"
               " su %s di %d crediti non è stata effettuata \n\n",
               tipoPunt, valPunt);

	return head;
}


/*svuota completamente la lista fornita con head*/
void freelist(bet *head){

   bet* tmp;

   while (head != NULL)
    {
       tmp = head;
       head = head->next;
       free(tmp);
    }

	return;
}

#endif