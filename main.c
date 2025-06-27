#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "clientes.h"
#include "fila.h"
#include "historico.h"
#include "atendimento.h"

// Autor: Pedro Eduardo Dall Agnol GRR20240844
// Descrição: Menu principal do sistema de atendimento bancário com múltiplas filas

int gerar_numero_cliente() {
    static int numero = 1;
    return numero++;
}

void menu() {
    printf("\n--- Simulador de Atendimento Multicaixa ---\n");
    printf("1. Cadastrar e inserir cliente na fila\n");
    printf("2. Atender proximo cliente\n");
    printf("3. Exibir filas\n");
    printf("4. Exibir tempo medio de atendimento\n");
    printf("5. Listar atendimentos realizados\n");
    printf("0. Sair\n");
    printf("Escolha: ");
}

int main() {
    Fila fila_comum, fila_rapida;
    PilhaHistorico historico;

    inicializar_fila(&fila_comum);
    inicializar_fila(&fila_rapida);
    inicializar_pilha(&historico);

    int opcao;
    do {
        menu();
        scanf("%d", &opcao);
        getchar();  // Limpa o \n

        if (opcao == 1) {
            char nome[NOME_TAM];
            int procedimentos;

            printf("Nome do cliente: ");
            fgets(nome, sizeof(nome), stdin);
            nome[strcspn(nome, "\n")] = 0;

            printf("Quantidade de procedimentos: ");
            scanf("%d", &procedimentos);
            getchar();

            int numero = gerar_numero_cliente();
            Cliente cliente = criar_cliente(nome, numero, procedimentos);

            if (procedimentos <= 2) {
                if (!enfileirar(&fila_rapida, cliente))
                    printf("Fila rapida cheia!\n");
                else
                    printf("Cliente inserido na fila rapida.\n");
            } else {
                if (!enfileirar(&fila_comum, cliente))
                    printf("Fila comum cheia!\n");
                else
                    printf("Cliente inserido na fila comum.\n");
            }

        } else if (opcao == 2) {
            static int turno = 0;
            // Alterna entre filas
            if (turno % 2 == 0 && !fila_vazia(&fila_comum)) {
                atender_cliente(&fila_comum, &historico, "Comum");
            } else if (!fila_vazia(&fila_rapida)) {
                atender_cliente(&fila_rapida, &historico, "Rapido");
            } else if (!fila_vazia(&fila_comum)) {
                atender_cliente(&fila_comum, &historico, "Comum");
            } else {
                printf("Nenhum cliente nas filas.\n");
            }
            turno++;

        } else if (opcao == 3) {
            exibir_fila(&fila_rapida, "Rapido");
            exibir_fila(&fila_comum, "Comum");

        } else if (opcao == 4) {
            exibir_tempo_medio(&historico);

        } else if (opcao == 5) {
            listar_atendimentos(&historico);

        } else if (opcao != 0) {
            printf("Opcao invalida!\n");
        }

    } while (opcao != 0);

    printf("Encerrando sistema...\n");
    return 0;
}