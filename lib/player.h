#include <stdio.h>


typedef struct giocatore{
    char *username;
    char *passwordHash;
    int saldo;
} player;


void login();

void login(){
    char *username;
    FILE *fp;

    printf("Inserisci il tuo username: ");
    scanf("%s", &username);

    if(fp = fopen("users", "rb")){
        
    }

}
