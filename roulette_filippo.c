#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

struct puntata{// struct contenente la coppia valore/tipo di puntata
    char tipo;
    int valore;
	struct puntata *succ;
};
typedef struct puntata *punt;

void n_puntata(punt *l);
int  main() {
  punt np = NULL;
  char sc;
  int dsp=10000;
  char gc;
  int rossi[]={1,3,5,7,9,12,14,16,18,19,21,23,25,27,30,32,34,36}; // array contenente tutti i numeri rossi
  int neri[]={2,4,6,8,10,11,13,15,17,20,22,24,26,28,29,31,33,35}; //array contenente tutti i numeri neri
  int range1[]={1,2,3,4,5,6,7,8,9,10,11,12};
  int range2[]={13,14,15,16,17,18,19,20,21,23,24};
  int range3[]={25,26,27,28,29,30,31,32,33,34,35,36};
  int riga1[]={1,4,7,10,13,16,19,22,25,28,31,34};
  int riga2[]={2,5,8,11,14,17,20,23,26,29,32,35};
  int riga3[]={3,6,9,12,15,18,21,24,27,30,33,36};
  /*struct giocate[]; array contente i valori delle singole puntate (es 10 sui rossi e 1 su un numero nella stessa partita)
                      L: Non si dichiara così un array di struct*/
  printf("buongiorno, bonus di primo accesso di 10000pt\n");
  do {
    printf("menu\n");
    printf("1-carica credito\n");
    printf("2-gioca \n");
    printf("3-visulizza saldo\n");
    printf("0-esci\n" );
    printf("scegli ->  ");
    scanf("%c", &sc);
    switch (sc) {
      case('1'):
		//dsp=ricarica(dsp);
      break;
      case '2':
		n_puntata(&np);
      break;
      case '3':
        printf("la disponibilità è %d\n", dsp );
        break;
      }
  } while(sc!= '0');
  printf("vaffanculo\n");
  return 0;
}

void n_puntata(punt *l){
	int n=0,val=0;
	int tipo,exit=0;
	printf("\nQuante puntate vuoi fare?\n> ");
	scanf("%d", &n);
	for(int i=0;i<n;i++){
		printf("\nPuntata n° %d\n", i+1);
		while(exit!=1){
			printf("\nChe tipo di puntata vuoi fare?\n");
			printf("1-punta sui neri\n");//data x capiacita di un secchio e y in un'altro secchio trovare z in un'altro secchio
			printf("2-punta sui rossi\n");
			printf("3-punta su un numero\n");
			printf("4-punta sui numeri pari\n");
			printf("5-punta sui numeri dispari\n");
			printf("6-punta sui primi 12 (1-12)\n");
			printf("7-punta sui secondi 12 (13-24)\n");
			printf("8-punta sui terzi 12 (25-36)\n");
			printf("9-punta su una riga\n");
			printf("0-gioca\n");
			printf("B-menu precedente\n");
			printf("scegli -> \n");
			scanf("%d", &tipo); //F: tipo di puntata
			switch(tipo){
				case '0':
				  exit=1;
				break;
				case '1':
				//code
				break;
				case '2':
				  //code
				break;
				case '3':
				  //code
				break;
				case '4':
				  //code
				break;
				case '5':
				  //code
				break;
				case '6':
				  //code
				break;
				case '7':
				  //code
				break;
				case '8':
				  //code
				break;
				case '9':
				  //code
				break;
				
			}
		}
		printf("\n\nQuanto vuoi puntare?\n> ");
		scanf("%d", &val); //F: valore puntata singola
	}
}
