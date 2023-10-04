#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int main(){
    char minhaString[] = "Hello, World!";
    int i;

    for (i = 0; minhaString[i] != '\0'; i++) {
        minhaString[i] = toupper(minhaString[i]);
    }

    printf("String em maiúsculas: %s\n", minhaString);

    return 0;
}

