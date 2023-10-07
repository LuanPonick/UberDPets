#include <stdio.h>
#include <stdbool.h>
#include <string.h>

void testeFuncao(char teste1[], bool teste2);
int main(){
    // char minhaString[] = "Hello, World!";
    // int i;

    // for (i = 0; minhaString[i] != '\0'; i++) {
    //     minhaString[i] = toupper(minhaString[i]);
    // }

    // printf("String em maiúsculas: %s\n", minhaString);

    // return 0;

    char teste[] = "valor foda";
    bool top = true;

    testeFuncao(teste, top);
}

void testeFuncao( char teste1[], bool teste2){
    printf("%s %d", teste1, teste2);
}

