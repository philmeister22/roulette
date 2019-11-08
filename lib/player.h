#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SAVE_FILE "players.txt"
#define SALDO_INIZIALE 1000
#define MAX_USERNAME 30
#define MAX_PASSWORD


typedef struct giocatore{
    char username[MAX_USERNAME + 1];
    char *passwordHash;
    int saldo;
} player;


player *login();                /* mostra prompt di login/registrazione, returna
                                la struct del giocatore */
player *newPlayer();            /* registra e fa login di un nuovo utente */
int checkUsername(char *);      /* controlla che l'username contenga soltanto
                                [0-9, A-Z, a-z], returna 0 se non corretto */
player *userExist(char *, int); /* controlla l'esistenza del player nel file,
                                se non esiste chiede all'utente se vuole registrarsi
                                o riprovare, flag controlla soltanto se esiste o no*/
void serialize(player *);       /* stampa la struct fornita nel file predefinito */


player *login(){

    char inputName[MAX_USERNAME + 1], sceltaNewp;
    player *player = NULL;
    FILE *fp;


    if(!(fp = fopen(SAVE_FILE, "r"))){
        while(1){
            printf("\nIl tuo salvataggio risulta inesistente, vuoi crearne uno nuovo(N) "
                "oppure vuoi chiudere(C) il gioco? ");
            scanf(" %c%*[^]", &sceltaNewp);
            printf("\n");
            sceltaNewp = toupper(sceltaNewp);

            if(sceltaNewp == 'N'){
                fp = fopen(SAVE_FILE, "w+");
                fclose(fp);
                return newPlayer();
            }else if(sceltaNewp == 'C')
                exit(0);
            else
                printf("\nErrore nella scelta inserita \n");
            }
    }


    while(!player){
        do{
            printf("\nInserisci il tuo username oppure (+) per crearne un nuovo utente: ");
            scanf(" %30s", inputName);
        }while(!checkUsername(inputName));

        player = userExist(inputName, 1);
    }

    /* printf("Il tuo username \x8A %s ed \x8A lungo %d caratteri!", inputName, strlen(inputName)); */

    return player;
}


player *newPlayer(){
    player *tmp = NULL;
    char inputName[MAX_USERNAME + 1];


    do{
        printf("\nInserisci l'username che vuoi: ");
        scanf(" %30s", inputName);
        }while(!checkNewUser(inputName));

    tmp = (player *) malloc(sizeof(player));

    strcpy(tmp->username, inputName);
    tmp->saldo = SALDO_INIZIALE;

    serialize(tmp);

    return tmp;
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


player *userExist(char *username, int flag){

    FILE *fp;
    player *tmp = NULL;
    char sceltaNewp, tmpName[MAX_USERNAME + 1] = {0};
    int tmpSaldo = 0;

    if((fp = fopen(SAVE_FILE, "r"))){

        while(!feof(fp)){
            fscanf(fp, "%[^;];%d ", &tmpName, &tmpSaldo);
            /* printf("\n%s | %s  %d \t", username, tmpName, tmpSaldo); */

            if(!strcmp(username, tmpName)){
                tmp = (player *) malloc(sizeof(player));
                strcpy(tmp->username, tmpName);
                tmp->saldo = tmpSaldo;

                return tmp;
            }
            else{
                while(flag){
                    printf("\nL'utente inserito non esiste! \n"
                           "Vuoi registrarti(R) oppure inserire un altro username(U)? ");
                    scanf(" %c%*[^]", &sceltaNewp);
                    printf("\n");
                    sceltaNewp = toupper(sceltaNewp);

                    if(sceltaNewp == 'R')
                        return newPlayer();
                    else if(sceltaNewp == 'U')
                        return tmp;
                    else
                        printf("\nErrore nella scelta inserita \n");
                }
            }
        }
    }else
        printf("Errore nell'apertura del file %s\n\n", SAVE_FILE);

    return tmp;
}


int checkNewUser(char *username){
    if(!checkUsername(username))
        return 0;
    if(userExist(username, 0)){
        printf("L'username \"%s\" non è disponibile", username);
        return 0;
    }

    return 1;
}


void serialize(player* out){

    FILE *fp;
    char *tmp;

    if(tmp = malloc(sizeof(char) * sizeof(*(out)))){
        sprintf(tmp, "%s;%d", out->username, out->saldo);
        printf("%s | %s %d", tmp, out->username, out->saldo);
    }
    else
        printf("Errore allocazione memoria per stampa a file\n\n");

    if(fp = fopen(SAVE_FILE, "a")){
        fprintf(fp, "%s\n", tmp);
        free(tmp);
        fclose(fp);
    }else
        printf("Errore nell'apertura del file %s\n\n", SAVE_FILE);

}
