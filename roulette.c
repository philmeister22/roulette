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
  using namespace std;
  char sc;
  int dsp=10000;
  char gc;
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
          printf("4-menu precedente\n");
          printf("scegli -> \n");
          scanf("%c",&gc );


        } while(gc!='4');
      break;
      case '3':
        printf("la disponibilità è %d\n", dsp );
        break;
    }
  } while(sc!= '0');
  printf("vaffanculo\n");
  return 0;
}
