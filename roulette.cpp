/*Luca: io consiglierei di mantenere il progetto in C, visto e considerato che è ciò che studieremo*/

#include<iostream>
#include<stdio.h>
#include<math.h>
int ricarica(int s){
  int tmp;
  printf("quanto vuoi aggiugere?\n" );
  scanf("%d", &tmp);
  s=s+tmp;
  return s;
}
int  main(int argc, char const *argv[]) {
  struct puntata{// struct contenente la coppia valore/tipo di puntata
    int valore;
    char tipo;
  };

  using namespace std;
  char sc;
  int dsp=10000;
  char gc;
  int rossi[]={1,3,5,7,9,12,14,16,18,19,21,23,25,27,30,32,34,36}; // array contenente tutti i numeri rossi
  int neri[]={2,4,6,8,10,11,13,15,17,20,22,24,26,28,29,31,33,35}; //array contenente tutti i numeri neri
  int  n; // numero di giocate che un singolo giocatore vuole fare in una mano
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
      dsp=ricarica(dsp);
      break;
      case '2':
        do {
          printf("menu\n");
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
          scanf("%c",&gc );
          printf("inserisci il numero delle puntate che vuoi fare\n");
          scanf("%d",&n );
          //fare ciclo per caricare l'array con la puntata e il relativo tipo sulla base dell'n inserito dall'utente
          switch (gc) {
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
            case '0':
              //code
            break;


          }

        } while(gc!='B');
      break;
      case '3':
        printf("la disponibilità è %d\n", dsp );
        break;
    }
  } while(sc!= '0');
  printf("vaffanculo\n");
  return 0;
}
