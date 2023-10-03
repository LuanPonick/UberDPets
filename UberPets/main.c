#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <regex.h>
#include <unistd.h>

int main(){
    char userName[] = "";    
    //end declarentions

    pedirNome(userName);
    printf(userName);
    
    return 1;
}

void pedirNome(char* name[]){
    regex_t regex;
    int reti;
    
    inicio:
    
    printf("Digite o nome do usuario: ");
    fgets(name, sizeof(name), stdin); 
    
    reti = regcomp(&regex, "^[^0-9]*$", 0);
    reti = regexec(&regex, name, 0, NULL, 0);
    if (!reti) {
        return;
    } else {
        printf("favor digite um nome valido...");
        printf("\n");
        usleep(2000000);
        goto inicio;
    }
}
