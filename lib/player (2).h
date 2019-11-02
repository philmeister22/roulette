#include <stdio.h>
#include <string.h>
#include "openssl/evp.h"
#include "openssl/sha.h"
#include "openssl/rand.h"


#define MAX_USERNAME 10
#define MAX_PASSWORD

typedef struct giocatore{
    char username;
    char *passwordHash;
    int saldo;
} player;


void login();

void login(){
    char *username;
    char *input = "test";
    int length = 4;
    FILE *fp;

    /* more ITERATIONs, more secure. But you should consider the performance on your target machine */
    int ITERATION = 512000;

    /* this will be the result of PBKDF2-HMAC-SHA1 */
    int SHA1_LEN = 20;
    unsigned char* out = (unsigned char*)calloc(SHA1_LEN, sizeof(unsigned char));

    int SALT_LEN = 5;
    unsigned char* salt = (unsigned char*)calloc(SALT_LEN, sizeof(unsigned char));
    RAND_bytes(salt, SALT_LEN);

    PKCS5_PBKDF2_HMAC_SHA1(input, strlen(input), salt, SALT_LEN, ITERATION, SHA1_LEN, out);
    printf("%s", out);
}
