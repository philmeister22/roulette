#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PLAYERS_FILE "players.txt"
#define MAX_USERNAME 30
#define MAX_PASSWORD


typedef struct giocatore{
    char username[MAX_USERNAME + 1];
    char *passwordHash;
    int saldo;
} player;


player *login();                        /* mostra prompt di login/registrazione, returna
                                        la struct del giocatore */
int checkUsername(char *);              /* controlla che l'username contenga soltanto
                                        [0-9, A-Z, a-z], returna 0 se non corretto */
player *userExist(char *);              /* controlla l'esistenza del player nel file,
                                        returna null se non esiste */
void serialize(player *);          /* stampa la struct fornita nel file predefinito */
player deserialize(char *);


player *login(){

    char inputName[MAX_USERNAME + 1], flush;
    player *player;

    do{
        printf("\nInserisci il tuo username: ");
        scanf("%30s", inputName);
        while ((flush = fgetc(stdin)) != '\n' && flush != EOF);     /* flush buffer */
    }while(!checkUsername(inputName));

    userExist(inputName);

    /* printf("Il tuo username \x8A %s ed \x8A lungo %d caratteri!", inputName, strlen(inputName)); */

    return player;
}


int checkUsername(char *username){
    int i = 0;

    for(i = 0; i < strlen(username); i++){
        if(username[i] < 48 ||                            /* prima dei numeri */
           (username[i] > 57 && username[i] < 65) ||      /* tra numeri e maiuscole */
           (username[i] > 90 && username[i] < 97) ||      /* tra maiuscole e minuscole */
           username[i] > 122){                            /* dopo minuscole */
               printf("\nAssicurati che l'username inserito"
                      "contenga solamente lettere e numeri! \n\n");

               return 0;
           }
    }

    return 1;
}


player *userExist(char *username){
    FILE *fp;
    char tmpName[MAX_USERNAME + 1] = {0};
    int tmpSaldo = 0;

    if((fp = fopen(PLAYERS_FILE, "r"))){

        while(!feof(fp)){
            fscanf(fp, "%[^;];%d ", &tmpName, &tmpSaldo);
            printf("%s | %s  %d \t", username, tmpName, tmpSaldo);

            if(!strcmp(username, tmpName)){
                printf("Sono uguali!\n");
            }
            else{
                printf("Sono diversi!\n");
            }

        }

    }else
        printf("Errore nell'apertura del file %s\n\n", PLAYERS_FILE);


}


void serialize(player* out){

    FILE *fp;
    char *tmp;

    if(tmp = malloc(sizeof(char) * sizeof(*(out))))
        sprintf(tmp, "%s;%d", out->username, out->saldo);
    else
        printf("Errore allocazione memoria per stampa a file\n\n");

    if(fp = fopen(PLAYERS_FILE, "a")){
        fprintf(fp, "%s\n", tmp);
        free(tmp);
    }else
        printf("Errore nell'apertura del file %s\n\n", PLAYERS_FILE);

}


/*
    player = malloc(sizeof(player));
    strcpy(player->username, inputName);
    player->saldo = 10000;

    serialize(fp, player, sizeof(player));
    fclose(fp);

    return 0;
}
*/
