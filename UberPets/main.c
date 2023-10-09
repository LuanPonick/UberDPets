#include <stdio.h>
#include <string.h>
/*
*
* repositorio desse código https://github.com/LuanPonick/UberDPets .
*
*/
// Estrutura para armazenar informações de clientes
struct Cliente {
    char nome[50];
    char endereco[100];
    char telefone[15];
    char formaPagamento[10]; 
    char caixaTransporte[5]; 
    float distanciaKm;
    char nomePet[50];
    char tipoPet[20]; 
    char numeroCartao[20]; 
};

// Estrutura para armazenar informações de motoristas
struct Motorista {
    char nome[50];
    char numeroCNH[20];
    char antecedentesCriminais[5]; 
};

int main() {
    int escolha;

    // Loop principal do programa
    while (1) {
        printf("Escolha uma opcao:\n");
        printf("1 - Cadastrar Cliente\n");
        printf("2 - Cadastrar Motorista\n");
        printf("0 - Sair\n");

        scanf("%d", &escolha);

        if (escolha == 0) {
            // Sair do programa
            break;
        } else if (escolha == 1) {
            // Cadastrar um cliente
            struct Cliente cliente;
            printf("Nome do cliente: ");
            scanf("%s", cliente.nome);
            printf("Endereco do cliente: ");
            scanf("%s", cliente.endereco);

            while (getchar() != '\n');

            printf("Telefone do cliente: ");
            fgets(cliente.telefone, sizeof(cliente.telefone), stdin);
            cliente.telefone[strlen(cliente.telefone) - 1] = '\0'; 

            printf("Numero do cartao de credito: "); 
            fgets(cliente.numeroCartao, sizeof(cliente.numeroCartao), stdin);
            cliente.numeroCartao[strlen(cliente.numeroCartao) - 1] = '\0'; 

            do {
                printf("Forma de pagamento do cliente (credito/debito): ");
                scanf("%s", cliente.formaPagamento);
            } while (strcmp(cliente.formaPagamento, "credito") != 0 && strcmp(cliente.formaPagamento, "debito") != 0);

            printf("Voce teria a caixa de transporte para seu pet? (Sim/Nao): ");
            scanf("%s", cliente.caixaTransporte);

            if (strcmp(cliente.caixaTransporte, "Nao") == 0) {
                printf("Cancelado\n\n");
                continue; 
            }

            printf("Digite a distancia em quilometros da sua casa até a empresa: ");
            scanf("%f", &cliente.distanciaKm);

            printf("Nome do pet: ");
            scanf("%s", cliente.nomePet);

            printf("Seu pet é um gato ou cachorro? ");
            scanf("%s", cliente.tipoPet);

            // Calcular o preço do transporte
            float preco = 5.0 + (cliente.distanciaKm * 1.6);

            // Aplicar acréscimo ou desconto com base na forma de pagamento
            if (strcmp(cliente.formaPagamento, "credito") == 0) {
                preco *= 1.03; // Acréscimo de 3%
            } else if (strcmp(cliente.formaPagamento, "debito") == 0) {
                preco -= 10.0; // Desconto de R$ 10,00
            }

            // Exibir informações do cliente, incluindo o nome do pet, tipo e o preço final
            printf("\nCliente cadastrado:\n");
            printf("Nome: %s\n", cliente.nome);
            printf("Endereco: %s\n", cliente.endereco);
            printf("Telefone: %s\n", cliente.telefone);
            printf("Forma de pagamento: %s\n", cliente.formaPagamento);
            printf("Numero do cartao: %s\n", cliente.numeroCartao); 
            printf("Caixa de transporte para pet: %s\n", cliente.caixaTransporte);
            printf("Distancia até a empresa: %.2f km\n", cliente.distanciaKm);
            printf("Nome do pet: %s\n", cliente.nomePet);
            printf("Tipo de pet: %s\n", cliente.tipoPet);
            printf("Preço do transporte: $%.2f\n\n", preco);

        } else if (escolha == 2) {
            // Cadastrar um motorista
            struct Motorista motorista;
            printf("Nome do motorista: ");
            scanf("%s", motorista.nome);
            printf("Numero da CNH do motorista: ");
            scanf("%s", motorista.numeroCNH);
            printf("Possui antecedentes criminais? (Sim/Nao): ");
            scanf("%s", motorista.antecedentesCriminais);

            // Perguntar ao motorista se deseja confirmar o cadastro
            printf("Deseja confirmar o cadastro do motorista (Sim/Nao)? ");
            char confirmacao[5];
            scanf("%s", confirmacao);

            if (strcmp(confirmacao, "Sim") == 0) {
                // Exibir informações do motorista
                printf("\nMotorista cadastrado:\n");
                printf("Nome: %s\n", motorista.nome);
                printf("Numero da CNH: %s\n", motorista.numeroCNH);
                printf("Antecedentes criminais: %s\n", motorista.antecedentesCriminais);
                printf("Cadastro confirmado\n\n");
            } else {
                printf("Cadastro cancelado\n\n");
            }

        } else {
            printf("Opcao invalida. Tente novamente.\n\n");
        }
    }

    return 0;
}