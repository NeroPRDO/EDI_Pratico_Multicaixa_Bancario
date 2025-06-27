#ifndef HISTORICO_H
#define HISTORICO_H

#include "clientes.h"

#define TAM_MAX_PILHA 200

typedef struct {
    Cliente cliente;
    int tempoAtendimento;
    char tipo[10];  // "Rápido" ou "Comum"
} Registro;

typedef struct {
    Registro registros[TAM_MAX_PILHA];
    int topo;
} PilhaHistorico;

// Inicializa a pilha de histórico
void inicializar_pilha(PilhaHistorico *pilha);

// Verifica se a pilha está cheia
int pilha_cheia(PilhaHistorico *pilha);

// Verifica se a pilha está vazia
int pilha_vazia(PilhaHistorico *pilha);

// Empilha um novo registro de atendimento
int empilhar(PilhaHistorico *pilha, Registro reg);

// Desempilha um registro (opcional)
int desempilhar(PilhaHistorico *pilha, Registro *reg);

// Exibe todos os registros de atendimento
void exibir_historico(PilhaHistorico *pilha);

#endif