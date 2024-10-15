/******************************************************************/
/* Aluno1: Nome Completo - Número de matrícula: 12345678 */
/* Aluno2: Nome Completo - Número de matrícula: 12345678 */
/* Número de matrícula: 12345678 */
/* Exercício-Programa 1 — Caixa Eletrônico */
/* Programação Avançada - 2024 - Professor: Bruno Perillo */
/* Compilador: gcc versão 9.3.0 */
/******************************************************************/

#include <stdio.h>

// Função para exibir a quantidade de cédulas e o valor total no caixa
void exibir_cedulas(int cedulas[], int total) {
    printf("R$ 100 R$ 50 R$ 20 R$ 10 R$ 5 R$ 2 R$ 1 Total\n");
    printf("Quantidade de cédulas: %d %d %d %d %d %d %d %d\n", cedulas[0], cedulas[1], cedulas[2], cedulas[3], cedulas[4], cedulas[5], cedulas[6], total);
}

// Função para calcular o total em reais no caixa
int calcular_total(int cedulas[]) {
    int valores[7] = {100, 50, 20, 10, 5, 2, 1};
    int total = 0;
    for (int i = 0; i < 7; i++) {
        total += cedulas[i] * valores[i];
    }
    return total;
}

// Função para realizar o saque
int realizar_saque(int cedulas[], int valor_saque) {
    int cedulas_temp[7];
    int valores[7] = {100, 50, 20, 10, 5, 2, 1};

    // Cópia do array de cédulas para testar a operação de saque
    for (int i = 0; i < 7; i++) {
        cedulas_temp[i] = cedulas[i];
    }

    for (int i = 0; i < 7; i++) {
        while (valor_saque >= valores[i] && cedulas_temp[i] > 0) {
            valor_saque -= valores[i];
            cedulas_temp[i]--;
        }
    }

    if (valor_saque == 0) {
        // Atualiza o caixa após o saque bem-sucedido
        for (int i = 0; i < 7; i++) {
            cedulas[i] = cedulas_temp[i];
        }
        return 1;  // Saque realizado com sucesso
    } else {
        return 0;  // Falta de cédulas suficientes
    }
}

// Função para realizar depósito
void realizar_deposito(int cedulas[], int deposito[]) {
    for (int i = 0; i < 7; i++) {
        cedulas[i] += deposito[i];
    }
}

int main() {
    int cedulas[7];  // Armazena a quantidade de cédulas: 100, 50, 20, 10, 5, 2, 1
    int operacao;
    
    // Leitura da quantidade inicial de cédulas
    printf("Digite a quantidade inicial de cédulas (100 50 20 10 5 2 1):\n");
    for (int i = 0; i < 7; i++) {
        scanf("%d", &cedulas[i]);
    }

    exibir_cedulas(cedulas, calcular_total(cedulas));

    while (1) {
        printf("\nDigite a operação (0 para saque, 1 para depósito, -1 para encerrar):\n");
        scanf("%d", &operacao);

        if (operacao == -1) {
            break;
        }

        if (operacao == 0) {
            // Saque
            int valor_saque;
            printf("Digite o valor do saque:\n");
            scanf("%d", &valor_saque);

            if (realizar_saque(cedulas, valor_saque)) {
                printf("Saque de R$ %d efetuado\n", valor_saque);
            } else {
                printf("Saque de R$ %d não realizado por falta de cédulas\n", valor_saque);
            }

            exibir_cedulas(cedulas, calcular_total(cedulas));

        } else if (operacao == 1) {
            // Depósito
            int deposito[7];
            printf("Digite a quantidade de cédulas a serem depositadas (100 50 20 10 5 2 1):\n");
            for (int i = 0; i < 7; i++) {
                scanf("%d", &deposito[i]);
            }

            realizar_deposito(cedulas, deposito);
            printf("Depósito realizado\n");

            exibir_cedulas(cedulas, calcular_total(cedulas));
        }
    }

    printf("Operações encerradas.\n");

    return 0;
}