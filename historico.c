#include <stdio.h>
#include <string.h>
#include "historico.h"

// Autor: Gabriela Harres Rodrigues GRR20246215
// Descrição: Inicializa a pilha
void inicializar_pilha(PilhaHistorico *pilha) {
    pilha->topo = -1;
}

int pilha_cheia(PilhaHistorico *pilha) {
    return pilha->topo == TAM_MAX_PILHA - 1;
}

int pilha_vazia(PilhaHistorico *pilha) {
    return pilha->topo == -1;
}

// Autor: Gabriela Harres Rodrigues GRR20246215
// Descrição: Empilha um novo registro na pilha de histórico
int empilhar(PilhaHistorico *pilha, Registro reg) {
    if (pilha_cheia(pilha)) return 0;
    pilha->topo++;
    pilha->registros[pilha->topo] = reg;
    return 1;
}

int desempilhar(PilhaHistorico *pilha, Registro *reg) {
    if (pilha_vazia(pilha)) return 0;
    *reg = pilha->registros[pilha->topo];
    pilha->topo--;
    return 1;
}

void exibir_historico(PilhaHistorico *pilha) {
    printf("Historico de Atendimentos:\n");
    for (int i = pilha->topo; i >= 0; i--) {
        Registro r = pilha->registros[i];
        printf("  - %s | Tipo: %s | Tempo: %d min\n", r.cliente.nome, r.tipo, r.tempoAtendimento);
    }
}