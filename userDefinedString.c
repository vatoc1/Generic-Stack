#include "userDefinedString.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



void PrintString(void * str) {
    char * x = *(char**)str;
    printf("%s ",x);
}

void StringDispose(void * str) {
    char ** temp=(char**)str;
    
    
    free(*temp);




    free(temp);



}


void StringPop(void * str) {
    char ** temp=(char**)str;
    free(temp);
    
}