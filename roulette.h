#include <stdio.h>
#include <stdlib.h>


/* struct corrispondente a una giocata:
    tipo: nome della puntata fatta (rossi, pari, cavallo...)
    numeri: array contenente i numeri della giocata, vuoto nel caso siano
            puntate esterne
    valore: il valore in crediti della puntata
    vincente: bool per indicare se la giocata è vincente
    next: pointer alla struct successiva*/
typedef struct puntata{
    char *tipo;
    int *numeri;
    int valore;
    int vincente;
	struct puntata *next;
} bet;


bet *append(bet *, char *, int[], int); /*append(betlist, tipo, valore)*/


bet *append(bet *head, char tipoPunt[], int numPunt[], int valPunt){

	bet *tmp;
	bet *ptr;
	if(tmp = (bet*)malloc(sizeof(bet))){
        tmp->tipo = tipoPunt;
        tmp->numeri = numPunt;
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
