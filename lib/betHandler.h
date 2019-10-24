#include <stdio.h>
#include <stdlib.h>
#include "betStruct.h"


bet *betPlacer(bet *, char *);


bet *betPlacer(bet* head, char *tipoPunt){
    int valPunt, *numPunt = NULL;
    do{
        printf("\n\nQuanti crediti vuoi puntare? ");
    }while(scanf("%d", &valPunt));

    if(!strcmp(tipoPunt, "pari") || !strcmp(tipoPunt, "dispari") ||
       !strcmp(tipoPunt, "manque") || !strcmp(tipoPunt, "passe") ||
       !strcmp(tipoPunt, "rosso") || !strcmp(tipoPunt, "nero")){
           return append(head, tipoPunt, numPunt, valPunt);
       }

}
