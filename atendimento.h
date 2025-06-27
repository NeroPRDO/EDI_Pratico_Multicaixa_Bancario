#ifndef ATENDIMENTO_H
#define ATENDIMENTO_H

#include "fila.h"
#include "historico.h"

// Simula o atendimento de um cliente em uma fila
void atender_cliente(Fila *fila, PilhaHistorico *historico, const char *tipo);

// Calcula e exibe o tempo médio de atendimento por tipo
void exibir_tempo_medio(PilhaHistorico *historico);

// Lista todos os atendimentos do histórico
void listar_atendimentos(PilhaHistorico *historico);

#endif