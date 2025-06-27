#include <stdio.h>
#include <string.h>
#include "atendimento.h"

// Autor: João Vítor Kretzschmar GRR20240632
// Descrição: Atende um cliente de uma fila e registra no histórico
void atender_cliente(Fila *fila, PilhaHistorico *historico, const char *tipo) {
    Cliente cliente;
    if (!desenfileirar(fila, &cliente)) {
        printf("Nenhum cliente na fila %s.\n", tipo);
        return;
    }

    int tempo = 5 + cliente.procedimentos * 3;  // Exemplo de tempo
    printf("Atendendo %s (%s) - Tempo estimado: %d min\n", cliente.nome, tipo, tempo);

    Registro reg;
    reg.cliente = cliente;
    reg.tempoAtendimento = tempo;
    strncpy(reg.tipo, tipo, sizeof(reg.tipo));
    reg.tipo[sizeof(reg.tipo) - 1] = '\0';

    empilhar(historico, reg);
}

// Autor: João Vítor Kretzschmar GRR20240632
// Descrição: Exibe o tempo médio de atendimento por tipo
void exibir_tempo_medio(PilhaHistorico *historico) {
    int totalRapido = 0, tempoRapido = 0;
    int totalComum = 0, tempoComum = 0;

    for (int i = 0; i <= historico->topo; i++) {
        Registro r = historico->registros[i];
        if (strcmp(r.tipo, "Rapido") == 0) {
            totalRapido++;
            tempoRapido += r.tempoAtendimento;
        } else {
            totalComum++;
            tempoComum += r.tempoAtendimento;
        }
    }

    printf("Tempo medio - Rapido: %.2f min\n", totalRapido ? (float)tempoRapido / totalRapido : 0);
    printf("Tempo medio - Comum:  %.2f min\n", totalComum ? (float)tempoComum / totalComum : 0);
}

void listar_atendimentos(PilhaHistorico *historico) {
    printf("Todos os Atendimentos Realizados:\n");
    for (int i = 0; i <= historico->topo; i++) {
        Registro r = historico->registros[i];
        printf("  - %s | Tipo: %s | Tempo: %d min\n", r.cliente.nome, r.tipo, r.tempoAtendimento);
    }
}