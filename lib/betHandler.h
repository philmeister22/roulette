#include <stdio.h>
#include "betStruct.h"


bet *betPlacer(bet *, char *);


bet *betPlacer(bet* head, char *tipoPunt){

    if(tipoPunt == "pari" || tipoPunt == "dispari" ||
       tipoPunt == "manque" || tipoPunt == "passe" ||
       tipoPunt == "rossi" || tipoPunt =="neri"){ 
           printf("bella pulcini");
       }
    else{
        printf("sticazzi");
    }

}
