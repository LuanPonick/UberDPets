#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <regex.h>
#include <unistd.h>

int main(void){
    char userName[] = "";    
    //end declarentions

    pedirNome( userName );
    printf(userName);
    
    return 1;
}

void pedirNome(char** name[]){
    regex_t regex;
    int reti;
    
    pedirNomeInicio:
    //pega nome de entrada
    printf( "Digite o nome do usuario: " );
    fgets( name, sizeof(name), stdin ); 
    
    reti = regcomp( &regex, "^[^0-9]*$", 0 );
    reti = regexec( &regex, name, 0, NULL, 0 );
    
    pedirNomeConfirmacao:

    //testa se o nome é valido
    if ( reti ) {
        printf( "favor digite um nome valido...\n " );
        usleep( 2000000 );
        goto pedirNomeInicio;
    }
    
    //confirmaçao
    char chose[] = ""; 
    printf( "voce digitou %s", name );
    printf( "esta correto? (Y/N)" );
    scanf(" %c", chose);
    
    //transforma toda a entrada em maisculas.
    for (int i = 0; chose[i] != '\0'; i++) {
        chose[i] = toupper(chose[i]);
    }
    
    //testa se o resultado de entrada é Y/y caso nao ele pergunta novamente
    if( strcmp( chose, "Y") == 0 ){
        return;
    }else if( strcmp( chose, "N") == 0 ){
        goto pedirNomeInicio;
    }
    printf("favor digite Y ( sim ) ou N ( não )... \n");
    usleep(1000000);
    goto pedirNomeConfirmacao;
}
