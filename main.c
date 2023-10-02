#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int main(){
    bool isFinished = true;

    do{
        pedirNome();
    }while( !isFinished );
    
    return 0;
}

void pedirNome(){
    printf("digite o nome do usuario");
    char teste[5];
    fgets(teste, sizeof(teste), stdin); 
    printf(teste);
}