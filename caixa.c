#include <stdio.h>
#include <stdbool.h>

int notas[7] = {100, 50, 20, 10, 5, 2, 1};

void exibirCedulas(int quantidade[]) {
    printf("Cédulas disponíveis no caixa:\n");
    for (int i = 0; i < 7; i++) {
        printf("R$ %d: %d\n", notas[i], quantidade[i]);
    }
    printf("\n");
}

bool realizarSaque(int valor, int quantidade[]) {
    int usadas[7] = {0};  
    int valorRestante = valor;

    for (int i = 0; i < 7; i++) {
        while (valorRestante >= notas[i] && quantidade[i] > 0) {
            usadas[i]++;
            quantidade[i]--;
            valorRestante -= notas[i];
        }
    }

    if (valorRestante != 0) {
        printf("Saque de R$ %d não pode ser realizado. Cedulas insuficientes.\n", valor);
        
        for (int i = 0; i < 7; i++) {
            quantidade[i] += usadas[i];
        }
        return false;
    }

    printf("Saque realizado com sucesso! Cédulas utilizadas:\n");
    for (int i = 0; i < 7; i++) {
        if (usadas[i] > 0) {
            printf("R$ %d: %d\n", notas[i], usadas[i]);
        }
    }
    return true;
}

void realizarDeposito(int quantidade[]) {
    printf("Digite a quantidade de cédulas a depositar:\n");
    for (int i = 0; i < 7; i++) {
        int qtd;
        printf("R$ %d: ", notas[i]);
        scanf("%d", &qtd);
        quantidade[i] += qtd;
    }
    printf("Depósito realizado com sucesso!\n");
}

int main() {
    int quantidade[7];  

    printf("Digite a quantidade inicial de cédulas no caixa:\n");
    for (int i = 0; i < 7; i++) {
        printf("R$ %d: ", notas[i]);
        scanf("%d", &quantidade[i]);
    }

    int operacao;
    while (1) {
        printf("\nEscolha a operação: 0 - Saque, 1 - Depósito, -1 - Encerrar\n");
        scanf("%d", &operacao);

        if (operacao == -1) {
            printf("Encerrando o programa...\n");
            break;
        } else if (operacao == 0) {
            int valor;
            printf("Digite o valor a ser sacado: ");
            scanf("%d", &valor);
            if (valor <= 0) {
                printf("Valor inválido para saque.\n");
            } else {
                realizarSaque(valor, quantidade);
            }
        } else if (operacao == 1) {
            realizarDeposito(quantidade);
        } else {
            printf("Operação inválida. Tente novamente.\n");
        }

        exibirCedulas(quantidade);
    }
    return 0;
}