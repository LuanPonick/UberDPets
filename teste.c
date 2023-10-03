#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int main(){
    char userName[] = "";    
    //end declarentions

    pedirNome(userName);
    printf(userName);
}

void pedirNome(char *name[]){

    for (int i = 0; i < 3; i++)
    {
        printf(".");
    }
    
}