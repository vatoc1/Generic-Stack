#include <stdlib.h>
#include "stack.c"
#include "userDefinedString.c"





int main() {
    
    char * x = strdup("Tony");
    char * y = strdup("Paulie");
    char * z = strdup("Silvio");

    Stack s;
    StackInit(&s,sizeof(char*),StringDispose,StringPop); 
    StackPush(&s,&x);
    StackPush(&s,&z);
    StackPush(&s,&y);
   
    StackPrint(&s,PrintString);
    printf("\n");
    
    StackPop(&s,ptr);

   
    StackDispose(&s);


    






    
    

    return 0;

}