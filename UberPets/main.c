#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <regex.h>
#include <unistd.h>

void pedirNome( char** name[] );
void pedirConfirmacao( char** resposta[], bool regex, char value[], char nomeFuncao[] );
void tipoDeCadastro( char **valor[] );

int main(){
    char userName[] = ""; 
    char escolhaCadastroDeUsuario[] = "";
    //end declarentions
    
    //tipoDeCadastro( escolhaCadastroDeUsuario );
    pedirNome( userName );
    printf(userName);
    
    return 1;
}

void pedirNome(char** name[]){
    regex_t regex;
   
    
    pedirNomeInicio:
    //pega nome de entrada
    printf( "Digite o nome do usuario: " );
    fgets( name, sizeof(name), stdin );
    char resp[] = ""; 
    pedirConfirmacao(resp, true, name, "pedirNome");
    printf("%s: animal",resp);
    
}
void pedirConfirmacao( char** resposta[], bool regex, char value[], char nomeFuncao[]){
    //regra regex -> nao permitir numero! 
    int reti;
    reti = regcomp( &regex, "^[^0-9]*$", 0 );
    reti = regexec( &regex, value, 0, NULL, 0 );
    
    pedirNomeConfirmacao:
         
    //testa se o nome é valido na regra do regex
    if ( reti && regex) {
        printf("antes");
        //printf( "favor não digite numeros...\n " );
        //usleep( 2000000 );
        strcat(nomeFuncao, "Inicio");
        resposta = nomeFuncao;
        printf("teste %s",resposta);
    }   
    //confirmaçao
    char chose[] = ""; 
    printf( "voce digitou %s", value );
    printf( "esta correto? (Y/N)" );
    scanf(" %c", chose);
    chose[0] = toupper(chose[0]);
    
    //testa se o resultado de entrada é Y/y caso nao ele pergunta novamente
    if( strcmp( chose, "Y") == 0 ){
        resposta = "ok";
        return;
    }else if( strcmp( chose, "N") == 0 ){
        resposta = "pedirNomeInicio";
    }else{
        printf("favor digite Y ( sim ) ou N ( não )... \n");
        usleep(1000000);
        goto pedirNomeConfirmacao;
    }
}

void tipoDeCadastro( char **valor[] ){
    char temp;
    
    tipoDeCadastroInicio:
    printf( "qual seria a forma de cadastro? " );
    printf( "( 1 ) Cliente " );
    printf( "( 2 ) Motorista " );
    fgets( temp, sizeof(temp), stdin ); 
    if(strcmp( temp, "1") == 0 ){
        return;
    }else if( strcmp( temp, "2") == 0 ){
        return;
    }
    printf("favor digite Um valor valido... \n");
    usleep(1000000);
    goto tipoDeCadastroInicio;
    
}