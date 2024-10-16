#include <stdio.h>

// Cabeçalho obrigatório
/******************************************************************/
/* Aluno1: Henrique Viganó - Número de matrícula: 8125140           */
/* Aluno2: Nathalia Ascencio - Número de matrícula: 8157954           */
/* Exercício-Programa 1 — Caixa Eletrônico                        */
/* Programação Avançada - 2024 - Professor: Bruno Perillo          */
/* Compilador: ... (DevC++ ou gcc) versão ...                      */
/******************************************************************/

// Função para mostrar as cédulas disponíveis
void exibir_cedulas(int cedulas[], int total) {
    printf("R$ 100 R$ 50 R$ 20 R$ 10 R$ 5 R$ 2 R$ 1 Total\n");
    printf("Quantidade de cédulas %d %d %d %d %d %d %d %d\n", 
           cedulas[0], cedulas[1], cedulas[2], cedulas[3], 
           cedulas[4], cedulas[5], cedulas[6], total);
}

// Função para processar o saque
int processar_saque(int cedulas[], int valor) {
    int notas[7] = {100, 50, 20, 10, 5, 2, 1};
    int saque_total = 0;
    int cedulas_usadas[7] = {0};

    for (int i = 0; i < 7; i++) {
        while (valor >= notas[i] && cedulas[i] > 0) {
            valor -= notas[i];
            cedulas[i]--;
            cedulas_usadas[i]++;
            saque_total += notas[i];
        }
    }

    if (valor == 0) {
        printf("Saque de R$ %d efetuado\n", saque_total);
        return saque_total;
    } else {
        // Reverter o saque se não for possível realizá-lo
        for (int i = 0; i < 7; i++) {
            cedulas[i] += cedulas_usadas[i];
        }
        printf("Saque de R$ %d não realizado por falta de cédulas\n", saque_total);
        return 0;
    }
}

// Função para processar o depósito
int processar_deposito(int cedulas[], int deposito[]) {
    int notas[7] = {100, 50, 20, 10, 5, 2, 1};
    int valor_total = 0;

    for (int i = 0; i < 7; i++) {
        cedulas[i] += deposito[i];
        valor_total += deposito[i] * notas[i];
    }

    printf("Depósito de R$ %d\n", valor_total);
    return valor_total;
}

int main() {
    int cedulas[7]; // Notas de 100, 50, 20, 10, 5, 2, 1
    int operacao, valor;
    int total = 0;

    // Leitura da quantidade inicial de cédulas
    printf("Digite a quantidade inicial de cédulas (100, 50, 20, 10, 5, 2, 1): ");
    for (int i = 0; i < 7; i++) {
        scanf("%d", &cedulas[i]);
        total += cedulas[i];
    }

    exibir_cedulas(cedulas, total);

    while (1) {
        scanf("%d", &operacao);

        if (operacao == -1) {
            break;
        } else if (operacao == 0) {
            // Saque
            scanf("%d", &valor);
            int saque_realizado = processar_saque(cedulas, valor);
            total -= saque_realizado;
            exibir_cedulas(cedulas, total);
        } else if (operacao == 1) {
            // Depósito
            int deposito[7];
            for (int i = 0; i < 7; i++) {
                scanf("%d", &deposito[i]);
            }
            int deposito_realizado = processar_deposito(cedulas, deposito);
            total += deposito_realizado;
            exibir_cedulas(cedulas, total);
        }
    }

    return 0;
}
