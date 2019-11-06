#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SAVE_FILE "players.txt"
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
player *userExist(char *);      /* controlla l'esistenza del player nel file,
                                returna null se non esiste */
void serialize(player *);       /* stampa la struct fornita nel file predefinito */


player *login(){

    char inputName[MAX_USERNAME + 1], sceltaNewp;
    player *player = NULL;
    FILE *fp;


    if(!(fp = fopen(SAVE_FILE, "r"))){
        while(1){
            printf("\nIl tuo salvataggio risulta inesistente, vuoi crearne uno nuovo(N)"
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
            printf("\nInserisci il tuo username: ");
            scanf(" %30s", inputName);
        }while(!checkUsername(inputName));

        player = userExist(inputName);
    }

    /* printf("Il tuo username \x8A %s ed \x8A lungo %d caratteri!", inputName, strlen(inputName)); */

    return player;
}


/* TODO: create register user function*/
player *newPlayer(){
    printf("Nuovo utente!!");
    return NULL;
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
                while(1){
                    printf("\nL'utente inserito non esiste! \n"
                           "Vuoi registrarti(R) oppure inserire un altro username(U)? ");
                    scanf(" %c%*[^]", &sceltaNewp);
                    printf("\n");
                    sceltaNewp = toupper(sceltaNewp);

                    if(sceltaNewp == 'R') return newPlayer();
                    else if(sceltaNewp == 'U') return tmp;
                    else printf("\nErrore nella scelta inserita \n");
                }
            }
        }
    }else
        printf("Errore nell'apertura del file %s\n\n", SAVE_FILE);

    return tmp;
}


void serialize(player* out){

    FILE *fp;
    char *tmp;

    if(tmp = malloc(sizeof(char) * sizeof(*(out))))
        sprintf(tmp, "%s;%d", out->username, out->saldo);
    else
        printf("Errore allocazione memoria per stampa a file\n\n");

    if(fp = fopen(SAVE_FILE, "a")){
        fprintf(fp, "%s\n", tmp);
        free(tmp);
    }else
        printf("Errore nell'apertura del file %s\n\n", SAVE_FILE);

}
